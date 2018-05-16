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

int list_dataTypes[20];
int list_naturezas[20];
int cont;
int functionDataType;
char tempUm;

void set_error_flag();
int get_error_flag();

void clear_lists();
void put_in_lists(int natureza, int dataType);

void reset_cont();
void inc_cont();
int get_cont();

void define_dataType (int type, HASHNODE *identifier);
ASTREE* define_astree_nature_and_type(ASTREE *node,HASHNODE *element);
ASTREE* define_astree_type(ASTREE *node,HASHNODE *element);
ASTREE* define_astree_nature(ASTREE *node,HASHNODE *element);

void verify_function_declaration (HASHNODE *function);
void verify_function_declared (HASHNODE *function);
void verify_variable_declaration (HASHNODE *variable);
void verify_variable_declared (HASHNODE *variable);
void verify_vector (HASHNODE *vector);
void verify_pointer (HASHNODE *pointer);

int compareHashTreeNatureza (int hashc, int treec);
void compare_lists (int* naturezaHash,int* dataTypesHash,int size);

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
%type<astree> error


%%

program: code {$$ = astreeCreate(ASTREE_PROGRAM,$1,0,0,0,0); astreePrintTree($$,"",1); 
	if(get_error_flag() == 0)
	     {
	        printf("Programa pertence a linguagem.\n"); 
		exit(0);
	     }
	     else
	     {
	        printf("Erro de semantica\n"); 		
		exit(4);
	     }; 
              };

code: var code { $$ = astreeCreate(ASTREE_DECL_LIST,$1,$2,0,0,0);}
	| func code { $$ = astreeCreate(ASTREE_DECL_LIST,$1,$2,0,0,0);}
	| error
	|{ $$ = 0;};

var: var_type TK_IDENTIFIER '=' LIT_INTEGER';' { $$ = astreeCreate(ASTREE_VAR_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$4),0,0,$2); 
			$2->natureza = NATUREZA_ESCALAR;
			define_dataType ($1->type, $2);
			verify_variable_declaration ($2);}
	| var_type TK_IDENTIFIER '=' LIT_REAL ';' { $$ = astreeCreate(ASTREE_VAR_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$4),0,0,$2); 
			$2->natureza = NATUREZA_ESCALAR;
			define_dataType ($1->type, $2);
			verify_variable_declaration ($2);}
	| var_type TK_IDENTIFIER '=' LIT_CHAR ';' { $$ = astreeCreate(ASTREE_VAR_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$4),0,0,$2);
			$2->natureza = NATUREZA_ESCALAR;
			define_dataType ($1->type, $2);
			verify_variable_declaration ($2); }
	| var_type '#' TK_IDENTIFIER '=' LIT_CHAR';' { $$ = astreeCreate(ASTREE_POINT_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$5),0,0,$3);
			$3->natureza = NATUREZA_ESCALAR;
			define_dataType ($1->type, $3);
			verify_variable_declaration ($3);}
	| var_type '#' TK_IDENTIFIER '=' LIT_REAL ';' { $$ = astreeCreate(ASTREE_POINT_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$5),0,0,$3);
			$3->natureza = NATUREZA_ESCALAR;
			define_dataType ($1->type, $3);
			verify_variable_declaration ($3);}
	| var_type '#' TK_IDENTIFIER '=' LIT_INTEGER ';' { $$ = astreeCreate(ASTREE_POINT_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$5),0,0,$3);
			$3->natureza = NATUREZA_ESCALAR;
			define_dataType ($1->type, $3);
			verify_variable_declaration ($3);}
	| var_type TK_IDENTIFIER '[' LIT_INTEGER ']'  ';' {$$ = astreeCreate(ASTREE_VET_DECL,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$4),0,0,$2); 			$2->natureza = NATUREZA_VETOR;
			define_dataType($1->type, $2);
			verify_variable_declaration($2);}
	| var_type TK_IDENTIFIER '[' LIT_INTEGER ']' ':' lit_list ';' {$$ = astreeCreate(ASTREE_VET_DECL_INIT,$1,astreeCreate(ASTREE_LIT,0,0,0,0,$4),$7,0,$2);
			$2->natureza = NATUREZA_VETOR;
			define_dataType($1->type, $2);
			verify_variable_declaration($2);} 
	;

