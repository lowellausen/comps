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

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"

extern int lineCount;


#define   SYMBOL_UNDEFINED  	0 
#define   SYMBOL_LIT_INTEGER  	1 
#define   SYMBOL_LIT_REAL 	2 
#define   SYMBOL_LIT_CHAR   	3 
#define   SYMBOL_LIT_STRING  	4 
#define   SYMBOL_IDENTIFIER  	5 

int list_dataTypes[20];
int list_naturezas[20];
int cont;
int functionDataType;
char tempUm;

void set_error_flag();
int get_error_flag();

void clear_lists();
void put_in_lists(int natureza, int dataType);

void reset_cont();
void inc_cont();
int get_cont();

void define_dataType (int type, HASHNODE *identifier);
ASTREE* define_astree_nature_and_type(ASTREE *node,HASHNODE *element);
ASTREE* define_astree_type(ASTREE *node,HASHNODE *element);
ASTREE* define_astree_nature(ASTREE *node,HASHNODE *element);

void verify_function_declaration (HASHNODE *function);
void verify_function_declared (HASHNODE *function);
void verify_variable_declaration (HASHNODE *variable);
void verify_variable_declared (HASHNODE *variable);
void verify_vector (HASHNODE *vector);
void verify_pointer (HASHNODE *pointer);

int compareHashTreeNatureza (int hashc, int treec);
void compare_lists (int* naturezaHash,int* dataTypesHash,int size);


#line 115 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TK_WHILE = 258,
    TK_CHAR = 259,
    TK_INT = 260,
    TK_FLOAT = 261,
    TK_IF = 262,
    TK_THEN = 263,
    TK_ELSE = 264,
    TK_FOR = 265,
    TK_TO = 266,
    TK_READ = 267,
    TK_RETURN = 268,
    TK_PRINT = 269,
    OPERATOR_LE = 270,
    OPERATOR_GE = 271,
    OPERATOR_EQ = 272,
    OPERATOR_NE = 273,
    OPERATOR_AND = 274,
    OPERATOR_OR = 275,
    TK_IDENTIFIER = 276,
    LIT_INTEGER = 277,
    LIT_REAL = 278,
    LIT_CHAR = 279,
    LIT_STRING = 280,
    TOKEN_ERROR = 281
  };
#endif
/* Tokens.  */
#define TK_WHILE 258
#define TK_CHAR 259
#define TK_INT 260
#define TK_FLOAT 261
#define TK_IF 262
#define TK_THEN 263
#define TK_ELSE 264
#define TK_FOR 265
#define TK_TO 266
#define TK_READ 267
#define TK_RETURN 268
#define TK_PRINT 269
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_NE 273
#define OPERATOR_AND 274
#define OPERATOR_OR 275
#define TK_IDENTIFIER 276
#define LIT_INTEGER 277
#define LIT_REAL 278
#define LIT_CHAR 279
#define LIT_STRING 280
#define TOKEN_ERROR 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 51 "parser.y" /* yacc.c:355  */
HASHNODE *symbol; 
	ASTREE *astree;
	

#line 212 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 229 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   295

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    33,     2,     2,    34,     2,
      41,    42,    31,    29,    43,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    37,
      27,    36,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   138,   139,   140,   141,   143,   147,   151,
     155,   159,   163,   167,   170,   176,   177,   178,   181,   184,
     187,   192,   193,   196,   196,   199,   206,   214,   214,   215,
     218,   218,   219,   222,   224,   225,   228,   229,   230,   231,
     232,   233,   234,   237,   238,   241,   244,   247,   248,   249,
     250,   253,   256,   261,   273,   274,   276,   282,   283,   286,
     336,   386,   401,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   426,   426,   437,   446,   447,   450,   450,   450,
     453,   454,   457,   460
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_WHILE", "TK_CHAR", "TK_INT",
  "TK_FLOAT", "TK_IF", "TK_THEN", "TK_ELSE", "TK_FOR", "TK_TO", "TK_READ",
  "TK_RETURN", "TK_PRINT", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_NE", "OPERATOR_AND", "OPERATOR_OR", "TK_IDENTIFIER",
  "LIT_INTEGER", "LIT_REAL", "LIT_CHAR", "LIT_STRING", "TOKEN_ERROR",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'#'", "'&'", "'!'", "'='",
  "';'", "'['", "']'", "':'", "'('", "')'", "','", "'{'", "'}'", "$accept",
  "program", "code", "var", "var_type", "lit", "lit_list", "func", "$@1",
  "param", "param_list", "$@2", "aux_param_list", "$@3", "block",
  "command_list", "command", "attribution", "read", "print", "print_list",
  "return", "expr", "func_call", "$@4", "call_param_list", "control", "if",
  "while", "for", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    60,    62,    43,
      45,    42,    47,    35,    38,    33,    61,    59,    91,    93,
      58,    40,    41,    44,   123,   125
};
# endif

