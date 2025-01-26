#include <map>
#include "hotspot.h"

#define STEP_TO_JIT 10
#define STEP_TO_FIX 50

const Instruction& HotSpot::hotSwap(const Instruction &instruction) {
    if ( instruction.operationCode == Instruction::OperationCode::FUNC ||
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
            // Если сработало STEP_TO_JIT - обрабатываем jitterom;
            if (entry->calls == STEP_TO_JIT)
            {
                const Instruction& jittered = this->jitter.process(instruction);
                long originalTime = entry->originalTime;
                entry = new InstructionEntry(instruction, jittered, STEP_TO_JIT+1);
                entry->originalTime = originalTime;
                delete this->calls[instruction.operationId];
                entry->startTime = std::chrono::high_resolution_clock::now();
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
    
        if (entry.calls <= STEP_TO_JIT) {
            // std::cerr << "instruction #" << instruction.operationId << " original call duration: " << duration << std::endl;
            entry.originalTime += duration;
        } else if (entry.calls <= STEP_TO_FIX) {
            // std::cerr << "instruction #" << instruction.operationId << " jittered call duration: " << duration << std::endl;
            entry.jitterTime += duration;
        }
        if (entry.calls == STEP_TO_JIT) {
            double avg = entry.originalTime / duration;
        } else if (entry.calls == STEP_TO_FIX) {
            long originalAvgTime = entry.originalTime / STEP_TO_JIT;
            long jitteredAvgTime = (entry.jitterTime / (STEP_TO_FIX-STEP_TO_JIT));
            std::cerr << "instruction " << instructionTypeStr(instruction) << " original avr time: " << originalAvgTime << ", jittered avr time: " << jitteredAvgTime << std::endl;
            if (jitteredAvgTime > originalAvgTime) {
                std::cerr << "instruction " << instructionTypeStr(instruction) << " jit code has been rejected" << std::endl;
                InstructionEntry* newEntry = new InstructionEntry(instruction, entry.original, STEP_TO_FIX+1);
                delete &entry;
                this->calls[instruction.operationId] = newEntry;
            } else {
                std::cerr << "instruction " << instructionTypeStr(instruction) << " jit code has been approved" << std::endl;
            }
        }
    }
}