var_type: TK_CHAR { $$ = astreeCreate(ASTREE_CHAR,0,0,0,0,0); $$->dataType = DATATYPE_ASTREE_CHAR;}
	| TK_FLOAT { $$ = astreeCreate(ASTREE_FLOAT,0,0,0,0,0); $$->dataType = DATATYPE_ASTREE_FLOAT;}
	| TK_INT { $$ = astreeCreate(ASTREE_INT,0,0,0,0,0); $$->dataType = DATATYPE_ASTREE_INTEGER;}
	;

lit: LIT_INTEGER { $$ = astreeCreate(ASTREE_SYMBOL,0,0,0,0, $1); $$->symbol = $1; 
		$$->natureza = NATUREZA_ASTREE_ESCALAR;
		$$->dataType = DATATYPE_ASTREE_INTEGER;}
	| LIT_REAL { $$ = astreeCreate(ASTREE_SYMBOL,0,0,0,0, $1); $$->symbol = $1; 
		$$->natureza = NATUREZA_ASTREE_ESCALAR;
		$$->dataType = DATATYPE_ASTREE_FLOAT;}
	| LIT_CHAR { $$ = astreeCreate(ASTREE_SYMBOL,0,0,0,0, $1); $$->symbol = $1; 
		$$->natureza = NATUREZA_ASTREE_ESCALAR;
		$$->dataType = DATATYPE_ASTREE_CHAR;}
	;

lit_list : lit lit_list {$$ = astreeCreate(ASTREE_SYMBOL_LIST,$1,$2,0,0,0);} 
	| {$$ = 0;}
	; 

func: var_type TK_IDENTIFIER '(' {reset_cont();clear_lists();} param_list ')' block {$$ = astreeCreate(ASTREE_FUNC, $1,$5,$7,0, $2); }
	;

param: var_type TK_IDENTIFIER {
		$2->natureza = NATUREZA_ESCALAR;
		define_dataType ($1->type, $2);
		verify_variable_declaration ($2);
		$$ = astreeCreate(ASTREE_PARAM, $1,0,0,0, $2);
		put_in_lists(NATUREZA_ESCALAR, $2->dataType);
	}
	| var_type '#' TK_IDENTIFIER{ 
		$3->natureza = NATUREZA_POINTER;
		define_dataType ($1->type, $3);
		verify_variable_declaration ($3);
		$$ = astreeCreate(ASTREE_PARAM,$1,0,0,0,$3);
		put_in_lists(NATUREZA_POINTER, $3->dataType);
	};

param_list: param{inc_cont();} aux_param_list {$$ = astreeCreate(ASTREE_PARAM_LIST, $1,$3,0,0,0);}
	| {$$ = 0;}
	;

aux_param_list: ',' param {inc_cont();} aux_param_list {$$ = astreeCreate(ASTREE_PARAM_LIST, $2,$4,0,0,0);}
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

