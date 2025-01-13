
// Generated from antlr4-runtime/grammer/MyLanguage.g4 by ANTLR 4.7


#include "MyLanguageListener.h"

#include "MyLanguageParser.h"


using namespace antlrcpp;
using namespace antlr4;

MyLanguageParser::MyLanguageParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MyLanguageParser::~MyLanguageParser() {
  delete _interpreter;
}

std::string MyLanguageParser::getGrammarFileName() const {
  return "MyLanguage.g4";
}

const std::vector<std::string>& MyLanguageParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MyLanguageParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

MyLanguageParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyLanguageParser::ProgramContext::EOF() {
  return getToken(MyLanguageParser::EOF, 0);
}

std::vector<MyLanguageParser::StatementContext *> MyLanguageParser::ProgramContext::statement() {
  return getRuleContexts<MyLanguageParser::StatementContext>();
}

MyLanguageParser::StatementContext* MyLanguageParser::ProgramContext::statement(size_t i) {
  return getRuleContext<MyLanguageParser::StatementContext>(i);
}


size_t MyLanguageParser::ProgramContext::getRuleIndex() const {
  return MyLanguageParser::RuleProgram;
}

void MyLanguageParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void MyLanguageParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

MyLanguageParser::ProgramContext* MyLanguageParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, MyLanguageParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MyLanguageParser::T__0)
      | (1ULL << MyLanguageParser::T__3)
      | (1ULL << MyLanguageParser::T__7)
      | (1ULL << MyLanguageParser::T__9)
      | (1ULL << MyLanguageParser::T__10)
      | (1ULL << MyLanguageParser::IDENTIFIER))) != 0)) {
      setState(26);
      statement();
      setState(31);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(32);
    match(MyLanguageParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MyLanguageParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MyLanguageParser::VariableDeclarationContext* MyLanguageParser::StatementContext::variableDeclaration() {
  return getRuleContext<MyLanguageParser::VariableDeclarationContext>(0);
}

MyLanguageParser::AssignmentContext* MyLanguageParser::StatementContext::assignment() {
  return getRuleContext<MyLanguageParser::AssignmentContext>(0);
}

MyLanguageParser::IfStatementContext* MyLanguageParser::StatementContext::ifStatement() {
  return getRuleContext<MyLanguageParser::IfStatementContext>(0);
}

MyLanguageParser::FunctionDeclarationContext* MyLanguageParser::StatementContext::functionDeclaration() {
  return getRuleContext<MyLanguageParser::FunctionDeclarationContext>(0);
}

MyLanguageParser::FunctionCallContext* MyLanguageParser::StatementContext::functionCall() {
  return getRuleContext<MyLanguageParser::FunctionCallContext>(0);
}

MyLanguageParser::ForStatementContext* MyLanguageParser::StatementContext::forStatement() {
  return getRuleContext<MyLanguageParser::ForStatementContext>(0);
}

MyLanguageParser::PrintStatementContext* MyLanguageParser::StatementContext::printStatement() {
  return getRuleContext<MyLanguageParser::PrintStatementContext>(0);
}


size_t MyLanguageParser::StatementContext::getRuleIndex() const {
  return MyLanguageParser::RuleStatement;
}

void MyLanguageParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void MyLanguageParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

MyLanguageParser::StatementContext* MyLanguageParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, MyLanguageParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(41);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(34);
      variableDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(35);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(36);
      ifStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(37);
      functionDeclaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(38);
      functionCall();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(39);
      forStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(40);
      printStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

MyLanguageParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyLanguageParser::VariableDeclarationContext::IDENTIFIER() {
  return getToken(MyLanguageParser::IDENTIFIER, 0);
}

MyLanguageParser::ExpressionContext* MyLanguageParser::VariableDeclarationContext::expression() {
  return getRuleContext<MyLanguageParser::ExpressionContext>(0);
}


size_t MyLanguageParser::VariableDeclarationContext::getRuleIndex() const {
  return MyLanguageParser::RuleVariableDeclaration;
}

void MyLanguageParser::VariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaration(this);
}

void MyLanguageParser::VariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaration(this);
}

