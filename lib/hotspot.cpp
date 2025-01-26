#include <map>
#include "hotspot.h"


const Instruction& HotSpot::hotSwap(const Instruction &instruction) {
    if ( instruction.operationCode == Instruction::OperationCode::CALL ||
         instruction.operationCode == Instruction::OperationCode::WHILE ||
         instruction.operationCode == Instruction::OperationCode::FOR )
    {
        InstructionEntry* entry;
        if (this->calls.find(instruction.operationId) == this->calls.end())
        {
            entry = new InstructionEntry(instruction, 1);
            this->calls[instruction.operationId] = entry;
        }
        else
        {
            entry = this->calls[instruction.operationId];
            if (entry->calls == 5)
            {
                const Instruction& jittered = this->jitter.process(instruction);
                entry = new InstructionEntry(instruction, jittered, 6);
                delete this->calls[instruction.operationId];
                this->calls[instruction.operationId] = entry;
                return jittered;
            } else {
                entry->calls++;
            }
        }
        entry->startTime = std::chrono::high_resolution_clock::now();
    }
    return instruction;
}

const void HotSpot::hotStat(const Instruction &instruction) {
    // Здесь обрабатываем вызов статистики
    if (this->calls.find(instruction.operationId) != this->calls.end())
    {
        InstructionEntry& entry = *(this->calls[instruction.operationId]);
        long duration = (std::chrono::high_resolution_clock::now() - entry.startTime).count();
        if (entry.calls < 5) {
            std::cerr << "original instruction #" << instruction.operationId << " stat: " << duration << std::endl;
        } else if (entry.calls >= 10 && entry.calls < 20) {
            std::cerr << "jittered instruction #" << instruction.operationId << " stat: " << duration << std::endl;
        }
    }

}
