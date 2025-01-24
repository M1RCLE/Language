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
    for (auto &instr: instructions) {
        std::vector<Instruction> processedBlock;
        switch (instr.operationCode) {
            case Instruction::OperationCode::FUNC:
                _functions[instr.register1] = instr;
                processedBlock = adaptInstructions(instr.block);
                adaptedInstructions.emplace_back(Instruction::FunctionInstruction(
                        instr.register1, instr.parameters, processedBlock));
                break;

            case Instruction::OperationCode::IF:
                if (!instr.block.empty()) {
                    processedBlock = adaptInstructions(instr.block);
                    instr.block = processedBlock;
                }
                adaptedInstructions.push_back(instr);
                break;

            case Instruction::OperationCode::WHILE:
                if (!instr.block.empty()) {
                    processedBlock = adaptInstructions(instr.block);
                    instr.block = processedBlock;
                }
                adaptedInstructions.push_back(compileLoop(instr));
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
                instr.target = instr.register1;
                adaptedInstructions.push_back(instr);
                break;
            case Instruction::OperationCode::ARRAY_VARIABLE_STORAGE:
                instr.target = anyToStringCompiler(instr.register3);
                adaptedInstructions.push_back(instr);
                break;
            default:
                adaptedInstructions.push_back(instr);
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

bool is_digits(std::string &str) {
    for (char ch: str) {
        if (!(ch >= 48 && ch <= 57)) {
            return false;
        }
    }

    return true;
}

template<typename T>
bool compareAny(const std::any &a, const std::any &b) {
    if (a.type() != b.type()) {
        return false;
    }

    if (a.type() == typeid(T)) {
        T value1 = std::any_cast<T>(a);
        T value2 = std::any_cast<T>(b);
        return value1 == value2;
    }

    return false;
}

bool areIntOrLongLong(const std::any &value1, const std::any &value2) {
    if (value1.type() == typeid(std::string) && value2.type() == typeid(std::string)) {
        try {
            auto first = std::any_cast<std::string>(value1);
            auto second = std::any_cast<std::string>(value2);
            std::stoll(first);
            std::stoll(second);
            return true;
        } catch (const std::exception& ex) {
            return false;
        }
    }
    return (value1.type() == typeid(int) || value1.type() == typeid(long long)) &&
           (value2.type() == typeid(int) || value2.type() == typeid(long long));
}

bool compareAnyValues(const std::any &a, const std::any &b) {
    if (a.type() == b.type()) {
        if (a.type() == typeid(int)) {
            return compareAny<int>(a, b);
        } else if (a.type() == typeid(double)) {
            return compareAny<double>(a, b);
        } else if (a.type() == typeid(std::string)) {
            return compareAny<std::string>(a, b);
        } else if (a.type() == typeid(long long)) {
            return compareAny<long long>(a, b);
        }
    }
    return false;
}

std::vector<Instruction> Compiler::instructionsOptimizations(std::vector<Instruction> &instructions) {
    std::vector<Instruction> optimizedInstructions;

    for (size_t i = 0; i < instructions.size(); ++i) {
        auto &instr = instructions[i];

        if (instr.operationCode == Instruction::OperationCode::SAVE) {
            if (i + 1 < instructions.size() && instructions[i + 1].operationCode == Instruction::OperationCode::SAVE &&
                instr.register1 == instructions[i + 1].register1) {
                continue;
            }
        }

        if (instr.operationCode == Instruction::OperationCode::ADD ||
            instr.operationCode == Instruction::OperationCode::SUB ||
            instr.operationCode == Instruction::OperationCode::MUL ||
            instr.operationCode == Instruction::OperationCode::MOD) {
            if (i + 1 < instructions.size() && instructions[i + 1].operationCode == instr.operationCode &&
                instr.register1 == instructions[i + 1].register1 &&
                compareAnyValues(instr.register2, instructions[i + 1].register2)) {
                continue;
            }
        }

        if ((instr.operationCode == Instruction::OperationCode::ADD ||
             instr.operationCode == Instruction::OperationCode::SUB ||
             instr.operationCode == Instruction::OperationCode::MUL) &&
             instr.register2.has_value() && instr.register3.has_value() &&
             areIntOrLongLong(instr.register2, instr.register3)) {

            try {
                auto reg2_str = std::any_cast<std::string>(instr.register2);
                auto reg3_str = std::any_cast<std::string>(instr.register3);
                auto reg2 = std::stoi(reg2_str);
                auto reg3 = std::stoi(reg3_str);

                int result = 0;
                switch (instr.operationCode) {
                    case Instruction::OperationCode::ADD:
                        result = reg2 + reg3;
                        break;
                    case Instruction::OperationCode::SUB:
                        result = reg2 - reg3;
                        break;
                    case Instruction::OperationCode::MUL:
                        result = reg2 * reg3;
                        break;
                    default:
                        break;
                }

                optimizedInstructions.emplace_back(Instruction::OperationCode::SAVE, instr.register1, result);
                continue;
            } catch (const std::bad_any_cast &e) {
                std::cerr << "Unknown error in optimisation" << std::endl;
            }
        }

        optimizedInstructions.push_back(instr);
    }
    return optimizedInstructions;
}
