/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

    #include "main.h"

#line 70 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_IGNORE = 258,
    T_IDENTIFIER = 259,
    T_DOUBLE = 260,
    T_INTEGER = 261,
    T_EQ = 262,
    T_NEQ = 263,
    T_GTE = 264,
    T_GT = 265,
    T_LTE = 266,
    T_LT = 267,
    T_ASSIGNMENT = 268,
    T_LPAR = 269,
    T_RPAR = 270,
    T_DOT = 271,
    T_COMMA = 272,
    T_COLON = 273,
    T_SEMICOLON = 274,
    T_PLUS = 275,
    T_MINUS = 276,
    T_STAR = 277,
    T_DIV = 278,
    T_AND = 279,
    T_OR = 280,
    T_NOT = 281,
    T_PROGRAM = 282,
    T_BEGIN = 283,
    T_END = 284,
    T_LABEL = 285,
    T_VAR = 286,
    T_FUNCTION = 287,
    T_PROCEDURE = 288,
    T_IF = 289,
    T_THEN = 290,
    T_ELSE = 291,
    T_WHILE = 292,
    T_DO = 293,
    T_GOTO = 294,
    T_READ = 295,
    T_WRITE = 296
  };
#endif
/* Tokens.  */
#define T_IGNORE 258
#define T_IDENTIFIER 259
#define T_DOUBLE 260
#define T_INTEGER 261
#define T_EQ 262
#define T_NEQ 263
#define T_GTE 264
#define T_GT 265
#define T_LTE 266
#define T_LT 267
#define T_ASSIGNMENT 268
#define T_LPAR 269
#define T_RPAR 270
#define T_DOT 271
#define T_COMMA 272
#define T_COLON 273
#define T_SEMICOLON 274
#define T_PLUS 275
#define T_MINUS 276
#define T_STAR 277
#define T_DIV 278
#define T_AND 279
#define T_OR 280
#define T_NOT 281
#define T_PROGRAM 282
#define T_BEGIN 283
#define T_END 284
#define T_LABEL 285
#define T_VAR 286
#define T_FUNCTION 287
#define T_PROCEDURE 288
#define T_IF 289
#define T_THEN 290
#define T_ELSE 291
#define T_WHILE 292
#define T_DO 293
#define T_GOTO 294
#define T_READ 295
#define T_WRITE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 7 "parser.y" /* yacc.c:355  */

    char str[TOKEN_SIZE];

#line 196 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 213 "parser.c" /* yacc.c:358  */

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    71,    96,    97,   103,   125,   101,   139,
     140,   144,   145,   149,   159,   160,   164,   165,   169,   173,
     180,   181,   185,   198,   199,   203,   207,   214,   215,   219,
     223,   224,   228,   235,   239,   240,   245,   252,   275,   276,
     280,   286,   295,   299,   300,   304,   305,   309,   314,   313,
     333,   334,   335,   336,   337,   338,   339,   340,   344,   368,
     383,   382,   413,   428,   432,   433,   437,   437,   453,   457,
     458,   462,   472,   486,   485,   532,   560,   577,   559,   615,
     622,   621,   631,   632,   651,   652,   672,   673,   693,   755,
     756,   767,   768,   787,   788,   789,   793,   794,   795,   799,
     800,   801,   802,   803,   804
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_IGNORE", "T_IDENTIFIER", "T_DOUBLE",
  "T_INTEGER", "T_EQ", "T_NEQ", "T_GTE", "T_GT", "T_LTE", "T_LT",
  "T_ASSIGNMENT", "T_LPAR", "T_RPAR", "T_DOT", "T_COMMA", "T_COLON",
  "T_SEMICOLON", "T_PLUS", "T_MINUS", "T_STAR", "T_DIV", "T_AND", "T_OR",
  "T_NOT", "T_PROGRAM", "T_BEGIN", "T_END", "T_LABEL", "T_VAR",
  "T_FUNCTION", "T_PROCEDURE", "T_IF", "T_THEN", "T_ELSE", "T_WHILE",
  "T_DO", "T_GOTO", "T_READ", "T_WRITE", "$accept", "program", "$@1",
  "list_ignore", "block", "$@2", "$@3", "label_declaration_part",
  "label_list", "label_identifier", "variable_declaration_part",
  "variable_declaration_list", "variable_declaration", "variable_list",
  "variable_var", "routine_declaration_part", "routine_declaration_list",
  "routine_declaration", "procedure_declaration", "procedure_heading",
  "procedure_identification", "function_declaration", "function_heading",
  "function_identification", "formal_parameter_section",
  "formal_parameter_list", "formal_parameter", "statement_part",
  "statement_list", "statements", "statement", "$@4", "statement_nolabel",
  "assignment", "call_noparams", "call", "$@5", "goto", "read",
  "read_expression_list", "read_expression", "$@6", "write",
  "write_expression_list", "write_expression", "condition", "$@7",
  "condition_if", "while", "$@8", "$@9", "expression_list", "$@10",
  "expression", "simple_expression", "term", "factor", "addop", "mulop",
  "relop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -108

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-108)))

