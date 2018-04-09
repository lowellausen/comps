#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "y.tab.h"


extern int yylex();
extern int isRunning();
extern int getLineNumber();
extern void initMe();
extern FILE *yyin;
extern int yyparse();


int main (int argc, char *argv[])
{
	FILE *inp;
	if (!(inp = fopen(argv[1], "r"))) {
		printf ("Erro na abertura do arquivo.\n");
	        exit (2);
	}
	yyin = inp;

	initMe(); 
	if(!yyparse())
		printf("Programa aceito.");
	fclose(yyin);
	printf("\nTotal de linhas : %d\n", getLineNumber());
	exit(0);
}
