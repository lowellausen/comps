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

#line 51 "parser.y"
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
#line 79 "y.tab.c"

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
    0,    1,    1,    1,    1,    2,    2,    2,    2,    2,
    2,    2,    2,    3,    3,    3,    4,    4,    4,    5,
    5,   25,    6,    7,    7,   26,    8,    8,   27,    9,
    9,   10,   11,   11,   12,   12,   12,   12,   12,   12,
   12,   13,   13,   14,   15,   16,   16,   16,   16,   17,
   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,
   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,
   28,   19,   19,   20,   20,   21,   21,   21,   22,   22,
   23,   24,
};
static const YYINT yylen[] = {                            2,
    1,    2,    2,    1,    0,    5,    5,    5,    6,    6,
    6,    6,    8,    1,    1,    1,    1,    1,    1,    2,
    0,    0,    7,    2,    3,    0,    3,    0,    0,    4,
    0,    3,    3,    1,    1,    1,    1,    1,    1,    1,
    0,    3,    6,    2,    2,    1,    1,    2,    2,    2,
    1,    4,    1,    1,    2,    2,    3,    3,    3,    3,
    3,    3,    3,    2,    3,    3,    3,    3,    3,    3,
    0,    5,    3,    1,    3,    1,    1,    1,    6,    8,
    5,    9,
};
static const YYINT yydefred[] = {                         0,
    4,   14,   16,   15,    0,    1,    0,    0,    0,    2,
    0,    0,    3,    0,    0,   22,    0,    0,    0,    0,
    0,    0,    0,    6,    7,    8,    0,    0,   26,    0,
    0,    0,    0,   12,    0,   24,    0,    0,    0,   11,
   10,    9,   17,   18,   19,    0,    0,   25,    0,   27,
    0,   23,   20,   13,   29,    0,    0,    0,    0,    0,
    0,    0,   39,    0,    0,   35,   36,   37,   38,   40,
   76,   77,   78,    0,    0,    0,    0,   44,    0,    0,
    0,    0,    0,   53,    0,   54,    0,   45,    0,    0,
    0,   32,    0,   30,    0,    0,    0,    0,    0,   55,
   56,   64,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   48,   49,    0,    0,   33,
    0,    0,    0,    0,   73,    0,   57,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   60,   61,    0,
   81,    0,    0,   52,    0,    0,    0,    0,    0,    0,
   72,    0,    0,    0,   75,   80,    0,   82,
};
static const YYINT yydgoto[] = {                          5,
    6,    7,    8,   84,   47,    9,   29,   30,   50,   63,
   64,   65,   66,   67,   68,   88,   69,   89,   86,  146,
   70,   71,   72,   73,   22,   38,   74,  126,
};
static const YYINT yysindex[] = {                      -149,
    0,    0,    0,    0,    0,    0, -149,  -19, -149,    0,
  -23, -272,    0, -215, -256,    0,  -18,  -20,    6,   19,
  -11, -125, -118,    0,    0,    0,  -52,  -17,    0,   52,
   35,   41,   42,    0,  -99,    0, -163,   73,   -5,    0,
    0,    0,    0,    0,    0,  -99,   61,    0, -125,    0,
  -57,    0,    0,    0,    0,   91,   96,  106, -124,  114,
   46,  -46,    0,   28,   97,    0,    0,    0,    0,    0,
    0,    0,    0,   73,  114,  114, -120,    0,  -27, -113,
 -107,  114,  114,    0,  513,    0,   46,    0,  402,  114,
  114,    0,  -57,    0,  455,  462,  108,  114,  134,    0,
    0,    0,  478,  114,  114,  114,  114,  114,  114,  114,
  114,  114,  114,  114,  114,    0,    0,  513,  471,    0,
  -57,  -82,  114,  492,    0,  114,    0,   85,   85,   85,
   85,  527,  520,   85,   85,   -6,   -6,    0,    0,  120,
    0,  -57,  396,    0,  506,  142,  114,  -79,  114,  114,
    0,  513,  -57,  485,    0,    0,  -57,    0,
};
static const YYINT yyrindex[] = {                       185,
    0,    0,    0,    0,    0,    0,  185,    0,  185,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  146,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  139,    0,    0,  160,    0,    0,
    0,    0,    0,    0,    0,  139,    0,    0,    0,    0,
  -38,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   77,    0,    0,    0,    0,    0,
    0,    0,    0,  160,    0,    0,    0,    0,  -33,    0,
    0,    0,    0,    0,  -58,    0,  -55,    0,  -40,    0,
    0,    0,  -38,    0,    0,    0,    0,    0,  214,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -37,    0,    0,
  -35,    0,    0,    0,    0,    0,    0,   36,   64,   81,
  104,  419,  436,  132,  155,  -10,   13,    0,    0,    0,
    0,  -35,    0,    0,  162,    0,    0,  -22,    0,    0,
    0,  -12,  -35,    0,    0,    0,  -35,    0,
};
static const YYINT yygindex[] = {                         0,
   33,    0,   10,    9,  166,    0,  164,    0,  145,  177,
  127,   29,    0,    0,    0,    2,    0,  536,    0,   71,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 799
static const YYINT yytable[] = {                         51,
   50,   51,   17,   46,   51,   35,   34,   51,   51,   51,
   51,   51,   99,   51,   90,   12,   16,   37,   47,   21,
   41,   42,   58,   41,   58,   51,   51,   58,   51,   58,
   58,   28,   58,   58,   58,  114,   79,   14,   24,   10,
  115,   13,   23,   46,   91,   59,   43,   59,   58,   58,
   59,   58,   59,   59,   46,   59,   59,   59,   28,   51,
   18,   19,   20,   98,   25,   51,   50,   15,   65,   46,
   65,   59,   59,   65,   59,   65,   65,   26,   82,   65,
   80,   27,   58,   81,   47,   83,   41,   42,  116,   41,
  117,   51,   39,   40,   65,   65,   66,   65,   66,   41,
   42,   66,   79,   66,   66,   59,    1,   66,    2,    3,
    4,   48,   43,   67,   58,   67,   49,   51,   67,   54,
   67,   67,   66,   66,   67,   66,  114,  112,   65,  113,
   75,  115,    2,    3,    4,   76,   68,   59,   68,   67,
   67,   68,   67,   68,   68,   77,   82,   68,   80,  141,
   78,   81,   92,   83,   97,   93,   66,   31,   32,   33,
   65,  100,   68,   68,   62,   68,   62,  101,  123,   62,
  148,   62,   62,   67,  125,   62,   43,   44,   45,  142,
  147,  156,  151,  153,    5,  158,   28,   63,   66,   63,
   62,   62,   63,   62,   63,   63,   68,   21,   63,   56,
   31,   34,   74,   57,   50,   67,   58,   46,   59,   60,
   61,   53,   55,   63,   63,   52,   63,   62,   94,  120,
  155,    0,   47,    0,   62,   42,    0,   41,   68,   51,
    0,   51,    0,    0,    0,   51,   51,   51,   51,   51,
   51,   51,   51,   51,   51,   51,   71,   63,   71,    0,
   43,   71,   58,   71,   58,   11,   62,   36,   58,   58,
   58,   58,   58,   58,   58,   58,   58,   58,   58,    0,
    0,    0,    0,    0,    0,   59,    0,   59,    0,   63,
    0,   59,   59,   59,   59,   59,   59,   59,   59,   59,
   59,   59,    0,    0,    0,    0,    0,    0,   65,    0,
   65,    0,    0,    0,   65,   65,   65,   65,   65,   65,
   65,   65,   65,   65,   65,    0,    0,    0,    0,    0,
   79,   43,   44,   45,   87,    0,   66,    0,   66,    0,
    0,    0,   66,   66,   66,   66,   66,   66,   66,   66,
   66,   66,   66,   67,    0,   67,    0,    0,    0,   67,
   67,   67,   67,   67,   67,   67,   67,   67,   67,   67,
    0,    0,    0,    0,    0,    0,   68,    0,   68,    0,
    0,    0,   68,   68,   68,   68,   68,   68,   68,   68,
   68,   68,   68,    0,    0,    0,    0,    0,   79,   43,
   44,   45,    0,    0,   62,    0,   62,    0,    0,    0,
   62,   62,   62,   62,   62,   62,   62,   62,   62,   62,
   62,    0,    0,    0,    0,    0,    0,   63,    0,   63,
    0,    0,    0,   63,   63,   63,   63,   63,   63,   63,
   63,   63,   63,   63,   82,    0,   80,  114,  112,   81,
  113,   83,  115,  114,  112,    0,  113,    0,  115,    0,
    0,   69,    0,   69,    0,  110,   69,  111,   69,   69,
    0,  110,   69,  111,    0,    0,    0,    0,   70,    0,
   70,    0,    0,   70,    0,   70,   70,   69,    0,   70,
    0,    0,    0,    0,    0,    0,    0,    0,   71,   71,
   71,   71,    0,    0,   70,  121,  114,  112,    0,  113,
    0,  115,  122,  114,  112,    0,  113,    0,  115,    0,
    0,   69,  114,  112,  110,  113,  111,  115,  127,  114,
  112,  110,  113,  111,  115,  157,  114,  112,   70,  113,
  110,  115,  111,  114,  112,    0,  113,  110,  115,  111,
    0,    0,    0,   69,  110,    0,  111,  114,  112,  150,
  113,  110,  115,  111,  114,  112,    0,  113,    0,  115,
   70,  114,  112,  140,  113,  110,  115,  111,  114,  112,
    0,  113,  110,  115,  111,    0,    0,    0,    0,  110,
    0,  111,    0,    0,  144,    0,  110,    0,  111,    0,
    0,    0,    0,    0,    0,   85,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   95,   96,    0,    0,    0,    0,    0,  102,  103,    0,
    0,    0,    0,    0,    0,  118,  119,    0,    0,    0,
    0,    0,    0,  124,    0,    0,    0,    0,    0,  128,
  129,  130,  131,  132,  133,  134,  135,  136,  137,  138,
  139,    0,    0,    0,    0,    0,    0,    0,  143,    0,
  149,  145,    0,    0,  104,  105,  106,  107,  108,  109,
  104,  105,  106,  107,  108,  109,   79,   43,   44,   45,
   87,   69,  152,   69,  154,  145,    0,    0,    0,    0,
    0,   69,   69,   69,   69,   69,   69,   69,   70,    0,
   70,    0,    0,    0,    0,    0,    0,    0,    0,   70,
   70,   70,   70,   70,   70,    0,    0,    0,    0,    0,
    0,    0,    0,  104,  105,  106,  107,  108,  109,    0,
  104,  105,  106,  107,  108,  109,    0,    0,    0,  104,
  105,  106,  107,  108,  109,    0,  104,  105,  106,  107,
  108,  109,    0,  104,  105,  106,  107,  108,  109,    0,
  104,  105,  106,  107,  108,  109,    0,    0,    0,    0,
    0,    0,    0,    0,  104,  105,  106,  107,  108,  109,
    0,  104,  105,  106,  107,  108,  109,    0,  104,  105,
  106,  107,  108,    0,    0,  104,  105,  106,  107,
};
static const YYINT yycheck[] = {                         33,
   59,   35,  275,   59,   38,   58,   59,   41,   42,   43,
   44,   45,   40,   47,   61,   35,   40,   35,   59,  276,
   59,   59,   33,   59,   35,   59,   60,   38,   62,   40,
   41,   22,   43,   44,   45,   42,   59,   61,   59,    7,
   47,    9,   61,   35,   91,   33,   59,   35,   59,   60,
   38,   62,   40,   41,   46,   43,   44,   45,   49,   93,
  276,  277,  278,   91,   59,  123,  125,   91,   33,  125,
   35,   59,   60,   38,   62,   40,   41,   59,   33,   44,
   35,   93,   93,   38,  125,   40,  125,  125,   87,  125,
   89,  125,   41,   59,   59,   60,   33,   62,   35,   59,
   59,   38,  125,   40,   41,   93,  256,   44,  258,  259,
  260,  275,  125,   33,  125,   35,   44,  123,   38,   59,
   40,   41,   59,   60,   44,   62,   42,   43,   93,   45,
   40,   47,  258,  259,  260,   40,   33,  125,   35,   59,
   60,   38,   62,   40,   41,   40,   33,   44,   35,  121,
  275,   38,  125,   40,  275,   59,   93,  276,  277,  278,
  125,  275,   59,   60,   33,   62,   35,  275,   61,   38,
  142,   40,   41,   93,   41,   44,  276,  277,  278,  262,
   61,  153,   41,  263,    0,  157,   41,   33,  125,   35,
   59,   60,   38,   62,   40,   41,   93,   59,   44,  257,
   41,  125,   41,  261,  263,  125,  264,  263,  266,  267,
  268,   46,   49,   59,   60,   39,   62,  275,   74,   93,
  150,   -1,  263,   -1,   93,  263,   -1,  263,  125,  263,
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
   -1,   -1,   -1,   -1,   -1,   60,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   75,   76,   -1,   -1,   -1,   -1,   -1,   82,   83,   -1,
   -1,   -1,   -1,   -1,   -1,   90,   91,   -1,   -1,   -1,
   -1,   -1,   -1,   98,   -1,   -1,   -1,   -1,   -1,  104,
  105,  106,  107,  108,  109,  110,  111,  112,  113,  114,
  115,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,
  265,  126,   -1,   -1,  269,  270,  271,  272,  273,  274,
  269,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  263,  147,  265,  149,  150,   -1,   -1,   -1,   -1,
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
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#define YYUNDFTOKEN 311
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
0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : code",
"code : var code",
"code : func code",
"code : error",
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
"$$1 :",
"func : var_type TK_IDENTIFIER '(' $$1 param_list ')' block",
"param : var_type TK_IDENTIFIER",
"param : var_type '#' TK_IDENTIFIER",
"$$2 :",
"param_list : param $$2 aux_param_list",
"param_list :",
"$$3 :",
"aux_param_list : ',' param $$3 aux_param_list",
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
"$$4 :",
"func_call : TK_IDENTIFIER '(' $$4 call_param_list ')'",
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
#line 505 "parser.y"

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
#line 827 "y.tab.c"

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
#line 125 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_PROGRAM,yystack.l_mark[0].astree,0,0,0,0); astreePrintTree(yyval.astree,"",1); 
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
break;
case 2:
#line 138 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_DECL_LIST,yystack.l_mark[-1].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 3:
#line 139 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_DECL_LIST,yystack.l_mark[-1].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 5:
#line 141 "parser.y"
	{ yyval.astree = 0;}
break;
case 6:
#line 143 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_VAR_DECL,yystack.l_mark[-4].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].symbol),0,0,yystack.l_mark[-3].symbol); 
			yystack.l_mark[-3].symbol->natureza = NATUREZA_ESCALAR;
			define_dataType (yystack.l_mark[-4].astree->type, yystack.l_mark[-3].symbol);
			verify_variable_declaration (yystack.l_mark[-3].symbol);}
break;
case 7:
#line 147 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_VAR_DECL,yystack.l_mark[-4].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].symbol),0,0,yystack.l_mark[-3].symbol); 
			yystack.l_mark[-3].symbol->natureza = NATUREZA_ESCALAR;
			define_dataType (yystack.l_mark[-4].astree->type, yystack.l_mark[-3].symbol);
			verify_variable_declaration (yystack.l_mark[-3].symbol);}