#define YYPACT_NINF -120

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define YYTABLE_NINF -7

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,  -120,  -120,  -120,  -120,    13,  -120,    74,   -15,    74,
    -120,  -120,    -4,    -1,  -120,     4,    18,  -120,   -19,    48,
      49,    51,    84,    77,    93,  -120,  -120,  -120,   -33,   -12,
    -120,   111,   117,   118,   119,  -120,   127,  -120,   136,   137,
     126,  -120,  -120,  -120,  -120,  -120,  -120,   127,   145,  -120,
      77,  -120,    -2,  -120,  -120,  -120,  -120,   140,   142,   143,
     190,   218,   203,     5,  -120,   167,   178,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,   137,   218,   218,   193,  -120,
      -5,   214,   222,   218,   218,  -120,   245,  -120,   203,  -120,
     144,   218,   218,  -120,    -2,  -120,    76,    82,   187,   218,
     204,  -120,  -120,  -120,   110,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,  -120,  -120,   245,
     171,  -120,    -2,   237,   218,   177,  -120,   218,  -120,    90,
      90,    90,    90,   263,   239,    90,    90,    45,    45,  -120,
    -120,   211,  -120,    -2,   202,  -120,    41,   206,   218,   240,
     218,   218,  -120,   245,    -2,   116,  -120,  -120,    -2,  -120
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,    15,    17,    16,     0,     2,     0,     0,     0,
       1,     3,     0,     0,     4,     0,     0,    23,     0,     0,
       0,     0,     0,    29,     0,     7,     8,     9,     0,     0,
      27,     0,     0,     0,     0,    13,    22,    25,     0,    32,
       0,    12,    11,    10,    18,    19,    20,    22,     0,    26,
       0,    28,    42,    24,    21,    14,    30,     0,     0,     0,
       0,     0,     0,     0,    40,     0,    35,    36,    37,    38,
      39,    41,    77,    78,    79,    32,     0,     0,     0,    45,
      52,     0,     0,     0,     0,    54,    51,    55,    47,    46,
      48,     0,     0,    33,    42,    31,     0,     0,     0,     0,
      72,    56,    57,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,    50,    43,
       0,    34,    42,     0,     0,     0,    74,     0,    58,    66,
      67,    68,    69,    70,    71,    63,    64,    59,    60,    61,
      62,     0,    82,    42,     0,    53,    75,     0,     0,    80,
       0,     0,    73,    44,    42,     0,    76,    81,    42,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,    55,  -120,   -21,   -22,   235,  -120,  -120,   200,
    -120,  -120,   208,  -120,   244,   191,  -119,  -120,  -120,  -120,
     -23,  -120,   -61,  -120,  -120,   135,  -120,  -120,  -120,  -120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    85,    48,     9,    23,    30,
      31,    39,    51,    75,    64,    65,    66,    67,    68,    69,
      89,    70,    90,    87,   127,   147,    71,    72,    73,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      86,    57,    29,   142,    35,    58,    12,    36,    59,    37,
      60,    61,    62,    10,    47,    96,    97,    24,    13,    63,
      18,    38,   103,   104,   149,    47,    19,    20,    21,    29,
     119,   120,    15,    99,    16,   157,   100,    17,   125,   159,
      22,    91,    52,    92,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   105,   106,   107,   108,
     109,   110,    11,   144,    14,   117,   146,   118,   111,   112,
     113,   114,   115,   116,    -6,     1,   115,   116,     2,     3,
       4,     2,     3,     4,   151,    25,    26,   153,    27,   155,
     146,   105,   106,   107,   108,   109,   110,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   111,
     112,   113,   114,   115,   116,    32,    33,    34,   122,   113,
     114,   115,   116,    28,   123,   105,   106,   107,   108,   109,
     110,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   111,   112,   113,   114,   115,   116,    44,
      45,    46,   128,    40,    41,    42,    43,    49,   158,   105,
     106,   107,   108,   109,   110,    80,    44,    45,    46,    88,
      52,   111,   112,   113,   114,   115,   116,    81,    82,    83,
      50,    76,    55,    77,    78,    84,   105,   106,   107,   108,
     109,   110,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   111,   112,   113,   114,   115,   116,
     141,    79,    93,   150,    98,    94,   145,   105,   106,   107,
     108,   109,   110,   124,    80,    44,    45,    46,    88,   111,
     112,   113,   114,   115,   116,   101,    81,    82,    83,    80,
      44,    45,    46,   102,    84,   143,   126,   148,   152,   154,
      56,    81,    82,    83,   105,   106,   107,   108,   109,    84,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   111,   112,   113,   114,   115,   116,   105,   106,
     107,   108,    54,    95,    53,   121,   156,     0,     0,     0,
     111,   112,   113,   114,   115,   116
};