MyLanguageParser::VariableDeclarationContext* MyLanguageParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, MyLanguageParser::RuleVariableDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    match(MyLanguageParser::T__0);
    setState(44);
    match(MyLanguageParser::IDENTIFIER);
    setState(45);
    match(MyLanguageParser::T__1);
    setState(46);
    expression(0);
    setState(47);
    match(MyLanguageParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

MyLanguageParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyLanguageParser::AssignmentContext::IDENTIFIER() {
  return getToken(MyLanguageParser::IDENTIFIER, 0);
}

MyLanguageParser::ExpressionContext* MyLanguageParser::AssignmentContext::expression() {
  return getRuleContext<MyLanguageParser::ExpressionContext>(0);
}


size_t MyLanguageParser::AssignmentContext::getRuleIndex() const {
  return MyLanguageParser::RuleAssignment;
}

void MyLanguageParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void MyLanguageParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}

MyLanguageParser::AssignmentContext* MyLanguageParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 6, MyLanguageParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    match(MyLanguageParser::IDENTIFIER);
    setState(50);
    match(MyLanguageParser::T__1);
    setState(51);
    expression(0);
    setState(52);
    match(MyLanguageParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

MyLanguageParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MyLanguageParser::ExpressionContext* MyLanguageParser::IfStatementContext::expression() {
  return getRuleContext<MyLanguageParser::ExpressionContext>(0);
}

std::vector<MyLanguageParser::BlockContext *> MyLanguageParser::IfStatementContext::block() {
  return getRuleContexts<MyLanguageParser::BlockContext>();
}

MyLanguageParser::BlockContext* MyLanguageParser::IfStatementContext::block(size_t i) {
  return getRuleContext<MyLanguageParser::BlockContext>(i);
}


size_t MyLanguageParser::IfStatementContext::getRuleIndex() const {
  return MyLanguageParser::RuleIfStatement;
}

void MyLanguageParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void MyLanguageParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

MyLanguageParser::IfStatementContext* MyLanguageParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, MyLanguageParser::RuleIfStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(MyLanguageParser::T__3);
    setState(55);
    match(MyLanguageParser::T__4);
    setState(56);
    expression(0);
    setState(57);
    match(MyLanguageParser::T__5);
    setState(58);
    block();
    setState(61);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MyLanguageParser::T__6) {
      setState(59);
      match(MyLanguageParser::T__6);
      setState(60);
      block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

MyLanguageParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyLanguageParser::FunctionDeclarationContext::IDENTIFIER() {
  return getToken(MyLanguageParser::IDENTIFIER, 0);
}

MyLanguageParser::BlockContext* MyLanguageParser::FunctionDeclarationContext::block() {
  return getRuleContext<MyLanguageParser::BlockContext>(0);
}

MyLanguageParser::ParameterListContext* MyLanguageParser::FunctionDeclarationContext::parameterList() {
  return getRuleContext<MyLanguageParser::ParameterListContext>(0);
}


size_t MyLanguageParser::FunctionDeclarationContext::getRuleIndex() const {
  return MyLanguageParser::RuleFunctionDeclaration;
}

void MyLanguageParser::FunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDeclaration(this);
}

void MyLanguageParser::FunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDeclaration(this);
}

MyLanguageParser::FunctionDeclarationContext* MyLanguageParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, MyLanguageParser::RuleFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(MyLanguageParser::T__7);
    setState(64);
    match(MyLanguageParser::IDENTIFIER);
    setState(65);
    match(MyLanguageParser::T__4);
    setState(67);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MyLanguageParser::IDENTIFIER) {
      setState(66);
      parameterList();
    }
    setState(69);
    match(MyLanguageParser::T__5);
    setState(70);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

MyLanguageParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MyLanguageParser::ParameterListContext::IDENTIFIER() {
  return getTokens(MyLanguageParser::IDENTIFIER);
}

tree::TerminalNode* MyLanguageParser::ParameterListContext::IDENTIFIER(size_t i) {
  return getToken(MyLanguageParser::IDENTIFIER, i);
}


size_t MyLanguageParser::ParameterListContext::getRuleIndex() const {
  return MyLanguageParser::RuleParameterList;
}

void MyLanguageParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void MyLanguageParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}