break;
case 8:
#line 151 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_VAR_DECL,yystack.l_mark[-4].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].symbol),0,0,yystack.l_mark[-3].symbol);
			yystack.l_mark[-3].symbol->natureza = NATUREZA_ESCALAR;
			define_dataType (yystack.l_mark[-4].astree->type, yystack.l_mark[-3].symbol);
			verify_variable_declaration (yystack.l_mark[-3].symbol); }
break;
case 9:
#line 155 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_POINT_DECL,yystack.l_mark[-5].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].symbol),0,0,yystack.l_mark[-3].symbol);
			yystack.l_mark[-3].symbol->natureza = NATUREZA_ESCALAR;
			define_dataType (yystack.l_mark[-5].astree->type, yystack.l_mark[-3].symbol);
			verify_variable_declaration (yystack.l_mark[-3].symbol);}
break;
case 10:
#line 159 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_POINT_DECL,yystack.l_mark[-5].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].symbol),0,0,yystack.l_mark[-3].symbol);
			yystack.l_mark[-3].symbol->natureza = NATUREZA_ESCALAR;
			define_dataType (yystack.l_mark[-5].astree->type, yystack.l_mark[-3].symbol);
			verify_variable_declaration (yystack.l_mark[-3].symbol);}
break;
case 11:
#line 163 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_POINT_DECL,yystack.l_mark[-5].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-1].symbol),0,0,yystack.l_mark[-3].symbol);
			yystack.l_mark[-3].symbol->natureza = NATUREZA_ESCALAR;
			define_dataType (yystack.l_mark[-5].astree->type, yystack.l_mark[-3].symbol);
			verify_variable_declaration (yystack.l_mark[-3].symbol);}