static const yytype_int16 yycheck[] =
{
      61,     3,    23,   122,    37,     7,    21,    40,    10,    21,
      12,    13,    14,     0,    36,    76,    77,    36,    33,    21,
      21,    33,    83,    84,   143,    47,    22,    23,    24,    50,
      91,    92,    36,    38,    38,   154,    41,    41,    99,   158,
      22,    36,    44,    38,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    15,    16,    17,    18,
      19,    20,     7,   124,     9,    88,   127,    90,    27,    28,
      29,    30,    31,    32,     0,     1,    31,    32,     4,     5,
       6,     4,     5,     6,    43,    37,    37,   148,    37,   150,
     151,    15,    16,    17,    18,    19,    20,    15,    16,    17,
      18,    19,    20,    27,    28,    29,    30,    31,    32,    27,
      28,    29,    30,    31,    32,    22,    23,    24,    42,    29,
      30,    31,    32,    39,    42,    15,    16,    17,    18,    19,
      20,    15,    16,    17,    18,    19,    20,    27,    28,    29,
      30,    31,    32,    27,    28,    29,    30,    31,    32,    22,
      23,    24,    42,    42,    37,    37,    37,    21,    42,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      44,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      43,    41,    37,    41,    41,    41,    15,    16,    17,    18,
      19,    20,    15,    16,    17,    18,    19,    20,    27,    28,
      29,    30,    31,    32,    27,    28,    29,    30,    31,    32,
      39,    21,    45,    11,    21,    37,    39,    15,    16,    17,
      18,    19,    20,    36,    21,    22,    23,    24,    25,    27,
      28,    29,    30,    31,    32,    21,    33,    34,    35,    21,
      22,    23,    24,    21,    41,     8,    42,    36,    42,     9,
      50,    33,    34,    35,    15,    16,    17,    18,    19,    41,
      15,    16,    17,    18,    19,    20,    27,    28,    29,    30,
      31,    32,    27,    28,    29,    30,    31,    32,    15,    16,
      17,    18,    47,    75,    40,    94,   151,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     6,    47,    48,    49,    50,    53,
       0,    48,    21,    33,    48,    36,    38,    41,    21,    22,
      23,    24,    22,    54,    36,    37,    37,    37,    39,    50,
      55,    56,    22,    23,    24,    37,    40,    21,    33,    57,
      42,    37,    37,    37,    22,    23,    24,    51,    52,    21,
      43,    58,    44,    60,    52,    37,    55,     3,     7,    10,
      12,    13,    14,    21,    60,    61,    62,    63,    64,    65,
      67,    72,    73,    74,    75,    59,    41,    41,    41,    21,
      21,    33,    34,    35,    41,    51,    68,    69,    25,    66,
      68,    36,    38,    45,    37,    58,    68,    68,    21,    38,
      41,    21,    21,    68,    68,    15,    16,    17,    18,    19,
      20,    27,    28,    29,    30,    31,    32,    66,    66,    68,
      68,    61,    42,    42,    36,    68,    42,    70,    42,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    39,    62,     8,    68,    39,    68,    71,    36,    62,
      11,    43,    42,    68,     9,    68,    71,    62,    42,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    48,    49,    49,    49,
      49,    49,    49,    49,    49,    50,    50,    50,    51,    51,
      51,    52,    52,    54,    53,    55,    55,    57,    56,    56,
      59,    58,    58,    60,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    64,    65,    66,    66,    66,
      66,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    70,    69,    69,    71,    71,    72,    72,    72,
      73,    73,    74,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     0,     5,     5,     5,
       6,     6,     6,     6,     8,     1,     1,     1,     1,     1,
       1,     2,     0,     0,     7,     2,     3,     0,     3,     0,
       0,     4,     0,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     6,     2,     2,     1,     1,     2,
       2,     2,     1,     4,     1,     1,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     0,     5,     3,     1,     3,     1,     1,     1,
       6,     8,     5,     9
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
#line 125 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_PROGRAM,(yyvsp[0].astree),0,0,0,0); astreePrintTree((yyval.astree),"",1); 
	if(get_error_flag() == 0)
	     {
	        printf("Programa pertence a linguagem.\n"); 
		exit(0);
	     }
	     else
	     {
	        printf("Erro de semantica\n"); 		
		exit(4);
	     }; 
              }
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_DECL_LIST,(yyvsp[-1].astree),(yyvsp[0].astree),0,0,0);}
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_DECL_LIST,(yyvsp[-1].astree),(yyvsp[0].astree),0,0,0);}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = 0;}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_VAR_DECL,(yyvsp[-4].astree),astreeCreate(ASTREE_LIT,0,0,0,0,(yyvsp[-1].symbol)),0,0,(yyvsp[-3].symbol)); 
			(yyvsp[-3].symbol)->natureza = NATUREZA_ESCALAR;
			define_dataType ((yyvsp[-4].astree)->type, (yyvsp[-3].symbol));
			verify_variable_declaration ((yyvsp[-3].symbol));}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_VAR_DECL,(yyvsp[-4].astree),astreeCreate(ASTREE_LIT,0,0,0,0,(yyvsp[-1].symbol)),0,0,(yyvsp[-3].symbol)); 
			(yyvsp[-3].symbol)->natureza = NATUREZA_ESCALAR;
			define_dataType ((yyvsp[-4].astree)->type, (yyvsp[-3].symbol));
			verify_variable_declaration ((yyvsp[-3].symbol));}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_VAR_DECL,(yyvsp[-4].astree),astreeCreate(ASTREE_LIT,0,0,0,0,(yyvsp[-1].symbol)),0,0,(yyvsp[-3].symbol));
			(yyvsp[-3].symbol)->natureza = NATUREZA_ESCALAR;
			define_dataType ((yyvsp[-4].astree)->type, (yyvsp[-3].symbol));
			verify_variable_declaration ((yyvsp[-3].symbol)); }
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_POINT_DECL,(yyvsp[-5].astree),astreeCreate(ASTREE_LIT,0,0,0,0,(yyvsp[-1].symbol)),0,0,(yyvsp[-3].symbol));
			(yyvsp[-3].symbol)->natureza = NATUREZA_ESCALAR;
			define_dataType ((yyvsp[-5].astree)->type, (yyvsp[-3].symbol));
			verify_variable_declaration ((yyvsp[-3].symbol));}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_POINT_DECL,(yyvsp[-5].astree),astreeCreate(ASTREE_LIT,0,0,0,0,(yyvsp[-1].symbol)),0,0,(yyvsp[-3].symbol));
			(yyvsp[-3].symbol)->natureza = NATUREZA_ESCALAR;
			define_dataType ((yyvsp[-5].astree)->type, (yyvsp[-3].symbol));
			verify_variable_declaration ((yyvsp[-3].symbol));}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_POINT_DECL,(yyvsp[-5].astree),astreeCreate(ASTREE_LIT,0,0,0,0,(yyvsp[-1].symbol)),0,0,(yyvsp[-3].symbol));
			(yyvsp[-3].symbol)->natureza = NATUREZA_ESCALAR;
			define_dataType ((yyvsp[-5].astree)->type, (yyvsp[-3].symbol));
			verify_variable_declaration ((yyvsp[-3].symbol));}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_VET_DECL,(yyvsp[-5].astree),astreeCreate(ASTREE_LIT,0,0,0,0,(yyvsp[-2].symbol)),0,0,(yyvsp[-4].symbol)); 			(yyvsp[-4].symbol)->natureza = NATUREZA_VETOR;
			define_dataType((yyvsp[-5].astree)->type, (yyvsp[-4].symbol));
			verify_variable_declaration((yyvsp[-4].symbol));}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 170 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_VET_DECL_INIT,(yyvsp[-7].astree),astreeCreate(ASTREE_LIT,0,0,0,0,(yyvsp[-4].symbol)),(yyvsp[-1].astree),0,(yyvsp[-6].symbol));
			(yyvsp[-6].symbol)->natureza = NATUREZA_VETOR;
			define_dataType((yyvsp[-7].astree)->type, (yyvsp[-6].symbol));
			verify_variable_declaration((yyvsp[-6].symbol));}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_CHAR,0,0,0,0,0); (yyval.astree)->dataType = DATATYPE_ASTREE_CHAR;}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_FLOAT,0,0,0,0,0); (yyval.astree)->dataType = DATATYPE_ASTREE_FLOAT;}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_INT,0,0,0,0,0); (yyval.astree)->dataType = DATATYPE_ASTREE_INTEGER;}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_SYMBOL,0,0,0,0, (yyvsp[0].symbol)); (yyval.astree)->symbol = (yyvsp[0].symbol); 
		(yyval.astree)->natureza = NATUREZA_ASTREE_ESCALAR;
		(yyval.astree)->dataType = DATATYPE_ASTREE_INTEGER;}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_SYMBOL,0,0,0,0, (yyvsp[0].symbol)); (yyval.astree)->symbol = (yyvsp[0].symbol); 
		(yyval.astree)->natureza = NATUREZA_ASTREE_ESCALAR;
		(yyval.astree)->dataType = DATATYPE_ASTREE_FLOAT;}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_SYMBOL,0,0,0,0, (yyvsp[0].symbol)); (yyval.astree)->symbol = (yyvsp[0].symbol); 
		(yyval.astree)->natureza = NATUREZA_ASTREE_ESCALAR;
		(yyval.astree)->dataType = DATATYPE_ASTREE_CHAR;}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 192 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_SYMBOL_LIST,(yyvsp[-1].astree),(yyvsp[0].astree),0,0,0);}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 193 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = 0;}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 196 "parser.y" /* yacc.c:1646  */
    {reset_cont();clear_lists();}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 196 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_FUNC, (yyvsp[-6].astree),(yyvsp[-2].astree),(yyvsp[0].astree),0, (yyvsp[-5].symbol)); }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 199 "parser.y" /* yacc.c:1646  */
    {
		(yyvsp[0].symbol)->natureza = NATUREZA_ESCALAR;
		define_dataType ((yyvsp[-1].astree)->type, (yyvsp[0].symbol));
		verify_variable_declaration ((yyvsp[0].symbol));
		(yyval.astree) = astreeCreate(ASTREE_PARAM, (yyvsp[-1].astree),0,0,0, (yyvsp[0].symbol));
		put_in_lists(NATUREZA_ESCALAR, (yyvsp[0].symbol)->dataType);
	}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 206 "parser.y" /* yacc.c:1646  */
    { 
		(yyvsp[0].symbol)->natureza = NATUREZA_POINTER;
		define_dataType ((yyvsp[-2].astree)->type, (yyvsp[0].symbol));
		verify_variable_declaration ((yyvsp[0].symbol));
		(yyval.astree) = astreeCreate(ASTREE_PARAM,(yyvsp[-2].astree),0,0,0,(yyvsp[0].symbol));
		put_in_lists(NATUREZA_POINTER, (yyvsp[0].symbol)->dataType);
	}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 214 "parser.y" /* yacc.c:1646  */
    {inc_cont();}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_PARAM_LIST, (yyvsp[-2].astree),(yyvsp[0].astree),0,0,0);}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = 0;}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 218 "parser.y" /* yacc.c:1646  */
    {inc_cont();}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 218 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_PARAM_LIST, (yyvsp[-2].astree),(yyvsp[0].astree),0,0,0);}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 219 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = 0;}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_BLOCK,(yyvsp[-1].astree),0,0,0,0);}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 224 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_CMD_LIST, (yyvsp[-2].astree),(yyvsp[0].astree),0,0,0);}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 225 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = (yyvsp[0].astree);}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 228 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = (yyvsp[0].astree);}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 229 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = (yyvsp[0].astree);}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 230 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = (yyvsp[0].astree);}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 231 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = (yyvsp[0].astree);}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 232 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = (yyvsp[0].astree);}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 233 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = (yyvsp[0].astree);}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 234 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = 0;}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 237 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) =  astreeCreate(ASTREE_ASSIGN_VAR, (yyvsp[0].astree), 0, 0, 0, (yyvsp[-2].symbol)); }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 238 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) =  astreeCreate(ASTREE_ASSIGN_VECTOR, (yyvsp[-3].astree), (yyvsp[0].astree), 0, 0, (yyvsp[-5].symbol)); }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 241 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) =  astreeCreate(ASTREE_READ, 0, 0, 0, 0, (yyvsp[0].symbol)); }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) =  astreeCreate(ASTREE_PRINT, (yyvsp[0].astree), 0, 0, 0, 0); }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_SYMBOL,0,0,0,0, (yyvsp[0].symbol)); (yyval.astree)->symbol = (yyvsp[0].symbol); }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_EXP,(yyvsp[0].astree),0,0,0, 0);}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_PRT_LST_ST,(yyvsp[0].astree),0,0,0, (yyvsp[-1].symbol)); (yyval.astree)->symbol = (yyvsp[-1].symbol); }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 250 "parser.y" /* yacc.c:1646  */
    { (yyval.astree) = astreeCreate(ASTREE_PRT_LST,(yyvsp[-1].astree),(yyvsp[0].astree),0,0, 0); }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 253 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_RETURN, (yyvsp[0].astree), 0, 0, 0, 0);}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 256 "parser.y" /* yacc.c:1646  */
    {
			verify_variable_declared ((yyvsp[0].symbol));
			(yyval.astree) = astreeCreate(ASTREE_SYMBOL, 0, 0, 0, 0, (yyvsp[0].symbol)); 
			(yyval.astree) = define_astree_nature_and_type((yyval.astree),(yyvsp[0].symbol));
}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 261 "parser.y" /* yacc.c:1646  */
    {
			verify_vector((yyvsp[-3].symbol));
			if((yyvsp[-1].astree)->dataType == DATATYPE_ASTREE_FLOAT || DATATYPE_ASTREE_CHAR || (yyvsp[-1].astree)->natureza == NATUREZA_ASTREE_POINTER)
			{
				fprintf(stderr,"Erro na linha  %d. Indice do vetor %s deveria escalar.\n",getLineNumber(),(yyvsp[-3].symbol)->text); 
				set_error_flag();
			}			
			(yyval.astree) = astreeCreate(ASTREE_VECTOR, (yyvsp[-1].astree), 0, 0, 0, (yyvsp[-3].symbol));
			//$$ = define_astree_nature_and_type($$,$1); //Talvez deva ser NATUREZA_ESCALAR
			(yyval.astree) = define_astree_type((yyval.astree),(yyvsp[-3].symbol));
			(yyval.astree)->natureza = NATUREZA_ASTREE_ESCALAR;
}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 273 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = (yyvsp[0].astree);}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 274 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = (yyvsp[0].astree);
(yyval.astree)->natureza = NATUREZA_ASTREE_ESCALAR;}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 276 "parser.y" /* yacc.c:1646  */
    {
			verify_pointer((yyvsp[0].symbol));				
			(yyval.astree) = astreeCreate(ASTREE_SYMBOL_POINT, 0, 0, 0, 0, (yyvsp[0].symbol));
			(yyval.astree) = define_astree_type((yyval.astree),(yyvsp[0].symbol));
			(yyval.astree)->natureza = NATUREZA_ASTREE_ESCALAR;
}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 282 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_SYMBOL_ADDRESS, 0, 0, 0, 0, (yyvsp[0].symbol));}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 283 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_EXP_BRACKET, (yyvsp[-1].astree), 0, 0, 0, 0);
			(yyval.astree)->dataType = (yyvsp[-1].astree)->dataType;
			(yyval.astree)->natureza = (yyvsp[-1].astree)->natureza;}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 286 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_SOMA, (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0, 0); 
	if(((yyvsp[-2].astree)->natureza == NATUREZA_ASTREE_ESCALAR)&&((yyvsp[0].astree)->natureza == NATUREZA_ASTREE_ESCALAR))
			{
		
					if ((yyvsp[-2].astree)->dataType!=DATATYPE_ASTREE_INTEGER)
						(yyval.astree)->dataType = DATATYPE_ASTREE_INTEGER;
					else if ((yyvsp[-2].astree)->dataType!=DATATYPE_ASTREE_CHAR)
						(yyval.astree)->dataType = DATATYPE_ASTREE_CHAR;
					else if ((yyvsp[-2].astree)->dataType!=DATATYPE_ASTREE_FLOAT)
						(yyval.astree)->dataType = DATATYPE_ASTREE_FLOAT;
					(yyval.astree)->natureza = NATUREZA_ASTREE_ESCALAR;
			}
			else
			{
				if((yyvsp[-2].astree)->natureza == NATUREZA_ASTREE_POINTER)
				{
					if(((yyvsp[0].astree)->natureza != NATUREZA_ASTREE_ESCALAR))
					{
						fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
						set_error_flag();
					}
					else
					{
						(yyval.astree)->dataType = (yyvsp[-2].astree)->dataType;
						(yyval.astree)->natureza = NATUREZA_ASTREE_POINTER;
					}
				}
				else
				{
					if((yyvsp[0].astree)->natureza == NATUREZA_ASTREE_POINTER)
					{
						if(((yyvsp[-2].astree)->natureza != NATUREZA_ASTREE_ESCALAR))
						{
							fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
							set_error_flag();
						}
						else
						{
							(yyval.astree)->dataType = (yyvsp[0].astree)->dataType;
							(yyval.astree)->natureza = NATUREZA_ASTREE_POINTER;
						}
					}
					else
					{
						fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
						set_error_flag();
					}
				}
			}			
		}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 336 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_SUB, (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0, 0); 
