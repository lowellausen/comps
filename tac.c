#include "tac.h"
#include "hash.h"

TAC * tacCreate(int type, HASHNODE * res, HASHNODE * op1, HASHNODE * op2)
{
	TAC * newTac = 0;

	newTac = (TAC*) calloc(1,sizeof(TAC));
	newTac->type = type;
	newTac->res = res;
	newTac->op1 = op1;
	newTac->op2 = op2;
	newTac->prev = 0;
	newTac->next = 0;
	return newTac;
}


void tacPrintSingle(TAC * tac)
{
	if(tac != 0)
	{

		switch(tac->type)
		{
			case TAC_SYMBOL: return; fprintf(stderr, "TAC_SYMBOL "); break; //poluição demais tche
			case TAC_VECTOR:  fprintf(stderr, "TAC_VECTOR "); break;
			case TAC_LIT: fprintf(stderr, "TAC_LIT "); break;
			case TAC_ADD: fprintf(stderr, "TAC_ADD "); break;
			case TAC_SUB: fprintf(stderr, "TAC_SUB "); break;
			case TAC_MUL: fprintf(stderr, "TAC_MUL "); break;
			case TAC_DIV: fprintf(stderr, "TAC_DIV "); break;
			case TAC_EQ: fprintf(stderr, "TAC_EQ "); break;
			case TAC_LE: fprintf(stderr, "TAC_LE "); break;
			case TAC_GE: fprintf(stderr, "TAC_GE "); break;
			case TAC_NE: fprintf(stderr, "TAC_NE "); break;
			case TAC_GREATER: fprintf(stderr, "TAC_GREATER "); break;
			case TAC_LESS: fprintf(stderr, "TAC_LESS "); break;
			case TAC_AND: fprintf(stderr, "TAC_AND "); break;
			case TAC_OR: fprintf(stderr, "TAC_OR "); break;
			case TAC_NOT: fprintf(stderr, "TAC_NOT "); break;
			case TAC_MOVE: fprintf(stderr, "TAC_MOVE "); break;
			case TAC_POINTER: fprintf(stderr, "TAC_POINTER "); break;
			case TAC_POINTER_ADDR: fprintf(stderr, "TAC_POINTER_ADDR "); break;
			case TAC_VECTORDEC1: fprintf(stderr, "TAC_VECTORDEC "); break;
			case TAC_VECTORDEC2: fprintf(stderr, "TAC_VECTORDEC_INIT "); break;
			case TAC_POINTER_DEC_NO_INIT: fprintf(stderr, "TAC_POINTER_DEC_NO_INIT "); break;
			case TAC_POINTER_DEC: fprintf(stderr, "TAC_POINTER_DEC "); break;
			case TAC_VARDEC: fprintf(stderr, "TAC_VARDEC "); break;
			case TAC_VARDEC_INIT: fprintf(stderr, "TAC_VARDEC_INIT "); break;
			case TAC_VARDEC_PARAM: fprintf(stderr, "TAC_VARDEC_PARAM "); break;
			case TAC_FUNCDEC: fprintf(stderr, "TAC_FUNDEC "); break;
			case TAC_FUNCDEC_PARAMS: fprintf(stderr, "TAC_FUNDEC_PARAMS "); break;
			case TAC_FUNCDEC_PARAMS2: fprintf(stderr, "TAC_FUNDEC_PARAMS2 "); break;
			case TAC_VECTOR_INIT: fprintf(stderr, "TAC_VECTOR_INIT "); break;
			case TAC_CHAR: fprintf(stderr, "TAC_CHAR "); break;
			case TAC_INT: fprintf(stderr, "TAC_INT "); break;
			case TAC_FLOAT: fprintf(stderr, "TAC_FLOAT "); break;
			case TAC_IFZ: fprintf(stderr, "TAC_IFZ "); break;
			case TAC_IFNZ: fprintf(stderr, "TAC_IFNZ "); break;
			case TAC_RETURN: fprintf(stderr, "TAC_RETURN "); break;
			case TAC_PRINT: fprintf(stderr, "TAC_PRINT "); break;
			case TAC_INPUT: fprintf(stderr, "TAC_INPUT "); break;
			case TAC_VECTOR_WRITE: fprintf(stderr, "TAC_VECTOR_WRITE "); break;
			case TAC_ARG: return ;fprintf(stderr, "TAC_ARG "); break; // estranho tbm
			case TAC_CALL: fprintf(stderr, "TAC_CALL "); break;
			case TAC_FUNDEC: fprintf(stderr, "TAC_FUNDEC "); break;
			case TAC_JUMP: fprintf(stderr, "TAC_JUMP "); break;
			case TAC_LABEL: fprintf(stderr, "TAC_LABEL "); break;
			case TAC_TEMP: fprintf(stderr, "TAC_TEMP "); break;
			case TAC_BEGINFUNC: fprintf(stderr, "TAC_BEGINFUNC "); break;
			case TAC_ENDFUNC: fprintf(stderr, "TAC_ENDFUNC "); break;
			case TAC_VECTOR_READ: fprintf(stderr, "TAC_VECTOR_READ "); break;

			default: fprintf(stderr, "UNKNOWN %d", tac->type);
		}
		if(tac->res)
			fprintf(stderr, "res(%s) ", tac->res->text);
		if(tac->op1)
			fprintf(stderr, "op1(%s) ", tac->op1->text);
		if(tac->op2)
			fprintf(stderr, "op2(%s) ", tac->op2->text);
		fprintf(stderr, "\n");
	}
}


