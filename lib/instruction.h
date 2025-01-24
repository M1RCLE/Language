#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <any>
#include <iostream>
#include <string>
#include <vector>

class Instruction {
public:
    enum class OperationCode {
        EMPTY,
        SAVE,
        PRINT,
        ARRAY,
        ADD,
        SUB,
        MUL,
        LESS,
        GREATER,
        EQUALS,
        NOT_EQUALS,
        IF,
        WHILE,
        FUNC,
        RETURN,
        NEW,
        READ_INDEX,
        WRITE_INDEX,
        ARRAY_VARIABLE_STORAGE,
        CALL,
        MOD,
        COMMA
    };

    OperationCode operationCode;
    std::string operand1;
    std::any operand2;
    std::any operand3;
    std::vector<Instruction> block;
    std::string target;
    std::vector<std::string> parameters;

    Instruction(OperationCode opCode, const std::string &operand1)
            : operationCode(opCode),
              operand1(operand1),
              operand2(),
              operand3(),
              block(),
              target(),
              parameters() {}

    Instruction(OperationCode opCode, const std::string &operand1, std::any operand2)
            : operationCode(opCode),
              operand1(operand1),
              operand2(operand2),
              operand3(),
              block(),
              target(),
              parameters() {}

    Instruction(OperationCode opCode, const std::string &target,
                const std::string &operand1)
            : operationCode(opCode),
              target(target),
              operand1(operand1),
              operand2(),
              operand3(),
              block(),
              parameters() {}

    Instruction(OperationCode opCode, const std::string &operand1, std::any operand2,
                std::any operand3)
            : operationCode(opCode),
              operand1(operand1),
              operand2(operand2),
              operand3(operand3),
              block(),
              target(),
              parameters() {}

    Instruction(OperationCode opCode, const std::string &operand1, std::any operand2,
                const std::vector<Instruction> &blockInstructions)
            : operationCode(opCode),
              operand1(operand1),
              operand2(operand2),
              operand3(),
              block(blockInstructions),
              target(),
              parameters() {}

    Instruction(OperationCode opCode, const std::string &operand1,
                const std::vector<std::string> &parameters)
            : operationCode(opCode),
              operand1(operand1),
              operand2(),
              operand3(),
              block(),
              target(),
              parameters(parameters) {}

    Instruction(OperationCode opCode, const std::string &operand1, std::any operand2,
                std::any operand3,
                const std::vector<Instruction> &blockInstructions)
            : operationCode(opCode),
              operand1(operand1),
              operand2(operand2),
              operand3(operand3),
              block(blockInstructions),
              target(),
              parameters() {}

    Instruction(OperationCode opCode, const std::string &operand1,
                const std::vector<Instruction> &blockInstructions,
                const std::vector<std::string> &parameters)
            : operationCode(opCode),
              operand1(operand1),
              operand2(),
              operand3(),
              block(blockInstructions),
              target(),
              parameters(parameters) {}

    Instruction()
            : operationCode(OperationCode::SAVE),
              operand1(),
              operand2(),
              operand3(),
              block(),
              target(),
              parameters() {}

    static Instruction FunctionInstruction(
            const std::string &functionName,
            const std::vector<std::string> &parameters,
            const std::vector<Instruction> &instructions) {
        Instruction newInstruction;
        newInstruction.operationCode = OperationCode::FUNC;
        newInstruction.operand1 = functionName;
        newInstruction.block = instructions;
        newInstruction.parameters = parameters;
        return newInstruction;
    }

    std::string toString() const {
        std::string result = opCodeToString(operationCode) + " " + operand1;
        if (operand2.type() == typeid(std::string)) {
            result += " " + std::any_cast<std::string>(operand2);
        } else if (operand2.type() == typeid(int)) {
            result += " " + std::to_string(std::any_cast<int>(operand2));
        } else if (operand2.type() == typeid(float)) {
            result += " " + std::to_string(std::any_cast<float>(operand2));
        }
        if (operand3.type() == typeid(std::string)) {
            result += " " + std::any_cast<std::string>(operand3);
        } else if (operand3.type() == typeid(int)) {
            result += " " + std::to_string(std::any_cast<int>(operand3));
        } else if (operand3.type() == typeid(float)) {
            result += " " + std::to_string(std::any_cast<float>(operand3));
        }
        if (!block.empty()) {
            result += " [";
            for (const auto &instruction: block) {
                result += instruction.toString() + " ";
            }
            result += "]";
        }
        return result;
    }

    static std::string opCodeToString(OperationCode opCode) {
        switch (opCode) {
            case OperationCode::SAVE:
                return "STORE";
            case OperationCode::PRINT:
                return "PRINT";
            case OperationCode::ARRAY:
                return "ARRAY";
            case OperationCode::ADD:
                return "ADD";
            case OperationCode::SUB:
                return "SUB";
            case OperationCode::MUL:
                return "MUL";
            case OperationCode::LESS:
                return "LESS";
            case OperationCode::GREATER:
                return "GREATER";
            case OperationCode::EQUALS:
                return "EQUALS";
            case OperationCode::NOT_EQUALS:
                return "NOT_EQUALS";
            case OperationCode::IF:
                return "IF";
            case OperationCode::WHILE:
                return "WHILE";
            case OperationCode::FUNC:
                return "FUNC";
            case OperationCode::RETURN:
                return "RETURN";
            case OperationCode::NEW:
                return "NEW";
            case OperationCode::READ_INDEX:
                return "READ_INDEX";
            case OperationCode::WRITE_INDEX:
                return "WRITE_INDEX";
            case OperationCode::ARRAY_VARIABLE_STORAGE:
                return "STORE_ARRAY_VAR";
            case OperationCode::CALL:
                return "CALL";
            case OperationCode::MOD:
                return "MOD";
            case OperationCode::COMMA:
                return "COMMA";
            default:
                return "UNKNOWN";
        }
    }
};

#endif  // INSTRUCTION_H
