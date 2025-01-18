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

#include "instruction.h"
#include "memoryManager.h"

class VirtualMachine {
 private:
  std::vector<Instruction> instructions;
  MemoryManager memoryManager;
  std::map<std::string, Instruction> functions;
  bool isReturning;

 public:
  void loadFromFile(const std::string& filename);
  std::vector<Instruction> readNestedBlock(std::ifstream& in);
  void run();
  void execute(const Instruction& instruction);
  void run(const std::vector<Instruction>& block);
  bool conditions(const Instruction& instruction);
  long getOperandValue(const std::any& operand);
  std::vector<std::any> parseToListOfObjects(const std::any& input);
};

#endif