if(((yyvsp[-2].astree)->natureza == NATUREZA_ASTREE_ESCALAR)&&((yyvsp[0].astree)->natureza == NATUREZA_ASTREE_ESCALAR))
			{
					if ((yyvsp[-2].astree)->dataType!=DATATYPE_ASTREE_INTEGER)
						(yyval.astree)->dataType = DATATYPE_ASTREE_INTEGER;
					else if ((yyvsp[-2].astree)->dataType!=DATATYPE_ASTREE_CHAR)
						(yyval.astree)->dataType = DATATYPE_ASTREE_CHAR;
					else if ((yyvsp[-2].astree)->dataType!=DATATYPE_ASTREE_FLOAT)
						(yyval.astree)->dataType = DATATYPE_ASTREE_FLOAT;

					(yyval.astree)->natureza = NATUREZA_ASTREE_ESCALAR;
			}
			else
			{
				if((yyvsp[-2].astree)->natureza == NATUREZA_ASTREE_POINTER)
				{
					if(((yyvsp[0].astree)->natureza != NATUREZA_ASTREE_ESCALAR))
					{
						fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
						set_error_flag();
					}
					else
					{
						(yyval.astree)->dataType = (yyvsp[-2].astree)->dataType;
						(yyval.astree)->natureza = NATUREZA_ASTREE_POINTER;
					}
				}
				else
				{
					if((yyvsp[0].astree)->natureza == NATUREZA_ASTREE_POINTER)
					{
						if(((yyvsp[-2].astree)->natureza != NATUREZA_ASTREE_ESCALAR))
						{
							fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
							set_error_flag();
						}
						else
						{
							(yyval.astree)->dataType = (yyvsp[0].astree)->dataType;
							(yyval.astree)->natureza = NATUREZA_ASTREE_POINTER;
						}
					}
					else
					{
						fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
						set_error_flag();
					}
				}
			}
}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 386 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_MULT, (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0, 0); 

	if((yyvsp[-2].astree)->natureza != NATUREZA_ASTREE_ESCALAR
                        || (yyvsp[0].astree)->natureza != NATUREZA_ASTREE_ESCALAR)
			{
				fprintf(stderr,"Erro na linha  %d. Multiplicacao soh eh permitida entre inteiros (word ou byte).\n", getLineNumber()); 
				set_error_flag();
			}
			(yyval.astree)->natureza = NATUREZA_ASTREE_ESCALAR;
			if ((yyvsp[-2].astree)->dataType!=DATATYPE_ASTREE_INTEGER)
						(yyval.astree)->dataType = DATATYPE_ASTREE_INTEGER;
					else if ((yyvsp[-2].astree)->dataType!=DATATYPE_ASTREE_CHAR)
						(yyval.astree)->dataType = DATATYPE_ASTREE_CHAR;
					else if ((yyvsp[-2].astree)->dataType!=DATATYPE_ASTREE_FLOAT)
						(yyval.astree)->dataType = DATATYPE_ASTREE_FLOAT;}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 401 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_DIV, (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0, 0); 