#define YYTABLE_NINF -61

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -23,     4,    13,  -108,  -108,    12,    34,    57,    63,    34,
      58,  -108,    49,    74,    67,    53,  -108,    45,  -108,  -108,
       1,  -108,    74,  -108,  -108,    81,    68,  -108,    70,    72,
      24,  -108,    73,     1,    86,    81,    88,    89,  -108,    75,
    -108,  -108,    76,    82,  -108,    78,    -3,    94,  -108,  -108,
    -108,  -108,  -108,    77,    24,    49,     2,  -108,    49,    96,
      83,  -108,    14,  -108,  -108,  -108,    84,   100,    92,    90,
    -108,  -108,   104,    11,     8,  -108,   105,    98,    99,   -10,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,     3,
    -108,   106,    97,  -108,     2,  -108,     8,  -108,   102,   103,
    -108,     8,     8,  -108,    79,    61,    23,  -108,     8,  -108,
    -108,     8,    14,  -108,  -108,    85,  -108,  -108,   114,  -108,
    -108,    26,     8,   107,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,     8,     8,  -108,  -108,  -108,
       8,    87,   108,   109,   115,   112,   111,  -108,  -108,  -108,
    -108,    62,  -108,   116,   113,  -108,    23,    -4,  -108,  -108,
    -108,  -108,  -108,  -108,     8,     3,  -108,  -108,     3,  -108,
    -108,  -108,     8,  -108,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     0,     4,     0,     0,
       0,     5,     9,     0,     0,    14,    13,     0,    11,     3,
       0,     6,     0,    10,    22,     0,     0,    16,     0,    20,
      23,    12,     0,    15,     0,     0,     0,     0,     7,     0,
      25,    27,     0,    30,    28,     0,     0,     0,    17,    19,
      21,    36,    32,     0,    24,     9,     0,    31,     9,     0,
       0,    18,     0,     8,    26,    29,     0,     0,     0,    38,
      33,    34,     0,    59,     0,    76,     0,     0,     0,     0,
      43,    47,    50,    51,    52,    53,    54,    55,    56,     0,
      57,     0,     0,    37,     0,    35,     0,    48,     0,    88,
      90,     0,     0,    89,     0,    82,    84,    86,     0,    62,
      66,     0,     0,    42,    46,    72,    45,    40,     0,    39,
      58,     0,     0,     0,    92,    75,    99,   100,   104,   102,
     103,   101,    93,    94,    95,     0,     0,    96,    97,    98,
       0,     0,     0,    64,     0,     0,    69,    71,    44,    73,
      41,    59,    49,     0,    79,    91,    85,    83,    87,    77,
      63,    66,    67,    68,     0,     0,    61,    80,     0,    65,
      70,    74,     0,    78,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -108,  -108,  -108,   120,   -19,  -108,  -108,  -108,  -108,   110,
    -108,  -108,    91,   -15,  -108,  -108,  -108,    66,  -108,  -108,
    -108,  -108,  -108,  -108,    93,    39,  -108,    95,  -108,  -107,
     -60,  -108,    15,  -108,  -108,   -62,  -108,  -108,  -108,   -27,
    -108,  -108,  -108,   -29,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,   -35,  -108,   -73,     5,     7,   -99,  -108,  -108,  -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     8,    14,    30,    53,    15,    17,    18,
      21,    26,    27,    28,    29,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    57,    68,    69,   114,    79,   115,
     116,   121,    81,    82,    83,   103,    98,    85,    86,   142,
     143,   144,    87,   145,   146,    88,   165,    89,    90,   108,
     168,   153,   172,   147,   105,   106,   107,   135,   140,   136
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      84,   104,    80,   124,     1,    24,    66,    73,     3,   112,
      32,    56,    99,     4,   100,    59,   132,   133,    73,   113,
      50,   134,   101,   120,    96,   -60,     6,    84,   123,    97,
     151,    62,    25,    67,   102,   141,    65,    74,     7,    70,
      75,   158,    76,    77,    78,   137,   138,   139,    74,   154,
      84,    75,   148,    76,    77,    78,    36,    37,   171,    84,
      74,   173,    22,    75,    23,    76,    77,    78,   126,   127,
     128,   129,   130,   131,     9,    96,   -60,    12,    10,    13,
      16,   132,   133,    19,    20,    24,   134,    33,    34,    35,
      49,    47,    51,    52,    54,    55,    56,    58,    61,   154,
      71,    72,    91,    84,    92,    62,    84,    93,    95,    94,
     117,   109,   110,   111,   125,   118,   122,   -60,   150,   162,
      64,   149,   155,   160,    48,   159,   161,   163,   164,    11,
     167,   166,    31,   119,   169,   170,   152,   174,     0,    60,
       0,   157,   156,     0,     0,     0,     0,     0,    63
};

