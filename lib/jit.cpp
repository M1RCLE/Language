#include "jit.h"

const Instruction& Jit::process(const Instruction &instruction)
{
                    
     // Тут чё-то правим по ходу исполнения программы
     std::cerr << "hotswap jit call for instruction #" << instruction.operationId << std::endl;
     return instruction;
}