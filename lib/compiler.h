#ifndef COMPILER_H
#define COMPILER_H

#include <algorithm>
#include <any>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "parser.h"

class Compiler {
private:
    std::vector<Instruction> _instructions;
    std::map<std::string, Instruction> _functions;
    std::map<std::string, long> _variableIndexes;
    long nextVariableIndex = 0;

    std::set<std::string> usedVariables;

    long getVariableIndex(const std::string &variableName);

    void addUsedVariable(const std::any &operand);

    bool isInteger(const std::string &str);

    Instruction compileForLoop(const Instruction &loopInstruction);
    Instruction compileWhileLoop(const Instruction &loopInstruction);

    std::vector<Instruction> adaptInstructions(
            std::vector<Instruction> &instructions);

    static std::vector<Instruction> instructionsOptimizations(
            std::vector<Instruction> &instructions);

    void writeInstruction(std::ofstream &out, const Instruction &instr);

public:
    explicit Compiler(const std::vector<Instruction> &instructions);

    void saveToFile(const std::string &filename);
};

#endif