%{
#include "hash.h"
#include "tokens.h"

int lineCount = 1;
int running = 1;

%}

%x COMMENT

%%



if	{return KW_IF;}
then 	{return KW_THEN;}
else	{return KW_ELSE;}
while	{return KW_WHILE;}
int	{return KW_INT;}
float	{return KW_FLOAT;}
for	{return KW_FOR;}
read	{return KW_READ;}
return	{return KW_RETURN;}
print	{return KW_PRINT;}
char	{return KW_CHAR;}

[,;:(){}+-/<>=!&$#] { return yytext[0]; }
"["	{ return yytext[0]; }  //estavam dando erro se juntos dos acima
"]"	{ return yytext[0]; }
"*"	{ return yytext[0]; }

"<="	{return OPERATOR_LE;}
">="	{return OPERATOR_GE;}
"=="	{return OPERATOR_EQ;}
"!="	{return OPERATOR_NE;}
"&&"	{return OPERATOR_AND;}
"||"	{return OPERATOR_OR;}

[A-Za-z_][A-Za-z_0-9]*	{return TK_IDENTIFIER;}
[0-9]+ 			{return LIT_INTEGER;}
[0-9]+.[0-9]+		{return LIT_REAL;}
"'"[0-9a-zA-Z]"'"	{return LIT_CHAR; }
\"([^\\\"]|\\.)*\"	{return LIT_STRING; }

[ \t]  //ignorar espaçamentos

\n   {++lineCount;}  //incrementar as linhas

"//".*  //ignorar comentários

"/*"   {BEGIN(COMMENT);}  
<COMMENT>\n       { }		
<COMMENT>.
<COMMENT>"*/"  {BEGIN(INITIAL);}




.	{ return TOKEN_ERROR; }


%%

int getLineNumber(){return lineCount;}

int isRunning(){return running;}

void initMe(){
	running = 1;
	hashInit();
}

int yywrap(){
	running = 0;

	return 1;
}
