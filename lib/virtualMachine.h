#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include <any>
#include <iostream>
#include <map>
#include <memory>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

#include "memoryManager.h"
#include "hotspot.h"

class VirtualMachine {
private:
    std::vector<Instruction> instructions;
    MemoryManager memoryManager;
    std::map<std::string, Instruction> functions;
    bool isReturning = false;
    HotSpot hotspot;
    bool instructionSwapped = false;
public:
    void loadFromFile(const std::string &filename);

    std::vector<Instruction> readNestedBlock(std::ifstream &in);

    void run();

    void execute(std::vector<Instruction> &instructions, Instruction &instruction);

    void run(std::vector<Instruction> &block);

    bool conditions(const Instruction &instruction);

    long getOperandValue(const std::any &operand);

    std::vector<std::any> parseToListOfObjects(const std::any &input);

    VirtualMachine() = default;
};

#endif