if((yyvsp[-2].astree)->natureza != NATUREZA_ASTREE_ESCALAR
                        || (yyvsp[0].astree)->natureza != NATUREZA_ASTREE_ESCALAR)
			{
				fprintf(stderr,"Erro na linha  %d. Multiplicacao soh eh permitida entre inteiros (word ou byte).\n", getLineNumber()); 
				set_error_flag();
			}
			(yyval.astree)->natureza = NATUREZA_ASTREE_ESCALAR;
			if ((yyvsp[-2].astree)->dataType!=DATATYPE_ASTREE_INTEGER)
						(yyval.astree)->dataType = DATATYPE_ASTREE_INTEGER;
					else if ((yyvsp[-2].astree)->dataType!=DATATYPE_ASTREE_CHAR)
						(yyval.astree)->dataType = DATATYPE_ASTREE_CHAR;
					else if ((yyvsp[-2].astree)->dataType!=DATATYPE_ASTREE_FLOAT)
						(yyval.astree)->dataType = DATATYPE_ASTREE_FLOAT;}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 415 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_LESS, (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0, 0); }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 416 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_GREAT, (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0, 0); }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 417 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_NEG, (yyvsp[0].astree), 0, 0, 0, 0);}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 418 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_LE, (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0, 0);}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 419 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_GE, (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0, 0);}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 420 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_EQ, (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0, 0);}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 421 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_NE, (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0, 0);}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 422 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_AND, (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0, 0); }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 423 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_OR, (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0, 0);}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 426 "parser.y" /* yacc.c:1646  */
    {reset_cont();clear_lists();}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 426 "parser.y" /* yacc.c:1646  */
    {
			verify_function_declared ((yyvsp[-4].symbol));
			(yyval.astree) = astreeCreate(ASTREE_FUNC_CALL, (yyvsp[-1].astree), 0, 0, 0, (yyvsp[-4].symbol));

			if((yyvsp[-4].symbol)->number_of_param_func != get_cont())
			{
				fprintf(stderr,"Erro na linha  %d. Funcao %s deveria ter %d parametros.\n",getLineNumber(),(yyvsp[-4].symbol)->text,(yyvsp[-4].symbol)->number_of_param_func); 
				set_error_flag(); }
			(yyval.astree) = define_astree_type((yyval.astree),(yyvsp[-4].symbol));
			(yyval.astree)->natureza = NATUREZA_ASTREE_FUNCTION; //Talvez deva ser NATUREZA_ESCALAR
			compare_lists((yyvsp[-4].symbol)->list_naturezas, (yyvsp[-4].symbol)->list_dataTypes,(yyvsp[-4].symbol)->number_of_param_func);}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 437 "parser.y" /* yacc.c:1646  */
    {
			verify_function_declared ((yyvsp[-2].symbol));
			(yyval.astree) = astreeCreate(ASTREE_FUNC_CALL, 0, 0, 0, 0, (yyvsp[-2].symbol));
			(yyval.astree) = define_astree_type((yyval.astree),(yyvsp[-2].symbol));
			(yyval.astree)->natureza = NATUREZA_ASTREE_FUNCTION; //Talvez deva ser NATUREZA_ESCALAR

}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 446 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = (yyvsp[0].astree);}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 447 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_EXP_LIST, (yyvsp[-2].astree),(yyvsp[0].astree),0,0,0);}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 450 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = (yyvsp[0].astree);}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 450 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = (yyvsp[0].astree);}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 450 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = (yyvsp[0].astree);}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 453 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_IF, (yyvsp[-3].astree), (yyvsp[0].astree), 0, 0, 0); }
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 454 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_IF_ELSE, (yyvsp[-5].astree), (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0); }
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 457 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_WHILE, (yyvsp[-2].astree), (yyvsp[0].astree), 0, 0, 0); }
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 460 "parser.y" /* yacc.c:1646  */
    {(yyval.astree) = astreeCreate(ASTREE_FOR, (yyvsp[-4].astree), (yyvsp[-2].astree), (yyvsp[0].astree), 0, (yyvsp[-6].symbol)); }
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2142 "y.tab.c" /* yacc.c:1646  */
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
#line 463 "parser.y" /* yacc.c:1906  */


