#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <any>
#include <iostream>
#include <string>
#include <utility>
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
    std::string register1;
    std::any register2;
    std::any register3;
    std::vector<Instruction> block;
    std::string target;
    std::vector<std::string> parameters;

    Instruction(OperationCode opCode, std::string reg1)
            : operationCode(opCode),
              register1(std::move(reg1)),
              register2(),
              register3(),
              block(),
              target(),
              parameters() {}

    Instruction(OperationCode opCode, std::string reg1, std::any reg2)
            : operationCode(opCode),
              register1(std::move(reg1)),
              register2(std::move(reg2)),
              register3(),
              block(),
              target(),
              parameters() {}

    Instruction(OperationCode opCode, std::string target,
                std::string reg1)
            : operationCode(opCode),
              target(std::move(target)),
              register1(std::move(reg1)),
              register2(),
              register3(),
              block(),
              parameters() {}

    Instruction(OperationCode opCode, std::string reg1, std::any reg2,
                std::any reg3)
            : operationCode(opCode),
              register1(std::move(reg1)),
              register2(std::move(reg2)),
              register3(std::move(reg3)),
              block(),
              target(),
              parameters() {}

    Instruction(OperationCode opCode, std::string reg1, std::any reg2,
                const std::vector<Instruction> &blockInstructions)
            : operationCode(opCode),
              register1(std::move(reg1)),
              register2(std::move(reg2)),
              register3(),
              block(blockInstructions),
              target(),
              parameters() {}

    Instruction(OperationCode opCode, std::string reg1,
                const std::vector<std::string> &parameters)
            : operationCode(opCode),
              register1(std::move(reg1)),
              register2(),
              register3(),
              block(),
              target(),
              parameters(parameters) {}

    Instruction(OperationCode opCode, std::string reg1, std::any reg2,
                std::any reg3,
                const std::vector<Instruction> &blockInstructions)
            : operationCode(opCode),
              register1(std::move(reg1)),
              register2(std::move(reg2)),
              register3(std::move(reg3)),
              block(blockInstructions),
              target(),
              parameters() {}

    Instruction(OperationCode opCode, std::string reg1,
                const std::vector<Instruction> &blockInstructions,
                const std::vector<std::string> &parameters)
            : operationCode(opCode),
              register1(std::move(reg1)),
              register2(),
              register3(),
              block(blockInstructions),
              target(),
              parameters(parameters) {}

    Instruction()
            : operationCode(OperationCode::SAVE),
              register1(),
              register2(),
              register3(),
              block(),
              target(),
              parameters() {}

    static Instruction FunctionInstruction(
            const std::string &functionName,
            const std::vector<std::string> &parameters,
            const std::vector<Instruction> &instructions) {
        Instruction newInstruction;
        newInstruction.operationCode = OperationCode::FUNC;
        newInstruction.register1 = functionName;
        newInstruction.block = instructions;
        newInstruction.parameters = parameters;
        return newInstruction;
    }

    std::string toString() const {
        std::string result = opCodeToString(operationCode) + " " + register1;
        if (register2.type() == typeid(std::string)) {
            result += " " + std::any_cast<std::string>(register2);
        } else if (register2.type() == typeid(int)) {
            result += " " + std::to_string(std::any_cast<int>(register2));
        } else if (register2.type() == typeid(float)) {
            result += " " + std::to_string(std::any_cast<float>(register2));
        }
        if (register3.type() == typeid(std::string)) {
            result += " " + std::any_cast<std::string>(register3);
        } else if (register3.type() == typeid(int)) {
            result += " " + std::to_string(std::any_cast<int>(register3));
        } else if (register3.type() == typeid(float)) {
            result += " " + std::to_string(std::any_cast<float>(register3));
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