break;
case 12:
#line 167 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_VET_DECL,yystack.l_mark[-5].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-2].symbol),0,0,yystack.l_mark[-4].symbol); 			yystack.l_mark[-4].symbol->natureza = NATUREZA_VETOR;
			define_dataType(yystack.l_mark[-5].astree->type, yystack.l_mark[-4].symbol);
			verify_variable_declaration(yystack.l_mark[-4].symbol);}
break;
case 13:
#line 170 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_VET_DECL_INIT,yystack.l_mark[-7].astree,astreeCreate(ASTREE_LIT,0,0,0,0,yystack.l_mark[-4].symbol),yystack.l_mark[-1].astree,0,yystack.l_mark[-6].symbol);
			yystack.l_mark[-6].symbol->natureza = NATUREZA_VETOR;
			define_dataType(yystack.l_mark[-7].astree->type, yystack.l_mark[-6].symbol);
			verify_variable_declaration(yystack.l_mark[-6].symbol);}
break;
case 14:
#line 176 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_CHAR,0,0,0,0,0); yyval.astree->dataType = DATATYPE_ASTREE_CHAR;}
break;
case 15:
#line 177 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_FLOAT,0,0,0,0,0); yyval.astree->dataType = DATATYPE_ASTREE_FLOAT;}
break;
case 16:
#line 178 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_INT,0,0,0,0,0); yyval.astree->dataType = DATATYPE_ASTREE_INTEGER;}
break;
case 17:
#line 181 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_SYMBOL,0,0,0,0, yystack.l_mark[0].symbol); yyval.astree->symbol = yystack.l_mark[0].symbol; 
		yyval.astree->natureza = NATUREZA_ASTREE_ESCALAR;
		yyval.astree->dataType = DATATYPE_ASTREE_INTEGER;}
