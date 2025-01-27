#ifndef JIT_H
#define JIT_H

#include "compiler.h"

class Jit {
 public:
  Instruction* process(Instruction* instruction);

  Jit() {}
};

#endif
