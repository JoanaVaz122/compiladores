/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "udf_parser.y"

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

#line 85 "udf_parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "udf_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tPUBLIC = 3,                    /* tPUBLIC  */
  YYSYMBOL_tPRIVATE = 4,                   /* tPRIVATE  */
  YYSYMBOL_tFORWARD = 5,                   /* tFORWARD  */
  YYSYMBOL_tAUTO_TYPE = 6,                 /* tAUTO_TYPE  */
  YYSYMBOL_tSTRING_TYPE = 7,               /* tSTRING_TYPE  */
  YYSYMBOL_tINT_TYPE = 8,                  /* tINT_TYPE  */
  YYSYMBOL_tREAL_TYPE = 9,                 /* tREAL_TYPE  */
  YYSYMBOL_tPTR_TYPE = 10,                 /* tPTR_TYPE  */
  YYSYMBOL_tTENSOR_TYPE = 11,              /* tTENSOR_TYPE  */
  YYSYMBOL_tVOID_TYPE = 12,                /* tVOID_TYPE  */
  YYSYMBOL_tIF = 13,                       /* tIF  */
  YYSYMBOL_tELIF = 14,                     /* tELIF  */
  YYSYMBOL_tELSE = 15,                     /* tELSE  */
  YYSYMBOL_tFOR = 16,                      /* tFOR  */
  YYSYMBOL_tBREAK = 17,                    /* tBREAK  */
  YYSYMBOL_tCONTINUE = 18,                 /* tCONTINUE  */
  YYSYMBOL_tRETURN = 19,                   /* tRETURN  */
  YYSYMBOL_tOBJECTS = 20,                  /* tOBJECTS  */
  YYSYMBOL_tTCAPACITY = 21,                /* tTCAPACITY  */
  YYSYMBOL_tTRANK = 22,                    /* tTRANK  */
  YYSYMBOL_tTDIMS = 23,                    /* tTDIMS  */
  YYSYMBOL_tTDIM = 24,                     /* tTDIM  */
  YYSYMBOL_tTINDEX = 25,                   /* tTINDEX  */
  YYSYMBOL_tTRESHAPE = 26,                 /* tTRESHAPE  */
  YYSYMBOL_tTCONTRACTION = 27,             /* tTCONTRACTION  */
  YYSYMBOL_tPRINT = 28,                    /* tPRINT  */
  YYSYMBOL_tPRINTLN = 29,                  /* tPRINTLN  */
  YYSYMBOL_tINPUT = 30,                    /* tINPUT  */
  YYSYMBOL_tSIZEOF = 31,                   /* tSIZEOF  */
  YYSYMBOL_tUMINUS = 32,                   /* tUMINUS  */
  YYSYMBOL_tIFX = 33,                      /* tIFX  */
  YYSYMBOL_tINTEGER = 34,                  /* tINTEGER  */
  YYSYMBOL_tREAL = 35,                     /* tREAL  */
  YYSYMBOL_tSTRING = 36,                   /* tSTRING  */
  YYSYMBOL_tID = 37,                       /* tID  */
  YYSYMBOL_tNULLPTR = 38,                  /* tNULLPTR  */
  YYSYMBOL_39_ = 39,                       /* '='  */
  YYSYMBOL_tOR = 40,                       /* tOR  */
  YYSYMBOL_tAND = 41,                      /* tAND  */
  YYSYMBOL_tEQ = 42,                       /* tEQ  */
  YYSYMBOL_tNE = 43,                       /* tNE  */
  YYSYMBOL_tGE = 44,                       /* tGE  */
  YYSYMBOL_tLE = 45,                       /* tLE  */
  YYSYMBOL_46_ = 46,                       /* '>'  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_48_ = 48,                       /* '+'  */
  YYSYMBOL_49_ = 49,                       /* '-'  */
  YYSYMBOL_50_ = 50,                       /* '*'  */
  YYSYMBOL_51_ = 51,                       /* '/'  */
  YYSYMBOL_52_ = 52,                       /* '%'  */
  YYSYMBOL_tUNARY = 53,                    /* tUNARY  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* ','  */
  YYSYMBOL_56_ = 56,                       /* '('  */
  YYSYMBOL_57_ = 57,                       /* ')'  */
  YYSYMBOL_58_ = 58,                       /* '{'  */
  YYSYMBOL_59_ = 59,                       /* '}'  */
  YYSYMBOL_60_ = 60,                       /* '['  */
  YYSYMBOL_61_ = 61,                       /* ']'  */
  YYSYMBOL_62_ = 62,                       /* '.'  */
  YYSYMBOL_63_ = 63,                       /* '~'  */
  YYSYMBOL_64_ = 64,                       /* '?'  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_file = 66,                      /* file  */
  YYSYMBOL_declarations = 67,              /* declarations  */
  YYSYMBOL_declaration = 68,               /* declaration  */
  YYSYMBOL_vardec = 69,                    /* vardec  */
  YYSYMBOL_vardecs = 70,                   /* vardecs  */
  YYSYMBOL_opt_vardecs = 71,               /* opt_vardecs  */
  YYSYMBOL_data_type = 72,                 /* data_type  */
  YYSYMBOL_tensor_dims = 73,               /* tensor_dims  */
  YYSYMBOL_opt_initializer = 74,           /* opt_initializer  */
  YYSYMBOL_fundec = 75,                    /* fundec  */
  YYSYMBOL_fundef = 76,                    /* fundef  */
  YYSYMBOL_argdecs = 77,                   /* argdecs  */
  YYSYMBOL_argdec = 78,                    /* argdec  */
  YYSYMBOL_block = 79,                     /* block  */
  YYSYMBOL_fordec = 80,                    /* fordec  */
  YYSYMBOL_fordecs = 81,                   /* fordecs  */
  YYSYMBOL_opt_forinit = 82,               /* opt_forinit  */
  YYSYMBOL_return = 83,                    /* return  */
  YYSYMBOL_stmts = 84,                     /* stmts  */
  YYSYMBOL_opt_stmts = 85,                 /* opt_stmts  */
  YYSYMBOL_stmt = 86,                      /* stmt  */
  YYSYMBOL_iffalse = 87,                   /* iffalse  */
  YYSYMBOL_lvalue = 88,                    /* lvalue  */
  YYSYMBOL_expr = 89,                      /* expr  */
  YYSYMBOL_exprs = 90,                     /* exprs  */
  YYSYMBOL_opt_exprs = 91,                 /* opt_exprs  */
  YYSYMBOL_tensor_literal = 92,            /* tensor_literal  */
  YYSYMBOL_integer = 93,                   /* integer  */
  YYSYMBOL_real = 94,                      /* real  */
  YYSYMBOL_string = 95                     /* string  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 96 "udf_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 218 "udf_parser.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   760

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  255

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    52,     2,     2,
      56,    57,    50,    48,    55,    49,    62,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
      47,    39,    46,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,    63,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    40,    41,    42,    43,    44,    45,
      53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   101,   101,   102,   106,   107,   110,   111,   112,   117,
     118,   119,   120,   121,   124,   125,   128,   129,   132,   133,
     134,   135,   136,   137,   138,   141,   142,   145,   146,   149,
     150,   151,   152,   153,   154,   157,   158,   159,   160,   163,
     164,   165,   168,   171,   174,   177,   178,   181,   182,   183,
     187,   190,   191,   194,   195,   198,   199,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   214,   215,   219,
     220,   221,   222,   223,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   239,   241,   243,   244,   245,
     246,   247,   249,   250,   251,   252,   253,   254,   256,   257,
     259,   260,   261,   263,   265,   266,   267,   269,   270,   271,
     276,   277,   280,   281,   285,   289,   290,   291,   292
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tPUBLIC", "tPRIVATE",
  "tFORWARD", "tAUTO_TYPE", "tSTRING_TYPE", "tINT_TYPE", "tREAL_TYPE",
  "tPTR_TYPE", "tTENSOR_TYPE", "tVOID_TYPE", "tIF", "tELIF", "tELSE",
  "tFOR", "tBREAK", "tCONTINUE", "tRETURN", "tOBJECTS", "tTCAPACITY",
  "tTRANK", "tTDIMS", "tTDIM", "tTINDEX", "tTRESHAPE", "tTCONTRACTION",
  "tPRINT", "tPRINTLN", "tINPUT", "tSIZEOF", "tUMINUS", "tIFX", "tINTEGER",
  "tREAL", "tSTRING", "tID", "tNULLPTR", "'='", "tOR", "tAND", "tEQ",
  "tNE", "tGE", "tLE", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "tUNARY", "';'", "','", "'('", "')'", "'{'", "'}'", "'['", "']'", "'.'",
  "'~'", "'?'", "$accept", "file", "declarations", "declaration", "vardec",
  "vardecs", "opt_vardecs", "data_type", "tensor_dims", "opt_initializer",
  "fundec", "fundef", "argdecs", "argdec", "block", "fordec", "fordecs",
  "opt_forinit", "return", "stmts", "opt_stmts", "stmt", "iffalse",
  "lvalue", "expr", "exprs", "opt_exprs", "tensor_literal", "integer",
  "real", "string", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-219)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-26)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     148,   174,   187,   -29,  -219,  -219,  -219,   -14,   -12,  -219,
      37,   148,  -219,    -1,    20,  -219,  -219,    29,    44,    67,
      79,   -32,   195,    59,  -219,  -219,  -219,   -30,   -22,   -20,
      65,   113,   270,   119,   117,   128,  -219,     4,   270,   119,
    -219,   270,   119,   119,  -219,   119,   119,   129,   121,  -219,
     158,  -219,  -219,  -219,   159,  -219,   270,   270,   270,   270,
     270,    55,   634,  -219,  -219,  -219,   175,   179,    35,  -219,
    -219,  -219,  -219,   183,   634,    48,   634,    88,   107,   115,
     118,   270,   270,   270,   270,   634,   634,   326,   354,    36,
     -13,   270,   270,  -219,   164,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,    96,
    -219,  -219,   119,   171,  -219,   171,   171,   171,  -219,  -219,
     634,     5,   382,   133,   176,   173,   180,  -219,   270,  -219,
     634,   410,   270,   634,   662,   690,    -7,    -7,    -7,    -7,
      -7,    -7,    -4,    -4,   -13,   -13,   -13,  -219,  -219,   177,
     178,  -219,   748,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
     181,   270,   634,  -219,   134,   270,   270,   334,   119,   198,
     193,   748,   208,   211,   270,   438,  -219,   466,   155,   212,
     214,   215,   216,  -219,   199,   202,   204,  -219,  -219,   239,
     270,   270,  -219,  -219,   208,   203,  -219,   494,   222,   522,
    -219,  -219,  -219,   224,   222,  -219,  -219,   270,    76,  -219,
     550,    54,    80,  -219,  -219,  -219,  -219,   578,   217,   218,
     230,  -219,   223,   225,   176,  -219,  -219,  -219,   208,   233,
     301,   241,   119,   270,   135,   270,    10,   270,  -219,   228,
     227,   208,  -219,   176,   634,   270,   270,  -219,   229,   606,
     208,   208,  -219,   135,  -219
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,    18,    19,    20,     0,     0,    21,
       0,     3,     4,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     1,     5,     6,    27,     0,    27,
       0,     9,     0,    39,     0,     0,    25,     0,     0,    39,
      11,     0,    39,    39,    10,    39,    39,     0,     0,   103,
       0,   115,   116,   117,    69,    77,     0,     0,     0,     0,
       0,    85,    13,    79,    74,    75,    76,     0,     0,    40,
      24,    23,    22,     0,    28,     0,    12,     0,     0,     0,
       0,     0,     0,     0,   112,   101,   100,     0,   110,     0,
     102,     0,     0,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,    42,     0,    32,    26,    29,    34,    31,    33,    30,
     110,     0,     0,     0,   113,     0,   107,   108,     0,   114,
      86,     0,     0,    84,    99,    98,    94,    97,    95,    93,
      96,    92,    87,    88,    89,    90,    91,    80,    81,     0,
       0,    41,    16,    37,    35,    38,    36,    78,   104,   106,
     105,     0,   111,    70,     0,     0,     0,     0,     0,     0,
       0,    17,    55,     0,     0,     0,    73,     0,     0,     0,
       0,     0,     0,    14,     0,     0,     0,    63,    64,     0,
       0,     0,    66,    65,    56,     0,    53,     0,    27,     0,
      71,    82,    83,     0,    27,     9,    15,     0,    47,    51,
       0,     0,     0,    54,    43,    60,    72,     0,     0,     0,
       0,    45,    48,     0,    50,    52,    61,    62,     0,     0,
       0,     0,     0,   112,    57,     0,   115,     0,    46,     0,
       0,     0,    58,    49,    44,   112,     0,    67,     0,     0,
       0,     0,    59,     0,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,  -219,   273,  -146,  -219,  -219,     0,  -219,   -26,
    -219,  -219,    56,   182,    25,    53,  -219,  -219,  -219,  -219,
    -219,  -189,    38,  -219,   -28,   -43,  -218,  -219,  -219,  -219,
    -219
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    12,    13,   171,   172,    67,    37,    40,
      15,    16,    68,    69,   192,   221,   222,   223,   193,   194,
     195,   196,   242,    61,   120,   124,   125,    63,    64,    65,
      66
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    18,    20,    44,    62,   213,   170,    32,    21,    38,
      74,    14,    94,    76,    95,   239,    89,    41,    94,    38,
      95,    94,    35,    95,    33,   184,    39,   248,    85,    86,
      87,    88,    90,    22,    42,    23,    43,    24,   121,   234,
     123,   104,   105,   106,   107,   108,   106,   107,   108,   109,
      72,   157,   247,    26,   122,   109,   -25,    27,   109,    73,
     128,   252,   253,   130,   131,   -25,    28,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    29,   218,     4,     5,     6,     7,   219,     9,   164,
     112,   128,   113,    36,    91,    75,    48,   129,    77,    78,
     162,    79,    80,   112,    30,   115,    49,    50,   226,   128,
      51,    52,    53,    54,    55,    92,    31,   147,   148,    93,
     149,    45,   150,   178,    56,    57,     4,     5,     6,     7,
       8,     9,    58,   175,   227,   128,    59,   177,   153,    60,
     154,   155,   156,   112,   197,   116,   199,   211,   212,   240,
     241,     1,   173,     2,     3,     4,     5,     6,     7,     8,
       9,   210,   112,    70,   117,   224,   197,   180,   181,    46,
     112,   173,   118,   112,    71,   119,    81,    82,    44,   217,
      17,     4,     5,     6,     7,     8,     9,   121,   128,   128,
     159,   176,   243,    19,     4,     5,     6,     7,     8,     9,
     197,    34,     4,     5,     6,     7,     8,     9,   220,   244,
     128,   110,   202,   197,    83,    84,   111,   114,   249,    47,
     132,   185,   197,   197,   186,   187,   188,   189,    48,   152,
     160,   128,   220,   165,   166,   182,   190,   191,    49,    50,
     161,   174,    51,    52,    53,    54,    55,   183,   198,   203,
      47,   204,   205,   206,   229,    32,    56,    57,   207,    48,
     208,    38,   214,    41,    58,   230,   152,   231,    59,    49,
      50,    60,   235,    51,    52,    53,    54,    55,   232,   233,
     237,    47,   245,   246,    25,   238,   250,    56,    57,     0,
      48,   254,     0,   209,   151,    58,     0,     0,     0,    59,
      49,    50,    60,     0,    51,    52,    53,    54,    55,     0,
       0,     0,    47,     0,     0,     0,     0,     0,    56,    57,
       0,    48,     0,     0,     0,     0,    58,     0,     0,     0,
      59,    49,    50,    60,     0,   236,    52,    53,    54,    55,
     179,     4,     5,     6,     7,     8,     9,     0,     0,    56,
      57,    94,     0,    95,     0,     0,     0,    58,     0,     0,
       0,    59,     0,     0,    60,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    94,
       0,    95,     0,   126,     0,     0,     0,     0,   109,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    94,     0,    95,
       0,     0,     0,     0,     0,   127,   109,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    94,     0,    95,     0,   158,
       0,     0,     0,     0,   109,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    94,     0,    95,     0,     0,     0,     0,
       0,   163,   109,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    94,     0,    95,     0,     0,     0,     0,     0,   200,
     109,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    94,
       0,    95,     0,   201,     0,     0,     0,     0,   109,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    94,   215,    95,
       0,     0,     0,     0,     0,     0,   109,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    94,     0,    95,     0,     0,
       0,     0,     0,   216,   109,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    94,   225,    95,     0,     0,     0,     0,
       0,     0,   109,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    94,     0,    95,     0,   228,     0,     0,     0,     0,
     109,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    94,
       0,    95,     0,   251,     0,     0,     0,     0,   109,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    94,     0,    95,
       0,     0,     0,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    94,     0,    95,     0,     0,
       0,     0,     0,     0,   109,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   109,   168,   169,     4,     5,     6,     7,     8,
       9
};

static const yytype_int16 yycheck[] =
{
       0,     1,     2,    29,    32,   194,   152,    39,    37,    39,
      38,    11,    25,    41,    27,   233,    59,    39,    25,    39,
      27,    25,    22,    27,    56,   171,    56,   245,    56,    57,
      58,    59,    60,    47,    56,    47,    56,     0,    81,   228,
      83,    48,    49,    50,    51,    52,    50,    51,    52,    62,
      46,    46,   241,    54,    82,    62,    46,    37,    62,    55,
      55,   250,   251,    91,    92,    55,    37,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    37,     6,     7,     8,     9,    10,    11,    12,   132,
      55,    55,    57,    34,    39,    39,    20,    61,    42,    43,
     128,    45,    46,    55,    37,    57,    30,    31,    54,    55,
      34,    35,    36,    37,    38,    60,    37,    21,    22,    64,
      24,    56,    26,   166,    48,    49,     7,     8,     9,    10,
      11,    12,    56,   161,    54,    55,    60,   165,   113,    63,
     115,   116,   117,    55,   172,    57,   174,   190,   191,    14,
      15,     3,   152,     5,     6,     7,     8,     9,    10,    11,
      12,   189,    55,    46,    57,   208,   194,   167,   168,    56,
      55,   171,    57,    55,    46,    57,    47,    56,   204,   207,
       6,     7,     8,     9,    10,    11,    12,   230,    55,    55,
      57,    57,   235,     6,     7,     8,     9,    10,    11,    12,
     228,     6,     7,     8,     9,    10,    11,    12,   208,   237,
      55,    36,    57,   241,    56,    56,    37,    34,   246,    11,
      56,    13,   250,   251,    16,    17,    18,    19,    20,    58,
      57,    55,   232,    56,    56,    37,    28,    29,    30,    31,
      60,    60,    34,    35,    36,    37,    38,    54,    37,    37,
      11,    37,    37,    54,    37,    39,    48,    49,    56,    20,
      56,    39,    59,    39,    56,    47,    58,    37,    60,    30,
      31,    63,    39,    34,    35,    36,    37,    38,    55,    54,
      39,    11,    54,    56,    11,   232,    57,    48,    49,    -1,
      20,   253,    -1,    54,   112,    56,    -1,    -1,    -1,    60,
      30,    31,    63,    -1,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    48,    49,
      -1,    20,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      60,    30,    31,    63,    -1,    34,    35,    36,    37,    38,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    48,
      49,    25,    -1,    27,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    60,    -1,    -1,    63,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    25,
      -1,    27,    -1,    57,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    25,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    25,    -1,    27,    -1,    57,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    25,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    25,
      -1,    27,    -1,    57,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    25,    54,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    25,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    25,    54,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    25,    -1,    27,    -1,    57,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    25,
      -1,    27,    -1,    57,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    25,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    25,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    62,     5,     6,     7,     8,     9,    10,    11,
      12
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    11,    12,
      66,    67,    68,    69,    72,    75,    76,     6,    72,     6,
      72,    37,    47,    47,     0,    68,    54,    37,    37,    37,
      37,    37,    39,    56,     6,    72,    34,    73,    39,    56,
      74,    39,    56,    56,    74,    56,    56,    11,    20,    30,
      31,    34,    35,    36,    37,    38,    48,    49,    56,    60,
      63,    88,    89,    92,    93,    94,    95,    72,    77,    78,
      46,    46,    46,    55,    89,    77,    89,    77,    77,    77,
      77,    47,    56,    56,    56,    89,    89,    89,    89,    90,
      89,    39,    60,    64,    25,    27,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    62,
      36,    37,    55,    57,    34,    57,    57,    57,    57,    57,
      89,    90,    89,    90,    90,    91,    57,    61,    55,    61,
      89,    89,    56,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    21,    22,    24,
      26,    78,    58,    79,    79,    79,    79,    46,    57,    57,
      57,    60,    89,    61,    90,    56,    56,     3,     5,     6,
      69,    70,    71,    72,    60,    89,    57,    89,    90,     6,
      72,    72,    37,    54,    69,    13,    16,    17,    18,    19,
      28,    29,    79,    83,    84,    85,    86,    89,    37,    89,
      61,    57,    57,    37,    37,    37,    54,    56,    56,    54,
      89,    90,    90,    86,    59,    54,    61,    89,     6,    11,
      72,    80,    81,    82,    90,    54,    54,    54,    57,    37,
      47,    37,    55,    54,    86,    39,    34,    39,    80,    91,
      14,    15,    87,    90,    89,    54,    56,    86,    91,    89,
      57,    57,    86,    86,    87
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    68,    68,    68,    69,
      69,    69,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    76,    77,
      77,    77,    78,    79,    80,    81,    81,    82,    82,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    87,    87,    88,
      88,    88,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      90,    90,    91,    91,    92,    93,    94,    95,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     2,     1,     1,     3,
       4,     3,     5,     4,     2,     3,     0,     1,     1,     1,
       1,     1,     4,     4,     4,     1,     3,     0,     2,     5,
       6,     6,     5,     6,     6,     6,     7,     6,     7,     0,
       1,     3,     2,     4,     4,     1,     3,     0,     1,     4,
       1,     2,     3,     1,     2,     0,     1,     5,     6,     9,
       2,     3,     3,     1,     1,     1,     1,     2,     6,     1,
       4,     6,     7,     5,     1,     1,     1,     1,     4,     1,
       3,     3,     6,     6,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     1,     4,     4,     4,     3,     3,     2,
       1,     3,     0,     1,     3,     1,     1,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (compiler, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (compiler);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, compiler);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, std::shared_ptr<cdk::compiler> compiler)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YY_USE (yyvaluep);
  YY_USE (compiler);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (std::shared_ptr<cdk::compiler> compiler)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* file: %empty  */
