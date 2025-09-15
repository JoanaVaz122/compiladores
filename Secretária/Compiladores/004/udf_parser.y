%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!
%}

%parse-param {std::shared_ptr<cdk::compiler> compiler}

%union {
  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;          /* integer value */
  double                d;          /* double value */
  std::string          *s;          /* symbol name or string literal */


  cdk::basic_node      *node;       /* node pointer */
  cdk::typed_node      *typenode;
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  cdk::basic_type      *types;
  
  
  udf::block_node      *block;
  udf::tensor_node     *tensor;      /* tensor nodes */
  std::vector<size_t>  *dims;
};


%token tPUBLIC tPRIVATE tFORWARD tAUTO_TYPE 
%token tSTRING_TYPE tINT_TYPE tREAL_TYPE tPTR_TYPE tTENSOR_TYPE tVOID_TYPE 
%token tIF tELIF tELSE
%token tFOR
%token tBREAK tCONTINUE tRETURN tOBJECTS
%token tTCAPACITY tTRANK tTDIMS tTDIM tTINDEX tTRESHAPE tTCONTRACTION  
%token tPRINT tPRINTLN tINPUT tSIZEOF
%token tUMINUS tIFX



%token <i> tINTEGER
%token <d> tREAL
%token <s> tSTRING tID
%token <expression> tNULLPTR


%type<node> stmt return iffalse
%type<sequence> file stmts opt_stmts 
%type<sequence> exprs opt_exprs
%type<expression> expr integer real opt_initializer tensor_literal
%type<lvalue> lvalue
%type<block> block

%type<node>     declaration  argdec  fordec  vardec fundec fundef
%type<sequence> declarations argdecs fordecs vardecs opt_vardecs 
%type<node>     opt_forinit
%type<dims>     tensor_dims

%type<s> string
%type<type> data_type


%nonassoc tIF tIFX
%nonassoc tELIF tELSE


%right tUMINUS
%right '='
%left tOR
%left tAND
%left tEQ tNE tGE tLE '>' '<'
%left '+' '-'
%left '*' '/' '%' 
%right tUNARY





%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file            : /* empty */  { compiler->ast($$ = new cdk::sequence_node(LINE)); }
                | declarations { compiler->ast($$ = $1); }
                ;


declarations    : declaration              { $$ = new cdk::sequence_node(LINE, $1); }
                | declarations declaration { $$ = new cdk::sequence_node(LINE, $2, $1); }
                ;

declaration     : vardec ';' { $$ = $1; }
                | fundec     { $$ = $1; }
                | fundef     { $$ = $1; }
                ;

/* Remove this duplicate/old stmt rule block to avoid conflicts. */

vardec          : tFORWARD data_type  tID                         { $$ = new udf::variable_declaration_node(LINE, tPUBLIC,  $2, *$3, nullptr); }
                | tPUBLIC  data_type  tID         opt_initializer { $$ = new udf::variable_declaration_node(LINE, tPUBLIC,  $2, *$3, $4); }
                |          data_type  tID         opt_initializer { $$ = new udf::variable_declaration_node(LINE, tPRIVATE, $1, *$2, $3); delete $2; }
                | tPUBLIC  tAUTO_TYPE tID '=' expr                { $$ = new udf::variable_declaration_node(LINE, tPUBLIC, nullptr, *$3, $5); }
                |          tAUTO_TYPE tID '=' expr                { $$ = new udf::variable_declaration_node(LINE, tPRIVATE, nullptr, *$2, $4); }         
                ;

vardecs         : vardec ';'         { $$ = new cdk::sequence_node(LINE, $1);     }
                | vardecs vardec ';' { $$ = new cdk::sequence_node(LINE, $2, $1); }
                ;
             
opt_vardecs     : /* empty */ { $$ = NULL; }
                | vardecs     { $$ = $1; }
                ;

