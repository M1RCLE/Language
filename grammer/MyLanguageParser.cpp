
// Generated from study/Language/grammer/MyLanguage.g4 by ANTLR 4.13.2


#include "MyLanguageListener.h"
#include "MyLanguageVisitor.h"

#include "MyLanguageParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MyLanguageParserStaticData final {
  MyLanguageParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MyLanguageParserStaticData(const MyLanguageParserStaticData&) = delete;
  MyLanguageParserStaticData(MyLanguageParserStaticData&&) = delete;
  MyLanguageParserStaticData& operator=(const MyLanguageParserStaticData&) = delete;
  MyLanguageParserStaticData& operator=(MyLanguageParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mylanguageParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<MyLanguageParserStaticData> mylanguageParserStaticData = nullptr;

void mylanguageParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mylanguageParserStaticData != nullptr) {
    return;
  }
#else
  assert(mylanguageParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MyLanguageParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "varDeclaration", "assignment", "functionDeclaration", 
      "parameterList", "ifStatement", "whileLoop", "forLoop", "returnStatement", 
      "block", "expressionStatement", "expression", "comparison", "addition", 
      "multiplication", "unary", "primary", "functionCall", "argumentList"
    },
    std::vector<std::string>{
      "", "'let'", "'='", "';'", "'func'", "'('", "')'", "','", "'if'", 
      "'else'", "'while'", "'for'", "'return'", "'{'", "'}'", "'=='", "'!='", 
      "'<'", "'<='", "'>'", "'>='", "'+'", "'-'", "'*'", "'/'", "'!'", "'true'", 
      "'false'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "ID", "INT", "FLOAT", 
      "STRING", "WS", "COMMENT", "MULTILINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,34,199,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,5,0,42,8,0,10,
  	0,12,0,45,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,57,8,1,1,2,
  	1,2,1,2,1,2,3,2,63,8,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,3,
  	4,76,8,4,1,4,1,4,1,4,1,5,1,5,1,5,5,5,84,8,5,10,5,12,5,87,9,5,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,3,6,96,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,
  	8,1,8,3,8,109,8,8,1,8,3,8,112,8,8,1,8,1,8,1,8,3,8,117,8,8,1,8,1,8,1,8,
  	1,9,1,9,3,9,124,8,9,1,9,1,9,1,10,1,10,5,10,130,8,10,10,10,12,10,133,9,
  	10,1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,13,1,13,1,13,5,13,145,8,13,10,
  	13,12,13,148,9,13,1,14,1,14,1,14,5,14,153,8,14,10,14,12,14,156,9,14,1,
  	15,1,15,1,15,5,15,161,8,15,10,15,12,15,164,9,15,1,16,1,16,1,16,3,16,169,
  	8,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,17,182,
  	8,17,1,18,1,18,1,18,3,18,187,8,18,1,18,1,18,1,19,1,19,1,19,5,19,194,8,
  	19,10,19,12,19,197,9,19,1,19,0,0,20,0,2,4,6,8,10,12,14,16,18,20,22,24,
  	26,28,30,32,34,36,38,0,4,1,0,15,20,1,0,21,22,1,0,23,24,2,0,21,22,25,25,
  	210,0,43,1,0,0,0,2,56,1,0,0,0,4,58,1,0,0,0,6,66,1,0,0,0,8,71,1,0,0,0,
  	10,80,1,0,0,0,12,88,1,0,0,0,14,97,1,0,0,0,16,103,1,0,0,0,18,121,1,0,0,
  	0,20,127,1,0,0,0,22,136,1,0,0,0,24,139,1,0,0,0,26,141,1,0,0,0,28,149,
  	1,0,0,0,30,157,1,0,0,0,32,168,1,0,0,0,34,181,1,0,0,0,36,183,1,0,0,0,38,
  	190,1,0,0,0,40,42,3,2,1,0,41,40,1,0,0,0,42,45,1,0,0,0,43,41,1,0,0,0,43,
  	44,1,0,0,0,44,46,1,0,0,0,45,43,1,0,0,0,46,47,5,0,0,1,47,1,1,0,0,0,48,
  	57,3,4,2,0,49,57,3,6,3,0,50,57,3,8,4,0,51,57,3,12,6,0,52,57,3,14,7,0,
  	53,57,3,16,8,0,54,57,3,22,11,0,55,57,3,18,9,0,56,48,1,0,0,0,56,49,1,0,
  	0,0,56,50,1,0,0,0,56,51,1,0,0,0,56,52,1,0,0,0,56,53,1,0,0,0,56,54,1,0,
  	0,0,56,55,1,0,0,0,57,3,1,0,0,0,58,59,5,1,0,0,59,62,5,28,0,0,60,61,5,2,
  	0,0,61,63,3,24,12,0,62,60,1,0,0,0,62,63,1,0,0,0,63,64,1,0,0,0,64,65,5,
  	3,0,0,65,5,1,0,0,0,66,67,5,28,0,0,67,68,5,2,0,0,68,69,3,24,12,0,69,70,
  	5,3,0,0,70,7,1,0,0,0,71,72,5,4,0,0,72,73,5,28,0,0,73,75,5,5,0,0,74,76,
  	3,10,5,0,75,74,1,0,0,0,75,76,1,0,0,0,76,77,1,0,0,0,77,78,5,6,0,0,78,79,
  	3,20,10,0,79,9,1,0,0,0,80,85,5,28,0,0,81,82,5,7,0,0,82,84,5,28,0,0,83,
  	81,1,0,0,0,84,87,1,0,0,0,85,83,1,0,0,0,85,86,1,0,0,0,86,11,1,0,0,0,87,
  	85,1,0,0,0,88,89,5,8,0,0,89,90,5,5,0,0,90,91,3,24,12,0,91,92,5,6,0,0,
  	92,95,3,20,10,0,93,94,5,9,0,0,94,96,3,20,10,0,95,93,1,0,0,0,95,96,1,0,
  	0,0,96,13,1,0,0,0,97,98,5,10,0,0,98,99,5,5,0,0,99,100,3,24,12,0,100,101,
  	5,6,0,0,101,102,3,20,10,0,102,15,1,0,0,0,103,104,5,11,0,0,104,108,5,5,
  	0,0,105,109,3,4,2,0,106,109,3,6,3,0,107,109,5,3,0,0,108,105,1,0,0,0,108,
  	106,1,0,0,0,108,107,1,0,0,0,109,111,1,0,0,0,110,112,3,24,12,0,111,110,
  	1,0,0,0,111,112,1,0,0,0,112,113,1,0,0,0,113,116,5,3,0,0,114,117,3,24,
  	12,0,115,117,3,6,3,0,116,114,1,0,0,0,116,115,1,0,0,0,116,117,1,0,0,0,
  	117,118,1,0,0,0,118,119,5,6,0,0,119,120,3,20,10,0,120,17,1,0,0,0,121,
  	123,5,12,0,0,122,124,3,24,12,0,123,122,1,0,0,0,123,124,1,0,0,0,124,125,
  	1,0,0,0,125,126,5,3,0,0,126,19,1,0,0,0,127,131,5,13,0,0,128,130,3,2,1,
  	0,129,128,1,0,0,0,130,133,1,0,0,0,131,129,1,0,0,0,131,132,1,0,0,0,132,
  	134,1,0,0,0,133,131,1,0,0,0,134,135,5,14,0,0,135,21,1,0,0,0,136,137,3,
  	24,12,0,137,138,5,3,0,0,138,23,1,0,0,0,139,140,3,26,13,0,140,25,1,0,0,
  	0,141,146,3,28,14,0,142,143,7,0,0,0,143,145,3,28,14,0,144,142,1,0,0,0,
  	145,148,1,0,0,0,146,144,1,0,0,0,146,147,1,0,0,0,147,27,1,0,0,0,148,146,
  	1,0,0,0,149,154,3,30,15,0,150,151,7,1,0,0,151,153,3,30,15,0,152,150,1,
  	0,0,0,153,156,1,0,0,0,154,152,1,0,0,0,154,155,1,0,0,0,155,29,1,0,0,0,
  	156,154,1,0,0,0,157,162,3,32,16,0,158,159,7,2,0,0,159,161,3,32,16,0,160,
  	158,1,0,0,0,161,164,1,0,0,0,162,160,1,0,0,0,162,163,1,0,0,0,163,31,1,
  	0,0,0,164,162,1,0,0,0,165,166,7,3,0,0,166,169,3,32,16,0,167,169,3,34,
  	17,0,168,165,1,0,0,0,168,167,1,0,0,0,169,33,1,0,0,0,170,182,5,29,0,0,
  	171,182,5,30,0,0,172,182,5,31,0,0,173,182,5,26,0,0,174,182,5,27,0,0,175,
  	176,5,5,0,0,176,177,3,24,12,0,177,178,5,6,0,0,178,182,1,0,0,0,179,182,
  	5,28,0,0,180,182,3,36,18,0,181,170,1,0,0,0,181,171,1,0,0,0,181,172,1,
  	0,0,0,181,173,1,0,0,0,181,174,1,0,0,0,181,175,1,0,0,0,181,179,1,0,0,0,
  	181,180,1,0,0,0,182,35,1,0,0,0,183,184,5,28,0,0,184,186,5,5,0,0,185,187,
  	3,38,19,0,186,185,1,0,0,0,186,187,1,0,0,0,187,188,1,0,0,0,188,189,5,6,
  	0,0,189,37,1,0,0,0,190,195,3,24,12,0,191,192,5,7,0,0,192,194,3,24,12,
  	0,193,191,1,0,0,0,194,197,1,0,0,0,195,193,1,0,0,0,195,196,1,0,0,0,196,
  	39,1,0,0,0,197,195,1,0,0,0,18,43,56,62,75,85,95,108,111,116,123,131,146,
  	154,162,168,181,186,195
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mylanguageParserStaticData = std::move(staticData);
}

}

