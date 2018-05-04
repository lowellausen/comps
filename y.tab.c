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
#include "hash.h"
#include "astree.h"

extern int lineCount;


#define   SYMBOL_UNDEFINED  	0 
#define   SYMBOL_LIT_INTEGER  	1 
#define   SYMBOL_LIT_REAL 	2 
#define   SYMBOL_LIT_CHAR   	3 
#define   SYMBOL_LIT_STRING  	4 
#define   SYMBOL_IDENTIFIER  	5 

#line 20 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {HASHNODE *symbol; 
	ASTREE *astree;
	} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 48 "y.tab.c"

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
    0,    1,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    2,    3,    3,    3,    4,    4,    4,    5,    5,
    6,    7,    7,    8,    8,    9,    9,   10,   11,   11,
   12,   12,   12,   12,   12,   12,   12,   13,   13,   14,
   15,   16,   16,   16,   16,   17,   18,   18,   18,   18,
   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,
   18,   18,   18,   18,   18,   18,   19,   19,   20,   20,
   21,   21,   21,   22,   22,   23,   24,
};
static const YYINT yylen[] = {                            2,
    1,    2,    2,    0,    5,    5,    5,    6,    6,    6,
    6,    8,    1,    1,    1,    1,    1,    1,    2,    0,
    6,    2,    3,    2,    0,    3,    0,    3,    3,    1,
    1,    1,    1,    1,    1,    1,    0,    3,    6,    2,
    2,    1,    1,    2,    2,    2,    1,    4,    1,    1,
    2,    2,    3,    3,    3,    3,    3,    3,    3,    2,
    3,    3,    3,    3,    3,    3,    4,    3,    1,    3,
    1,    1,    1,    6,    8,    5,    9,
};
static const YYINT yydefred[] = {                         0,
   13,   15,   14,    0,    1,    0,    0,    0,    2,    0,
    0,    3,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    5,    6,    7,    0,   22,    0,
    0,   24,    0,    0,    0,    0,   11,    0,   23,    0,
    0,   21,   10,    9,    8,   16,   17,   18,    0,    0,
   26,    0,    0,    0,    0,    0,    0,    0,   35,    0,
    0,   31,   32,   33,   34,   36,   71,   72,   73,   19,
   12,    0,    0,    0,   40,    0,    0,    0,    0,    0,
   49,    0,   50,    0,   41,    0,    0,    0,   28,    0,
    0,    0,    0,    0,    0,   51,   52,   60,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   44,   45,    0,    0,   29,    0,    0,    0,    0,
   68,    0,    0,   53,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   56,   57,    0,   76,    0,    0,
   48,    0,   67,    0,    0,    0,   70,    0,    0,    0,
   75,    0,   77,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,   81,   50,    8,   22,   23,   32,   59,
   60,   61,   62,   63,   64,   85,   65,   86,   83,  123,
   66,   67,   68,   69,
};
static const YYINT yysindex[] = {                      -197,
    0,    0,    0,    0,    0, -197,  -19, -197,    0,  -23,
 -272,    0, -167, -235, -197,   -2,   -4,    6,   23,  -15,
  -17,   56,   60, -146,    0,    0,    0,  -52,    0, -168,
 -197,    0,  -11,   58,   68,   69,    0, -143,    0,   56,
  -57,    0,    0,    0,    0,    0,    0,    0, -143,   87,
    0,  110,  111,  113, -119,  214,   46,  -46,    0,   35,
  100,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  214,  214, -113,    0,  -27, -106, -100,  214,  214,
    0,  513,    0,   46,    0,  402,  214,  214,    0,  -57,
  455,  462,  116,  214,  114,    0,    0,    0,  478,  214,
  214,  214,  214,  214,  214,  214,  214,  214,  214,  214,
  214,    0,    0,  513,  471,    0,  -57,  -84,  214,  492,
    0,  506,  138,    0,   -3,   -3,   -3,   -3,  527,  520,
   -3,   -3,   47,   47,    0,    0,  119,    0,  -57,  396,
    0,  214,    0,  214,  -82,  214,    0,  513,  -57,  485,
    0,  -57,    0,
};
static const YYINT yyrindex[] = {                       182,
    0,    0,    0,    0,    0,  182,    0,  182,    0,    0,
    0,    0,    0,    0,  142,    0,    0,    0,    0,    0,
    0,  143,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  126,    0,  143,
  -38,    0,    0,    0,    0,    0,    0,    0,  126,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   61,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -33,    0,    0,    0,    0,
    0,  -58,    0,  -55,    0,  -40,    0,    0,    0,  -38,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -37,    0,    0,  -35,    0,    0,    0,
    0,  146,    0,    0,   36,   64,   81,  104,  419,  436,
  132,  155,  -10,   13,    0,    0,    0,    0,  -35,    0,
    0,    0,    0,    0,  -22,    0,    0,  -12,  -35,    0,
    0,  -35,    0,
};
static const YYINT yygindex[] = {                         0,
   85,    0,    5,   -6,  149,    0,  170,    0,  162,  179,
  123,   19,    0,    0,    0,   34,    0,  541,    0,   74,
    0,    0,    0,    0,
};
#define YYTABLESIZE 799
static const YYINT yytable[] = {                         47,
   46,   47,   16,   42,   47,   38,   37,   47,   47,   47,
   47,   47,   95,   47,   87,   11,   15,   30,   43,   21,
   37,   38,   54,   37,   54,   47,   47,   54,   47,   54,
   54,   49,   54,   54,   54,   21,   74,   13,  110,  108,
   20,  109,   49,  111,   88,   55,   39,   55,   54,   54,
   55,   54,   55,   55,   25,   55,   55,   55,   24,   47,
    1,    2,    3,   94,   26,   41,   46,   14,   61,   42,
   61,   55,   55,   61,   55,   61,   61,   28,   79,   61,
   77,   27,   54,   78,   43,   80,   37,   38,  110,   37,
    9,   47,   12,  111,   61,   61,   62,   61,   62,   31,
   33,   62,   74,   62,   62,   55,   39,   62,   17,   18,
   19,   41,   39,   63,   54,   63,   43,  112,   63,  113,
   63,   63,   62,   62,   63,   62,   44,   45,   61,   34,
   35,   36,   46,   47,   48,  138,   64,   55,   64,   63,
   63,   64,   63,   64,   64,   71,   79,   64,   77,   72,
   73,   78,   74,   80,  121,   75,   62,  145,   90,   89,
   61,   93,   64,   64,   58,   64,   58,  151,   96,   58,
  153,   58,   58,   63,   97,   58,  119,  139,  143,  144,
  149,    4,   25,   27,   20,   30,   69,   59,   62,   59,
   58,   58,   59,   58,   59,   59,   64,   70,   59,   52,
   40,   51,    0,   53,   46,   63,   54,   42,   55,   56,
   57,   42,  116,   59,   59,  147,   59,   58,    0,    0,
    0,    0,   43,    0,   58,   38,    0,   37,   64,   47,
    0,   47,    0,    0,    0,   47,   47,   47,   47,   47,
   47,   47,   47,   47,   47,   47,   79,   59,   77,    0,
   39,   78,   54,   80,   54,   10,   58,   29,   54,   54,
   54,   54,   54,   54,   54,   54,   54,   54,   54,    0,
    0,    0,    0,    0,    0,   55,    0,   55,    0,   59,
    0,   55,   55,   55,   55,   55,   55,   55,   55,   55,
   55,   55,    0,    0,    0,    0,    0,    0,   61,    0,
   61,    0,    0,    0,   61,   61,   61,   61,   61,   61,
   61,   61,   61,   61,   61,    0,    0,    0,    0,    0,
   76,   46,   47,   48,   84,    0,   62,    0,   62,    0,
    0,    0,   62,   62,   62,   62,   62,   62,   62,   62,
   62,   62,   62,   63,    0,   63,    0,    0,    0,   63,
   63,   63,   63,   63,   63,   63,   63,   63,   63,   63,
    0,    0,    0,    0,    0,    0,   64,    0,   64,    0,
    0,    0,   64,   64,   64,   64,   64,   64,   64,   64,
   64,   64,   64,    0,    0,    0,    0,    0,   76,   46,
   47,   48,    0,    0,   58,    0,   58,    0,    0,    0,
   58,   58,   58,   58,   58,   58,   58,   58,   58,   58,
   58,    0,    0,    0,    0,    0,    0,   59,    0,   59,
    0,    0,    0,   59,   59,   59,   59,   59,   59,   59,
   59,   59,   59,   59,   79,    0,   77,  110,  108,   78,
  109,   80,  111,  110,  108,    0,  109,    0,  111,    0,
    0,   65,    0,   65,    0,  106,   65,  107,   65,   65,
    0,  106,   65,  107,    0,    0,    0,    0,   66,    0,
   66,    0,    0,   66,    0,   66,   66,   65,    0,   66,
    0,    0,    0,    0,    0,    0,    0,    0,   76,   46,
   47,   48,    0,    0,   66,  117,  110,  108,    0,  109,
    0,  111,  118,  110,  108,    0,  109,    0,  111,    0,
    0,   65,  110,  108,  106,  109,  107,  111,  124,  110,
  108,  106,  109,  107,  111,  152,  110,  108,   66,  109,
  106,  111,  107,  110,  108,    0,  109,  106,  111,  107,
    0,    0,    0,   65,  106,    0,  107,  110,  108,  142,
  109,  106,  111,  107,  110,  108,    0,  109,    0,  111,
   66,  110,  108,  137,  109,  106,  111,  107,  110,  108,
    0,  109,  106,  111,  107,    0,    0,    0,    0,  106,
    0,  107,    0,    0,  141,    0,  106,    0,  107,    0,
    0,    0,    0,    0,    0,    0,   82,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   91,   92,    0,    0,    0,    0,    0,   98,
   99,    0,    0,    0,    0,    0,    0,  114,  115,    0,
    0,    0,    0,    0,  120,  122,    0,    0,    0,    0,
  125,  126,  127,  128,  129,  130,  131,  132,  133,  134,
  135,  136,    0,    0,    0,    0,    0,    0,    0,  140,
  146,    0,    0,    0,  100,  101,  102,  103,  104,  105,
  100,  101,  102,  103,  104,  105,   76,   46,   47,   48,
   84,   65,  122,   65,  148,    0,  150,    0,    0,    0,
    0,   65,   65,   65,   65,   65,   65,   65,   66,    0,
   66,    0,    0,    0,    0,    0,    0,    0,    0,   66,
   66,   66,   66,   66,   66,    0,    0,    0,    0,    0,
    0,    0,    0,  100,  101,  102,  103,  104,  105,    0,
  100,  101,  102,  103,  104,  105,    0,    0,    0,  100,
  101,  102,  103,  104,  105,    0,  100,  101,  102,  103,
  104,  105,    0,  100,  101,  102,  103,  104,  105,    0,
  100,  101,  102,  103,  104,  105,    0,    0,    0,    0,
    0,    0,    0,    0,  100,  101,  102,  103,  104,  105,
    0,  100,  101,  102,  103,  104,  105,    0,  100,  101,
  102,  103,  104,    0,    0,  100,  101,  102,  103,
};
static const YYINT yycheck[] = {                         33,
   59,   35,  275,   59,   38,   58,   59,   41,   42,   43,
   44,   45,   40,   47,   61,   35,   40,   35,   59,   15,
   59,   59,   33,   59,   35,   59,   60,   38,   62,   40,
   41,   38,   43,   44,   45,   31,   59,   61,   42,   43,
  276,   45,   49,   47,   91,   33,   59,   35,   59,   60,
   38,   62,   40,   41,   59,   43,   44,   45,   61,   93,
  258,  259,  260,   91,   59,  123,  125,   91,   33,  125,
   35,   59,   60,   38,   62,   40,   41,   93,   33,   44,
   35,   59,   93,   38,  125,   40,  125,  125,   42,  125,
    6,  125,    8,   47,   59,   60,   33,   62,   35,   44,
   41,   38,  125,   40,   41,   93,  275,   44,  276,  277,
  278,  123,  125,   33,  125,   35,   59,   84,   38,   86,
   40,   41,   59,   60,   44,   62,   59,   59,   93,  276,
  277,  278,  276,  277,  278,  117,   33,  125,   35,   59,
   60,   38,   62,   40,   41,   59,   33,   44,   35,   40,
   40,   38,   40,   40,   41,  275,   93,  139,   59,  125,
  125,  275,   59,   60,   33,   62,   35,  149,  275,   38,
  152,   40,   41,   93,  275,   44,   61,  262,   41,   61,
  263,    0,   41,   41,   59,  125,   41,   33,  125,   35,
   59,   60,   38,   62,   40,   41,   93,   49,   44,  257,
   31,   40,   -1,  261,  263,  125,  264,  263,  266,  267,
  268,   33,   90,   59,   60,  142,   62,  275,   -1,   -1,
   -1,   -1,  263,   -1,   93,  263,   -1,  263,  125,  263,
   -1,  265,   -1,   -1,   -1,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,   33,   93,   35,   -1,
  263,   38,  263,   40,  265,  275,  125,  275,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,   -1,
   -1,   -1,   -1,   -1,   -1,  263,   -1,  265,   -1,  125,
   -1,  269,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,
  265,   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,   -1,   -1,   -1,   -1,   -1,
  275,  276,  277,  278,  279,   -1,  263,   -1,  265,   -1,
   -1,   -1,  269,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  263,   -1,  265,   -1,   -1,   -1,  269,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,  265,   -1,
   -1,   -1,  269,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,   -1,   -1,   -1,   -1,   -1,  275,  276,
  277,  278,   -1,   -1,  263,   -1,  265,   -1,   -1,   -1,
  269,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,  265,
   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,  275,
  276,  277,  278,  279,   33,   -1,   35,   42,   43,   38,
   45,   40,   47,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   33,   -1,   35,   -1,   60,   38,   62,   40,   41,
   -1,   60,   44,   62,   -1,   -1,   -1,   -1,   33,   -1,
   35,   -1,   -1,   38,   -1,   40,   41,   59,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  275,  276,
  277,  278,   -1,   -1,   59,   41,   42,   43,   -1,   45,
   -1,   47,   41,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   93,   42,   43,   60,   45,   62,   47,   41,   42,
   43,   60,   45,   62,   47,   41,   42,   43,   93,   45,
   60,   47,   62,   42,   43,   -1,   45,   60,   47,   62,
   -1,   -1,   -1,  125,   60,   -1,   62,   42,   43,   44,
   45,   60,   47,   62,   42,   43,   -1,   45,   -1,   47,
  125,   42,   43,   93,   45,   60,   47,   62,   42,   43,
   -1,   45,   60,   47,   62,   -1,   -1,   -1,   -1,   60,
   -1,   62,   -1,   -1,   93,   -1,   60,   -1,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   56,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   72,   73,   -1,   -1,   -1,   -1,   -1,   79,
   80,   -1,   -1,   -1,   -1,   -1,   -1,   87,   88,   -1,
   -1,   -1,   -1,   -1,   94,   95,   -1,   -1,   -1,   -1,
  100,  101,  102,  103,  104,  105,  106,  107,  108,  109,
  110,  111,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  119,
  265,   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,
  269,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  263,  142,  265,  144,   -1,  146,   -1,   -1,   -1,
   -1,  273,  274,  275,  276,  277,  278,  279,  263,   -1,
  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
  275,  276,  277,  278,  279,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,   -1,
  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,  269,
  270,  271,  272,  273,  274,   -1,  269,  270,  271,  272,
  273,  274,   -1,  269,  270,  271,  272,  273,  274,   -1,
  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,
   -1,  269,  270,  271,  272,  273,  274,   -1,  269,  270,
  271,  272,  273,   -1,   -1,  269,  270,  271,  272,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#define YYUNDFTOKEN 307
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
0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : code",
"code : var code",
"code : func code",
"code :",
"var : var_type TK_IDENTIFIER '=' LIT_INTEGER ';'",
"var : var_type TK_IDENTIFIER '=' LIT_REAL ';'",
"var : var_type TK_IDENTIFIER '=' LIT_CHAR ';'",
"var : var_type '#' TK_IDENTIFIER '=' LIT_CHAR ';'",
"var : var_type '#' TK_IDENTIFIER '=' LIT_REAL ';'",
"var : var_type '#' TK_IDENTIFIER '=' LIT_INTEGER ';'",
"var : var_type TK_IDENTIFIER '[' LIT_INTEGER ']' ';'",
"var : var_type TK_IDENTIFIER '[' LIT_INTEGER ']' ':' lit_list ';'",
"var_type : TK_CHAR",
"var_type : TK_FLOAT",
"var_type : TK_INT",
"lit : LIT_INTEGER",
"lit : LIT_REAL",
"lit : LIT_CHAR",
"lit_list : lit lit_list",
"lit_list :",
"func : var_type TK_IDENTIFIER '(' param_list ')' block",
"param : var_type TK_IDENTIFIER",
"param : var_type '#' TK_IDENTIFIER",
"param_list : param aux_param_list",
"param_list :",
"aux_param_list : ',' param aux_param_list",
"aux_param_list :",
"block : '{' command_list '}'",
"command_list : command ';' command_list",
"command_list : command",
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
"expr : '!' expr",
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
#line 218 "parser.y"

int yyerror(){
	printf("programa não reconhecido, erro na linha %d\n", lineCount);
	exit(3);
}
#line 502 "y.tab.c"

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
case 1:
#line 94 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_PROGRAM,yystack.l_mark[0].astree,0,0,0,0); astreePrintTree(yyval.astree,"  "); printf("deu bowa.\n"); 
              }
