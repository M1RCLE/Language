#include "compiler.h"

long Compiler::getVariableIndex(const std::string& variableName) {
  if (variableIndexes.find(variableName) == variableIndexes.end()) {
    variableIndexes[variableName] = nextVariableIndex++;
  }
  return variableIndexes[variableName];
}

void Compiler::addUsedVariable(const std::any& operand) {
  if (operand.type() == typeid(std::string)) {
    const std::string& strOperand = std::any_cast<std::string>(operand);
    if (!isInteger(strOperand)) {
      usedVariables.insert(strOperand);
    }
  }
}

bool Compiler::isInteger(const std::string& str) {
  if (str.empty()) return false;
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

Instruction Compiler::compileLoop(const Instruction& loopInstruction) {
  return Instruction(Instruction::OpCode::LOOP, loopInstruction.operand1,
                     loopInstruction.operand2, loopInstruction.operand3,
                     loopInstruction.block);
}

std::vector<Instruction> Compiler::preprocessInstructions(
    const std::vector<Instruction>& instructions) {
  std::vector<Instruction> preprocessedInstructions;
  for (const auto& instruction : instructions) {
    std::vector<Instruction> processedBlock;
    switch (instruction.opCode) {
      case Instruction::OpCode::FUN:
        functions[instruction.operand1] = instruction;
        processedBlock = preprocessInstructions(instruction.block);
        preprocessedInstructions.emplace_back(Instruction::FunctionInstruction(
            instruction.operand1, instruction.parameters, processedBlock));
        break;

      case Instruction::OpCode::IF:
        if (!instruction.block.empty()) {
          processedBlock = preprocessInstructions(instruction.block);
          preprocessedInstructions.push_back(
              Instruction(instruction.opCode, instruction.operand1,
                          instruction.operand2, processedBlock));
        } else {
          preprocessedInstructions.push_back(instruction);
        }
        break;

      case Instruction::OpCode::LOOP:
        if (!instruction.block.empty()) {
          processedBlock = preprocessInstructions(instruction.block);
          preprocessedInstructions.push_back(compileLoop(instruction));
        } else {
          preprocessedInstructions.push_back(compileLoop(instruction));
        }
        break;

      default:
        preprocessedInstructions.push_back(instruction);
        break;
    }
  }
  return preprocessedInstructions;
}

std::vector<Instruction> Compiler::optimizeInstructions(
    const std::vector<Instruction>& instructions) {
  std::vector<Instruction> optimizeInstructions;
  for (size_t i = 0; i < instructions.size(); ++i) {
    Instruction current = instructions[i];

    if (i + 1 < instructions.size()) {
      Instruction next = instructions[i + 1];
      if (current.opCode == Instruction::OpCode::STORE &&
          next.opCode == Instruction::OpCode::STORE &&
          current.target == next.operand1 &&
          std::any_cast<std::string>(next.operand2) == next.operand1) {
        optimizeInstructions.push_back(current);
        i++;
      } else {
        optimizeInstructions.push_back(current);
      }
    } else {
      optimizeInstructions.push_back(current);
    }
  }

  return optimizeInstructions;
}

std::vector<Instruction> Compiler::filterDeadCode(
    const std::vector<Instruction>& instructions) {
  std::vector<Instruction> optimizedInstructions;

  for (auto it = instructions.rbegin(); it != instructions.rend(); ++it) {
    const auto& instruction = *it;
    switch (instruction.opCode) {
      case Instruction::OpCode::PRINT:
        usedVariables.insert(instruction.operand1);
        optimizedInstructions.push_back(instruction);
        break;

      case Instruction::OpCode::ADD:
      case Instruction::OpCode::SUB:
      case Instruction::OpCode::MUL:
      case Instruction::OpCode::MOD:
        if (!instruction.target.empty() &&
                usedVariables.contains(instruction.target) ||
            usedVariables.contains(instruction.operand1)) {
          addUsedVariable(instruction.operand2);
          addUsedVariable(instruction.operand3);
          optimizedInstructions.push_back(instruction);
        }
        break;

      case Instruction::OpCode::STORE:
        if (!instruction.target.empty() &&
                usedVariables.contains(instruction.target) ||
            usedVariables.contains(instruction.operand1)) {
          addUsedVariable(instruction.operand2);
          optimizedInstructions.push_back(instruction);
        }
        break;

      case Instruction::OpCode::IF:
      case Instruction::OpCode::LOOP:
        usedVariables.insert(instruction.operand1);
        addUsedVariable(instruction.operand3);
        if (!instruction.block.empty()) {
          std::vector<Instruction> reversedBlock =
              filterDeadCode(instruction.block);
          std::reverse(reversedBlock.begin(), reversedBlock.end());
          optimizedInstructions.push_back(
              Instruction(instruction.opCode, instruction.operand1,
                          instruction.operand2, reversedBlock));
        }
        break;

      case Instruction::OpCode::CALL:
        if (instruction.operand2.type() == typeid(std::vector<std::any>)) {
          const auto& args =
              std::any_cast<std::vector<std::any>>(instruction.operand2);
          for (const auto& arg : args) {
            addUsedVariable(arg);
          }
        }
        optimizedInstructions.push_back(instruction);
        break;
      case Instruction::OpCode::STORE_ARRAY_VAR:
        if (!instruction.target.empty() &&
            usedVariables.contains(instruction.target)) {
          usedVariables.insert(instruction.operand1);
          usedVariables.insert(
              std::any_cast<std::string>(instruction.operand2));
          optimizedInstructions.push_back(instruction);
        }

      default:
        optimizedInstructions.push_back(instruction);
        break;
    }
  }

  return optimizedInstructions;
}

void Compiler::writeInstruction(std::ofstream& out, const Instruction& instr) {
  out.put(static_cast<char>(instr.opCode));

  switch (instr.opCode) {
    case Instruction::OpCode::FUN: {
      if (!instr.operand1.empty()) {
        out.write(instr.operand1.data(), instr.operand1.size());
        out.put('\0');
      }
      auto params_size = instr.parameters.size();
      out.write(reinterpret_cast<const char*>(&params_size), sizeof(size_t));
      for (const auto& param : instr.parameters) {
        out.write(param.data(), param.size());
        out.put('\0');
      }
      size_t blockSize = instr.block.size();
      out.write(reinterpret_cast<const char*>(&blockSize), sizeof(size_t));
      for (const auto& blockInstr : instr.block) {
        writeInstruction(out, blockInstr);
      }
      break;
    }
    case Instruction::OpCode::RETURN: {
      if (!instr.operand1.empty()) {
        out.write(instr.operand1.data(), instr.operand1.size());
        out.put('\0');
      }
      if (instr.operand2.has_value()) {
        writeInstruction(out, std::any_cast<Instruction>(instr.operand2));
      }
      break;
    }
    case Instruction::OpCode::IF: {
      if (!instr.operand1.empty()) {
        out.write(instr.operand1.data(), instr.operand1.size());
        out.put('\0');
      }

      auto op2 = std::any_cast<std::string>(instr.operand2);
      auto op3 = std::any_cast<std::string>(instr.operand3);

      if (instr.operand2.has_value()) {
        out.write(op2.data(), op2.size());
        out.put('\0');
      }

      if (instr.operand3.has_value()) {
        out.write(op3.data(), op3.size());
        out.put('\0');
      }

      size_t blockSize = instr.block.size();
      out.write(reinterpret_cast<const char*>(&blockSize), sizeof(size_t));
      for (const auto& blockInstr : instr.block) {
        writeInstruction(out, blockInstr);
      }
      break;
    }
    case Instruction::OpCode::LOOP: {
      if (!instr.operand1.empty()) {
        out.write(instr.operand1.data(), instr.operand1.size());
        out.put('\0');
      }

      auto op2 = std::any_cast<std::string>(instr.operand2);
      auto op3 = std::any_cast<std::string>(instr.operand3);

      if (instr.operand2.has_value()) {
        out.write(op2.data(), op2.size());
        out.put('\0');
      }

      if (instr.operand3.has_value()) {
        out.write(op3.data(), op3.size());
        out.put('\0');
      }

      size_t blockSize = instr.block.size();
      out.write(reinterpret_cast<const char*>(&blockSize), sizeof(size_t));
      for (const auto& blockInstr : instr.block) {
        writeInstruction(out, blockInstr);
      }
      break;
    }
    default: {
      if (!instr.operand1.empty()) {
        out.write(instr.operand1.data(), instr.operand1.size());
        out.put('\0');
      }

      auto op2 = std::any_cast<std::string>(instr.operand2);
      auto op3 = std::any_cast<std::string>(instr.operand3);

      if (instr.operand2.has_value()) {
        out.write(op2.data(), op2.size());
        out.put('\0');
      }

      if (instr.operand3.has_value()) {
        out.write(op3.data(), op3.size());
        out.put('\0');
      }
      break;
    }
  }
}

Compiler::Compiler(const std::vector<Instruction>& instructions)
    : instructions(instructions) {}

void Compiler::saveToFile(const std::string& filename) {
  std::ofstream out(filename, std::ios::binary);
  if (!out) {
    throw std::runtime_error("Error opening file for writing");
  }

  auto preporcessedInstructions = preprocessInstructions(instructions);
  auto filteredInstructions = filterDeadCode(preporcessedInstructions);
  std::reverse(filteredInstructions.begin(), filteredInstructions.end());
  auto optimizedInstructions = optimizeInstructions(filteredInstructions);

  for (const auto& instr : optimizedInstructions) {
    writeInstruction(out, instr);
  }
}