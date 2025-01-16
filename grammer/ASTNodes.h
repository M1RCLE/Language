//
// Created by Michael Shindarev on 16.01.2025.
//

#ifndef SOSAL_ASTNODES_H
#define SOSAL_ASTNODES_H

#include <string>
#include <vector>
#include <memory>

// Base AST Node
class ASTNode {
public:
    virtual ~ASTNode() = default;
};

// Derived classes for specific AST node types
class ProgramNode : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> statements;
};

class VarDeclarationNode : public ASTNode {
public:
    std::string varName;
    std::unique_ptr<ASTNode> initializer;
};

class AssignmentNode : public ASTNode {
public:
    std::string varName;
    std::unique_ptr<ASTNode> value;
};

class FunctionDeclarationNode : public ASTNode {
public:
    std::string funcName;
    std::vector<std::string> parameters;
    std::unique_ptr<ASTNode> body;
};

class IfNode : public ASTNode {
public:
    std::unique_ptr<ASTNode> condition;
    std::unique_ptr<ASTNode> thenBlock;
    std::unique_ptr<ASTNode> elseBlock;
};

class WhileNode : public ASTNode {
public:
    std::unique_ptr<ASTNode> condition;
    std::unique_ptr<ASTNode> body;
};

class ForNode : public ASTNode {
public:
    std::unique_ptr<ASTNode> initializer;
    std::unique_ptr<ASTNode> condition;
    std::unique_ptr<ASTNode> update;
    std::unique_ptr<ASTNode> body;
};

class ReturnNode : public ASTNode {
public:
    std::unique_ptr<ASTNode> value;
};

class BlockNode : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> statements;
};

class ExpressionStatementNode : public ASTNode {
public:
    std::unique_ptr<ASTNode> expression;
};

class BinaryExpressionNode : public ASTNode {
public:
    std::string op;
    std::unique_ptr<ASTNode> left;
    std::unique_ptr<ASTNode> right;
};

class UnaryExpressionNode : public ASTNode {
public:
    std::string op;
    std::unique_ptr<ASTNode> operand;
};

class LiteralNode : public ASTNode {
public:
    std::string value;
};

class IdentifierNode : public ASTNode {
public:
    std::string name;
};

class FunctionCallNode : public ASTNode {
public:
    std::string funcName;
    std::vector<std::unique_ptr<ASTNode>> arguments;
};


#endif //SOSAL_ASTNODES_H
