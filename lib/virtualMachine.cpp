#include "virtualMachine.h"

#include <fstream>
#include <sstream>

std::string anyToStringVM(const std::any& value) {
  if (!value.has_value()) {
    return "";
  }
  if (value.type() == typeid(std::string)) {
    return std::any_cast<std::string>(value);
  }
  if (value.type() == typeid(int)) {
    return std::to_string(std::any_cast<int>(value));
  }
  if (value.type() == typeid(long)) {
    return std::to_string(std::any_cast<long>(value));
  }
  if (value.type() == typeid(float)) {
    return std::to_string(std::any_cast<float>(value));
  }
  if (value.type() == typeid(double)) {
    return std::to_string(std::any_cast<double>(value));
  }
  if (value.type() == typeid(Instruction::OpCode)) {
    return Instruction::opCodeToString(
        std::any_cast<Instruction::OpCode>(value));
  }
  return "";
}

void VirtualMachine::loadFromFile(const std::string& filename) {
  try {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
      throw std::runtime_error("Cannot open file: " + filename);
    }

    while (file.peek() != EOF) {
      std::string opCodeOrdinal;
      std::getline(file, opCodeOrdinal, '\0');
      auto opCode = static_cast<Instruction::OpCode>(opCodeOrdinal[0]);

      switch (opCode) {
        case Instruction::OpCode::FUNC: {
          std::string functionName;
          std::getline(file, functionName, '\0');

          int64_t parameterCount;
          file.read(reinterpret_cast<char*>(&parameterCount), sizeof(int64_t));
          std::vector<std::string> parameters(parameterCount);
          for (int64_t i = 0; i < parameterCount; ++i) {
            std::getline(file, parameters[i], '\0');
          }

          std::vector<Instruction> block;
          int64_t blockSize;
          file.read(reinterpret_cast<char*>(&blockSize), sizeof(blockSize));
          if (blockSize > 0) {
            for (int64_t i = 0; i < blockSize; ++i) {
              std::string opCodeOrdinal;
              std::getline(file, opCodeOrdinal, '\0');
              auto nestedOpCode =
                  static_cast<Instruction::OpCode>(opCodeOrdinal[0]);

              if (nestedOpCode == Instruction::OpCode::RETURN) {
                std::string returnValue;
                std::getline(file, returnValue, '\0');

                Instruction nestedInstruction;
                if (returnValue.empty()) {
                  std::string opCodeOrdinal;
                  std::getline(file, opCodeOrdinal, '\0');
                  auto nestedOpCode =
                      static_cast<Instruction::OpCode>(opCodeOrdinal[0]);

                  std::string nestedOperand1, nestedOperand2, nestedOperand3;
                  std::getline(file, nestedOperand1, '\0');
                  std::getline(file, nestedOperand2, '\0');
                  std::getline(file, nestedOperand3, '\0');

                  nestedInstruction =
                      Instruction(nestedOpCode, nestedOperand1, nestedOperand2,
                                  nestedOperand3);
                }

                block.push_back(Instruction(Instruction::OpCode::RETURN,
                                            returnValue, nestedInstruction));
              } else if (nestedOpCode == Instruction::OpCode::IF ||
                         nestedOpCode == Instruction::OpCode::WHILE) {
                std::string operand1, operand2, operand3;
                std::getline(file, operand1, '\0');

                std::getline(file, operand2, '\0');

                std::getline(file, operand3, '\0');

                auto operandCompare =
                    static_cast<Instruction::OpCode>(operand2[0]);

                std::vector<Instruction> nestedBlock = readNestedBlock(file);
                block.push_back(Instruction(nestedOpCode, operand1,
                                            operandCompare, operand3,
                                            nestedBlock));
              } else {
                std::string nestedOperand1, nestedOperand2, nestedOperand3;
                std::getline(file, nestedOperand1, '\0');

                std::getline(file, nestedOperand2, '\0');

                std::getline(file, nestedOperand3, '\0');

                block.push_back(Instruction(nestedOpCode, nestedOperand1,
                                            nestedOperand2, nestedOperand3));
              }
            }
          }

          auto functionInstruction =
              Instruction::FunctionInstruction(functionName, parameters, block);
          functions[functionName] = functionInstruction;
          continue;
        }

        case Instruction::OpCode::RETURN: {
          std::string returnValue;
          std::getline(file, returnValue, '\0');

          instructions.push_back(
              Instruction(Instruction::OpCode::RETURN, returnValue));
          continue;
        }
      }

      std::string operand1, operand2, operand3;
      std::getline(file, operand1, '\0');
      std::getline(file, operand2, '\0');
      std::getline(file, operand3, '\0');

      std::vector<Instruction> block;
      if (opCode == Instruction::OpCode::IF ||
          opCode == Instruction::OpCode::WHILE) {
        block = readNestedBlock(file);
        auto operandCompare = static_cast<Instruction::OpCode>(operand2[0]);
        instructions.push_back(
            Instruction(opCode, operand1, operandCompare, operand3, block));
      } else {
        instructions.push_back(
            Instruction(opCode, operand1, operand2, operand3, block));
      }
    }
  } catch (const std::exception& e) {
    throw std::runtime_error("Error loading bytecode from file: " +
                             std::string(e.what()));
  }
}

