#ifndef HOTSPOT_H
#define HOTSPOT_H

#include <map>
#include "instruction.h"
#include "jit.h"

struct InstructionEntry {
    long calls;
    const Instruction &original;
    const Instruction &jittered;
    long originalTime = 0;
    long jitterTime = 0;
    std::chrono::high_resolution_clock::time_point startTime;

    InstructionEntry(const Instruction &original, const Instruction &jittered, long calls) :
        original(original), jittered(jittered), calls(calls) {};

    InstructionEntry(const Instruction &original) :
        original(original), jittered(original), calls(0) {};

    InstructionEntry(const Instruction &original, long calls) :
        original(original), jittered(original), calls(calls) {};

};

class HotSpot {

private:

    std::map<long, InstructionEntry*> calls;
    Jit jitter;

public:

    HotSpot() {}

    const Instruction& hotSwap(const Instruction &instruction);
    const void hotStat(const Instruction &instruction);

};

#endif
