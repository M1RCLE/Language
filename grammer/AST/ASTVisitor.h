#pragma once

#include "ASTNodes.h"

class ASTVisitor {
public:
    virtual void visit(ASTProgram &node) {}
    virtual void visit(ASTVarDeclaration &node) {}
    virtual void visit(ASTAssignment &node) {}
    virtual void visit(ASTFunctionDeclaration &node) {}
    virtual void visit(ASTIfStatement &node) {}
    virtual void visit(ASTWhileLoop &node) {}
    virtual void visit(ASTForLoop &node) {}
    virtual void visit(ASTReturnStatement &node) {}
    virtual void visit(ASTBinaryExpression &node) {}
    virtual void visit(ASTUnaryExpression &node) {}
    virtual void visit(ASTLiteral &node) {}
    virtual void visit(ASTIdentifier &node) {}
    virtual void visit(ASTFunctionCall &node) {}
};