static const yytype_int16 yycheck[] =
{
      62,    74,    62,   102,    27,     4,     4,     4,     4,    19,
      25,    14,     4,     0,     6,    18,    20,    21,     4,    29,
      35,    25,    14,    96,    13,    14,    14,    89,   101,    18,
       4,    28,    31,    31,    26,   108,    55,    34,     4,    58,
      37,   140,    39,    40,    41,    22,    23,    24,    34,   122,
     112,    37,   112,    39,    40,    41,    32,    33,   165,   121,
      34,   168,    17,    37,    19,    39,    40,    41,     7,     8,
       9,    10,    11,    12,    17,    13,    14,    19,    15,    30,
       6,    20,    21,    16,    31,     4,    25,    19,    18,    17,
       4,    18,     4,     4,    19,    19,    14,    19,     4,   172,
       4,    18,    18,   165,     4,    28,   168,    15,     4,    19,
       4,     6,    14,    14,    35,    18,    14,    14,     4,     4,
      54,    36,    15,    15,    33,    38,    17,    15,    17,     9,
      17,    15,    22,    94,   161,   164,   121,   172,    -1,    46,
      -1,   136,   135,    -1,    -1,    -1,    -1,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    43,     4,     0,    44,    14,     4,    45,    17,
      15,    45,    19,    30,    46,    49,     6,    50,    51,    16,
      31,    52,    17,    19,     4,    31,    53,    54,    55,    56,
      47,    51,    55,    19,    18,    17,    32,    33,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    18,    54,     4,
      55,     4,     4,    48,    19,    19,    14,    66,    19,    18,
      66,     4,    28,    69,    59,    46,     4,    31,    67,    68,
      46,     4,    18,     4,    34,    37,    39,    40,    41,    70,
      72,    74,    75,    76,    77,    79,    80,    84,    87,    89,
      90,    18,     4,    15,    19,     4,    13,    18,    78,     4,
       6,    14,    26,    77,    95,    96,    97,    98,    91,     6,
      14,    14,    19,    29,    69,    71,    72,     4,    18,    67,
      95,    73,    14,    95,    98,    35,     7,     8,     9,    10,
      11,    12,    20,    21,    25,    99,   101,    22,    23,    24,
     100,    95,    81,    82,    83,    85,    86,    95,    72,    36,
       4,     4,    74,    93,    95,    15,    97,    96,    98,    38,
      15,    17,     4,    15,    17,    88,    15,    17,    92,    81,
      85,    71,    94,    71,    93
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    44,    43,    45,    45,    47,    48,    46,    49,
      49,    50,    50,    51,    52,    52,    53,    53,    54,    54,
      55,    55,    56,    57,    57,    58,    58,    59,    59,    60,
      61,    61,    62,    63,    64,    64,    65,    66,    67,    67,
      68,    68,    69,    70,    70,    71,    71,    72,    73,    72,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    76,
      78,    77,    79,    80,    81,    81,    83,    82,    84,    85,
      85,    86,    87,    88,    87,    89,    91,    92,    90,    93,
      94,    93,    95,    95,    96,    96,    97,    97,    98,    98,
      98,    98,    98,    99,    99,    99,   100,   100,   100,   101,
     101,   101,   101,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     1,     3,     0,     0,     6,     0,
       3,     1,     3,     1,     0,     3,     1,     3,     4,     3,
       1,     3,     1,     0,     2,     1,     3,     1,     1,     3,
       1,     2,     2,     3,     3,     4,     2,     3,     1,     3,
       3,     4,     3,     1,     3,     1,     1,     1,     0,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     5,     2,     4,     1,     3,     0,     2,     4,     1,
       3,     1,     2,     0,     5,     3,     0,     0,     6,     1,
       0,     4,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
      yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
      yychar = yylex ();
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
#line 72 "parser.y" /* yacc.c:1646  */
    {
        node_push (symbol, (yyvsp[0].str), "main",
            CAT_PROGRAM_ID, TYPE_CONTROL,
            NO_LEVEL, NO_LOCATION, NO_LABEL);

        print_line ("INPP", "", "", 1);

    }
#line 1432 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "parser.y" /* yacc.c:1646  */
    {
        node p = node_pop (symbol);
        while (p->category != CAT_PROGRAM_ID)
            p = node_pop (symbol);

        char* dmem_param = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (dmem_param, "%d", p->mem_count);

        print_line ("DMEM", dmem_param, "", 1);
        print_line ("PARA", "", "end.", 1);
    }
#line 1448 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 103 "parser.y" /* yacc.c:1646  */
    {
        /*
         * Marca o rÃ³tulo de inÃ­cio do procedimento
         * apÃ³s identificar a seÃ§Ã£o de variÃ¡veis.
         */

        ctrl->label_count++;

        char* label_id = malloc (sizeof(char) * TOKEN_SIZE);
        char* label_comment = malloc (sizeof(char) * TOKEN_SIZE);

        sprintf (label_id, "R%02d", ctrl->label_count);
        if (ctrl->label_count == 1)
            sprintf(label_comment, "main");

        node_push (label, label_id, label_comment,
            CAT_LABEL, TYPE_CONTROL,
            ctrl->level, ctrl->location, ctrl->label_count);

        print_line ("DSVS", label_id, "", 1);
    }
#line 1474 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 125 "parser.y" /* yacc.c:1646  */
    {
        /*
         * Exibe o rÃ³tulo do programa principal quando
         * todas as rotinas tiverem sido declaradas.
         */

        node p = node_pop (label);
        char* label_nada = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_nada, "R%02d: NADA", p->label);
        print_line (label_nada, "", p->value, 0);
    }
