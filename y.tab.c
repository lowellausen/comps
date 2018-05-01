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
    0,    1,    1,    1,    2,    2,    2,    2,    3,    3,
    3,    4,    4,    4,    5,    5,    6,    7,    8,    8,
    9,    9,   10,   11,   11,   12,   12,   12,   12,   12,
   12,   12,   13,   13,   14,   15,   16,   16,   16,   16,
   17,   18,   18,   18,   18,   18,   18,   18,   18,   18,
   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,
   18,   19,   19,   20,   20,   21,   21,   21,   22,   22,
   23,   24,
};
static const YYINT yylen[] = {                            2,
    1,    2,    2,    0,    5,    6,    6,    8,    1,    1,
    1,    1,    1,    1,    2,    0,    6,    2,    2,    0,
    3,    0,    3,    3,    1,    1,    1,    1,    1,    1,
    1,    0,    3,    6,    2,    2,    1,    1,    2,    2,
    2,    1,    4,    1,    1,    2,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    4,    3,    1,    3,    1,    1,    1,    6,    8,
    5,    9,
};
static const YYINT yydefred[] = {                         0,
    9,   11,   10,    0,    1,    0,    0,    0,    2,    0,
    0,    3,    0,    0,    0,    0,   12,   13,   14,    0,
    0,    0,    0,    0,    0,    5,    0,   18,    0,   19,
    0,    0,    7,    0,    0,    0,   17,    6,    0,    0,
   21,    0,    0,    0,    0,    0,    0,    0,   30,    0,
    0,   26,   27,   28,   29,   31,   66,   67,   68,   15,
    8,    0,    0,    0,   35,    0,    0,    0,    0,   44,
    0,   45,    0,   36,    0,    0,    0,   23,    0,    0,
    0,    0,    0,    0,   46,   47,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   39,   40,    0,    0,   24,    0,    0,    0,    0,   63,
    0,    0,   48,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   55,    0,   71,    0,    0,
   43,    0,   62,    0,    0,    0,   65,    0,    0,    0,
   70,    0,   72,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,   70,   40,    8,   23,   24,   30,   49,
   50,   51,   52,   53,   54,   74,   55,   75,   72,  112,
   56,   57,   58,   59,
};
static const YYINT yysindex[] = {                      -241,
    0,    0,    0,    0,    0, -241,  -28, -241,    0,   33,
 -260,    0, -202, -237, -241,  -13,    0,    0,    0,   12,
  -16, -197,   49,   54, -202,    0,  -38,    0, -241,    0,
  -27,   39,    0, -202,   49, -110,    0,    0, -202,   40,
    0,   60,   76,   77, -154,  105,   -4,  -45,    0,   -3,
   73,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  105,  105, -139,    0,  -34, -134, -133,  105,    0,
  762,    0,   -4,    0,  -10,  105,  105,    0, -110,  148,
  513,   83,  105,    3,    0,    0,  520,  105,  105,  105,
  105,  105,  105,  105,  105,  105,  105,  105,  105,  105,
    0,    0,  762,  545,    0, -110, -107,  105,  582,    0,
  588,  118,    0,  129,  129,  129,  129,  803,  778,  129,
  129,  106,  106,  130,  130,    0,  107,    0, -110,  604,
    0,  105,    0,  105,  -90,  105,    0,  762, -110,  718,
    0, -110,    0,
};
static const YYINT yyrindex[] = {                       175,
    0,    0,    0,    0,    0,  175,    0,  175,    0,    0,
    0,    0,    0,    0,  136,    0,    0,    0,    0,    0,
    0,    0,  137,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  120,  137,  -55,    0,    0,  120,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -33,    0,    0,    0,    0,
  -58,    0,  -56,    0,  -35,    0,    0,    0,  -55,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   -6,    0,    0,   -5,    0,    0,    0,    0,
  141,    0,    0,  126,  162,  407,  424,  335,  493,  447,
  464,   67,   90,   21,   44,    0,    0,    0,   -5,    0,
    0,    0,    0,    0,  -12,    0,    0,   13,   -5,    0,
    0,   -5,    0,
};
static const YYINT yygindex[] = {                         0,
   34,    0,   86,   84,  145,    0,  158,    0,  159,  165,
  119,  -84,    0,    0,    0,  -24,    0,  818,    0,   69,
    0,    0,    0,    0,
};
#define YYTABLESIZE 1075
static const YYINT yytable[] = {                         42,
   41,   42,   37,   32,   42,   84,   11,   42,   42,   42,
   42,   42,   36,   42,   16,   76,    1,    2,    3,   34,
   33,  128,  100,   38,   67,   42,   42,   68,   42,   69,
   67,   98,   96,   68,   97,   69,   99,   67,   21,    9,
   68,   12,   69,  110,  135,   77,   69,   25,  101,   94,
  102,   95,   33,   32,  141,   51,   83,  143,   51,   42,
   51,   51,   51,   51,   51,   51,   41,   51,   37,   32,
   26,   34,   15,   17,   18,   19,   27,   28,   52,   51,
   51,   52,   51,   52,   52,   52,   52,   52,   52,   38,
   52,   42,   29,   13,   31,   36,   20,   38,   61,   62,
   22,   49,   52,   52,   49,   52,   49,   49,   32,   49,
   49,   49,   69,   51,   22,   63,   64,   39,   33,   32,
   65,   78,   39,   14,   50,   49,   49,   50,   49,   50,
   50,   79,   50,   50,   50,   82,   52,   34,  100,   67,
   85,   86,   68,  108,   69,   51,   42,   98,   50,   50,
   43,   50,   99,   44,  129,   45,   46,   47,  133,   49,
   56,  100,  100,   56,   48,   56,   56,  134,   52,   56,
   98,   96,  139,   97,    4,   99,   20,   22,   16,   25,
  100,   64,   50,   60,   56,   56,   35,   56,  106,   98,
   96,   49,   97,   41,   99,   37,   57,  105,    0,   57,
  137,   57,   57,    0,   41,   57,   37,   94,    0,   95,
    0,    0,    0,    0,   50,    0,    0,    0,   56,    0,
   57,   57,    0,   57,    0,    0,    0,   38,    0,   42,
    0,   42,    0,    0,    0,   42,   42,   42,   42,   42,
   42,   42,   42,   42,   42,   42,   10,    0,    0,    0,
   56,    0,    0,    0,   57,    0,   33,   32,   88,   89,
   90,   91,   92,   93,   66,   17,   18,   19,   73,    0,
   66,   17,   18,   19,   73,   34,    0,   66,   17,   18,
   19,    0,    0,   51,    0,   51,   57,    0,    0,   51,
   51,   51,   51,   51,   51,   51,   51,   51,   51,   51,
    0,    0,    0,    0,    0,    0,   52,    0,   52,    0,
    0,    0,   52,   52,   52,   52,   52,   52,   52,   52,
   52,   52,   52,    0,    0,    0,    0,    0,    0,   49,
    0,   49,    0,    0,    0,   49,   49,   49,   49,   49,
   49,   49,   49,   49,   49,   49,    0,    0,    0,    0,
    0,    0,   50,    0,   50,    0,    0,    0,   50,   50,
   50,   50,   50,   50,   50,   50,   50,   50,   50,   60,
    0,    0,   60,    0,   60,   60,    0,    0,   60,   66,
   17,   18,   19,    0,    0,    0,    0,    0,   56,    0,
   56,    0,    0,   60,   56,   56,   56,   56,   56,   56,
   56,   56,   56,   56,   56,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   88,   89,   90,   91,
   92,   93,    0,    0,   57,    0,   57,   60,    0,    0,
   57,   57,   57,   57,   57,   57,   57,   57,   57,   57,
   57,   58,    0,    0,   58,    0,   58,   58,    0,    0,
   58,    0,    0,    0,    0,    0,    0,    0,   59,   60,
    0,   59,    0,   59,   59,   58,   58,   59,   58,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   53,   59,   59,   53,   59,   53,   53,    0,    0,
   53,    0,    0,    0,    0,    0,    0,    0,   54,   58,
    0,   54,    0,   54,   54,   53,   53,   54,   53,    0,
    0,    0,    0,    0,    0,    0,   59,    0,    0,    0,
    0,    0,   54,   54,    0,   54,    0,   61,    0,    0,
   61,   58,   61,   61,    0,    0,   61,    0,    0,   53,
    0,    0,    0,    0,    0,  100,    0,    0,   59,    0,
    0,   61,  100,  107,   98,   96,   54,   97,    0,   99,
  113,   98,   96,    0,   97,    0,   99,    0,    0,    0,
    0,   53,   94,    0,   95,    0,    0,  100,    0,   94,
    0,   95,    0,    0,    0,   61,   98,   96,   54,   97,
    0,   99,    0,    0,    0,    0,    0,   60,    0,   60,
    0,    0,    0,    0,   94,    0,   95,   60,   60,   60,
   60,   60,   60,   60,  100,    0,    0,   61,    0,    0,
  100,    0,    0,   98,   96,    0,   97,    0,   99,   98,
   96,  132,   97,    0,   99,    0,  100,  127,    0,    0,
    0,   94,    0,   95,    0,   98,   96,   94,   97,   95,
   99,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   94,    0,   95,    0,    0,    0,   58,
    0,   58,    0,    0,  131,   58,   58,   58,   58,   58,
   58,   58,   58,   58,   58,   58,   59,    0,   59,    0,
    0,    0,   59,   59,   59,   59,   59,   59,   59,   59,
   59,   59,   59,    0,    0,    0,    0,    0,    0,   53,
    0,   53,    0,    0,    0,   53,   53,   53,   53,   53,
   53,   53,   53,   53,   53,   53,   54,    0,   54,    0,
    0,    0,   54,   54,   54,   54,   54,   54,   54,   54,
   54,   54,   54,    0,    0,    0,    0,    0,    0,    0,
  100,    0,    0,    0,    0,   61,    0,   61,  142,   98,
   96,    0,   97,    0,   99,    0,   61,   61,   61,   61,
   61,   61,    0,    0,    0,    0,    0,   94,    0,   95,
    0,   88,   89,   90,   91,   92,   93,    0,   88,   89,
   90,   91,   92,   93,  100,    0,    0,    0,    0,    0,
    0,    0,    0,   98,   96,    0,   97,    0,   99,    0,
  100,    0,    0,   88,   89,   90,   91,   92,   93,   98,
   96,   94,   97,   95,   99,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  100,    0,   94,    0,   95,
    0,    0,    0,    0,   98,   96,    0,   97,    0,   99,
   88,   89,   90,   91,   92,   93,   88,   89,   90,   91,
   92,   93,   94,   71,   95,    0,    0,    0,  136,    0,
    0,    0,   88,   89,   90,   91,   92,   93,    0,   80,
   81,    0,    0,    0,    0,    0,   87,    0,    0,    0,
    0,    0,    0,  103,  104,    0,    0,    0,    0,    0,
  109,  111,    0,    0,    0,  114,  115,  116,  117,  118,
  119,  120,  121,  122,  123,  124,  125,  126,    0,    0,
    0,    0,    0,    0,    0,  130,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  111,
    0,  138,    0,  140,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   88,   89,   90,   91,
   92,   93,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   88,   89,   90,   91,   92,   93,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   88,   89,   90,   91,
   92,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   88,   89,   90,   91,
};
static const YYINT yycheck[] = {                         33,
   59,   35,   59,   59,   38,   40,   35,   41,   42,   43,
   44,   45,  123,   47,  275,   61,  258,  259,  260,   58,
   59,  106,   33,   59,   35,   59,   60,   38,   62,   40,
   35,   42,   43,   38,   45,   40,   47,   35,  276,    6,
   38,    8,   40,   41,  129,   91,   59,   61,   73,   60,
   75,   62,   59,   59,  139,   35,   91,  142,   38,   93,
   40,   41,   42,   43,   44,   45,  125,   47,  125,  125,
   59,   59,   40,  276,  277,  278,   93,  275,   35,   59,
   60,   38,   62,   40,   41,   42,   43,   44,   45,  125,
   47,  125,   44,   61,   41,  123,   13,   59,   59,   40,
   15,   35,   59,   60,   38,   62,   40,   41,   25,   43,
   44,   45,  125,   93,   29,   40,   40,   34,  125,  125,
  275,  125,   39,   91,   35,   59,   60,   38,   62,   40,
   41,   59,   43,   44,   45,  275,   93,  125,   33,   35,
  275,  275,   38,   61,   40,  125,  257,   42,   59,   60,
  261,   62,   47,  264,  262,  266,  267,  268,   41,   93,
   35,   33,   33,   38,  275,   40,   41,   61,  125,   44,
   42,   43,  263,   45,    0,   47,   41,   41,   59,  125,
   33,   41,   93,   39,   59,   60,   29,   62,   41,   42,
   43,  125,   45,   35,   47,   31,   35,   79,   -1,   38,
  132,   40,   41,   -1,  263,   44,  263,   60,   -1,   62,
   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,   93,   -1,
   59,   60,   -1,   62,   -1,   -1,   -1,  263,   -1,  263,
   -1,  265,   -1,   -1,   -1,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  275,   -1,   -1,   -1,
  125,   -1,   -1,   -1,   93,   -1,  263,  263,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,   -1,
  275,  276,  277,  278,  279,  263,   -1,  275,  276,  277,
  278,   -1,   -1,  263,   -1,  265,  125,   -1,   -1,  269,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,  265,   -1,
   -1,   -1,  269,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,  263,
   -1,  265,   -1,   -1,   -1,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,   -1,   -1,   -1,   -1,
   -1,   -1,  263,   -1,  265,   -1,   -1,   -1,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,   35,
   -1,   -1,   38,   -1,   40,   41,   -1,   -1,   44,  275,
  276,  277,  278,   -1,   -1,   -1,   -1,   -1,  263,   -1,
  265,   -1,   -1,   59,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  269,  270,  271,  272,
  273,  274,   -1,   -1,  263,   -1,  265,   93,   -1,   -1,
  269,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,   35,   -1,   -1,   38,   -1,   40,   41,   -1,   -1,
   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   35,  125,
   -1,   38,   -1,   40,   41,   59,   60,   44,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   35,   59,   60,   38,   62,   40,   41,   -1,   -1,
   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   35,   93,
   -1,   38,   -1,   40,   41,   59,   60,   44,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,
   -1,   -1,   59,   60,   -1,   62,   -1,   35,   -1,   -1,
   38,  125,   40,   41,   -1,   -1,   44,   -1,   -1,   93,
   -1,   -1,   -1,   -1,   -1,   33,   -1,   -1,  125,   -1,
   -1,   59,   33,   41,   42,   43,   93,   45,   -1,   47,
   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   -1,  125,   60,   -1,   62,   -1,   -1,   33,   -1,   60,
   -1,   62,   -1,   -1,   -1,   93,   42,   43,  125,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,  263,   -1,  265,
   -1,   -1,   -1,   -1,   60,   -1,   62,  273,  274,  275,
  276,  277,  278,  279,   33,   -1,   -1,  125,   -1,   -1,
   33,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   42,
   43,   44,   45,   -1,   47,   -1,   33,   93,   -1,   -1,
   -1,   60,   -1,   62,   -1,   42,   43,   60,   45,   62,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,  263,
   -1,  265,   -1,   -1,   93,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  263,   -1,  265,   -1,
   -1,   -1,  269,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,  263,
   -1,  265,   -1,   -1,   -1,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  263,   -1,  265,   -1,
   -1,   -1,  269,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   33,   -1,   -1,   -1,   -1,  263,   -1,  265,   41,   42,
   43,   -1,   45,   -1,   47,   -1,  274,  275,  276,  277,
  278,  279,   -1,   -1,   -1,   -1,   -1,   60,   -1,   62,
   -1,  269,  270,  271,  272,  273,  274,   -1,  269,  270,
  271,  272,  273,  274,   33,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   33,   -1,   -1,  269,  270,  271,  272,  273,  274,   42,
   43,   60,   45,   62,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   33,   -1,   60,   -1,   62,
   -1,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
  269,  270,  271,  272,  273,  274,  269,  270,  271,  272,
  273,  274,   60,   46,   62,   -1,   -1,   -1,  265,   -1,
   -1,   -1,  269,  270,  271,  272,  273,  274,   -1,   62,
   63,   -1,   -1,   -1,   -1,   -1,   69,   -1,   -1,   -1,
   -1,   -1,   -1,   76,   77,   -1,   -1,   -1,   -1,   -1,
   83,   84,   -1,   -1,   -1,   88,   89,   90,   91,   92,
   93,   94,   95,   96,   97,   98,   99,  100,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  108,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  132,
   -1,  134,   -1,  136,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  269,  270,  271,  272,
  273,  274,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  269,  270,  271,  272,
  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  269,  270,  271,  272,
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
"var : var_type TK_IDENTIFIER '=' lit ';'",
"var : var_type '#' TK_IDENTIFIER '=' lit ';'",
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
#line 182 "parser.y"

int yyerror(){
	printf("programa não reconhecido, erro na linha %d\n", lineCount);
	exit(3);
}
#line 550 "y.tab.c"

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
	{yyval.astree = astreeCreate(ASTREE_PROGRAM,yystack.l_mark[0].astree,0,0,0,0); astreePrintTree(yyval.astree,0); printf("deu bowa.\n"); 
             exit (0); }
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
	{ yyval.astree = astreeCreate(ASTREE_VAR_DECL,yystack.l_mark[-4].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].astree),0,0,yystack.l_mark[-3].symbol); }
