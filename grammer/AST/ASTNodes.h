//#ifndef ASTNODES_H
//#define ASTNODES_H
//
//#include <memory>
//#include <vector>
//#include <string>
//
//// Базовый класс для всех узлов AST
//class ASTNode {
//public:
//    virtual ~ASTNode() = default;
//    virtual void accept(class ASTVisitor& visitor) = 0;
//};
//
//// Узел программы (корень дерева)
//class ASTProgram : public ASTNode {
//public:
//    std::vector<std::unique_ptr<ASTNode>> statements;
//
//    void accept(ASTVisitor& visitor) override;
//};
//
//// Узел объявления переменной
//class ASTVarDeclaration : public ASTNode {
//public:
//    std::string name;
//    std::unique_ptr<ASTNode> initializer; // Может быть nullptr
//
//    void accept(ASTVisitor& visitor) override;
//};
//
//// Узел присваивания
//class ASTAssignment : public ASTNode {
//public:
//    std::string variable;
//    std::unique_ptr<ASTNode> value;
//
//    void accept(ASTVisitor& visitor) override;
//};
//
//// Узел объявления функции
//class ASTFunctionDeclaration : public ASTNode {
//public:
//    std::string name;
//    std::vector<std::string> parameters;
//    std::unique_ptr<ASTNode> body;
//
//    void accept(ASTVisitor& visitor) override;
//};
//
//// Узел условного оператора
//class ASTIfStatement : public ASTNode {
//public:
//    std::unique_ptr<ASTNode> condition;
//    std::unique_ptr<ASTNode> thenBranch;
//    std::unique_ptr<ASTNode> elseBranch; // Может быть nullptr
//
//    void accept(ASTVisitor& visitor) override;
//};
//
//// Узел цикла while
//class ASTWhileLoop : public ASTNode {
//public:
//    std::unique_ptr<ASTNode> condition;
//    std::unique_ptr<ASTNode> body;
//
//    void accept(ASTVisitor& visitor) override;
//};
//
//// Узел бинарного выражения
//class ASTBinaryOp : public ASTNode {
//public:
//    std::string op; // Оператор ('+', '-', '*', '/')
//    std::unique_ptr<ASTNode> left;
//    std::unique_ptr<ASTNode> right;
//
//    void accept(ASTVisitor& visitor) override;
//};
//
//// Узел литералов (чисел, строк, булевых значений)
//class ASTLiteral : public ASTNode {
//public:
//    enum class Type { INT, FLOAT, STRING, BOOL } type;
//    std::string value;
//
//    explicit ASTLiteral(const std::string& val, Type t) : value(val), type(t) {}
//
//    void accept(ASTVisitor& visitor) override;
//};
//
//// Узел переменной
//class ASTVariable : public ASTNode {
//public:
//    std::string name;
//
//    explicit ASTVariable(const std::string& varName) : name(varName) {}
//
//    void accept(ASTVisitor& visitor) override;
//};
//
//// Узел вызова функции
//class ASTFunctionCall : public ASTNode {
//public:
//    std::string name;
//    std::vector<std::unique_ptr<ASTNode>> arguments;
//
//    void accept(ASTVisitor& visitor) override;
//};
//
//// Узел блока кода
//class ASTBlock : public ASTNode {
//public:
//    std::vector<std::unique_ptr<ASTNode>> statements;
//
//    void accept(ASTVisitor& visitor) override;
//};
//
//#endif // ASTNODES_H


#pragma once

#include <string>
#include <vector>
#include <memory>

class ASTNode {
public:
    virtual ~ASTNode() = default;
};

class ASTStatement : public ASTNode {};
class ASTExpression : public ASTNode {};

class ASTProgram : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTStatement>> statements;
};

class ASTVarDeclaration : public ASTStatement {
public:
    std::string name;
    std::unique_ptr<ASTExpression> expression;
};

class ASTAssignment : public ASTStatement {
public:
    std::string name;
    std::unique_ptr<ASTExpression> expression;
};

class ASTFunctionDeclaration : public ASTStatement {
public:
    std::string name;
    std::vector<std::string> parameters;
    std::vector<std::unique_ptr<ASTStatement>> body;
};

class ASTIfStatement : public ASTStatement {
public:
    std::unique_ptr<ASTExpression> condition;
    std::vector<std::unique_ptr<ASTStatement>> thenBranch;
    std::vector<std::unique_ptr<ASTStatement>> elseBranch;
};

class ASTWhileLoop : public ASTStatement {
public:
    std::unique_ptr<ASTExpression> condition;
    std::vector<std::unique_ptr<ASTStatement>> body;
};

class ASTForLoop : public ASTStatement {
public:
    std::unique_ptr<ASTStatement> initializer;
    std::unique_ptr<ASTExpression> condition;
    std::unique_ptr<ASTStatement> increment;
    std::vector<std::unique_ptr<ASTStatement>> body;
};

class ASTReturnStatement : public ASTStatement {
public:
    std::unique_ptr<ASTExpression> expression;
};

class ASTBinaryExpression : public ASTExpression {
public:
    std::string op;
    std::unique_ptr<ASTExpression> left;
    std::unique_ptr<ASTExpression> right;
};

class ASTUnaryExpression : public ASTExpression {
public:
    std::string op;
    std::unique_ptr<ASTExpression> expr;
};

class ASTLiteral : public ASTExpression {
public:
    std::string value;
};

class ASTIdentifier : public ASTExpression {
public:
    std::string name;
};

class ASTFunctionCall : public ASTExpression {
public:
    std::string functionName;
    std::vector<std::unique_ptr<ASTExpression>> arguments;
};