#line 1490 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 150 "parser.y" /* yacc.c:1646  */
    {
        ctrl->label_count++;

        node_push (symbol, (yyvsp[0].str), "",
            CAT_STMTLABEL, TYPE_CONTROL,
            ctrl->level, NO_LOCATION, ctrl->label_count);
    }
#line 1502 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 170 "parser.y" /* yacc.c:1646  */
    {
        parser_update_params ((yyvsp[0].str));
    }
#line 1510 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 174 "parser.y" /* yacc.c:1646  */
    {
        parser_update_params ((yyvsp[0].str));
    }
#line 1518 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 186 "parser.y" /* yacc.c:1646  */
    {
        /*
         * Adiciona variÃ¡vel na tabela de sÃ­mbolos.
         */
        node_push (symbol, (yyvsp[0].str), "",
            CAT_VARIABLE, TYPE_UNDEFINED,
            ctrl->level, ctrl->location, NO_LABEL);

        ctrl->location++;
    }
#line 1533 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 204 "parser.y" /* yacc.c:1646  */
    {
        parser_routine_declaration ();
    }
#line 1541 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 208 "parser.y" /* yacc.c:1646  */
    {
        parser_routine_declaration ();
    }
#line 1549 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 229 "parser.y" /* yacc.c:1646  */
    {
        parser_routine_identification (CAT_PROCEDURE, (yyvsp[0].str));
    }
