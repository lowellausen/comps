#ifndef ASTREE_H
#define ASTREE_H

#include <stdio.h>

#define MAXSONS 4

#define ASTREE_SYMBOL 1

#define ASTREE_CHAR 2
#define ASTREE_INT 3
#define ASTREE_FLOAT 4

#define ASTREE_WHILE 5
#define ASTREE_IF 6
#define ASTREE_IF_ELSE 7
#define ASTREE_FOR 8
#define ASTREE_READ 9
#define ASTREE_RETURN 10
#define ASTREE_PRINT 11

#define ASTREE_VAR_DECL 12
#define ASTREE_POINT_DECL 13
#define ASTREE_VET_DECL 14
#define ASTREE_VET_DECL_INIT 15

#define ASTREE_SYMBOL_LIST 16
#define ASTREE_PARAM 17
#define ASTREE_PARAM_LIST 18

#define ASTREE_FUNC 19

#define ASTREE_BLOCK 20
#define ASTREE_VECTOR 21
#define ASTREE_FUNC_CALL 22

#define ASTREE_SOMA 32
#define ASTREE_SUB 33
#define ASTREE_MULT 34 
#define ASTREE_DIV 35

#define ASTREE_NEG 36 
#define ASTREE_POINTER 37 
#define ASTREE_ADRESS 38 

#define ASTREE_LE 39 
#define ASTREE_GE 40 
#define ASTREE_EQ 41 
#define ASTREE_NE 42 
#define ASTREE_AND 43 
#define ASTREE_OR 44 
#define ASTREE_LESS 45 
#define ASTREE_GREAT 46 
#define ASTREE_EXP_BRACKET 47

#define ASTREE_EXP_LIST 48
#define ASTREE_CMD_LIST 49

#define ASTREE_PROGRAM 50
#define ASTREE_DECL_LIST 51

#define ASTREE_ASSIGN_VECTOR 52
#define ASTREE_ASSIGN_VAR 53

#define ASTREE_LIT_INT 54
#define ASTREE_SYMBOL_POINT 55
#define ASTREE_SYMBOL_ADDRESS 56

#define DEBUG 94944040

typedef struct ASTREE
	{
	int type;
	int value;
	int printed;
	HASH_NODE* symbol;
	struct ASTREE *son[MAX_SONS];
	
	}ASTREE;

ASTREE *astreeCreate( int type, ASTREE *s0, ASTREE *s1, ASTREE *s2, ASTREE *s3, HASH_NODE *n );
void astreesPrintSingle (ASTREE *node);
void astreePrintTree (ASTREE *node, int level);

FILE* outputfile;

#endif