MyLanguageParser::ParameterListContext* MyLanguageParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 12, MyLanguageParser::RuleParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    match(MyLanguageParser::IDENTIFIER);
    setState(77);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyLanguageParser::T__8) {
      setState(73);
      match(MyLanguageParser::T__8);
      setState(74);
      match(MyLanguageParser::IDENTIFIER);
      setState(79);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

MyLanguageParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyLanguageParser::FunctionCallContext::IDENTIFIER() {
  return getToken(MyLanguageParser::IDENTIFIER, 0);
}

MyLanguageParser::ArgumentListContext* MyLanguageParser::FunctionCallContext::argumentList() {
  return getRuleContext<MyLanguageParser::ArgumentListContext>(0);
}


size_t MyLanguageParser::FunctionCallContext::getRuleIndex() const {
  return MyLanguageParser::RuleFunctionCall;
}

void MyLanguageParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void MyLanguageParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

MyLanguageParser::FunctionCallContext* MyLanguageParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 14, MyLanguageParser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    match(MyLanguageParser::IDENTIFIER);
    setState(81);
    match(MyLanguageParser::T__4);
    setState(83);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MyLanguageParser::T__4)
      | (1ULL << MyLanguageParser::IDENTIFIER)
      | (1ULL << MyLanguageParser::NUMBER))) != 0)) {
      setState(82);
      argumentList();
    }
    setState(85);
    match(MyLanguageParser::T__5);
    setState(86);
    match(MyLanguageParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

MyLanguageParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MyLanguageParser::ExpressionContext *> MyLanguageParser::ArgumentListContext::expression() {
  return getRuleContexts<MyLanguageParser::ExpressionContext>();
}

MyLanguageParser::ExpressionContext* MyLanguageParser::ArgumentListContext::expression(size_t i) {
  return getRuleContext<MyLanguageParser::ExpressionContext>(i);
}


size_t MyLanguageParser::ArgumentListContext::getRuleIndex() const {
  return MyLanguageParser::RuleArgumentList;
}

void MyLanguageParser::ArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentList(this);
}

void MyLanguageParser::ArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentList(this);
}

MyLanguageParser::ArgumentListContext* MyLanguageParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 16, MyLanguageParser::RuleArgumentList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    expression(0);
    setState(93);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyLanguageParser::T__8) {
      setState(89);
      match(MyLanguageParser::T__8);
      setState(90);
      expression(0);
      setState(95);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

MyLanguageParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MyLanguageParser::VariableDeclarationContext* MyLanguageParser::ForStatementContext::variableDeclaration() {
  return getRuleContext<MyLanguageParser::VariableDeclarationContext>(0);
}

MyLanguageParser::ExpressionContext* MyLanguageParser::ForStatementContext::expression() {
  return getRuleContext<MyLanguageParser::ExpressionContext>(0);
}

MyLanguageParser::AssignmentContext* MyLanguageParser::ForStatementContext::assignment() {
  return getRuleContext<MyLanguageParser::AssignmentContext>(0);
}

MyLanguageParser::BlockContext* MyLanguageParser::ForStatementContext::block() {
  return getRuleContext<MyLanguageParser::BlockContext>(0);
}


size_t MyLanguageParser::ForStatementContext::getRuleIndex() const {
  return MyLanguageParser::RuleForStatement;
}

void MyLanguageParser::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}

void MyLanguageParser::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}

MyLanguageParser::ForStatementContext* MyLanguageParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, MyLanguageParser::RuleForStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(MyLanguageParser::T__9);
    setState(97);
    match(MyLanguageParser::T__4);
    setState(98);
    variableDeclaration();
    setState(99);
    expression(0);
    setState(100);
    match(MyLanguageParser::T__2);
    setState(101);
    assignment();
    setState(102);
    match(MyLanguageParser::T__5);
    setState(103);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintStatementContext ------------------------------------------------------------------

MyLanguageParser::PrintStatementContext::PrintStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MyLanguageParser::ExpressionContext* MyLanguageParser::PrintStatementContext::expression() {
  return getRuleContext<MyLanguageParser::ExpressionContext>(0);
}


size_t MyLanguageParser::PrintStatementContext::getRuleIndex() const {
  return MyLanguageParser::RulePrintStatement;
}