MyLanguageParser::MyLanguageParser(TokenStream *input) : MyLanguageParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MyLanguageParser::MyLanguageParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MyLanguageParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *mylanguageParserStaticData->atn, mylanguageParserStaticData->decisionToDFA, mylanguageParserStaticData->sharedContextCache, options);
}

MyLanguageParser::~MyLanguageParser() {
  delete _interpreter;
}

const atn::ATN& MyLanguageParser::getATN() const {
  return *mylanguageParserStaticData->atn;
}

std::string MyLanguageParser::getGrammarFileName() const {
  return "MyLanguage.g4";
}

const std::vector<std::string>& MyLanguageParser::getRuleNames() const {
  return mylanguageParserStaticData->ruleNames;
}

const dfa::Vocabulary& MyLanguageParser::getVocabulary() const {
  return mylanguageParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MyLanguageParser::getSerializedATN() const {
  return mylanguageParserStaticData->serializedATN;
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


std::any MyLanguageParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::ProgramContext* MyLanguageParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, MyLanguageParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4267711794) != 0)) {
      setState(40);
      statement();
      setState(45);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(46);
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

MyLanguageParser::VarDeclarationContext* MyLanguageParser::StatementContext::varDeclaration() {
  return getRuleContext<MyLanguageParser::VarDeclarationContext>(0);
}

MyLanguageParser::AssignmentContext* MyLanguageParser::StatementContext::assignment() {
  return getRuleContext<MyLanguageParser::AssignmentContext>(0);
}

MyLanguageParser::FunctionDeclarationContext* MyLanguageParser::StatementContext::functionDeclaration() {
  return getRuleContext<MyLanguageParser::FunctionDeclarationContext>(0);
}

MyLanguageParser::IfStatementContext* MyLanguageParser::StatementContext::ifStatement() {
  return getRuleContext<MyLanguageParser::IfStatementContext>(0);
}

MyLanguageParser::WhileLoopContext* MyLanguageParser::StatementContext::whileLoop() {
  return getRuleContext<MyLanguageParser::WhileLoopContext>(0);
}

MyLanguageParser::ForLoopContext* MyLanguageParser::StatementContext::forLoop() {
  return getRuleContext<MyLanguageParser::ForLoopContext>(0);
}

MyLanguageParser::ExpressionStatementContext* MyLanguageParser::StatementContext::expressionStatement() {
  return getRuleContext<MyLanguageParser::ExpressionStatementContext>(0);
}

MyLanguageParser::ReturnStatementContext* MyLanguageParser::StatementContext::returnStatement() {
  return getRuleContext<MyLanguageParser::ReturnStatementContext>(0);
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


std::any MyLanguageParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::StatementContext* MyLanguageParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, MyLanguageParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(56);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(48);
      varDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(49);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(50);
      functionDeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(51);
      ifStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(52);
      whileLoop();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(53);
      forLoop();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(54);
      expressionStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(55);
      returnStatement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclarationContext ------------------------------------------------------------------

MyLanguageParser::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyLanguageParser::VarDeclarationContext::ID() {
  return getToken(MyLanguageParser::ID, 0);
}

MyLanguageParser::ExpressionContext* MyLanguageParser::VarDeclarationContext::expression() {
  return getRuleContext<MyLanguageParser::ExpressionContext>(0);
}


size_t MyLanguageParser::VarDeclarationContext::getRuleIndex() const {
  return MyLanguageParser::RuleVarDeclaration;
}

void MyLanguageParser::VarDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclaration(this);
}

void MyLanguageParser::VarDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclaration(this);
}


