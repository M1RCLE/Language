#include "virtualMachine.h"

#include <fstream>
#include <sstream>

std::string anyToStringVM(const std::any &value) {
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
    if (value.type() == typeid(Instruction::OperationCode)) {
        return Instruction::opCodeToString(
                std::any_cast<Instruction::OperationCode>(value));
    }
    return "";
}

void VirtualMachine::loadFromFile(const std::string &filename) {
    try {
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file: " + filename);
        }

        while (file.peek() != EOF) {
            std::string opCodeOrdinal;
            std::getline(file, opCodeOrdinal, '\0');
            auto opCode = static_cast<Instruction::OperationCode>(opCodeOrdinal[0]);

            switch (opCode) {
                case Instruction::OperationCode::FUNC: {
                    std::string functionName;
                    std::getline(file, functionName, '\0');

                    int64_t parameterCount;
                    file.read(reinterpret_cast<char *>(&parameterCount), sizeof(int64_t));
                    std::vector<std::string> parameters(parameterCount);
                    for (int64_t i = 0; i < parameterCount; ++i) {
                        std::getline(file, parameters[i], '\0');
                    }

                    std::vector<Instruction> block;
                    int64_t blockSize;
                    file.read(reinterpret_cast<char *>(&blockSize), sizeof(blockSize));
                    if (blockSize > 0) {
                        for (int64_t i = 0; i < blockSize; ++i) {
                            std::string opCodeOrdinalCpy;
                            std::getline(file, opCodeOrdinalCpy, '\0');
                            auto nestedOpCode =
                                    static_cast<Instruction::OperationCode>(opCodeOrdinalCpy[0]);

                            if (nestedOpCode == Instruction::OperationCode::RETURN) {
                                std::string returnValue;
                                std::getline(file, returnValue, '\0');

                                Instruction nestedInstruction;
                                if (returnValue.empty()) {
                                    std::string opCodeOrdinalCpyTwo;
                                    std::getline(file, opCodeOrdinalCpyTwo, '\0');
                                    auto nestedOpCodeCpy =
                                            static_cast<Instruction::OperationCode>(opCodeOrdinalCpyTwo[0]);

                                    std::string nestedOperand1, nestedOperand2, nestedOperand3;
                                    std::getline(file, nestedOperand1, '\0');
                                    std::getline(file, nestedOperand2, '\0');
                                    std::getline(file, nestedOperand3, '\0');

                                    nestedInstruction =
                                            Instruction(nestedOpCodeCpy, nestedOperand1, nestedOperand2,
                                                        nestedOperand3);
                                }

                                block.emplace_back(Instruction::OperationCode::RETURN,
                                                            returnValue, nestedInstruction);
                            } else if (nestedOpCode == Instruction::OperationCode::IF ||
                                       nestedOpCode == Instruction::OperationCode::WHILE ||
                                       nestedOpCode == Instruction::OperationCode::FOR) {
                                std::string operand1, operand2, operand3;
                                std::getline(file, operand1, '\0');

                                std::getline(file, operand2, '\0');

                                std::getline(file, operand3, '\0');

                                auto operandCompare =
                                        static_cast<Instruction::OperationCode>(operand2[0]);

                                std::vector<Instruction> nestedBlock = readNestedBlock(file);
                                block.emplace_back(nestedOpCode, operand1,
                                                            operandCompare, operand3,
                                                            nestedBlock);
                            } else {
                                std::string nestedOperand1, nestedOperand2, nestedOperand3;
                                std::getline(file, nestedOperand1, '\0');

                                std::getline(file, nestedOperand2, '\0');

                                std::getline(file, nestedOperand3, '\0');

                                block.emplace_back(nestedOpCode, nestedOperand1,
                                                            nestedOperand2, nestedOperand3);
                            }
                        }
                    }

                    auto functionInstruction =
                            Instruction::FunctionInstruction(functionName, parameters, block);
                    functions[functionName] = functionInstruction;
                    continue;
                }

                case Instruction::OperationCode::RETURN: {
                    std::string returnValue;
                    std::getline(file, returnValue, '\0');

                    instructions.emplace_back(Instruction::OperationCode::RETURN, returnValue);
                    continue;
                }

                default:
                    break;
            }

            std::string operand1, operand2, operand3;
            std::getline(file, operand1, '\0');
            std::getline(file, operand2, '\0');
            std::getline(file, operand3, '\0');

            std::vector<Instruction> block;
            if (opCode == Instruction::OperationCode::IF ||
                opCode == Instruction::OperationCode::WHILE ||
                opCode == Instruction::OperationCode::FOR) {
                block = readNestedBlock(file);
                auto operandCompare = static_cast<Instruction::OperationCode>(operand2[0]);
                instructions.emplace_back(opCode, operand1, operandCompare, operand3, block);
            } else {
                instructions.emplace_back(opCode, operand1, operand2, operand3, block);
            }
        }
    } catch (const std::exception &e) {
        throw std::runtime_error("Error loading bytecode from file: " +
                                 std::string(e.what()));
    }
}

