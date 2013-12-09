/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Parser.y" /* yacc.c:339  */

 
/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */


#include "Sociaty.h"
#include "Role.h"
#include "Eval.h"
#include "Parser.h"
#include "Lexer.h"

int yyparse(yyscan_t scanner);
int yyerror(yyscan_t scanner, const char *msg){
		printf("yyerror, %s\n",msg);
	}

#define YACCDEBUG
#ifdef YACCDEBUG
#define yd_print(s) \
  {\
    fprintf(ns.Err, "--->Match %s\n", s);\
  }
#else
#define yd_print(s) 
#endif
extern Sociaty ns;
 

#line 98 "Parser.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 33 "Parser.y" /* yacc.c:355  */

#include "Common.h"  
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
	typedef void* yyscan_t;
#endif
void ParseExpressionFromFile(char *fpath);
void ParseExpressionFromFp(FILE *fp);
void ParseExpressionFromString(char *str);
yyscan_t current_scanner;

#line 140 "Parser.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    INTEGER = 260,
    BLOCK = 261,
    FOR = 262,
    WHILE = 263,
    IF = 264,
    ELSIF = 265,
    ELSE = 266,
    USE = 267,
    LOAD = 268,
    ADD = 269,
    INVOKE = 270,
    PRINT = 271,
    PUTSTR = 272,
    VALUE = 273,
    READFILE = 274,
    NOT = 275,
    ISFILE = 276,
    ISDIR = 277,
    END_OF_STATEMENT = 278,
    SETFLAG = 279,
    SETARGS = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 52 "Parser.y" /* yacc.c:355  */

	int numval;
	StringIntArray arr;
	StringInt strint;
	char *strval;

#line 185 "Parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 199 "Parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,     2,
      29,    30,     2,    35,    38,     2,    37,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,     2,
      27,    26,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    32,     2,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    92,    97,    98,    99,   103,   109,   110,
     111,   112,   113,   125,   142,   150,   164,   168,   173,   180,
     187,   192,   197,   201,   205,   209,   213,   218,   222,   226,
     230,   234,   240,   247,   251,   260,   266,   274,   280,   286,
     292,   298,   304,   309,   316,   330,   334,   338,   348,   360,
     365,   368,   376,   390,   393,   398,   399,   402,   406,   413,
     419,   427,   431,   438,   443,   450,   455
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT", "INTEGER",
  "BLOCK", "FOR", "WHILE", "IF", "ELSIF", "ELSE", "USE", "LOAD", "ADD",
  "INVOKE", "PRINT", "PUTSTR", "VALUE", "READFILE", "NOT", "ISFILE",
  "ISDIR", "END_OF_STATEMENT", "SETFLAG", "SETARGS", "'='", "'<'", "'>'",
  "'('", "')'", "'&'", "'|'", "'['", "']'", "'+'", "':'", "'.'", "','",
  "$accept", "translation_unit", "statement", "expression",
  "control_expression", "else_expression", "boolean_expression",
  "internal_function", "assignment_expression", "inherent_expression",
  "eval_expression", "role_as_const", "const_as_role", "const_or_int",
  "role", "member", "argument", "argument_list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    61,    60,    62,    40,
      41,    38,   124,    91,    93,    43,    58,    46,    44
};
# endif