std::vector<Instruction> VirtualMachine::readNestedBlock(std::ifstream& file) {
  std::vector<Instruction> block;
  int64_t blockSize;
  file.read(reinterpret_cast<char*>(&blockSize), sizeof(blockSize));
  if (blockSize > 0) {
    for (int64_t i = 0; i < blockSize; ++i) {
      std::string opCodeOrdinal;
      std::getline(file, opCodeOrdinal, '\0');
      auto nestedOpCode = static_cast<Instruction::OpCode>(opCodeOrdinal[0]);

      if (nestedOpCode == Instruction::OpCode::RETURN) {
        std::string returnValue;
        std::getline(file, returnValue, '\0');

        Instruction instruction;
        if (returnValue.empty()) {
          std::string opCodeOrdinal;
          std::getline(file, opCodeOrdinal, '\0');
          auto nestedOpCode =
              static_cast<Instruction::OpCode>(opCodeOrdinal[0]);

          std::string nestedOperand1, nestedOperand2, nestedOperand3;
          std::getline(file, nestedOperand1, '\0');
          std::getline(file, nestedOperand2, '\0');
          std::getline(file, nestedOperand3, '\0');

          instruction = Instruction(nestedOpCode, nestedOperand1,
                                    nestedOperand2, nestedOperand3);
        }

        block.emplace_back(
            Instruction(Instruction::OpCode::RETURN, returnValue, instruction));
      } else if (nestedOpCode == Instruction::OpCode::IF ||
                 nestedOpCode == Instruction::OpCode::WHILE) {
        std::string operand1, operand2, operand3;
        std::getline(file, operand1, '\0');
        std::getline(file, operand2, '\0');
        std::getline(file, operand3, '\0');

        auto operandCompare = static_cast<Instruction::OpCode>(operand2[0]);

        std::vector<Instruction> nestedBlock = readNestedBlock(file);
        block.emplace_back(Instruction(nestedOpCode, operand1, operandCompare,
                                       operand3, nestedBlock));
      } else {
        std::string nestedOperand1, nestedOperand2, nestedOperand3;
        std::getline(file, nestedOperand1, '\0');
        std::getline(file, nestedOperand2, '\0');
        std::getline(file, nestedOperand3, '\0');

        block.emplace_back(Instruction(nestedOpCode, nestedOperand1,
                                       nestedOperand2, nestedOperand3));
      }
    }
  }
  return block;
}

void VirtualMachine::run() {
  for (const auto& instruction : instructions) {
    execute(instruction);
  }
}

