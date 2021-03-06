#ifndef ASTREE_H
#define ASTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

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

#define ASTREE_SYMBOL_LIST 16  //nada na tac?
#define ASTREE_PARAM 17		//nada na tac?	
#define ASTREE_PARAM_LIST 18	//nada na tac?

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
#define ASTREE_ADRESS 38     //nada na tac?

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

#define ASTREE_PROGRAM 50     //nada na tac?
#define ASTREE_DECL_LIST 51

#define ASTREE_ASSIGN_VECTOR 52
#define ASTREE_ASSIGN_VAR 53
   
#define ASTREE_LIT 54            //nada na tac?
#define ASTREE_SYMBOL_POINT 55
#define ASTREE_SYMBOL_ADDRESS 56  //nada na tac?

#define ASTREE_PRT_LST_ST 57     //nada na tac?
#define ASTREE_EXP 58           //nada na tac?
#define ASTREE_PRT_LST 59       //nada na tac?

#define DEBUG 94944040

#define   SYMBOL_UNDEFINED  	0 
#define   SYMBOL_LIT_INTEGER  	1 
#define   SYMBOL_LIT_REAL 	2 
#define   SYMBOL_LIT_CHAR   	3 
#define   SYMBOL_LIT_STRING  	4 
#define   SYMBOL_IDENTIFIER  	5 
#define   SYMBOL_VAR 		6
#define   SYMBOL_VEC 		7
#define   SYMBOL_FUNC 		8
#define   SYMBOL_PTR 		9



/*#define NATUREZA_ASTREE_NAO_DEF 60
#define NATUREZA_ASTREE_ESCALAR 61
#define NATUREZA_ASTREE_STRING  62
#define NATUREZA_ASTREE_VETOR   63
#define NATUREZA_ASTREE_POINTER 64
#define NATUREZA_ASTREE_FUNCTION 65*/

#define DATATYPE_ASTREE_NAO_DEF 66
#define DATATYPE_ASTREE_INTEGER 67
#define DATATYPE_ASTREE_CHAR 68
#define DATATYPE_ASTREE_FLOAT 69
#define DATATYPE_ASTREE_STRING 71
#define DATATYPE_ASTREE_PTR 72

#define DATATYPE_ASTREE_BOOLEAN 70 //usar para definir nodos de expressões??

typedef struct ASTREE
	{
	int type;
	int value;
	int printed;
	int natureza;
	int dataType;
	HASHNODE* symbol;
	struct ASTREE *son[MAXSONS];
	
	}ASTREE;

int printTree;

ASTREE *astreeCreate( int type, ASTREE *s0, ASTREE *s1, ASTREE *s2, ASTREE *s3, HASHNODE *n );
void astreesPrintSingle (ASTREE *node, char *gap, int level);
void astreePrintTree (ASTREE *node, char *gap, int level);

FILE* outputfile;

#endif




