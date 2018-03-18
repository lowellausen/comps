#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "hash.h"

extern int yyin;
extern int yylex();
extern int isRunning();
extern int getLineNumber();
extern void initMe();

int main (int argc, char *argv[])
{
	initMe();
	int tok = 0;
	printf("%s", argv[1]);
	
	/*FILE *inp;	
	if(!(inp = fopen(argv[1], "r"))){
		printf("Erro abrindo o arquivo");
		return 0;	
	} 
	yyin = inp; */
	
 	int it = 5;
 
	while(it >= 0)
	{	it--;
 		tok = yylex();	
		
		switch (tok)
		{
		case KW_CHAR:
			printf("Olha lá um CHAR na linha %d", getLineNumber());
			break;
		case KW_INT:
			printf("Olha lá um INT na linha %d", getLineNumber());
			break;
		case KW_FLOAT:
			printf("Olha lá um FLOAT na linha %d", getLineNumber());
			break;
		case KW_IF:
			printf("Olha lá um IF na linha %d", getLineNumber());
			break;
		case KW_THEN:
			printf("Olha lá um THEN na linha %d", getLineNumber());
			break;
		case KW_ELSE:
			printf("Olha lá um ELSE na linha %d", getLineNumber());
			break;
		case KW_WHILE:
			printf("Olha lá um WHILE na linha %d", getLineNumber());
			break;
		case KW_FOR:
			printf("Olha lá um FOR na linha %d", getLineNumber());
			break;
		case KW_READ:
			printf("Olha lá um READ na linha %d", getLineNumber());
			break;
		case KW_RETURN:
			printf("Olha lá um RETURN na linha %d", getLineNumber());
			break;
		case KW_PRINT:
			printf("Olha lá um PRINT na linha %d", getLineNumber());
			break;

		case OPERATOR_LE:
			printf("Olha lá um <= na linha %d", getLineNumber());
			break;
		case OPERATOR_GE:
			printf("Olha lá um >= na linha %d", getLineNumber());
			break;
		case OPERATOR_EQ:
			printf("Olha lá um == na linha %d", getLineNumber());
			break;
		case OPERATOR_NE:
			printf("Olha lá um != na linha %d", getLineNumber());
			break;
		case OPERATOR_AND:
			printf("Olha lá um AND na linha %d", getLineNumber());
			break;
		case OPERATOR_OR:
			printf("Olha lá um OR na linha %d", getLineNumber());
			break;
		case TK_IDENTIFIER:
			printf("Olha lá um ID na linha %d", getLineNumber());
			break;
		case LIT_INTEGER:
			printf("Olha lá um INTEIRO na linha %d", getLineNumber());
			break;
		case LIT_REAL:
			printf("Olha lá um REAL na linha %d", getLineNumber());
			break;
		case LIT_CHAR:
			printf("Olha lá um CHARZAO na linha %d", getLineNumber());
			break;
		case LIT_STRING:
			printf("Olha lá um STRING na linha %d", getLineNumber());
			break;
		case TOKEN_ERROR:
			printf("Olha lá um ERRO na linha %d", getLineNumber());
			break;
		case 0:
			break;
		default:
			printf("Olha lá um %c na linha %d",tok, getLineNumber());
			break;
		}	
	}
	printf("\nTinha %d linhas.\n", getLineNumber());
	hashPrint();
	//fclose(yyin);
	exit(0);
}