void VirtualMachine::execute(const Instruction& instruction) {
  switch (instruction.opCode) {
    case Instruction::OpCode::STORE: {
      if (!instruction.target.empty()) {
        memoryManager.allocate(instruction.target, instruction.operand2);
      } else {
        memoryManager.allocate(instruction.operand1, instruction.operand2);
      }
      break;
    }
    case Instruction::OpCode::PRINT: {
      auto value = memoryManager.getValue(instruction.operand1);
      if (value->has_value()) {
        std::cout << anyToStringVM(*value) << std::endl;
      } else {
        throw std::runtime_error("Variable not found: " + instruction.operand1);
      }
      break;
    }
    case Instruction::OpCode::ADD: {
      auto result = getOperandValue(instruction.operand2) +
                    getOperandValue(instruction.operand3);
      if (!instruction.target.empty()) {
        memoryManager.allocate(instruction.target, result);
      } else {
        memoryManager.allocate(instruction.operand1, result);
      }
      break;
    }
    case Instruction::OpCode::SUB: {
      auto result = getOperandValue(instruction.operand2) -
                    getOperandValue(instruction.operand3);
      if (!instruction.target.empty()) {
        memoryManager.allocate(instruction.target, result);
      } else {
        memoryManager.allocate(instruction.operand1, result);
      }
      break;
    }
    case Instruction::OpCode::MUL: {
      auto result = getOperandValue(instruction.operand2) *
                    getOperandValue(instruction.operand3);
      if (!instruction.target.empty()) {
        memoryManager.allocate(instruction.target, result);
      } else {
        memoryManager.allocate(instruction.operand1, result);
      }
      break;
    }
    case Instruction::OpCode::MOD: {
      auto result = getOperandValue(instruction.operand2) %
                    getOperandValue(instruction.operand3);
      if (!instruction.target.empty()) {
        memoryManager.allocate(instruction.target, result);
      } else {
        memoryManager.allocate(instruction.operand1, result);
      }
      break;
    }
    case Instruction::OpCode::LESS: {
      auto result = getOperandValue(instruction.operand2) <
                    getOperandValue(instruction.operand3);
      if (!instruction.target.empty()) {
        memoryManager.allocate(instruction.target, result);
      } else {
        memoryManager.allocate(instruction.operand1, result);
      }
      break;
    }
    case Instruction::OpCode::GREATER: {
      auto result = getOperandValue(instruction.operand2) >
                    getOperandValue(instruction.operand3);
      if (!instruction.target.empty()) {
        memoryManager.allocate(instruction.target, result);
      } else {
        memoryManager.allocate(instruction.operand1, result);
      }
      break;
    }
    case Instruction::OpCode::EQUALS: {
      auto result = getOperandValue(instruction.operand2) ==
                    getOperandValue(instruction.operand3);
      if (!instruction.target.empty()) {
        memoryManager.allocate(instruction.target, result);
      } else {
        memoryManager.allocate(instruction.operand1, result);
      }
      break;
    }
    case Instruction::OpCode::NOT_EQUALS: {
      auto result = getOperandValue(instruction.operand2) !=
                    getOperandValue(instruction.operand3);
      if (!instruction.target.empty()) {
        memoryManager.allocate(instruction.target, result);
      } else {
        memoryManager.allocate(instruction.operand1, result);
      }
      break;
    }
    case Instruction::OpCode::NEW: {
      std::any size = instruction.operand2;
      if (size.type() == typeid(std::string)) {
        auto arraySize = std::stol(std::any_cast<std::string>(size));
        if (!instruction.target.empty()) {
          memoryManager.allocateArray(instruction.target, arraySize);
        } else {
          memoryManager.allocateArray(instruction.operand1, arraySize);
        }
      } else if (size.type() == typeid(std::vector<std::any>)) {
        auto array = std::any_cast<std::vector<std::any>>(instruction.operand2);
        if (!instruction.target.empty()) {
          memoryManager.allocateArray(instruction.target, array);
        } else {
          memoryManager.allocateArray(instruction.operand1, array);
        }
      } else {
        throw std::runtime_error("Invalid array size");
      }
      break;
    }
    case Instruction::OpCode::WRITE_INDEX: {
      auto index = getOperandValue(instruction.operand2);
      auto value = getOperandValue(instruction.operand3);
      if (!instruction.target.empty()) {
        memoryManager.setArrayElement(instruction.target, index, value);
      } else {
        memoryManager.setArrayElement(instruction.operand1, index, value);
      }
      break;
    }
    case Instruction::OpCode::STORE_ARRAY_VAR: {
      auto value = memoryManager.getArrayElement(
          instruction.operand1, getOperandValue(instruction.operand2));
      if (!value.has_value()) {
        throw std::runtime_error("Variable not found: " + instruction.operand1);
      }
      if (!instruction.target.empty()) {
        memoryManager.allocate(instruction.target, value);
      } else {
        memoryManager.allocate(std::any_cast<std::string>(instruction.operand3),
                               value);
      }
      break;
    }
    case Instruction::OpCode::READ_INDEX: {
      auto value = memoryManager.getArrayElement(
          instruction.operand1, getOperandValue(instruction.operand2));
      if (value.has_value()) {
        std::cout << std::any_cast<std::string>(value) << std::endl;
      } else {
        throw std::runtime_error("Variable not found");
      }
      break;
    }
    case Instruction::OpCode::IF: {
      if (conditions(instruction) && !instruction.block.empty()) {
        run(instruction.block);
      }
      break;
    }
    case Instruction::OpCode::WHILE: {
      while (conditions(instruction)) {
        if (!instruction.block.empty()) {
          run(instruction.block);
        }
      }
      break;
    }
    case Instruction::OpCode::FUNC: {
      std::string functionName = instruction.operand1;
      std::vector<std::string> params = instruction.parameters;
      std::vector<Instruction> functionBody = instruction.block;
      Instruction functionInstr = Instruction(
          Instruction::OpCode::FUNC, functionName, params, functionBody);
      functions[functionName] = functionInstr;
      break;
    }
    case Instruction::OpCode::CALL: {
      if (!functions.contains(instruction.operand1)) {
        throw std::runtime_error("Unknown function");
      }
      auto& functionInstruction = functions[instruction.operand1];

      std::vector<std::string> params = functionInstruction.parameters;

      std::vector<Instruction> functionBody = functionInstruction.block;

      auto args = instruction.operand2;
      std::vector<std::any> valsForAlloc;
      std::vector<std::any> arguments = parseToListOfObjects(args);
      if (params.size() != arguments.size()) {
        throw std::runtime_error("Function " + instruction.operand1 +
                                 " expects " + std::to_string(params.size()) +
                                 " arguments, but got " +
                                 std::to_string(arguments.size()));
      }

      for (int i = 0; i < params.size(); ++i) {
        std::any argument = arguments[i];
        std::any* valueToAllocate;

        if (argument.type() == typeid(std::string)) {
          std::string varName = std::any_cast<std::string>(argument);
          valueToAllocate = memoryManager.getValue(varName);
          if (!valueToAllocate->has_value()) {
            *valueToAllocate = argument;
          }
        } else {
          *valueToAllocate = argument;
        }
        valsForAlloc.push_back(*valueToAllocate);
      }
      memoryManager.enterFunction();

      for (int i = 0; i < params.size(); ++i) {
        memoryManager.allocate(params[i], valsForAlloc[i]);
      }

      run(functionBody);

      std::any returnValue = memoryManager.getReturnValue();
      memoryManager.exitFunction();
      isReturning = false;

      if (instruction.operand3.has_value()) {
        memoryManager.allocate(std::any_cast<std::string>(instruction.operand3),
                               returnValue);
      }
      break;
    }
    case Instruction::OpCode::RETURN: {
      if (instruction.operand1.empty()) {
        Instruction instruction1 =
            std::any_cast<Instruction>(instruction.operand2);
        std::string functionName = instruction1.operand1;
        if (!functions.contains(functionName)) {
          throw std::runtime_error("Unknown function");
        }
        Instruction functionInstruction = functions[functionName];

        std::vector<std::string> parameters = functionInstruction.parameters;
        std::vector<Instruction> functionBody = functionInstruction.block;

        std::string args = std::any_cast<std::string>(instruction1.operand2);
        std::vector<std::any> arguments = parseToListOfObjects(args);
        if (parameters.size() != arguments.size()) {
          throw std::runtime_error("Function " + functionName + " expects " +
                                   std::to_string(parameters.size()) +
                                   " arguments, but got " +
                                   std::to_string(arguments.size()));
        }

        std::vector<std::any> operandValues;
        for (long i = 0; i < parameters.size(); i++) {
          std::any argument = arguments[i];
          std::any* valueToAllocate;

          if (argument.type() == typeid(std::string)) {
            std::string varName = std::any_cast<std::string>(argument);
            valueToAllocate = memoryManager.getValue(varName);
            if (!valueToAllocate->has_value()) {
              *valueToAllocate = argument;
            }
          } else {
            *valueToAllocate = argument;
          }
          operandValues.push_back(*valueToAllocate);
        }

        memoryManager.enterFunction();
        for (long i = 0; i < parameters.size(); i++) {
          memoryManager.allocate(parameters[i], operandValues[i]);
        }
        run(functionBody);
        std::any returnValue = memoryManager.getReturnValue();
        memoryManager.exitFunction();
        isReturning = false;

        if (instruction1.operand3.has_value()) {
          if (!returnValue.has_value()) {
            throw std::runtime_error("Function did not return a value");
          }
          memoryManager.allocate(
              std::any_cast<std::string>(instruction1.operand3), returnValue);
        }
        return;
      }
      std::any* returnValue = memoryManager.getValue(instruction.operand1);
      if (!returnValue->has_value()) {
        throw std::runtime_error("Return value not found");
      }
      memoryManager.setReturnValue(*returnValue);
      isReturning = true;
      break;
    }
    default:
      throw std::runtime_error("Unknown instruction");
  }
}