break;
case 18:
#line 184 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_SYMBOL,0,0,0,0, yystack.l_mark[0].symbol); yyval.astree->symbol = yystack.l_mark[0].symbol; 
		yyval.astree->natureza = NATUREZA_ASTREE_ESCALAR;
		yyval.astree->dataType = DATATYPE_ASTREE_FLOAT;}
break;
case 19:
#line 187 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_SYMBOL,0,0,0,0, yystack.l_mark[0].symbol); yyval.astree->symbol = yystack.l_mark[0].symbol; 
		yyval.astree->natureza = NATUREZA_ASTREE_ESCALAR;
		yyval.astree->dataType = DATATYPE_ASTREE_CHAR;}
break;
case 20:
#line 192 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_SYMBOL_LIST,yystack.l_mark[-1].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 21:
#line 193 "parser.y"
	{yyval.astree = 0;}
break;
case 22:
#line 212 "parser.y"
	{reset_cont();clear_lists();}
break;
case 23:
#line 212 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_FUNC, yystack.l_mark[-6].astree,yystack.l_mark[-2].astree,yystack.l_mark[0].astree,0, yystack.l_mark[-5].symbol); }
break;
case 24:
#line 215 "parser.y"
	{
		yystack.l_mark[0].symbol->natureza = NATUREZA_ESCALAR;
		define_dataType (yystack.l_mark[-1].astree->type, yystack.l_mark[0].symbol);
		verify_variable_declaration (yystack.l_mark[0].symbol);
		yyval.astree = astreeCreate(ASTREE_PARAM, yystack.l_mark[-1].astree,0,0,0, yystack.l_mark[0].symbol);
		put_in_lists(NATUREZA_ESCALAR, yystack.l_mark[0].symbol->dataType);
	}
