
// Generated from study/Language/grammer/MyLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "MyLanguageParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MyLanguageParser.
 */
class  MyLanguageListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(MyLanguageParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(MyLanguageParser::ProgramContext *ctx) = 0;

  virtual void enterStatement(MyLanguageParser::StatementContext *ctx) = 0;
  virtual void exitStatement(MyLanguageParser::StatementContext *ctx) = 0;

  virtual void enterVarDeclaration(MyLanguageParser::VarDeclarationContext *ctx) = 0;
  virtual void exitVarDeclaration(MyLanguageParser::VarDeclarationContext *ctx) = 0;

  virtual void enterAssignment(MyLanguageParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(MyLanguageParser::AssignmentContext *ctx) = 0;

  virtual void enterFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext *ctx) = 0;
  virtual void exitFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext *ctx) = 0;

  virtual void enterParameterList(MyLanguageParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(MyLanguageParser::ParameterListContext *ctx) = 0;

  virtual void enterIfStatement(MyLanguageParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(MyLanguageParser::IfStatementContext *ctx) = 0;

  virtual void enterWhileLoop(MyLanguageParser::WhileLoopContext *ctx) = 0;
  virtual void exitWhileLoop(MyLanguageParser::WhileLoopContext *ctx) = 0;

  virtual void enterForLoop(MyLanguageParser::ForLoopContext *ctx) = 0;
  virtual void exitForLoop(MyLanguageParser::ForLoopContext *ctx) = 0;

  virtual void enterReturnStatement(MyLanguageParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(MyLanguageParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBlock(MyLanguageParser::BlockContext *ctx) = 0;
  virtual void exitBlock(MyLanguageParser::BlockContext *ctx) = 0;

  virtual void enterExpressionStatement(MyLanguageParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(MyLanguageParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterExpression(MyLanguageParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(MyLanguageParser::ExpressionContext *ctx) = 0;

  virtual void enterComparison(MyLanguageParser::ComparisonContext *ctx) = 0;
  virtual void exitComparison(MyLanguageParser::ComparisonContext *ctx) = 0;

  virtual void enterAddition(MyLanguageParser::AdditionContext *ctx) = 0;
  virtual void exitAddition(MyLanguageParser::AdditionContext *ctx) = 0;

  virtual void enterMultiplication(MyLanguageParser::MultiplicationContext *ctx) = 0;
  virtual void exitMultiplication(MyLanguageParser::MultiplicationContext *ctx) = 0;

  virtual void enterUnary(MyLanguageParser::UnaryContext *ctx) = 0;
  virtual void exitUnary(MyLanguageParser::UnaryContext *ctx) = 0;

  virtual void enterPrimary(MyLanguageParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(MyLanguageParser::PrimaryContext *ctx) = 0;

  virtual void enterFunctionCall(MyLanguageParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(MyLanguageParser::FunctionCallContext *ctx) = 0;

  virtual void enterArgumentList(MyLanguageParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(MyLanguageParser::ArgumentListContext *ctx) = 0;


};