int yyerror(){
	printf("programa não reconhecido, erro na linha %d\n", lineCount);
	exit(3);
}

void set_error_flag()
{
	extern int error;
	error = 1;
}	

int get_error_flag()
{
	extern int error;
	return error;
}

void clear_lists()
{
	int i;
	for(i=0;i<20;i++)
	{
		list_dataTypes[i]=0;
		list_naturezas[i]=0;
	}
}

void put_in_lists(int natureza, int dataType)
{
	list_dataTypes[cont]=dataType;
	list_naturezas[cont]=natureza;	
}

void reset_cont()
{
	cont = 0;
}

void inc_cont()
{
	cont += 1;
}

int get_cont()
{
	return cont;
}

void define_dataType (int type, HASHNODE *identifier)
{ 
	if(type == ASTREE_INT)identifier->dataType = DATATYPE_INTEGER;
	if(type == ASTREE_FLOAT)identifier->dataType = DATATYPE_FLOAT;
	if(type == ASTREE_CHAR)identifier->dataType = DATATYPE_CHAR;
}

void verify_function_declaration (HASHNODE *function)
{	
	if(function->is_declared == 1)
	{
		fprintf(stderr,"Erro na linha  %d. Funcao %s ja declarada. \n", getLineNumber(),function->text); 
		set_error_flag();
	}
	else function->is_declared = 1;	
}