void VirtualMachine::run(const std::vector<Instruction>& block) {
  for (const auto& instruction : block) {
    if (isReturning) {
      break;
    }
    execute(instruction);
  }
}

bool VirtualMachine::conditions(const Instruction& instruction) {
  std::string conditionType = anyToStringVM(instruction.operand2);
  if (conditionType == "LESS") {
    return getOperandValue(instruction.operand1) <
           getOperandValue(instruction.operand3);
  }
  if (conditionType == "GREATER") {
    return getOperandValue(instruction.operand1) >
           getOperandValue(instruction.operand3);
  }
  if (conditionType == "EQUALS") {
    return getOperandValue(instruction.operand1) ==
           getOperandValue(instruction.operand3);
  }
  if (conditionType == "NOT_EQUALS") {
    return getOperandValue(instruction.operand1) !=
           getOperandValue(instruction.operand3);
  }
  throw std::runtime_error("Unknown condition: " + conditionType);
}

long VirtualMachine::getOperandValue(const std::any& operand) {
  if (operand.type() == typeid(long)) {
    return std::any_cast<long>(operand);
  }
  if (operand.type() == typeid(int)) {
    return std::any_cast<int>(operand);
  }
  if (operand.type() == typeid(std::string)) {
    std::string varName = std::any_cast<std::string>(operand);
    auto value = memoryManager.getValue(varName);
    if (value != nullptr && value->type() == typeid(int)) {
      return std::any_cast<int>(*value);
    }
    if (value != nullptr && value->type() == typeid(long)) {
      return std::any_cast<long>(*value);
    }
    if (value != nullptr && value->type() == typeid(std::string)) {
      try {
        return std::stol(std::any_cast<std::string>(*value));
      } catch (const std::invalid_argument&) {
        throw std::runtime_error(
            "Variable " + varName +
            " is not a valid number: " + std::any_cast<std::string>(*value));
      }
    }
    if (value == nullptr) {
      try {
        return std::stol(varName);
      } catch (const std::invalid_argument&) {
        throw std::runtime_error("Variable " + varName +
                                 " is not a valid number");
      }
    }
    if (value->type() == typeid(std::vector<std::any>)) {
      throw std::runtime_error("Variable " + varName +
                               " is an array, not an Integer");
    }
    throw std::runtime_error("Variable " + varName + " has unsupported type");
  }
  throw std::runtime_error("Invalid operand type");
}

