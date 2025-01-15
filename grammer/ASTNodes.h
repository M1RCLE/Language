#ifndef ASTNODES_H
#define ASTNODES_H

#include <memory>
#include <vector>
#include <string>

// Базовый класс для всех узлов AST
class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void accept(class ASTVisitor& visitor) = 0;
};

// Узел программы (корень дерева)
class ASTProgram : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> statements;

    void accept(ASTVisitor& visitor) override;
};

// Узел объявления переменной
class ASTVarDeclaration : public ASTNode {
public:
    std::string name;
    std::unique_ptr<ASTNode> initializer; // Может быть nullptr

    void accept(ASTVisitor& visitor) override;
};

// Узел присваивания
class ASTAssignment : public ASTNode {
public:
    std::string variable;
    std::unique_ptr<ASTNode> value;

    void accept(ASTVisitor& visitor) override;
};

// Узел объявления функции
class ASTFunctionDeclaration : public ASTNode {
public:
    std::string name;
    std::vector<std::string> parameters;
    std::unique_ptr<ASTNode> body;

    void accept(ASTVisitor& visitor) override;
};

// Узел условного оператора
class ASTIfStatement : public ASTNode {
public:
    std::unique_ptr<ASTNode> condition;
    std::unique_ptr<ASTNode> thenBranch;
    std::unique_ptr<ASTNode> elseBranch; // Может быть nullptr

    void accept(ASTVisitor& visitor) override;
};

// Узел цикла while
class ASTWhileLoop : public ASTNode {
public:
    std::unique_ptr<ASTNode> condition;
    std::unique_ptr<ASTNode> body;

    void accept(ASTVisitor& visitor) override;
};

// Узел бинарного выражения
class ASTBinaryOp : public ASTNode {
public:
    std::string op; // Оператор ('+', '-', '*', '/')
    std::unique_ptr<ASTNode> left;
    std::unique_ptr<ASTNode> right;

    void accept(ASTVisitor& visitor) override;
};

// Узел литералов (чисел, строк, булевых значений)
class ASTLiteral : public ASTNode {
public:
    enum class Type { INT, FLOAT, STRING, BOOL } type;
    std::string value;

    explicit ASTLiteral(const std::string& val, Type t) : value(val), type(t) {}

    void accept(ASTVisitor& visitor) override;
};

// Узел переменной
class ASTVariable : public ASTNode {
public:
    std::string name;

    explicit ASTVariable(const std::string& varName) : name(varName) {}

    void accept(ASTVisitor& visitor) override;
};

// Узел вызова функции
class ASTFunctionCall : public ASTNode {
public:
    std::string name;
    std::vector<std::unique_ptr<ASTNode>> arguments;

    void accept(ASTVisitor& visitor) override;
};

// Узел блока кода
class ASTBlock : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> statements;

    void accept(ASTVisitor& visitor) override;
};

#endif // ASTNODES_H
