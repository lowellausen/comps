%{
#include <stdio.h>
#include <stdlib.h>
%}

%token TK_WHILE
%token TK_CHAR       
%token TK_INT        
%token TK_FLOAT      
%token TK_IF         
%token TK_THEN       
%token TK_ELSE       
%token TK_FOR        
%token TK_READ       
%token TK_RETURN     
%token TK_PRINT      

%token OPERATOR_LE   
%token OPERATOR_GE   
%token OPERATOR_EQ   
%token OPERATOR_NE   
%token OPERATOR_AND  
%token OPERATOR_OR   

%token TK_IDENTIFIER 
%token LIT_INTEGER   
%token LIT_REAL      
%token LIT_CHAR      
%token LIT_STRING    
%token TOKEN_ERROR   

%%

program: commandList;

commandList: command commandList
	|;

command: reservedFunc'('')';

reservedFunc: TK_WHILE|TK_IF|TK_THEN|TK_ELSE|TK_FOR|TK_READ|TK_RETURN|TK_PRINT;


%%

int yyerror(){
	printf("programa não reconhecido");
	return 3;
}
