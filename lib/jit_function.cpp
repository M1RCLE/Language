#include "jit.h"
#include "jit_for_fusion.h"

/*
JitEntry* loopFusion(JitEntry &currentEntry) {
     const Instruction &currentInstruction = entryInstruction(currentEntry);
     // std::cerr << "LOOP FUSION FOR: " << instructionTypeStr(currentInstruction) << std::endl;
     std::vector instructions = currentInstruction.block;
     int current_line = 0;
     int for_line = -1;
     Instruction* first_instruction = nullptr;
     for (Instruction instruction: instructions) {
          if (instruction.operationCode == Instruction::OperationCode::FOR) {
               // std::cerr << "\tLOOP FUSION - FOR FOUND: " << instructionTypeStr(instruction) << std::endl;
               if (for_line == -1) {
                    for_line = current_line;
                    first_instruction = &instruction;
               } else if (for_line == current_line - 1) {
                    JitEntry* newEntry = loopFusion(currentEntry, for_line);
                    if (newEntry != nullptr) {
                         return newEntry;
                    }
                    for_line = current_line;
                    first_instruction = &instruction;
               } else {
                    for_line = -1;
               }
          } else {
               for_line = -1;
          }
          current_line++;
     }
     return nullptr;
}
*/
Instruction jit_function_process(Instruction instruction) {
    return jit_for_fusion_process(instruction);
}