#define YYPACT_NINF -28

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-28)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     160,   -19,     4,   114,   107,   107,     4,     4,    46,   -28,
     -28,     4,     4,   137,   -28,   -15,   -28,   -28,   -28,   -28,
     -28,    70,   -18,    11,    19,    30,   -28,   -28,   107,   107,
     114,   107,   107,   114,    36,   -16,   -28,   -28,   -28,   -28,
      46,   107,   -28,   -28,   -28,     8,    46,    46,   -28,   -28,
     -28,   -28,    97,    26,    21,     4,     8,    49,    52,    23,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,    90,    53,    34,
      40,    58,   152,   -28,   -28,   -28,   -28,    46,   -28,   -28,
       8,     4,    46,   -28,   -28,   -25,   107,   -28,    35,   -28,
     -28,   -28,    55,    39,    17,   107,   107,   107,   -28,   107,
     -28,   -28,   -28,   -17,   -28,   -28,   -28,   114,   114,   -28,
     114,   -28,   -28,   -28,   -28,   -28,   -28,    60,    67,    82,
     -28,   -28,    87,    17,   -28
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    58,     0,     0,     0,     0,     0,     0,     0,     7,
       4,     0,     0,     0,     2,     0,     8,     9,    10,    11,
      12,    45,    57,     0,     0,     0,    55,    56,     0,     0,
       0,     0,     0,     0,     0,    19,    50,    49,    32,    33,
       0,     0,    63,    64,    65,    34,     0,     0,     1,     3,
       6,     5,     0,     0,     0,     0,    47,     0,     0,     0,
      59,    13,    51,    52,    26,    27,    28,     0,    14,     0,
       0,     0,     0,    35,    54,    53,    36,     0,    38,    37,
      39,     0,     0,    41,    46,     0,     0,    44,     0,    61,
      60,    29,     0,     0,     0,     0,     0,     0,    22,     0,
      23,    66,    43,     0,    48,    42,    62,     0,     0,    16,
       0,    15,    21,    20,    24,    25,    40,     0,     0,     0,
      30,    31,    17,     0,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,    91,   -28,   -28,   -20,   -27,   -28,   -28,   -28,
     -28,    -4,   -28,    12,    32,   -28,    31,   -12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,    14,    15,    16,   111,    34,    17,    18,    19,
      20,    35,    73,    36,    37,    22,    44,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    39,    50,    64,    69,   104,    67,     1,    51,    56,
      70,    71,    72,    77,    23,    57,    59,   116,    24,    58,
      42,    77,    60,   109,    62,    63,   110,    65,    66,     1,
      26,    27,    21,    42,    25,    80,    61,    76,    40,    41,
      43,    85,    68,    46,    47,    21,    77,    86,    83,     1,
      26,    27,    74,    43,    88,    89,    84,    90,    78,    42,
      95,     1,    26,    27,    94,    42,    96,    98,   100,   106,
     103,   108,    75,     1,    26,    27,    28,    29,    79,    43,
     117,   118,   105,   119,    97,    43,   107,    87,   122,    42,
     120,   112,   113,   114,    42,   115,    52,   121,   123,    53,
       1,    26,    27,   124,    49,    54,    55,     0,   101,    43,
       1,    26,    27,   102,    43,    28,    29,     1,    26,    27,
      91,    92,    93,     0,     0,    28,    29,     0,    81,     0,
      82,     0,    28,    29,    30,    31,    32,    48,     0,     0,
       1,     0,     0,    33,     2,     0,     3,     0,     0,     4,
       5,     6,     7,     8,     9,     1,    26,    27,     0,     0,
      10,    11,    12,     1,     0,     0,     0,     2,     0,     3,
      28,    29,     4,     5,     6,     7,     8,     9,    99,     0,
       0,     0,     0,    10,    11,    12
};