bool is_number(const std::string& s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}

std::vector<std::any> VirtualMachine::parseToListOfObjects(
    const std::any& input) {
  std::string str = std::any_cast<std::string>(input);
  str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);

  if (str.empty()) {
    return {};
  }

  std::vector<std::any> result;
  std::stringstream ss(str);
  std::string item;

  while (std::getline(ss, item, ',')) {
    std::string trimmedItem = item;
    trimmedItem.erase(0, trimmedItem.find_first_not_of(" \t\n\r\f\v"));
    trimmedItem.erase(trimmedItem.find_last_not_of(" \t\n\r\f\v") + 1);

    if (trimmedItem.front() == '[' && trimmedItem.back() == ']') {
      std::string arrayContent =
          trimmedItem.substr(1, trimmedItem.length() - 2);
      std::vector<std::any> objectArray;
      std::stringstream arraySS(arrayContent);
      std::string arrayItem;

      while (std::getline(arraySS, arrayItem, ',')) {
        std::string trimmedArrayItem = arrayItem;
        trimmedArrayItem.erase(
            0, trimmedArrayItem.find_first_not_of(" \t\n\r\f\v"));
        trimmedArrayItem.erase(
            trimmedArrayItem.find_last_not_of(" \t\n\r\f\v") + 1);
        try {
          objectArray.push_back(std::stol(trimmedArrayItem));
        } catch (const std::invalid_argument&) {
          objectArray.push_back(trimmedArrayItem);
        }
      }
      result.push_back(objectArray);
    } else {
      if (is_number(trimmedItem)) {
        auto stolTrimmedItem = std::stol(trimmedItem);
        result.push_back(stolTrimmedItem);
      } else {
        result.push_back(trimmedItem);
      }
    }
  }

  return result;
}
