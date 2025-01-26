#ifndef JIT_H
#define JIT_H

#include "instruction.h"

class Jit {

    public:

        const Instruction& process(const Instruction &instruction);

        Jit() {
        }
};


#endif
