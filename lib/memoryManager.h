#include <any>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

struct ObjectEntry {
  std::any value;
  long refCount;

  ObjectEntry() {}
  ObjectEntry(const std::any& value) : value(value), refCount(1) {}
};

class MemoryManager {
 private:
  std::unordered_map<std::string, ObjectEntry> globalMemory;
  std::stack<std::unordered_map<std::string, ObjectEntry>> callStack;
  std::any returnValue;

  static const long MAX_STACK_DEPTH = 1000;

  bool isInFunction() const;
  std::unordered_map<std::string, ObjectEntry>& getCurrentMemory();
  ObjectEntry* getMemoryEntry(const std::string& name);

 public:
  void allocate(const std::string& name, const std::any& value);
  void addReference(const std::string& name);
  void releaseReference(const std::string& name);
  std::any getValue(const std::string& name);
  void allocateArray(const std::string& name, long size);
  void allocateArray(const std::string& name,
                     const std::vector<std::any>& array);
  std::vector<std::any>& getArray(const std::string& name);
  void setArrayElement(const std::string& name, long index,
                       const std::any& value);
  std::any getArrayElement(const std::string& name, long index);
  void enterFunction();
  void exitFunction();
  void allocateLocal(const std::string& name, const std::any& value);
  void setReturnValue(const std::any& value);
  std::any getReturnValue() const;
};