data_type       : tSTRING_TYPE                     { $$ = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
                | tINT_TYPE                        { $$ = cdk::primitive_type::create(4, cdk::TYPE_INT);     }
                | tREAL_TYPE                       { $$ = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
                | tVOID_TYPE                       { $$ = cdk::primitive_type::create(0, cdk::TYPE_VOID);   }
                | tTENSOR_TYPE '<' tensor_dims '>' { $$ = cdk::tensor_type::create(*$3);}
                | tPTR_TYPE '<' data_type '>'      { $$ = cdk::reference_type::create(4, $3); }
                | tPTR_TYPE '<' tAUTO_TYPE '>'     { $$ = cdk::reference_type::create(4, nullptr); }
                ;

tensor_dims     : tINTEGER                          { $$ = new std::vector<size_t>({(size_t)$1}); }
                | tensor_dims ',' tINTEGER          { $$ = $1; $1->push_back((size_t)$3); }
                ;

opt_initializer : /* empty */         { $$ = nullptr; /* must be nullptr, not NIL */ }
                | '=' expr            { $$ = $2; }
                ;

fundec          :          data_type  tID '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPRIVATE, $1, *$2, $4); }
                | tFORWARD data_type  tID '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPUBLIC,  $2, *$3, $5); }
                | tPUBLIC  data_type  tID '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPUBLIC,  $2, *$3, $5); }
                |          tAUTO_TYPE tID '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPRIVATE, nullptr, *$2, $4); }
                | tFORWARD tAUTO_TYPE tID '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPUBLIC,  nullptr, *$3, $5); }
                | tPUBLIC  tAUTO_TYPE tID '(' argdecs ')' { $$ = new udf::function_declaration_node(LINE, tPUBLIC,  nullptr, *$3, $5); }
                ;

fundef          :         data_type  tID '(' argdecs ')' block { $$ = new udf::function_definition_node(LINE, tPRIVATE, $1, *$2, $4, $6); }
                | tPUBLIC data_type  tID '(' argdecs ')' block { $$ = new udf::function_definition_node(LINE, tPUBLIC,  $2, *$3, $5, $7); }
                |         tAUTO_TYPE tID '(' argdecs ')' block { $$ = new udf::function_definition_node(LINE, tPRIVATE, nullptr, *$2, $4, $6); }
                | tPUBLIC tAUTO_TYPE tID '(' argdecs ')' block { $$ = new udf::function_definition_node(LINE, tPUBLIC,  nullptr, *$3, $5, $7); }
                ;

argdecs         : /* empty */         { $$ = new cdk::sequence_node(LINE);  }
                |             argdec  { $$ = new cdk::sequence_node(LINE, $1);     }
                | argdecs ',' argdec  { $$ = new cdk::sequence_node(LINE, $3, $1); }
                ;

argdec          : data_type tID { $$ = new udf::variable_declaration_node(LINE, tPRIVATE, $1, *$2, nullptr); }
                ;

block           : '{' opt_vardecs opt_stmts '}' { $$ = new udf::block_node(LINE, $2, $3); }
                ;

fordec          : data_type tID '=' expr { $$ = new udf::variable_declaration_node(LINE, tPRIVATE,  $1, *$2, $4); }
                ;
              
fordecs         :             fordec  { $$ = new cdk::sequence_node(LINE, $1);     }
                | fordecs ',' fordec  { $$ = new cdk::sequence_node(LINE, $3, $1); }
                ;

opt_forinit     : /*empty*/           { $$ = new cdk::sequence_node(LINE); }
                | fordecs  { $$ = $1; }
                | tAUTO_TYPE tID '=' exprs {
                  $$ = new udf::variable_declaration_node(LINE, tPRIVATE, nullptr, *$2, new udf::tensor_node(LINE, nullptr, $4));
                  delete $2;
                }
                | exprs               { $$ = new udf::tensor_node(LINE, nullptr, $1); }
                ;

return          : tRETURN ';'         { $$ = new udf::return_node(LINE, nullptr); }
                | tRETURN expr ';'    { $$ = new udf::return_node(LINE, new udf::tensor_node(LINE, $2, nullptr)); }
                ;

stmts           : stmt                { $$ = new cdk::sequence_node(LINE, $1);     }
                | stmts stmt          { $$ = new cdk::sequence_node(LINE, $2, $1); }
                ;

opt_stmts       : /* empty */         { $$ = new cdk::sequence_node(LINE); }
                | stmts               { $$ = $1; }
                ;


stmt            : tIF '(' expr ')' stmt                                      { $$ = new udf::if_node(LINE, $3, $5); }
                | tIF '(' expr ')' stmt  iffalse                             { $$ = new udf::if_else_node(LINE, $3, $5, $6); }
                | tFOR '(' opt_forinit ';' opt_exprs ';' opt_exprs ')' stmt  { $$ = new udf::for_node(LINE, static_cast<cdk::sequence_node*>($3), static_cast<cdk::sequence_node*>($5), static_cast<cdk::sequence_node*>($7), $9); }
                | expr ';'                                                   { $$ = new udf::evaluation_node(LINE, $1); }
                | tPRINT   exprs ';'                                         { $$ = new udf::print_node(LINE, $2, false); }
                | tPRINTLN exprs ';'                                         { $$ = new udf::print_node(LINE, $2, true); }
                | tBREAK                                                     { $$ = new udf::break_node(LINE);  }
                | tCONTINUE                                                  { $$ = new udf::continue_node(LINE); }
                | return                                                     { $$ = $1; }
                | block                                                      { $$ = $1; }
                
iffalse         : tELSE stmt                        { $$ = $2; }
                | tELIF '(' expr ')' stmt iffalse   { $$ = new udf::if_else_node(LINE, $3, $5, $6); }
                ;


lvalue          :  tID                                      { $$ = new cdk::variable_node(LINE, *$1); delete $1; }
                | lvalue             '[' expr ']'           { $$ = new udf::left_index_node(LINE, new cdk::rvalue_node(LINE, $1), $3); }
                | '(' expr ')' '[' expr ']'                 { $$ = new udf::left_index_node(LINE, $2, $5); }
                | tID '('opt_exprs')' '[' expr ']'          { $$ = new udf::left_index_node(LINE, new udf::function_call_node(LINE, *$1, $3), $6); }
                | expr tTINDEX '(' exprs ')'                      { $$ = new udf::tensor_index_node(LINE, $1, $4); }
                ;

expr            : integer                             { $$ = $1; }
                | real                                { $$ = $1; }
                | string                              { $$ = new cdk::string_node(LINE, $1); }
                | tNULLPTR                            { $$ = new udf::nullptr_node(LINE); }
                | tTENSOR_TYPE '<' exprs '>'          { $$ = new udf::tensor_node(LINE,nullptr,$3);}
                | tensor_literal                      { $$ = $1;}
                | expr '.' tTCAPACITY                 { $$ = new udf::tensor_capacity_node(LINE,$1);}
                | expr '.' tTRANK                     { $$ = new udf::tensor_rank_node(LINE,$1);}
                | expr '.' tTDIM '('expr')'           { $$ = new udf::tensor_dim_node(LINE,$1, $5);}
                | expr '.' tTRESHAPE  '('exprs')'     { $$ = new udf::tensor_reshape_node(LINE,$1,$5);}
                | expr tTCONTRACTION expr             { $$ = new udf::tensor_contraction_node(LINE,$1,$3);}

                /* LEFT VALUES */
                | lvalue                        { $$ = new cdk::rvalue_node(LINE, $1); }
                /* ASSIGNMENTS */
                | lvalue '=' expr               { $$ = new cdk::assignment_node(LINE, $1, $3); }
                /* ARITHMETIC EXPRESSIONS */
                | expr '+' expr                 { $$ = new cdk::add_node(LINE, $1, $3); }
                | expr '-' expr                 { $$ = new cdk::sub_node(LINE, $1, $3); }
                | expr '*' expr                 { $$ = new cdk::mul_node(LINE, $1, $3); }
                | expr '/' expr                 { $$ = new cdk::div_node(LINE, $1, $3); }
                | expr '%' expr                 { $$ = new cdk::mod_node(LINE, $1, $3); }
                /* LOGICAL EXPRESSIONS */
                | expr  '<' expr                { $$ = new cdk::lt_node(LINE, $1, $3); }
                | expr tLE  expr                { $$ = new cdk::le_node(LINE, $1, $3); }
                | expr tEQ  expr                { $$ = new cdk::eq_node(LINE, $1, $3); }
                | expr tGE  expr                { $$ = new cdk::ge_node(LINE, $1, $3); }
                | expr  '>' expr                { $$ = new cdk::gt_node(LINE, $1, $3); }
                | expr tNE  expr                { $$ = new cdk::ne_node(LINE, $1, $3); }
                /* LOGICAL EXPRESSIONS */
                | expr tAND  expr               { $$ = new cdk::and_node(LINE, $1, $3); }
                | expr tOR   expr               { $$ = new cdk::or_node (LINE, $1, $3); }
                /* UNARY EXPRESSION */
                | '-' expr %prec tUMINUS        { $$ = new cdk::unary_minus_node(LINE, $2); }
                | '+' expr %prec tUMINUS        { $$ = $2; }
                | '~' expr %prec tUNARY                     { $$ = new cdk::not_node(LINE, $2); }
                /* OTHER EXPRESSION */
                | tINPUT                        { $$ = new udf::input_node(LINE); }
                /* OTHER EXPRESSION */
                | tOBJECTS '(' expr ')'         { $$ = new udf::object_node(LINE, $3); }
                | tID '(' opt_exprs ')'         { $$ = new udf::function_call_node(LINE, *$1, $3); delete $1; }
                | tSIZEOF '(' exprs ')'         { $$ = new udf::sizeof_node(LINE, new udf::tensor_node(LINE, nullptr, $3)); }
                /* OTHER EXPRESSION */
                | '(' expr ')'                  { $$ = $2; }
                | '[' expr ']'                  { $$ = new udf::tensor_node(LINE, $2, nullptr); }
                | lvalue '?'                    { $$ = new udf::address_of_node(LINE, $1); }
                ;



exprs           : expr                      { $$ = new cdk::sequence_node(LINE, $1);     }
                | exprs ',' expr            { $$ = new cdk::sequence_node(LINE, $3, $1); }
                ;

opt_exprs       : /* empty */               { $$ = new cdk::sequence_node(LINE); }
                | exprs                     { $$ = $1; }
                ;

 
tensor_literal  : '[' exprs ']' { $$ = new udf::tensor_node(LINE,nullptr,$2);}
                ;


integer         : tINTEGER                      { $$ = new cdk::integer_node(LINE, $1); }
real            : tREAL                         { $$ = new cdk::double_node(LINE, $1); };
string          : tSTRING                       { $$ = $1; }
                | string tSTRING                { $$ = $1; $$->append(*$2); delete $2; }
                ;