#line 1557 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 246 "parser.y" /* yacc.c:1646  */
    {
        parser_routine_identification (CAT_FUNCTION, (yyvsp[0].str));
    }
#line 1565 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 253 "parser.y" /* yacc.c:1646  */
    {
        int c = -4;
        node p = node_get_tail (symbol);
        node q = p;

        while (1) {
            if (p->location == NO_LOCATION)
                p->location = c;

            q = p->prev;
            if (q->location != NO_LOCATION)
                break;

            c--;
            p = q;
        }

        p->param_count = (p->location + 4) * -1;
    }
#line 1589 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 281 "parser.y" /* yacc.c:1646  */
    {
        node_push (symbol, (yyvsp[-2].str), "",
            CAT_PARAM, type_strtoint ((yyvsp[0].str)),
            ctrl->level, NO_LOCATION, NO_LABEL);
    }
#line 1599 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 287 "parser.y" /* yacc.c:1646  */
    {
        node_push (symbol, (yyvsp[-2].str), "",
            CAT_PARAMREF, type_strtoint ((yyvsp[0].str)),
            ctrl->level, NO_LOCATION, NO_LABEL);
    }
#line 1609 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 310 "parser.y" /* yacc.c:1646  */
    {
        dump_statements();
    }
#line 1617 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 314 "parser.y" /* yacc.c:1646  */
    {
        node p = node_get (symbol, (yyvsp[-1].str));
        node r = node_get_routine ();

        char* label = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label, "R%02d: ENRT %d, %d",
            p->label, p->level, r->mem_count);

        node_push (stmt, get_line (label, "", (yyvsp[-1].str), 0), "",
            CAT_STATEMENT, TYPE_CONTROL,
            NO_LEVEL, NO_LOCATION, NO_LABEL);
    }
#line 1634 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 327 "parser.y" /* yacc.c:1646  */
    {
        dump_statements();
    }
