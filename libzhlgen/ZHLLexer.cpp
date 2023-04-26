
// Generated from ZHLLexer.g4 by ANTLR 4.12.0


#include "ZHLLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ZHLLexerStaticData final {
  ZHLLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ZHLLexerStaticData(const ZHLLexerStaticData&) = delete;
  ZHLLexerStaticData(ZHLLexerStaticData&&) = delete;
  ZHLLexerStaticData& operator=(const ZHLLexerStaticData&) = delete;
  ZHLLexerStaticData& operator=(ZHLLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag zhllexerLexerOnceFlag;
ZHLLexerStaticData *zhllexerLexerStaticData = nullptr;

void zhllexerLexerInitialize() {
  assert(zhllexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<ZHLLexerStaticData>(
    std::vector<std::string>{
      "DoubleQuote", "Colon", "Semi", "Qualifier", "Cleanup", "Static", 
      "Virtual", "Declspec", "LeftParen", "RightParen", "Comma", "Star", 
      "Lt", "Gt", "LeftRBracket", "RightRBracket", "LeftBracket", "RightBracket", 
      "Class", "Struct", "Reference", "Depends", "Typedef", "Const", "CppRef", 
      "Unsigned", "Signed", "Long", "Int", "Short", "Char", "Bool", "Float", 
      "Double", "Void", "Visibility", "Public", "Private", "Protected", 
      "Register", "GeneralPurposeRegister", "Eax", "Ebx", "Ecx", "Edx", 
      "Esi", "Edi", "Esp", "Ebp", "SSERegister", "Xmm0", "Xmm1", "Xmm2", 
      "Xmm3", "Xmm4", "Xmm5", "Xmm6", "Xmm7", "CallingConvention", "Stdcall", 
      "Cdecl", "Fastcall", "Thiscall", "Signature", "ReferenceSignature", 
      "Name", "Number", "HexNumber", "DecNumber", "GenericCode", "Whitespace", 
      "Newline", "BlockComment", "LineComment", "Any"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'\"'", "':'", "';'", "", "'cleanup'", "'static'", "'virtual'", 
      "'__declspec'", "'('", "')'", "','", "'*'", "'<'", "'>'", "'['", "']'", 
      "'{'", "'}'", "'class'", "'struct'", "'reference'", "'depends'", "'typedef'", 
      "'const'", "'&'", "'unsigned'", "'signed'", "'long'", "'int'", "'short'", 
      "'char'", "'bool'", "'float'", "'double'", "'void'", "", "'public'", 
      "'private'", "'protected'", "", "", "'eax'", "'ebx'", "'ecx'", "'edx'", 
      "'esi'", "'edi'", "'esp'", "'ebp'", "", "'xmm0'", "'xmm1'", "'xmm2'", 
      "'xmm3'", "'xmm4'", "'xmm5'", "'xmm6'", "'xmm7'", "", "'__stdcall'", 
      "'__cdecl'", "'__fastcall'", "'__thiscall'"
    },
    std::vector<std::string>{
      "", "DoubleQuote", "Colon", "Semi", "Qualifier", "Cleanup", "Static", 
      "Virtual", "Declspec", "LeftParen", "RightParen", "Comma", "Star", 
      "Lt", "Gt", "LeftRBracket", "RightRBracket", "LeftBracket", "RightBracket", 
      "Class", "Struct", "Reference", "Depends", "Typedef", "Const", "CppRef", 
      "Unsigned", "Signed", "Long", "Int", "Short", "Char", "Bool", "Float", 
      "Double", "Void", "Visibility", "Public", "Private", "Protected", 
      "Register", "GeneralPurposeRegister", "Eax", "Ebx", "Ecx", "Edx", 
      "Esi", "Edi", "Esp", "Ebp", "SSERegister", "Xmm0", "Xmm1", "Xmm2", 
      "Xmm3", "Xmm4", "Xmm5", "Xmm6", "Xmm7", "CallingConvention", "Stdcall", 
      "Cdecl", "Fastcall", "Thiscall", "Signature", "ReferenceSignature", 
      "Name", "Number", "HexNumber", "DecNumber", "GenericCode", "Whitespace", 
      "Newline", "BlockComment", "LineComment", "Any"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,75,598,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,2,68,7,68,2,69,7,69,2,70,
  	7,70,2,71,7,71,2,72,7,72,2,73,7,73,2,74,7,74,1,0,1,0,1,1,1,1,1,2,1,2,
  	1,3,1,3,1,3,1,3,3,3,162,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,
  	1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,18,1,18,
  	1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,24,
  	1,24,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,26,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,28,1,28,1,28,1,28,1,29,1,29,
  	1,29,1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,31,1,31,1,31,1,31,1,31,
  	1,32,1,32,1,32,1,32,1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,34,
  	1,34,1,34,1,34,1,34,1,35,1,35,1,35,3,35,327,8,35,1,36,1,36,1,36,1,36,
  	1,36,1,36,1,36,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,38,1,38,1,38,
  	1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,39,1,39,3,39,356,8,39,1,40,1,40,
  	1,40,1,40,1,40,1,40,1,40,1,40,3,40,366,8,40,1,41,1,41,1,41,1,41,1,42,
  	1,42,1,42,1,42,1,43,1,43,1,43,1,43,1,44,1,44,1,44,1,44,1,45,1,45,1,45,
  	1,45,1,46,1,46,1,46,1,46,1,47,1,47,1,47,1,47,1,48,1,48,1,48,1,48,1,49,
  	1,49,1,49,1,49,1,49,1,49,1,49,1,49,3,49,408,8,49,1,50,1,50,1,50,1,50,
  	1,50,1,51,1,51,1,51,1,51,1,51,1,52,1,52,1,52,1,52,1,52,1,53,1,53,1,53,
  	1,53,1,53,1,54,1,54,1,54,1,54,1,54,1,55,1,55,1,55,1,55,1,55,1,56,1,56,
  	1,56,1,56,1,56,1,57,1,57,1,57,1,57,1,57,1,58,1,58,1,58,1,58,3,58,454,
  	8,58,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,60,1,60,1,60,
  	1,60,1,60,1,60,1,60,1,60,1,61,1,61,1,61,1,61,1,61,1,61,1,61,1,61,1,61,
  	1,61,1,61,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,63,
  	1,63,3,63,498,8,63,1,63,4,63,501,8,63,11,63,12,63,502,1,63,1,63,1,63,
  	1,64,1,64,3,64,510,8,64,1,64,4,64,513,8,64,11,64,12,64,514,1,64,1,64,
  	1,64,1,65,1,65,5,65,522,8,65,10,65,12,65,525,9,65,1,66,1,66,3,66,529,
  	8,66,1,67,1,67,1,67,1,67,4,67,535,8,67,11,67,12,67,536,1,68,4,68,540,
  	8,68,11,68,12,68,541,1,69,1,69,1,69,1,69,5,69,548,8,69,10,69,12,69,551,
  	9,69,1,69,1,69,1,69,1,70,4,70,557,8,70,11,70,12,70,558,1,70,1,70,1,71,
  	1,71,3,71,565,8,71,1,71,3,71,568,8,71,1,71,1,71,1,72,1,72,1,72,1,72,5,
  	72,576,8,72,10,72,12,72,579,9,72,1,72,1,72,1,72,1,72,1,72,1,73,1,73,1,
  	73,1,73,5,73,590,8,73,10,73,12,73,593,9,73,1,73,1,73,1,74,1,74,2,549,
  	577,0,75,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,
  	13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,
  	49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,
  	36,73,37,75,38,77,39,79,40,81,41,83,42,85,43,87,44,89,45,91,46,93,47,
  	95,48,97,49,99,50,101,51,103,52,105,53,107,54,109,55,111,56,113,57,115,
  	58,117,59,119,60,121,61,123,62,125,63,127,64,129,65,131,66,133,67,135,
  	68,137,69,139,70,141,71,143,72,145,73,147,74,149,75,1,0,8,4,0,48,57,63,
  	63,65,70,97,102,5,0,40,41,48,57,63,63,65,70,97,102,3,0,65,90,95,95,97,
  	122,4,0,48,57,65,90,95,95,97,122,3,0,48,57,65,70,97,102,1,0,48,57,2,0,
  	9,9,32,32,2,0,10,10,13,13,634,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,
  	1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,
  	0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,
  	29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,
  	0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,
  	0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,
  	61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,
  	0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,
  	0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,0,
  	93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,0,103,
  	1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,1,0,0,0,0,113,
  	1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,119,1,0,0,0,0,121,1,0,0,0,0,123,
  	1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,129,1,0,0,0,0,131,1,0,0,0,0,133,
  	1,0,0,0,0,135,1,0,0,0,0,137,1,0,0,0,0,139,1,0,0,0,0,141,1,0,0,0,0,143,
  	1,0,0,0,0,145,1,0,0,0,0,147,1,0,0,0,0,149,1,0,0,0,1,151,1,0,0,0,3,153,
  	1,0,0,0,5,155,1,0,0,0,7,161,1,0,0,0,9,163,1,0,0,0,11,171,1,0,0,0,13,178,
  	1,0,0,0,15,186,1,0,0,0,17,197,1,0,0,0,19,199,1,0,0,0,21,201,1,0,0,0,23,
  	203,1,0,0,0,25,205,1,0,0,0,27,207,1,0,0,0,29,209,1,0,0,0,31,211,1,0,0,
  	0,33,213,1,0,0,0,35,215,1,0,0,0,37,217,1,0,0,0,39,223,1,0,0,0,41,230,
  	1,0,0,0,43,240,1,0,0,0,45,248,1,0,0,0,47,256,1,0,0,0,49,262,1,0,0,0,51,
  	264,1,0,0,0,53,273,1,0,0,0,55,280,1,0,0,0,57,285,1,0,0,0,59,289,1,0,0,
  	0,61,295,1,0,0,0,63,300,1,0,0,0,65,305,1,0,0,0,67,311,1,0,0,0,69,318,
  	1,0,0,0,71,326,1,0,0,0,73,328,1,0,0,0,75,335,1,0,0,0,77,343,1,0,0,0,79,
  	355,1,0,0,0,81,365,1,0,0,0,83,367,1,0,0,0,85,371,1,0,0,0,87,375,1,0,0,
  	0,89,379,1,0,0,0,91,383,1,0,0,0,93,387,1,0,0,0,95,391,1,0,0,0,97,395,
  	1,0,0,0,99,407,1,0,0,0,101,409,1,0,0,0,103,414,1,0,0,0,105,419,1,0,0,
  	0,107,424,1,0,0,0,109,429,1,0,0,0,111,434,1,0,0,0,113,439,1,0,0,0,115,
  	444,1,0,0,0,117,453,1,0,0,0,119,455,1,0,0,0,121,465,1,0,0,0,123,473,1,
  	0,0,0,125,484,1,0,0,0,127,495,1,0,0,0,129,507,1,0,0,0,131,519,1,0,0,0,
  	133,528,1,0,0,0,135,530,1,0,0,0,137,539,1,0,0,0,139,543,1,0,0,0,141,556,
  	1,0,0,0,143,567,1,0,0,0,145,571,1,0,0,0,147,585,1,0,0,0,149,596,1,0,0,
  	0,151,152,5,34,0,0,152,2,1,0,0,0,153,154,5,58,0,0,154,4,1,0,0,0,155,156,
  	5,59,0,0,156,6,1,0,0,0,157,162,3,9,4,0,158,162,3,11,5,0,159,162,3,13,
  	6,0,160,162,3,15,7,0,161,157,1,0,0,0,161,158,1,0,0,0,161,159,1,0,0,0,
  	161,160,1,0,0,0,162,8,1,0,0,0,163,164,5,99,0,0,164,165,5,108,0,0,165,
  	166,5,101,0,0,166,167,5,97,0,0,167,168,5,110,0,0,168,169,5,117,0,0,169,
  	170,5,112,0,0,170,10,1,0,0,0,171,172,5,115,0,0,172,173,5,116,0,0,173,
  	174,5,97,0,0,174,175,5,116,0,0,175,176,5,105,0,0,176,177,5,99,0,0,177,
  	12,1,0,0,0,178,179,5,118,0,0,179,180,5,105,0,0,180,181,5,114,0,0,181,
  	182,5,116,0,0,182,183,5,117,0,0,183,184,5,97,0,0,184,185,5,108,0,0,185,
  	14,1,0,0,0,186,187,5,95,0,0,187,188,5,95,0,0,188,189,5,100,0,0,189,190,
  	5,101,0,0,190,191,5,99,0,0,191,192,5,108,0,0,192,193,5,115,0,0,193,194,
  	5,112,0,0,194,195,5,101,0,0,195,196,5,99,0,0,196,16,1,0,0,0,197,198,5,
  	40,0,0,198,18,1,0,0,0,199,200,5,41,0,0,200,20,1,0,0,0,201,202,5,44,0,
  	0,202,22,1,0,0,0,203,204,5,42,0,0,204,24,1,0,0,0,205,206,5,60,0,0,206,
  	26,1,0,0,0,207,208,5,62,0,0,208,28,1,0,0,0,209,210,5,91,0,0,210,30,1,
  	0,0,0,211,212,5,93,0,0,212,32,1,0,0,0,213,214,5,123,0,0,214,34,1,0,0,
  	0,215,216,5,125,0,0,216,36,1,0,0,0,217,218,5,99,0,0,218,219,5,108,0,0,
  	219,220,5,97,0,0,220,221,5,115,0,0,221,222,5,115,0,0,222,38,1,0,0,0,223,
  	224,5,115,0,0,224,225,5,116,0,0,225,226,5,114,0,0,226,227,5,117,0,0,227,
  	228,5,99,0,0,228,229,5,116,0,0,229,40,1,0,0,0,230,231,5,114,0,0,231,232,
  	5,101,0,0,232,233,5,102,0,0,233,234,5,101,0,0,234,235,5,114,0,0,235,236,
  	5,101,0,0,236,237,5,110,0,0,237,238,5,99,0,0,238,239,5,101,0,0,239,42,
  	1,0,0,0,240,241,5,100,0,0,241,242,5,101,0,0,242,243,5,112,0,0,243,244,
  	5,101,0,0,244,245,5,110,0,0,245,246,5,100,0,0,246,247,5,115,0,0,247,44,
  	1,0,0,0,248,249,5,116,0,0,249,250,5,121,0,0,250,251,5,112,0,0,251,252,
  	5,101,0,0,252,253,5,100,0,0,253,254,5,101,0,0,254,255,5,102,0,0,255,46,
  	1,0,0,0,256,257,5,99,0,0,257,258,5,111,0,0,258,259,5,110,0,0,259,260,
  	5,115,0,0,260,261,5,116,0,0,261,48,1,0,0,0,262,263,5,38,0,0,263,50,1,
  	0,0,0,264,265,5,117,0,0,265,266,5,110,0,0,266,267,5,115,0,0,267,268,5,
  	105,0,0,268,269,5,103,0,0,269,270,5,110,0,0,270,271,5,101,0,0,271,272,
  	5,100,0,0,272,52,1,0,0,0,273,274,5,115,0,0,274,275,5,105,0,0,275,276,
  	5,103,0,0,276,277,5,110,0,0,277,278,5,101,0,0,278,279,5,100,0,0,279,54,
  	1,0,0,0,280,281,5,108,0,0,281,282,5,111,0,0,282,283,5,110,0,0,283,284,
  	5,103,0,0,284,56,1,0,0,0,285,286,5,105,0,0,286,287,5,110,0,0,287,288,
  	5,116,0,0,288,58,1,0,0,0,289,290,5,115,0,0,290,291,5,104,0,0,291,292,
  	5,111,0,0,292,293,5,114,0,0,293,294,5,116,0,0,294,60,1,0,0,0,295,296,
  	5,99,0,0,296,297,5,104,0,0,297,298,5,97,0,0,298,299,5,114,0,0,299,62,
  	1,0,0,0,300,301,5,98,0,0,301,302,5,111,0,0,302,303,5,111,0,0,303,304,
  	5,108,0,0,304,64,1,0,0,0,305,306,5,102,0,0,306,307,5,108,0,0,307,308,
  	5,111,0,0,308,309,5,97,0,0,309,310,5,116,0,0,310,66,1,0,0,0,311,312,5,
  	100,0,0,312,313,5,111,0,0,313,314,5,117,0,0,314,315,5,98,0,0,315,316,
  	5,108,0,0,316,317,5,101,0,0,317,68,1,0,0,0,318,319,5,118,0,0,319,320,
  	5,111,0,0,320,321,5,105,0,0,321,322,5,100,0,0,322,70,1,0,0,0,323,327,
  	3,73,36,0,324,327,3,75,37,0,325,327,3,77,38,0,326,323,1,0,0,0,326,324,
  	1,0,0,0,326,325,1,0,0,0,327,72,1,0,0,0,328,329,5,112,0,0,329,330,5,117,
  	0,0,330,331,5,98,0,0,331,332,5,108,0,0,332,333,5,105,0,0,333,334,5,99,
  	0,0,334,74,1,0,0,0,335,336,5,112,0,0,336,337,5,114,0,0,337,338,5,105,
  	0,0,338,339,5,118,0,0,339,340,5,97,0,0,340,341,5,116,0,0,341,342,5,101,
  	0,0,342,76,1,0,0,0,343,344,5,112,0,0,344,345,5,114,0,0,345,346,5,111,
  	0,0,346,347,5,116,0,0,347,348,5,101,0,0,348,349,5,99,0,0,349,350,5,116,
  	0,0,350,351,5,101,0,0,351,352,5,100,0,0,352,78,1,0,0,0,353,356,3,81,40,
  	0,354,356,3,99,49,0,355,353,1,0,0,0,355,354,1,0,0,0,356,80,1,0,0,0,357,
  	366,3,83,41,0,358,366,3,85,42,0,359,366,3,87,43,0,360,366,3,89,44,0,361,
  	366,3,91,45,0,362,366,3,93,46,0,363,366,3,95,47,0,364,366,3,97,48,0,365,
  	357,1,0,0,0,365,358,1,0,0,0,365,359,1,0,0,0,365,360,1,0,0,0,365,361,1,
  	0,0,0,365,362,1,0,0,0,365,363,1,0,0,0,365,364,1,0,0,0,366,82,1,0,0,0,
  	367,368,5,101,0,0,368,369,5,97,0,0,369,370,5,120,0,0,370,84,1,0,0,0,371,
  	372,5,101,0,0,372,373,5,98,0,0,373,374,5,120,0,0,374,86,1,0,0,0,375,376,
  	5,101,0,0,376,377,5,99,0,0,377,378,5,120,0,0,378,88,1,0,0,0,379,380,5,
  	101,0,0,380,381,5,100,0,0,381,382,5,120,0,0,382,90,1,0,0,0,383,384,5,
  	101,0,0,384,385,5,115,0,0,385,386,5,105,0,0,386,92,1,0,0,0,387,388,5,
  	101,0,0,388,389,5,100,0,0,389,390,5,105,0,0,390,94,1,0,0,0,391,392,5,
  	101,0,0,392,393,5,115,0,0,393,394,5,112,0,0,394,96,1,0,0,0,395,396,5,
  	101,0,0,396,397,5,98,0,0,397,398,5,112,0,0,398,98,1,0,0,0,399,408,3,101,
  	50,0,400,408,3,103,51,0,401,408,3,105,52,0,402,408,3,107,53,0,403,408,
  	3,109,54,0,404,408,3,111,55,0,405,408,3,113,56,0,406,408,3,115,57,0,407,
  	399,1,0,0,0,407,400,1,0,0,0,407,401,1,0,0,0,407,402,1,0,0,0,407,403,1,
  	0,0,0,407,404,1,0,0,0,407,405,1,0,0,0,407,406,1,0,0,0,408,100,1,0,0,0,
  	409,410,5,120,0,0,410,411,5,109,0,0,411,412,5,109,0,0,412,413,5,48,0,
  	0,413,102,1,0,0,0,414,415,5,120,0,0,415,416,5,109,0,0,416,417,5,109,0,
  	0,417,418,5,49,0,0,418,104,1,0,0,0,419,420,5,120,0,0,420,421,5,109,0,
  	0,421,422,5,109,0,0,422,423,5,50,0,0,423,106,1,0,0,0,424,425,5,120,0,
  	0,425,426,5,109,0,0,426,427,5,109,0,0,427,428,5,51,0,0,428,108,1,0,0,
  	0,429,430,5,120,0,0,430,431,5,109,0,0,431,432,5,109,0,0,432,433,5,52,
  	0,0,433,110,1,0,0,0,434,435,5,120,0,0,435,436,5,109,0,0,436,437,5,109,
  	0,0,437,438,5,53,0,0,438,112,1,0,0,0,439,440,5,120,0,0,440,441,5,109,
  	0,0,441,442,5,109,0,0,442,443,5,54,0,0,443,114,1,0,0,0,444,445,5,120,
  	0,0,445,446,5,109,0,0,446,447,5,109,0,0,447,448,5,55,0,0,448,116,1,0,
  	0,0,449,454,3,119,59,0,450,454,3,121,60,0,451,454,3,123,61,0,452,454,
  	3,125,62,0,453,449,1,0,0,0,453,450,1,0,0,0,453,451,1,0,0,0,453,452,1,
  	0,0,0,454,118,1,0,0,0,455,456,5,95,0,0,456,457,5,95,0,0,457,458,5,115,
  	0,0,458,459,5,116,0,0,459,460,5,100,0,0,460,461,5,99,0,0,461,462,5,97,
  	0,0,462,463,5,108,0,0,463,464,5,108,0,0,464,120,1,0,0,0,465,466,5,95,
  	0,0,466,467,5,95,0,0,467,468,5,99,0,0,468,469,5,100,0,0,469,470,5,101,
  	0,0,470,471,5,99,0,0,471,472,5,108,0,0,472,122,1,0,0,0,473,474,5,95,0,
  	0,474,475,5,95,0,0,475,476,5,102,0,0,476,477,5,97,0,0,477,478,5,115,0,
  	0,478,479,5,116,0,0,479,480,5,99,0,0,480,481,5,97,0,0,481,482,5,108,0,
  	0,482,483,5,108,0,0,483,124,1,0,0,0,484,485,5,95,0,0,485,486,5,95,0,0,
  	486,487,5,116,0,0,487,488,5,104,0,0,488,489,5,105,0,0,489,490,5,115,0,
  	0,490,491,5,99,0,0,491,492,5,97,0,0,492,493,5,108,0,0,493,494,5,108,0,
  	0,494,126,1,0,0,0,495,497,3,1,0,0,496,498,5,46,0,0,497,496,1,0,0,0,497,
  	498,1,0,0,0,498,500,1,0,0,0,499,501,7,0,0,0,500,499,1,0,0,0,501,502,1,
  	0,0,0,502,500,1,0,0,0,502,503,1,0,0,0,503,504,1,0,0,0,504,505,3,1,0,0,
  	505,506,3,3,1,0,506,128,1,0,0,0,507,509,3,1,0,0,508,510,5,46,0,0,509,
  	508,1,0,0,0,509,510,1,0,0,0,510,512,1,0,0,0,511,513,7,1,0,0,512,511,1,
  	0,0,0,513,514,1,0,0,0,514,512,1,0,0,0,514,515,1,0,0,0,515,516,1,0,0,0,
  	516,517,3,1,0,0,517,518,3,3,1,0,518,130,1,0,0,0,519,523,7,2,0,0,520,522,
  	7,3,0,0,521,520,1,0,0,0,522,525,1,0,0,0,523,521,1,0,0,0,523,524,1,0,0,
  	0,524,132,1,0,0,0,525,523,1,0,0,0,526,529,3,135,67,0,527,529,3,137,68,
  	0,528,526,1,0,0,0,528,527,1,0,0,0,529,134,1,0,0,0,530,531,5,48,0,0,531,
  	532,5,120,0,0,532,534,1,0,0,0,533,535,7,4,0,0,534,533,1,0,0,0,535,536,
  	1,0,0,0,536,534,1,0,0,0,536,537,1,0,0,0,537,136,1,0,0,0,538,540,7,5,0,
  	0,539,538,1,0,0,0,540,541,1,0,0,0,541,539,1,0,0,0,541,542,1,0,0,0,542,
  	138,1,0,0,0,543,544,5,123,0,0,544,545,5,123,0,0,545,549,1,0,0,0,546,548,
  	9,0,0,0,547,546,1,0,0,0,548,551,1,0,0,0,549,550,1,0,0,0,549,547,1,0,0,
  	0,550,552,1,0,0,0,551,549,1,0,0,0,552,553,5,125,0,0,553,554,5,125,0,0,
  	554,140,1,0,0,0,555,557,7,6,0,0,556,555,1,0,0,0,557,558,1,0,0,0,558,556,
  	1,0,0,0,558,559,1,0,0,0,559,560,1,0,0,0,560,561,6,70,0,0,561,142,1,0,
  	0,0,562,564,5,13,0,0,563,565,5,10,0,0,564,563,1,0,0,0,564,565,1,0,0,0,
  	565,568,1,0,0,0,566,568,5,10,0,0,567,562,1,0,0,0,567,566,1,0,0,0,568,
  	569,1,0,0,0,569,570,6,71,0,0,570,144,1,0,0,0,571,572,5,47,0,0,572,573,
  	5,42,0,0,573,577,1,0,0,0,574,576,9,0,0,0,575,574,1,0,0,0,576,579,1,0,
  	0,0,577,578,1,0,0,0,577,575,1,0,0,0,578,580,1,0,0,0,579,577,1,0,0,0,580,
  	581,5,42,0,0,581,582,5,47,0,0,582,583,1,0,0,0,583,584,6,72,0,0,584,146,
  	1,0,0,0,585,586,5,47,0,0,586,587,5,47,0,0,587,591,1,0,0,0,588,590,8,7,
  	0,0,589,588,1,0,0,0,590,593,1,0,0,0,591,589,1,0,0,0,591,592,1,0,0,0,592,
  	594,1,0,0,0,593,591,1,0,0,0,594,595,6,73,0,0,595,148,1,0,0,0,596,597,
  	9,0,0,0,597,150,1,0,0,0,21,0,161,326,355,365,407,453,497,502,509,514,
  	523,528,536,541,549,558,564,567,577,591,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  zhllexerLexerStaticData = staticData.release();
}

}

ZHLLexer::ZHLLexer(CharStream *input) : Lexer(input) {
  ZHLLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *zhllexerLexerStaticData->atn, zhllexerLexerStaticData->decisionToDFA, zhllexerLexerStaticData->sharedContextCache);
}

ZHLLexer::~ZHLLexer() {
  delete _interpreter;
}

std::string ZHLLexer::getGrammarFileName() const {
  return "ZHLLexer.g4";
}

const std::vector<std::string>& ZHLLexer::getRuleNames() const {
  return zhllexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ZHLLexer::getChannelNames() const {
  return zhllexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ZHLLexer::getModeNames() const {
  return zhllexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ZHLLexer::getVocabulary() const {
  return zhllexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ZHLLexer::getSerializedATN() const {
  return zhllexerLexerStaticData->serializedATN;
}

const atn::ATN& ZHLLexer::getATN() const {
  return *zhllexerLexerStaticData->atn;
}




void ZHLLexer::initialize() {
  ::antlr4::internal::call_once(zhllexerLexerOnceFlag, zhllexerLexerInitialize);
}