break;
case 2:
#line 97 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_DECL_LIST,yystack.l_mark[-1].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 3:
#line 98 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_DECL_LIST,yystack.l_mark[-1].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 4:
#line 99 "parser.y"
	{ yyval.astree = 0;}
break;
case 5:
#line 101 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_VAR_DECL,yystack.l_mark[-4].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].symbol),0,0,yystack.l_mark[-3].symbol); }
break;
case 6:
#line 102 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_VAR_DECL,yystack.l_mark[-4].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].symbol),0,0,yystack.l_mark[-3].symbol); }
break;
case 7:
#line 103 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_VAR_DECL,yystack.l_mark[-4].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].symbol),0,0,yystack.l_mark[-3].symbol); }
break;
case 8:
#line 104 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_POINT_DECL,yystack.l_mark[-5].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].symbol),0,0,yystack.l_mark[-3].symbol);}
break;
case 9:
#line 105 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_POINT_DECL,yystack.l_mark[-5].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].symbol),0,0,yystack.l_mark[-3].symbol);}
break;
case 10:
#line 106 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_POINT_DECL,yystack.l_mark[-5].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].symbol),0,0,yystack.l_mark[-3].symbol);}
break;
case 11:
#line 107 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_VET_DECL,yystack.l_mark[-5].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-2].symbol),0,0,yystack.l_mark[-4].symbol); }
break;
case 12:
#line 108 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_VET_DECL_INIT,yystack.l_mark[-7].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-4].symbol),yystack.l_mark[-1].astree,0,yystack.l_mark[-6].symbol);}
break;
case 13:
#line 111 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_CHAR,0,0,0,0,0); }
break;
case 14:
#line 112 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_FLOAT,0,0,0,0,0); }
break;
case 15:
#line 113 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_INT,0,0,0,0,0); }
break;
case 16:
#line 116 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_SYMBOL,0,0,0,0, yystack.l_mark[0].symbol); yyval.astree->symbol = yystack.l_mark[0].symbol; }
break;
case 17:
#line 117 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_SYMBOL,0,0,0,0, yystack.l_mark[0].symbol); yyval.astree->symbol = yystack.l_mark[0].symbol; }
break;
case 18:
#line 118 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_SYMBOL,0,0,0,0, yystack.l_mark[0].symbol); yyval.astree->symbol = yystack.l_mark[0].symbol; }
break;
case 19:
#line 121 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_SYMBOL_LIST,yystack.l_mark[-1].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 20:
#line 122 "parser.y"
	{yyval.astree = 0;}
