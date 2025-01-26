#include "instruction.h"
#include "utils.h"

static long operationSequence = 0;

long nextOperationId() {
    return ++operationSequence;
}

const std::string instructionTypeStr(const Instruction &instruction) {
    std::string result = instruction.operationCode == Instruction::OperationCode::FUNC ? "function::" + instruction.register1 
             : instruction.operationCode == Instruction::OperationCode::WHILE ? "while-loop"
             : instruction.operationCode == Instruction::OperationCode::FOR ? "for-loop"
             : "regular";
    return result + "[#" + std::to_string(instruction.operationId) + "]";
}

bool Instruction::operator==(const Instruction &instr) const {
  if (operationCode == instr.operationCode) {
    return true;
  }
  return false;
}