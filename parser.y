%{
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

extern int lineCount;


#define   SYMBOL_UNDEFINED  	0 
#define   SYMBOL_LIT_INTEGER  	1 
#define   SYMBOL_LIT_REAL 	2 
#define   SYMBOL_LIT_CHAR   	3 
#define   SYMBOL_LIT_STRING  	4 
#define   SYMBOL_IDENTIFIER  	5 

%}


%union {HASHNODE *symbol; };

%token TK_WHILE
%token TK_CHAR       
%token TK_INT        
%token TK_FLOAT      
%token TK_IF         
%token TK_THEN       
%token TK_ELSE       
%token TK_FOR
%token TK_TO        
%token TK_READ       
%token TK_RETURN     
%token TK_PRINT      

%token OPERATOR_LE   
%token OPERATOR_GE   
%token OPERATOR_EQ   
%token OPERATOR_NE   
%token OPERATOR_AND  
%token OPERATOR_OR   

%token<symbol> TK_IDENTIFIER 
%token<symbol> LIT_INTEGER   
%token<symbol> LIT_REAL      
%token<symbol> LIT_CHAR      
%token<symbol> LIT_STRING    
%token TOKEN_ERROR   

%%

program: code;

code: var code | func code
	|;

var: var_type TK_IDENTIFIER '=' lit';' | var_type '#' TK_IDENTIFIER '=' lit';' | var_type TK_IDENTIFIER vec_dec ';' 	
	;

var_type: TK_CHAR | TK_FLOAT | TK_INT 
	;

vec_dec : '[' LIT_INTEGER ']' | '[' LIT_INTEGER ']' ':' lit_list |
	;  

lit: LIT_INTEGER | LIT_REAL | LIT_CHAR
	;

lit_list : lit lit_list |
	; 

func: var_type TK_IDENTIFIER '(' param_list ')' block
	;

param: var_type TK_IDENTIFIER
	;

param_list:  param | param aux_param_list |
	;

aux_param_list: ',' param aux_param_list |
	;  

block: '{' command_list '}' 
	;

command_list: command ';' command_list | command |
	;

command: attribution | read | print | return | block | control |
	;

attribution: TK_IDENTIFIER '=' expr | TK_IDENTIFIER '[' expr ']' '=' expr
	;

read: TK_READ TK_IDENTIFIER
	;

print: TK_PRINT print_list
	;

print_list: LIT_STRING | expr | LIT_STRING print_list | expr print_list
	;

return: TK_RETURN expr
	;	

expr: TK_IDENTIFIER | TK_IDENTIFIER '[' expr ']' | lit  | func_call | '#' TK_IDENTIFIER | '&'TK_IDENTIFIER
	| '(' expr ')' | expr '+' expr | expr '-' expr | expr '*' expr | expr '/' expr | expr '<' expr
	| expr '>' expr | expr '!' expr | expr OPERATOR_LE expr |  expr OPERATOR_GE expr | expr OPERATOR_EQ expr
	|  expr OPERATOR_NE expr |  expr OPERATOR_AND expr |  expr OPERATOR_OR expr
	;

func_call: TK_IDENTIFIER '(' call_param_list ')' | TK_IDENTIFIER '('')'
	;

call_param_list:  expr |  expr ',' call_param_list
	;

control: if | while | for
	;

if: TK_IF '(' expr ')' TK_THEN command | TK_IF '(' expr ')' TK_THEN command TK_ELSE command
	;

while: TK_WHILE '(' expr ')' command
	;

for: TK_FOR '(' TK_IDENTIFIER '=' expr TK_TO expr ')' command
	;

%%

int yyerror(){
	printf("programa não reconhecido, erro na linha %d\n", lineCount);
	exit(3);
}
