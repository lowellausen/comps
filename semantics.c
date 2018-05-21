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
		if(node->symbol->type != SYMBOL_IDENTIFIER){
		printSemanticError("Declaração duplicada de função", node->symbol->text);
		return;
		}
	}
	else if(node->symbol->type != SYMBOL_IDENTIFIER){
		printSemanticError("Declaração duplicada de variável", node->symbol->text);
		return;
	}
	
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
			//setDataType(node, node->son[0]->type);
			setDataType(node, ASTREE_SYMBOL_POINT);
			break;
		case ASTREE_VET_DECL: 
			node->symbol->type = SYMBOL_VEC;
			setDataType(node, node->son[0]->type);
			break;
		case ASTREE_VET_DECL_INIT: 
			node->symbol->type = SYMBOL_VEC; //mudar algo do de cima?
			setDataType(node, node->son[0]->type);
			break;
		case ASTREE_FUNC:
			node->symbol->type = SYMBOL_FUNC;
			setDataType(node, node->son[0]->type);
			int n_par = countDecFuncNumParams(node->son[1]);
			setNumParams(node,n_par);
			break;

	}
}

int countDecFuncNumParams(ASTREE *node){
	if(!node) 
		return 0;
	else
		return 1 + countDecFuncNumParams(node->son[1]);
}

void setNumParams(ASTREE *node, int npar){
	HASHNODE* hash = hashSearch(node->symbol->text);
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
			if(node->symbol->type != SYMBOL_VAR && node->symbol->type != SYMBOL_PTR){
				printSemanticError("Atribuição incompatível",NULL);
			}
			break;
		case ASTREE_SYMBOL_POINT:
			if(node->symbol->type != SYMBOL_PTR){
				printSemanticError("Atribuição incompatível",NULL);
			}
			break;
		case ASTREE_ASSIGN_VECTOR:
			if(node->symbol->type != SYMBOL_VEC){
				printSemanticError("Atribuição incompatível de vetor",NULL);
			}
			break;
		case ASTREE_VECTOR:
			if(node->symbol->type != SYMBOL_VEC){
				printSemanticError("Acesso de vetor incompatível",NULL);
			}
			break;
		case ASTREE_FUNC_CALL:
			if(node->symbol->type != SYMBOL_FUNC){
				printSemanticError("Chamada de função incompatível",NULL);		
			}			
			break;
		//Somente variaveis escalares sao aceitas no comando read e nao vetores ou pos. de vetores
		case ASTREE_READ:
			if(node->symbol->type != SYMBOL_VAR){
				printSemanticError("Read incompatível",NULL);		
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
			printSemanticError("Chamada de função incompatível",node->symbol->text);
		n_par = countFuncCallParams(node->son[0]);
	}		
	HASHNODE* hash = hashSearch(node->symbol->text);
	int correct_n_par = hash->number_of_param_func;
	if(n_par != correct_n_par) //n parametros errado
		printSemanticError("Chamada de função incompatível",node->symbol->text);
}

int verifyFuncCallParams(ASTREE* node){
	if(!node){
		return 1;
	}

	int acc_val = verifyFuncCallParams(node->son[1]);
	if(acc_val == 0){
		return 0; 
	} 
	
	return 1; 
}

int countFuncCallParams(ASTREE* node){
	if(!node)
		return 0;
	else
		return 1 + countFuncCallParams(node->son[1]);
}

