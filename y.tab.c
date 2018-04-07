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
    6,    6,    6,    5,    5,    5,    5,    7,    7,    3,
   10,    8,    8,    8,   11,   11,    9,   12,   12,   12,
   13,   13,   13,   13,   13,   13,   13,   14,   14,   15,
   16,   20,   20,   20,   20,   17,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   21,   21,   22,   22,
   18,   18,   18,   23,   23,   24,   25,
};
static const YYINT yylen[] = {                            2,
    1,    2,    2,    0,    5,    6,    4,    1,    1,    1,
    3,    5,    0,    1,    1,    1,    1,    2,    0,    6,
    2,    1,    2,    0,    3,    0,    3,    3,    1,    0,
    1,    1,    1,    1,    1,    1,    0,    3,    6,    2,
    2,    1,    1,    2,    2,    2,    1,    4,    1,    1,
    2,    2,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    4,    3,    1,    3,
    1,    1,    1,    6,    8,    5,    9,
};
static const YYINT yydefred[] = {                         0,
    8,   10,    9,    0,    1,    0,    0,    0,    2,    3,
    0,    0,    0,    0,    0,    0,    0,   14,   15,   16,
   17,    0,    0,    0,    0,    0,    7,    0,    5,    0,
   21,    0,    0,   23,    0,    0,    0,   20,    0,    6,
    0,   12,    0,    0,    0,    0,    0,    0,    0,   35,
    0,    0,   31,   32,   33,   34,   36,   71,   72,   73,
   25,   18,    0,    0,    0,   40,    0,    0,    0,    0,
   49,    0,   50,    0,    0,   41,    0,    0,   27,    0,
    0,    0,    0,    0,    0,   51,    0,   52,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   44,   45,    0,    0,   28,    0,    0,    0,    0,
   68,    0,    0,   53,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   76,    0,
    0,   48,    0,   67,    0,    0,    0,   70,    0,    0,
    0,   75,    0,   77,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,   71,   16,   42,   25,   50,   26,
   34,   51,   52,   53,   54,   55,   56,   57,   75,   76,
   73,  113,   58,   59,   60,
};
static const YYINT yysindex[] = {                      -157,
    0,    0,    0,    0,    0, -157, -157,  -28,    0,    0,
   57, -260, -125, -256, -157,  -25,  -23,    0,    0,    0,
    0,  -19,  -44, -219,   17,   19,    0, -125,    0,    3,
    0,  -49, -157,    0,   18, -125,  -80,    0,   19,    0,
 -125,    0,   65,   66,   71, -177,    1,   98,  -60,    0,
  -11,   56,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    1,    1, -159,    0,  -36, -155,    1, -153,
    0,  553,    0,   98,  -10,    0,    1,    1,    0,  -80,
  160,  442,   62,    1,   40,    0,  465,    0,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    0,    0,  553,  472,    0,  -80, -133,    1,  488,
    0,  495,   90,    0,  553,  553,  553,  553,  553,  553,
  553,  553,  553,  553,  553,  553,  553,   73,    0,  -80,
  525,    0,    1,    0,    1, -128,    1,    0,  553,  -80,
  547,    0,  -80,    0,
};
static const YYINT yyrindex[] = {                       137,
    0,    0,    0,    0,    0,  137,  137,    0,    0,    0,
   80,    0,    0,    0,   99,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  102,    0,    0,    0,   96,
    0,    0,    0,    0,    0,   97,  -56,    0,  118,    0,
   97,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   35,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -33,    0,    0,    0,
    0,  -46,    0,  419,  -40,    0,    0,    0,    0,  -56,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -37,    0,    0,  -13,    0,    0,    0,
    0,  127,    0,    0,    7,   24,   32,   49,   69,   86,
  106,  123,  131,  298,  376,  384,  401,    0,    0,  -13,
    0,    0,    0,    0,    0,  -43,    0,    0,   -6,  -13,
    0,    0,  -13,    0,
};
static const YYINT yygindex[] = {                         0,
   11,    0,    0,   -9,   58,    0,  129,    0,  141,  143,
  139,  100,  -86,    0,    0,    0,    0,    0,  765,   21,
    0,   50,    0,    0,    0,
};
#define YYTABLESIZE 902
static const YYINT yytable[] = {                         47,
   77,   47,   37,   85,   47,   24,   12,   47,   47,   47,
   47,   47,   46,   47,   17,   74,    9,   10,   43,   23,
  129,   38,  101,   24,   68,   47,   47,   70,   47,   69,
   78,   97,   95,   27,   96,   68,   98,   28,   70,   29,
   69,   61,   37,  136,   61,   37,   61,   61,   30,   99,
   61,  100,   39,  142,   84,   31,  144,   32,   62,   47,
   36,   62,   33,   62,   62,   61,   63,   62,   30,   63,
   22,   63,   63,   37,   68,   63,   40,   70,   46,   69,
  111,   74,   62,   64,   43,   35,   64,   38,   64,   64,
   63,   47,   64,   41,  102,  103,   15,   66,   41,   61,
    1,    2,    3,   65,   63,   64,   65,   64,   65,   65,
   65,   37,   65,   79,   80,   83,   62,   13,   39,   86,
   66,   88,  109,   66,   63,   66,   66,   65,  130,   66,
  134,   61,   68,  135,  140,   70,    4,   69,   13,   24,
   54,   64,   22,   54,   66,   54,   54,   14,   62,   54,
   18,   19,   20,   21,   11,   19,   63,   55,   26,   29,
   55,   65,   55,   55,   54,   56,   55,   69,   56,   62,
   56,   56,   38,   64,   56,   39,   43,   61,   66,  106,
   44,   55,  138,   45,    0,   46,   47,   48,    0,   56,
    0,    0,  101,   65,   49,    0,    0,    0,   54,    0,
  107,   97,   95,    0,   96,    0,   98,    0,    0,    0,
   66,    0,    0,    0,    0,   55,   46,    0,    0,   99,
    0,  100,   43,   56,    0,   38,    0,    0,    0,   47,
   54,   47,    0,    0,    0,   47,   47,   47,   47,   47,
   47,   47,   47,   47,   47,   47,   11,   55,    0,   37,
    0,    0,    0,    0,    0,   56,   39,    0,   89,   90,
   91,   92,   93,   94,   67,   18,   19,   20,   74,   61,
    0,   61,    0,    0,    0,   67,   18,   19,   20,   21,
    0,   61,   61,   61,   61,   61,   62,    0,   62,    0,
    0,    0,    0,    0,   63,    0,   63,    0,   62,   62,
   62,   62,   62,    0,    0,    0,   63,   63,   63,   63,
   63,   64,    0,   64,   67,   18,   19,   20,   21,    0,
    0,    0,    0,   64,   64,   64,   64,   64,    0,    0,
    0,   65,   57,   65,    0,   57,    0,   57,   57,    0,
    0,   57,    0,   65,   65,   65,   65,   65,   66,    0,
   66,    0,    0,    0,    0,    0,   57,    0,    0,    0,
   66,   66,   66,   66,   66,    0,    0,    0,   54,    0,
   54,    0,   67,   18,   19,   20,   74,    0,    0,    0,
   54,   54,   54,   54,   54,   55,    0,   55,    0,    0,
   57,    0,    0,   56,    0,   56,    0,   55,   55,   55,
   55,   55,    0,    0,    0,   56,   56,   56,   56,   56,
   58,    0,    0,   58,    0,   58,   58,    0,   59,   58,
    0,   59,   57,   59,   59,    0,    0,   59,   89,   90,
   91,   92,   93,   94,   58,   60,    0,    0,   60,    0,
   60,   60,   59,    0,   60,    0,    0,    0,    0,    0,
    0,   17,    0,    0,    0,    0,    0,    0,    0,   60,
   17,   17,    0,   17,    0,   17,    0,    0,   58,    0,
    0,    0,    0,    0,  101,    0,   59,   17,   17,    0,
   17,    0,  108,   97,   95,    0,   96,    0,   98,    0,
    0,    0,    0,   60,    0,    0,    0,  101,    0,    0,
   58,   99,    0,  100,  101,  114,   97,   95,   59,   96,
    0,   98,    0,   97,   95,    0,   96,    0,   98,    0,
  101,    0,    0,    0,   99,   60,  100,  101,    0,   97,
   95,   99,   96,  100,   98,    0,   97,   95,  133,   96,
    0,   98,    0,   17,    0,    0,    0,   99,    0,  100,
    0,    0,    0,    0,   99,    0,  100,  101,    0,    0,
   57,    0,   57,    0,  128,    0,   97,   95,    0,   96,
    0,   98,   57,   57,   57,   57,   57,    0,    0,  101,
  132,    0,    0,    0,   99,  101,  100,  143,   97,   95,
    0,   96,    0,   98,   97,   95,    0,   96,    0,   98,
    0,    0,    0,    0,    0,    0,   99,    0,  100,    0,
    0,    0,   99,    0,  100,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   58,    0,
   58,    0,    0,    0,    0,    0,   59,    0,   59,    0,
   58,   58,   58,   58,   58,    0,    0,    0,   59,   59,
   59,   59,   59,   60,    0,   60,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   60,   60,   60,   60,   60,
    0,   17,    0,    0,    0,    0,    0,   17,   17,   17,
   17,   17,   17,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   89,   90,   91,   92,   93,   94,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   89,   90,   91,   92,   93,   94,    0,
   89,   90,   91,   92,   93,   94,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   89,   90,   91,   92,
   93,   94,    0,   89,   90,   91,   92,   93,   94,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  137,
    0,    0,    0,   89,   90,   91,   92,   93,   94,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   72,    0,    0,    0,   89,   90,   91,   92,   93,
   94,   89,   90,   91,   92,   93,   94,   81,   82,    0,
    0,    0,    0,   87,    0,    0,    0,    0,    0,    0,
    0,  104,  105,    0,    0,    0,    0,    0,  110,  112,
    0,    0,    0,  115,  116,  117,  118,  119,  120,  121,
  122,  123,  124,  125,  126,  127,    0,    0,    0,    0,
    0,    0,    0,  131,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  112,    0,  139,
    0,  141,
};
static const YYINT yycheck[] = {                         33,
   61,   35,   59,   40,   38,   15,   35,   41,   42,   43,
   44,   45,   59,   47,  275,   59,    6,    7,   59,  276,
  107,   59,   33,   33,   35,   59,   60,   38,   62,   40,
   91,   42,   43,   59,   45,   35,   47,   61,   38,   59,
   40,   35,  123,  130,   38,   59,   40,   41,   93,   60,
   44,   62,   59,  140,   91,  275,  143,   41,   35,   93,
   58,   38,   44,   40,   41,   59,   35,   44,  125,   38,
   13,   40,   41,  123,   35,   44,   59,   38,  125,   40,
   41,  125,   59,   35,  125,   28,   38,  125,   40,   41,
   59,  125,   44,   36,   74,   75,   40,  275,   41,   93,
  258,  259,  260,   35,   40,   40,   38,   59,   40,   41,
   40,  125,   44,  125,   59,  275,   93,   61,  125,  275,
   35,  275,   61,   38,   93,   40,   41,   59,  262,   44,
   41,  125,   35,   61,  263,   38,    0,   40,   59,   41,
   35,   93,   41,   38,   59,   40,   41,   91,  125,   44,
  276,  277,  278,  279,   59,   59,  125,   35,   41,  125,
   38,   93,   40,   41,   59,   35,   44,   41,   38,   41,
   40,   41,   32,  125,   44,   33,  257,   39,   93,   80,
  261,   59,  133,  264,   -1,  266,  267,  268,   -1,   59,
   -1,   -1,   33,  125,  275,   -1,   -1,   -1,   93,   -1,
   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
  125,   -1,   -1,   -1,   -1,   93,  263,   -1,   -1,   60,
   -1,   62,  263,   93,   -1,  263,   -1,   -1,   -1,  263,
  125,  265,   -1,   -1,   -1,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  275,  125,   -1,  263,
   -1,   -1,   -1,   -1,   -1,  125,  263,   -1,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  263,
   -1,  265,   -1,   -1,   -1,  275,  276,  277,  278,  279,
   -1,  275,  276,  277,  278,  279,  263,   -1,  265,   -1,
   -1,   -1,   -1,   -1,  263,   -1,  265,   -1,  275,  276,
  277,  278,  279,   -1,   -1,   -1,  275,  276,  277,  278,
  279,  263,   -1,  265,  275,  276,  277,  278,  279,   -1,
   -1,   -1,   -1,  275,  276,  277,  278,  279,   -1,   -1,
   -1,  263,   35,  265,   -1,   38,   -1,   40,   41,   -1,
   -1,   44,   -1,  275,  276,  277,  278,  279,  263,   -1,
  265,   -1,   -1,   -1,   -1,   -1,   59,   -1,   -1,   -1,
  275,  276,  277,  278,  279,   -1,   -1,   -1,  263,   -1,
  265,   -1,  275,  276,  277,  278,  279,   -1,   -1,   -1,
  275,  276,  277,  278,  279,  263,   -1,  265,   -1,   -1,
   93,   -1,   -1,  263,   -1,  265,   -1,  275,  276,  277,
  278,  279,   -1,   -1,   -1,  275,  276,  277,  278,  279,
   35,   -1,   -1,   38,   -1,   40,   41,   -1,   35,   44,
   -1,   38,  125,   40,   41,   -1,   -1,   44,  269,  270,
  271,  272,  273,  274,   59,   35,   -1,   -1,   38,   -1,
   40,   41,   59,   -1,   44,   -1,   -1,   -1,   -1,   -1,
   -1,   33,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   93,   -1,
   -1,   -1,   -1,   -1,   33,   -1,   93,   59,   60,   -1,
   62,   -1,   41,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,   93,   -1,   -1,   -1,   33,   -1,   -1,
  125,   60,   -1,   62,   33,   41,   42,   43,  125,   45,
   -1,   47,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   33,   -1,   -1,   -1,   60,  125,   62,   33,   -1,   42,
   43,   60,   45,   62,   47,   -1,   42,   43,   44,   45,
   -1,   47,   -1,  125,   -1,   -1,   -1,   60,   -1,   62,
   -1,   -1,   -1,   -1,   60,   -1,   62,   33,   -1,   -1,
  263,   -1,  265,   -1,   93,   -1,   42,   43,   -1,   45,
   -1,   47,  275,  276,  277,  278,  279,   -1,   -1,   33,
   93,   -1,   -1,   -1,   60,   33,   62,   41,   42,   43,
   -1,   45,   -1,   47,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   60,   -1,   62,   -1,
   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,
  265,   -1,   -1,   -1,   -1,   -1,  263,   -1,  265,   -1,
  275,  276,  277,  278,  279,   -1,   -1,   -1,  275,  276,
  277,  278,  279,  263,   -1,  265,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  275,  276,  277,  278,  279,
   -1,  263,   -1,   -1,   -1,   -1,   -1,  269,  270,  271,
  272,  273,  274,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,   -1,
  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  269,  270,  271,  272,
  273,  274,   -1,  269,  270,  271,  272,  273,  274,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  265,
   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   47,   -1,   -1,   -1,  269,  270,  271,  272,  273,
  274,  269,  270,  271,  272,  273,  274,   63,   64,   -1,
   -1,   -1,   -1,   69,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   77,   78,   -1,   -1,   -1,   -1,   -1,   84,   85,
   -1,   -1,   -1,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,  100,  101,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  109,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  133,   -1,  135,
   -1,  137,
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
"lit : LIT_STRING",
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
#line 505 "y.tab.c"

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
