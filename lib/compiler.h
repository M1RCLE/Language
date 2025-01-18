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

#include "instruction.h"

class Compiler {
 private:
  std::vector<Instruction> instructions;
  std::map<std::string, Instruction> functions;
  std::map<std::string, long> variableIndexes;
  long nextVariableIndex = 0;

  std::set<std::string> usedVariables;

  long getVariableIndex(const std::string& variableName);
  void addUsedVariable(const std::any& operand);
  bool isInteger(const std::string& str);
  Instruction compileLoop(const Instruction& loopInstruction);
  std::vector<Instruction> preprocessInstructions(
      const std::vector<Instruction>& instructions);
  std::vector<Instruction> optimizeInstructions(
      const std::vector<Instruction>& instructions);
  std::vector<Instruction> filterDeadCode(
      const std::vector<Instruction>& instructions);
  void writeInstruction(std::ofstream& out, const Instruction& instr);

 public:
  Compiler(const std::vector<Instruction>& instructions);

  void saveToFile(const std::string& filename);
};

#endif