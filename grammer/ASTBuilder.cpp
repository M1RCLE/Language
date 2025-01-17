//
// Created by Michael Shindarev on 16.01.2025.
//

#include "MyLanguageParser.h"
#include "MyLanguageVisitor.h"
#include "ASTNodes.h"

class AstBuilder : public MyLanguageVisitor {
public:
    std::any visitProgram(MyLanguageParser::ProgramContext *context) override {
        auto programNode = std::make_shared<ProgramNode>();

        for (auto statement : context->statement()) {
            programNode->statements.push_back(std::any_cast<std::shared_ptr<AstNode>>(visit(statement)));
        }

        return programNode;
    }

    std::any visitStatement(MyLanguageParser::StatementContext *context) override {
        if (context->varDeclaration()) {
            return visit(context->varDeclaration());
        }
        if (context->assignment()) {
            return visit(context->assignment());
        }
        if (context->functionDeclaration()) {
            return visit(context->functionDeclaration());
        }
        if (context->ifStatement()) {
            return visit(context->ifStatement());
        }
        if (context->whileLoop()) {
            return visit(context->whileLoop());
        }
        if (context->forLoop()) {
            return visit(context->forLoop());
        }
        if (context->expressionStatement()) {
            return visit(context->expressionStatement());
        }
        if (context->returnStatement()) {
            return visit(context->returnStatement());
        }

        throw std::runtime_error("Unexpected statement type in visitStatement.");
    }

    std::any visitVarDeclaration(MyLanguageParser::VarDeclarationContext *context) override {
        auto varDeclarationNode = std::make_shared<VarDeclarationNode>();
        varDeclarationNode->name = context->ID()->getText();
        if (context->expression()) {
            varDeclarationNode->initializer = std::any_cast<std::shared_ptr<AstNode>>(visit(context->expression()));
        }
        return varDeclarationNode;
    }

    std::any visitAssignment(MyLanguageParser::AssignmentContext *context) override {
        auto assignmentNode = std::make_shared<AssignmentNode>();
        assignmentNode->name = context->ID()->getText();
        assignmentNode->expression = std::any_cast<std::shared_ptr<AstNode>>(visit(context->expression()));
        return assignmentNode;
    }

    std::any visitFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext *context) override {
        auto functionDeclaration = std::make_shared<FunctionCallNode>();
        functionDeclaration->functionName = context->ID()->getText();
        if (context->parameterList()) {
//            for (auto param : context->parameterList()->ID()) {
//                functionDeclaration->arguments.push_back(param->getText());
//            }
        }
    }

    std::any visitParameterList(MyLanguageParser::ParameterListContext *context) override {

    }

    std::any visitIfStatement(MyLanguageParser::IfStatementContext *context) override {

    }

    std::any visitWhileLoop(MyLanguageParser::WhileLoopContext *context) override {

    }

    std::any visitForLoop(MyLanguageParser::ForLoopContext *context) override {

    }

    std::any visitReturnStatement(MyLanguageParser::ReturnStatementContext *context) override {

    }

    std::any visitBlock(MyLanguageParser::BlockContext *context) override {

    }

    std::any visitExpressionStatement(MyLanguageParser::ExpressionStatementContext *context) override {

    }

    std::any visitExpression(MyLanguageParser::ExpressionContext *context) override {

    }

    std::any visitComparison(MyLanguageParser::ComparisonContext *context) override {

    }

    std::any visitAddition(MyLanguageParser::AdditionContext *context) override {

    }

    std::any visitMultiplication(MyLanguageParser::MultiplicationContext *context) override {

    }

    std::any visitUnary(MyLanguageParser::UnaryContext *context) override {

    }

    std::any visitPrimary(MyLanguageParser::PrimaryContext *context) override {

    }

    std::any visitFunctionCall(MyLanguageParser::FunctionCallContext *context) override {

    }

    std::any visitArgumentList(MyLanguageParser::ArgumentListContext *context) override {

    }

};

