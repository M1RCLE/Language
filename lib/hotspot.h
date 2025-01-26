#ifndef HOTSPOT_H
#define HOTSPOT_H

#include <map>
#include <chrono>
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

struct HotSwapReturn {
  Instruction& instruction;
  bool isSwapped;

  HotSwapReturn(Instruction& _instruction, bool _isSwapped) : instruction(_instruction), isSwapped(_isSwapped) {}
};

class HotSpot {
 private:
  std::map<long, InstructionEntry *> calls;
  Jit jitter;

 public:
  HotSpot() {}

  HotSwapReturn hotSwap(Instruction &instruction);
  const void hotStat(const Instruction &instruction);
};

#endif