std::any MyLanguageParser::VarDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitVarDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::VarDeclarationContext* MyLanguageParser::varDeclaration() {
  VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, MyLanguageParser::RuleVarDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(MyLanguageParser::T__0);
    setState(59);
    match(MyLanguageParser::ID);
    setState(62);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MyLanguageParser::T__1) {
      setState(60);
      match(MyLanguageParser::T__1);
      setState(61);
      expression();
    }
    setState(64);
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

tree::TerminalNode* MyLanguageParser::AssignmentContext::ID() {
  return getToken(MyLanguageParser::ID, 0);
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


std::any MyLanguageParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::AssignmentContext* MyLanguageParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 6, MyLanguageParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(MyLanguageParser::ID);
    setState(67);
    match(MyLanguageParser::T__1);
    setState(68);
    expression();
    setState(69);
    match(MyLanguageParser::T__2);
   
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

tree::TerminalNode* MyLanguageParser::FunctionDeclarationContext::ID() {
  return getToken(MyLanguageParser::ID, 0);
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


std::any MyLanguageParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::FunctionDeclarationContext* MyLanguageParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 8, MyLanguageParser::RuleFunctionDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(MyLanguageParser::T__3);
    setState(72);
    match(MyLanguageParser::ID);
    setState(73);
    match(MyLanguageParser::T__4);
    setState(75);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MyLanguageParser::ID) {
      setState(74);
      parameterList();
    }
    setState(77);
    match(MyLanguageParser::T__5);
    setState(78);
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

std::vector<tree::TerminalNode *> MyLanguageParser::ParameterListContext::ID() {
  return getTokens(MyLanguageParser::ID);
}

tree::TerminalNode* MyLanguageParser::ParameterListContext::ID(size_t i) {
  return getToken(MyLanguageParser::ID, i);
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


std::any MyLanguageParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::ParameterListContext* MyLanguageParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 10, MyLanguageParser::RuleParameterList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    match(MyLanguageParser::ID);
    setState(85);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyLanguageParser::T__6) {
      setState(81);
      match(MyLanguageParser::T__6);
      setState(82);
      match(MyLanguageParser::ID);
      setState(87);
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


std::any MyLanguageParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::IfStatementContext* MyLanguageParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, MyLanguageParser::RuleIfStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(MyLanguageParser::T__7);
    setState(89);
    match(MyLanguageParser::T__4);
    setState(90);
    expression();
    setState(91);
    match(MyLanguageParser::T__5);
    setState(92);
    block();
    setState(95);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MyLanguageParser::T__8) {
      setState(93);
      match(MyLanguageParser::T__8);
      setState(94);
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

//----------------- WhileLoopContext ------------------------------------------------------------------

MyLanguageParser::WhileLoopContext::WhileLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MyLanguageParser::ExpressionContext* MyLanguageParser::WhileLoopContext::expression() {
  return getRuleContext<MyLanguageParser::ExpressionContext>(0);
}

MyLanguageParser::BlockContext* MyLanguageParser::WhileLoopContext::block() {
  return getRuleContext<MyLanguageParser::BlockContext>(0);
}


size_t MyLanguageParser::WhileLoopContext::getRuleIndex() const {
  return MyLanguageParser::RuleWhileLoop;
}

void MyLanguageParser::WhileLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileLoop(this);
}

void MyLanguageParser::WhileLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileLoop(this);
}