void verify_function_declared (HASHNODE *function)
{ 
	if(function->is_declared == 0)
	{
		fprintf(stderr,"Erro na linha  %d. Funcao %s nao declarada. \n", getLineNumber(),function->text); 
		set_error_flag();
	}
	else
	{
		if(function->natureza != NATUREZA_FUNCTION)
		{
			fprintf(stderr,"Erro na linha  %d. Chama %s, que nao eh funcao. \n", getLineNumber(),function->text); 
			set_error_flag();						
		}
	}
}

void verify_variable_declaration (HASHNODE *variable)
{
	if(variable->is_declared == 1)
	{
		fprintf(stderr,"Erro na linha  %d. Variavel %s ja declarada. \n", getLineNumber(),variable->text); 
		set_error_flag();
	}
	else variable->is_declared = 1;
}


void verify_variable_declared (HASHNODE *variable)
{ 
	
	if(variable->is_declared == 0)
	{
		fprintf(stderr,"Erro na linha  %d. Variavel %s nao declarada. \n", getLineNumber(),variable->text); 
		set_error_flag();
	}
	else
	{
          if (variable->natureza==NATUREZA_FUNCTION)
          {
		    fprintf(stderr,"Erro na linha  %d. Funcao %s nao eh uma variavel. \n", getLineNumber(),variable->text); 
		    set_error_flag();
          }
        }
}

void verify_vector (HASHNODE *vector)
{ 
	if(vector->is_declared == 0)
	{
		fprintf(stderr,"Erro na linha  %d. Variavel %s nao declarada. \n", getLineNumber(),vector->text); 
		set_error_flag();
	}
        else
        {
		if (vector->natureza!=NATUREZA_VETOR)
		{
		    fprintf(stderr,"Erro na linha  %d. %s nao eh vetor. \n", getLineNumber(),vector->text); 
		    set_error_flag();
        	}    
    	}
}

