
// Generated from study/Language/grammer/MyLanguage.g4 by ANTLR 4.13.2


#include "MyLanguageListener.h"

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
      "parameterList", "ifStatement", "whileLoop", "forLoopAssignment", 
      "forLoop", "returnStatement", "block", "expressionStatement", "expression", 
      "comparison", "addition", "multiplication", "unary", "primary", "functionCall", 
      "argumentList"
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
  	4,1,34,205,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,1,0,5,
  	0,44,8,0,10,0,12,0,47,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,
  	59,8,1,1,2,1,2,1,2,1,2,3,2,65,8,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,
  	1,4,1,4,3,4,78,8,4,1,4,1,4,1,4,1,5,1,5,1,5,5,5,86,8,5,10,5,12,5,89,9,
  	5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,98,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,
  	1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,3,9,115,8,9,1,9,3,9,118,8,9,1,9,1,9,1,
  	9,3,9,123,8,9,1,9,1,9,1,9,1,10,1,10,3,10,130,8,10,1,10,1,10,1,11,1,11,
  	5,11,136,8,11,10,11,12,11,139,9,11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,
  	1,14,1,14,1,14,5,14,151,8,14,10,14,12,14,154,9,14,1,15,1,15,1,15,5,15,
  	159,8,15,10,15,12,15,162,9,15,1,16,1,16,1,16,5,16,167,8,16,10,16,12,16,
  	170,9,16,1,17,1,17,1,17,3,17,175,8,17,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,1,18,1,18,1,18,3,18,188,8,18,1,19,1,19,1,19,3,19,193,8,19,1,19,
  	1,19,1,20,1,20,1,20,5,20,200,8,20,10,20,12,20,203,9,20,1,20,0,0,21,0,
  	2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0,4,1,0,15,20,
  	1,0,21,22,1,0,23,24,2,0,21,22,25,25,215,0,45,1,0,0,0,2,58,1,0,0,0,4,60,
  	1,0,0,0,6,68,1,0,0,0,8,73,1,0,0,0,10,82,1,0,0,0,12,90,1,0,0,0,14,99,1,
  	0,0,0,16,105,1,0,0,0,18,109,1,0,0,0,20,127,1,0,0,0,22,133,1,0,0,0,24,
  	142,1,0,0,0,26,145,1,0,0,0,28,147,1,0,0,0,30,155,1,0,0,0,32,163,1,0,0,
  	0,34,174,1,0,0,0,36,187,1,0,0,0,38,189,1,0,0,0,40,196,1,0,0,0,42,44,3,
  	2,1,0,43,42,1,0,0,0,44,47,1,0,0,0,45,43,1,0,0,0,45,46,1,0,0,0,46,48,1,
  	0,0,0,47,45,1,0,0,0,48,49,5,0,0,1,49,1,1,0,0,0,50,59,3,4,2,0,51,59,3,
  	6,3,0,52,59,3,8,4,0,53,59,3,12,6,0,54,59,3,14,7,0,55,59,3,18,9,0,56,59,
  	3,24,12,0,57,59,3,20,10,0,58,50,1,0,0,0,58,51,1,0,0,0,58,52,1,0,0,0,58,
  	53,1,0,0,0,58,54,1,0,0,0,58,55,1,0,0,0,58,56,1,0,0,0,58,57,1,0,0,0,59,
  	3,1,0,0,0,60,61,5,1,0,0,61,64,5,28,0,0,62,63,5,2,0,0,63,65,3,26,13,0,
  	64,62,1,0,0,0,64,65,1,0,0,0,65,66,1,0,0,0,66,67,5,3,0,0,67,5,1,0,0,0,
  	68,69,5,28,0,0,69,70,5,2,0,0,70,71,3,26,13,0,71,72,5,3,0,0,72,7,1,0,0,
  	0,73,74,5,4,0,0,74,75,5,28,0,0,75,77,5,5,0,0,76,78,3,10,5,0,77,76,1,0,
  	0,0,77,78,1,0,0,0,78,79,1,0,0,0,79,80,5,6,0,0,80,81,3,22,11,0,81,9,1,
  	0,0,0,82,87,5,28,0,0,83,84,5,7,0,0,84,86,5,28,0,0,85,83,1,0,0,0,86,89,
  	1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,11,1,0,0,0,89,87,1,0,0,0,90,91,
  	5,8,0,0,91,92,5,5,0,0,92,93,3,26,13,0,93,94,5,6,0,0,94,97,3,22,11,0,95,
  	96,5,9,0,0,96,98,3,22,11,0,97,95,1,0,0,0,97,98,1,0,0,0,98,13,1,0,0,0,
  	99,100,5,10,0,0,100,101,5,5,0,0,101,102,3,26,13,0,102,103,5,6,0,0,103,
  	104,3,22,11,0,104,15,1,0,0,0,105,106,5,28,0,0,106,107,5,2,0,0,107,108,
  	3,26,13,0,108,17,1,0,0,0,109,110,5,11,0,0,110,114,5,5,0,0,111,115,3,4,
  	2,0,112,115,3,6,3,0,113,115,5,3,0,0,114,111,1,0,0,0,114,112,1,0,0,0,114,
  	113,1,0,0,0,115,117,1,0,0,0,116,118,3,26,13,0,117,116,1,0,0,0,117,118,
  	1,0,0,0,118,119,1,0,0,0,119,122,5,3,0,0,120,123,3,26,13,0,121,123,3,16,
  	8,0,122,120,1,0,0,0,122,121,1,0,0,0,122,123,1,0,0,0,123,124,1,0,0,0,124,
  	125,5,6,0,0,125,126,3,22,11,0,126,19,1,0,0,0,127,129,5,12,0,0,128,130,
  	3,26,13,0,129,128,1,0,0,0,129,130,1,0,0,0,130,131,1,0,0,0,131,132,5,3,
  	0,0,132,21,1,0,0,0,133,137,5,13,0,0,134,136,3,2,1,0,135,134,1,0,0,0,136,
  	139,1,0,0,0,137,135,1,0,0,0,137,138,1,0,0,0,138,140,1,0,0,0,139,137,1,
  	0,0,0,140,141,5,14,0,0,141,23,1,0,0,0,142,143,3,26,13,0,143,144,5,3,0,
  	0,144,25,1,0,0,0,145,146,3,28,14,0,146,27,1,0,0,0,147,152,3,30,15,0,148,
  	149,7,0,0,0,149,151,3,30,15,0,150,148,1,0,0,0,151,154,1,0,0,0,152,150,
  	1,0,0,0,152,153,1,0,0,0,153,29,1,0,0,0,154,152,1,0,0,0,155,160,3,32,16,
  	0,156,157,7,1,0,0,157,159,3,32,16,0,158,156,1,0,0,0,159,162,1,0,0,0,160,
  	158,1,0,0,0,160,161,1,0,0,0,161,31,1,0,0,0,162,160,1,0,0,0,163,168,3,
  	34,17,0,164,165,7,2,0,0,165,167,3,34,17,0,166,164,1,0,0,0,167,170,1,0,
  	0,0,168,166,1,0,0,0,168,169,1,0,0,0,169,33,1,0,0,0,170,168,1,0,0,0,171,
  	172,7,3,0,0,172,175,3,34,17,0,173,175,3,36,18,0,174,171,1,0,0,0,174,173,
  	1,0,0,0,175,35,1,0,0,0,176,188,5,29,0,0,177,188,5,30,0,0,178,188,5,31,
  	0,0,179,188,5,26,0,0,180,188,5,27,0,0,181,182,5,5,0,0,182,183,3,26,13,
  	0,183,184,5,6,0,0,184,188,1,0,0,0,185,188,5,28,0,0,186,188,3,38,19,0,
  	187,176,1,0,0,0,187,177,1,0,0,0,187,178,1,0,0,0,187,179,1,0,0,0,187,180,
  	1,0,0,0,187,181,1,0,0,0,187,185,1,0,0,0,187,186,1,0,0,0,188,37,1,0,0,
  	0,189,190,5,28,0,0,190,192,5,5,0,0,191,193,3,40,20,0,192,191,1,0,0,0,
  	192,193,1,0,0,0,193,194,1,0,0,0,194,195,5,6,0,0,195,39,1,0,0,0,196,201,
  	3,26,13,0,197,198,5,7,0,0,198,200,3,26,13,0,199,197,1,0,0,0,200,203,1,
  	0,0,0,201,199,1,0,0,0,201,202,1,0,0,0,202,41,1,0,0,0,203,201,1,0,0,0,
  	18,45,58,64,77,87,97,114,117,122,129,137,152,160,168,174,187,192,201
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
    setState(45);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4267711794) != 0)) {
      setState(42);
      statement();
      setState(47);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(48);
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
    setState(58);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(50);
      varDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(51);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(52);
      functionDeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(53);
      ifStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(54);
      whileLoop();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(55);
      forLoop();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(56);
      expressionStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(57);
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
    setState(60);
    match(MyLanguageParser::T__0);
    setState(61);
    match(MyLanguageParser::ID);
    setState(64);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MyLanguageParser::T__1) {
      setState(62);
      match(MyLanguageParser::T__1);
      setState(63);
      expression();
    }
    setState(66);
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
    setState(68);
    match(MyLanguageParser::ID);
    setState(69);
    match(MyLanguageParser::T__1);
    setState(70);
    expression();
    setState(71);
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
    setState(73);
    match(MyLanguageParser::T__3);
    setState(74);
    match(MyLanguageParser::ID);
    setState(75);
    match(MyLanguageParser::T__4);
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MyLanguageParser::ID) {
      setState(76);
      parameterList();
    }
    setState(79);
    match(MyLanguageParser::T__5);
    setState(80);
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
    setState(82);
    match(MyLanguageParser::ID);
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyLanguageParser::T__6) {
      setState(83);
      match(MyLanguageParser::T__6);
      setState(84);
      match(MyLanguageParser::ID);
      setState(89);
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
    setState(90);
    match(MyLanguageParser::T__7);
    setState(91);
    match(MyLanguageParser::T__4);
    setState(92);
    expression();
    setState(93);
    match(MyLanguageParser::T__5);
    setState(94);
    block();
    setState(97);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MyLanguageParser::T__8) {
      setState(95);
      match(MyLanguageParser::T__8);
      setState(96);
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
    setState(99);
    match(MyLanguageParser::T__9);
    setState(100);
    match(MyLanguageParser::T__4);
    setState(101);
    expression();
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

//----------------- ForLoopAssignmentContext ------------------------------------------------------------------

MyLanguageParser::ForLoopAssignmentContext::ForLoopAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyLanguageParser::ForLoopAssignmentContext::ID() {
  return getToken(MyLanguageParser::ID, 0);
}

MyLanguageParser::ExpressionContext* MyLanguageParser::ForLoopAssignmentContext::expression() {
  return getRuleContext<MyLanguageParser::ExpressionContext>(0);
}


size_t MyLanguageParser::ForLoopAssignmentContext::getRuleIndex() const {
  return MyLanguageParser::RuleForLoopAssignment;
}

void MyLanguageParser::ForLoopAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForLoopAssignment(this);
}