std::any MyLanguageParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::WhileLoopContext* MyLanguageParser::whileLoop() {
  WhileLoopContext *_localctx = _tracker.createInstance<WhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 14, MyLanguageParser::RuleWhileLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(MyLanguageParser::T__9);
    setState(98);
    match(MyLanguageParser::T__4);
    setState(99);
    expression();
    setState(100);
    match(MyLanguageParser::T__5);
    setState(101);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForLoopContext ------------------------------------------------------------------

MyLanguageParser::ForLoopContext::ForLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MyLanguageParser::BlockContext* MyLanguageParser::ForLoopContext::block() {
  return getRuleContext<MyLanguageParser::BlockContext>(0);
}

MyLanguageParser::VarDeclarationContext* MyLanguageParser::ForLoopContext::varDeclaration() {
  return getRuleContext<MyLanguageParser::VarDeclarationContext>(0);
}

std::vector<MyLanguageParser::AssignmentContext *> MyLanguageParser::ForLoopContext::assignment() {
  return getRuleContexts<MyLanguageParser::AssignmentContext>();
}

MyLanguageParser::AssignmentContext* MyLanguageParser::ForLoopContext::assignment(size_t i) {
  return getRuleContext<MyLanguageParser::AssignmentContext>(i);
}

std::vector<MyLanguageParser::ExpressionContext *> MyLanguageParser::ForLoopContext::expression() {
  return getRuleContexts<MyLanguageParser::ExpressionContext>();
}

MyLanguageParser::ExpressionContext* MyLanguageParser::ForLoopContext::expression(size_t i) {
  return getRuleContext<MyLanguageParser::ExpressionContext>(i);
}


size_t MyLanguageParser::ForLoopContext::getRuleIndex() const {
  return MyLanguageParser::RuleForLoop;
}

void MyLanguageParser::ForLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForLoop(this);
}