break;
case 25:
#line 222 "parser.y"
	{ 
		yystack.l_mark[0].symbol->natureza = NATUREZA_POINTER;
		define_dataType (yystack.l_mark[-2].astree->type, yystack.l_mark[0].symbol);
		verify_variable_declaration (yystack.l_mark[0].symbol);
		yyval.astree = astreeCreate(ASTREE_PARAM,yystack.l_mark[-2].astree,0,0,0,yystack.l_mark[0].symbol);
		put_in_lists(NATUREZA_POINTER, yystack.l_mark[0].symbol->dataType);
	}
break;
case 26:
#line 230 "parser.y"
	{inc_cont();}
break;
case 27:
#line 230 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_PARAM_LIST, yystack.l_mark[-2].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 28:
#line 231 "parser.y"
	{yyval.astree = 0;}
break;
case 29:
#line 234 "parser.y"
	{inc_cont();}
break;
case 30:
#line 234 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_PARAM_LIST, yystack.l_mark[-2].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 31:
#line 235 "parser.y"
	{yyval.astree = 0;}
break;
case 32:
#line 238 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_BLOCK,yystack.l_mark[-1].astree,0,0,0,0);}
break;
case 33:
#line 240 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_CMD_LIST, yystack.l_mark[-2].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 34:
#line 241 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 35:
#line 244 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 36:
#line 245 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 37:
#line 246 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 38:
#line 247 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 39:
#line 248 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 40:
#line 249 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 41:
#line 250 "parser.y"
	{yyval.astree = 0;}
break;
case 42:
#line 253 "parser.y"
	{ 
			verify_variable_declared (yystack.l_mark[-2].symbol);			
			yyval.astree =  astreeCreate(ASTREE_ASSIGN_VAR, yystack.l_mark[0].astree, 0, 0, 0, yystack.l_mark[-2].symbol); 
			if(!compareHashTreeNatureza(yystack.l_mark[-2].symbol->natureza,yystack.l_mark[0].astree->natureza))
			{			
				fprintf(stderr,"Erro na linha  %d. Atribuicao de elementos incompativeis.\n", getLineNumber()); 
				set_error_flag();
			}
		}
