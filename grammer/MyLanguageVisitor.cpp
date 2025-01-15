
// Generated from study/Language/grammer/MyLanguage.g4 by ANTLR 4.13.2


#include "MyLanguageVisitor.h"

#include "MyLanguageBaseVisitor.h"
#include "ASTNodes.h" // Заголовочный файл с определениями узлов AST

class ASTBuilder : public MyLanguageBaseVisitor {
public:
    // Программа
    std::any visitProgram(MyLanguageParser::ProgramContext* ctx) override {
        auto program = std::make_unique<ASTProgram>();
        for (auto stmtCtx : ctx->statement()) {
            program->statements.push_back(visit(stmtCtx));
        }
        return program;
    }

    // Переменная
    std::any visitVarDeclaration(MyLanguageParser::VarDeclarationContext* ctx) override {
        auto varDecl = std::make_unique<ASTVarDeclaration>();
        varDecl->name = ctx->ID()->getText();
        if (ctx->expression()) {
            varDecl->initializer = visit(ctx->expression());
        }
        return varDecl;
    }

    // Присваивание
    std::any visitAssignment(MyLanguageParser::AssignmentContext* ctx) override {
        auto assignment = std::make_unique<ASTAssignment>();
        assignment->variable = ctx->ID()->getText();
        assignment->value = visit(ctx->expression());
        return assignment;
    }

    // Объявление функции
    std::any visitFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext* ctx) override {
        auto funcDecl = std::make_unique<ASTFunctionDeclaration>();
        funcDecl->name = ctx->ID()->getText();

        if (ctx->parameterList()) {
            for (auto param : ctx->parameterList()->ID()) {
                funcDecl->parameters.push_back(param->getText());
            }
        }

        funcDecl->body = visit(ctx->block());
        return funcDecl;
    }

    // Условие
    std::any visitIfStatement(MyLanguageParser::IfStatementContext* ctx) override {
        auto ifStmt = std::make_unique<ASTIfStatement>();
        ifStmt->condition = visit(ctx->expression());
        ifStmt->thenBranch = visit(ctx->block());
        if (ctx->block(1)) {
            ifStmt->elseBranch = visit(ctx->block(1));
        }
        return ifStmt;
    }

    // Цикл while
    std::any visitWhileLoop(MyLanguageParser::WhileLoopContext* ctx) override {
        auto whileLoop = std::make_unique<ASTWhileLoop>();
        whileLoop->condition = visit(ctx->expression());
        whileLoop->body = visit(ctx->block());
        return whileLoop;
    }

    // Цикл for
    std::any visitForLoop(MyLanguageParser::ForLoopContext* ctx) override {
        auto forLoop = std::make_unique<ASTForLoop>();
        if (ctx->varDeclaration()) {
            forLoop->initializer = visit(ctx->varDeclaration());
        } else if (ctx->assignment()) {
            forLoop->initializer = visit(ctx->assignment());
        }

        if (ctx->expression(0)) {
            forLoop->condition = visit(ctx->expression(0));
        }

        if (ctx->expression(1)) {
            forLoop->increment = visit(ctx->expression(1));
        } else if (ctx->forLoopAssignment()) {
            forLoop->increment = visit(ctx->forLoopAssignment());
        }

        forLoop->body = visit(ctx->block());
        return forLoop;
    }

    // Возврат
    std::any visitReturnStatement(MyLanguageParser::ReturnStatementContext* ctx) override {
        auto returnStmt = std::make_unique<ASTReturnStatement>();
        if (ctx->expression()) {
            returnStmt->value = visit(ctx->expression());
        }
        return returnStmt;
    }

    // Блок
    std::any visitBlock(MyLanguageParser::BlockContext* ctx) override {
        auto block = std::make_unique<ASTBlock>();
        for (auto stmtCtx : ctx->statement()) {
            block->statements.push_back(visit(stmtCtx));
        }
        return block;
    }

    // Выражение
    std::any visitExpression(MyLanguageParser::ExpressionContext* ctx) override {
        return visit(ctx->comparison());
    }

    // Сравнение
    std::any visitComparison(MyLanguageParser::ComparisonContext* ctx) override {
        auto left = visit(ctx->addition(0));

        if (ctx->addition().size() == 1) {
            return left; // Без операций
        }

        auto comparison = std::make_unique<ASTBinaryOp>();
        comparison->left = std::move(left);
        comparison->op = ctx->children[1]->getText(); // Оператор
        comparison->right = visit(ctx->addition(1));
        return comparison;
    }

    // Арифметика
    std::any visitAddition(MyLanguageParser::AdditionContext* ctx) override {
        auto left = visit(ctx->multiplication(0));

        for (size_t i = 1; i < ctx->multiplication().size(); ++i) {
            auto binaryOp = std::make_unique<ASTBinaryOp>();
            binaryOp->left = std::move(left);
            binaryOp->op = ctx->children[2 * i - 1]->getText(); // '+' или '-'
            binaryOp->right = visit(ctx->multiplication(i));
            left = std::move(binaryOp);
        }

        return left;
    }

    // Множественное
    std::any visitMultiplication(MyLanguageParser::MultiplicationContext* ctx) override {
        auto left = visit(ctx->unary(0));

        for (size_t i = 1; i < ctx->unary().size(); ++i) {
            auto binaryOp = std::make_unique<ASTBinaryOp>();
            binaryOp->left = std::move(left);
            binaryOp->op = ctx->children[2 * i - 1]->getText(); // '*' или '/'
            binaryOp->right = visit(ctx->unary(i));
            left = std::move(binaryOp);
        }

        return left;
    }

    // Унарные операции
    std::any visitUnary(MyLanguageParser::UnaryContext* ctx) override {
        if (ctx->primary()) {
            return visit(ctx->primary());
        }

        auto unaryOp = std::make_unique<ASTUnaryOp>();
        unaryOp->op = ctx->children[0]->getText(); // '+', '-', '!'
        unaryOp->operand = visit(ctx->unary());
        return unaryOp;
    }

    // Основное
    std::any visitPrimary(MyLanguageParser::PrimaryContext* ctx) override {
        if (ctx->INT()) {
            return std::make_unique<ASTLiteral>(std::stoi(ctx->INT()->getText()));
        }

        if (ctx->FLOAT()) {
            return std::make_unique<ASTLiteral>(std::stof(ctx->FLOAT()->getText()));
        }

        if (ctx->STRING()) {
            return std::make_unique<ASTLiteral>(ctx->STRING()->getText());
        }

        if (ctx->ID()) {
            return std::make_unique<ASTVariable>(ctx->ID()->getText());
        }

        if (ctx->functionCall()) {
            return visit(ctx->functionCall());
        }

        if (ctx->expression()) {
            return visit(ctx->expression());
        }

        throw std::runtime_error("Unsupported primary expression");
    }

    // Вызов функции
    std::any visitFunctionCall(MyLanguageParser::FunctionCallContext* ctx) override {
        auto funcCall = std::make_unique<ASTFunctionCall>();
        funcCall->name = ctx->ID()->getText();

        if (ctx->argumentList()) {
            for (auto exprCtx : ctx->argumentList()->expression()) {
                funcCall->arguments.push_back(visit(exprCtx));
            }
        }

        return funcCall;
    }
};