expr: TK_IDENTIFIER {
			verify_variable_declared ($1);
			$$ = astreeCreate(ASTREE_SYMBOL, 0, 0, 0, 0, $1); 
			$$ = define_astree_nature_and_type($$,$1);
} 
	| TK_IDENTIFIER '[' expr ']' {
			verify_vector($1);
			if($3->dataType == DATATYPE_ASTREE_FLOAT || DATATYPE_ASTREE_CHAR || $3->natureza == NATUREZA_ASTREE_POINTER)
			{
				fprintf(stderr,"Erro na linha  %d. Indice do vetor %s deveria escalar.\n",getLineNumber(),$1->text); 
				set_error_flag();
			}			
			$$ = astreeCreate(ASTREE_VECTOR, $3, 0, 0, 0, $1);
			//$$ = define_astree_nature_and_type($$,$1); //Talvez deva ser NATUREZA_ESCALAR
			$$ = define_astree_type($$,$1);
			$$->natureza = NATUREZA_ASTREE_ESCALAR;
} ;
	| lit  {$$ = $1;}
	| func_call {$$ = $1;
$$->natureza = NATUREZA_ASTREE_ESCALAR;} 
	| '#' TK_IDENTIFIER {
			verify_pointer($2);				
			$$ = astreeCreate(ASTREE_SYMBOL_POINT, 0, 0, 0, 0, $2);
			$$ = define_astree_type($$,$2);
			$$->natureza = NATUREZA_ASTREE_ESCALAR;
} 
	| '&'TK_IDENTIFIER {$$ = astreeCreate(ASTREE_SYMBOL_ADDRESS, 0, 0, 0, 0, $2);}
	| '(' expr ')' {$$ = astreeCreate(ASTREE_EXP_BRACKET, $2, 0, 0, 0, 0);
			$$->dataType = $2->dataType;
			$$->natureza = $2->natureza;} 
	| expr '+' expr {$$ = astreeCreate(ASTREE_SOMA, $1, $3, 0, 0, 0); 
	if(($1->natureza == NATUREZA_ASTREE_ESCALAR)&&($3->natureza == NATUREZA_ASTREE_ESCALAR))
			{
		
					if ($1->dataType!=DATATYPE_ASTREE_INTEGER)
						$$->dataType = DATATYPE_ASTREE_INTEGER;
					else if ($1->dataType!=DATATYPE_ASTREE_CHAR)
						$$->dataType = DATATYPE_ASTREE_CHAR;
					else if ($1->dataType!=DATATYPE_ASTREE_FLOAT)
						$$->dataType = DATATYPE_ASTREE_FLOAT;
					$$->natureza = NATUREZA_ASTREE_ESCALAR;
			}
			else
			{
				if($1->natureza == NATUREZA_ASTREE_POINTER)
				{
					if(($3->natureza != NATUREZA_ASTREE_ESCALAR))
					{
						fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
						set_error_flag();
					}
					else
					{
						$$->dataType = $1->dataType;
						$$->natureza = NATUREZA_ASTREE_POINTER;
					}
				}
				else
				{
					if($3->natureza == NATUREZA_ASTREE_POINTER)
					{
						if(($1->natureza != NATUREZA_ASTREE_ESCALAR))
						{
							fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
							set_error_flag();
						}
						else
						{
							$$->dataType = $3->dataType;
							$$->natureza = NATUREZA_ASTREE_POINTER;
						}
					}
					else
					{
						fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
						set_error_flag();
					}
				}
			}			
		}
	| expr '-' expr {$$ = astreeCreate(ASTREE_SUB, $1, $3, 0, 0, 0); 
if(($1->natureza == NATUREZA_ASTREE_ESCALAR)&&($3->natureza == NATUREZA_ASTREE_ESCALAR))
			{
					if ($1->dataType!=DATATYPE_ASTREE_INTEGER)
						$$->dataType = DATATYPE_ASTREE_INTEGER;
					else if ($1->dataType!=DATATYPE_ASTREE_CHAR)
						$$->dataType = DATATYPE_ASTREE_CHAR;
					else if ($1->dataType!=DATATYPE_ASTREE_FLOAT)
						$$->dataType = DATATYPE_ASTREE_FLOAT;

					$$->natureza = NATUREZA_ASTREE_ESCALAR;
			}
			else
			{
				if($1->natureza == NATUREZA_ASTREE_POINTER)
				{
					if(($3->natureza != NATUREZA_ASTREE_ESCALAR))
					{
						fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
						set_error_flag();
					}
					else
					{
						$$->dataType = $1->dataType;
						$$->natureza = NATUREZA_ASTREE_POINTER;
					}
				}
				else
				{
					if($3->natureza == NATUREZA_ASTREE_POINTER)
					{
						if(($1->natureza != NATUREZA_ASTREE_ESCALAR))
						{
							fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
							set_error_flag();
						}
						else
						{
							$$->dataType = $3->dataType;
							$$->natureza = NATUREZA_ASTREE_POINTER;
						}
					}
					else
					{
						fprintf(stderr,"Erro na linha  %d. Soma invalida.\n", getLineNumber()); 
						set_error_flag();
					}
				}
			}
}
	| expr '*' expr {$$ = astreeCreate(ASTREE_MULT, $1, $3, 0, 0, 0); 

	if($1->natureza != NATUREZA_ASTREE_ESCALAR
                        || $3->natureza != NATUREZA_ASTREE_ESCALAR)
			{
				fprintf(stderr,"Erro na linha  %d. Multiplicacao soh eh permitida entre inteiros (word ou byte).\n", getLineNumber()); 
				set_error_flag();
			}
			$$->natureza = NATUREZA_ASTREE_ESCALAR;
			if ($1->dataType!=DATATYPE_ASTREE_INTEGER)
						$$->dataType = DATATYPE_ASTREE_INTEGER;
					else if ($1->dataType!=DATATYPE_ASTREE_CHAR)
						$$->dataType = DATATYPE_ASTREE_CHAR;
					else if ($1->dataType!=DATATYPE_ASTREE_FLOAT)
						$$->dataType = DATATYPE_ASTREE_FLOAT;}
	| expr '/' expr {$$ = astreeCreate(ASTREE_DIV, $1, $3, 0, 0, 0); 
if($1->natureza != NATUREZA_ASTREE_ESCALAR
                        || $3->natureza != NATUREZA_ASTREE_ESCALAR)
			{
				fprintf(stderr,"Erro na linha  %d. Multiplicacao soh eh permitida entre inteiros (word ou byte).\n", getLineNumber()); 
				set_error_flag();
			}
			$$->natureza = NATUREZA_ASTREE_ESCALAR;
			if ($1->dataType!=DATATYPE_ASTREE_INTEGER)
						$$->dataType = DATATYPE_ASTREE_INTEGER;
					else if ($1->dataType!=DATATYPE_ASTREE_CHAR)
						$$->dataType = DATATYPE_ASTREE_CHAR;
					else if ($1->dataType!=DATATYPE_ASTREE_FLOAT)
						$$->dataType = DATATYPE_ASTREE_FLOAT;}
	| expr '<' expr {$$ = astreeCreate(ASTREE_LESS, $1, $3, 0, 0, 0); }
	| expr '>' expr {$$ = astreeCreate(ASTREE_GREAT, $1, $3, 0, 0, 0); }
	| '!' expr {$$ = astreeCreate(ASTREE_NEG, $2, 0, 0, 0, 0);} ;	    
	| expr OPERATOR_LE expr {$$ = astreeCreate(ASTREE_LE, $1, $3, 0, 0, 0);}
	|  expr OPERATOR_GE expr {$$ = astreeCreate(ASTREE_GE, $1, $3, 0, 0, 0);}
	| expr OPERATOR_EQ expr {$$ = astreeCreate(ASTREE_EQ, $1, $3, 0, 0, 0);}
	|  expr OPERATOR_NE expr {$$ = astreeCreate(ASTREE_NE, $1, $3, 0, 0, 0);}
	|  expr OPERATOR_AND expr {$$ = astreeCreate(ASTREE_AND, $1, $3, 0, 0, 0); }
	|  expr OPERATOR_OR expr {$$ = astreeCreate(ASTREE_OR, $1, $3, 0, 0, 0);}       
	;

