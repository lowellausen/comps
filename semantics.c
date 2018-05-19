#include "semantics.h"

//extern HASHNODE *hashTable;

int semanticFullCheck(ASTREE *node){
	hashCheckUndeclared();	
	checkAstNodeDataType(node);
	checkSymbolsUse(node);
	return semanticErrors;
}

void setSymbolAndDataType(ASTREE *node, int type){

	if (type == ASTREE_FUNC){
		if(node->son[0]->symbol->type != TK_IDENTIFIER){
		printSemanticError("funcao declarada mais de uma vez", node->son[0]->symbol->text);
		return;
		}
	}
	else if(node->symbol->type != TK_IDENTIFIER){
		printSemanticError("variavel declarada mais de uma vez", node->symbol->text);
		return;
	}
	
/*	if(node->symbol)
		printf("node %s type %d\n",node->symbol->text,type);
	else
		printf("node %s type %d\n",node->son[0]->symbol->text,type);
*/
	switch(type){
		case ASTREE_PARAM:	
			node->symbol->type = SYMBOL_VAR;
			setDataType(node, node->son[0]->type);
			break;
		case ASTREE_VAR_DECL: 				
			node->symbol->type = SYMBOL_VAR;
			setDataType(node, node->son[0]->type);
			break;
		case ASTREE_POINT_DECL: 				
			node->symbol->type = SYMBOL_PTR;
			setDataType(node, node->son[0]->type);
			break;
		case ASTREE_VET_DECL: 
			node->symbol->type = SYMBOL_VEC;
			setDataType(node, node->son[0]->son[0]->type);
			break;
		case ASTREE_VET_DECL_INIT: 
			node->symbol->type = SYMBOL_VEC; //mudar algo do de cima??#TODO
			setDataType(node, node->son[0]->son[0]->type);
			break;
		case ASTREE_FUNC:
			node->son[0]->symbol->type = SYMBOL_FUNC;
			setDataType(node->son[0], node->son[0]->son[0]->type);
			int n_par = countDecFuncNumParams(node->son[0]->son[1]);
			setNumParams(node,n_par);
			break;

	}
}

int countDecFuncNumParams(ASTREE *node){
	if(!node) // if NULL = end of list
		return 0;
	else
		return 1 + countDecFuncNumParams(node->son[1]);
}

void setNumParams(ASTREE *node, int npar){
	int address = getHashAddress(node->son[0]->symbol->text);
	HASHNODE* hash = hashInsert(node->son[0]->symbol->text, address);
	hash->number_of_param_func = npar;
}

void setDataType(ASTREE *node, int type){
	switch(type){
		case ASTREE_INT: node->symbol->dataType = DATATYPE_ASTREE_INTEGER; break;
		case ASTREE_CHAR: node->symbol->dataType = DATATYPE_ASTREE_CHAR; break;
		case ASTREE_FLOAT: node->symbol->dataType = DATATYPE_ASTREE_FLOAT; break;
		case ASTREE_SYMBOL_POINT: node->symbol->dataType = DATATYPE_ASTREE_PTR; break;
		default: node->symbol->dataType = DATATYPE_ASTREE_NAO_DEF; break;
	}
	node->dataType = node->symbol->dataType;
}

void checkSymbolsUse(ASTREE *node){
	if(node == NULL){
		return;
	}
	
	switch(node->type){
		case ASTREE_ASSIGN_VAR:
			if(node->symbol->type != SYMBOL_VAR){
				printSemanticError("expressao de atribuicao invalida",NULL);
			}
			break;
		case ASTREE_SYMBOL_POINT:
			if(node->symbol->type != SYMBOL_PTR){
				printSemanticError("expressao de atribuicao invalida",NULL);
			}
			break;
		case ASTREE_ASSIGN_VECTOR:
			if(node->symbol->type != SYMBOL_VEC){
				printSemanticError("expressao de atribuicao de vetor invalida",NULL);
			}
			break;
		case ASTREE_VECTOR:
			if(node->symbol->type != SYMBOL_VEC){
				printSemanticError("expressao de acesso ao vetor invalida",NULL);
			}
			break;
		case ASTREE_FUNC_CALL:
			if(node->symbol->type != SYMBOL_FUNC){
				printSemanticError("expressao de chamada de funcao invalida",NULL);		
			}			
			break;
		//Somente variaveis escalares sao aceitas no comando read e nao vetores ou pos. de vetores
		case ASTREE_READ:
			if(node->symbol->type != SYMBOL_VAR){
				printSemanticError("comando 'read' invalido, apenas valores escalares sao aceitos",NULL);		
			}			
			break;		
	}

	int i;
	for(i=0; i<MAXSONS; i++){
		checkSymbolsUse(node->son[i]);
	}
}