void MyLanguageParser::PrintStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintStatement(this);
}

void MyLanguageParser::PrintStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintStatement(this);
}

MyLanguageParser::PrintStatementContext* MyLanguageParser::printStatement() {
  PrintStatementContext *_localctx = _tracker.createInstance<PrintStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, MyLanguageParser::RulePrintStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(MyLanguageParser::T__10);
    setState(106);
    match(MyLanguageParser::T__4);
    setState(107);
    expression(0);
    setState(108);
    match(MyLanguageParser::T__5);
    setState(109);
    match(MyLanguageParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

MyLanguageParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MyLanguageParser::StatementContext *> MyLanguageParser::BlockContext::statement() {
  return getRuleContexts<MyLanguageParser::StatementContext>();
}

MyLanguageParser::StatementContext* MyLanguageParser::BlockContext::statement(size_t i) {
  return getRuleContext<MyLanguageParser::StatementContext>(i);
}


size_t MyLanguageParser::BlockContext::getRuleIndex() const {
  return MyLanguageParser::RuleBlock;
}

void MyLanguageParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void MyLanguageParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

MyLanguageParser::BlockContext* MyLanguageParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 22, MyLanguageParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    match(MyLanguageParser::T__11);
    setState(115);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MyLanguageParser::T__0)
      | (1ULL << MyLanguageParser::T__3)
      | (1ULL << MyLanguageParser::T__7)
      | (1ULL << MyLanguageParser::T__9)
      | (1ULL << MyLanguageParser::T__10)
      | (1ULL << MyLanguageParser::IDENTIFIER))) != 0)) {
      setState(112);
      statement();
      setState(117);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(118);
    match(MyLanguageParser::T__12);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MyLanguageParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MyLanguageParser::ExpressionContext *> MyLanguageParser::ExpressionContext::expression() {
  return getRuleContexts<MyLanguageParser::ExpressionContext>();
}

MyLanguageParser::ExpressionContext* MyLanguageParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<MyLanguageParser::ExpressionContext>(i);
}

tree::TerminalNode* MyLanguageParser::ExpressionContext::IDENTIFIER() {
  return getToken(MyLanguageParser::IDENTIFIER, 0);
}

tree::TerminalNode* MyLanguageParser::ExpressionContext::NUMBER() {
  return getToken(MyLanguageParser::NUMBER, 0);
}


size_t MyLanguageParser::ExpressionContext::getRuleIndex() const {
  return MyLanguageParser::RuleExpression;
}

void MyLanguageParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void MyLanguageParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


MyLanguageParser::ExpressionContext* MyLanguageParser::expression() {
   return expression(0);
}

MyLanguageParser::ExpressionContext* MyLanguageParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MyLanguageParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  MyLanguageParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, MyLanguageParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(127);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyLanguageParser::T__4: {
        setState(121);
        match(MyLanguageParser::T__4);
        setState(122);
        expression(0);
        setState(123);
        match(MyLanguageParser::T__5);
        break;
      }

      case MyLanguageParser::IDENTIFIER: {
        setState(125);
        match(MyLanguageParser::IDENTIFIER);
        break;
      }

      case MyLanguageParser::NUMBER: {
        setState(126);
        match(MyLanguageParser::NUMBER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(140);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(138);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(129);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(130);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MyLanguageParser::T__13)
            | (1ULL << MyLanguageParser::T__14)
            | (1ULL << MyLanguageParser::T__15)
            | (1ULL << MyLanguageParser::T__16))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(131);
          expression(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(132);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(133);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MyLanguageParser::T__17)
            | (1ULL << MyLanguageParser::T__18)
            | (1ULL << MyLanguageParser::T__19)
            | (1ULL << MyLanguageParser::T__20))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(134);
          expression(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(135);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(136);
          _la = _input->LA(1);
          if (!(_la == MyLanguageParser::T__21

          || _la == MyLanguageParser::T__22)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(137);
          expression(5);
          break;
        }

        } 
      }
      setState(142);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool MyLanguageParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 12: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MyLanguageParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MyLanguageParser::_decisionToDFA;
