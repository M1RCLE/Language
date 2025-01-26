#include "jit.h"

bool shouldUnroll(const Instruction& instruction) {
  try {
    long startValue = std::any_cast<long>(instruction.register2);
    long endValue = std::any_cast<long>(instruction.register3);
    return (endValue - startValue) <= 8;  // Разворачиваем, если итераций <= 8
  } catch (const std::bad_any_cast&) {
    return false;  // Невозможно развернуть цикл, если диапазон не числовой
  }
}

void replaceVariable(Instruction& instruction, const std::string& variable,
                     long value) {
  if (instruction.register1 == variable) {
    instruction.register1 = std::to_string(value);
  }
  if (instruction.register2.type() == typeid(std::string) &&
      std::any_cast<std::string>(instruction.register2) == variable) {
    instruction.register2 = value;
  }
  if (instruction.register3.type() == typeid(std::string) &&
      std::any_cast<std::string>(instruction.register3) == variable) {
    instruction.register3 = value;
  }
}

Instruction unrollLoop(const Instruction& instruction) {
  Instruction unrolledLoop;
  unrolledLoop.operationCode =
      Instruction::OperationCode::FOR;
  long startValue = std::any_cast<long>(instruction.register2);
  long endValue = std::any_cast<long>(instruction.register3);
  std::string variableName = instruction.register1;

  // Генерируем инструкции для каждой итерации цикла
  for (long i = startValue; i < endValue; ++i) {
    for (const auto& innerInstruction : instruction.block) {
      Instruction iteration = innerInstruction;
      replaceVariable(iteration, variableName, i);
      unrolledLoop.block.push_back(iteration);
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