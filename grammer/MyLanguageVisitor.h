
// Generated from study/Language/grammer/MyLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "MyLanguageParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MyLanguageParser.
 */
class  MyLanguageVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MyLanguageParser.
   */
    virtual std::any visitProgram(MyLanguageParser::ProgramContext *context) = 0;

    virtual std::any visitStatement(MyLanguageParser::StatementContext *context) = 0;

    virtual std::any visitVarDeclaration(MyLanguageParser::VarDeclarationContext *context) = 0;

    virtual std::any visitAssignment(MyLanguageParser::AssignmentContext *context) = 0;

    virtual std::any visitFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext *context) = 0;

    virtual std::any visitParameterList(MyLanguageParser::ParameterListContext *context) = 0;

    virtual std::any visitIfStatement(MyLanguageParser::IfStatementContext *context) = 0;

    virtual std::any visitWhileLoop(MyLanguageParser::WhileLoopContext *context) = 0;

    virtual std::any visitForLoop(MyLanguageParser::ForLoopContext *context) = 0;

    virtual std::any visitReturnStatement(MyLanguageParser::ReturnStatementContext *context) = 0;

    virtual std::any visitBlock(MyLanguageParser::BlockContext *context) = 0;

    virtual std::any visitExpressionStatement(MyLanguageParser::ExpressionStatementContext *context) = 0;

    virtual std::any visitExpression(MyLanguageParser::ExpressionContext *context) = 0;

    virtual std::any visitComparison(MyLanguageParser::ComparisonContext *context) = 0;

    virtual std::any visitAddition(MyLanguageParser::AdditionContext *context) = 0;

    virtual std::any visitMultiplication(MyLanguageParser::MultiplicationContext *context) = 0;

    virtual std::any visitUnary(MyLanguageParser::UnaryContext *context) = 0;

    virtual std::any visitPrimary(MyLanguageParser::PrimaryContext *context) = 0;

    virtual std::any visitFunctionCall(MyLanguageParser::FunctionCallContext *context) = 0;

    virtual std::any visitArgumentList(MyLanguageParser::ArgumentListContext *context) = 0;


};