void MyLanguageParser::ForLoopAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForLoopAssignment(this);
}

MyLanguageParser::ForLoopAssignmentContext* MyLanguageParser::forLoopAssignment() {
  ForLoopAssignmentContext *_localctx = _tracker.createInstance<ForLoopAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 16, MyLanguageParser::RuleForLoopAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(MyLanguageParser::ID);
    setState(106);
    match(MyLanguageParser::T__1);
    setState(107);
    expression();
   
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

MyLanguageParser::AssignmentContext* MyLanguageParser::ForLoopContext::assignment() {
  return getRuleContext<MyLanguageParser::AssignmentContext>(0);
}

std::vector<MyLanguageParser::ExpressionContext *> MyLanguageParser::ForLoopContext::expression() {
  return getRuleContexts<MyLanguageParser::ExpressionContext>();
}

MyLanguageParser::ExpressionContext* MyLanguageParser::ForLoopContext::expression(size_t i) {
  return getRuleContext<MyLanguageParser::ExpressionContext>(i);
}

MyLanguageParser::ForLoopAssignmentContext* MyLanguageParser::ForLoopContext::forLoopAssignment() {
  return getRuleContext<MyLanguageParser::ForLoopAssignmentContext>(0);
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

MyLanguageParser::ForLoopContext* MyLanguageParser::forLoop() {
  ForLoopContext *_localctx = _tracker.createInstance<ForLoopContext>(_ctx, getState());
  enterRule(_localctx, 18, MyLanguageParser::RuleForLoop);
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
    setState(109);
    match(MyLanguageParser::T__10);
    setState(110);
    match(MyLanguageParser::T__4);
    setState(114);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyLanguageParser::T__0: {
        setState(111);
        varDeclaration();
        break;
      }

      case MyLanguageParser::ID: {
        setState(112);
        assignment();
        break;
      }

      case MyLanguageParser::T__2: {
        setState(113);
        match(MyLanguageParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(117);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4267704352) != 0)) {
      setState(116);
      expression();
    }
    setState(119);
    match(MyLanguageParser::T__2);
    setState(122);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(120);
      expression();
      break;
    }

    case 2: {
      setState(121);
      forLoopAssignment();
      break;
    }

    default:
      break;
    }
    setState(124);
    match(MyLanguageParser::T__5);
    setState(125);
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

