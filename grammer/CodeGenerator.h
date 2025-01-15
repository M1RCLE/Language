#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "ASTNodes.h"
#include <unordered_map>

class CodeGenerator {
public:
    llvm::LLVMContext Context;
    llvm::IRBuilder<> Builder;
    std::unique_ptr<llvm::Module> Module;
    std::unordered_map<std::string, llvm::Value*> NamedValues;

    CodeGenerator()
            : Builder(Context), Module(std::make_unique<llvm::Module>("MyLanguageModule", Context)) {}

    llvm::Value* generate(ASTNode* node) {
        return node->generateCode(*this);
    }

    void dumpIR() {
        Module->print(llvm::outs(), nullptr);
    }
};

#endif