break;
case 21:
#line 125 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_FUNC, yystack.l_mark[-5].astree,yystack.l_mark[-2].astree,yystack.l_mark[0].astree,0, yystack.l_mark[-4].symbol); }
break;
case 22:
#line 128 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_PARAM, yystack.l_mark[-1].astree,0,0,0, yystack.l_mark[0].symbol);}
break;
case 23:
#line 129 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_PARAM, yystack.l_mark[-2].astree,0,0,0, yystack.l_mark[0].symbol);}
break;
case 24:
#line 132 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_PARAM_LIST, yystack.l_mark[-1].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 25:
#line 133 "parser.y"
	{yyval.astree = 0;}
break;
case 26:
#line 136 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_PARAM_LIST, yystack.l_mark[-1].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 27:
#line 137 "parser.y"
	{yyval.astree = 0;}
break;
case 28:
#line 140 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_BLOCK,yystack.l_mark[-1].astree,0,0,0,0);}
break;
case 29:
#line 142 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_CMD_LIST, yystack.l_mark[-2].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 30:
#line 143 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 31:
#line 146 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 32:
#line 147 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 33:
#line 148 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 34:
#line 149 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 35:
#line 150 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 36:
#line 151 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 37:
#line 152 "parser.y"
	{yyval.astree = 0;}