void verifyParams(ASTREE* node){
	int n_par = 0;
	if(node->son[0]){
		int val = verifyFuncCallParams(node->son[0]);
		if(!val) 
			printSemanticError("ha parametros booleanos na chamada da funcao",node->symbol->text);
		n_par = countFuncCallParams(node->son[0]);
	}		
	HASHNODE* hash = hashSearch(node->symbol->text);
	int correct_n_par = hash->number_of_param_func;
	if(n_par != correct_n_par)
		printSemanticError("numero invalido de parametros na chamada da funcao",node->symbol->text);
}

int verifyFuncCallParams(ASTREE* node){
	if(!node){
		return 1;
	}
	// undefined pq alguem pode tentar colocar uma string ou var q n exista
	if( node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF){
		return 0; //indicativo de invalidez (algum parametro eh -1)
	}
	int acc_val = verifyFuncCallParams(node->son[1]);
	if(acc_val == 0){
		return 0; //se no resto da lista tem bool, retorna false
	} 
	
	return 1; //apenas retorna true se o tipo dessa nao eh booleano e nao tem nenhuma outra bool no resto da lista
}

int countFuncCallParams(ASTREE* node){
	if(!node)
		return 0;
	else
		return 1 + countFuncCallParams(node->son[1]);
}

int testID(HASHNODE* id,ASTREE* node){
	if(id->type == SYMBOL_VEC || id->type == SYMBOL_FUNC){
		printSemanticError("uso invalido de vetor/funcao", id->text);
		node->dataType = DATATYPE_ASTREE_NAO_DEF;
		return 0;
	}
	return 1;
}


