#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "astree.h"

ASTREE *astreeCreate( int type, ASTREE *s0, ASTREE *s1, ASTREE *s2, ASTREE *s3, HASHNODE *n ) {
	ASTREE *node = 0;
	
	node = (ASTREE*) calloc (1,sizeof(ASTREE));
	node->type = type;
	node->son[0] = s0;
	node->son[1] = s1;
	node->son[2] = s2;
	node->son[3] = s3;
	
	node->symbol = n;
	node->printed = 0;

	return node;
}

void astreePrintSingle (ASTREE *node, char *gap, int level)
{
	if (!node)
		return;
	if(node->printed==1)
		return;
	node->printed = 1;

	char *gapson; 
	gapson = (char *)malloc(level*3 * sizeof(char));
	strcat(gap," ");	
	strcpy(gapson,gap);
	

	switch (node->type)
	{
		case DEBUG:
		    if(node->symbol)
			fprintf(outputfile, " %s", node->symbol->text);		   
		    astreePrintSingle (node->son[0],gapson, level+1);		    
		    astreePrintSingle (node->son[1],gapson, level+1);		    
		    astreePrintSingle (node->son[2],gapson, level+1);
		break;
		case ASTREE_SYMBOL: 
			if(node->symbol && printTree) printf("%sSimbolo:%s\n", gap, node->symbol->text);
			if(node->symbol)
			   fprintf(outputfile, "%s", node->symbol->text);
		break;
		case ASTREE_SYMBOL_POINT: 
			if(node->symbol && printTree) printf("%sSimboloPonteiro:%s\n", gap, node->symbol->text);
			if(node->symbol)
			   fprintf(outputfile, "#%s", node->symbol->text);			
		break;
		case ASTREE_SYMBOL_ADDRESS: 
			if(node->symbol && printTree) printf("%sSimboloEndereço:%s\n", gap, node->symbol->text);
			fprintf(outputfile, "&");
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			break;
		case ASTREE_CHAR: 
			fprintf(outputfile, "char ");
			if(printTree) printf("%schar\n",gap);
			break;
		case ASTREE_INT:
			fprintf(outputfile, "int ");
			if(printTree) printf("%sint\n",gap);
			break;
		case ASTREE_FLOAT: 
			fprintf(outputfile, "float ");
			if(printTree) printf("%sfloat\n",gap);
			break;

		case ASTREE_VAR_DECL: 
		        astreePrintSingle (node->son[0],gapson, level+1);
			if(node->symbol && printTree) printf("%sDeclaraçãoVar:%s\n", gap, node->symbol->text);
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			fprintf(outputfile, "=");
			astreePrintSingle (node->son[1],gapson, level+1);
			fprintf(outputfile, ";\n");
			break;
		case  ASTREE_LIT:
			if(printTree) printf("%sLiteral:%s\n", gap, node->symbol->text); 
                        fprintf(outputfile,"%s",node->symbol->text); 
                        break;
		case ASTREE_POINT_DECL:
			astreePrintSingle (node->son[0],gapson, level+1);
			if(node->symbol && printTree) printf("%sCeclaraçãoPoint:%s\n", gap, node->symbol->text);
			fprintf(outputfile, "#");
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			fprintf(outputfile, " = ");
			astreePrintSingle (node->son[1],gapson, level+1);
			fprintf(outputfile, ";\n");
			break;
		case ASTREE_VET_DECL: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(node->symbol && printTree) printf("%sDeclaraçãoVet:%s\n", gap, node->symbol->text);
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			fprintf(outputfile, "[");
			astreePrintSingle (node->son[1],gapson, level+1);
			fprintf(outputfile, "]");
			fprintf(outputfile, ";\n");
			 break;
		case ASTREE_VET_DECL_INIT: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(node->symbol && printTree) printf("%sDeclInitVet:%s\n", gap, node->symbol->text);
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			fprintf(outputfile, "[");
			astreePrintSingle (node->son[1],gapson, level+1);
			fprintf(outputfile, "] : ");
			astreePrintSingle (node->son[2],gapson, level+1);
			fprintf(outputfile, ";\n");
			break;

		case ASTREE_SYMBOL_LIST: 
			astreePrintSingle (node->son[0],gapson, level+1);
			fprintf(outputfile, " ");
			astreePrintSingle (node->son[1],gapson, level+1);
			break;

     	        case ASTREE_PARAM_LIST: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(node->son[1])
				fprintf(outputfile, ", ");
			astreePrintSingle (node->son[1],gapson, level+1);
			break;
		case ASTREE_PARAM: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(node->symbol && printTree) printf("%sParametro:%s\n", gap, node->symbol->text);
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			break;

		case ASTREE_FUNC: 
			fprintf(outputfile, "\n\n");
			astreePrintSingle (node->son[0],gapson, level+1);
			if(node->symbol && printTree) printf("%sDeclaraçãoFunção:%s\n", gap, node->symbol->text);
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			fprintf(outputfile, "(");	
			astreePrintSingle (node->son[1],gapson, level+1);
			fprintf(outputfile, ")\n");
			astreePrintSingle (node->son[2],gapson, level+1);
			break;	

		case ASTREE_VECTOR:
			if(node->symbol && printTree) printf("%sExprVet:%s\n", gap, node->symbol->text); 
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			fprintf(outputfile, "[");
			astreePrintSingle (node->son[0],gapson, level+1);
			fprintf(outputfile, "]");
			break;
		
		case ASTREE_EXP_BRACKET:
			fprintf(outputfile,"(");
			astreePrintSingle (node->son[0],gapson, level+1);
			fprintf(outputfile,")");
			break;

		case ASTREE_FUNC_CALL:
			if(node->symbol && printTree) printf("%sChamadaFunção:%s\n", gap, node->symbol->text); 
			if(node->symbol)
				fprintf(outputfile, "%s (", node->symbol->text);
			if (node->son[0])
		        	astreePrintSingle (node->son[0],gapson, level+1);
			fprintf(outputfile, ")");
			break;

		case ASTREE_SOMA: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(printTree) printf("%sSoma:\n", gap);
			fprintf(outputfile, "+");
			astreePrintSingle (node->son[1],gapson, level+1);
			break;
		case ASTREE_SUB: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(printTree) printf("%sSubtração:\n", gap);
			fprintf(outputfile, "-");
			astreePrintSingle (node->son[1],gapson, level+1);
			break;
		case ASTREE_DIV: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(printTree) printf("%sDivisão:\n", gap);
			fprintf(outputfile, "/");
			astreePrintSingle (node->son[1],gapson, level+1);
			break;
		case ASTREE_MULT:
			astreePrintSingle (node->son[0],gapson, level+1);
			if(printTree) printf("%sMultiplicação:\n", gap);
			fprintf(outputfile, "*");
			astreePrintSingle (node->son[1],gapson, level+1);
			break;
		case ASTREE_LE:
			astreePrintSingle (node->son[0],gapson, level+1);
			if(printTree) printf("%sMenorIgual:\n", gap);
			fprintf(outputfile, "<=");
			astreePrintSingle (node->son[1],gapson, level+1);
			break;
		case ASTREE_GE: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(printTree) printf("%sMaiorIgual:\n", gap);
			fprintf(outputfile, ">=");
			astreePrintSingle (node->son[1],gapson, level+1);
			break;
		case ASTREE_EQ: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(printTree) printf("%sIgual:\n", gap);
			fprintf(outputfile, "== ");
			astreePrintSingle (node->son[1],gapson, level+1); 
			break;
		case ASTREE_NE: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(printTree) printf("%sDiferente:\n", gap);
			fprintf(outputfile, "!= ");
			astreePrintSingle (node->son[1],gapson, level+1); 
			break;
		case ASTREE_AND: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(printTree) printf("%sAnd:\n", gap);
			fprintf(outputfile, "&& ");
			astreePrintSingle (node->son[1],gapson, level+1); 
			break;
		case ASTREE_OR: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(printTree) printf("%sOr:\n", gap);
			fprintf(outputfile, "|| ");
			astreePrintSingle (node->son[1],gapson, level+1); 
			break;
		case ASTREE_LESS: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(printTree) printf("%sMenor:\n", gap);
			fprintf(outputfile, "< ");
			astreePrintSingle (node->son[1],gapson, level+1); 
			break;
		case ASTREE_GREAT: 
			astreePrintSingle (node->son[0],gapson, level+1);
			if(printTree) printf("%sMaior:\n", gap);
			fprintf(outputfile, "> ");
			astreePrintSingle (node->son[1],gapson, level+1); 
			break;
		case ASTREE_NEG: 
			if(printTree) printf("%sNegação:\n", gap);
			fprintf(outputfile, "!(");
			astreePrintSingle (node->son[0],gapson, level+1); 
			fprintf(outputfile, ") ");
			break;

		case ASTREE_EXP_LIST: 
			astreePrintSingle (node->son[0],gapson, level+1);
			fprintf(outputfile, ", ");
			astreePrintSingle (node->son[1],gapson, level+1);
			break;
 
 		case ASTREE_CMD_LIST: 
			astreePrintSingle (node->son[0],gapson, level+1);
			fprintf(outputfile, ";");
			fprintf(outputfile, "\n");
			astreePrintSingle (node->son[1],gapson, level+1);
			break;
 	
 		case ASTREE_ASSIGN_VAR:  
			if(node->symbol && printTree) printf("%sAtribuição:%s\n", gap, node->symbol->text);                        
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			fprintf(outputfile, "= ");
			astreePrintSingle (node->son[0],gapson, level+1);
			break;
		case ASTREE_ASSIGN_VECTOR:    
			if(node->symbol && printTree) printf("%sAtribuiçãoVet:%s\n", gap, node->symbol->text);            
			fprintf(outputfile,"%s",node->symbol->text);
			fprintf(outputfile, "[");
			astreePrintSingle (node->son[0],gapson, level+1);
			fprintf(outputfile, "]");
                        fprintf(outputfile, " = ");
			astreePrintSingle (node->son[1],gapson, level+1);
			break;

		case ASTREE_IF: 
			if(printTree) printf("%sIF:\n", gap); 
			fprintf(outputfile, "if( ");
			astreePrintSingle (node->son[0],gapson, level+1);
			fprintf(outputfile, ") then ");
			astreePrintSingle (node->son[1],gapson, level+1); 
			break;
		case ASTREE_IF_ELSE: 
			if(printTree) printf("%sIFELSE:\n", gap); 
			fprintf(outputfile, "if( ");
			astreePrintSingle (node->son[0],gapson, level+1);
			fprintf(outputfile, ") then ");
			astreePrintSingle (node->son[1],gapson, level+1);
			fprintf(outputfile, " else ");
			astreePrintSingle (node->son[2],gapson, level+1);
			break;
						 
		case ASTREE_FOR: 
			if(printTree) printf("%sFOR:\n", gap); 
			fprintf(outputfile, "for ");
			fprintf(outputfile, "(");
			fprintf(outputfile,"%s",node->symbol->text);
			fprintf(outputfile, " = ");
			astreePrintSingle (node->son[0],gapson, level+1); 
			fprintf(outputfile, " to ");
			astreePrintSingle (node->son[1],gapson, level+1); 
			fprintf(outputfile, ") ");
			astreePrintSingle (node->son[2],gapson, level+1); 
			break;

		case ASTREE_WHILE: 
			if(printTree) printf("%sWHILE:\n", gap); 
			fprintf(outputfile, "while ");
			fprintf(outputfile, "(");
			astreePrintSingle (node->son[0],gapson, level+1);
			fprintf(outputfile, ") ");
			astreePrintSingle (node->son[1],gapson, level+1); 
			break;
		case ASTREE_READ:
			if(printTree) printf("%sRead:\n", gap); 
			fprintf(outputfile, "read ");
			fprintf(outputfile,"%s",node->symbol->text);
			break;
		case ASTREE_RETURN:
			if(printTree) printf("%sResturn:\n", gap); 
			fprintf(outputfile, "return ");
			astreePrintSingle (node->son[0],gapson, level+1);
			break;

		case ASTREE_PRINT:
			if(printTree) printf("%sPrint:\n", gap); 
			fprintf(outputfile, "print ");
			astreePrintSingle (node->son[0],gapson, level+1);
			break;
		case ASTREE_PROGRAM: 
			if(printTree) printf("%sPrograma!\n", gap); 
			astreePrintSingle (node->son[0],gapson, level+1);
			break;

		case ASTREE_DECL_LIST: 
			if(printTree) printf("%sListaDeclarações:\n", gap); 
			astreePrintSingle (node->son[0],gapson, level+1);
			astreePrintSingle (node->son[1],gapson, level+1); 
			break;
		case ASTREE_PRT_LST_ST: 
			if(printTree) printf("%sListaParametros:\n", gap); 
			fprintf(outputfile,"%s",node->symbol->text);
			astreePrintSingle (node->son[0],gapson, level+1);
			break;
		case ASTREE_EXP:
			if(printTree) printf("%sExpressão:\n", gap); 
			astreePrintSingle (node->son[0],gapson, level+1);
			break;
		case ASTREE_PRT_LST: 
			if(printTree) printf("%sLstaParametros:\n", gap); 
			astreePrintSingle (node->son[0],gapson, level+1);
			astreePrintSingle (node->son[1],gapson, level+1);
			break;
		case ASTREE_BLOCK: 
			if(printTree) printf("%sBloco:\n", gap); 
			fprintf(outputfile,"{\n");
			astreePrintSingle (node->son[0],gapson, level+1);
			fprintf(outputfile,"}\n");
			break;
	}
	free(gapson);
}

void astreePrintTree(ASTREE * node, char *gap, int level) {
	int i = 0;
		
	if(!node) return;

	char *gapson; 
	gapson = (char *)malloc(level*3 * sizeof(char));
	strcpy(gapson,gap);
	
	
	astreePrintSingle(node, gapson, level);

	strcat(gapson,"  ");



	for(i=0;i<MAXSONS;i++)
		if(node->son[i])
			astreePrintTree(node->son[i],gapson, level +1);



	free(gapson);
}
