//
// Created by Michael Shindarev on 16.01.2025.
//

#include "MyLanguageParser.h"
#include "MyLanguageVisitor.h"
#include "ASTNodes.h"

class AstBuilder : public MyLanguageVisitor {
public:
    std::any visitProgram(MyLanguageParser::ProgramContext *context) override {

    }

    std::any visitStatement(MyLanguageParser::StatementContext *context) override {

    }

    std::any visitVarDeclaration(MyLanguageParser::VarDeclarationContext *context) override {

    }

    std::any visitAssignment(MyLanguageParser::AssignmentContext *context) override {

    }

    std::any visitFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext *context) override {

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

