#include "jit.h"
#include "jit_for_fusion.h"


Instruction* jit_function_process(Instruction* instruction) {
    return jit_for_fusion_process(instruction);
}