void MyLanguageParser::ForLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForLoop(this);
}


std::any MyLanguageParser::ForLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitForLoop(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::ForLoopContext* MyLanguageParser::forLoop() {
  ForLoopContext *_localctx = _tracker.createInstance<ForLoopContext>(_ctx, getState());
  enterRule(_localctx, 16, MyLanguageParser::RuleForLoop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    match(MyLanguageParser::T__10);
    setState(104);
    match(MyLanguageParser::T__4);
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyLanguageParser::T__0: {
        setState(105);
        varDeclaration();
        break;
      }

      case MyLanguageParser::ID: {
        setState(106);
        assignment();
        break;
      }

      case MyLanguageParser::T__2: {
        setState(107);
        match(MyLanguageParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(111);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4267704352) != 0)) {
      setState(110);
      expression();
    }
    setState(113);
    match(MyLanguageParser::T__2);
    setState(116);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(114);
      expression();
      break;
    }

    case 2: {
      setState(115);
      assignment();
      break;
    }

    default:
      break;
    }
    setState(118);
    match(MyLanguageParser::T__5);
    setState(119);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

MyLanguageParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MyLanguageParser::ExpressionContext* MyLanguageParser::ReturnStatementContext::expression() {
  return getRuleContext<MyLanguageParser::ExpressionContext>(0);
}


size_t MyLanguageParser::ReturnStatementContext::getRuleIndex() const {
  return MyLanguageParser::RuleReturnStatement;
}

void MyLanguageParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void MyLanguageParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}


std::any MyLanguageParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::ReturnStatementContext* MyLanguageParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, MyLanguageParser::RuleReturnStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(MyLanguageParser::T__11);
    setState(123);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4267704352) != 0)) {
      setState(122);
      expression();
    }
    setState(125);
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


std::any MyLanguageParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::BlockContext* MyLanguageParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 20, MyLanguageParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(MyLanguageParser::T__12);
    setState(131);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4267711794) != 0)) {
      setState(128);
      statement();
      setState(133);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(134);
    match(MyLanguageParser::T__13);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

MyLanguageParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MyLanguageParser::ExpressionContext* MyLanguageParser::ExpressionStatementContext::expression() {
  return getRuleContext<MyLanguageParser::ExpressionContext>(0);
}


size_t MyLanguageParser::ExpressionStatementContext::getRuleIndex() const {
  return MyLanguageParser::RuleExpressionStatement;
}

void MyLanguageParser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void MyLanguageParser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}