std::vector<Instruction> VirtualMachine::readNestedBlock(std::ifstream &file) {
    std::vector<Instruction> block;
    int64_t blockSize;
    file.read(reinterpret_cast<char *>(&blockSize), sizeof(blockSize));
    if (blockSize > 0) {
        for (int64_t i = 0; i < blockSize; ++i) {
            std::string opCodeOrdinal;
            std::getline(file, opCodeOrdinal, '\0');
            auto nestedOpCode = static_cast<Instruction::OperationCode>(opCodeOrdinal[0]);

            if (nestedOpCode == Instruction::OperationCode::RETURN) {
                std::string returnValue;
                std::getline(file, returnValue, '\0');

                Instruction instruction;
                if (returnValue.empty()) {
                    std::string opCodeOrdinalCpyOne;
                    std::getline(file, opCodeOrdinalCpyOne, '\0');
                    auto nestedOpCodeCpy =
                            static_cast<Instruction::OperationCode>(opCodeOrdinalCpyOne[0]);

                    std::string nestedOperand1, nestedOperand2, nestedOperand3;
                    std::getline(file, nestedOperand1, '\0');
                    std::getline(file, nestedOperand2, '\0');
                    std::getline(file, nestedOperand3, '\0');

                    instruction = Instruction(nestedOpCodeCpy, nestedOperand1,
                                              nestedOperand2, nestedOperand3);
                }

                block.emplace_back(
                        Instruction::OperationCode::RETURN, returnValue, instruction);
            } else if (nestedOpCode == Instruction::OperationCode::IF ||
                       nestedOpCode == Instruction::OperationCode::WHILE ||
                       nestedOpCode == Instruction::OperationCode::FOR) {
                std::string operand1, operand2, operand3;
                std::getline(file, operand1, '\0');
                std::getline(file, operand2, '\0');
                std::getline(file, operand3, '\0');

                auto operandCompare = static_cast<Instruction::OperationCode>(operand2[0]);

                std::vector<Instruction> nestedBlock = readNestedBlock(file);
                block.emplace_back(nestedOpCode, operand1, operandCompare,
                                               operand3, nestedBlock);
            } else {
                std::string nestedOperand1, nestedOperand2, nestedOperand3;
                std::getline(file, nestedOperand1, '\0');
                std::getline(file, nestedOperand2, '\0');
                std::getline(file, nestedOperand3, '\0');

                block.emplace_back(nestedOpCode, nestedOperand1,
                                               nestedOperand2, nestedOperand3);
            }
        }
    }
    return block;
}

void VirtualMachine::run() {
    for (const auto &instruction: instructions) {
        execute(instruction);
    }
}

