#include "jit.h"

const Instruction& Jit::process(const Instruction &instruction)
{
                    
     std::cerr << "hotswap jit call for instruction #" << instruction.operationId << std::endl;
     return instruction;
}