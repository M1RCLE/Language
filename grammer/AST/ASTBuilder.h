#pragma once

#include "ASTNodes.h"
#include "MyLanguageBaseVisitor.h"

class ASTBuilder : public MyLanguageBaseVisitor {
public:
    std::any visitProgram(MyLanguageParser::ProgramContext *ctx) override;
    std::any visitVarDeclaration(MyLanguageParser::VarDeclarationContext *ctx) override;
    std::any visitAssignment(MyLanguageParser::AssignmentContext *ctx) override;
    std::any visitFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext *ctx) override;
    std::any visitIfStatement(MyLanguageParser::IfStatementContext *ctx) override;
    std::any visitWhileLoop(MyLanguageParser::WhileLoopContext *ctx) override;
    std::any visitForLoop(MyLanguageParser::ForLoopContext *ctx) override;
    std::any visitReturnStatement(MyLanguageParser::ReturnStatementContext *ctx) override;
    std::any visitExpression(MyLanguageParser::ExpressionContext *ctx) override;
};
