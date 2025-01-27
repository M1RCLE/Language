#include "instruction.h"
#include "utils.h"

static long operationSequence = 0;

long nextOperationId() {
    return ++operationSequence;
}

const std::string instructionTypeStr(const Instruction &instruction) {
    std::string str = (instruction.operationCode == Instruction::OperationCode::EMPTY ? "EMPTY" :
            instruction.operationCode == Instruction::OperationCode::SAVE ? "SAVE" :
            instruction.operationCode == Instruction::OperationCode::PRINT ? "PRINT" :
            instruction.operationCode == Instruction::OperationCode::ARRAY ? "ARRAY" :
            instruction.operationCode == Instruction::OperationCode::ADD ? "ADD" :
            instruction.operationCode == Instruction::OperationCode::SUB ? "SUB" :
            instruction.operationCode == Instruction::OperationCode::MUL ? "MUL" :
            instruction.operationCode == Instruction::OperationCode::LESS ? "LESS" :
            instruction.operationCode == Instruction::OperationCode::GREATER ? "GREATER" :
            instruction.operationCode == Instruction::OperationCode::EQUALS ? "EQUALS" :
            instruction.operationCode == Instruction::OperationCode::NOT_EQUALS ? "NOT_EQUALS" :
            instruction.operationCode == Instruction::OperationCode::IF ? "IF" :
            instruction.operationCode == Instruction::OperationCode::WHILE ? "WHILE" :
            instruction.operationCode == Instruction::OperationCode::FUNC ? "FUNC" :
            instruction.operationCode == Instruction::OperationCode::RETURN ? "RETURN" :
            instruction.operationCode == Instruction::OperationCode::NEW ? "NEW" :
            instruction.operationCode == Instruction::OperationCode::READ_INDEX ? "READ_INDEX" :
            instruction.operationCode == Instruction::OperationCode::WRITE_INDEX ? "WRITE_INDEX" :
            instruction.operationCode == Instruction::OperationCode::ARRAY_VARIABLE_STORAGE ? "ARRAY_VARIABLE_STORAGE" :
            instruction.operationCode == Instruction::OperationCode::CALL ? "CALL" :
            instruction.operationCode == Instruction::OperationCode::MOD ? "MOD" :
            instruction.operationCode == Instruction::OperationCode::COMMA ? "COMMA" :
            instruction.operationCode == Instruction::OperationCode::COLON ? "COLON" :
            instruction.operationCode == Instruction::OperationCode::FOR ? "FOR" :
            "regular");
        return str + "[#" + std::to_string(instruction.operationId) + "]";
}

bool Instruction::operator==(const Instruction &instr) const {
  if (operationCode == instr.operationCode) {
    return true;
  }
  return false;
}