#include "jit.h"

const Instruction& Jit::process(const Instruction &instruction)
{
                    
     // Тут чё-то правим по ходу исполнения программы
     std::cerr << "hotswap jit call for instruction " << instructionTypeStr(instruction) << std::endl;
     return instruction;
}