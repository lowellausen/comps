%{
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"
#include "semantics.h"
#include "tac.h"
#include "asm.h"

extern int lineCount;


/*#define   SYMBOL_UNDEFINED  	0
#define   SYMBOL_LIT_INTEGER  	1
#define   SYMBOL_LIT_REAL 	2
#define   SYMBOL_LIT_CHAR   	3
#define   SYMBOL_LIT_STRING  	4
#define   SYMBOL_IDENTIFIER  	5 */

%}


%union {ASTREE *astree;
	HASHNODE *symbol;
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

program: code {$$ = astreeCreate(ASTREE_PROGRAM,$1,0,0,0,0); astreePrintTree($$,"",1);
semanticFullCheck($$); printf("Programa Reconhecido.\n");
TAC * tac = generateCode($1);
tacPrintListReverse(tac); writeToFile("program.s", generateAsm(tacGetFirst(tac)));
              };

code: var code { $$ = astreeCreate(ASTREE_DECL_LIST,$1,$2,0,0,0);}
	| func code { $$ = astreeCreate(ASTREE_DECL_LIST,$1,$2,0,0,0);}
	|{ $$ = 0;};

var: var_type TK_IDENTIFIER '=' LIT_INTEGER';' { $$ = astreeCreate(ASTREE_VAR_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$4),0,0,$2); setSymbolAndDataType($$, ASTREE_VAR_DECL);}
	| var_type TK_IDENTIFIER '=' LIT_REAL ';' { $$ = astreeCreate(ASTREE_VAR_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$4),0,0,$2);
setSymbolAndDataType($$, ASTREE_VAR_DECL);}
	| var_type TK_IDENTIFIER '=' LIT_CHAR ';' { $$ = astreeCreate(ASTREE_VAR_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$4),0,0,$2);
setSymbolAndDataType($$, ASTREE_VAR_DECL);}
	| var_type '#' TK_IDENTIFIER '=' LIT_CHAR';' { $$ = astreeCreate(ASTREE_POINT_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$5),0,0,$3);
setSymbolAndDataType($$, ASTREE_POINT_DECL);}
	| var_type '#' TK_IDENTIFIER '=' LIT_REAL ';' { $$ = astreeCreate(ASTREE_POINT_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$5),0,0,$3);
setSymbolAndDataType($$, ASTREE_POINT_DECL);}
	| var_type '#' TK_IDENTIFIER '=' LIT_INTEGER ';' { $$ = astreeCreate(ASTREE_POINT_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$5),0,0,$3);
setSymbolAndDataType($$, ASTREE_POINT_DECL);}
	| var_type TK_IDENTIFIER '[' LIT_INTEGER ']'  ';' {$$ = astreeCreate(ASTREE_VET_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$4),0,0,$2); setSymbolAndDataType($$, ASTREE_VET_DECL);}
	| var_type TK_IDENTIFIER '[' LIT_INTEGER ']' ':' lit_list ';' {$$ = astreeCreate(ASTREE_VET_DECL_INIT,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$4),$7,0,$2);setSymbolAndDataType($$, ASTREE_VET_DECL_INIT);}
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

func: var_type TK_IDENTIFIER '(' param_list ')' block {$$ = astreeCreate(ASTREE_FUNC, $1,$4,$6,0, $2);setSymbolAndDataType($$, ASTREE_FUNC); }
	;

param: var_type TK_IDENTIFIER {$$ = astreeCreate(ASTREE_PARAM, $1,0,0,0, $2);setSymbolAndDataType($$, ASTREE_PARAM);}
	| var_type '#' TK_IDENTIFIER {$$ = astreeCreate(ASTREE_PARAM, $1,0,0,0, $3);setSymbolAndDataType($$, ASTREE_PARAM);}
	;

param_list: param aux_param_list {$$ = astreeCreate(ASTREE_PARAM_LIST, $1,$2,0,0,0);}
	| {$$ = 0;}
	;

aux_param_list: ',' param aux_param_list {$$ = astreeCreate(ASTREE_PARAM_LIST, $2,$3,0,0,0);}
	| {$$ = 0;}
	;

block: '{' command_list '}' { $$ = astreeCreate(ASTREE_BLOCK,$2,0,0,0,0);};

command_list: command ';' command_list {$$ = astreeCreate(ASTREE_CMD_LIST, $1,$3,0,0,0);}
	| command {$$ = $1;}
	;

command: attribution {$$ = $1;}
	| read {$$ = $1;}
	| print {$$ = $1;}
	| return {$$ = $1;}
	| block {$$ = $1;}
	| control {$$ = $1;}
	|{$$ = 0;}
	;

attribution: TK_IDENTIFIER '=' expr { $$ =  astreeCreate(ASTREE_ASSIGN_VAR, $3, 0, 0, 0, $1); }
	| TK_IDENTIFIER '[' expr ']' '=' expr { $$ =  astreeCreate(ASTREE_ASSIGN_VECTOR, $3, $6, 0, 0, $1); }
	;

