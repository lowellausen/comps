/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include <stdio.h>
#include <stdlib.h>

extern int lineCount;
#line 26 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define TK_WHILE 257
#define TK_CHAR 258
#define TK_INT 259
#define TK_FLOAT 260
#define TK_IF 261
#define TK_THEN 262
#define TK_ELSE 263
#define TK_FOR 264
#define TK_TO 265
#define TK_READ 266
#define TK_RETURN 267
#define TK_PRINT 268
#define OPERATOR_LE 269
#define OPERATOR_GE 270
#define OPERATOR_EQ 271
#define OPERATOR_NE 272
#define OPERATOR_AND 273
#define OPERATOR_OR 274
#define TK_IDENTIFIER 275
#define LIT_INTEGER 276
#define LIT_REAL 277
#define LIT_CHAR 278
#define LIT_STRING 279
#define TOKEN_ERROR 280
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    2,    2,    2,    4,    4,    4,
    6,    6,    6,    5,    5,    5,    7,    7,    3,   10,
    8,    8,    8,   11,   11,    9,   12,   12,   12,   13,
   13,   13,   13,   13,   13,   13,   14,   14,   15,   16,
   20,   20,   20,   20,   17,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   21,   21,   22,   22,   18,
   18,   18,   23,   23,   24,   25,
};
static const YYINT yylen[] = {                            2,
    1,    2,    2,    0,    5,    6,    4,    1,    1,    1,
    3,    5,    0,    1,    1,    1,    2,    0,    6,    2,
    1,    2,    0,    3,    0,    3,    3,    1,    0,    1,
    1,    1,    1,    1,    1,    0,    3,    6,    2,    2,
    1,    1,    2,    2,    2,    1,    4,    1,    1,    2,
    2,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    4,    3,    1,    3,    1,
    1,    1,    6,    8,    5,    9,
};
static const YYINT yydefred[] = {                         0,
    8,   10,    9,    0,    1,    0,    0,    0,    2,    3,
    0,    0,    0,    0,    0,    0,    0,   14,   15,   16,
    0,    0,    0,    0,    0,    7,    0,    5,    0,   20,
    0,    0,   22,    0,    0,    0,   19,    0,    6,    0,
   12,    0,    0,    0,    0,    0,    0,    0,   34,    0,
    0,   30,   31,   32,   33,   35,   70,   71,   72,   24,
   17,    0,    0,    0,   39,    0,    0,    0,    0,   48,
    0,   49,    0,    0,   40,    0,    0,   26,    0,    0,
    0,    0,    0,    0,   50,    0,   51,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   43,   44,    0,    0,   27,    0,    0,    0,    0,   67,
    0,    0,   52,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   75,    0,    0,
   47,    0,   66,    0,    0,    0,   69,    0,    0,    0,
   74,    0,   76,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,   70,   16,   41,   24,   49,   25,
   33,   50,   51,   52,   53,   54,   55,   56,   74,   75,
   72,  112,   57,   58,   59,
};
static const YYINT yysindex[] = {                      -202,
    0,    0,    0,    0,    0, -202, -202,  -28,    0,    0,
   57, -269, -182, -261, -202,  -41,  -21,    0,    0,    0,
  -35,  -49, -226,   22,   33,    0, -182,    0,   28,    0,
  -22, -202,    0,   43, -182,  -80,    0,   33,    0, -182,
    0,   63,   65,   66, -164,   98,    1,  -60,    0,  -11,
   56,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   98,   98, -159,    0,  -36, -153,   98, -152,    0,
  522,    0,    1,  -10,    0,   98,   98,    0,  -80,  160,
  414,   70,   98,   40,    0,  421,    0,   98,   98,   98,
   98,   98,   98,   98,   98,   98,   98,   98,   98,   98,
    0,    0,  522,  437,    0,  -80, -128,   98,  445,    0,
  469,   94,    0,  522,  522,  522,  522,  522,  522,  522,
  522,  522,  522,  522,  522,  522,   76,    0,  -80,  490,
    0,   98,    0,   98, -124,   98,    0,  522,  -80,  506,
    0,  -80,    0,
};
static const YYINT yyrindex[] = {                       140,
    0,    0,    0,    0,    0,  140,  140,    0,    0,    0,
   93,    0,    0,    0,  112,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  113,    0,    0,    0,   96,    0,
    0,    0,    0,    0,  100,  -56,    0,  119,    0,  100,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   45,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -33,    0,    0,    0,    0,
  -46,    0,  -40,  -37,    0,    0,    0,    0,  -56,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -13,    0,    0,   -6,    0,    0,    0,    0,
  127,    0,    0,    7,   24,   32,   49,   69,   86,  106,
  123,  131,  298,  376,  384,  401,    0,    0,   -6,    0,
    0,    0,    0,    0,  -43,    0,    0,   -5,   -6,    0,
    0,   -6,    0,
};
static const YYINT yygindex[] = {                         0,
   14,    0,    0,    2,  116,    0,  133,    0,  145,  146,
  142,  104,  -68,    0,    0,    0,    0,    0,  535,   25,
    0,   53,    0,    0,    0,
};
#define YYTABLESIZE 796
static const YYINT yytable[] = {                         46,
   76,   46,   36,   84,   46,   17,   12,   46,   46,   46,
   46,   46,   45,   46,   22,   73,   23,   26,   41,    9,
   10,   42,  100,   28,   67,   46,   46,   69,   46,   68,
   77,   96,   94,   23,   95,   67,   97,  128,   69,   27,
   68,   60,   36,   29,   60,   37,   60,   60,   30,   98,
   60,   99,   36,   38,   83,    1,    2,    3,   61,   46,
  135,   61,   31,   61,   61,   60,   62,   61,   29,   62,
  141,   62,   62,  143,   67,   62,   32,   69,   45,   68,
  110,   73,   61,   63,   41,   35,   63,   42,   63,   63,
   62,   46,   63,   18,   19,   20,   15,  101,  102,   60,
   36,   39,   62,   64,   63,   64,   64,   63,   64,   64,
   65,   37,   64,   78,   79,   82,   61,   13,   36,   38,
   65,   85,   87,   65,   62,   65,   65,   64,   21,   65,
  108,   60,   67,  129,  133,   69,  134,   68,  139,    4,
   53,   63,   34,   53,   65,   53,   53,   14,   61,   53,
   40,   13,   23,   21,   11,   40,   62,   54,   18,   25,
   54,   64,   54,   54,   53,   55,   54,   68,   55,   28,
   55,   55,   61,   63,   55,   37,   42,   38,   65,   60,
   43,   54,  105,   44,  137,   45,   46,   47,    0,   55,
    0,    0,  100,   64,   48,    0,    0,    0,   53,    0,
  106,   96,   94,    0,   95,    0,   97,    0,    0,    0,
   65,    0,    0,    0,    0,   54,   45,    0,    0,   98,
    0,   99,   41,   55,    0,   42,    0,    0,    0,   46,
   53,   46,    0,    0,    0,   46,   46,   46,   46,   46,
   46,   46,   46,   46,   46,   46,   11,   54,    0,   37,
    0,    0,    0,    0,    0,   55,   36,   38,   88,   89,
   90,   91,   92,   93,   66,   18,   19,   20,   73,   60,
    0,   60,    0,    0,    0,   66,   18,   19,   20,   73,
    0,   60,   60,   60,   60,   60,   61,    0,   61,    0,
    0,    0,    0,    0,   62,    0,   62,    0,   61,   61,
   61,   61,   61,    0,    0,    0,   62,   62,   62,   62,
   62,   63,    0,   63,   66,   18,   19,   20,    0,    0,
    0,    0,    0,   63,   63,   63,   63,   63,    0,    0,
    0,   64,   56,   64,    0,   56,    0,   56,   56,    0,
    0,   56,    0,   64,   64,   64,   64,   64,   65,    0,
   65,    0,    0,    0,    0,    0,   56,    0,    0,    0,
   65,   65,   65,   65,   65,    0,    0,    0,   53,    0,
   53,    0,   66,   18,   19,   20,    0,    0,    0,    0,
   53,   53,   53,   53,   53,   54,    0,   54,    0,    0,
   56,    0,    0,   55,    0,   55,    0,   54,   54,   54,
   54,   54,    0,    0,    0,   55,   55,   55,   55,   55,
   57,    0,    0,   57,    0,   57,   57,    0,   58,   57,
    0,   58,   56,   58,   58,    0,    0,   58,   88,   89,
   90,   91,   92,   93,   57,   59,    0,    0,   59,    0,
   59,   59,   58,    0,   59,    0,  100,    0,    0,    0,
    0,    0,    0,  100,  107,   96,   94,    0,   95,   59,
   97,  113,   96,   94,    0,   95,    0,   97,   57,  100,
    0,    0,    0,   98,    0,   99,   58,  100,   96,   94,
   98,   95,   99,   97,    0,    0,   96,   94,    0,   95,
    0,   97,    0,   59,    0,    0,   98,    0,   99,    0,
   57,  100,    0,    0,   98,    0,   99,    0,   58,    0,
   96,   94,  132,   95,    0,   97,    0,    0,    0,    0,
    0,    0,  100,    0,    0,   59,    0,    0,   98,  127,
   99,   96,   94,    0,   95,    0,   97,  131,  100,    0,
    0,    0,    0,    0,    0,    0,  142,   96,   94,   98,
   95,   99,   97,    0,  100,    0,    0,    0,    0,    0,
   56,    0,   56,   96,   94,   98,   95,   99,   97,    0,
    0,    0,   56,   56,   56,   56,   56,    0,    0,    0,
   71,   98,    0,   99,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   80,   81,    0,    0,
    0,    0,   86,    0,    0,    0,    0,    0,    0,    0,
  103,  104,    0,    0,    0,    0,    0,  109,  111,    0,
    0,    0,  114,  115,  116,  117,  118,  119,  120,  121,
  122,  123,  124,  125,  126,    0,    0,    0,   57,    0,
   57,    0,  130,    0,    0,    0,   58,    0,   58,    0,
   57,   57,   57,   57,   57,    0,    0,    0,   58,   58,
   58,   58,   58,   59,    0,   59,  111,    0,  138,    0,
  140,    0,    0,    0,    0,   59,   59,   59,   59,   59,
    0,    0,   88,   89,   90,   91,   92,   93,    0,   88,
   89,   90,   91,   92,   93,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   88,   89,   90,   91,   92,
   93,    0,    0,   88,   89,   90,   91,   92,   93,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   88,   89,   90,
   91,   92,   93,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  136,    0,    0,    0,   88,   89,
   90,   91,   92,   93,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   88,   89,   90,   91,   92,   93,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   88,   89,   90,   91,   92,   93,
};
static const YYINT yycheck[] = {                         33,
   61,   35,   59,   40,   38,  275,   35,   41,   42,   43,
   44,   45,   59,   47,  276,   59,   15,   59,   59,    6,
    7,   59,   33,   59,   35,   59,   60,   38,   62,   40,
   91,   42,   43,   32,   45,   35,   47,  106,   38,   61,
   40,   35,  123,   93,   38,   59,   40,   41,  275,   60,
   44,   62,   59,   59,   91,  258,  259,  260,   35,   93,
  129,   38,   41,   40,   41,   59,   35,   44,  125,   38,
  139,   40,   41,  142,   35,   44,   44,   38,  125,   40,
   41,  125,   59,   35,  125,   58,   38,  125,   40,   41,
   59,  125,   44,  276,  277,  278,   40,   73,   74,   93,
  123,   59,   40,   35,   40,   40,   38,   59,   40,   41,
  275,  125,   44,  125,   59,  275,   93,   61,  125,  125,
   35,  275,  275,   38,   93,   40,   41,   59,   13,   44,
   61,  125,   35,  262,   41,   38,   61,   40,  263,    0,
   35,   93,   27,   38,   59,   40,   41,   91,  125,   44,
   35,   59,   41,   41,   59,   40,  125,   35,   59,   41,
   38,   93,   40,   41,   59,   35,   44,   41,   38,  125,
   40,   41,   40,  125,   44,   31,  257,   32,   93,   38,
  261,   59,   79,  264,  132,  266,  267,  268,   -1,   59,
   -1,   -1,   33,  125,  275,   -1,   -1,   -1,   93,   -1,
   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
  125,   -1,   -1,   -1,   -1,   93,  263,   -1,   -1,   60,
   -1,   62,  263,   93,   -1,  263,   -1,   -1,   -1,  263,
  125,  265,   -1,   -1,   -1,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  275,  125,   -1,  263,
   -1,   -1,   -1,   -1,   -1,  125,  263,  263,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  263,
   -1,  265,   -1,   -1,   -1,  275,  276,  277,  278,  279,
   -1,  275,  276,  277,  278,  279,  263,   -1,  265,   -1,
   -1,   -1,   -1,   -1,  263,   -1,  265,   -1,  275,  276,
  277,  278,  279,   -1,   -1,   -1,  275,  276,  277,  278,
  279,  263,   -1,  265,  275,  276,  277,  278,   -1,   -1,
   -1,   -1,   -1,  275,  276,  277,  278,  279,   -1,   -1,
   -1,  263,   35,  265,   -1,   38,   -1,   40,   41,   -1,
   -1,   44,   -1,  275,  276,  277,  278,  279,  263,   -1,
  265,   -1,   -1,   -1,   -1,   -1,   59,   -1,   -1,   -1,
  275,  276,  277,  278,  279,   -1,   -1,   -1,  263,   -1,
  265,   -1,  275,  276,  277,  278,   -1,   -1,   -1,   -1,
  275,  276,  277,  278,  279,  263,   -1,  265,   -1,   -1,
   93,   -1,   -1,  263,   -1,  265,   -1,  275,  276,  277,
  278,  279,   -1,   -1,   -1,  275,  276,  277,  278,  279,
   35,   -1,   -1,   38,   -1,   40,   41,   -1,   35,   44,
   -1,   38,  125,   40,   41,   -1,   -1,   44,  269,  270,
  271,  272,  273,  274,   59,   35,   -1,   -1,   38,   -1,
   40,   41,   59,   -1,   44,   -1,   33,   -1,   -1,   -1,
   -1,   -1,   -1,   33,   41,   42,   43,   -1,   45,   59,
   47,   41,   42,   43,   -1,   45,   -1,   47,   93,   33,
   -1,   -1,   -1,   60,   -1,   62,   93,   33,   42,   43,
   60,   45,   62,   47,   -1,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,   93,   -1,   -1,   60,   -1,   62,   -1,
  125,   33,   -1,   -1,   60,   -1,   62,   -1,  125,   -1,
   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,   -1,   33,   -1,   -1,  125,   -1,   -1,   60,   93,
   62,   42,   43,   -1,   45,   -1,   47,   93,   33,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   41,   42,   43,   60,
   45,   62,   47,   -1,   33,   -1,   -1,   -1,   -1,   -1,
  263,   -1,  265,   42,   43,   60,   45,   62,   47,   -1,
   -1,   -1,  275,  276,  277,  278,  279,   -1,   -1,   -1,
   46,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   62,   63,   -1,   -1,
   -1,   -1,   68,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   76,   77,   -1,   -1,   -1,   -1,   -1,   83,   84,   -1,
   -1,   -1,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,  100,   -1,   -1,   -1,  263,   -1,
  265,   -1,  108,   -1,   -1,   -1,  263,   -1,  265,   -1,
  275,  276,  277,  278,  279,   -1,   -1,   -1,  275,  276,
  277,  278,  279,  263,   -1,  265,  132,   -1,  134,   -1,
  136,   -1,   -1,   -1,   -1,  275,  276,  277,  278,  279,
   -1,   -1,  269,  270,  271,  272,  273,  274,   -1,  269,
  270,  271,  272,  273,  274,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  269,  270,  271,  272,  273,
  274,   -1,   -1,  269,  270,  271,  272,  273,  274,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  269,  270,  271,
  272,  273,  274,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  265,   -1,   -1,   -1,  269,  270,
  271,  272,  273,  274,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  269,  270,  271,  272,  273,  274,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#define YYUNDFTOKEN 308
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,0,"'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,
0,0,0,0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TK_WHILE","TK_CHAR","TK_INT",
"TK_FLOAT","TK_IF","TK_THEN","TK_ELSE","TK_FOR","TK_TO","TK_READ","TK_RETURN",
"TK_PRINT","OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE",
"OPERATOR_AND","OPERATOR_OR","TK_IDENTIFIER","LIT_INTEGER","LIT_REAL",
"LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : code",
"code : var code",
"code : func code",
"code :",
"var : var_type TK_IDENTIFIER '=' lit ';'",
"var : var_type '#' TK_IDENTIFIER '=' lit ';'",
"var : var_type TK_IDENTIFIER vec_dec ';'",
"var_type : TK_CHAR",
"var_type : TK_FLOAT",
"var_type : TK_INT",
"vec_dec : '[' LIT_INTEGER ']'",
"vec_dec : '[' LIT_INTEGER ']' ':' lit_list",
"vec_dec :",
"lit : LIT_INTEGER",
"lit : LIT_REAL",
"lit : LIT_CHAR",
"lit_list : lit lit_list",
"lit_list :",
"func : var_type TK_IDENTIFIER '(' param_list ')' block",
"param : var_type TK_IDENTIFIER",
"param_list : param",
"param_list : param aux_param_list",
"param_list :",
"aux_param_list : ',' param aux_param_list",
"aux_param_list :",
"block : '{' command_list '}'",
"command_list : command ';' command_list",
"command_list : command",
"command_list :",
"command : attribution",
"command : read",
"command : print",
"command : return",
"command : block",
"command : control",
"command :",
"attribution : TK_IDENTIFIER '=' expr",
"attribution : TK_IDENTIFIER '[' expr ']' '=' expr",
"read : TK_READ TK_IDENTIFIER",
"print : TK_PRINT print_list",
"print_list : LIT_STRING",
"print_list : expr",
"print_list : LIT_STRING print_list",
"print_list : expr print_list",
"return : TK_RETURN expr",
"expr : TK_IDENTIFIER",
"expr : TK_IDENTIFIER '[' expr ']'",
"expr : lit",
"expr : func_call",
"expr : '#' TK_IDENTIFIER",
"expr : '&' TK_IDENTIFIER",
"expr : '(' expr ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr '!' expr",
"expr : expr OPERATOR_LE expr",
"expr : expr OPERATOR_GE expr",
"expr : expr OPERATOR_EQ expr",
"expr : expr OPERATOR_NE expr",
"expr : expr OPERATOR_AND expr",
"expr : expr OPERATOR_OR expr",
"func_call : TK_IDENTIFIER '(' call_param_list ')'",
"func_call : TK_IDENTIFIER '(' ')'",
"call_param_list : expr",
"call_param_list : expr ',' call_param_list",
"control : if",
"control : while",
"control : for",
"if : TK_IF '(' expr ')' TK_THEN command",
"if : TK_IF '(' expr ')' TK_THEN command TK_ELSE command",
"while : TK_WHILE '(' expr ')' command",
"for : TK_FOR '(' TK_IDENTIFIER '=' expr TK_TO expr ')' command",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 118 "parser.y"

int yyerror(){
	printf("programa não reconhecido, erro na linha %d", lineCount);
	return 3;
}
#line 482 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
