#ifndef HOTSPOT_H
#define HOTSPOT_H

#include <map>
#include "instruction.h"
#include "jit.h"

struct InstructionEntry {
    long calls = 0;
    const Instruction &original;
    const Instruction &jittered;

    InstructionEntry(const Instruction &original, const Instruction &jittered, long calls) :
        original(original), jittered(jittered), calls(calls) {};

    InstructionEntry(const Instruction &original) :
        original(original), jittered(original) {};

};

class HotSpot {

private:

    std::map<long, InstructionEntry*> calls;
    Jit jitter;

public:

    HotSpot() {}

    const Instruction& hotSwap(const Instruction &instruction);

};

#endif