//TODO : verificar print
void checkAstNodeDataType(ASTREE *node){
	if(node == NULL){
		return;
	}

	int i;
	for(i=0; i<MAXSONS; i++){
		checkAstNodeDataType(node->son[i]);
	}

	switch(node->type){
		case ASTREE_SYMBOL:
			if(testID(node->symbol,node))
				node->dataType = node->symbol->dataType;
			break;		
		case ASTREE_VECTOR:
			if(node->son[0]->dataType != DATATYPE_INTEGER && node->son[0]->dataType != DATATYPE_CHAR) {
				printSemanticError("indice do vetor deve ser do tipo inteiro", node->symbol->text); 
			}
			node->dataType = node->symbol->dataType;
			break;
		case ASTREE_FUNC_CALL:  // not sure if node->symbol->dataType ou node->symbol->type
			// talvez uma condicao a mais se for literal
			verifyParams(node);
			node->dataType = node->symbol->dataType;
			break;
		case ASTREE_LESS:
		case ASTREE_GREAT:
		case ASTREE_LE:
		case ASTREE_GE:
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF || node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("expressao UNDEFINED em operacao relacional", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = DATATYPE_ASTREE_BOOLEAN;
			break;
		case ASTREE_EQ:
		case ASTREE_NE:
	//ACHO QUE N PODE TER  BOOL EM LADO NENHUM
			/*if((node->son[0]->dataType == DATATYPE_ASTREE_BOOLEAN && node->son[1]->dataType != DATATYPE_ASTREE_BOOLEAN) || 
			(node->son[1]->dataType == DATATYPE_ASTREE_BOOLEAN && node->son[0]->dataType != DATATYPE_ASTREE_BOOLEAN)){
				printSemanticError("conflito de tipos em operação de eq/ne", NULL);
			}*/
			if(node->son[0]->dataType == DATATYPE_ASTREE_BOOLEAN || node->son[1]->dataType == DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("conflito de tipos em operação de eq/ne", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF || node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("expressao UNDEFINED em operacao relacional", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = DATATYPE_ASTREE_BOOLEAN;
			break;
		case ASTREE_AND:	
		case ASTREE_OR:
			if(node->son[0]->dataType != DATATYPE_ASTREE_BOOLEAN || node->son[1]->dataType != DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("expressao booleana esperada em operacao and/or", NULL); 
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF || node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("expressao UNDEFINED em operacao relacional", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = DATATYPE_ASTREE_BOOLEAN;	
			break;
		case ASTREE_NEG:
			if(node->son[0]->dataType != DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("expressao booleana esperada em operacao not", NULL); 
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("expressao UNDEFINED em operacao NOT", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = DATATYPE_ASTREE_BOOLEAN;
			break;
		case ASTREE_SOMA:
			if(node->son[0]->dataType == DATATYPE_ASTREE_BOOLEAN || node->son[1]->dataType == DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("expressao booleana nao esperada em expressao aritmetica", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_PTR && node->son[1]->dataType == DATATYPE_ASTREE_PTR){
				printSemanticError("soma de 2 ponteiros nao esperada ", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF || node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("expressao UNDEFINED em operacao aritmetica", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = aritmeticInference(node);
			break;    
		case ASTREE_SUB: 
		case ASTREE_MULT: 
		case ASTREE_DIV: 
			if(node->son[0]->dataType == DATATYPE_ASTREE_BOOLEAN || node->son[1]->dataType == DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("expressao booleana nao esperada em expressao aritmetica", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_PTR || node->son[1]->dataType == DATATYPE_ASTREE_PTR){
				printSemanticError("expressão aritmética de ponteiros não esperada ", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF || node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("expressao UNDEFINED em operacao aritmetica", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = aritmeticInference(node);
			break;
		case ASTREE_ASSIGN_VAR: 
			if(!verifyAssignmentTypes(node->symbol->dataType, node->son[0]->dataType)){
				printSemanticError("conflito de tipos na atribuicao", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("expressao UNDEFINED em comando ASSIGN", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = node->symbol->dataType;
			break;
		case ASTREE_ASSIGN_VECTOR: 
			if(node->son[0]->dataType != DATATYPE_INTEGER && node->son[0]->dataType != DATATYPE_CHAR) {
				printSemanticError("indice do vetor em atribuicao v#indice deve ser do tipo inteiro", node->symbol->text); 
			}
			if(!verifyAssignmentTypes(node->symbol->dataType, node->son[1]->dataType)){
				printSemanticError("conflito de tipos na atribuicao", NULL);
			}
			if(node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("expressao UNDEFINED em comando ASSIGN", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = node->symbol->dataType;
			break;
		case ASTREE_EXP_BRACKET:
			node->dataType = node->son[0]->dataType;
			break;
		case ASTREE_FOR:
			if(node->son[0]->dataType == DATATYPE_ASTREE_BOOLEAN || node->son[1]->dataType == DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("expresao booleana em comando FOR", NULL);	
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF || node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("expressao UNDEFINED em comando FOR", NULL);
			}	
			break;
		case ASTREE_WHILE:
			if(node->son[0]->dataType != DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("expresao booleana esperada em comando WHILE", NULL);	
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("expressao UNDEFINED em comando WHILE", NULL);
			}
			break;	
		case ASTREE_RETURN:	
			if(node->son[0]->dataType == DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("comando RETURN do tipo booleano nao esperado", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("expressao UNDEFINED em comando RETURN", NULL);
			}
			break;	
		case ASTREE_READ:
			if(node->symbol->dataType == DATATYPE_ASTREE_BOOLEAN || node->symbol->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("comando READ com tipo nao esperado", NULL);
			}
			break;
		// print é uma lista de elementos onde cada elemento pode ser um string ou expressao aritmetica
		case ASTREE_PRINT:
			if(node->symbol){
				if(node->symbol->dataType != DATATYPE_ASTREE_STRING){
					printSemanticError("comando PRINT com simbolo nao esperado, deve ser string", NULL);
				}
			}else if(node->son[0]){
				if(node->son[0]->dataType == DATATYPE_ASTREE_BOOLEAN || node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF){
					printSemanticError("comando PRINT com expressao nao esperada, deve ser aritmetica", NULL);
				}
			}
	}

	//printf("type: %d datatype: %d \n", node->type, node->dataType);
}
int aritmeticInference(ASTREE *node){
	// eh soh isso ?? 
	return typeInference(node->son[0]->dataType, node->son[1]->dataType);

}

int typeInference(int type1, int type2){
	if(type1 == DATATYPE_ASTREE_NAO_DEF || type2 == DATATYPE_ASTREE_NAO_DEF){
		return DATATYPE_ASTREE_NAO_DEF;
	}
	if(type1 == DATATYPE_ASTREE_BOOLEAN || type2 == DATATYPE_ASTREE_BOOLEAN){
		return DATATYPE_ASTREE_NAO_DEF;
	}

	if(type1 == DATATYPE_FLOAT || type2 == DATATYPE_FLOAT){
		return DATATYPE_FLOAT;
	}
	else if(type1 == DATATYPE_INTEGER || type2 == DATATYPE_INTEGER){
		return DATATYPE_INTEGER;
	}
	else if(type1 == DATATYPE_CHAR || type2 == DATATYPE_CHAR){
		return DATATYPE_CHAR;
	}
	else{ 
		return DATATYPE_ASTREE_NAO_DEF;
	}	
}

int verifyAssignmentTypes(int type1, int type2){
	if(type1 == DATATYPE_ASTREE_BOOLEAN || type2 == DATATYPE_ASTREE_BOOLEAN){
		return 0;
	}
	if(type1 == DATATYPE_ASTREE_NAO_DEF || type2 == DATATYPE_ASTREE_NAO_DEF){
		return 0;
	}
	return 1;
}

void hashCheckUndeclared(){
	HASHNODE *node;
	int i;	 
	for(i=0; i<HASH_TABLE_SIZE; i++){
		for(node=hashTable[i]; node; node=node->next){ 
			if(node->type == SYMBOL_IDENTIFIER){
				//erro variavel nao declarada
				printSemanticError("variavel nao declarada", node->text); 
			}
		}
	} 
}

void printSemanticError(char* errorDesc, char* param){
	if(param != NULL){
		fprintf(stderr,"Erro semantico: %s [%s].\n", errorDesc, param);	
	}else{
		fprintf(stderr,"Erro semantico: %s.\n", errorDesc);	
	}
	semanticErrors++;	
}
