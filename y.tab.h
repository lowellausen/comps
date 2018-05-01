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
extern YYSTYPE yylval;