break;
case 43:
#line 262 "parser.y"
	{ 
			yystack.l_mark[-5].symbol->natureza = NATUREZA_ASTREE_ESCALAR;
			
			yyval.astree =  astreeCreate(ASTREE_ASSIGN_VECTOR, yystack.l_mark[-3].astree, yystack.l_mark[0].astree, 0, 0, yystack.l_mark[-5].symbol);
			if(yystack.l_mark[-5].symbol->natureza != yystack.l_mark[-3].astree->natureza)
			{
				
				fprintf(stderr,"Erro na linha  %d. Atribuicao de elementos incompativeis.\n", getLineNumber()); 
				set_error_flag();
			} 
		}
break;
case 44:
#line 275 "parser.y"
	{ yyval.astree =  astreeCreate(ASTREE_READ, 0, 0, 0, 0, yystack.l_mark[0].symbol); }
break;
case 45:
#line 278 "parser.y"
	{ yyval.astree =  astreeCreate(ASTREE_PRINT, yystack.l_mark[0].astree, 0, 0, 0, 0); }
break;
case 46:
#line 281 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_SYMBOL,0,0,0,0, yystack.l_mark[0].symbol); yyval.astree->symbol = yystack.l_mark[0].symbol; }
break;
case 47:
#line 282 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_EXP,yystack.l_mark[0].astree,0,0,0, 0);}
break;
case 48:
#line 283 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_PRT_LST_ST,yystack.l_mark[0].astree,0,0,0, yystack.l_mark[-1].symbol); yyval.astree->symbol = yystack.l_mark[-1].symbol; }
break;
case 49:
#line 284 "parser.y"
	{ yyval.astree = astreeCreate(ASTREE_PRT_LST,yystack.l_mark[-1].astree,yystack.l_mark[0].astree,0,0, 0); }
break;
case 50:
#line 287 "parser.y"
	{
		yyval.astree = astreeCreate(ASTREE_RETURN, yystack.l_mark[0].astree, 0, 0, 0, 0); 
		if(!compareHashTreeNatureza(yystack.l_mark[0].astree->natureza,functionDataType))
		{
			fprintf(stderr,"Erro na linha  %d. Retorno da funcao invalido.\n", getLineNumber()); 
			set_error_flag();
		}
		functionDataType = 0;
	}
break;
case 51:
#line 297 "parser.y"
	{
			verify_variable_declared (yystack.l_mark[0].symbol);
			yyval.astree = astreeCreate(ASTREE_SYMBOL, 0, 0, 0, 0, yystack.l_mark[0].symbol); 
			yyval.astree = define_astree_nature_and_type(yyval.astree,yystack.l_mark[0].symbol);
}
break;
case 52:
#line 302 "parser.y"
	{
			verify_vector(yystack.l_mark[-3].symbol);
			if(yystack.l_mark[-1].astree->dataType == DATATYPE_ASTREE_FLOAT || DATATYPE_ASTREE_CHAR || yystack.l_mark[-1].astree->natureza == NATUREZA_ASTREE_POINTER)
			{
				fprintf(stderr,"Erro na linha  %d. Indice do vetor %s deveria escalar.\n",getLineNumber(),yystack.l_mark[-3].symbol->text); 
				set_error_flag();
			}			
			yyval.astree = astreeCreate(ASTREE_VECTOR, yystack.l_mark[-1].astree, 0, 0, 0, yystack.l_mark[-3].symbol);
			/*$$ = define_astree_nature_and_type($$,$1); //Talvez deva ser NATUREZA_ESCALAR*/
			yyval.astree = define_astree_type(yyval.astree,yystack.l_mark[-3].symbol);
			yyval.astree->natureza = NATUREZA_ASTREE_ESCALAR;
}
break;
case 53:
#line 314 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 54:
#line 315 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;
yyval.astree->natureza = NATUREZA_ASTREE_ESCALAR;}
break;
case 55:
#line 317 "parser.y"
	{
			verify_pointer(yystack.l_mark[0].symbol);				
			yyval.astree = astreeCreate(ASTREE_SYMBOL_POINT, 0, 0, 0, 0, yystack.l_mark[0].symbol);
			yyval.astree = define_astree_type(yyval.astree,yystack.l_mark[0].symbol);
			yyval.astree->natureza = NATUREZA_ASTREE_ESCALAR;
}
break;
case 56:
#line 323 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_SYMBOL_ADDRESS, 0, 0, 0, 0, yystack.l_mark[0].symbol);}
break;
case 57:
#line 324 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_EXP_BRACKET, yystack.l_mark[-1].astree, 0, 0, 0, 0);
			yyval.astree->dataType = yystack.l_mark[-1].astree->dataType;
			yyval.astree->natureza = yystack.l_mark[-1].astree->natureza;}