void tacPrintListReverse(TAC * tac)
{
	if(tac != 0)
	{
		tacPrintListReverse(tac->prev);
		tacPrintSingle(tac);
	}
}

void tacPrintList(TAC * tac)
{
	if(tac != 0)
	{
		tacPrintSingle(tac);
		tacPrintList(tac->next);
	}

}

TAC * tacReverse(TAC * tac)
{
	if(tac == 0)
		return;

	TAC * aux;

	for(aux = tac; aux->prev; aux = aux->prev)
		aux->prev->next = aux;

	return aux;
}

TAC * tacJoin(TAC * l1, TAC * l2)
{
	TAC * aux;

	if(l1 == 0) return l2;
	if(l2 == 0) return l1;

	for(aux = l2 ; aux->prev != 0 ; aux = aux->prev)
	{
	}

	aux->prev = l1;
	return l2;
}

TAC * generateCode(ASTREE * root)
{
	int i;
	TAC * code[MAXSONS];
	for(i=0; i < MAXSONS; i++)
		code[i] = 0;

	if(root != 0)
	{
		// Process children first
		for(i=0; i < MAXSONS; i++)
			code[i] = generateCode(root->son[i]);

		switch(root->type)
		{
			case ASTREE_SYMBOL: return tacCreate(TAC_SYMBOL, root->symbol, 0, 0);
			case ASTREE_VECTOR: return makeVectorRead(root->symbol, code[0]);
			case ASTREE_SOMA: return makeOp(TAC_ADD, code[0], code[1]);
			case ASTREE_SUB: return makeOp(TAC_SUB, code[0], code[1]);
			case ASTREE_MULT: return makeOp(TAC_MUL, code[0], code[1]);
			case ASTREE_DIV: return makeOp(TAC_DIV, code[0], code[1]);
			case ASTREE_EQ: return makeOp(TAC_EQ, code[0], code[1]);
			case ASTREE_LE: return makeOp(TAC_LE, code[0], code[1]);
			case ASTREE_GE: return makeOp(TAC_GE, code[0], code[1]);
			case ASTREE_NE: return makeOp(TAC_NE, code[0], code[1]);
			case ASTREE_GREAT: return makeOp(TAC_GREATER, code[0], code[1]);
			case ASTREE_LESS: return makeOp(TAC_LESS, code[0], code[1]);
			case ASTREE_AND: return makeOp(TAC_AND, code[0], code[1]);
			case ASTREE_OR: return makeOp(TAC_OR, code[0], code[1]);
			case ASTREE_NEG: return makeOp(TAC_NOT, code[0], 0);
			case ASTREE_ASSIGN_VAR: return tacJoin(code[0], tacCreate(TAC_MOVE, root->symbol, code[0] ? code[0]->res : 0, 0));
			case ASTREE_POINTER: return tacCreate(TAC_POINTER, root->symbol, 0, 0);
			case ASTREE_SYMBOL_POINT: return tacCreate(TAC_POINTER_ADDR, root->symbol, 0, 0);

			case ASTREE_VET_DECL: return tacCreate(TAC_VECTORDEC1, root->symbol, root->son[1] ? root->son[1]->symbol : 0,0);
			case ASTREE_VET_DECL_INIT: return tacCreate(TAC_VECTORDEC2, root->symbol, root->son[1] ? root->son[1]->symbol : 0, 0);

			case ASTREE_POINT_DECL: return tacCreate(TAC_POINTER_DEC, root->symbol, root->son[1] ? root->son[1]->symbol : 0, 0);
			case ASTREE_ASSIGN_VECTOR: return makeVectorAttr(root->symbol, code[0], code[1]);

			case ASTREE_VAR_DECL: return tacCreate(TAC_VARDEC_INIT, root->symbol,root->son[1]->symbol, 0);
            case ASTREE_PARAM: return tacCreate(TAC_VARDEC_PARAM, root->symbol,(HASHNODE*)root->son[1], 0);

			case ASTREE_FUNC: return makeFuncDec(root->symbol, code[1], code[2]);


			/*case ASTREE_CHAR:	return tacCreate(TAC_CHAR, root->symbol, 0, 0);
			case ASTREE_INT:	return tacCreate(TAC_INT, root->symbol, 0, 0);
			case ASTREE_FLOAT:	return tacCreate(TAC_FLOAT, root->symbol, 0, 0);*/

			case ASTREE_DECL_LIST: return tacJoin(code[0], code[1]);

			case ASTREE_EXP_BRACKET: return code[0];

			case ASTREE_IF: return makeIfThen(code[0], code[1]);
			case ASTREE_IF_ELSE: return makeIfElse(code[0], code[1], code[2]);

			case ASTREE_BLOCK:	return code[0];
			case ASTREE_CMD_LIST: return tacJoin(code[0],code[1]);
			case ASTREE_SYMBOL_LIST: return tacJoin(code[0],code[1]);

			// ANTIGO case ASTREE_OUTPUT_PARAM:
			case ASTREE_EXP_LIST: return tacJoin(code[0],makeArg(root->symbol, code[0], code[1]));
			case ASTREE_RETURN: return tacJoin(code[0], tacCreate(TAC_RETURN, code[0] ? code[0]->res : 0, 0, 0));
			case ASTREE_PRINT: return tacJoin(code[0], tacCreate(TAC_PRINT, code[0] ? code[0]->res : 0, 0, 0));
			case ASTREE_READ: return tacJoin(code[0], tacCreate(TAC_INPUT, root->symbol, 0, 0));
			case ASTREE_FOR: return makeLoop(root->symbol, code[0], code[1], code[2], code[3]);
			case ASTREE_WHILE: return makeLoopWhile(code[0], code[1], code[2]);


			//NÃO TEMOS DISTINÇÃO ENTRE PARAMETROS DE FUNÇÃO E LISTA DE EXPRESSÕES! case ASTREE_FUNCPARAMS: return makeArg(root->symbol, code[0], code[1]);????????????????????????????TODO
			case ASTREE_FUNC_CALL: return makeFuncCall(root->symbol, code[0]);

			default:  return tacJoin(tacJoin(tacJoin(code[0],code[1]),code[2]),code[3]);
			break;
		}

	}
	else
	{
		return 0;
	}

}