static const yytype_int8 yycheck[] =
{
       4,     5,    17,    30,    20,    30,    33,     3,    23,    21,
      26,    27,    28,    38,    33,    33,     5,    34,    37,    37,
       8,    38,     3,     6,    28,    29,     9,    31,    32,     3,
       4,     5,     0,    21,     2,    47,     6,    41,     6,     7,
       8,    53,     6,    11,    12,    13,    38,    26,    52,     3,
       4,     5,    40,    21,     5,     3,    30,    34,    46,    47,
      26,     3,     4,     5,    11,    53,    26,    71,    72,    34,
      82,    32,    40,     3,     4,     5,    18,    19,    46,    47,
     107,   108,    86,   110,    26,    53,    31,    55,     6,    77,
      30,    95,    96,    97,    82,    99,    26,    30,    11,    29,
       3,     4,     5,   123,    13,    35,    36,    -1,    77,    77,
       3,     4,     5,    81,    82,    18,    19,     3,     4,     5,
      30,    31,    32,    -1,    -1,    18,    19,    -1,    31,    -1,
      33,    -1,    18,    19,    20,    21,    22,     0,    -1,    -1,
       3,    -1,    -1,    29,     7,    -1,     9,    -1,    -1,    12,
      13,    14,    15,    16,    17,     3,     4,     5,    -1,    -1,
      23,    24,    25,     3,    -1,    -1,    -1,     7,    -1,     9,
      18,    19,    12,    13,    14,    15,    16,    17,    26,    -1,
      -1,    -1,    -1,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,     9,    12,    13,    14,    15,    16,    17,
      23,    24,    25,    40,    41,    42,    43,    46,    47,    48,
      49,    53,    54,    33,    37,    53,     4,     5,    18,    19,
      20,    21,    22,    29,    45,    50,    52,    53,    50,    50,
      53,    53,    52,    53,    55,    56,    53,    53,     0,    41,
      17,    23,    26,    29,    35,    36,    56,    33,    37,     5,
       3,     6,    50,    50,    45,    50,    50,    45,     6,    20,
      26,    27,    28,    51,    52,    53,    50,    38,    52,    53,
      56,    31,    33,    50,    30,    56,    26,    53,     5,     3,
      34,    30,    31,    32,    11,    26,    26,    26,    50,    26,
      50,    55,    53,    56,    30,    50,    34,    31,    32,     6,
       9,    44,    50,    50,    50,    50,    34,    45,    45,    45,
      30,    30,     6,    11,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    41,    41,    41,    41,    42,    42,
      42,    42,    42,    43,    43,    43,    44,    44,    44,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    47,    47,    47,    48,    49,    49,    49,    49,    50,
      50,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    54,    55,    55,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     3,     5,     1,     3,     5,     1,
       4,     4,     3,     3,     4,     4,     2,     2,     2,     3,
       6,     6,     2,     2,     2,     3,     3,     3,     3,     3,
       5,     3,     4,     4,     3,     1,     3,     2,     4,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     4,     1,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (scanner, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, yyscan_t scanner)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 89 "Parser.y" /* yacc.c:1661  */
    { 
  yd_print("statement");
}
#line 1359 "Parser.c" /* yacc.c:1661  */
    break;

  case 3:
#line 92 "Parser.y" /* yacc.c:1661  */
    { 
	yd_print("translation_unit statement");
}
#line 1367 "Parser.c" /* yacc.c:1661  */
    break;

  case 6:
#line 100 "Parser.y" /* yacc.c:1661  */
    {
	Sociaty_PutString((yyvsp[0].strval));
}
#line 1375 "Parser.c" /* yacc.c:1661  */
    break;

  case 7:
#line 104 "Parser.y" /* yacc.c:1661  */
    {
	Sociaty_PutString((yyvsp[0].strval));
}
#line 1383 "Parser.c" /* yacc.c:1661  */
    break;

  case 12:
#line 114 "Parser.y" /* yacc.c:1661  */
    {
	char *rtn;
	rtn = Eval((yyvsp[0].numval));
	yd_print(rtn);
	ParseExpressionFromString(rtn);
//	Sociaty_WriteMembers();
//	printf("clearargs%d\n", $1);
	Sociaty_ClearArgs((yyvsp[0].numval));
}
#line 1397 "Parser.c" /* yacc.c:1661  */
    break;

  case 13:
#line 126 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("FOR");
	int i, ii, it;
	char str[8];
	it = Sociaty_RoleAddSubordinate((yyvsp[-1].numval), "_Iterator");
	ii = Sociaty_RoleAddSubordinate((yyvsp[-1].numval), "_Index");
	for(i=0; i< Sociaty_GetRole((yyvsp[-1].numval))->Elements.Length; i++){
    Sociaty_GetRole(it)->_TargetIndex = Sociaty_GetRole((yyvsp[-1].numval))->Elements.Values[i];
		sprintf(str, "%d", i);
		Sociaty_GetRole(ii)->_Value = estrdup(str);
//		printf("xxxx%s\nxxx", Sociaty_GetRole(ii)->_Value);
		char *rtn;
		rtn = EvalString(Sociaty_GetFinalRole((yyvsp[-1].numval)), (yyvsp[0].strval), 1);
    ParseExpressionFromString(rtn);
  }
}
#line 1418 "Parser.c" /* yacc.c:1661  */
    break;

  case 14:
#line 143 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("IF");
	if((yyvsp[-1].numval)){
		estraddeol(&(yyvsp[0].strval));
		ParseExpressionFromString((yyvsp[0].strval));
	}
}
#line 1430 "Parser.c" /* yacc.c:1661  */
    break;

  case 15:
#line 151 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("IF ELSE");
  if((yyvsp[-3].numval)){
		estraddeol(&(yyvsp[-2].strval));
    ParseExpressionFromString((yyvsp[-2].strval));
  }
	else{
		estraddeol(&(yyvsp[0].strval));
		ParseExpressionFromString((yyvsp[0].strval));
	}
}
#line 1446 "Parser.c" /* yacc.c:1661  */
    break;

  case 16:
#line 165 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.strval) = (yyvsp[0].strval);
}
#line 1454 "Parser.c" /* yacc.c:1661  */
    break;

  case 17:
#line 169 "Parser.y" /* yacc.c:1661  */
    {
	if((yyvsp[-1].numval)) (yyval.strval) = (yyvsp[0].strval);
	else (yyval.strval) = estrdup("");
}
#line 1463 "Parser.c" /* yacc.c:1661  */
    break;

  case 18:
#line 174 "Parser.y" /* yacc.c:1661  */
    {
	if((yyvsp[-3].numval)) (yyval.strval) = (yyvsp[-2].strval);
  else (yyval.strval) = (yyvsp[0].strval);
}
#line 1472 "Parser.c" /* yacc.c:1661  */
    break;

  case 19:
#line 181 "Parser.y" /* yacc.c:1661  */
    {
	if(!estrisnull((yyvsp[0].strval)) && strcmp((yyvsp[0].strval), "0"))
		(yyval.numval) = 1;
	else
		(yyval.numval) = 0;
}
#line 1483 "Parser.c" /* yacc.c:1661  */
    break;

  case 20:
#line 188 "Parser.y" /* yacc.c:1661  */
    {
	if(!strcmp((yyvsp[-3].strval), (yyvsp[0].strval))) (yyval.numval) = 1;
	else (yyval.numval) = 0;
}
#line 1492 "Parser.c" /* yacc.c:1661  */
    break;

  case 21:
#line 193 "Parser.y" /* yacc.c:1661  */
    {
	if(strcmp((yyvsp[-3].strval), (yyvsp[0].strval))) (yyval.numval) = 1;
	else (yyval.numval) = 0;
}
#line 1501 "Parser.c" /* yacc.c:1661  */
    break;

  case 22:
#line 198 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = (atoi((yyvsp[-2].strval)) < atoi((yyvsp[0].strval)));
}
#line 1509 "Parser.c" /* yacc.c:1661  */
    break;

  case 23:
#line 202 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = (atoi((yyvsp[-2].strval)) >= atoi((yyvsp[0].strval)));
}
#line 1517 "Parser.c" /* yacc.c:1661  */
    break;

  case 24:
#line 206 "Parser.y" /* yacc.c:1661  */
    {
  (yyval.numval) = (atoi((yyvsp[-3].strval)) <= atoi((yyvsp[0].strval)));
}
#line 1525 "Parser.c" /* yacc.c:1661  */
    break;

  case 25:
#line 210 "Parser.y" /* yacc.c:1661  */
    {
  (yyval.numval) = (atoi((yyvsp[-3].strval)) >= atoi((yyvsp[0].strval)));
}
#line 1533 "Parser.c" /* yacc.c:1661  */
    break;

  case 26:
#line 214 "Parser.y" /* yacc.c:1661  */
    {
//	printf("NOT %d", $2);
	(yyval.numval) = !(yyvsp[0].numval);
}
#line 1542 "Parser.c" /* yacc.c:1661  */
    break;

  case 27:
#line 219 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = eisfile((yyvsp[0].strval));
}
#line 1550 "Parser.c" /* yacc.c:1661  */
    break;

  case 28:
#line 223 "Parser.y" /* yacc.c:1661  */
    {
  (yyval.numval) = eisdir((yyvsp[0].strval));
}
#line 1558 "Parser.c" /* yacc.c:1661  */
    break;

  case 29:
#line 227 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = (yyvsp[-1].numval);
}
#line 1566 "Parser.c" /* yacc.c:1661  */
    break;

  case 30:
#line 231 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = (yyvsp[-4].numval) && (yyvsp[-1].numval);
}
#line 1574 "Parser.c" /* yacc.c:1661  */
    break;

  case 31:
#line 235 "Parser.y" /* yacc.c:1661  */
    {
  (yyval.numval) = (yyvsp[-4].numval) || (yyvsp[-1].numval);
}
#line 1582 "Parser.c" /* yacc.c:1661  */
    break;

  case 32:
#line 241 "Parser.y" /* yacc.c:1661  */
    {
	char *fpath;
  fpath = UseFile((yyvsp[0].strval));
		if(fpath != NULL)
			ParseExpressionFromFile(fpath);
}
#line 1593 "Parser.c" /* yacc.c:1661  */
    break;

  case 33:
#line 248 "Parser.y" /* yacc.c:1661  */
    {
	ParseExpressionFromFile((yyvsp[0].strval));
}
#line 1601 "Parser.c" /* yacc.c:1661  */
    break;

  case 34:
#line 252 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("PRINT");
	int i;
	for(i=0; i<(yyvsp[0].arr).Length; i++){
		Sociaty_PutString((yyvsp[0].arr).StrValues[i]);
	}
	StringIntArray_DisposeSub(&(yyvsp[0].arr));
}
#line 1614 "Parser.c" /* yacc.c:1661  */
    break;

  case 35:
#line 261 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("ADD");
	IndexArray_Add(&Sociaty_GetRole((yyvsp[-1].numval))->Elements,
								 (yyvsp[0].numval));
}
#line 1624 "Parser.c" /* yacc.c:1661  */
    break;

  case 36:
#line 267 "Parser.y" /* yacc.c:1661  */
    {
  yd_print("INVOKE");
	char *rtn;
	rtn = EvalString(Sociaty_GetFinalRole((yyvsp[-1].numval)), (yyvsp[0].strval), 1);
//  yd_print(rtn);
	ParseExpressionFromString(rtn);
}
#line 1636 "Parser.c" /* yacc.c:1661  */
    break;

  case 37:
#line 275 "Parser.y" /* yacc.c:1661  */
    {
	//TODO 
  yd_print("SETFLAG");
	Sociaty_GetRole((yyvsp[-1].numval))->_Flag = Sociaty_GetRole((yyvsp[0].numval))->_Flag;
}
#line 1646 "Parser.c" /* yacc.c:1661  */
    break;

  case 38:
#line 281 "Parser.y" /* yacc.c:1661  */
    {
	//TODO 
  yd_print("SETFLAG");
	Sociaty_GetRole((yyvsp[-1].numval))->_Flag = GetFlag((yyvsp[0].strval));
}
#line 1656 "Parser.c" /* yacc.c:1661  */
    break;

  case 39:
#line 287 "Parser.y" /* yacc.c:1661  */
    {
	//TODO 
}
#line 1664 "Parser.c" /* yacc.c:1661  */
    break;

  case 40:
#line 293 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("ASSIGN ARRAY");
	Sociaty_RoleAssignArray((yyvsp[-4].numval), &(yyvsp[-1].arr));
	StringIntArray_DisposeSub(&(yyvsp[-1].arr));
}
#line 1674 "Parser.c" /* yacc.c:1661  */
    break;

  case 41:
#line 299 "Parser.y" /* yacc.c:1661  */
    { 
	yd_print("ASSIGN VALUE");
	if(Sociaty_GetRole((yyvsp[-2].numval))->_Value != NULL) free(Sociaty_GetRole((yyvsp[-2].numval))->_Value);
	Sociaty_GetRole((yyvsp[-2].numval))->_Value = estrdup((yyvsp[0].strval));
}
#line 1684 "Parser.c" /* yacc.c:1661  */
    break;

  case 42:
#line 305 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("CONCAT VALUE");
  estrcat(&Sociaty_GetRole((yyvsp[-3].numval))->_Value, (yyvsp[0].strval));
}
#line 1693 "Parser.c" /* yacc.c:1661  */
    break;

  case 43:
#line 310 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("ASSIGN REF");
	Sociaty_GetRole((yyvsp[-3].numval))->_TargetIndex = (yyvsp[0].numval);
}
#line 1702 "Parser.c" /* yacc.c:1661  */
    break;

  case 44:
#line 317 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("INHERENT");
  if(Sociaty_SearchPCRelation((yyvsp[-2].numval), (yyvsp[0].numval)) != 0){
		printf("EXIST%sxxxx%dxxxx%s\n",Sociaty_GetRole((yyvsp[-2].numval))->_Name,Sociaty_SearchPCRelation((yyvsp[-2].numval), (yyvsp[0].numval)),Sociaty_GetRole((yyvsp[0].numval))->_Name);
    eerror("cannot inherent");
//    exit(1);
  }
	else{
		Sociaty_AddPCRelation((yyvsp[0].numval), (yyvsp[-2].numval));
	}
}
#line 1718 "Parser.c" /* yacc.c:1661  */
    break;

  case 45:
#line 330 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("EVAL");
	(yyval.numval) = (yyvsp[0].numval); 
}
#line 1727 "Parser.c" /* yacc.c:1661  */
    break;

  case 46:
#line 334 "Parser.y" /* yacc.c:1661  */
    {  
	yd_print("EVAL");
	(yyval.numval) = (yyvsp[-2].numval); 
}
#line 1736 "Parser.c" /* yacc.c:1661  */
    break;

  case 47:
#line 339 "Parser.y" /* yacc.c:1661  */
    {
	int i;
	yd_print("EVAL ARGS");

	i = Sociaty_RoleAddSubordinate((yyvsp[-1].numval), "_Args");
	Sociaty_RoleAssignArray(i, &(yyvsp[0].arr));
	StringIntArray_DisposeSub(&(yyvsp[0].arr));
	(yyval.numval) = (yyvsp[-1].numval);
}
#line 1750 "Parser.c" /* yacc.c:1661  */
    break;

  case 48:
#line 349 "Parser.y" /* yacc.c:1661  */
    {
	int i;
	yd_print("EVAL ARGS");
  i = Sociaty_RoleAddSubordinate((yyvsp[-3].numval), "_Args");
  Sociaty_RoleAssignArray(i, &(yyvsp[-1].arr));
	StringIntArray_DisposeSub(&(yyvsp[-1].arr));
//  IndexArray_PassBySymbol(&Sociaty_GetRole($1)->Args, &$3);
	(yyval.numval) = (yyvsp[-3].numval);
}
#line 1764 "Parser.c" /* yacc.c:1661  */
    break;

  case 49:
#line 360 "Parser.y" /* yacc.c:1661  */
    {
	Role *r = Sociaty_GetRole((yyvsp[0].numval));
  (yyval.strval) = EvalString(r, GetDymValue(r->_Name),0);
//	printf("\nxxxxxxxx%s\t%s\neeeeee\n", r->_Name, $$);
}
#line 1774 "Parser.c" /* yacc.c:1661  */
    break;

  case 50:
#line 365 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.strval) = (yyvsp[0].strval);
}
#line 1782 "Parser.c" /* yacc.c:1661  */
    break;

  case 51:
#line 369 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("VALUE");
  char pi;
	pi = Sociaty_SearchRole((yyvsp[0].strval));
//  yd_print(rtn);
  (yyval.strval) = Sociaty_GetRole(pi)->_Value;
}
#line 1794 "Parser.c" /* yacc.c:1661  */
    break;

  case 52:
#line 377 "Parser.y" /* yacc.c:1661  */
    {
	char* fpath;
  FILE *fp;
  fpath=GetPath((yyvsp[0].strval));
  if(fpath == NULL){
		(yyval.strval) = "";
  }

  fp = fopen(fpath, "r");
  (yyval.strval) = ereadfile(fp);
}
#line 1810 "Parser.c" /* yacc.c:1661  */
    break;

  case 53:
#line 390 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = (yyvsp[0].numval);
}
#line 1818 "Parser.c" /* yacc.c:1661  */
    break;

  case 54:
#line 393 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = Sociaty_AddConstRole((yyvsp[0].strval));
}
#line 1826 "Parser.c" /* yacc.c:1661  */
    break;

  case 55:
#line 398 "Parser.y" /* yacc.c:1661  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1832 "Parser.c" /* yacc.c:1661  */
    break;

  case 56:
#line 399 "Parser.y" /* yacc.c:1661  */
    {(yyval.strval) = (yyvsp[0].strval); }
#line 1838 "Parser.c" /* yacc.c:1661  */
    break;

  case 57:
#line 403 "Parser.y" /* yacc.c:1661  */
    {
  (yyval.numval) = (yyvsp[0].numval);
}
#line 1846 "Parser.c" /* yacc.c:1661  */
    break;

  case 58:
#line 407 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = Sociaty_AddNewRole((yyvsp[0].strval));	
}
#line 1854 "Parser.c" /* yacc.c:1661  */
    break;

  case 59:
#line 414 "Parser.y" /* yacc.c:1661  */
    {
	int pi;
  pi = Sociaty_AddNewRole((yyvsp[-2].strval));
	(yyval.numval) = Sociaty_RoleAddSubordinate(pi, (yyvsp[0].strval));
}
#line 1864 "Parser.c" /* yacc.c:1661  */
    break;

  case 60:
#line 420 "Parser.y" /* yacc.c:1661  */
    {
	int pi;
  pi = Sociaty_AddNewRole((yyvsp[-3].strval));
//	printf("xxx%s\n",Sociaty_GetRole(pi)->_Name);
	(yyval.numval) = Sociaty_RoleAddElement(pi, (yyvsp[-1].strval));
//	printf("xxxx%s\n",Sociaty_GetRole($$)->_Name);
}
#line 1876 "Parser.c" /* yacc.c:1661  */
    break;

  case 61:
#line 428 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = Sociaty_RoleAddSubordinate((yyvsp[-2].numval), (yyvsp[0].strval));
}
#line 1884 "Parser.c" /* yacc.c:1661  */
    break;

  case 62:
#line 432 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = Sociaty_RoleAddElement((yyvsp[-3].numval), (yyvsp[-1].strval));
}
#line 1892 "Parser.c" /* yacc.c:1661  */
    break;

  case 63:
#line 439 "Parser.y" /* yacc.c:1661  */
    {	
	(yyval.strint).Str = (yyvsp[0].strval); 
	(yyval.strint).Int = -1;
}
#line 1901 "Parser.c" /* yacc.c:1661  */
    break;

  case 64:
#line 444 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.strint).Str = Sociaty_GetRole((yyvsp[0].numval))->_Value;
	(yyval.strint).Int = (yyvsp[0].numval);
}
#line 1910 "Parser.c" /* yacc.c:1661  */
    break;

  case 65:
#line 451 "Parser.y" /* yacc.c:1661  */
    { 
	StringIntArray_Create(&(yyval.arr)); 
	StringIntArray_Add(&(yyval.arr), (yyvsp[0].strint).Str, (yyvsp[0].strint).Int);
}
#line 1919 "Parser.c" /* yacc.c:1661  */
    break;

  case 66:
#line 455 "Parser.y" /* yacc.c:1661  */
    { 
	(yyval.arr) = (yyvsp[-2].arr); 
	StringIntArray_Add(&(yyval.arr), (yyvsp[0].strint).Str, (yyvsp[0].strint).Int); 
}
#line 1928 "Parser.c" /* yacc.c:1661  */
    break;


#line 1932 "Parser.c" /* yacc.c:1661  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval, scanner);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 461 "Parser.y" /* yacc.c:1906  */


	//void ParseExpressionFromString(Expression *expr, char *str){
void ParseExpressionFromFp(FILE *fp){
	char *content;
	content = ereadfile(fp);
	estraddeol(&content);
	ParseExpressionFromString(content);
//	free(fpath);
}
void ParseExpressionFromFile(char *fpath){
  char *content;
  FILE *ifp;
  if(fpath[0]){
    if((ifp=fopen(fpath,"r")) != NULL){
			ParseExpressionFromFp(ifp);
		}
		else{
			eerror("file not exist");
			exit(1);
		}
  }
  else{
    eerror("file not exist");
    exit(1);
  }
	fclose(ifp);
//  free(fpath);
}

void ParseExpressionFromString(char *str){
//	printf("\nParseExpressionFromString\n=====\n%s\n=====\n\n", str);
  yyscan_t scanner;
	current_scanner = scanner;
  YY_BUFFER_STATE state;
	if (yylex_init(&scanner)) {
    // couldn't initialize
		eerror("yylex_init failed");
    return;
  }
	state = yy_scan_string(str, scanner);
//	if (yyparse(&expr, scanner)) {
	if (yyparse(scanner)){
    // error parsing
		eerror("yyparse failed");
    exit(1);
  }
	yy_delete_buffer(state, scanner);
	yylex_destroy(scanner);
//	free(str);

}
