#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"


extern int yylex();
extern int isRunning();
extern int getLineNumber();
extern void initMe();
extern FILE *yyin;
extern int yyparse();


int main (int argc, char *argv[])
{
	initMe();
	int tok = 0;
	
	FILE *inp;	
	if(!(inp = fopen(argv[1], "r"))){
		printf("Erro abrindo o arquivo");
		return 0;	
	} 
	yyin = inp; 
	
 
 
	/*while(isRunning())
	{
 		tok = yylex();	
		if(isRunning()){
		switch (tok)
		{
		case KW_CHAR:
			printf("Olha lá um CHAR na linha %d\n", getLineNumber());
			break;
		case KW_INT:
			printf("Olha lá um INT na linha %d\n", getLineNumber());
			break;
		case KW_FLOAT:
			printf("Olha lá um FLOAT na linha %d\n", getLineNumber());
			break;
		case KW_IF:
			printf("Olha lá um IF na linha %d\n", getLineNumber());
			break;
		case KW_THEN:
			printf("Olha lá um THEN na linha %d\n", getLineNumber());
			break;
		case KW_ELSE:
			printf("Olha lá um ELSE na linha %d\n", getLineNumber());
			break;
		case KW_WHILE:
			printf("Olha lá um WHILE na linha %d\n", getLineNumber());
			break;
		case KW_FOR:
			printf("Olha lá um FOR na linha %d\n", getLineNumber());
			break;
		case KW_READ:
			printf("Olha lá um READ na linha %d\n", getLineNumber());
			break;
		case KW_RETURN:
			printf("Olha lá um RETURN na linha %d\n", getLineNumber());
			break;
		case KW_PRINT:
			printf("Olha lá um PRINT na linha %d\n", getLineNumber());
			break;

		case OPERATOR_LE:
			printf("Olha lá um <= na linha %d\n", getLineNumber());
			break;
		case OPERATOR_GE:
			printf("Olha lá um >= na linha %d\n", getLineNumber());
			break;
		case OPERATOR_EQ:
			printf("Olha lá um == na linha %d\n", getLineNumber());
			break;
		case OPERATOR_NE:
			printf("Olha lá um != na linha %d\n", getLineNumber());
			break;
		case OPERATOR_AND:
			printf("Olha lá um AND na linha %d\n", getLineNumber());
			break;
		case OPERATOR_OR:
			printf("Olha lá um OR na linha %d\n", getLineNumber());
			break;
		case TK_IDENTIFIER:
			printf("Olha lá um ID na linha %d\n", getLineNumber());
			break;
		case LIT_INTEGER:
			printf("Olha lá um INTEIRO na linha %d\n", getLineNumber());
			break;
		case LIT_REAL:
			printf("Olha lá um REAL na linha %d\n", getLineNumber());
			break;
		case LIT_CHAR:
			printf("Olha lá um CHARZAO na linha %d\n", getLineNumber());
			break;
		case LIT_STRING:
			printf("Olha lá um STRING na linha %d\n", getLineNumber());
			break;
		case TOKEN_ERROR:
			printf("Olha lá um ERRO na linha %d\n", getLineNumber());
			break;
		case 0:
			break;
		default:
			printf("Olha lá um %c na linha %d\n",tok, getLineNumber());
			break;
		}
		}	
	}*/

	if(!yyparse())printf("programa aceito");	

	hashPrint();
	fclose(yyin);
	printf("\nTotal de linhas : %d\n", getLineNumber());
	return 0;
}
