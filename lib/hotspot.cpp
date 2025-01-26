#include <map>
#include "hotspot.h"


const Instruction& HotSpot::hotSwap(const Instruction &instruction) {
    if ( instruction.operationCode == Instruction::OperationCode::CALL ||
         instruction.operationCode == Instruction::OperationCode::WHILE ||
         instruction.operationCode == Instruction::OperationCode::FOR )
    {
        if (this->calls.find(instruction.operationId) == this->calls.end())
        {
            this->calls[instruction.operationId] = new InstructionEntry(instruction);
        }
        else
        {
            InstructionEntry* entry = this->calls[instruction.operationId];
            if (entry->calls == 5)
            {
                const Instruction& jittered = this->jitter.process(instruction);
                entry = new InstructionEntry(instruction, jittered, 6);
                delete this->calls[instruction.operationId];
                this->calls[instruction.operationId] = entry;
                return jittered;
            } else if (entry->calls > 5) {
                entry->calls++;            
                return this->calls[instruction.operationId]->jittered;
            }
            entry->calls++;            

        }
    }
    return instruction;
}
