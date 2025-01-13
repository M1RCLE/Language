
// Generated from antlr4-runtime/grammer/MyLanguage.g4 by ANTLR 4.7

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

  virtual void enterVariableDeclaration(MyLanguageParser::VariableDeclarationContext *ctx) = 0;
  virtual void exitVariableDeclaration(MyLanguageParser::VariableDeclarationContext *ctx) = 0;

  virtual void enterAssignment(MyLanguageParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(MyLanguageParser::AssignmentContext *ctx) = 0;

  virtual void enterIfStatement(MyLanguageParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(MyLanguageParser::IfStatementContext *ctx) = 0;

  virtual void enterFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext *ctx) = 0;
  virtual void exitFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext *ctx) = 0;

  virtual void enterParameterList(MyLanguageParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(MyLanguageParser::ParameterListContext *ctx) = 0;

  virtual void enterFunctionCall(MyLanguageParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(MyLanguageParser::FunctionCallContext *ctx) = 0;

  virtual void enterArgumentList(MyLanguageParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(MyLanguageParser::ArgumentListContext *ctx) = 0;

  virtual void enterForStatement(MyLanguageParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(MyLanguageParser::ForStatementContext *ctx) = 0;

  virtual void enterPrintStatement(MyLanguageParser::PrintStatementContext *ctx) = 0;
  virtual void exitPrintStatement(MyLanguageParser::PrintStatementContext *ctx) = 0;

  virtual void enterBlock(MyLanguageParser::BlockContext *ctx) = 0;
  virtual void exitBlock(MyLanguageParser::BlockContext *ctx) = 0;

  virtual void enterExpression(MyLanguageParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(MyLanguageParser::ExpressionContext *ctx) = 0;


};