void verify_pointer (HASHNODE *pointer)
{ 
	if(pointer->is_declared == 0)
	{
		fprintf(stderr,"Erro na linha  %d. Variavel %s nao declarada. \n", getLineNumber(),pointer->text); 
		set_error_flag();
	}
    else
    {
		if (pointer->natureza!=NATUREZA_POINTER)
		{
		    fprintf(stderr,"Erro na linha  %d. %s nao eh ponteiro. \n", getLineNumber(),pointer->text); 
		    set_error_flag();
        }    
    }
}

ASTREE* define_astree_nature_and_type(ASTREE *node,HASHNODE *element)
{
    switch (element->natureza)
    {
        case NATUREZA_ESCALAR:
                node->natureza = NATUREZA_ASTREE_ESCALAR;
            break;
        case NATUREZA_VETOR:
                node->natureza = NATUREZA_ASTREE_VETOR;
            break;
        case NATUREZA_FUNCTION:
                node->natureza = NATUREZA_ASTREE_FUNCTION;
            break;
        case NATUREZA_POINTER:
                node->natureza = NATUREZA_ASTREE_POINTER;
            break;
     }
    switch (element->dataType)
    {
        case DATATYPE_INTEGER:
                node->dataType = DATATYPE_ASTREE_INTEGER;
            break;
        case DATATYPE_FLOAT:
		node->dataType = DATATYPE_ASTREE_FLOAT;
            break;
	case DATATYPE_CHAR:
                node->dataType = DATATYPE_ASTREE_CHAR;
            break;
     } 
     return node;      
}

ASTREE* define_astree_type(ASTREE *node,HASHNODE *element)
{
    switch (element->dataType)
    {
 case DATATYPE_INTEGER:
                node->dataType = DATATYPE_ASTREE_INTEGER;
            break;
        case DATATYPE_FLOAT:
		node->dataType = DATATYPE_ASTREE_FLOAT;
            break;
	case DATATYPE_CHAR:
                node->dataType = DATATYPE_ASTREE_CHAR;
            break;
     } 
     return node;      
}

ASTREE* define_astree_nature(ASTREE *node,HASHNODE *element)
{
    switch (element->natureza)
    {
        case NATUREZA_ESCALAR:
                node->natureza = NATUREZA_ASTREE_ESCALAR;
            break;
        case NATUREZA_VETOR:
                node->natureza = NATUREZA_ASTREE_VETOR;
            break;
        case NATUREZA_FUNCTION:
                node->natureza = NATUREZA_ASTREE_FUNCTION;
            break;
        case NATUREZA_POINTER:
                node->natureza = NATUREZA_ASTREE_POINTER;
            break;
     }
}

int compareHashTreeNatureza (int hashc, int treec)
{
	switch (hashc)
	{
		case NATUREZA_ESCALAR:
			if (treec==NATUREZA_ASTREE_ESCALAR)
			    return 1;
		break;

		case NATUREZA_VETOR:
			if (treec==NATUREZA_ASTREE_VETOR)
			    return 1;
		break;
		case NATUREZA_FUNCTION:
			if (treec==NATUREZA_ASTREE_FUNCTION)
			    return 1;
		break;
		case NATUREZA_POINTER:
			if (treec==NATUREZA_ASTREE_POINTER)
			    return 1;
		break;
	}
}


void compare_lists (int* naturezaHash,int* dataTypesHash,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		//printf ("type=%d natureza=%d listnaturezas=%d listdatatypes=%d\n",dataTypesHash[i], naturezaHash[i], list_naturezas[i], list_dataTypes[i]);
		switch (naturezaHash[i])
		{			
			case NATUREZA_ESCALAR:
				if(list_naturezas[i]!=NATUREZA_ASTREE_ESCALAR)
				{
					fprintf(stderr,"Erro na linha  %d.  Parametro %d incompativel com sua declaracao na funcao. (natureza)\n", getLineNumber(),i);
					set_error_flag();
				}
				break;
			case NATUREZA_VETOR:
				if(list_naturezas[i]!=NATUREZA_ASTREE_VETOR)
				{
					fprintf(stderr,"Erro na linha  %d. Parametro %d incompativel com sua declaracao na funcao. (natureza) \n", getLineNumber(),i);
					set_error_flag();
				}
				break;
			case NATUREZA_POINTER:
				if(list_naturezas[i]!=NATUREZA_ASTREE_POINTER)
				{
					fprintf(stderr,"Erro na linha  %d. Parametro %d incompativel com sua declaracao na funcao. (natureza) \n", getLineNumber(),i);
					set_error_flag();
				}
				break;
			default:
				break;
		}
	/*	switch (dataTypesHash[i])
		{
			case DATATYPE_INTEGER:
			case DATATYPE_WORD:
				if(list_dataTypes[i]!=DATATYPE_ASTREE_INTEGER)
				{
					fprintf(stderr,"Erro na linha  %d. Parametro %d incompativel com sua declaracao na funcao. (dataType) \n", getLineNumber(),i);
					set_error_flag();
				}
				break;
			case DATATYPE_BOOL:
				if(list_dataTypes[i]!=DATATYPE_ASTREE_BOOLEAN)
				{
					fprintf(stderr,"Erro na linha  %d. Parametro %d incompativel com sua declaracao na funcao. (dataType) \n", getLineNumber(),i);
					set_error_flag();
				}
				break;
		} */

	}
}
