#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"
#include "semantics.h"
#include "y.tab.h"


extern int yylex();
extern int isRunning();
extern int getLineNumber();
extern void initMe();
extern FILE *yyin;
extern int yyparse();
extern FILE *outputfile;
extern int printTree;


int main (int argc, char *argv[])
{
   extern FILE *yyin;
   if (argc < 2)
   {
      printf ("Falta o nome do arquivo.\n");
      exit(1);
   }
   yyin = fopen (argv[1],"r");
   if (yyin == NULL)
   {
      printf ("Erro na abertura do arquivo.\n");
      exit (2);
   }

   if (!(outputfile = fopen(argv[2], "w")))
   {
      fprintf(stderr, "Cannot create output file...\n");
      exit(3);
   }

   printTree=0;	
   
   initMe(); 

   yyparse();

	//semanticFullCheck(ast);

   fclose(outputfile);
	//hashPrint();
   
  
   exit(0);
}