atn::PredictionContextCache MyLanguageParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MyLanguageParser::_atn;
std::vector<uint16_t> MyLanguageParser::_serializedATN;

std::vector<std::string> MyLanguageParser::_ruleNames = {
  "program", "statement", "variableDeclaration", "assignment", "ifStatement", 
  "functionDeclaration", "parameterList", "functionCall", "argumentList", 
  "forStatement", "printStatement", "block", "expression"
};

std::vector<std::string> MyLanguageParser::_literalNames = {
  "", "'let'", "'='", "';'", "'if'", "'('", "')'", "'else'", "'func'", "','", 
  "'for'", "'print'", "'{'", "'}'", "'*'", "'/'", "'+'", "'-'", "'<'", "'<='", 
  "'>'", "'>='", "'=='", "'!='"
};

std::vector<std::string> MyLanguageParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "IDENTIFIER", "NUMBER", "WS"
};

dfa::Vocabulary MyLanguageParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MyLanguageParser::_tokenNames;

MyLanguageParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1c, 0x92, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x3, 
    0x2, 0x7, 0x2, 0x1e, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x21, 0xb, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x2c, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0x40, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0x46, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x4e, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x51, 
    0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x56, 0xa, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x5e, 
    0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x61, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x7, 0xd, 0x74, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x77, 0xb, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x5, 0xe, 0x82, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 
    0x8d, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x90, 0xb, 0xe, 0x3, 0xe, 0x2, 0x3, 
    0x1a, 0xf, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x2, 0x5, 0x3, 0x2, 0x10, 0x13, 0x3, 0x2, 0x14, 0x17, 0x3, 
    0x2, 0x18, 0x19, 0x2, 0x96, 0x2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x8, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x38, 0x3, 0x2, 0x2, 0x2, 0xc, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x10, 0x52, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x5a, 0x3, 0x2, 0x2, 0x2, 0x14, 0x62, 0x3, 0x2, 0x2, 0x2, 0x16, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x71, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x81, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x1e, 0x5, 0x4, 0x3, 0x2, 0x1d, 0x1c, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x1f, 0x20, 0x3, 0x2, 0x2, 0x2, 0x20, 0x22, 0x3, 0x2, 0x2, 0x2, 
    0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x7, 0x2, 0x2, 0x3, 0x23, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x24, 0x2c, 0x5, 0x6, 0x4, 0x2, 0x25, 0x2c, 
    0x5, 0x8, 0x5, 0x2, 0x26, 0x2c, 0x5, 0xa, 0x6, 0x2, 0x27, 0x2c, 0x5, 
    0xc, 0x7, 0x2, 0x28, 0x2c, 0x5, 0x10, 0x9, 0x2, 0x29, 0x2c, 0x5, 0x14, 
    0xb, 0x2, 0x2a, 0x2c, 0x5, 0x16, 0xc, 0x2, 0x2b, 0x24, 0x3, 0x2, 0x2, 
    0x2, 0x2b, 0x25, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x26, 0x3, 0x2, 0x2, 0x2, 
    0x2b, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x3, 0x2, 0x2, 0x2e, 0x2f, 0x7, 
    0x1a, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x4, 0x2, 0x2, 0x30, 0x31, 0x5, 0x1a, 
    0xe, 0x2, 0x31, 0x32, 0x7, 0x5, 0x2, 0x2, 0x32, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x34, 0x7, 0x1a, 0x2, 0x2, 0x34, 0x35, 0x7, 0x4, 0x2, 0x2, 
    0x35, 0x36, 0x5, 0x1a, 0xe, 0x2, 0x36, 0x37, 0x7, 0x5, 0x2, 0x2, 0x37, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x7, 0x6, 0x2, 0x2, 0x39, 0x3a, 
    0x7, 0x7, 0x2, 0x2, 0x3a, 0x3b, 0x5, 0x1a, 0xe, 0x2, 0x3b, 0x3c, 0x7, 
    0x8, 0x2, 0x2, 0x3c, 0x3f, 0x5, 0x18, 0xd, 0x2, 0x3d, 0x3e, 0x7, 0x9, 
    0x2, 0x2, 0x3e, 0x40, 0x5, 0x18, 0xd, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0x42, 0x7, 0xa, 0x2, 0x2, 0x42, 0x43, 0x7, 0x1a, 0x2, 0x2, 0x43, 
    0x45, 0x7, 0x7, 0x2, 0x2, 0x44, 0x46, 0x5, 0xe, 0x8, 0x2, 0x45, 0x44, 
    0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 0x8, 0x2, 0x2, 0x48, 0x49, 0x5, 0x18, 
    0xd, 0x2, 0x49, 0xd, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4f, 0x7, 0x1a, 0x2, 
    0x2, 0x4b, 0x4c, 0x7, 0xb, 0x2, 0x2, 0x4c, 0x4e, 0x7, 0x1a, 0x2, 0x2, 
    0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x7, 
    0x1a, 0x2, 0x2, 0x53, 0x55, 0x7, 0x7, 0x2, 0x2, 0x54, 0x56, 0x5, 0x12, 
    0xa, 0x2, 0x55, 0x54, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 0x8, 0x2, 0x2, 
    0x58, 0x59, 0x7, 0x5, 0x2, 0x2, 0x59, 0x11, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x5f, 0x5, 0x1a, 0xe, 0x2, 0x5b, 0x5c, 0x7, 0xb, 0x2, 0x2, 0x5c, 0x5e, 
    0x5, 0x1a, 0xe, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x61, 0x3, 
    0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 
    0x2, 0x2, 0x60, 0x13, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x62, 0x63, 0x7, 0xc, 0x2, 0x2, 0x63, 0x64, 0x7, 0x7, 0x2, 0x2, 
    0x64, 0x65, 0x5, 0x6, 0x4, 0x2, 0x65, 0x66, 0x5, 0x1a, 0xe, 0x2, 0x66, 
    0x67, 0x7, 0x5, 0x2, 0x2, 0x67, 0x68, 0x5, 0x8, 0x5, 0x2, 0x68, 0x69, 
    0x7, 0x8, 0x2, 0x2, 0x69, 0x6a, 0x5, 0x18, 0xd, 0x2, 0x6a, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0xd, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x7, 
    0x2, 0x2, 0x6d, 0x6e, 0x5, 0x1a, 0xe, 0x2, 0x6e, 0x6f, 0x7, 0x8, 0x2, 
    0x2, 0x6f, 0x70, 0x7, 0x5, 0x2, 0x2, 0x70, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x75, 0x7, 0xe, 0x2, 0x2, 0x72, 0x74, 0x5, 0x4, 0x3, 0x2, 0x73, 
    0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x77, 0x3, 0x2, 0x2, 0x2, 0x75, 0x73, 
    0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 0x78, 0x3, 
    0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 0xf, 
    0x2, 0x2, 0x79, 0x19, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x8, 0xe, 0x1, 
    0x2, 0x7b, 0x7c, 0x7, 0x7, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x1a, 0xe, 0x2, 
    0x7d, 0x7e, 0x7, 0x8, 0x2, 0x2, 0x7e, 0x82, 0x3, 0x2, 0x2, 0x2, 0x7f, 
    0x82, 0x7, 0x1a, 0x2, 0x2, 0x80, 0x82, 0x7, 0x1b, 0x2, 0x2, 0x81, 0x7a, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x80, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0xc, 0x8, 
    0x2, 0x2, 0x84, 0x85, 0x9, 0x2, 0x2, 0x2, 0x85, 0x8d, 0x5, 0x1a, 0xe, 
    0x9, 0x86, 0x87, 0xc, 0x7, 0x2, 0x2, 0x87, 0x88, 0x9, 0x3, 0x2, 0x2, 
    0x88, 0x8d, 0x5, 0x1a, 0xe, 0x8, 0x89, 0x8a, 0xc, 0x6, 0x2, 0x2, 0x8a, 
    0x8b, 0x9, 0x4, 0x2, 0x2, 0x8b, 0x8d, 0x5, 0x1a, 0xe, 0x7, 0x8c, 0x83, 
    0x3, 0x2, 0x2, 0x2, 0x8c, 0x86, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 0x2, 
    0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0xd, 0x1f, 0x2b, 0x3f, 0x45, 0x4f, 
    0x55, 0x5f, 0x75, 0x81, 0x8c, 0x8e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MyLanguageParser::Initializer MyLanguageParser::_init;