func_call: TK_IDENTIFIER '(' {reset_cont();clear_lists();} call_param_list ')' {
			verify_function_declared ($1);
			$$ = astreeCreate(ASTREE_FUNC_CALL, $4, 0, 0, 0, $1);

			if($1->number_of_param_func != get_cont())
			{
				fprintf(stderr,"Erro na linha  %d. Funcao %s deveria ter %d parametros.\n",getLineNumber(),$1->text,$1->number_of_param_func); 
				set_error_flag(); }
			$$ = define_astree_type($$,$1);
			$$->natureza = NATUREZA_ASTREE_FUNCTION; //Talvez deva ser NATUREZA_ESCALAR
			compare_lists($1->list_naturezas, $1->list_dataTypes,$1->number_of_param_func);}
	| TK_IDENTIFIER '('')' {
			verify_function_declared ($1);
			$$ = astreeCreate(ASTREE_FUNC_CALL, 0, 0, 0, 0, $1);
			$$ = define_astree_type($$,$1);
			$$->natureza = NATUREZA_ASTREE_FUNCTION; //Talvez deva ser NATUREZA_ESCALAR

}
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

void set_error_flag()
{
	extern int error;
	error = 1;
}	

int get_error_flag()
{
	extern int error;
	return error;
}

void clear_lists()
{
	int i;
	for(i=0;i<20;i++)
	{
		list_dataTypes[i]=0;
		list_naturezas[i]=0;
	}
}