MyLanguageParser::ReturnStatementContext* MyLanguageParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, MyLanguageParser::RuleReturnStatement);
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
    match(MyLanguageParser::T__11);
    setState(129);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4267704352) != 0)) {
      setState(128);
      expression();
    }
    setState(131);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(MyLanguageParser::T__12);
    setState(137);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4267711794) != 0)) {
      setState(134);
      statement();
      setState(139);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(140);
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

MyLanguageParser::ExpressionStatementContext* MyLanguageParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, MyLanguageParser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    expression();
    setState(143);
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

MyLanguageParser::ExpressionContext* MyLanguageParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 26, MyLanguageParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
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

MyLanguageParser::ComparisonContext* MyLanguageParser::comparison() {
  ComparisonContext *_localctx = _tracker.createInstance<ComparisonContext>(_ctx, getState());
  enterRule(_localctx, 28, MyLanguageParser::RuleComparison);
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
    setState(147);
    addition();
    setState(152);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2064384) != 0)) {
      setState(148);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2064384) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(149);
      addition();
      setState(154);
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

MyLanguageParser::AdditionContext* MyLanguageParser::addition() {
  AdditionContext *_localctx = _tracker.createInstance<AdditionContext>(_ctx, getState());
  enterRule(_localctx, 30, MyLanguageParser::RuleAddition);
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
    setState(155);
    multiplication();
    setState(160);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyLanguageParser::T__20

    || _la == MyLanguageParser::T__21) {
      setState(156);
      _la = _input->LA(1);
      if (!(_la == MyLanguageParser::T__20

      || _la == MyLanguageParser::T__21)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(157);
      multiplication();
      setState(162);
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

MyLanguageParser::MultiplicationContext* MyLanguageParser::multiplication() {
  MultiplicationContext *_localctx = _tracker.createInstance<MultiplicationContext>(_ctx, getState());
  enterRule(_localctx, 32, MyLanguageParser::RuleMultiplication);
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
    setState(163);
    unary();
    setState(168);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyLanguageParser::T__22

    || _la == MyLanguageParser::T__23) {
      setState(164);
      _la = _input->LA(1);
      if (!(_la == MyLanguageParser::T__22

      || _la == MyLanguageParser::T__23)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(165);
      unary();
      setState(170);
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

MyLanguageParser::UnaryContext* MyLanguageParser::unary() {
  UnaryContext *_localctx = _tracker.createInstance<UnaryContext>(_ctx, getState());
  enterRule(_localctx, 34, MyLanguageParser::RuleUnary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(174);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyLanguageParser::T__20:
      case MyLanguageParser::T__21:
      case MyLanguageParser::T__24: {
        enterOuterAlt(_localctx, 1);
        setState(171);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 39845888) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(172);
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
        setState(173);
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

MyLanguageParser::PrimaryContext* MyLanguageParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 36, MyLanguageParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(187);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(176);
      match(MyLanguageParser::INT);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(177);
      match(MyLanguageParser::FLOAT);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(178);
      match(MyLanguageParser::STRING);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(179);
      match(MyLanguageParser::T__25);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(180);
      match(MyLanguageParser::T__26);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(181);
      match(MyLanguageParser::T__4);
      setState(182);
      expression();
      setState(183);
      match(MyLanguageParser::T__5);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(185);
      match(MyLanguageParser::ID);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(186);
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

MyLanguageParser::FunctionCallContext* MyLanguageParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 38, MyLanguageParser::RuleFunctionCall);
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
    setState(189);
    match(MyLanguageParser::ID);
    setState(190);
    match(MyLanguageParser::T__4);
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4267704352) != 0)) {
      setState(191);
      argumentList();
    }
    setState(194);
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

MyLanguageParser::ArgumentListContext* MyLanguageParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 40, MyLanguageParser::RuleArgumentList);
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
    setState(196);
    expression();
    setState(201);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyLanguageParser::T__6) {
      setState(197);
      match(MyLanguageParser::T__6);
      setState(198);
      expression();
      setState(203);
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