break;
case 38:
#line 155 "parser.y"
	{ yyval.astree =  astreeCreate(ASTREE_ASSIGN_VAR, yystack.l_mark[0].astree, 0, 0, 0, yystack.l_mark[-2].symbol); }
break;
case 39:
#line 156 "parser.y"
	{ yyval.astree =  astreeCreate(ASTREE_ASSIGN_VECTOR, yystack.l_mark[-3].astree, yystack.l_mark[0].astree, 0, 0, yystack.l_mark[-5].symbol); }
break;
case 40:
#line 159 "parser.y"
	{ yyval.astree =  astreeCreate(ASTREE_READ, 0, 0, 0, 0, yystack.l_mark[0].symbol); }
break;
case 41:
#line 162 "parser.y"
	{ yyval.astree =  astreeCreate(ASTREE_PRINT, yystack.l_mark[0].astree, 0, 0, 0, 0); }
break;
case 42:
#line 165 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_SYMBOL,0,0,0,0, yystack.l_mark[0].symbol); yyval.astree->symbol = yystack.l_mark[0].symbol; }
break;
case 43:
#line 166 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_EXP,yystack.l_mark[0].astree,0,0,0, 0);}
break;
case 44:
#line 167 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_PRT_LST_ST,yystack.l_mark[0].astree,0,0,0, yystack.l_mark[-1].symbol); yyval.astree->symbol = yystack.l_mark[-1].symbol; }
break;
case 45:
#line 168 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_PRT_LST,yystack.l_mark[-1].astree,yystack.l_mark[0].astree,0,0, 0); }
break;
case 46:
#line 171 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_RETURN, yystack.l_mark[0].astree, 0, 0, 0, 0);}
break;
case 47:
#line 174 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_SYMBOL, 0, 0, 0, 0, yystack.l_mark[0].symbol); }
break;
case 48:
#line 175 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_VECTOR, yystack.l_mark[-1].astree, 0, 0, 0, yystack.l_mark[-3].symbol);}
break;
case 49:
#line 176 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 50:
#line 177 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 51:
#line 178 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_SYMBOL_POINT, 0, 0, 0, 0, yystack.l_mark[0].symbol);}
break;
case 52:
#line 179 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_SYMBOL_ADDRESS, 0, 0, 0, 0, yystack.l_mark[0].symbol);}
break;
case 53:
#line 180 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_EXP_BRACKET, yystack.l_mark[-1].astree, 0, 0, 0, 0);}
break;
case 54:
#line 181 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_SOMA, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 55:
#line 182 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_SUB, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 56:
#line 183 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_MULT, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 57:
#line 184 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_DIV, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 58:
#line 185 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_LESS, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 59:
#line 186 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_GREAT, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 60:
#line 187 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_NEG, yystack.l_mark[0].astree, 0, 0, 0, 0);}
break;
case 61:
#line 188 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_LE, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0);}
break;
case 62:
#line 189 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_GE, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0);}
break;
case 63:
#line 190 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_EQ, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0);}
break;
case 64:
#line 191 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_NE, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0);}
break;
case 65:
#line 192 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_AND, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 66:
#line 193 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_OR, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0);}
break;
case 67:
#line 196 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_FUNC_CALL, yystack.l_mark[-1].astree, 0, 0, 0, yystack.l_mark[-3].symbol);}
break;
case 68:
#line 197 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_FUNC_CALL, 0, 0, 0, 0, yystack.l_mark[-2].symbol);}
break;
case 69:
#line 200 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 70:
#line 201 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_EXP_LIST, yystack.l_mark[-2].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 71:
#line 204 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 72:
#line 204 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 73:
#line 204 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 74:
#line 207 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_IF, yystack.l_mark[-3].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 75:
#line 208 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_IF_ELSE, yystack.l_mark[-5].astree, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 76:
#line 211 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_WHILE, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 77:
#line 214 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_FOR, yystack.l_mark[-4].astree, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, yystack.l_mark[-6].symbol); }
break;
#line 1013 "y.tab.c"
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
