%{
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"
#include "y.tab.h"


int lineCount = 1;
int running = 1;

extern HASHNODE *table[HASH_TABLE_SIZE];

%}

%x COMMENT

%%



if	{return TK_IF;}
then 	{return TK_THEN;}
else	{return TK_ELSE;}
while	{return TK_WHILE;}
int	{return TK_INT;}
float	{return TK_FLOAT;}
for	{return TK_FOR;}
to	{return TK_TO;}
read	{return TK_READ;}
return	{return TK_RETURN;}
print	{return TK_PRINT;}
char	{return TK_CHAR;}

[,;:(){}+-/<>=!&$#] { return yytext[0]; }
"["	{ return yytext[0]; }  
"]"	{ return yytext[0]; }
"*"	{ return yytext[0]; }

"<="	{return OPERATOR_LE;}
">="	{return OPERATOR_GE;}
"=="	{return OPERATOR_EQ;}
"!="	{return OPERATOR_NE;}
"&&"	{return OPERATOR_AND;}
"||"	{return OPERATOR_OR;}

[A-Za-z_][A-Za-z_0-9]*	{yylval.symbol = hashInsert(yytext,SYMBOL_IDENTIFIER, DATATYPE_ASTREE_NAO_DEF);return TK_IDENTIFIER;}
[0-9]+ 			{yylval.symbol = hashInsert(yytext,SYMBOL_LIT_INTEGER,DATATYPE_ASTREE_INTEGER);return LIT_INTEGER;}
[0-9]+"."[0-9]+		{yylval.symbol = hashInsert(yytext,SYMBOL_LIT_REAL,DATATYPE_ASTREE_FLOAT);return LIT_REAL;}
"'"[0-9a-zA-Z]"'"	{yylval.symbol = hashInsert(yytext,SYMBOL_LIT_CHAR, DATATYPE_ASTREE_CHAR);return LIT_CHAR; }
\"([^\\\"]|\\.)*\"	{yylval.symbol = hashInsert(yytext,SYMBOL_LIT_STRING, DATATYPE_ASTREE_STRING);return LIT_STRING; }



[ \t]  

\n   {++lineCount;}  

"//".* 

"/*"   {BEGIN(COMMENT);}  
<COMMENT>\n       {++lineCount;}		
<COMMENT>.
<COMMENT>"*/"  {BEGIN(INITIAL);}




.	{return TOKEN_ERROR;}


%%

int getLineNumber(){return lineCount;}

int isRunning(){return running;}

void initMe(){
	running = 1;
	hashInit();
}

int yywrap(){
	running = 0;
	lineCount--; //tá lindo um \n a mais no fim do arquivo!!

	return 1;
}
