#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory>

class MemoryManager {
public:
    void allocate(const std::string& name, const std::shared_ptr<void>& value) {
        if (isInFunction()) {
            allocateLocal(name, value);
        }
        else {
            if (globalMemory.count(name)) {
                releaseReference(name);
            }
            globalMemory[name] = std::make_shared<ObjectEntry>(value);
        }
    }

    void addReference(const std::string& name) {
        auto entry = getMemoryEntry(name);
        if (entry) {
            entry->refCount++;
        }
        else {
            throw std::runtime_error("Variable " + name + " does not exist");
        }
    }

    void exitFunction() {
        auto localMemory = callStack.top();
        callStack.pop();

        for (const auto& [name, entry] : localMemory) {
            if (!globalMemory.count(name)) {
                if (entry) {
                    entry->refCount--;
                }
            }
        }
    }

    void releaseReference(const std::string& name) {
        auto entry = getMemoryEntry(name);
        if (entry) {
            entry->refCount--;
            if (entry->refCount <= 0) {
                if (isInFunction() && callStack.top().count(name)) {
                    callStack.top().erase(name);
                }
                else {
                    globalMemory.erase(name);
                }
            }
        }
        else {
            throw std::runtime_error("Variable " + name + " does not exist");
        }
    }

    std::shared_ptr<void> getValue(const std::string& name) {
        auto entry = getMemoryEntry(name);
        return entry ? entry->value : nullptr;
    }

    void allocateArray(const std::string& name, size_t size) {
        allocate(name, std::make_shared<std::vector<std::shared_ptr<void>>>(size));
    }

    std::vector<std::shared_ptr<void>>& getArray(const std::string& name) {
        auto value = std::static_pointer_cast<std::vector<std::shared_ptr<void>>>(getValue(name));
        if (!value) {
            throw std::runtime_error("Variable " + name + " is not an array");
        }
        return *value;
    }

    void setArrayElement(const std::string& name, size_t index, const std::shared_ptr<void>& value) {
        auto& array = getArray(name);
        if (index >= array.size()) {
            throw std::runtime_error("Array index out of bounds: " + std::to_string(index));
        }
        array[index] = value;
    }

    std::shared_ptr<void> getArrayElement(const std::string& name, size_t index) {
        auto& array = getArray(name);
        if (index >= array.size()) {
            throw std::runtime_error("Array index out of bounds: " + std::to_string(index));
        }
        return array[index];
    }

    void enterFunction() {
        if (callStack.size() >= MAX_STACK_DEPTH) {
            throw std::runtime_error("Maximum recursion depth exceeded");
        }
        callStack.push(std::map<std::string, std::shared_ptr<ObjectEntry>>());
    }

    void allocateLocal(const std::string& name, const std::shared_ptr<void>& value) {
        if (!isInFunction()) {
            throw std::runtime_error("Local allocation can only be done inside a function");
        }

        auto& currentMemory = callStack.top();
        if (currentMemory.count(name)) {
            releaseReference(name);
        }
        currentMemory[name] = std::make_shared<ObjectEntry>(value);
    }

    void setReturnValue(const std::shared_ptr<void>& value) {
        returnValue = value;
    }

    std::shared_ptr<void> getReturnValue() const {
        return returnValue;
    }

private:
    struct ObjectEntry {
        std::shared_ptr<void> value;
        size_t refCount;

        explicit ObjectEntry(const std::shared_ptr<void>& val) : value(val), refCount(1) {}
    };

    bool isInFunction() const {
        return !callStack.empty();
    }

    std::shared_ptr<ObjectEntry> getMemoryEntry(const std::string& name) {
        if (isInFunction() && callStack.top().count(name)) {
            return callStack.top()[name];
        }
        if (globalMemory.count(name)) {
            return globalMemory.at(name);
        }
        return nullptr;
    }

    std::map<std::string, std::shared_ptr<ObjectEntry>> globalMemory;
    std::stack<std::map<std::string, std::shared_ptr<ObjectEntry>>> callStack;
    std::shared_ptr<void> returnValue = nullptr;

    static constexpr size_t MAX_STACK_DEPTH = 1000;
};