std::any MyLanguageParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::ExpressionStatementContext* MyLanguageParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, MyLanguageParser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    expression();
    setState(137);
    match(MyLanguageParser::T__2);
   
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

MyLanguageParser::ComparisonContext* MyLanguageParser::ExpressionContext::comparison() {
  return getRuleContext<MyLanguageParser::ComparisonContext>(0);
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


std::any MyLanguageParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::ExpressionContext* MyLanguageParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 24, MyLanguageParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    comparison();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonContext ------------------------------------------------------------------

MyLanguageParser::ComparisonContext::ComparisonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MyLanguageParser::AdditionContext *> MyLanguageParser::ComparisonContext::addition() {
  return getRuleContexts<MyLanguageParser::AdditionContext>();
}

MyLanguageParser::AdditionContext* MyLanguageParser::ComparisonContext::addition(size_t i) {
  return getRuleContext<MyLanguageParser::AdditionContext>(i);
}


size_t MyLanguageParser::ComparisonContext::getRuleIndex() const {
  return MyLanguageParser::RuleComparison;
}

void MyLanguageParser::ComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison(this);
}

void MyLanguageParser::ComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison(this);
}


std::any MyLanguageParser::ComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitComparison(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::ComparisonContext* MyLanguageParser::comparison() {
  ComparisonContext *_localctx = _tracker.createInstance<ComparisonContext>(_ctx, getState());
  enterRule(_localctx, 26, MyLanguageParser::RuleComparison);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    addition();
    setState(146);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2064384) != 0)) {
      setState(142);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2064384) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(143);
      addition();
      setState(148);
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

//----------------- AdditionContext ------------------------------------------------------------------

MyLanguageParser::AdditionContext::AdditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MyLanguageParser::MultiplicationContext *> MyLanguageParser::AdditionContext::multiplication() {
  return getRuleContexts<MyLanguageParser::MultiplicationContext>();
}

MyLanguageParser::MultiplicationContext* MyLanguageParser::AdditionContext::multiplication(size_t i) {
  return getRuleContext<MyLanguageParser::MultiplicationContext>(i);
}


size_t MyLanguageParser::AdditionContext::getRuleIndex() const {
  return MyLanguageParser::RuleAddition;
}

void MyLanguageParser::AdditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddition(this);
}

void MyLanguageParser::AdditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddition(this);
}