#line 101 "udf_parser.y"
                               { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE)); }
#line 1445 "udf_parser.tab.c"
    break;

  case 3: /* file: declarations  */
#line 102 "udf_parser.y"
                               { compiler->ast((yyval.sequence) = (yyvsp[0].sequence)); }
#line 1451 "udf_parser.tab.c"
    break;

  case 4: /* declarations: declaration  */
#line 106 "udf_parser.y"
                                           { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1457 "udf_parser.tab.c"
    break;

  case 5: /* declarations: declarations declaration  */
#line 107 "udf_parser.y"
                                           { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1463 "udf_parser.tab.c"
    break;

  case 6: /* declaration: vardec ';'  */
#line 110 "udf_parser.y"
                             { (yyval.node) = (yyvsp[-1].node); }
#line 1469 "udf_parser.tab.c"
    break;

  case 7: /* declaration: fundec  */
#line 111 "udf_parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1475 "udf_parser.tab.c"
    break;

  case 8: /* declaration: fundef  */
#line 112 "udf_parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1481 "udf_parser.tab.c"
    break;

  case 9: /* vardec: tFORWARD data_type tID  */
#line 117 "udf_parser.y"
                                                                  { (yyval.node) = new udf::variable_declaration_node(LINE, tPUBLIC,  (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1487 "udf_parser.tab.c"
    break;

  case 10: /* vardec: tPUBLIC data_type tID opt_initializer  */
#line 118 "udf_parser.y"
                                                                  { (yyval.node) = new udf::variable_declaration_node(LINE, tPUBLIC,  (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1493 "udf_parser.tab.c"
    break;

  case 11: /* vardec: data_type tID opt_initializer  */
#line 119 "udf_parser.y"
                                                                  { (yyval.node) = new udf::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression)); delete (yyvsp[-1].s); }
#line 1499 "udf_parser.tab.c"
    break;

  case 12: /* vardec: tPUBLIC tAUTO_TYPE tID '=' expr  */
#line 120 "udf_parser.y"
                                                                  { (yyval.node) = new udf::variable_declaration_node(LINE, tPUBLIC, nullptr, *(yyvsp[-2].s), (yyvsp[0].expression)); }
#line 1505 "udf_parser.tab.c"
    break;

  case 13: /* vardec: tAUTO_TYPE tID '=' expr  */
#line 121 "udf_parser.y"
                                                                  { (yyval.node) = new udf::variable_declaration_node(LINE, tPRIVATE, nullptr, *(yyvsp[-2].s), (yyvsp[0].expression)); }
#line 1511 "udf_parser.tab.c"
    break;

  case 14: /* vardecs: vardec ';'  */
#line 124 "udf_parser.y"
                                     { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node));     }
#line 1517 "udf_parser.tab.c"
    break;

  case 15: /* vardecs: vardecs vardec ';'  */
#line 125 "udf_parser.y"
                                     { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[-2].sequence)); }
#line 1523 "udf_parser.tab.c"
    break;

  case 16: /* opt_vardecs: %empty  */
#line 128 "udf_parser.y"
                              { (yyval.sequence) = NULL; }
#line 1529 "udf_parser.tab.c"
    break;

  case 17: /* opt_vardecs: vardecs  */
#line 129 "udf_parser.y"
                              { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1535 "udf_parser.tab.c"
    break;

  case 18: /* data_type: tSTRING_TYPE  */
#line 132 "udf_parser.y"
                                                   { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
#line 1541 "udf_parser.tab.c"
    break;

  case 19: /* data_type: tINT_TYPE  */
#line 133 "udf_parser.y"
                                                   { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT);     }
#line 1547 "udf_parser.tab.c"
    break;

  case 20: /* data_type: tREAL_TYPE  */
#line 134 "udf_parser.y"
                                                   { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
#line 1553 "udf_parser.tab.c"
    break;

  case 21: /* data_type: tVOID_TYPE  */
#line 135 "udf_parser.y"
                                                   { (yyval.type) = cdk::primitive_type::create(0, cdk::TYPE_VOID);   }
#line 1559 "udf_parser.tab.c"
    break;

  case 22: /* data_type: tTENSOR_TYPE '<' tensor_dims '>'  */
#line 136 "udf_parser.y"
                                                   { (yyval.type) = cdk::tensor_type::create(*(yyvsp[-1].dims));}
#line 1565 "udf_parser.tab.c"
    break;

  case 23: /* data_type: tPTR_TYPE '<' data_type '>'  */
#line 137 "udf_parser.y"
                                                   { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1571 "udf_parser.tab.c"
    break;

  case 24: /* data_type: tPTR_TYPE '<' tAUTO_TYPE '>'  */
#line 138 "udf_parser.y"
                                                   { (yyval.type) = cdk::reference_type::create(4, nullptr); }
#line 1577 "udf_parser.tab.c"
    break;

  case 25: /* tensor_dims: tINTEGER  */
#line 141 "udf_parser.y"
                                                    { (yyval.dims) = new std::vector<size_t>({(size_t)(yyvsp[0].i)}); }
#line 1583 "udf_parser.tab.c"
    break;

  case 26: /* tensor_dims: tensor_dims ',' tINTEGER  */
#line 142 "udf_parser.y"
                                                    { (yyval.dims) = (yyvsp[-2].dims); (yyvsp[-2].dims)->push_back((size_t)(yyvsp[0].i)); }
#line 1589 "udf_parser.tab.c"
    break;

  case 27: /* opt_initializer: %empty  */
#line 145 "udf_parser.y"
                                      { (yyval.expression) = nullptr; /* must be nullptr, not NIL */ }
#line 1595 "udf_parser.tab.c"
    break;

  case 28: /* opt_initializer: '=' expr  */
#line 146 "udf_parser.y"
                                      { (yyval.expression) = (yyvsp[0].expression); }
#line 1601 "udf_parser.tab.c"
    break;

  case 29: /* fundec: data_type tID '(' argdecs ')'  */
#line 149 "udf_parser.y"
                                                          { (yyval.node) = new udf::function_declaration_node(LINE, tPRIVATE, (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1607 "udf_parser.tab.c"
    break;

  case 30: /* fundec: tFORWARD data_type tID '(' argdecs ')'  */
#line 150 "udf_parser.y"
                                                          { (yyval.node) = new udf::function_declaration_node(LINE, tPUBLIC,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1613 "udf_parser.tab.c"
    break;

  case 31: /* fundec: tPUBLIC data_type tID '(' argdecs ')'  */
#line 151 "udf_parser.y"
                                                          { (yyval.node) = new udf::function_declaration_node(LINE, tPUBLIC,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1619 "udf_parser.tab.c"
    break;

  case 32: /* fundec: tAUTO_TYPE tID '(' argdecs ')'  */
#line 152 "udf_parser.y"
                                                          { (yyval.node) = new udf::function_declaration_node(LINE, tPRIVATE, nullptr, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1625 "udf_parser.tab.c"
    break;

  case 33: /* fundec: tFORWARD tAUTO_TYPE tID '(' argdecs ')'  */
#line 153 "udf_parser.y"
                                                          { (yyval.node) = new udf::function_declaration_node(LINE, tPUBLIC,  nullptr, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1631 "udf_parser.tab.c"
    break;

  case 34: /* fundec: tPUBLIC tAUTO_TYPE tID '(' argdecs ')'  */
#line 154 "udf_parser.y"
                                                          { (yyval.node) = new udf::function_declaration_node(LINE, tPUBLIC,  nullptr, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1637 "udf_parser.tab.c"
    break;

  case 35: /* fundef: data_type tID '(' argdecs ')' block  */
#line 157 "udf_parser.y"
                                                               { (yyval.node) = new udf::function_definition_node(LINE, tPRIVATE, (yyvsp[-5].type), *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); }
#line 1643 "udf_parser.tab.c"
    break;

  case 36: /* fundef: tPUBLIC data_type tID '(' argdecs ')' block  */
#line 158 "udf_parser.y"
                                                               { (yyval.node) = new udf::function_definition_node(LINE, tPUBLIC,  (yyvsp[-5].type), *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); }
#line 1649 "udf_parser.tab.c"
    break;

  case 37: /* fundef: tAUTO_TYPE tID '(' argdecs ')' block  */
#line 159 "udf_parser.y"
                                                               { (yyval.node) = new udf::function_definition_node(LINE, tPRIVATE, nullptr, *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); }
#line 1655 "udf_parser.tab.c"
    break;

  case 38: /* fundef: tPUBLIC tAUTO_TYPE tID '(' argdecs ')' block  */
#line 160 "udf_parser.y"
                                                               { (yyval.node) = new udf::function_definition_node(LINE, tPUBLIC,  nullptr, *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); }
#line 1661 "udf_parser.tab.c"
    break;

  case 39: /* argdecs: %empty  */
#line 163 "udf_parser.y"
                                      { (yyval.sequence) = new cdk::sequence_node(LINE);  }
#line 1667 "udf_parser.tab.c"
    break;

  case 40: /* argdecs: argdec  */
#line 164 "udf_parser.y"
                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1673 "udf_parser.tab.c"
    break;

  case 41: /* argdecs: argdecs ',' argdec  */
#line 165 "udf_parser.y"
                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1679 "udf_parser.tab.c"
    break;

  case 42: /* argdec: data_type tID  */
#line 168 "udf_parser.y"
                                { (yyval.node) = new udf::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1685 "udf_parser.tab.c"
    break;

  case 43: /* block: '{' opt_vardecs opt_stmts '}'  */
#line 171 "udf_parser.y"
                                                { (yyval.block) = new udf::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)); }
#line 1691 "udf_parser.tab.c"
    break;

  case 44: /* fordec: data_type tID '=' expr  */
#line 174 "udf_parser.y"
                                         { (yyval.node) = new udf::variable_declaration_node(LINE, tPRIVATE,  (yyvsp[-3].type), *(yyvsp[-2].s), (yyvsp[0].expression)); }
#line 1697 "udf_parser.tab.c"
    break;

  case 45: /* fordecs: fordec  */
#line 177 "udf_parser.y"
                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1703 "udf_parser.tab.c"
    break;

  case 46: /* fordecs: fordecs ',' fordec  */
#line 178 "udf_parser.y"
                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1709 "udf_parser.tab.c"
    break;

  case 47: /* opt_forinit: %empty  */
#line 181 "udf_parser.y"
                                      { (yyval.node) = new cdk::sequence_node(LINE); }
#line 1715 "udf_parser.tab.c"
    break;

  case 48: /* opt_forinit: fordecs  */
#line 182 "udf_parser.y"
                           { (yyval.node) = (yyvsp[0].sequence); }
#line 1721 "udf_parser.tab.c"
    break;

  case 49: /* opt_forinit: tAUTO_TYPE tID '=' exprs  */
#line 183 "udf_parser.y"
                                           {
                  (yyval.node) = new udf::variable_declaration_node(LINE, tPRIVATE, nullptr, *(yyvsp[-2].s), new udf::tensor_node(LINE, nullptr, (yyvsp[0].sequence)));
                  delete (yyvsp[-2].s);
                }
#line 1730 "udf_parser.tab.c"
    break;

  case 50: /* opt_forinit: exprs  */
#line 187 "udf_parser.y"
                                      { (yyval.node) = new udf::tensor_node(LINE, nullptr, (yyvsp[0].sequence)); }
#line 1736 "udf_parser.tab.c"
    break;

  case 51: /* return: tRETURN ';'  */
#line 190 "udf_parser.y"
                                      { (yyval.node) = new udf::return_node(LINE, nullptr); }
#line 1742 "udf_parser.tab.c"
    break;

  case 52: /* return: tRETURN expr ';'  */
#line 191 "udf_parser.y"
                                      { (yyval.node) = new udf::return_node(LINE, new udf::tensor_node(LINE, (yyvsp[-1].expression), nullptr)); }
#line 1748 "udf_parser.tab.c"
    break;

  case 53: /* stmts: stmt  */
#line 194 "udf_parser.y"
                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1754 "udf_parser.tab.c"
    break;

  case 54: /* stmts: stmts stmt  */
#line 195 "udf_parser.y"
                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1760 "udf_parser.tab.c"
    break;

  case 55: /* opt_stmts: %empty  */
#line 198 "udf_parser.y"
                                      { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1766 "udf_parser.tab.c"
    break;

  case 56: /* opt_stmts: stmts  */
#line 199 "udf_parser.y"
                                      { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1772 "udf_parser.tab.c"
    break;

  case 57: /* stmt: tIF '(' expr ')' stmt  */
#line 203 "udf_parser.y"
                                                                             { (yyval.node) = new udf::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1778 "udf_parser.tab.c"
    break;

  case 58: /* stmt: tIF '(' expr ')' stmt iffalse  */
#line 204 "udf_parser.y"
                                                                             { (yyval.node) = new udf::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1784 "udf_parser.tab.c"
    break;

  case 59: /* stmt: tFOR '(' opt_forinit ';' opt_exprs ';' opt_exprs ')' stmt  */
#line 205 "udf_parser.y"
                                                                             { (yyval.node) = new udf::for_node(LINE, static_cast<cdk::sequence_node*>((yyvsp[-6].node)), static_cast<cdk::sequence_node*>((yyvsp[-4].sequence)), static_cast<cdk::sequence_node*>((yyvsp[-2].sequence)), (yyvsp[0].node)); }
#line 1790 "udf_parser.tab.c"
    break;

  case 60: /* stmt: expr ';'  */
#line 206 "udf_parser.y"
                                                                             { (yyval.node) = new udf::evaluation_node(LINE, (yyvsp[-1].expression)); }
#line 1796 "udf_parser.tab.c"
    break;

  case 61: /* stmt: tPRINT exprs ';'  */
#line 207 "udf_parser.y"
                                                                             { (yyval.node) = new udf::print_node(LINE, (yyvsp[-1].sequence), false); }
#line 1802 "udf_parser.tab.c"
    break;

  case 62: /* stmt: tPRINTLN exprs ';'  */
#line 208 "udf_parser.y"
                                                                             { (yyval.node) = new udf::print_node(LINE, (yyvsp[-1].sequence), true); }
#line 1808 "udf_parser.tab.c"
    break;

  case 63: /* stmt: tBREAK  */
#line 209 "udf_parser.y"
                                                                             { (yyval.node) = new udf::break_node(LINE);  }
#line 1814 "udf_parser.tab.c"
    break;

  case 64: /* stmt: tCONTINUE  */
#line 210 "udf_parser.y"
                                                                             { (yyval.node) = new udf::continue_node(LINE); }
#line 1820 "udf_parser.tab.c"
    break;

  case 65: /* stmt: return  */
#line 211 "udf_parser.y"
                                                                             { (yyval.node) = (yyvsp[0].node); }
#line 1826 "udf_parser.tab.c"
    break;

  case 66: /* stmt: block  */
#line 212 "udf_parser.y"
                                                                             { (yyval.node) = (yyvsp[0].block); }
#line 1832 "udf_parser.tab.c"
    break;

  case 67: /* iffalse: tELSE stmt  */
#line 214 "udf_parser.y"
                                                    { (yyval.node) = (yyvsp[0].node); }
#line 1838 "udf_parser.tab.c"
    break;

  case 68: /* iffalse: tELIF '(' expr ')' stmt iffalse  */
#line 215 "udf_parser.y"
                                                    { (yyval.node) = new udf::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1844 "udf_parser.tab.c"
    break;

  case 69: /* lvalue: tID  */
#line 219 "udf_parser.y"
                                                            { (yyval.lvalue) = new cdk::variable_node(LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1850 "udf_parser.tab.c"
    break;

  case 70: /* lvalue: lvalue '[' expr ']'  */
#line 220 "udf_parser.y"
                                                            { (yyval.lvalue) = new udf::left_index_node(LINE, new cdk::rvalue_node(LINE, (yyvsp[-3].lvalue)), (yyvsp[-1].expression)); }
#line 1856 "udf_parser.tab.c"
    break;

  case 71: /* lvalue: '(' expr ')' '[' expr ']'  */
#line 221 "udf_parser.y"
                                                            { (yyval.lvalue) = new udf::left_index_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].expression)); }
#line 1862 "udf_parser.tab.c"
    break;

  case 72: /* lvalue: tID '(' opt_exprs ')' '[' expr ']'  */
#line 222 "udf_parser.y"
                                                            { (yyval.lvalue) = new udf::left_index_node(LINE, new udf::function_call_node(LINE, *(yyvsp[-6].s), (yyvsp[-4].sequence)), (yyvsp[-1].expression)); }
#line 1868 "udf_parser.tab.c"
    break;

  case 73: /* lvalue: expr tTINDEX '(' exprs ')'  */
#line 223 "udf_parser.y"
                                                                  { (yyval.lvalue) = new udf::tensor_index_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].sequence)); }
#line 1874 "udf_parser.tab.c"
    break;

  case 74: /* expr: integer  */
#line 226 "udf_parser.y"
                                                      { (yyval.expression) = (yyvsp[0].expression); }
#line 1880 "udf_parser.tab.c"
    break;

  case 75: /* expr: real  */
#line 227 "udf_parser.y"
                                                      { (yyval.expression) = (yyvsp[0].expression); }
#line 1886 "udf_parser.tab.c"
    break;

  case 76: /* expr: string  */
#line 228 "udf_parser.y"
                                                      { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s)); }
#line 1892 "udf_parser.tab.c"
    break;

  case 77: /* expr: tNULLPTR  */
#line 229 "udf_parser.y"
                                                      { (yyval.expression) = new udf::nullptr_node(LINE); }
#line 1898 "udf_parser.tab.c"
    break;

  case 78: /* expr: tTENSOR_TYPE '<' exprs '>'  */
#line 230 "udf_parser.y"
                                                      { (yyval.expression) = new udf::tensor_node(LINE,nullptr,(yyvsp[-1].sequence));}
#line 1904 "udf_parser.tab.c"
    break;

  case 79: /* expr: tensor_literal  */
#line 231 "udf_parser.y"
                                                      { (yyval.expression) = (yyvsp[0].expression);}
#line 1910 "udf_parser.tab.c"
    break;

  case 80: /* expr: expr '.' tTCAPACITY  */
#line 232 "udf_parser.y"
                                                      { (yyval.expression) = new udf::tensor_capacity_node(LINE,(yyvsp[-2].expression));}
#line 1916 "udf_parser.tab.c"
    break;

  case 81: /* expr: expr '.' tTRANK  */
#line 233 "udf_parser.y"
                                                      { (yyval.expression) = new udf::tensor_rank_node(LINE,(yyvsp[-2].expression));}
#line 1922 "udf_parser.tab.c"
    break;

  case 82: /* expr: expr '.' tTDIM '(' expr ')'  */
#line 234 "udf_parser.y"
                                                      { (yyval.expression) = new udf::tensor_dim_node(LINE,(yyvsp[-5].expression), (yyvsp[-1].expression));}
#line 1928 "udf_parser.tab.c"
    break;

  case 83: /* expr: expr '.' tTRESHAPE '(' exprs ')'  */
#line 235 "udf_parser.y"
                                                      { (yyval.expression) = new udf::tensor_reshape_node(LINE,(yyvsp[-5].expression),(yyvsp[-1].sequence));}
#line 1934 "udf_parser.tab.c"
    break;

  case 84: /* expr: expr tTCONTRACTION expr  */
#line 236 "udf_parser.y"
                                                      { (yyval.expression) = new udf::tensor_contraction_node(LINE,(yyvsp[-2].expression),(yyvsp[0].expression));}
#line 1940 "udf_parser.tab.c"
    break;

  case 85: /* expr: lvalue  */
#line 239 "udf_parser.y"
                                                { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue)); }
#line 1946 "udf_parser.tab.c"
    break;

  case 86: /* expr: lvalue '=' expr  */
#line 241 "udf_parser.y"
                                                { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[0].expression)); }
#line 1952 "udf_parser.tab.c"
    break;

  case 87: /* expr: expr '+' expr  */
#line 243 "udf_parser.y"
                                                { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1958 "udf_parser.tab.c"
    break;

  case 88: /* expr: expr '-' expr  */
#line 244 "udf_parser.y"
                                                { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1964 "udf_parser.tab.c"
    break;

  case 89: /* expr: expr '*' expr  */
#line 245 "udf_parser.y"
                                                { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1970 "udf_parser.tab.c"
    break;

  case 90: /* expr: expr '/' expr  */
#line 246 "udf_parser.y"
                                                { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1976 "udf_parser.tab.c"
    break;

  case 91: /* expr: expr '%' expr  */
#line 247 "udf_parser.y"
                                                { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1982 "udf_parser.tab.c"
    break;

  case 92: /* expr: expr '<' expr  */
#line 249 "udf_parser.y"
                                                { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1988 "udf_parser.tab.c"
    break;

  case 93: /* expr: expr tLE expr  */
#line 250 "udf_parser.y"
                                                { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1994 "udf_parser.tab.c"
    break;

  case 94: /* expr: expr tEQ expr  */
#line 251 "udf_parser.y"
                                                { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2000 "udf_parser.tab.c"
    break;

  case 95: /* expr: expr tGE expr  */
#line 252 "udf_parser.y"
                                                { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2006 "udf_parser.tab.c"
    break;

  case 96: /* expr: expr '>' expr  */
#line 253 "udf_parser.y"
                                                { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2012 "udf_parser.tab.c"
    break;

  case 97: /* expr: expr tNE expr  */
#line 254 "udf_parser.y"
                                                { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2018 "udf_parser.tab.c"
    break;

  case 98: /* expr: expr tAND expr  */
#line 256 "udf_parser.y"
                                                { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2024 "udf_parser.tab.c"
    break;

  case 99: /* expr: expr tOR expr  */
#line 257 "udf_parser.y"
                                                { (yyval.expression) = new cdk::or_node (LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2030 "udf_parser.tab.c"
    break;

  case 100: /* expr: '-' expr  */
#line 259 "udf_parser.y"
                                                { (yyval.expression) = new cdk::unary_minus_node(LINE, (yyvsp[0].expression)); }
#line 2036 "udf_parser.tab.c"
    break;

  case 101: /* expr: '+' expr  */
#line 260 "udf_parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2042 "udf_parser.tab.c"
    break;

  case 102: /* expr: '~' expr  */
#line 261 "udf_parser.y"
                                                            { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression)); }
#line 2048 "udf_parser.tab.c"
    break;

  case 103: /* expr: tINPUT  */
#line 263 "udf_parser.y"
                                                { (yyval.expression) = new udf::input_node(LINE); }
#line 2054 "udf_parser.tab.c"
    break;

  case 104: /* expr: tOBJECTS '(' expr ')'  */
#line 265 "udf_parser.y"
                                                { (yyval.expression) = new udf::object_node(LINE, (yyvsp[-1].expression)); }
#line 2060 "udf_parser.tab.c"
    break;

  case 105: /* expr: tID '(' opt_exprs ')'  */
#line 266 "udf_parser.y"
                                                { (yyval.expression) = new udf::function_call_node(LINE, *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 2066 "udf_parser.tab.c"
    break;

  case 106: /* expr: tSIZEOF '(' exprs ')'  */
#line 267 "udf_parser.y"
                                                { (yyval.expression) = new udf::sizeof_node(LINE, new udf::tensor_node(LINE, nullptr, (yyvsp[-1].sequence))); }
#line 2072 "udf_parser.tab.c"
    break;

  case 107: /* expr: '(' expr ')'  */
#line 269 "udf_parser.y"
                                                { (yyval.expression) = (yyvsp[-1].expression); }
#line 2078 "udf_parser.tab.c"
    break;

  case 108: /* expr: '[' expr ']'  */
#line 270 "udf_parser.y"
                                                { (yyval.expression) = new udf::tensor_node(LINE, (yyvsp[-1].expression), nullptr); }
#line 2084 "udf_parser.tab.c"
    break;

  case 109: /* expr: lvalue '?'  */
#line 271 "udf_parser.y"
                                                { (yyval.expression) = new udf::address_of_node(LINE, (yyvsp[-1].lvalue)); }
#line 2090 "udf_parser.tab.c"
    break;

  case 110: /* exprs: expr  */
#line 276 "udf_parser.y"
                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression));     }
#line 2096 "udf_parser.tab.c"
    break;

  case 111: /* exprs: exprs ',' expr  */
#line 277 "udf_parser.y"
                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 2102 "udf_parser.tab.c"
    break;

  case 112: /* opt_exprs: %empty  */
#line 280 "udf_parser.y"
                                            { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 2108 "udf_parser.tab.c"
    break;

  case 113: /* opt_exprs: exprs  */
#line 281 "udf_parser.y"
                                            { (yyval.sequence) = (yyvsp[0].sequence); }
#line 2114 "udf_parser.tab.c"
    break;

  case 114: /* tensor_literal: '[' exprs ']'  */
#line 285 "udf_parser.y"
                                { (yyval.expression) = new udf::tensor_node(LINE,nullptr,(yyvsp[-1].sequence));}
#line 2120 "udf_parser.tab.c"
    break;

  case 115: /* integer: tINTEGER  */
#line 289 "udf_parser.y"
                                                { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i)); }
#line 2126 "udf_parser.tab.c"
    break;

  case 116: /* real: tREAL  */
#line 290 "udf_parser.y"
                                                { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d)); }
#line 2132 "udf_parser.tab.c"
    break;

  case 117: /* string: tSTRING  */
#line 291 "udf_parser.y"
                                                { (yyval.s) = (yyvsp[0].s); }
#line 2138 "udf_parser.tab.c"
    break;

  case 118: /* string: string tSTRING  */
#line 292 "udf_parser.y"
                                                { (yyval.s) = (yyvsp[-1].s); (yyval.s)->append(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2144 "udf_parser.tab.c"
    break;


#line 2148 "udf_parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (compiler, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, compiler);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, compiler);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (compiler, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, compiler);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