break;
case 58:
#line 327 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_SOMA, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); 
	if((yystack.l_mark[-2].astree->natureza == NATUREZA_ASTREE_ESCALAR)&&(yystack.l_mark[0].astree->natureza == NATUREZA_ASTREE_ESCALAR))
			{
		
					if (yystack.l_mark[-2].astree->dataType!=DATATYPE_ASTREE_INTEGER)
						yyval.astree->dataType = DATATYPE_ASTREE_INTEGER;
					else if (yystack.l_mark[-2].astree->dataType!=DATATYPE_ASTREE_CHAR)
						yyval.astree->dataType = DATATYPE_ASTREE_CHAR;
					else if (yystack.l_mark[-2].astree->dataType!=DATATYPE_ASTREE_FLOAT)
						yyval.astree->dataType = DATATYPE_ASTREE_FLOAT;
					yyval.astree->natureza = NATUREZA_ASTREE_ESCALAR;
			}
			else
			{
				if(yystack.l_mark[-2].astree->natureza == NATUREZA_ASTREE_POINTER)
				{
					if((yystack.l_mark[0].astree->natureza != NATUREZA_ASTREE_ESCALAR))
					{
						fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
						set_error_flag();
					}
					else
					{
						yyval.astree->dataType = yystack.l_mark[-2].astree->dataType;
						yyval.astree->natureza = NATUREZA_ASTREE_POINTER;
					}
				}
				else
				{
					if(yystack.l_mark[0].astree->natureza == NATUREZA_ASTREE_POINTER)
					{
						if((yystack.l_mark[-2].astree->natureza != NATUREZA_ASTREE_ESCALAR))
						{
							fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
							set_error_flag();
						}
						else
						{
							yyval.astree->dataType = yystack.l_mark[0].astree->dataType;
							yyval.astree->natureza = NATUREZA_ASTREE_POINTER;
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
break;
case 59:
#line 377 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_SUB, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); 
if((yystack.l_mark[-2].astree->natureza == NATUREZA_ASTREE_ESCALAR)&&(yystack.l_mark[0].astree->natureza == NATUREZA_ASTREE_ESCALAR))
			{
					if (yystack.l_mark[-2].astree->dataType!=DATATYPE_ASTREE_INTEGER)
						yyval.astree->dataType = DATATYPE_ASTREE_INTEGER;
					else if (yystack.l_mark[-2].astree->dataType!=DATATYPE_ASTREE_CHAR)
						yyval.astree->dataType = DATATYPE_ASTREE_CHAR;
					else if (yystack.l_mark[-2].astree->dataType!=DATATYPE_ASTREE_FLOAT)
						yyval.astree->dataType = DATATYPE_ASTREE_FLOAT;

					yyval.astree->natureza = NATUREZA_ASTREE_ESCALAR;
			}
			else
			{
				if(yystack.l_mark[-2].astree->natureza == NATUREZA_ASTREE_POINTER)
				{
					if((yystack.l_mark[0].astree->natureza != NATUREZA_ASTREE_ESCALAR))
					{
						fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
						set_error_flag();
					}
					else
					{
						yyval.astree->dataType = yystack.l_mark[-2].astree->dataType;
						yyval.astree->natureza = NATUREZA_ASTREE_POINTER;
					}
				}
				else
				{
					if(yystack.l_mark[0].astree->natureza == NATUREZA_ASTREE_POINTER)
					{
						if((yystack.l_mark[-2].astree->natureza != NATUREZA_ASTREE_ESCALAR))
						{
							fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
							set_error_flag();
						}
						else
						{
							yyval.astree->dataType = yystack.l_mark[0].astree->dataType;
							yyval.astree->natureza = NATUREZA_ASTREE_POINTER;
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
break;
case 60:
#line 427 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_MULT, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); 

	if(yystack.l_mark[-2].astree->natureza != NATUREZA_ASTREE_ESCALAR
                        || yystack.l_mark[0].astree->natureza != NATUREZA_ASTREE_ESCALAR)
			{
				fprintf(stderr,"Erro na linha  %d. Multiplicacao soh eh permitida entre inteiros (word ou byte).\n", getLineNumber()); 
				set_error_flag();
			}
			yyval.astree->natureza = NATUREZA_ASTREE_ESCALAR;
			if (yystack.l_mark[-2].astree->dataType!=DATATYPE_ASTREE_INTEGER)
						yyval.astree->dataType = DATATYPE_ASTREE_INTEGER;
					else if (yystack.l_mark[-2].astree->dataType!=DATATYPE_ASTREE_CHAR)
						yyval.astree->dataType = DATATYPE_ASTREE_CHAR;
					else if (yystack.l_mark[-2].astree->dataType!=DATATYPE_ASTREE_FLOAT)
						yyval.astree->dataType = DATATYPE_ASTREE_FLOAT;}
break;
case 61:
#line 442 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_DIV, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); 
if(yystack.l_mark[-2].astree->natureza != NATUREZA_ASTREE_ESCALAR
                        || yystack.l_mark[0].astree->natureza != NATUREZA_ASTREE_ESCALAR)
			{
				fprintf(stderr,"Erro na linha  %d. Multiplicacao soh eh permitida entre inteiros (word ou byte).\n", getLineNumber()); 
				set_error_flag();
			}
			yyval.astree->natureza = NATUREZA_ASTREE_ESCALAR;
			if (yystack.l_mark[-2].astree->dataType!=DATATYPE_ASTREE_INTEGER)
						yyval.astree->dataType = DATATYPE_ASTREE_INTEGER;
					else if (yystack.l_mark[-2].astree->dataType!=DATATYPE_ASTREE_CHAR)
						yyval.astree->dataType = DATATYPE_ASTREE_CHAR;
					else if (yystack.l_mark[-2].astree->dataType!=DATATYPE_ASTREE_FLOAT)
						yyval.astree->dataType = DATATYPE_ASTREE_FLOAT;}
break;
case 62:
#line 456 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_LESS, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 63:
#line 457 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_GREAT, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 64:
#line 458 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_NEG, yystack.l_mark[0].astree, 0, 0, 0, 0);}
break;
case 65:
#line 459 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_LE, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0);}
break;
case 66:
#line 460 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_GE, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0);}
break;
case 67:
#line 461 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_EQ, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0);}
break;
case 68:
#line 462 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_NE, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0);}
break;
case 69:
#line 463 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_AND, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 70:
#line 464 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_OR, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0);}
break;
case 71:
#line 467 "parser.y"
	{reset_cont();clear_lists();}
break;
case 72:
#line 467 "parser.y"
	{
			verify_function_declared (yystack.l_mark[-4].symbol);
			yyval.astree = astreeCreate(ASTREE_FUNC_CALL, yystack.l_mark[-1].astree, 0, 0, 0, yystack.l_mark[-4].symbol);

			if(yystack.l_mark[-4].symbol->number_of_param_func != get_cont())
			{
				fprintf(stderr,"Erro na linha  %d. Funcao %s deveria ter %d parametros.\n",getLineNumber(),yystack.l_mark[-4].symbol->text,yystack.l_mark[-4].symbol->number_of_param_func); 
				set_error_flag(); }
			yyval.astree = define_astree_type(yyval.astree,yystack.l_mark[-4].symbol);
			yyval.astree->natureza = NATUREZA_ASTREE_FUNCTION; /*Talvez deva ser NATUREZA_ESCALAR*/
			compare_lists(yystack.l_mark[-4].symbol->list_naturezas, yystack.l_mark[-4].symbol->list_dataTypes,yystack.l_mark[-4].symbol->number_of_param_func);}
break;
case 73:
#line 478 "parser.y"
	{
			verify_function_declared (yystack.l_mark[-2].symbol);
			yyval.astree = astreeCreate(ASTREE_FUNC_CALL, 0, 0, 0, 0, yystack.l_mark[-2].symbol);
			yyval.astree = define_astree_type(yyval.astree,yystack.l_mark[-2].symbol);
			yyval.astree->natureza = NATUREZA_ASTREE_FUNCTION; /*Talvez deva ser NATUREZA_ESCALAR*/

}
break;
case 74:
#line 487 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 75:
#line 488 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_EXP_LIST, yystack.l_mark[-2].astree,yystack.l_mark[0].astree,0,0,0);}
break;
case 76:
#line 491 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 77:
#line 491 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 78:
#line 491 "parser.y"
	{yyval.astree = yystack.l_mark[0].astree;}
break;
case 79:
#line 494 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_IF, yystack.l_mark[-3].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 80:
#line 495 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_IF_ELSE, yystack.l_mark[-5].astree, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 81:
#line 498 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_WHILE, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 82:
#line 501 "parser.y"
	{yyval.astree = astreeCreate(ASTREE_FOR, yystack.l_mark[-4].astree, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, yystack.l_mark[-6].symbol); }
break;
#line 1595 "y.tab.c"
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
