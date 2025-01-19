#include "virtualMachine.h"

#include <fstream>
#include <sstream>

std::string anyToStringVM(const std::any& value) {
  if (!value.has_value()) {
    return "";
  }
  if (value.type() == typeid(std::string)) {
    return std::any_cast<std::string>(value);
  } else if (value.type() == typeid(int)) {
    return std::to_string(std::any_cast<int>(value));
  } else if (value.type() == typeid(long)) {
    return std::to_string(std::any_cast<long>(value));
  } else if (value.type() == typeid(float)) {
    return std::to_string(std::any_cast<float>(value));
  } else if (value.type() == typeid(double)) {
    return std::to_string(std::any_cast<double>(value));
  } else if (value.type() == typeid(Instruction::OpCode)) {
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
        case Instruction::OpCode::FUN: {
          std::string functionName;
          std::getline(file, functionName, '\0');

          int64_t parameterCount;
          file.read(reinterpret_cast<char*>(&parameterCount),
                    sizeof(parameterCount));
          std::vector<std::string> parameters;
          for (int64_t i = 0; i < parameterCount; ++i) {
            std::getline(file, parameters[i], '\0');
          }

          std::vector<Instruction> block;
          int64_t blockSize;
          file.read(reinterpret_cast<char*>(&blockSize), sizeof(blockSize));
          if (blockSize > 0) {
            for (int64_t i = 0; i < blockSize; ++i) {
              int8_t nestedOpCodeOrdinal;
              file.read(reinterpret_cast<char*>(&nestedOpCodeOrdinal),
                        sizeof(nestedOpCodeOrdinal));
              auto nestedOpCode =
                  static_cast<Instruction::OpCode>(nestedOpCodeOrdinal);

              if (nestedOpCode == Instruction::OpCode::RETURN) {
                std::string returnValue;
                std::getline(file, returnValue, '\0');

                Instruction nestedInstruction;
                if (returnValue.empty()) {
                  file.read(reinterpret_cast<char*>(&nestedOpCodeOrdinal),
                            sizeof(nestedOpCodeOrdinal));
                  nestedOpCode =
                      static_cast<Instruction::OpCode>(nestedOpCodeOrdinal);

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
                         nestedOpCode == Instruction::OpCode::LOOP) {
                std::string operand1, operand2, operand3;
                std::getline(file, operand1, '\0');

                std::getline(file, operand2, '\0');

                std::getline(file, operand3, '\0');

                std::vector<Instruction> nestedBlock = readNestedBlock(file);
                block.push_back(Instruction(nestedOpCode, operand1, operand2,
                                            operand3, nestedBlock));
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
          opCode == Instruction::OpCode::LOOP) {
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
      int8_t nestedOpCodeOrdinal;
      file.read(reinterpret_cast<char*>(&nestedOpCodeOrdinal),
                sizeof(nestedOpCodeOrdinal));
      auto nestedOpCode = static_cast<Instruction::OpCode>(nestedOpCodeOrdinal);

      if (nestedOpCode == Instruction::OpCode::RETURN) {
        std::string returnValue;
        std::getline(file, returnValue, '\0');

        Instruction instruction;
        if (returnValue.empty()) {
          file.read(reinterpret_cast<char*>(&nestedOpCodeOrdinal),
                    sizeof(nestedOpCodeOrdinal));
          nestedOpCode = static_cast<Instruction::OpCode>(nestedOpCodeOrdinal);

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
                 nestedOpCode == Instruction::OpCode::LOOP) {
        std::string operand1, operand2, operand3;
        std::getline(file, operand1, '\0');
        std::getline(file, operand2, '\0');
        std::getline(file, operand3, '\0');

        std::vector<Instruction> nestedBlock = readNestedBlock(file);
        block.emplace_back(Instruction(nestedOpCode, operand1, operand2,
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
      if (value.has_value()) {
        std::cout << anyToStringVM(value) << std::endl;
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
    case Instruction::OpCode::LOOP: {
      while (conditions(instruction)) {
        if (!instruction.block.empty()) {
          run(instruction.block);
        }
      }
      break;
    }
    case Instruction::OpCode::FUN: {
      functions[instruction.operand1] = instruction;
      break;
    }
    case Instruction::OpCode::CALL: {
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

      for (size_t i = 0; i < params.size(); ++i) {
        std::any argument = arguments[i];
      }
      memoryManager.enterFunction();

      for (size_t i = 0; i < functionInstruction.parameters.size(); ++i) {
        memoryManager.allocate(functionInstruction.parameters[i],
                               instruction.parameters[i]);
      }

      run(functionInstruction.block);

      memoryManager.exitFunction();
      break;
    }
    case Instruction::OpCode::RETURN: {
      memoryManager.setReturnValue(instruction.operand1);
      break;
    }
    default:
      throw std::runtime_error("Unknown instruction");
  }
}

void VirtualMachine::run(const std::vector<Instruction>& block) {
  for (const auto& instruction : block) {
    if (isReturning) {
      break;  // Завершаем выполнение текущего блока при возвращении из функции
    }
    execute(instruction);
  }
}

bool VirtualMachine::conditions(const Instruction& instruction) {
  std::string conditionType = anyToStringVM(instruction.operand2);
  if (conditionType == "LESS") {
    return getOperandValue(instruction.operand1) <
           getOperandValue(instruction.operand3);
  } else if (conditionType == "GREATER") {
    return getOperandValue(instruction.operand1) >
           getOperandValue(instruction.operand3);
  } else if (conditionType == "EQUALS") {
    return getOperandValue(instruction.operand1) ==
           getOperandValue(instruction.operand3);
  } else if (conditionType == "NOT_EQUALS") {
    return getOperandValue(instruction.operand1) !=
           getOperandValue(instruction.operand3);
  } else {
    throw std::runtime_error("Unknown condition: " + conditionType);
  }
}

long VirtualMachine::getOperandValue(const std::any& operand) {
  if (operand.type() == typeid(long)) {
    return std::any_cast<long>(operand);
  } else if (operand.type() == typeid(int)) {
    return std::any_cast<int>(operand);
  } else if (operand.type() == typeid(std::string)) {
    std::string varName = std::any_cast<std::string>(operand);
    auto value = memoryManager.getValue(varName);
    if (value.type() == typeid(int)) {
      return std::any_cast<int>(value);
    } else if (value.type() == typeid(std::string)) {
      try {
        return std::stol(std::any_cast<std::string>(value));
      } catch (const std::invalid_argument&) {
        throw std::runtime_error(
            "Variable " + varName +
            " is not a valid number: " + std::any_cast<std::string>(value));
      }
    } else if (value.type() == typeid(nullptr)) {
      try {
        return std::stol(varName);
      } catch (const std::invalid_argument&) {
        throw std::runtime_error("Variable " + varName +
                                 " is not a valid number");
      }
    } else if (value.type() == typeid(std::vector<std::any>)) {
      throw std::runtime_error("Variable " + varName +
                               " is an array, not an Integer");
    }
    throw std::runtime_error("Variable " + varName + " has unsupported type");
  } else {
    throw std::runtime_error("Invalid operand type");
  }
}

std::vector<std::any> VirtualMachine::parseToListOfObjects(
    const std::any& input) {
  std::string str = std::any_cast<std::string>(input);
  std::string trimmed = str.substr(1, str.length() - 2);
  trimmed.erase(trimmed.find_last_not_of(" \t\n\r\f\v") + 1);

  if (trimmed.empty()) {
    return {};
  }

  std::vector<std::any> result;
  std::stringstream ss(trimmed);
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
      try {
        result.push_back(std::stol(trimmedItem));
      } catch (const std::invalid_argument&) {
        result.push_back(trimmedItem);
      }
    }
  }

  return result;
}
