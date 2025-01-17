#include "compiler.h"

Compiler::Compiler(const std::vector<Instruction>& instructions) : instructions(instructions) {}

void Compiler::saveToFile(const std::string& filename) {
    std::ofstream out(filename, std::ios::binary);
    if (!out) {
        throw std::runtime_error("Error opening file for writing bytecode.");
    }

    // Процессинг и оптимизация инструкций
    auto filteredInstructions = reverseList(filterDeadCode(preprocessInstructions(instructions)));
    auto optimizedInstructions = optimizeInstructions(filteredInstructions);

    for (const auto& instr : optimizedInstructions) {
        writeInstruction(out, instr);
    }
}

std::vector<Instruction> Compiler::reverseList(const std::vector<Instruction>& original) {
    std::vector<Instruction> reversed;
    for (auto it = original.rbegin(); it != original.rend(); ++it) {
        reversed.push_back(*it);
    }
    return reversed;
}

std::vector<Instruction> Compiler::preprocessInstructions(const std::vector<Instruction>& instructions) {
    std::vector<Instruction> preprocessedInstructions;

    for (const auto& instruction : instructions) {
        std::vector<Instruction> processedBlock;
        switch (instruction.opCode) {
            case Instruction::OpCode::FUN:
                functions[instruction.operand1] = instruction;
                processedBlock = preprocessInstructions(instruction.block);
                preprocessedInstructions.push_back(Instruction::FunctionInstruction(instruction.operand1, instruction.parameters, processedBlock));
                break;
            case Instruction::OpCode::IF:
                if (!instruction.block.empty()) {
                    processedBlock = preprocessInstructions(instruction.block);
                    instruction.block = processedBlock;
                }
                preprocessedInstructions.push_back(instruction);
                break;
            case Instruction::OpCode::LOOP:
                if (!instruction.block.empty()) {
                    processedBlock = preprocessInstructions(instruction.block);
                    instruction.block = processedBlock;
                }
                preprocessedInstructions.push_back(compileLoop(instruction));
                break;
            // Остальные операции остаются без изменений
            default:
                preprocessedInstructions.push_back(instruction);
                break;
        }
    }

    return preprocessedInstructions;
}

std::vector<Instruction> Compiler::optimizeInstructions(const std::vector<Instruction>& instructions) {
    std::vector<Instruction> optimizedInstructions;

    for (size_t i = 0; i < instructions.size(); ++i) {
        const Instruction& current = instructions[i];

        if (i + 1 < instructions.size()) {
            const Instruction& next = instructions[i + 1];

            // Устранение избыточных STORE
            if (current.opCode == Instruction::OpCode::STORE &&
                next.opCode == Instruction::OpCode::STORE &&
                current.target == next.operand1 &&
                next.operand2 == current.operand1) {
                optimizedInstructions.push_back(current);
                ++i; // Пропуск следующей инструкции
            } else {
                optimizedInstructions.push_back(current);
            }
        } else {
            optimizedInstructions.push_back(current);
        }
    }

    return optimizedInstructions;
}

std::vector<Instruction> Compiler::filterDeadCode(std::vector<Instruction>& instructions) {
    std::vector<Instruction> optimizedInstructions;

    for (auto it = instructions.rbegin(); it != instructions.rend(); ++it) {
        const Instruction& instruction = *it;

        switch (instruction.opCode) {
            case Instruction::OpCode::PRINT:
                usedVariables.insert(instruction.operand1);
                optimizedInstructions.push_back(instruction);
                break;
            case Instruction::OpCode::ADD:
            case Instruction::OpCode::SUB:
            case Instruction::OpCode::MUL:
            case Instruction::OpCode::MOD:
                if (usedVariables.count(instruction.target) || usedVariables.count(instruction.operand1)) {
                    usedVariables.insert(std::get<std::string>(instruction.operand2));
                    usedVariables.insert(std::get<std::string>(instruction.operand3));
                    optimizedInstructions.push_back(instruction);
                }
                break;
            case Instruction::OpCode::STORE:
                if (usedVariables.count(instruction.target) || usedVariables.count(instruction.operand1)) {
                    addUsedVariable(instruction.operand2);
                    optimizedInstructions.push_back(instruction);
                }
                break;
            // Дополнительная логика для IF, LOOP, и других инструкций
            default:
                optimizedInstructions.push_back(instruction);
                break;
        }
    }

    return optimizedInstructions;
}

long Compiler::getVariableIndex(const std::string& variableName) {
    return variableIndexes[variableName] = variableIndexes.count(variableName) ? variableIndexes[variableName] : nextVariableIndex++;
}

Instruction Compiler::compileLoop(const Instruction& loopInstruction) {
    return Instruction(Instruction::OpCode::LOOP, loopInstruction.operand1, loopInstruction.operand2, loopInstruction.operand3, loopInstruction.block);
}

void Compiler::writeInstruction(std::ofstream& out, const Instruction& instr) {
    out.put(static_cast<char>(static_cast<int>(instr.opCode))); // Запись кода операции

    switch (instr.opCode) {
        case Instruction::OpCode::FUN:
            out.write(instr.operand1.c_str(), instr.operand1.size());
            out.put('\0'); // Завершающий символ для строки
            out.write(reinterpret_cast<const char*>(&instr.parameters.size()), sizeof(instr.parameters.size()));
            for (const auto& param : instr.parameters) {
                out.write(param.c_str(), param.size());
                out.put('\0');
            }
            out.write(reinterpret_cast<const char*>(&instr.block.size()), sizeof(instr.block.size()));
            for (const auto& blockInstr : instr.block) {
                writeInstruction(out, blockInstr);
            }
            break;
        case Instruction::OpCode::RETURN:
            out.write(instr.operand1.c_str(), instr.operand1.size());
            out.put('\0');
            if (std::holds_alternative<Instruction>(instr.operand2)) {
                writeInstruction(out, std::get<Instruction>(instr.operand2));
            }
            break;
        // Остальные случаи для IF, LOOP и других инструкций
        default:
            out.write(instr.operand1.c_str(), instr.operand1.size());
            out.put('\0');
            out.write(reinterpret_cast<const char*>(&instr.operand2), sizeof(instr.operand2));
            out.write(reinterpret_cast<const char*>(&instr.operand3), sizeof(instr.operand3));
            break;
    }
}

void Compiler::addUsedVariable(const std::variant<std::string, int, float>& operand) {
    if (std::holds_alternative<std::string>(operand)) {
        usedVariables.insert(std::get<std::string>(operand));
    }
}

bool Compiler::isInteger(const std::string& str) {
    try {
        std::stoi(str);
        return true;
    } catch (...) {
        return false;
    }
}
