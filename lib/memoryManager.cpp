#include "memoryManager.h"

bool MemoryManager::isInFunction() const { return !callStack.empty(); }

std::unordered_map<std::string, ObjectEntry> &
MemoryManager::getCurrentMemory() {
    return isInFunction() ? callStack.top() : globalMemory;
}

ObjectEntry *MemoryManager::getMemoryEntry(
        const std::string &name) {
    if (isInFunction() && callStack.top().count(name)) {
        return &callStack.top().at(name);
    }
    auto it = globalMemory.find(name);
    return (it != globalMemory.end()) ? &it->second : nullptr;
}

void MemoryManager::allocate(const std::string &name, const std::any &value) {
    if (isInFunction()) {
        allocateLocal(name, value);
    } else {
        if (globalMemory.count(name)) {
            releaseReference(name);
        }
        globalMemory[name] = ObjectEntry(value);
    }
}

void MemoryManager::addReference(const std::string &name) {
    ObjectEntry *entry = getMemoryEntry(name);
    if (entry) {
        entry->refCount++;
    } else {
        throw std::runtime_error("Variable " + name + " does not exist");
    }
}

void MemoryManager::releaseReference(const std::string &name) {
    ObjectEntry *entry = getMemoryEntry(name);
    if (entry) {
        entry->refCount--;
        if (entry->refCount <= 0) {
            if (isInFunction() && callStack.top().count(name)) {
                callStack.top().erase(name);
            } else {
                globalMemory.erase(name);
            }
        }
    } else {
        throw std::runtime_error("Variable " + name + " does not exist");
    }
}

std::any *MemoryManager::getValue(const std::string &name) {
    ObjectEntry *entry = getMemoryEntry(name);
    return entry ? &entry->value : nullptr;
}

void MemoryManager::allocateArray(const std::string &name, long size) {
    allocate(name, std::vector<std::any>(size));
}

void MemoryManager::allocateArray(const std::string &name,
                                  const std::vector<std::any> &array) {
    allocate(name, array);
}

std::vector<std::any> &MemoryManager::getArray(const std::string &name) {
    auto *value = getValue(name);
    if (value->type() == typeid(std::vector<std::any>)) {
        return std::any_cast<std::vector<std::any> &>(*value);
    }
    throw std::runtime_error("Variable " + name + " is not an array");
}

void MemoryManager::setArrayElement(const std::string &name, long index,
                                    const std::any &value) {
    auto &array = getArray(name);
    if (index < 0 || static_cast<size_t>(index) >= array.size()) {
        throw std::runtime_error("Array index out of bounds: " +
                                 std::to_string(index));
    }
    array[index] = value;
}

std::any MemoryManager::getArrayElement(const std::string &name, long index) {
    auto &array = getArray(name);
    if (index < 0 || static_cast<size_t>(index) >= array.size()) {
        throw std::runtime_error("Array index out of bounds: " +
                                 std::to_string(index));
    }
    return array[index];
}

void MemoryManager::enterFunction() {
    if (callStack.size() >= MAX_STACK_DEPTH) {
        throw std::overflow_error("Maximum recursion depth exceeded");
    }
    callStack.emplace();
}

void MemoryManager::exitFunction() {
    auto localMemory = callStack.top();
    callStack.pop();

    for (auto &[name, entry]: localMemory) {
        if (!globalMemory.count(name)) {
            entry.refCount--;
        }
    }
}

void MemoryManager::allocateLocal(const std::string &name,
                                  const std::any &value) {
    if (!isInFunction()) {
        throw std::runtime_error(
                "Local allocation can only be done inside a function");
    }

    auto &currentMemory = callStack.top();
    if (currentMemory.count(name)) {
        releaseReference(name);
    }
    currentMemory[name] = ObjectEntry(value);
}

void MemoryManager::setReturnValue(const std::any &value) {
    returnValue = value;
}

std::any MemoryManager::getReturnValue() const { return returnValue; }