std::any MyLanguageParser::AdditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitAddition(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::AdditionContext* MyLanguageParser::addition() {
  AdditionContext *_localctx = _tracker.createInstance<AdditionContext>(_ctx, getState());
  enterRule(_localctx, 28, MyLanguageParser::RuleAddition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    multiplication();
    setState(154);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyLanguageParser::T__20

    || _la == MyLanguageParser::T__21) {
      setState(150);
      _la = _input->LA(1);
      if (!(_la == MyLanguageParser::T__20

      || _la == MyLanguageParser::T__21)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(151);
      multiplication();
      setState(156);
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

//----------------- MultiplicationContext ------------------------------------------------------------------

MyLanguageParser::MultiplicationContext::MultiplicationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MyLanguageParser::UnaryContext *> MyLanguageParser::MultiplicationContext::unary() {
  return getRuleContexts<MyLanguageParser::UnaryContext>();
}

MyLanguageParser::UnaryContext* MyLanguageParser::MultiplicationContext::unary(size_t i) {
  return getRuleContext<MyLanguageParser::UnaryContext>(i);
}


size_t MyLanguageParser::MultiplicationContext::getRuleIndex() const {
  return MyLanguageParser::RuleMultiplication;
}

void MyLanguageParser::MultiplicationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplication(this);
}

void MyLanguageParser::MultiplicationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplication(this);
}


std::any MyLanguageParser::MultiplicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitMultiplication(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::MultiplicationContext* MyLanguageParser::multiplication() {
  MultiplicationContext *_localctx = _tracker.createInstance<MultiplicationContext>(_ctx, getState());
  enterRule(_localctx, 30, MyLanguageParser::RuleMultiplication);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    unary();
    setState(162);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyLanguageParser::T__22

    || _la == MyLanguageParser::T__23) {
      setState(158);
      _la = _input->LA(1);
      if (!(_la == MyLanguageParser::T__22

      || _la == MyLanguageParser::T__23)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(159);
      unary();
      setState(164);
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

//----------------- UnaryContext ------------------------------------------------------------------

MyLanguageParser::UnaryContext::UnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MyLanguageParser::UnaryContext* MyLanguageParser::UnaryContext::unary() {
  return getRuleContext<MyLanguageParser::UnaryContext>(0);
}

MyLanguageParser::PrimaryContext* MyLanguageParser::UnaryContext::primary() {
  return getRuleContext<MyLanguageParser::PrimaryContext>(0);
}


size_t MyLanguageParser::UnaryContext::getRuleIndex() const {
  return MyLanguageParser::RuleUnary;
}

void MyLanguageParser::UnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary(this);
}

void MyLanguageParser::UnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary(this);
}


std::any MyLanguageParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::UnaryContext* MyLanguageParser::unary() {
  UnaryContext *_localctx = _tracker.createInstance<UnaryContext>(_ctx, getState());
  enterRule(_localctx, 32, MyLanguageParser::RuleUnary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(168);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyLanguageParser::T__20:
      case MyLanguageParser::T__21:
      case MyLanguageParser::T__24: {
        enterOuterAlt(_localctx, 1);
        setState(165);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 39845888) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(166);
        unary();
        break;
      }

      case MyLanguageParser::T__4:
      case MyLanguageParser::T__25:
      case MyLanguageParser::T__26:
      case MyLanguageParser::ID:
      case MyLanguageParser::INT:
      case MyLanguageParser::FLOAT:
      case MyLanguageParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(167);
        primary();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

MyLanguageParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyLanguageParser::PrimaryContext::INT() {
  return getToken(MyLanguageParser::INT, 0);
}

tree::TerminalNode* MyLanguageParser::PrimaryContext::FLOAT() {
  return getToken(MyLanguageParser::FLOAT, 0);
}

tree::TerminalNode* MyLanguageParser::PrimaryContext::STRING() {
  return getToken(MyLanguageParser::STRING, 0);
}

MyLanguageParser::ExpressionContext* MyLanguageParser::PrimaryContext::expression() {
  return getRuleContext<MyLanguageParser::ExpressionContext>(0);
}

tree::TerminalNode* MyLanguageParser::PrimaryContext::ID() {
  return getToken(MyLanguageParser::ID, 0);
}

MyLanguageParser::FunctionCallContext* MyLanguageParser::PrimaryContext::functionCall() {
  return getRuleContext<MyLanguageParser::FunctionCallContext>(0);
}


size_t MyLanguageParser::PrimaryContext::getRuleIndex() const {
  return MyLanguageParser::RulePrimary;
}

void MyLanguageParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void MyLanguageParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}


std::any MyLanguageParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::PrimaryContext* MyLanguageParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 34, MyLanguageParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(181);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(170);
      match(MyLanguageParser::INT);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(171);
      match(MyLanguageParser::FLOAT);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(172);
      match(MyLanguageParser::STRING);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(173);
      match(MyLanguageParser::T__25);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(174);
      match(MyLanguageParser::T__26);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(175);
      match(MyLanguageParser::T__4);
      setState(176);
      expression();
      setState(177);
      match(MyLanguageParser::T__5);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(179);
      match(MyLanguageParser::ID);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(180);
      functionCall();
      break;
    }

    default:
      break;
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

tree::TerminalNode* MyLanguageParser::FunctionCallContext::ID() {
  return getToken(MyLanguageParser::ID, 0);
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


std::any MyLanguageParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::FunctionCallContext* MyLanguageParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 36, MyLanguageParser::RuleFunctionCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    match(MyLanguageParser::ID);
    setState(184);
    match(MyLanguageParser::T__4);
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4267704352) != 0)) {
      setState(185);
      argumentList();
    }
    setState(188);
    match(MyLanguageParser::T__5);
   
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


std::any MyLanguageParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyLanguageVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

MyLanguageParser::ArgumentListContext* MyLanguageParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 38, MyLanguageParser::RuleArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    expression();
    setState(195);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyLanguageParser::T__6) {
      setState(191);
      match(MyLanguageParser::T__6);
      setState(192);
      expression();
      setState(197);
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

void MyLanguageParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mylanguageParserInitialize();
#else
  ::antlr4::internal::call_once(mylanguageParserOnceFlag, mylanguageParserInitialize);
#endif
}
