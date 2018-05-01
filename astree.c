#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"

ASTREE *astreeCreate( int type, ASTREE *s0, ASTREE *s1, ASTREE *s2, ASTREE *s3, HASH_NODE *n ) {
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

void astreePrintSingle (ASTREE *node)
{
	if (!node)
		return;
	if(node->printed==1)
		return;
	node->printed = 1;

	switch (node->type)
	{
		case DEBUG:
		    if(node->symbol)
			fprintf(outputfile, " %s ", node->symbol->text);		   
		    astreePrintSingle (node->son[0]);		    
		    astreePrintSingle (node->son[1]);		    
		    astreePrintSingle (node->son[2]);
		break;
		case ASTREE_SYMBOL: 
			if(node->symbol)
			   fprintf(outputfile, "%s ", node->symbol->text);
		break;
		case ASTREE_SYMBOL_POINT: 
			if(node->symbol)
			   fprintf(outputfile, "#%s ", node->symbol->text);
		break;
		case ASTREE_SYMBOL_ADDRESS: 
			fprintf(outputfile, "&");
			if(node->symbol)
				fprintf(outputfile, "%s ", node->symbol->text);
			break;
		case ASTREE_CHAR: 
			fprintf(outputfile, "char ");
			break;
		case ASTREE_INT: 
			fprintf(outputfile, "int ");
			break;
		case ASTREE_FLOAT: 
			fprintf(outputfile, "float ");
			break;

		case ASTREE_VAR_DECL:
			astreePrintSingle (node->son[0]);
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			astreePrintSingle (node->son[1]);
			fprintf(outputfile, ";\n");
			break;
		case ASTREE_VAR_DECL: 
		        astreePrintSingle (node->son[0]);
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			fprintf(outputfile, ":");
			astreePrintSingle (node->son[1]);
			fprintf(outputfile, ";\n");
			break;
		case  ASTREE_LIT_INT: 
                        fprintf(outputfile,"%s",node->symbol->text); 
                        break;
		case ASTREE_POINT_DECL:
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "#");
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			fprintf(outputfile, " : ");
			astreePrintSingle (node->son[1]);
			fprintf(outputfile, ";\n");
			break;
		case ASTREE_VET_DECL: 
			astreePrintSingle (node->son[0]);
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			fprintf(outputfile, "[");
			astreePrintSingle (node->son[1]);
			fprintf(outputfile, "]");
			fprintf(outputfile, ";\n");
			 break;
		case ASTREE_VET_DECL_INIT: 
			astreePrintSingle (node->son[0]);
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			fprintf(outputfile, "[");
			astreePrintSingle (node->son[1]);
			fprintf(outputfile, "] : ");
			astreePrintSingle (node->son[2]);
			fprintf(outputfile, ";\n");
			break;

		case ASTREE_SYMBOL_LIST: 
			astreePrintSingle (node->son[0]);
			astreePrintSingle (node->son[1]);
			break;

     	        case ASTREE_PARAM_LIST: 
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, ", ");
			astreePrintSingle (node->son[1]);
			break;
		case ASTREE_PARAM: 
			astreePrintSingle (node->son[0]);
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			break;

		case ASTREE_FUNC: 
			astreePrintSingle (node->son[0]);
			if(node->symbol)
				fprintf(outputfile, " %s", node->symbol->text);
			fprintf(outputfile, "( ");	
			astreePrintSingle (node->son[1]);
			fprintf(outputfile, ")\n");
			break;	

		case ASTREE_VECTOR: 
			if(node->symbol)
				fprintf(outputfile, "%s", node->symbol->text);
			fprintf(outputfile, "[");
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "]");
			break;
		
		case ASTREE_EXP_BRACKET:
			fprintf(outputfile,"(");
			astreePrintSingle (node->son[0]);
			fprintf(outputfile,")");
			break;

		case ASTREE_FUNC_CALL: 
			if(node->symbol)
				fprintf(outputfile, "%s (", node->symbol->text);
			if (node->son[0])
		        	astreePrintSingle (node->son[0]);
			fprintf(outputfile, ")");
			break;

		case ASTREE_SOMA: 
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "+ ");
			astreePrintSingle (node->son[1]);
			break;
		case ASTREE_SUB: 
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "- ");
			astreePrintSingle (node->son[1]);
			break;
		case ASTREE_DIV: 
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "/ ");
			astreePrintSingle (node->son[1]);
			break;
		case ASTREE_MULT:
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "* ");
			astreePrintSingle (node->son[1]);
			break;
		case ASTREE_LE:
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "<= ");
			astreePrintSingle (node->son[1]);
			break;
		case ASTREE_GE: 
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, ">= ");
			astreePrintSingle (node->son[1]);
			break;
		case ASTREE_EQ: 
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "== ");
			astreePrintSingle (node->son[1]); 
			break;
		case ASTREE_NE: 
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "!= ");
			astreePrintSingle (node->son[1]); 
			break;
		case ASTREE_AND: 
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "&& ");
			astreePrintSingle (node->son[1]); 
			break;
		case ASTREE_OR: 
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "|| ");
			astreePrintSingle (node->son[1]); 
			break;
		case ASTREE_LESS: 
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "< ");
			astreePrintSingle (node->son[1]); 
			break;
		case ASTREE_GREAT: 
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "> ");
			astreePrintSingle (node->son[1]); 
			break;
		case ASTREE_OP_NEG: 
			fprintf(outputfile, "!(");
			astreePrintSingle (node->son[0]); 
			fprintf(outputfile, ") ");
			break;

		case ASTREE_EXP_LIST: 
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, ", ");
			astreePrintSingle (node->son[1]);
			break;
 
 		case ASTREE_CMD_LIST: 
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, "\n");
			astreePrintSingle (node->son[1]);
			fprintf(outputfile, ";");
			break;
 	
 		case ASTREE_ASSIGN_VAR:                         
			if(node->symbol)
				fprintf(outputfile, " %s ", node->symbol->text);
			fprintf(outputfile, "= ");
			astreePrintSingle (node->son[0]);
			break;
		case ASTREE_ASSIGN_VECTOR:               
			astreePrintSingle (node->son[0]);
                        fprintf(outputfile, "= ");
			astreePrintSingle (node->son[1]);
			break;

		case ASTREE_IF: 
			fprintf(outputfile, "if( ");
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, ") then ");
			astreePrintSingle (node->son[1]); 
			break;
		case ASTREE_IF_ELSE: 
			fprintf(outputfile, "if( ");
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, ") then ");
			astreePrintSingle (node->son[1]);
			fprintf(outputfile, " else ");
			astreePrintSingle (node->son[2]);
			break;
						 
		case ASTREE_FOR: 
			fprintf(outputfile, "for ");
			fprintf(outputfile, "(");
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, " = ");
			astreePrintSingle (node->son[1]); 
			fprintf(outputfile, " to ");
			astreePrintSingle (node->son[2]); 
			fprintf(outputfile, ") ");
			astreePrintSingle (node->son[3]); 
			break;

		case ASTREE_WHILE: 
			fprintf(outputfile, "while ");
			fprintf(outputfile, "(");
			astreePrintSingle (node->son[0]);
			fprintf(outputfile, ") ");
			astreePrintSingle (node->son[1]); 
			break;
		case ASTREE_READ:
			fprintf(outputfile, "read ");
			astreePrintSingle (node->son[0]);
			break;
		case ASTREE_RETURN:
			fprintf(outputfile, "return ");
			astreePrintSingle (node->son[0]);
			break;

		case ASTREE_PRINT:
			fprintf(outputfile, "print ");
			astreePrintSingle (node->son[0]);
			break;
		case ASTREE_PROGRAM: 
			astreePrintSingle (node->son[0]);
			break;

		case ASTREE_DECL_LIST: 
			astreePrintSingle (node->son[0]);
			astreePrintSingle (node->son[1]); 
			break;

	}
}

void astreePrintTree(ASTREE * node, int level) {
	int i = 0;
		
	if(!node) return;
	
	astreePrintSingle(node);

	for(i=0;i<MAX_SONS;i++)
		if(node->son[i])
			astreePrintTree(node->son[i],level+1);
}
