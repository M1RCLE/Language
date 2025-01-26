#include "jit.h"

bool shouldUnroll(const Instruction& instruction) {
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

Instruction unrollLoop(const Instruction& instruction) {
  Instruction unrolledLoop;
  unrolledLoop.operationCode = Instruction::OperationCode::FOR;
  std::string variableName = std::any_cast<std::string>(instruction.register1);
  long startValue =
      std::stol(std::any_cast<std::string>(instruction.register2));
  long endValue = std::stol(std::any_cast<std::string>(instruction.register3));
  Instruction instructionStore = Instruction(Instruction::OperationCode::SAVE,
                                             variableName, startValue, nullptr);
  Instruction instructionAdd = Instruction(Instruction(
      Instruction::OperationCode::ADD, variableName, variableName, 1));

      unrolledLoop.block.push_back(instructionStore);

  for (long i = startValue; i < endValue; ++i) {
    for (const auto& innerInstruction : instruction.block) {
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
  if (shouldUnroll(instruction)) {
    std::cerr << "Unrolling FOR loop: " << instructionTypeStr(instruction)
              << std::endl;
    processedInstruction = unrollLoop(instruction);
    return processedInstruction;
  }

  return instruction;
}