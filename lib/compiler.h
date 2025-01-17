#ifndef COMPILER_H
#define COMPILER_H

#include "instruction.h"
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Compiler {
private:
    std::vector<Instruction> instructions;
    std::map<std::string, Instruction> functions;
    std::map<std::string, long> variableIndexes;
    long nextVariableIndex = 0;
    std::set<std::string> usedVariables;

public:
    explicit Compiler(const std::vector<Instruction>& instructions);

    void saveToFile(const std::string& filename);

    static std::vector<Instruction> reverseList(const std::vector<Instruction>& original);

private:
    std::vector<Instruction> preprocessInstructions(const std::vector<Instruction>& instructions);
    std::vector<Instruction> optimizeInstructions(const std::vector<Instruction>& instructions);
    std::vector<Instruction> filterDeadCode(std::vector<Instruction>& instructions);
    long getVariableIndex(const std::string& variableName);
    Instruction compileLoop(const Instruction& loopInstruction);
    void writeInstruction(std::ofstream& out, const Instruction& instr);
    void addUsedVariable(const std::variant<std::string, int, float>& operand);
    bool isInteger(const std::string& str);
};

#endif
