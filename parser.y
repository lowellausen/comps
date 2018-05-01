%{
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"

extern int lineCount;


#define   SYMBOL_UNDEFINED  	0 
#define   SYMBOL_LIT_INTEGER  	1 
#define   SYMBOL_LIT_REAL 	2 
#define   SYMBOL_LIT_CHAR   	3 
#define   SYMBOL_LIT_STRING  	4 
#define   SYMBOL_IDENTIFIER  	5 

%}


%union {HASHNODE *symbol; 
	ASTREE *astree;
	};

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

/*%left '+' '-'
%left '*' '/' 
%left OPERATOR_AND OPERATOR_OR '#' '&' '!'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE*/

%left OPERATOR_OR
%left OPERATOR_AND
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%left '+' '-'
%left '*' '/'
%nonassoc '#' '&' '!'


%type<astree> program
%type<astree> code
%type<astree> var
%type<astree> var_type
%type<astree> lit
%type<astree> lit_list
%type<astree> func
%type<astree> param
%type<astree> param_list
%type<astree> aux_param_list
%type<astree> block
%type<astree> command_list
%type<astree> command
%type<astree> attribution
%type<astree> read
%type<astree> print
%type<astree> print_list
%type<astree> return
%type<astree> expr
%type<astree> func_call
%type<astree> call_param_list
%type<astree> control
%type<astree> if
%type<astree> while
%type<astree> for



%%

program: code {$$ = astreeCreate(ASTREE_PROGRAM,$1,0,0,0,0); astreePrintTree($$,0); printf("deu bowa.\n"); 
             exit (0); };

code: var code { $$ = astreeCreate(ASTREE_DECL_LIST,$1,$2,0,0,0);}
	| func code { $$ = astreeCreate(ASTREE_DECL_LIST,$1,$2,0,0,0);}
	|{ $$ = 0;};

var: var_type TK_IDENTIFIER '=' lit';' { $$ = astreeCreate(ASTREE_VAR_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$4),0,0,$2); }
	| var_type '#' TK_IDENTIFIER '=' lit';' { $$ = astreeCreate(ASTREE_POINT_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$5),0,0,$3);}
	| var_type TK_IDENTIFIER '[' LIT_INTEGER ']'  ';' {$$ = astreeCreate(ASTREE_VET_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$4),0,0,$2); }
	| var_type TK_IDENTIFIER '[' LIT_INTEGER ']' ':' lit_list ';' {$$ = astreeCreate(ASTREE_VET_DECL_INIT,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$4),$7,0,$2);} 
	;

var_type: TK_CHAR { $$ = astreeCreate(ASTREE_CHAR,0,0,0,0,0); }
	| TK_FLOAT { $$ = astreeCreate(ASTREE_FLOAT,0,0,0,0,0); }
	| TK_INT { $$ = astreeCreate(ASTREE_INT,0,0,0,0,0); }
	;

lit: LIT_INTEGER { $$ = astreeCreate(ASTREE_SYMBOL,0,0,0,0, $1); $$->symbol = $1; }
	| LIT_REAL { $$ = astreeCreate(ASTREE_SYMBOL,0,0,0,0, $1); $$->symbol = $1; }
	| LIT_CHAR { $$ = astreeCreate(ASTREE_SYMBOL,0,0,0,0, $1); $$->symbol = $1; }
	;

lit_list : lit lit_list {$$ = astreeCreate(ASTREE_SYMBOL_LIST,$1,$2,0,0,0);} 
	| {$$ = 0;}
	; 

func: var_type TK_IDENTIFIER '(' param_list ')' block
	;

param: var_type TK_IDENTIFIER
	;

param_list: param aux_param_list |
	;

aux_param_list: ',' param aux_param_list |
	;  

block: '{' command_list '}' 
	;

command_list: command ';' command_list | command 
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
