#include "compiler.h"

std::string anyToStringCompiler(const std::any& value) {
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
    auto opCode = std::any_cast<Instruction::OpCode>(value);
    auto c = static_cast<char>(opCode);
    std::string s(1, c);
    return s;
  } else if (value.type() == typeid(std::vector<std::string>)) {
    std::string res;
    auto vec = std::any_cast<std::vector<std::string>>(value);
    for (int i = 0; i < vec.size(); ++i) {
      if (!res.empty()) {
        res += ',';
      }
      res += vec[i];
    }
    return res;
  }
  return "";
}

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
    std::vector<Instruction>& instructions) {
  std::vector<Instruction> preprocessedInstructions;
  for (auto& instruction : instructions) {
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
      case Instruction::OpCode::ADD:
      case Instruction::OpCode::SUB:
      case Instruction::OpCode::MUL:
      case Instruction::OpCode::MOD:
      case Instruction::OpCode::STORE:
      case Instruction::OpCode::LESS:
      case Instruction::OpCode::GREATER:
      case Instruction::OpCode::EQUALS:
      case Instruction::OpCode::NOT_EQUALS:
      case Instruction::OpCode::NEW:
      case Instruction::OpCode::WRITE_INDEX:
        instruction.target = instruction.operand1;
        preprocessedInstructions.push_back(instruction);
        break;
      case Instruction::OpCode::STORE_ARRAY_VAR:
        instruction.target = anyToStringCompiler(instruction.operand3);
        preprocessedInstructions.push_back(instruction);
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
          anyToStringCompiler(next.operand2) == next.operand1) {
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
    std::vector<Instruction>& instructions) {
  std::vector<Instruction> optimizedInstructions;

  for (auto it = instructions.rbegin(); it != instructions.rend(); ++it) {
    auto& instruction = *it;
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
          usedVariables.insert(anyToStringCompiler(instruction.operand2));
          usedVariables.insert(anyToStringCompiler(instruction.operand3));
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
          instruction.block = reversedBlock;
        }
        optimizedInstructions.push_back(instruction);
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
  auto c = static_cast<char>(instr.opCode);
  out << c;
  out << '\0';

  switch (instr.opCode) {
    case Instruction::OpCode::FUN: {
      if (!instr.operand1.empty()) {
        out << instr.operand1;
      } else {
        out << "";
      }
      out << '\0';
      auto params_size = instr.parameters.size();
      out.write(reinterpret_cast<const char*>(&params_size), sizeof(size_t));
      for (const auto& param : instr.parameters) {
        out << param;
        out << '\0';
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
        out << instr.operand1;
      } else {
        out << "";
      }
      out << '\0';
      if (instr.operand2.has_value()) {
        writeInstruction(out, std::any_cast<Instruction>(instr.operand2));
      }
      break;
    }
    case Instruction::OpCode::IF: {
      if (!instr.operand1.empty()) {
        out << instr.operand1;
      } else {
        out << "";
      }
      out << '\0';

      if (instr.operand2.has_value()) {
        auto op2 = anyToStringCompiler(instr.operand2);
        out << op2[0];
      } else {
        out << "";
      }
      out << '\0';

      if (instr.operand3.has_value()) {
        auto op3 = anyToStringCompiler(instr.operand3);
        out << op3;
      } else {
        out << "";
      }
      out << '\0';

      size_t blockSize = instr.block.size();
      out.write(reinterpret_cast<const char*>(&blockSize), sizeof(size_t));
      for (const auto& blockInstr : instr.block) {
        writeInstruction(out, blockInstr);
      }
      break;
    }
    case Instruction::OpCode::LOOP: {
      if (!instr.operand1.empty()) {
        out << instr.operand1;
      } else {
        out << "";
      }
      out << '\0';

      if (instr.operand2.has_value()) {
        auto op2 = anyToStringCompiler(instr.operand2);
        out << op2[0];
      } else {
        out << "";
      }
      out << '\0';

      if (instr.operand3.has_value()) {
        auto op3 = anyToStringCompiler(instr.operand3);
        out << op3;
      } else {
        out << "";
      }
      out << '\0';

      size_t blockSize = instr.block.size();
      out.write(reinterpret_cast<const char*>(&blockSize), sizeof(size_t));
      for (const auto& blockInstr : instr.block) {
        writeInstruction(out, blockInstr);
      }
      break;
    }
    default: {
      if (!instr.operand1.empty()) {
        out << instr.operand1;
      } else {
        out << "";
      }
      out << '\0';

      if (instr.operand2.has_value()) {
        auto op2 = anyToStringCompiler(instr.operand2);
        out << op2;
      } else {
        out << "";
      }
      out << '\0';

      if (instr.operand3.has_value()) {
        auto op3 = anyToStringCompiler(instr.operand3);
        out << op3;
      } else {
        out << "";
      }
      out << '\0';
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