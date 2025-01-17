//
// Created by Michael Shindarev on 16.01.2025.
//

#ifndef SOSAL_ASTNODES_H
#define SOSAL_ASTNODES_H

#include <memory>
#include <vector>
#include <string>

class AstNode {
public:
    virtual ~AstNode() = default;
};

class ProgramNode : public AstNode {
public:
    std::vector<std::shared_ptr<AstNode>> statements;
};

class VarDeclarationNode : public AstNode {
public:
    std::string name;
    std::shared_ptr<AstNode> initializer = nullptr;
};

class AssignmentNode : public AstNode {
public:
    std::string name;
    std::shared_ptr<AstNode> expression;
};

class FunctionDeclarationNode : public AstNode {
public:
    std::string name;
    std::vector<std::string> parameters;
    std::shared_ptr<AstNode> body;
};

class FunctionCallNode : public AstNode {
public:
    std::string functionName;
    std::vector<std::shared_ptr<AstNode>> arguments;
};

class IfStatementNode : public AstNode {
public:
    std::shared_ptr<AstNode> condition;
    std::shared_ptr<AstNode> thenBranch;
    std::shared_ptr<AstNode> elseBranch; // Can be nullptr if no else branch
};

class WhileLoopNode : public AstNode {
public:
    std::shared_ptr<AstNode> condition;
    std::shared_ptr<AstNode> body;
};

class ExpressionNode : public AstNode {
public:
    virtual ~ExpressionNode() = 0;
};

class BinaryExpressionNode : public ExpressionNode {
public:
    std::string op;
    std::shared_ptr<AstNode> left;
    std::shared_ptr<AstNode> right;
};

class UnaryExpressionNode : public ExpressionNode {
public:
    std::string op;
    std::shared_ptr<AstNode> operand;
};

class LiteralNode : public ExpressionNode {
public:
    std::string value;
};

#endif //SOSAL_ASTNODES_H