int testID(HASHNODE* id,ASTREE* node){
	if(id->type == SYMBOL_VEC || id->type == SYMBOL_FUNC){
		printSemanticError("Vetor/função incompatível", id->text);
		node->dataType = DATATYPE_ASTREE_NAO_DEF;
		return 0;
	}
	return 1;
}


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
			if(node->son[0]->dataType != DATATYPE_ASTREE_INTEGER && node->son[0]->dataType != DATATYPE_ASTREE_CHAR) {
				printSemanticError("Indice de vetor incompatível", node->symbol->text); 
			}
			node->dataType = node->symbol->dataType;
			break;
		case ASTREE_FUNC_CALL:  
			
			verifyParams(node);
			node->dataType = node->symbol->dataType;
			break;
		case ASTREE_LESS:
		case ASTREE_GREAT:
		case ASTREE_LE:
		case ASTREE_GE:
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF || node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("Expressão inválida", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = DATATYPE_ASTREE_BOOLEAN;
			break;
		case ASTREE_EQ:
		case ASTREE_NE:
			if(node->son[0]->dataType == DATATYPE_ASTREE_BOOLEAN || node->son[1]->dataType == DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("Tipos incompatíveis em operação", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF || node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("Tipo inválido em operação", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = DATATYPE_ASTREE_BOOLEAN;
			break;
		case ASTREE_AND:	
		case ASTREE_OR:
			if(node->son[0]->dataType != DATATYPE_ASTREE_BOOLEAN || node->son[1]->dataType != DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("Tipos incompatíveis em operação", NULL); 
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF || node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("Tipo inválido em operação", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = DATATYPE_ASTREE_BOOLEAN;	
			break;
		case ASTREE_NEG:
			if(node->son[0]->dataType != DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("Tipo incompatívei em operação", NULL); 
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("Tipo incompatívei em operação", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = DATATYPE_ASTREE_BOOLEAN;
			break;
		case ASTREE_SYMBOL_ADDRESS:
			if(testID(node->symbol,node))
				node->dataType = DATATYPE_ASTREE_PTR;
			break;
		case ASTREE_SYMBOL_POINT:
			if(testID(node->symbol,node))
				node->dataType = node->symbol->dataType;
			break;
		case ASTREE_SOMA:
			if(node->son[0]->dataType == DATATYPE_ASTREE_BOOLEAN || node->son[1]->dataType == DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("Tipos incompatíveis em operação", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_PTR && node->son[1]->dataType == DATATYPE_ASTREE_PTR){
				printSemanticError("Tipos incompatíveis em operação ", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF || node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("Tipos incompatíveis em operação", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = aritmeticInference(node);
			break;    
		case ASTREE_SUB: 
		case ASTREE_MULT: 
		case ASTREE_DIV: 
			if(node->son[0]->dataType == DATATYPE_ASTREE_BOOLEAN || node->son[1]->dataType == DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("Tipos incompatíveis em operação", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_PTR || node->son[1]->dataType == DATATYPE_ASTREE_PTR){
				printSemanticError("Tipos incompatíveis em operação ", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF || node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("Tipos incompatíveis em operação", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = aritmeticInference(node);
			break;
		case ASTREE_ASSIGN_VAR: 
			if(!verifyAssignmentTypes(node->symbol->dataType, node->son[0]->dataType)){
				printSemanticError("Tipos incompatíveis em atribuição", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("Tipos incompatíveis em atribuição", NULL);
				node->dataType = DATATYPE_ASTREE_NAO_DEF;
			}
			else
				node->dataType = node->symbol->dataType;
			break;
		case ASTREE_ASSIGN_VECTOR: 
			if(node->son[0]->dataType != DATATYPE_ASTREE_INTEGER && node->son[0]->dataType != DATATYPE_ASTREE_CHAR) {
				printSemanticError("Tipo incompatível em indexação de vetor", node->symbol->text); 
			}
			if(!verifyAssignmentTypes(node->symbol->dataType, node->son[1]->dataType)){
				printSemanticError("Tipos incompatíveis em atribuição", NULL);
			}
			if(node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("Tipos incompatíveis em atribuição", NULL);
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
				printSemanticError("Tipos incompatíveis em comando FOR", NULL);	
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF || node->son[1]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("Tipos incompatíveis em comando FOR", NULL);
			}	
			break;
		case ASTREE_WHILE:
			if(node->son[0]->dataType != DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("Tipos incompatíveis em comando WHILE", NULL);	
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("Tipos incompatíveis em comando WHILE", NULL);
			}
			break;	
		case ASTREE_RETURN:	
			if(node->son[0]->dataType == DATATYPE_ASTREE_BOOLEAN){
				printSemanticError("Tipos incompatíveis em comando RETURN", NULL);
			}
			if(node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("Tipos incompatíveis em comando RETURN", NULL);
			}
			break;	
		case ASTREE_READ:
			if(node->symbol->dataType == DATATYPE_ASTREE_BOOLEAN || node->symbol->dataType == DATATYPE_ASTREE_NAO_DEF){
				printSemanticError("Tipos incompatíveis em comando READ", NULL);
			}
			break;
		
		case ASTREE_PRINT:
			if(node->symbol){
				if(node->symbol->dataType != DATATYPE_ASTREE_STRING){
					printSemanticError("Tipos incompatíveis em comando PRINT", NULL);
				}
			}else if(node->son[0]){
				if(node->son[0]->dataType == DATATYPE_ASTREE_BOOLEAN || node->son[0]->dataType == DATATYPE_ASTREE_NAO_DEF){
					printSemanticError("Tipos incompatíveis em comando PRINT", NULL);
				}
			}
	}

	
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
	else if(type1 == DATATYPE_ASTREE_PTR || type2 == DATATYPE_ASTREE_PTR){
		return DATATYPE_ASTREE_PTR;
	}
	if(type1 == DATATYPE_ASTREE_FLOAT || type2 == DATATYPE_ASTREE_FLOAT){
		return DATATYPE_ASTREE_FLOAT;
	}
	else if(type1 == DATATYPE_ASTREE_INTEGER || type2 == DATATYPE_ASTREE_INTEGER){
		return DATATYPE_ASTREE_INTEGER;
	}
	else if(type1 == DATATYPE_ASTREE_CHAR || type2 == DATATYPE_ASTREE_CHAR){
		return DATATYPE_ASTREE_CHAR;
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