TAC * makeOp(int type, TAC * code0, TAC * code1)
{
	return tacJoin(tacJoin(code0,code1),
			tacCreate(type,(HASHNODE *)makeTemp(), code0 ? code0->res : 0, code1 ? code1->res : 0));
}

TAC * makeIfThen(TAC * code0, TAC * code1)
{
	TAC * tacIfThen;
	TAC * tacLabel;
	HASHNODE * newLabel;

	// EXP
	// IFZ
	// THEN CMD
	// LABEL

	newLabel = makeLabel();
	tacIfThen = tacCreate(TAC_IFZ, code0 ? code0->res : 0, newLabel, 0);
	tacLabel = tacCreate(TAC_LABEL, newLabel, 0, 0);
	return tacJoin(tacJoin(tacJoin(code0, tacIfThen), code1), tacLabel);
}


TAC * makeIfElse(TAC * code0, TAC * code1, TAC * code2)
{
	TAC * tacIfElse;
	TAC * tacLabel;
	HASHNODE * newLabel;

	// EXP
	// IFNZ
	// THEN CMD
	// LABEL

	newLabel = makeLabel();
	tacIfElse = tacCreate(TAC_IFZ, 0, code0 ? code0->res : 0, newLabel);
	tacLabel = tacCreate(TAC_LABEL, newLabel, 0, 0);
	return tacJoin(tacJoin(tacJoin(tacJoin(code0, tacIfElse), code1), tacLabel), code2);
}

