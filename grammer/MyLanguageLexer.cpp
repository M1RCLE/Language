
// Generated from study/Language/grammer/MyLanguage.g4 by ANTLR 4.13.2


#include "MyLanguageLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct MyLanguageLexerStaticData final {
  MyLanguageLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MyLanguageLexerStaticData(const MyLanguageLexerStaticData&) = delete;
  MyLanguageLexerStaticData(MyLanguageLexerStaticData&&) = delete;
  MyLanguageLexerStaticData& operator=(const MyLanguageLexerStaticData&) = delete;
  MyLanguageLexerStaticData& operator=(MyLanguageLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mylanguagelexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<MyLanguageLexerStaticData> mylanguagelexerLexerStaticData = nullptr;

void mylanguagelexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mylanguagelexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(mylanguagelexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MyLanguageLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "T__19", "T__20", "T__21", "T__22", "T__23", "T__24", 
      "T__25", "T__26", "ID", "INT", "FLOAT", "STRING", "WS", "COMMENT", 
      "MULTILINE_COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,34,220,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,1,0,1,0,1,0,1,
  	0,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,
  	1,7,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,14,1,
  	15,1,15,1,15,1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,20,1,
  	20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,
  	26,1,26,1,26,1,26,1,26,1,26,1,27,1,27,5,27,157,8,27,10,27,12,27,160,9,
  	27,1,28,4,28,163,8,28,11,28,12,28,164,1,29,4,29,168,8,29,11,29,12,29,
  	169,1,29,1,29,4,29,174,8,29,11,29,12,29,175,1,30,1,30,1,30,1,30,5,30,
  	182,8,30,10,30,12,30,185,9,30,1,30,1,30,1,31,4,31,190,8,31,11,31,12,31,
  	191,1,31,1,31,1,32,1,32,1,32,1,32,5,32,200,8,32,10,32,12,32,203,9,32,
  	1,32,1,32,1,33,1,33,1,33,1,33,5,33,211,8,33,10,33,12,33,214,9,33,1,33,
  	1,33,1,33,1,33,1,33,1,212,0,34,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,
  	9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,
  	21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,
  	65,33,67,34,1,0,6,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,
  	1,0,48,57,2,0,34,34,92,92,3,0,9,10,13,13,32,32,2,0,10,10,13,13,228,0,
  	1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,
  	0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,
  	23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,
  	0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,
  	0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,
  	55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,
  	0,0,0,0,67,1,0,0,0,1,69,1,0,0,0,3,73,1,0,0,0,5,75,1,0,0,0,7,77,1,0,0,
  	0,9,82,1,0,0,0,11,84,1,0,0,0,13,86,1,0,0,0,15,88,1,0,0,0,17,91,1,0,0,
  	0,19,96,1,0,0,0,21,102,1,0,0,0,23,106,1,0,0,0,25,113,1,0,0,0,27,115,1,
  	0,0,0,29,117,1,0,0,0,31,120,1,0,0,0,33,123,1,0,0,0,35,125,1,0,0,0,37,
  	128,1,0,0,0,39,130,1,0,0,0,41,133,1,0,0,0,43,135,1,0,0,0,45,137,1,0,0,
  	0,47,139,1,0,0,0,49,141,1,0,0,0,51,143,1,0,0,0,53,148,1,0,0,0,55,154,
  	1,0,0,0,57,162,1,0,0,0,59,167,1,0,0,0,61,177,1,0,0,0,63,189,1,0,0,0,65,
  	195,1,0,0,0,67,206,1,0,0,0,69,70,5,108,0,0,70,71,5,101,0,0,71,72,5,116,
  	0,0,72,2,1,0,0,0,73,74,5,61,0,0,74,4,1,0,0,0,75,76,5,59,0,0,76,6,1,0,
  	0,0,77,78,5,102,0,0,78,79,5,117,0,0,79,80,5,110,0,0,80,81,5,99,0,0,81,
  	8,1,0,0,0,82,83,5,40,0,0,83,10,1,0,0,0,84,85,5,41,0,0,85,12,1,0,0,0,86,
  	87,5,44,0,0,87,14,1,0,0,0,88,89,5,105,0,0,89,90,5,102,0,0,90,16,1,0,0,
  	0,91,92,5,101,0,0,92,93,5,108,0,0,93,94,5,115,0,0,94,95,5,101,0,0,95,
  	18,1,0,0,0,96,97,5,119,0,0,97,98,5,104,0,0,98,99,5,105,0,0,99,100,5,108,
  	0,0,100,101,5,101,0,0,101,20,1,0,0,0,102,103,5,102,0,0,103,104,5,111,
  	0,0,104,105,5,114,0,0,105,22,1,0,0,0,106,107,5,114,0,0,107,108,5,101,
  	0,0,108,109,5,116,0,0,109,110,5,117,0,0,110,111,5,114,0,0,111,112,5,110,
  	0,0,112,24,1,0,0,0,113,114,5,123,0,0,114,26,1,0,0,0,115,116,5,125,0,0,
  	116,28,1,0,0,0,117,118,5,61,0,0,118,119,5,61,0,0,119,30,1,0,0,0,120,121,
  	5,33,0,0,121,122,5,61,0,0,122,32,1,0,0,0,123,124,5,60,0,0,124,34,1,0,
  	0,0,125,126,5,60,0,0,126,127,5,61,0,0,127,36,1,0,0,0,128,129,5,62,0,0,
  	129,38,1,0,0,0,130,131,5,62,0,0,131,132,5,61,0,0,132,40,1,0,0,0,133,134,
  	5,43,0,0,134,42,1,0,0,0,135,136,5,45,0,0,136,44,1,0,0,0,137,138,5,42,
  	0,0,138,46,1,0,0,0,139,140,5,47,0,0,140,48,1,0,0,0,141,142,5,33,0,0,142,
  	50,1,0,0,0,143,144,5,116,0,0,144,145,5,114,0,0,145,146,5,117,0,0,146,
  	147,5,101,0,0,147,52,1,0,0,0,148,149,5,102,0,0,149,150,5,97,0,0,150,151,
  	5,108,0,0,151,152,5,115,0,0,152,153,5,101,0,0,153,54,1,0,0,0,154,158,
  	7,0,0,0,155,157,7,1,0,0,156,155,1,0,0,0,157,160,1,0,0,0,158,156,1,0,0,
  	0,158,159,1,0,0,0,159,56,1,0,0,0,160,158,1,0,0,0,161,163,7,2,0,0,162,
  	161,1,0,0,0,163,164,1,0,0,0,164,162,1,0,0,0,164,165,1,0,0,0,165,58,1,
  	0,0,0,166,168,7,2,0,0,167,166,1,0,0,0,168,169,1,0,0,0,169,167,1,0,0,0,
  	169,170,1,0,0,0,170,171,1,0,0,0,171,173,5,46,0,0,172,174,7,2,0,0,173,
  	172,1,0,0,0,174,175,1,0,0,0,175,173,1,0,0,0,175,176,1,0,0,0,176,60,1,
  	0,0,0,177,183,5,34,0,0,178,182,8,3,0,0,179,180,5,92,0,0,180,182,9,0,0,
  	0,181,178,1,0,0,0,181,179,1,0,0,0,182,185,1,0,0,0,183,181,1,0,0,0,183,
  	184,1,0,0,0,184,186,1,0,0,0,185,183,1,0,0,0,186,187,5,34,0,0,187,62,1,
  	0,0,0,188,190,7,4,0,0,189,188,1,0,0,0,190,191,1,0,0,0,191,189,1,0,0,0,
  	191,192,1,0,0,0,192,193,1,0,0,0,193,194,6,31,0,0,194,64,1,0,0,0,195,196,
  	5,47,0,0,196,197,5,47,0,0,197,201,1,0,0,0,198,200,8,5,0,0,199,198,1,0,
  	0,0,200,203,1,0,0,0,201,199,1,0,0,0,201,202,1,0,0,0,202,204,1,0,0,0,203,
  	201,1,0,0,0,204,205,6,32,0,0,205,66,1,0,0,0,206,207,5,47,0,0,207,208,
  	5,42,0,0,208,212,1,0,0,0,209,211,9,0,0,0,210,209,1,0,0,0,211,214,1,0,
  	0,0,212,213,1,0,0,0,212,210,1,0,0,0,213,215,1,0,0,0,214,212,1,0,0,0,215,
  	216,5,42,0,0,216,217,5,47,0,0,217,218,1,0,0,0,218,219,6,33,0,0,219,68,
  	1,0,0,0,10,0,158,164,169,175,181,183,191,201,212,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mylanguagelexerLexerStaticData = std::move(staticData);
}

}

MyLanguageLexer::MyLanguageLexer(CharStream *input) : Lexer(input) {
  MyLanguageLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *mylanguagelexerLexerStaticData->atn, mylanguagelexerLexerStaticData->decisionToDFA, mylanguagelexerLexerStaticData->sharedContextCache);
}

MyLanguageLexer::~MyLanguageLexer() {
  delete _interpreter;
}

std::string MyLanguageLexer::getGrammarFileName() const {
  return "MyLanguage.g4";
}

const std::vector<std::string>& MyLanguageLexer::getRuleNames() const {
  return mylanguagelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& MyLanguageLexer::getChannelNames() const {
  return mylanguagelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& MyLanguageLexer::getModeNames() const {
  return mylanguagelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& MyLanguageLexer::getVocabulary() const {
  return mylanguagelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MyLanguageLexer::getSerializedATN() const {
  return mylanguagelexerLexerStaticData->serializedATN;
}

const atn::ATN& MyLanguageLexer::getATN() const {
  return *mylanguagelexerLexerStaticData->atn;
}




void MyLanguageLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mylanguagelexerLexerInitialize();
#else
  ::antlr4::internal::call_once(mylanguagelexerLexerOnceFlag, mylanguagelexerLexerInitialize);
#endif
}