read: TK_READ TK_IDENTIFIER { $$ =  astreeCreate(ASTREE_READ, 0, 0, 0, 0, $2); }
	;

print: TK_PRINT print_list { $$ =  astreeCreate(ASTREE_PRINT, $2, 0, 0, 0, 0); }
	;

print_list: LIT_STRING { $$ = astreeCreate(ASTREE_SYMBOL,0,0,0,0, $1); $$->symbol = $1; }
	| expr { $$ = astreeCreate(ASTREE_EXP,$1,0,0,0, 0);}
	| LIT_STRING print_list { $$ = astreeCreate(ASTREE_PRT_LST_ST,$2,0,0,0, $1); $$->symbol = $1; }
	| expr print_list { $$ = astreeCreate(ASTREE_PRT_LST,$1,$2,0,0, 0); }
	;

return: TK_RETURN expr {$$ = astreeCreate(ASTREE_RETURN, $2, 0, 0, 0, 0);}
	;

expr: TK_IDENTIFIER {$$ = astreeCreate(ASTREE_SYMBOL, 0, 0, 0, 0, $1); }
	| TK_IDENTIFIER '[' expr ']' {$$ = astreeCreate(ASTREE_VECTOR, $3, 0, 0, 0, $1);}
	| lit  {$$ = $1;}
	| func_call {$$ = $1;}
	| '#' TK_IDENTIFIER {$$ = astreeCreate(ASTREE_SYMBOL_POINT, 0, 0, 0, 0, $2);}
	| '&'TK_IDENTIFIER {$$ = astreeCreate(ASTREE_SYMBOL_ADDRESS, 0, 0, 0, 0, $2);}
	| '(' expr ')' {$$ = astreeCreate(ASTREE_EXP_BRACKET, $2, 0, 0, 0, 0);}
	| expr '+' expr {$$ = astreeCreate(ASTREE_SOMA, $1, $3, 0, 0, 0); }
	| expr '-' expr {$$ = astreeCreate(ASTREE_SUB, $1, $3, 0, 0, 0); }
	| expr '*' expr {$$ = astreeCreate(ASTREE_MULT, $1, $3, 0, 0, 0); }
	| expr '/' expr {$$ = astreeCreate(ASTREE_DIV, $1, $3, 0, 0, 0); }
	| expr '<' expr {$$ = astreeCreate(ASTREE_LESS, $1, $3, 0, 0, 0); }
	| expr '>' expr {$$ = astreeCreate(ASTREE_GREAT, $1, $3, 0, 0, 0); }
	| '!' expr {$$ = astreeCreate(ASTREE_NEG, $2, 0, 0, 0, 0);}
	| expr OPERATOR_LE expr {$$ = astreeCreate(ASTREE_LE, $1, $3, 0, 0, 0);}
	|  expr OPERATOR_GE expr {$$ = astreeCreate(ASTREE_GE, $1, $3, 0, 0, 0);}
	| expr OPERATOR_EQ expr {$$ = astreeCreate(ASTREE_EQ, $1, $3, 0, 0, 0);}
	|  expr OPERATOR_NE expr {$$ = astreeCreate(ASTREE_NE, $1, $3, 0, 0, 0);}
	|  expr OPERATOR_AND expr {$$ = astreeCreate(ASTREE_AND, $1, $3, 0, 0, 0); }
	|  expr OPERATOR_OR expr {$$ = astreeCreate(ASTREE_OR, $1, $3, 0, 0, 0);}
	;

func_call: TK_IDENTIFIER '(' call_param_list ')' {$$ = astreeCreate(ASTREE_FUNC_CALL, $3, 0, 0, 0, $1);}
	| TK_IDENTIFIER '('')' {$$ = astreeCreate(ASTREE_FUNC_CALL, 0, 0, 0, 0, $1);}
	;

call_param_list:  expr {$$ = $1;};
	|  expr ',' call_param_list {$$ = astreeCreate(ASTREE_EXP_LIST, $1,$3,0,0,0);}
	;

control: if {$$ = $1;}| while {$$ = $1;}| for {$$ = $1;}
	;

if: TK_IF '(' expr ')' TK_THEN command {$$ = astreeCreate(ASTREE_IF, $3, $6, 0, 0, 0); }
	| TK_IF '(' expr ')' TK_THEN command TK_ELSE command {$$ = astreeCreate(ASTREE_IF_ELSE, $3, $6, $8, 0, 0); }
	;

while: TK_WHILE '(' expr ')' command {$$ = astreeCreate(ASTREE_WHILE, $3, $5, 0, 0, 0); }
	;

for: TK_FOR '(' TK_IDENTIFIER '=' expr TK_TO expr ')' command {$$ = astreeCreate(ASTREE_FOR, $5, $7, $9, 0, $3); }
	;

%%

int yyerror(){
	printf("programa não reconhecido, erro na linha %d\n", lineCount);
	exit(3);
}

