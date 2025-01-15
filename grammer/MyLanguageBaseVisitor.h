
// Generated from study/Language/grammer/MyLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "MyLanguageVisitor.h"


/**
 * This class provides an empty implementation of MyLanguageVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MyLanguageBaseVisitor : public MyLanguageVisitor {
public:

  virtual std::any visitProgram(MyLanguageParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(MyLanguageParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDeclaration(MyLanguageParser::VarDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(MyLanguageParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDeclaration(MyLanguageParser::FunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterList(MyLanguageParser::ParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(MyLanguageParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileLoop(MyLanguageParser::WhileLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForLoop(MyLanguageParser::ForLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(MyLanguageParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(MyLanguageParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatement(MyLanguageParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(MyLanguageParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparison(MyLanguageParser::ComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddition(MyLanguageParser::AdditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiplication(MyLanguageParser::MultiplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary(MyLanguageParser::UnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimary(MyLanguageParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCall(MyLanguageParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentList(MyLanguageParser::ArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }


};