void put_in_lists(int natureza, int dataType)
{
	list_dataTypes[cont]=dataType;
	list_naturezas[cont]=natureza;	
}

void reset_cont()
{
	cont = 0;
}

void inc_cont()
{
	cont += 1;
}

int get_cont()
{
	return cont;
}

void define_dataType (int type, HASHNODE *identifier)
{ 
	if(type == ASTREE_INT)identifier->dataType = DATATYPE_INTEGER;
	if(type == ASTREE_FLOAT)identifier->dataType = DATATYPE_FLOAT;
	if(type == ASTREE_CHAR)identifier->dataType = DATATYPE_CHAR;
}

void verify_function_declaration (HASHNODE *function)
{	
	if(function->is_declared == 1)
	{
		fprintf(stderr,"Erro na linha  %d. Funcao %s ja declarada. \n", getLineNumber(),function->text); 
		set_error_flag();
	}
	else function->is_declared = 1;	
}

void verify_function_declared (HASHNODE *function)
{ 
	if(function->is_declared == 0)
	{
		fprintf(stderr,"Erro na linha  %d. Funcao %s nao declarada. \n", getLineNumber(),function->text); 
		set_error_flag();
	}
	else
	{
		if(function->natureza != NATUREZA_FUNCTION)
		{
			fprintf(stderr,"Erro na linha  %d. Chama %s, que nao eh funcao. \n", getLineNumber(),function->text); 
			set_error_flag();						
		}
	}
}

void verify_variable_declaration (HASHNODE *variable)
{
	if(variable->is_declared == 1)
	{
		fprintf(stderr,"Erro na linha  %d. Variavel %s ja declarada. \n", getLineNumber(),variable->text); 
		set_error_flag();
	}
	else variable->is_declared = 1;
}


void verify_variable_declared (HASHNODE *variable)
{ 
	
	if(variable->is_declared == 0)
	{
		fprintf(stderr,"Erro na linha  %d. Variavel %s nao declarada. \n", getLineNumber(),variable->text); 
		set_error_flag();
	}
	else
	{
          if (variable->natureza==NATUREZA_FUNCTION)
          {
		    fprintf(stderr,"Erro na linha  %d. Funcao %s nao eh uma variavel. \n", getLineNumber(),variable->text); 
		    set_error_flag();
          }
        }
}

void verify_vector (HASHNODE *vector)
{ 
	if(vector->is_declared == 0)
	{
		fprintf(stderr,"Erro na linha  %d. Variavel %s nao declarada. \n", getLineNumber(),vector->text); 
		set_error_flag();
	}
        else
        {
		if (vector->natureza!=NATUREZA_VETOR)
		{
		    fprintf(stderr,"Erro na linha  %d. %s nao eh vetor. \n", getLineNumber(),vector->text); 
		    set_error_flag();
        	}    
    	}
}

void verify_pointer (HASHNODE *pointer)
{ 
	if(pointer->is_declared == 0)
	{
		fprintf(stderr,"Erro na linha  %d. Variavel %s nao declarada. \n", getLineNumber(),pointer->text); 
		set_error_flag();
	}
    else
    {
		if (pointer->natureza!=NATUREZA_POINTER)
		{
		    fprintf(stderr,"Erro na linha  %d. %s nao eh ponteiro. \n", getLineNumber(),pointer->text); 
		    set_error_flag();
        }    
    }
}

ASTREE* define_astree_nature_and_type(ASTREE *node,HASHNODE *element)
{
    switch (element->natureza)
    {
        case NATUREZA_ESCALAR:
                node->natureza = NATUREZA_ASTREE_ESCALAR;
            break;
        case NATUREZA_VETOR:
                node->natureza = NATUREZA_ASTREE_VETOR;
            break;
        case NATUREZA_FUNCTION:
                node->natureza = NATUREZA_ASTREE_FUNCTION;
            break;
        case NATUREZA_POINTER:
                node->natureza = NATUREZA_ASTREE_POINTER;
            break;
     }
    switch (element->dataType)
    {
        case DATATYPE_INTEGER:
                node->dataType = DATATYPE_ASTREE_INTEGER;
            break;
        case DATATYPE_FLOAT:
		node->dataType = DATATYPE_ASTREE_FLOAT;
            break;
	case DATATYPE_CHAR:
                node->dataType = DATATYPE_ASTREE_CHAR;
            break;
     } 
     return node;      
}

