#ifndef TAC_H
#define TAC_H

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"

#define TAC_SYMBOL 1
#define TAC_VECTOR 2
#define TAC_LIT 3
#define TAC_ADD 4
#define TAC_SUB 5
#define TAC_MUL 6
#define TAC_DIV 7

#define TAC_EQ 8
#define TAC_LE 9
#define TAC_GE 10
#define TAC_NE 11
#define TAC_GREATER 12
#define TAC_LESS 13
#define TAC_AND 14
#define TAC_OR 15
#define TAC_NOT 50
#define TAC_MOVE 16

#define TAC_POINTER 17
#define TAC_POINTER_ADDR 18
#define TAC_VECTORDEC1 19
#define TAC_VECTORDEC2 20
#define TAC_POINTER_DEC_NO_INIT 21
#define TAC_POINTER_DEC 22
#define TAC_VARDEC_INIT 23
#define TAC_VARDEC_PARAM 55
#define TAC_FUNCDEC 24
#define TAC_FUNCDEC_PARAMS 25
#define TAC_FUNCDEC_PARAMS2 26
#define TAC_VECTOR_INIT 27
#define TAC_INT 28
#define TAC_FLOAT 29
#define TAC_CHAR 30
#define TAC_IFZ 31
#define TAC_IFNZ 32
#define TAC_RETURN 33
#define TAC_PRINT 34
#define TAC_INPUT 35
#define TAC_VECTOR_WRITE 36
#define TAC_ARG 37
#define TAC_CALL 38
#define TAC_FUNDEC 39
#define TAC_JUMP 40
#define TAC_LABEL 41
#define TAC_TEMP 42
#define TAC_BEGINFUNC 43
#define TAC_ENDFUNC 44
#define TAC_VECTOR_READ 45

#define TAC_VARDEC 46


typedef struct tac_node
{
	int type;
	HASHNODE * res;
	HASHNODE * op1;
	HASHNODE * op2;
	struct tac_node * prev;
} TAC;


TAC * tacCreate(int type, HASHNODE * res, HASHNODE * op1, HASHNODE * op2);
void tacPrintSingle(TAC * tac);
void tacPrintListReverse(TAC * tac);
TAC * tacJoin(TAC * l1, TAC * l2);

TAC * generateCode(ASTREE * root);



TAC * makeOp(int type, TAC * code0, TAC * code1);
TAC * makeIfThen(TAC * code0, TAC * code1);
TAC * makeIfElse(TAC * code0, TAC * code1, TAC * code2);
TAC * makeLoop(HASHNODE * identifier, TAC * code0, TAC * code1, TAC * code2, TAC * code3);
TAC * makeLoopWhile(TAC * code0, TAC * code1, TAC * code2);
TAC * makeVectorAttr(HASHNODE * symbol, TAC * index, TAC * attr);
TAC * makeFuncDecParams(HASHNODE * symbol, TAC * next);
TAC * makeVectorInit(TAC * literal, TAC * next);
TAC * makeOutputParam(TAC * expression, TAC * next);
TAC * makeFuncCall(HASHNODE * symbol, TAC * params);
TAC * makeArg(HASHNODE * symbol, TAC * exp, TAC * next);
TAC * makeFuncDec(HASHNODE * symbol, TAC * param, TAC * cmds);
TAC * makeVectorRead(HASHNODE * symbol, TAC * index);

#endif
