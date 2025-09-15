%option c++ prefix="udf_scanner_" outfile="udf_scanner.cpp"
%option stack noyywrap yylineno 8bit debug
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "udf_parser.tab.h"

static std::vector<int> deferred; 

static std::ostringstream strlit;

// don't change this
#define yyerror LexerError
%}

SPACE     ([ \t\r]|\n)
INT       [[:digit:]]+

LETTER  [A-Za-z_]
IDENTIFIER   {LETTER}({LETTER}|[[:digit:]])*


%x X_COMMENT
%x X_STRING  X_BACKSLASH   X_CHAR    X_CHAR_END
%x X_OCTAL   X_HEXADECIMAL X_HEX_INT X_BIN_INT

%%
  yydebug=1; set_debug(1);





"=="                   return tEQ;
"!="                   return tNE;
"<="                   return tLE;
">="                   return tGE;
"&&"                   return tAND;
"||"                   return tOR;

"if"                   return tIF; 
"elif"                 return tELIF;
"else"                 return tELSE; 
"for"                  return tFOR;
"break"                return tBREAK;
"continue"             return tCONTINUE;
"return"               return tRETURN;
"write"                return tPRINT;
"writeln"              return tPRINTLN;

"int"                  return tINT_TYPE;
"real"                 return tREAL_TYPE;
"ptr"                  return tPTR_TYPE;
"string"               return tSTRING_TYPE;
"tensor"               return tTENSOR_TYPE;
"void"                 return tVOID_TYPE;
"auto"                 return tAUTO_TYPE;

"forward"              return tFORWARD;
"public"               return tPUBLIC;

"input"                return tINPUT;
"nullptr"              return tNULLPTR;
"objects"              return tOBJECTS;
"sizeof"               return tSIZEOF;

"capacity"             return tTCAPACITY;
"rank"                 return tTRANK;
"dims"                 return tTDIMS;
"dim"                  return tTDIM;
"@"                    return tTINDEX;
"reshape"              return tTRESHAPE;
"**"                   return tTCONTRACTION;



[A-Za-z][A-Za-z0-9_]*  yylval.s = new std::string(yytext); return tID;

"//".*$                /* match the whole line (it is ignored) */
"/*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"*/"        yy_pop_state();
<X_COMMENT>.|"\n"      ;  /* ignore inside comments */



"\""                           yy_push_state(X_STRING);
<X_STRING>\\                   yy_push_state(X_BACKSLASH);
<X_STRING>"\""                 {
                                 yylval.s = new std::string(strlit.str());
                                 strlit.str("");
                                 yy_pop_state();
                                 return tSTRING;
                               }
<X_STRING>.                    strlit << *yytext;

<X_BACKSLASH>n                 strlit << '\n'; yy_pop_state();
<X_BACKSLASH>r                 strlit << '\r'; yy_pop_state();
<X_BACKSLASH>t                 strlit << '\t'; yy_pop_state();
<X_BACKSLASH>\\                strlit << '\\'; yy_pop_state();

<X_BACKSLASH>[[:xdigit:]]{1,2} {
                                 strlit << (char)(unsigned char)strtoul(yytext, NULL, 16);
                                 yy_pop_state();
                               }
<X_BACKSLASH>.                 strlit << *yytext; yy_pop_state();


"0x"                          yy_push_state(X_HEX_INT);
<X_HEX_INT>[[:xdigit:]]+      { yylval.i = strtoul(yytext, NULL, 16); yy_pop_state(); return tINTEGER; }
<X_HEX_INT>.|\n               std::cerr << "WARNING: line " << lineno() << ": bad hexadecimal data!" << std::endl; exit(1);

[0-9]+                 yylval.i = strtol(yytext, nullptr, 10); return tINTEGER;

([0-9]*\.[0-9]+|[0-9]+\.[0-9]*)([eE][-+]?[0-9]+)? { yylval.d = strtod(yytext, NULL); return tREAL; }


[-+*/%~<>=@?()\[\]{},;:.!]   return *yytext;


[ \t\n]+               ; /* ignore whitespace */

.                      yyerror("Unknown character");

%%