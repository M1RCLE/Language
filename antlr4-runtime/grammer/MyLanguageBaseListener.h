
// Generated from antlr4-runtime/grammer/MyLanguage.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "MyLanguageListener.h"


/**
 * This class provides an empty implementation of MyLanguageListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MyLanguageBaseListener : public MyLanguageListener {
public:

  virtual void enterProgram(MyLanguageParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(MyLanguageParser::ProgramContext * /*ctx*/) override { }

  virtual void enterStatement(MyLanguageParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(MyLanguageParser::StatementContext * /*ctx*/) override { }

  virtual void enterVariableDeclaration(MyLanguageParser::VariableDeclarationContext * /*ctx*/) override { }
  virtual void exitVariableDeclaration(MyLanguageParser::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterAssignment(MyLanguageParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(MyLanguageParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterIfStatement(MyLanguageParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(MyLanguageParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext * /*ctx*/) override { }
  virtual void exitFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext * /*ctx*/) override { }

  virtual void enterParameterList(MyLanguageParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(MyLanguageParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterFunctionCall(MyLanguageParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(MyLanguageParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterArgumentList(MyLanguageParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(MyLanguageParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterForStatement(MyLanguageParser::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(MyLanguageParser::ForStatementContext * /*ctx*/) override { }

  virtual void enterPrintStatement(MyLanguageParser::PrintStatementContext * /*ctx*/) override { }
  virtual void exitPrintStatement(MyLanguageParser::PrintStatementContext * /*ctx*/) override { }

  virtual void enterBlock(MyLanguageParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(MyLanguageParser::BlockContext * /*ctx*/) override { }

  virtual void enterExpression(MyLanguageParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(MyLanguageParser::ExpressionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