break;
case 6:
#line 102 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_POINT_DECL,yystack.l_mark[-5].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].astree),0,0,yystack.l_mark[-3].symbol);}
break;
case 7:
#line 103 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_VET_DECL,yystack.l_mark[-5].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-2].symbol),0,0,yystack.l_mark[-4].symbol); }
break;
case 8:
#line 104 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_VET_DECL_INIT,yystack.l_mark[-7].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-4].symbol),yystack.l_mark[-1].astree,0,yystack.l_mark[-6].symbol);}
break;
case 9:
#line 107 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_CHAR,0,0,0,0,0); }
break;
case 10:
#line 108 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_FLOAT,0,0,0,0,0); }
break;
case 11:
#line 109 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_INT,0,0,0,0,0); }
break;
case 12:
#line 112 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_SYMBOL,0,0,0,0, yystack.l_mark[0].symbol); yyval.astree->symbol = yystack.l_mark[0].symbol; }
break;
case 13:
#line 113 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_SYMBOL,0,0,0,0, yystack.l_mark[0].symbol); yyval.astree->symbol = yystack.l_mark[0].symbol; }
break;
case 14:
#line 114 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_SYMBOL,0,0,0,0, yystack.l_mark[0].symbol); yyval.astree->symbol = yystack.l_mark[0].symbol; }
break;
case 15:
#line 117 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_SYMBOL_LIST,yystack.l_mark[-1].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 16:
#line 118 "parser.y"
	{yyval.astree = 0;}
break;
#line 817 "y.tab.c"
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
