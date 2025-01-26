#include "jit.h"

#include "utils.h"

bool shouldUnrollFor(const Instruction& instruction) {
  try {
    long startValue =
        std::stol(std::any_cast<std::string>(instruction.register2));
    long endValue =
        std::stol(std::any_cast<std::string>(instruction.register3));
    return (endValue - startValue) <= 8;
  } catch (const std::bad_any_cast&) {
    return false;
  }
}

Instruction unrollIf(const Instruction& instruction) {
     Instruction inst = Instruction(instruction);
  int i = 0;
  while (i < inst.block.size()) {
    if (inst.block[i].operationCode == Instruction::OperationCode::IF) {
      if (inst.block[i].register3.type() != typeid(std::string)) {
        ++i;
        continue;
      }
      std::string register3 =
          std::any_cast<std::string>(inst.block[i].register3);
      if (is_number(inst.block[i].register1) && is_number(register3)) {
        long first = std::stol(inst.block[i].register1);
        long second = std::stol(register3);
        std::string conditionType = Instruction::opCodeToString(
            std::any_cast<Instruction::OperationCode>(
                instruction.block[i].register2));
        bool canUnroll = false;
        if (conditionType == "LESS") {
          canUnroll = first < second;
        } else if (conditionType == "GREATER") {
          canUnroll = first > second;
        } else if (conditionType == "EQUALS") {
          canUnroll = first == second;
        } else if (conditionType == "NOT_EQUALS") {
          canUnroll = first != second;
        }

        if (canUnroll) {
          inst.block.insert(inst.block.begin() + i + 1,
                            inst.block[i].block.begin(),
                            inst.block[i].block.end());
          int plusI = inst.block[i].block.size();
          inst.block.erase(inst.block.begin() + i);
          i += plusI;
        } else {
          inst.block.erase(inst.block.begin() + i);
        }
        continue;
      }
    }
    ++i;
  }
  return inst;
}

Instruction unrollLoop(Instruction& instruction) {
  Instruction instr = unrollIf(instruction);
  Instruction unrolledLoop;
  unrolledLoop.operationCode = Instruction::OperationCode::FOR;
  std::string variableName = std::any_cast<std::string>(instr.register1);
  long startValue = std::stol(std::any_cast<std::string>(instr.register2));
  long endValue = std::stol(std::any_cast<std::string>(instr.register3));
  Instruction instructionStore = Instruction(Instruction::OperationCode::SAVE,
                                             variableName, startValue, nullptr);
  Instruction instructionAdd = Instruction(Instruction(
      Instruction::OperationCode::ADD, variableName, variableName, 1));

  unrolledLoop.block.push_back(instructionStore);

  for (long i = startValue; i < endValue; ++i) {
    for (const auto& innerInstruction : instr.block) {
      Instruction iteration = innerInstruction;
      unrolledLoop.block.push_back(iteration);
      unrolledLoop.block.push_back(instructionAdd);
    }
  }

  return unrolledLoop;
}

Instruction Jit::process(Instruction& instruction) {
  if (instruction.operationCode != Instruction::OperationCode::FOR) {
    return instruction;
  }
  Instruction processedInstruction;
  if (shouldUnrollFor(instruction)) {
    std::cerr << "Unrolling FOR loop: " << instructionTypeStr(instruction)
              << std::endl;
    processedInstruction = unrollLoop(instruction);
    return processedInstruction;
  }

  return instruction;
}