ASTREE* define_astree_type(ASTREE *node,HASHNODE *element)
{
    switch (element->dataType)
    {
 case DATATYPE_INTEGER:
                node->dataType = DATATYPE_ASTREE_INTEGER;
            break;
        case DATATYPE_FLOAT:
		node->dataType = DATATYPE_ASTREE_FLOAT;
            break;
	case DATATYPE_CHAR:
                node->dataType = DATATYPE_ASTREE_CHAR;
            break;
     } 
     return node;      
}

ASTREE* define_astree_nature(ASTREE *node,HASHNODE *element)
{
    switch (element->natureza)
    {
        case NATUREZA_ESCALAR:
                node->natureza = NATUREZA_ASTREE_ESCALAR;
            break;
        case NATUREZA_VETOR:
                node->natureza = NATUREZA_ASTREE_VETOR;
            break;
        case NATUREZA_FUNCTION:
                node->natureza = NATUREZA_ASTREE_FUNCTION;
            break;
        case NATUREZA_POINTER:
                node->natureza = NATUREZA_ASTREE_POINTER;
            break;
     }
}

int compareHashTreeNatureza (int hashc, int treec)
{
	switch (hashc)
	{
		case NATUREZA_ESCALAR:
			if (treec==NATUREZA_ASTREE_ESCALAR)
			    return 1;
		break;

		case NATUREZA_VETOR:
			if (treec==NATUREZA_ASTREE_VETOR)
			    return 1;
		break;
		case NATUREZA_FUNCTION:
			if (treec==NATUREZA_ASTREE_FUNCTION)
			    return 1;
		break;
		case NATUREZA_POINTER:
			if (treec==NATUREZA_ASTREE_POINTER)
			    return 1;
		break;
	}
}


void compare_lists (int* naturezaHash,int* dataTypesHash,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		//printf ("type=%d natureza=%d listnaturezas=%d listdatatypes=%d\n",dataTypesHash[i], naturezaHash[i], list_naturezas[i], list_dataTypes[i]);
		switch (naturezaHash[i])
		{			
			case NATUREZA_ESCALAR:
				if(list_naturezas[i]!=NATUREZA_ASTREE_ESCALAR)
				{
					fprintf(stderr,"Erro na linha  %d.  Parametro %d incompativel com sua declaracao na funcao. (natureza)\n", getLineNumber(),i);
					set_error_flag();
				}
				break;
			case NATUREZA_VETOR:
				if(list_naturezas[i]!=NATUREZA_ASTREE_VETOR)
				{
					fprintf(stderr,"Erro na linha  %d. Parametro %d incompativel com sua declaracao na funcao. (natureza) \n", getLineNumber(),i);
					set_error_flag();
				}
				break;
			case NATUREZA_POINTER:
				if(list_naturezas[i]!=NATUREZA_ASTREE_POINTER)
				{
					fprintf(stderr,"Erro na linha  %d. Parametro %d incompativel com sua declaracao na funcao. (natureza) \n", getLineNumber(),i);
					set_error_flag();
				}
				break;
			default:
				break;
		}
	/*	switch (dataTypesHash[i])
		{
			case DATATYPE_INTEGER:
			case DATATYPE_WORD:
				if(list_dataTypes[i]!=DATATYPE_ASTREE_INTEGER)
				{
					fprintf(stderr,"Erro na linha  %d. Parametro %d incompativel com sua declaracao na funcao. (dataType) \n", getLineNumber(),i);
					set_error_flag();
				}
				break;
			case DATATYPE_BOOL:
				if(list_dataTypes[i]!=DATATYPE_ASTREE_BOOLEAN)
				{
					fprintf(stderr,"Erro na linha  %d. Parametro %d incompativel com sua declaracao na funcao. (dataType) \n", getLineNumber(),i);
					set_error_flag();
				}
				break;
		} */

	}
}