TAC * makeLoop(HASHNODE * identifier, TAC * code0, TAC * code1, TAC * code2, TAC * code3)
{
	HASHNODE * loopLabelBegin = makeLabel();
	HASHNODE * loopLabelInit = makeLabel();
	HASHNODE * loopLabelEnd = makeLabel();
	TAC * labelBegin = tacCreate(TAC_LABEL, loopLabelBegin, 0, 0);
	TAC * labelEnd = tacCreate(TAC_LABEL, loopLabelEnd, 0, 0);

	TAC * idsymb = tacCreate(TAC_SYMBOL,identifier,0,0);
	TAC * initid = tacJoin(code0, tacCreate(TAC_MOVE, identifier, code0 ? code0->res : 0, 0));

	TAC * jmpBegin = tacCreate(TAC_JUMP, 0, loopLabelBegin, 0);
	TAC * jmpEnd = tacCreate(TAC_IFZ, 0, loopLabelEnd, code1 ? code1->res : 0);


        // INIT
	// LABELBEGIN
        // EXP
        // IFZ -> LABELEND
        // LOOP CMD
        // INC
        // JUMP LABELBEGIN
        // LABELEND


                                                                       //INIT  [BEGIN] [IF-EXP][JMPEND][CMD]  [INC]  [JMPBEGIN][END]
	//return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(code0, labelBegin), code1),jmpEnd),code3),code2),jmpBegin),labelEnd);
	return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(idsymb, initid), code1),jmpEnd),code3),code2),jmpBegin),labelEnd);
}

TAC * makeLoopWhile(TAC * code0, TAC * code1, TAC * code2){

    HASHNODE *beginLabel = makeLabel();
    HASHNODE *endLabel = makeLabel();
    TAC* tacBeginLabel = tacCreate(TAC_LABEL, beginLabel,0, 0);
    TAC *tacEndLabel = tacCreate(TAC_LABEL, endLabel,0, 0);
    TAC *j0 = tacCreate(TAC_IFZ, endLabel, code0?code0->res:0, NULL);
    TAC *j1 = tacCreate(TAC_JUMP, beginLabel,0,0);
    return tacJoin(tacBeginLabel,tacJoin(code0,tacJoin(j0,tacJoin(code1,tacJoin(j1,tacEndLabel)))));
}


TAC * makeVectorAttr(HASHNODE * symbol, TAC * index, TAC * attr)
{
	TAC * code;

	code = tacCreate(TAC_VECTOR_WRITE, symbol, index ? index->res : 0, attr ? attr->res : 0);

	return tacJoin(tacJoin(index, attr), code);

}


TAC * makeVectorInit(TAC * literal, TAC * next)
{
	TAC * new;

	new = tacCreate(TAC_VECTOR_INIT, literal ? literal->res : 0, 0, 0);

	return tacJoin(new, next);

}

TAC * makeOutputParam(TAC * expression, TAC * next)
{
	TAC * new;

	new = tacCreate(TAC_PRINT, expression ? expression->res : 0, 0, 0);

	return tacJoin(next, new);
}

TAC * makeFuncCall(HASHNODE * symbol, TAC * params)
{
	TAC * new;
	HASHNODE * temp = makeTemp();

	new = tacCreate(TAC_CALL, temp, symbol, params ? params->res : 0);

	return tacJoin(params, new);
}

TAC * makeArg(HASHNODE * symbol, TAC * exp, TAC * next)
{
	TAC * new;
	TAC * temp;

	// TAC_ARG (FX, argumento, n parâmetro)
	new = tacCreate(TAC_ARG, symbol, exp ? exp->res : 0, 0);

	return tacJoin(new,next);
}


TAC * makeFuncDec(HASHNODE * symbol, TAC * param, TAC * cmds)
{
	TAC * beginFunc = tacCreate(TAC_BEGINFUNC, symbol, 0, 0);
	TAC * endFunc = tacCreate(TAC_ENDFUNC, symbol, 0, 0);


	param = tacJoin(beginFunc, param);
	cmds = tacJoin(param, cmds);
	endFunc = tacJoin(cmds, endFunc);
	return endFunc;
}


TAC * makeVectorRead(HASHNODE * symbol, TAC * index)
{
	TAC * new;
	HASHNODE * tempResult = makeTemp();

	new = tacCreate(TAC_VECTOR_READ, tempResult, symbol, index ? index->res : 0);

	return tacJoin(index, new);
}
