#include "jit_for_fusion.h"

bool checkLoopFusuin(Instruction &firstLoop, Instruction &secondLoop) {
     std::vector<std::string> attr;
     attr.emplace_back(firstLoop.register1);
     for(Instruction inst:firstLoop.block) {
          attr.emplace_back(inst.register1);
     }
     for(Instruction inst:secondLoop.block) {
          if (std::find(attr.begin(), attr.end(),inst.register1)!=attr.end()) {
               return false;
          }
     }
     return true;
}

Instruction* buildLoopInstruction(Instruction* currentInstruction, Instruction &firstLoop, Instruction &secondLoop, int line_num) {
     Instruction* newInstruction = new Instruction(currentInstruction, nullptr);
     std::cerr << ">>\tREWRITE: " << instructionTypeStr(currentInstruction) << " - " << currentInstruction->register1 << std::endl;
     int pos = 0;
     Instruction* newLoop = nullptr;
     for (Instruction instruction: currentInstruction->block) {
          if (pos < line_num || pos > line_num+1) {
               std::cerr << "\t\t" << instructionTypeStr(instruction) << " - " << instruction.register1 << std::endl;
               newInstruction->block.emplace_back(instruction);
          } else if (pos == line_num) {
               newLoop = new Instruction(&instruction, nullptr);
               std::cerr << "\t\t" << instructionTypeStr(instruction) << " - " << instruction.register1 << std::endl;
               for (Instruction first: instruction.block) {
                    newLoop->block.emplace_back(first);
                    std::cerr << "\t\t\t" << instructionTypeStr(first) << " - " << first.register1 << std::endl;
               }
              newInstruction->block.emplace_back(newLoop);
          } else if (pos == line_num+1) {
               for (Instruction second: instruction.block) {
                    newLoop->block.emplace_back(second);
                    std::cerr << "\t\t\t" << instructionTypeStr(second) << " - " << second.register1 << std::endl;
               }
          }
          pos++;
     }
     std::cerr << "\t\tLOOP FUSION PROCESS: " << instructionTypeStr(*newInstruction) << std::endl;
     return newInstruction;
//     Instruction newInstruction = new Instruction(currentInstruction);
//     std::cerr << "RETURN JITTERED: " << instructionTypeStr(newInstruction) << std::endl;
//     return new Instruction(currentInstruction);
}

Instruction* loopFusion(Instruction* currentInstruction, int line_num) {
     Instruction &firstLoop = currentInstruction->block[line_num];
     Instruction &secondLoop = currentInstruction->block[line_num+1];
     if ( firstLoop.register1 != secondLoop.register1 ||
          std::any_cast<std::string>(firstLoop.register2) != std::any_cast<std::string>(secondLoop.register2) ||
          std::any_cast<std::string>(firstLoop.register3) != std::any_cast<std::string>(secondLoop.register3))
          {
               return nullptr;
          }
     if (!checkLoopFusuin(firstLoop, secondLoop) || !checkLoopFusuin(secondLoop, firstLoop)) {
          return nullptr;
     }
     Instruction* newInstruction = new Instruction(currentInstruction);
     return buildLoopInstruction(currentInstruction, firstLoop, secondLoop, line_num);
}

Instruction* jit_for_fusion_process(Instruction* currentInstruction) {
     std::cerr << "LOOP FUSION FOR: " << instructionTypeStr(currentInstruction) << std::endl;
     std::vector instructions = currentInstruction->block;
     int current_line = 0;
     int for_line = -1;
     Instruction* first_instruction = nullptr;
     for (Instruction instruction: instructions) {
          if (instruction.operationCode == Instruction::OperationCode::FOR) {
               std::cerr << "\tLOOP FUSION - FOR FOUND: " << instructionTypeStr(instruction) << std::endl;
               if (for_line == -1) {
                    for_line = current_line;
                    first_instruction = &instruction;
               } else if (for_line == current_line - 1) {
                    Instruction* newEntry = loopFusion(currentInstruction, for_line);
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
    std::cerr << "LOOP FUSION FOR: " << instructionTypeStr(currentInstruction) << " WAS NOT FOUND" << std::endl;
    return nullptr;;
}