#line 1642 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 345 "parser.y" /* yacc.c:1646  */
    {
        char* mode = malloc (sizeof(char) * TOKEN_SIZE);
        char* comment = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf(comment, "%s :=", (yyvsp[-2].str));
        node p = node_get (symbol, (yyvsp[-2].str));

        node e = node_pop (type);
        if (e->type == TYPE_BOOLEAN)
            yyerror ("atribuição inválida.");

        if (p->category == CAT_PARAMREF)
            strcpy (mode, "ARMI");
        else
            strcpy (mode, "ARMZ");

        node_push (stmt,
            get_line (mode, node_get_pos (symbol, (yyvsp[-2].str)), comment, 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1667 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 369 "parser.y" /* yacc.c:1646  */
    {
        node p = node_get (symbol, (yyvsp[0].str));

        char* param = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (param, "%s, %d", p->value, ctrl->level);

        node_push (stmt, get_line ("CHPR", param, (yyvsp[0].str), 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1682 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 383 "parser.y" /* yacc.c:1646  */
    {
        node_push (call, (yyvsp[0].str), "",
            CAT_CALL, TYPE_CONTROL,
            NO_LEVEL, NO_LOCATION, 1);

        node p = node_get (symbol, (yyvsp[0].str));
        if (p->category == CAT_FUNCTION) {
            node_push (stmt,
                get_line ("AMEM", "1", "", 1), "",
                CAT_STATEMENT, TYPE_CONTROL,
                ctrl->level, ctrl->location, NO_LABEL);
        }

    }
#line 1701 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 398 "parser.y" /* yacc.c:1646  */
    {
        node p = node_pop (call);
        p = node_get (symbol, p->token_id);

        char* param = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (param, "%s, %d", p->value, ctrl->level);

        node_push (stmt,
            get_line ("CHPR", param, (yyvsp[-4].str), 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1718 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 414 "parser.y" /* yacc.c:1646  */
    {
        node p = node_get (symbol, (yyvsp[0].str));
        char* label = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label, "R%02d, %d, %d",
            p->label, p->level, ctrl->level);

        node_push (stmt,
            get_line ("DSVR", label, (yyvsp[0].str), 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1734 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 437 "parser.y" /* yacc.c:1646  */
    {
        node_push (stmt,
            get_line ("LEIT", "", "read", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1745 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 444 "parser.y" /* yacc.c:1646  */
    {
        node_push (stmt,
            get_line ("ARMZ", node_get_pos (symbol, (yyvsp[0].str)), (yyvsp[0].str), 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1756 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 463 "parser.y" /* yacc.c:1646  */
    {
        node_push (stmt,
            get_line ("IMPR", "", "write", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1767 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 473 "parser.y" /* yacc.c:1646  */
    {
        /* RÃ³tulo de fim da condiÃ§Ã£o. */

        node p = node_pop (label);
        char* label_nada = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_nada, "R%02d: NADA", p->label);

        node_push (stmt,
            get_line (label_nada, "", "", 0), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1784 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 486 "parser.y" /* yacc.c:1646  */
    {
        /* Final do if com else. */

        ctrl->label_count++;

        node p_else = node_pop (label);

        /* Desvio para novo rÃ³tulo de fim do else. */

        char* label_id = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_id, "R%02d", ctrl->label_count);

        node_push (label, label_id, "",
            CAT_LABEL, TYPE_CONTROL,
            ctrl->level, ctrl->location, ctrl->label_count);

        node_push (stmt,
            get_line ("DSVS", label_id, "", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);

        /* RÃ³tulo de inÃ­cio do else. */

        char* label_nada = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_nada, "R%02d: NADA", p_else->label);

        node_push (stmt,
            get_line (label_nada, "", "else", 0), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);

    }
#line 1821 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 519 "parser.y" /* yacc.c:1646  */
    {
        node p = node_pop (label);
        char* label_nada = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_nada, "R%02d: NADA", p->label);

        node_push (stmt,
            get_line (label_nada, "", "", 0), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1836 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 533 "parser.y" /* yacc.c:1646  */
    {
        node p = node_pop (type);
        if (p->type != TYPE_BOOLEAN)
            yyerror ("expressão em if não é booleana.");

        /*
         * Testa condiÃ§Ã£o e marca o rÃ³tulo de inÃ­cio do else
         * ou do fim do if.
         */
        ctrl->label_count++;

        char* label_id = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_id, "R%02d", ctrl->label_count);

        node_push (label, label_id, "",
            CAT_LABEL, TYPE_CONTROL,
            ctrl->level, ctrl->location, ctrl->label_count);

        node_push (stmt,
            get_line ("DSVF", label_id, "if", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1864 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 560 "parser.y" /* yacc.c:1646  */
    {
        char* label_id = malloc (sizeof(char) * TOKEN_SIZE);
        char* label_nada = malloc (sizeof(char) * TOKEN_SIZE);

        sprintf (label_id, "R%02d", ++ctrl->label_count);
        sprintf (label_nada, "R%02d: NADA", ctrl->label_count);

        node_push (label, label_id, "",
            CAT_LABEL, TYPE_CONTROL,
            ctrl->level, ctrl->location, ctrl->label_count);

        node_push (stmt,
            get_line (label_nada, "", "while", 0), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1885 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 577 "parser.y" /* yacc.c:1646  */
    {
        node p = node_pop (type);
        if (p->type != TYPE_BOOLEAN)
            yyerror ("expressÃ£o em while nÃ£o Ã© booleana.");

        char* label_id = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_id, "R%02d", ++ctrl->label_count);

        node_push (label, label_id, "",
            CAT_LABEL, TYPE_CONTROL,
            ctrl->level, ctrl->location, ctrl->label_count);

        node_push (stmt,
            get_line ("DSVF", label_id, "do", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1907 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 595 "parser.y" /* yacc.c:1646  */
    {
        node p_endwhile = node_pop (label);
        node p_while = node_pop (label);

        char* label_nada = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_nada, "R%02d: NADA", p_endwhile->label);

        node_push (stmt,
            get_line ("DSVS", p_while->token_id, "", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);

        node_push (stmt,
            get_line (label_nada, "", "endwhile", 0), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1929 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 616 "parser.y" /* yacc.c:1646  */
    {
        node c = node_get_tail (call);
        if (strlen (c->token_id))
            c->label++;
    }
#line 1939 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 622 "parser.y" /* yacc.c:1646  */
    {
        node c = node_get_tail (call);
        if (strlen (c->token_id))
            c->label++;
    }
#line 1949 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 633 "parser.y" /* yacc.c:1646  */
    {
        node p = node_pop (type);
        node q = node_pop (type);

        if (p->type != q->type)
            yyerror ("comparação relop entre tipos inválidos.");

        node_push (type, p->token_id, "",
            CAT_TYPE, TYPE_BOOLEAN,
            ctrl->level, ctrl->location, NO_LABEL);

        node_push (stmt, (yyvsp[-1].str), "",
            CAT_STATEMENT, TYPE_BOOLEAN,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1969 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 653 "parser.y" /* yacc.c:1646  */
    {
        node p = node_pop (type);
        node q = node_pop (type);

        if (p->type != TYPE_INTEGER ||
            q->type != TYPE_INTEGER)
            yyerror ("addop entre tipos inválidos.");

        node_push (type, p->token_id, "",
            CAT_TYPE, TYPE_INTEGER,
            ctrl->level, ctrl->location, NO_LABEL);

        node_push (stmt, (yyvsp[-1].str), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 1990 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 674 "parser.y" /* yacc.c:1646  */
    {
        node p = node_pop (type);
        node q = node_pop (type);

        if (p->type != TYPE_INTEGER ||
            q->type != TYPE_INTEGER)
            yyerror ("mulop entre tipos inválidos.");

        node_push (type, p->token_id, "",
            CAT_TYPE, TYPE_INTEGER,
            ctrl->level, ctrl->location, NO_LABEL);

        node_push (stmt, (yyvsp[-1].str), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 2011 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 694 "parser.y" /* yacc.c:1646  */
    {
        int i = 0;
        char* s = malloc (sizeof(char) * TOKEN_SIZE);

        node p = node_get (symbol, (yyvsp[0].str));
        node c = node_get_tail (call);

        node_push (type, p->token_id, "",
            CAT_TYPE, p->type,
            ctrl->level, ctrl->location, NO_LABEL);

        /* Ã‰ um chamado sem parÃ¢metros. */

        if (p->category == CAT_FUNCTION
            || p->category == CAT_PROCEDURE) {

            char* param = malloc (sizeof(char) * TOKEN_SIZE);
            sprintf (param, "%s, %d", p->value, ctrl->level);
            strcpy (s, get_line ("CHPR", param, (yyvsp[0].str), 1));

        /* Ã‰ variÃ¡vel passada por referÃªncia. */

        } else if (p->category == CAT_PARAMREF) {

            node q = node_get (symbol, c->token_id);
            while (i < c->label) {
                if (q->next)
                    q = q->next;
                i++;
            }

            if (q->category != CAT_PARAMREF)
                strcpy (s, get_line ("CRVI",
                    node_get_pos (symbol, (yyvsp[0].str)), (yyvsp[0].str), 1));

        /* Ã‰ um parÃ¢metro de chamado. */

        } else if (strlen (c->token_id)) {

            p = node_get (symbol, c->token_id);
            while (i < c->label) {
                if (p->next)
                    p = p->next;
                i++;
            }

            if (p->category == CAT_PARAMREF)
                strcpy (s, get_line ("CREN",
                    node_get_pos (symbol, (yyvsp[0].str)), (yyvsp[0].str), 1));

        }

        if (!strlen (s) )
            strcpy (s, get_line ("CRVL",
                node_get_pos (symbol, (yyvsp[0].str)), (yyvsp[0].str), 1));

        node_push (stmt, s, "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);

    }
#line 2077 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 757 "parser.y" /* yacc.c:1646  */
    {
        node_push (type, (yyvsp[0].str), "",
            CAT_TYPE, TYPE_INTEGER,
            ctrl->level, ctrl->location, NO_LABEL);

        node_push (stmt,
            get_line("CRCT", (yyvsp[0].str), (yyvsp[0].str), 1), (yyvsp[0].str),
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 2092 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 769 "parser.y" /* yacc.c:1646  */
    {
        node p = node_pop (type);

        if (p->type != TYPE_BOOLEAN)
            yyerror ("not em tipo inválido.");

        node_push (type, p->token_id, "",
            CAT_TYPE, TYPE_BOOLEAN,
            ctrl->level, ctrl->location, NO_LABEL);

        node_push (stmt,
            get_line("NEGA", "", "not", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
#line 2112 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 787 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.str), get_line("SOMA", "", "", 1)); }
#line 2118 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 788 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.str), get_line("SUBT", "", "", 1)); }
#line 2124 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 789 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.str), get_line("DISJ", "", "", 1)); }
#line 2130 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 793 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.str), get_line("MULT", "", "", 1)); }
#line 2136 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 794 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.str), get_line("DIVI", "", "", 1)); }
#line 2142 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 795 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.str), get_line("CONJ", "", "", 1)); }
#line 2148 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 799 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.str), get_line("CMIG", "", "", 1)); }
#line 2154 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 800 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.str), get_line("CMDG", "", "", 1)); }
#line 2160 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 801 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.str), get_line("CMME", "", "", 1)); }
#line 2166 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 802 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.str), get_line("CMMA", "", "", 1)); }
#line 2172 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 803 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.str), get_line("CMEG", "", "", 1)); }
#line 2178 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 804 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.str), get_line("CMAG", "", "", 1)); }
#line 2184 "parser.c" /* yacc.c:1646  */
    break;


#line 2188 "parser.c" /* yacc.c:1646  */
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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
                      yytoken, &yylval);
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
                  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 807 "parser.y" /* yacc.c:1906  */


void yyerror (const char *msg) {
    fprintf(stderr, "\nErro linha %d: %s\n", yyget_lineno(), msg);
}

int main (int argc, char** argv) {

    FILE* fp;
    extern FILE* yyin;

    init();

    ctrl->print_comments = 0;

    if (argc<2 || argc>2) {
          printf("usage compilador <arq>a %d\n", argc);
          return(-1);
       }

    fp=fopen (argv[1], "r");
    if (fp == NULL) {
       printf("usage compilador <arq>b\n");
       return(-1);
    }

    yyin = fp;
    yyparse();

    return 0;
}
