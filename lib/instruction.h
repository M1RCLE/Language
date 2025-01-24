#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <any>
#include <iostream>
#include <string>
#include <vector>

class Instruction {
public:
    enum class OpCode {
        EMPTY,
        STORE,
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
        STORE_ARRAY_VAR,
        CALL,
        MOD,
        COMMA
    };

    OpCode opCode;
    std::string operand1;
    std::any operand2;
    std::any operand3;
    std::vector<Instruction> block;
    std::string target;
    std::vector<std::string> parameters;

    Instruction(OpCode opCode, const std::string &operand1)
            : opCode(opCode),
              operand1(operand1),
              operand2(),
              operand3(),
              block(),
              target(),
              parameters() {}

    Instruction(OpCode opCode, const std::string &operand1, std::any operand2)
            : opCode(opCode),
              operand1(operand1),
              operand2(operand2),
              operand3(),
              block(),
              target(),
              parameters() {}

    Instruction(OpCode opCode, const std::string &target,
                const std::string &operand1)
            : opCode(opCode),
              target(target),
              operand1(operand1),
              operand2(),
              operand3(),
              block(),
              parameters() {}

    Instruction(OpCode opCode, const std::string &operand1, std::any operand2,
                std::any operand3)
            : opCode(opCode),
              operand1(operand1),
              operand2(operand2),
              operand3(operand3),
              block(),
              target(),
              parameters() {}

    Instruction(OpCode opCode, const std::string &operand1, std::any operand2,
                const std::vector<Instruction> &blockInstructions)
            : opCode(opCode),
              operand1(operand1),
              operand2(operand2),
              operand3(),
              block(blockInstructions),
              target(),
              parameters() {}

    Instruction(OpCode opCode, const std::string &operand1,
                const std::vector<std::string> &parameters)
            : opCode(opCode),
              operand1(operand1),
              operand2(),
              operand3(),
              block(),
              target(),
              parameters(parameters) {}

    Instruction(OpCode opCode, const std::string &operand1, std::any operand2,
                std::any operand3,
                const std::vector<Instruction> &blockInstructions)
            : opCode(opCode),
              operand1(operand1),
              operand2(operand2),
              operand3(operand3),
              block(blockInstructions),
              target(),
              parameters() {}

    Instruction(OpCode opCode, const std::string &operand1,
                const std::vector<Instruction> &blockInstructions,
                const std::vector<std::string> &parameters)
            : opCode(opCode),
              operand1(operand1),
              operand2(),
              operand3(),
              block(blockInstructions),
              target(),
              parameters(parameters) {}

    Instruction()
            : opCode(OpCode::STORE),
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
        newInstruction.opCode = OpCode::FUNC;
        newInstruction.operand1 = functionName;
        newInstruction.block = instructions;
        newInstruction.parameters = parameters;
        return newInstruction;
    }

    std::string toString() const {
        std::string result = opCodeToString(opCode) + " " + operand1;
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

    static std::string opCodeToString(OpCode opCode) {
        switch (opCode) {
            case OpCode::STORE:
                return "STORE";
            case OpCode::PRINT:
                return "PRINT";
            case OpCode::ARRAY:
                return "ARRAY";
            case OpCode::ADD:
                return "ADD";
            case OpCode::SUB:
                return "SUB";
            case OpCode::MUL:
                return "MUL";
            case OpCode::LESS:
                return "LESS";
            case OpCode::GREATER:
                return "GREATER";
            case OpCode::EQUALS:
                return "EQUALS";
            case OpCode::NOT_EQUALS:
                return "NOT_EQUALS";
            case OpCode::IF:
                return "IF";
            case OpCode::WHILE:
                return "WHILE";
            case OpCode::FUNC:
                return "FUNC";
            case OpCode::RETURN:
                return "RETURN";
            case OpCode::NEW:
                return "NEW";
            case OpCode::READ_INDEX:
                return "READ_INDEX";
            case OpCode::WRITE_INDEX:
                return "WRITE_INDEX";
            case OpCode::STORE_ARRAY_VAR:
                return "STORE_ARRAY_VAR";
            case OpCode::CALL:
                return "CALL";
            case OpCode::MOD:
                return "MOD";
            case OpCode::COMMA:
                return "COMMA";
            default:
                return "UNKNOWN";
        }
    }
};

#endif  // INSTRUCTION_H