void VirtualMachine::execute(const Instruction &instruction) {
    switch (instruction.operationCode) {
        case Instruction::OperationCode::SAVE: {
            if (!instruction.target.empty()) {
                memoryManager.allocate(instruction.target, instruction.register2);
            } else {
                memoryManager.allocate(instruction.register1, instruction.register2);
            }
            break;
        }
        case Instruction::OperationCode::PRINT: {
            auto value = memoryManager.getValue(instruction.register1);
            if (value != nullptr) {
                std::cout << anyToStringVM(*value) << std::endl;
            } else {
                throw std::runtime_error("Variable not found: " + instruction.register1);
            }
            break;
        }
        case Instruction::OperationCode::ADD: {
            auto result = getOperandValue(instruction.register2) +
                          getOperandValue(instruction.register3);
            if (!instruction.target.empty()) {
                memoryManager.allocate(instruction.target, result);
            } else {
                memoryManager.allocate(instruction.register1, result);
            }
            break;
        }
        case Instruction::OperationCode::SUB: {
            auto result = getOperandValue(instruction.register2) -
                          getOperandValue(instruction.register3);
            if (!instruction.target.empty()) {
                memoryManager.allocate(instruction.target, result);
            } else {
                memoryManager.allocate(instruction.register1, result);
            }
            break;
        }
        case Instruction::OperationCode::MUL: {
            auto result = getOperandValue(instruction.register2) *
                          getOperandValue(instruction.register3);
            if (!instruction.target.empty()) {
                memoryManager.allocate(instruction.target, result);
            } else {
                memoryManager.allocate(instruction.register1, result);
            }
            break;
        }
        case Instruction::OperationCode::MOD: {
            auto result = getOperandValue(instruction.register2) %
                          getOperandValue(instruction.register3);
            if (!instruction.target.empty()) {
                memoryManager.allocate(instruction.target, result);
            } else {
                memoryManager.allocate(instruction.register1, result);
            }
            break;
        }
        case Instruction::OperationCode::LESS: {
            auto result = getOperandValue(instruction.register2) <
                          getOperandValue(instruction.register3);
            if (!instruction.target.empty()) {
                memoryManager.allocate(instruction.target, result);
            } else {
                memoryManager.allocate(instruction.register1, result);
            }
            break;
        }
        case Instruction::OperationCode::GREATER: {
            auto result = getOperandValue(instruction.register2) >
                          getOperandValue(instruction.register3);
            if (!instruction.target.empty()) {
                memoryManager.allocate(instruction.target, result);
            } else {
                memoryManager.allocate(instruction.register1, result);
            }
            break;
        }
        case Instruction::OperationCode::EQUALS: {
            auto result = getOperandValue(instruction.register2) ==
                          getOperandValue(instruction.register3);
            if (!instruction.target.empty()) {
                memoryManager.allocate(instruction.target, result);
            } else {
                memoryManager.allocate(instruction.register1, result);
            }
            break;
        }
        case Instruction::OperationCode::NOT_EQUALS: {
            auto result = getOperandValue(instruction.register2) !=
                          getOperandValue(instruction.register3);
            if (!instruction.target.empty()) {
                memoryManager.allocate(instruction.target, result);
            } else {
                memoryManager.allocate(instruction.register1, result);
            }
            break;
        }
        case Instruction::OperationCode::NEW: {
            std::any size = instruction.register2;
            if (size.type() == typeid(std::string)) {
                auto arraySize = std::stol(std::any_cast<std::string>(size));
                if (!instruction.target.empty()) {
                    memoryManager.allocateArray(instruction.target, arraySize);
                } else {
                    memoryManager.allocateArray(instruction.register1, arraySize);
                }
            } else if (size.type() == typeid(std::vector<std::any>)) {
                auto array = std::any_cast<std::vector<std::any>>(instruction.register2);
                if (!instruction.target.empty()) {
                    memoryManager.allocateArray(instruction.target, array);
                } else {
                    memoryManager.allocateArray(instruction.register1, array);
                }
            } else {
                throw std::runtime_error("Invalid array size");
            }
            break;
        }
        case Instruction::OperationCode::WRITE_INDEX: {
            auto index = getOperandValue(instruction.register2);
            auto value = getOperandValue(instruction.register3);
            if (!instruction.target.empty()) {
                memoryManager.setArrayElement(instruction.target, index, value);
            } else {
                memoryManager.setArrayElement(instruction.register1, index, value);
            }
            break;
        }
        case Instruction::OperationCode::ARRAY_VARIABLE_STORAGE: {
            auto value = memoryManager.getArrayElement(
                    instruction.register1, getOperandValue(instruction.register2));
            if (!value.has_value()) {
                throw std::runtime_error("Variable not found: " + instruction.register1);
            }
            if (!instruction.target.empty()) {
                memoryManager.allocate(instruction.target, value);
            } else {
                memoryManager.allocate(std::any_cast<std::string>(instruction.register3),
                                       value);
            }
            break;
        }
        case Instruction::OperationCode::READ_INDEX: {
            auto value = memoryManager.getArrayElement(
                    instruction.register1, getOperandValue(instruction.register2));
            if (value.has_value()) {
                std::cout << std::any_cast<std::string>(value) << std::endl;
            } else {
                throw std::runtime_error("Variable not found");
            }
            break;
        }
        case Instruction::OperationCode::IF: {
            if (conditions(instruction) && !instruction.block.empty()) {
                run(instruction.block);
            }
            break;
        }
        case Instruction::OperationCode::WHILE: {
            while (conditions(instruction)) {
                if (!instruction.block.empty()) {
                    run(instruction.block);
                }
            }
            break;
        }
        case Instruction::OperationCode::FOR: {
            while (conditions(instruction)) {
                if (!instruction.block.empty()) {
                    run(instruction.block);
                }
            }
            break;
        }
        case Instruction::OperationCode::FUNC: {
            std::string functionName = instruction.register1;
            std::vector<std::string> params = instruction.parameters;
            std::vector<Instruction> functionBody = instruction.block;
            Instruction functionInstr = Instruction(
                    Instruction::OperationCode::FUNC, functionName, params, functionBody);
            functions[functionName] = functionInstr;
            break;
        }
        case Instruction::OperationCode::CALL: {
            if (!functions.contains(instruction.register1)) {
                throw std::runtime_error("Unknown function");
            }
            auto &functionInstruction = functions[instruction.register1];

            std::vector<std::string> params = functionInstruction.parameters;

            std::vector<Instruction> functionBody = functionInstruction.block;

            auto args = instruction.register2;
            std::vector<std::any> valsForAlloc;
            std::vector<std::any> arguments = parseToListOfObjects(args);
            if (params.size() != arguments.size()) {
                throw std::runtime_error("Function " + instruction.register1 +
                                         " expects " + std::to_string(params.size()) +
                                         " arguments, but got " +
                                         std::to_string(arguments.size()));
            }

            for (int i = 0; i < params.size(); ++i) {
                std::any argument = arguments[i];
                std::any *valueToAllocate;

                if (argument.type() == typeid(std::string)) {
                    auto varName = std::any_cast<std::string>(argument);
                    valueToAllocate = memoryManager.getValue(varName);
                    if (!valueToAllocate->has_value()) {
                        valueToAllocate = &argument;
                    }
                } else {
                    valueToAllocate = &argument;
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

            if (instruction.register3.has_value()) {
                memoryManager.allocate(std::any_cast<std::string>(instruction.register3),
                                       returnValue);
            }
            break;
        }
        case Instruction::OperationCode::RETURN: {
            if (instruction.register1.empty()) {
                auto instruction1 =
                        std::any_cast<Instruction>(instruction.register2);
                std::string functionName = instruction1.register1;
                if (!functions.contains(functionName)) {
                    throw std::runtime_error("Unknown function");
                }
                Instruction functionInstruction = functions[functionName];

                std::vector<std::string> parameters = functionInstruction.parameters;
                std::vector<Instruction> functionBody = functionInstruction.block;

                auto args = std::any_cast<std::string>(instruction1.register2);
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
                    std::any *valueToAllocate;

                    if (argument.type() == typeid(std::string)) {
                        auto varName = std::any_cast<std::string>(argument);
                        valueToAllocate = memoryManager.getValue(varName);
                        if (!valueToAllocate->has_value()) {
                            valueToAllocate = &argument;
                        }
                    } else {
                        valueToAllocate = &argument;
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

                if (instruction1.register3.has_value()) {
                    if (!returnValue.has_value()) {
                        throw std::runtime_error("Function did not return a value");
                    }
                    memoryManager.allocate(
                            std::any_cast<std::string>(instruction1.register3), returnValue);
                }
                return;
            }
            std::any *returnValue = memoryManager.getValue(instruction.register1);
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

void VirtualMachine::run(const std::vector<Instruction> &block) {
    for (const auto &instruction: block) {
        if (isReturning) {
            break;
        }
        execute(instruction);
    }
}

bool VirtualMachine::conditions(const Instruction &instruction) {
    std::string conditionType = anyToStringVM(instruction.register2);
    if (conditionType == "LESS") {
        return getOperandValue(instruction.register1) <
               getOperandValue(instruction.register3);
    }
    if (conditionType == "GREATER") {
        return getOperandValue(instruction.register1) >
               getOperandValue(instruction.register3);
    }
    if (conditionType == "EQUALS") {
        return getOperandValue(instruction.register1) ==
               getOperandValue(instruction.register3);
    }
    if (conditionType == "NOT_EQUALS") {
        return getOperandValue(instruction.register1) !=
               getOperandValue(instruction.register3);
    }
    throw std::runtime_error("Unknown condition: " + conditionType);
}

long VirtualMachine::getOperandValue(const std::any &operand) {
    if (operand.type() == typeid(long)) {
        return std::any_cast<long>(operand);
    }
    if (operand.type() == typeid(int)) {
        return std::any_cast<int>(operand);
    }
    if (operand.type() == typeid(std::string)) {
        auto varName = std::any_cast<std::string>(operand);
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
            } catch (const std::invalid_argument &) {
                throw std::runtime_error(
                        "Variable " + varName +
                        " is not a valid number: " + std::any_cast<std::string>(*value));
            }
        }
        if (value == nullptr) {
            try {
                return std::stol(varName);
            } catch (const std::invalid_argument &) {
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

bool is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

std::vector<std::any> VirtualMachine::parseToListOfObjects(
        const std::any &input) {
    auto str = std::any_cast<std::string>(input);
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
                    objectArray.emplace_back(std::stol(trimmedArrayItem));
                } catch (const std::invalid_argument &) {
                    objectArray.emplace_back(trimmedArrayItem);
                }
            }
            result.emplace_back(objectArray);
        } else {
            if (is_number(trimmedItem)) {
                auto stolTrimmedItem = std::stol(trimmedItem);
                result.emplace_back(stolTrimmedItem);
            } else {
                result.emplace_back(trimmedItem);
            }
        }
    }

    return result;
}
