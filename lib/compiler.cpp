#include "compiler.h"

std::string anyToStringCompiler(const std::any &value) {
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
        auto opCode = std::any_cast<Instruction::OperationCode>(value);
        auto c = static_cast<char>(opCode);
        std::string s(1, c);
        return s;
    }
    if (value.type() == typeid(std::vector<std::string>)) {
        std::string res;
        auto vec = std::any_cast<std::vector<std::string>>(value);
        for (const auto &i: vec) {
            if (!res.empty()) {
                res += ',';
            }
            res += i;
        }
        return res;
    }
    return "";
}

long Compiler::getVariableIndex(const std::string &variableName) {
    if (_variableIndexes.find(variableName) == _variableIndexes.end()) {
        _variableIndexes[variableName] = nextVariableIndex++;
    }
    return _variableIndexes[variableName];
}

void Compiler::addUsedVariable(const std::any &operand) {
    if (operand.type() == typeid(std::string)) {
        const std::string &strOperand = std::any_cast<std::string>(operand);
        if (!isInteger(strOperand)) {
            usedVariables.insert(strOperand);
        }
    }
}

bool Compiler::isInteger(const std::string &str) {
    if (str.empty()) return false;
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

Instruction Compiler::compileLoop(const Instruction &loopInstruction) {
    return Instruction(Instruction::OperationCode::WHILE, loopInstruction.register1,
                       loopInstruction.register2, loopInstruction.register3,
                       loopInstruction.block);
}

std::vector<Instruction> Compiler::adaptInstructions(
        std::vector<Instruction> &instructions) {
    std::vector<Instruction> adaptedInstructions;
    for (auto &instruction: instructions) {
        std::vector<Instruction> processedBlock;
        switch (instruction.operationCode) {
            case Instruction::OperationCode::FUNC:
                _functions[instruction.register1] = instruction;
                processedBlock = adaptInstructions(instruction.block);
                adaptedInstructions.emplace_back(Instruction::FunctionInstruction(
                        instruction.register1, instruction.parameters, processedBlock));
                break;

            case Instruction::OperationCode::IF:
                if (!instruction.block.empty()) {
                    processedBlock = adaptInstructions(instruction.block);
                    instruction.block = processedBlock;
                }
                adaptedInstructions.push_back(instruction);
                break;

            case Instruction::OperationCode::WHILE:
                if (!instruction.block.empty()) {
                    processedBlock = adaptInstructions(instruction.block);
                    instruction.block = processedBlock;
                }
                adaptedInstructions.push_back(compileLoop(instruction));
                break;
            case Instruction::OperationCode::ADD:
            case Instruction::OperationCode::SUB:
            case Instruction::OperationCode::MUL:
            case Instruction::OperationCode::MOD:
            case Instruction::OperationCode::SAVE:
            case Instruction::OperationCode::LESS:
            case Instruction::OperationCode::GREATER:
            case Instruction::OperationCode::EQUALS:
            case Instruction::OperationCode::NOT_EQUALS:
            case Instruction::OperationCode::NEW:
            case Instruction::OperationCode::WRITE_INDEX:
                instruction.target = instruction.register1;
                adaptedInstructions.push_back(instruction);
                break;
            case Instruction::OperationCode::ARRAY_VARIABLE_STORAGE:
                instruction.target = anyToStringCompiler(instruction.register3);
                adaptedInstructions.push_back(instruction);
                break;
            default:
                adaptedInstructions.push_back(instruction);
                break;
        }
    }
    return adaptedInstructions;
}

void Compiler::writeInstruction(std::ofstream &out, const Instruction &instr) {
    auto c = static_cast<char>(instr.operationCode);
    out << c;
    out << '\0';

    switch (instr.operationCode) {
        case Instruction::OperationCode::FUNC: {
            if (!instr.register1.empty()) {
                out << instr.register1;
            } else {
                out << "";
            }
            out << '\0';
            auto params_size = instr.parameters.size();
            out.write(reinterpret_cast<const char *>(&params_size), sizeof(size_t));
            for (const auto &param: instr.parameters) {
                out << param;
                out << '\0';
            }
            size_t blockSize = instr.block.size();
            out.write(reinterpret_cast<const char *>(&blockSize), sizeof(size_t));
            for (const auto &blockInstr: instr.block) {
                writeInstruction(out, blockInstr);
            }
            break;
        }
        case Instruction::OperationCode::RETURN: {
            if (!instr.register1.empty()) {
                out << instr.register1;
            } else {
                out << "";
            }
            out << '\0';
            if (instr.register2.has_value()) {
                writeInstruction(out, std::any_cast<Instruction>(instr.register2));
            }
            break;
        }
        case Instruction::OperationCode::IF: {
            if (!instr.register1.empty()) {
                out << instr.register1;
            } else {
                out << "";
            }
            out << '\0';

            if (instr.register2.has_value()) {
                auto op2 = anyToStringCompiler(instr.register2);
                out << op2[0];
            } else {
                out << "";
            }
            out << '\0';

            if (instr.register3.has_value()) {
                auto op3 = anyToStringCompiler(instr.register3);
                out << op3;
            } else {
                out << "";
            }
            out << '\0';

            size_t blockSize = instr.block.size();
            out.write(reinterpret_cast<const char *>(&blockSize), sizeof(size_t));
            for (const auto &blockInstr: instr.block) {
                writeInstruction(out, blockInstr);
            }
            break;
        }
        case Instruction::OperationCode::WHILE: {
            if (!instr.register1.empty()) {
                out << instr.register1;
            } else {
                out << "";
            }
            out << '\0';

            if (instr.register2.has_value()) {
                auto op2 = anyToStringCompiler(instr.register2);
                out << op2[0];
            } else {
                out << "";
            }
            out << '\0';

            if (instr.register3.has_value()) {
                auto op3 = anyToStringCompiler(instr.register3);
                out << op3;
            } else {
                out << "";
            }
            out << '\0';

            size_t blockSize = instr.block.size();
            out.write(reinterpret_cast<const char *>(&blockSize), sizeof(size_t));
            for (const auto &blockInstr: instr.block) {
                writeInstruction(out, blockInstr);
            }
            break;
        }
        default: {
            if (!instr.register1.empty()) {
                out << instr.register1;
            } else {
                out << "";
            }
            out << '\0';

            if (instr.register2.has_value()) {
                auto op2 = anyToStringCompiler(instr.register2);
                out << op2;
            } else {
                out << "";
            }
            out << '\0';

            if (instr.register3.has_value()) {
                auto op3 = anyToStringCompiler(instr.register3);
                out << op3;
            } else {
                out << "";
            }
            out << '\0';
            break;
        }
    }
}

Compiler::Compiler(const std::vector<Instruction> &instructions)
        : _instructions(instructions) {}

void Compiler::saveToFile(const std::string &filename) {
    std::ofstream out(filename, std::ios::binary);
    if (!out) {
        throw std::runtime_error("Error opening file for writing");
    }

    auto optimizedInstructions = adaptInstructions(_instructions);
    optimizedInstructions = instructionsOptimizations(optimizedInstructions);

    for (const auto &instr: optimizedInstructions) {
        writeInstruction(out, instr);
    }
}

std::vector<Instruction> Compiler::instructionsOptimizations(const std::vector<Instruction> &instructions) {
    std::vector<Instruction> optimizedInstructions;

    for (size_t i = 0; i < instructions.size(); ++i) {
        const auto &instr = instructions[i];

        if (instr.operationCode == Instruction::OperationCode::SAVE) {
            if (i + 1 < instructions.size() && instructions[i + 1].operationCode == Instruction::OperationCode::SAVE &&
                instr.register1 == instructions[i + 1].register1) {
                continue;
            }
        }

        if (instr.operationCode == Instruction::OperationCode::ADD || instr.operationCode == Instruction::OperationCode::SUB) {
            if (i + 1 < instructions.size()) {
                const auto &nextInstr = instructions[i + 1];
                if ((nextInstr.operationCode == Instruction::OperationCode::ADD && instr.operationCode == Instruction::OperationCode::SUB) ||
                    (nextInstr.operationCode == Instruction::OperationCode::SUB && instr.operationCode == Instruction::OperationCode::ADD)) {
                    if (instr.register1 == nextInstr.register1 && instr.register2.type() == nextInstr.register2.type()) {
                        optimizedInstructions.push_back(instr);
                        continue;
                    }
                }
            }
        }

        if ((instr.operationCode == Instruction::OperationCode::ADD || instr.operationCode == Instruction::OperationCode::SUB ||
             instr.operationCode == Instruction::OperationCode::MUL || instr.operationCode == Instruction::OperationCode::MOD) &&
            instr.register2.type() == typeid(int) && instr.register3.type() == typeid(int)) {
            int operand2 = std::any_cast<int>(instr.register2);
            int operand3 = std::any_cast<int>(instr.register3);
            int result = 0;

            switch (instr.operationCode) {
                case Instruction::OperationCode::ADD:
                    result = operand2 + operand3;
                    break;
                case Instruction::OperationCode::SUB:
                    result = operand2 - operand3;
                    break;
                case Instruction::OperationCode::MUL:
                    result = operand2 * operand3;
                    break;
                case Instruction::OperationCode::MOD:
                    if (operand3 != 0) {
                        result = operand2 % operand3;
                    } else {
                        continue;
                    }
                    break;
                default:
                    break;
            }

            // Replace with simplified result
            optimizedInstructions.push_back(Instruction(Instruction::OperationCode::SAVE, instr.register1, result));
            continue; // Skip adding the original instruction
        }

        // Remove unused or redundant instructions (example: no-op, empty block, etc.)
        if (instr.operationCode == Instruction::OperationCode::EMPTY || instr.register1.empty()) {
            continue; // Skip this instruction
        }

        // Default: Add the current instruction
        optimizedInstructions.push_back(instr);
    }

    // Further optimizations can go here, such as handling function calls, loops, etc.

    return optimizedInstructions;
}
