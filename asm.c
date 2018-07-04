#include "asm.h"
#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



int LFBcount = 0;
int LFEcount = 0;
int LCcount = 0;

int inStrDCount = -1;
int inStrCCount = -1;
int firstVarInit = 0;
int vectorInitVarCount = 0;
int vectorInitSize = 0;
int vectorIsWord = 0;


void generateASM(TAC * tac)
{
	FILE * out;
	out = fopen("asm.s", "w");

	fprintf(out, "\t.data\n");

	generateDeclarations(tac, out);
	generateStrDec(tac, out);

	fprintf(out, "\t.text\n");

	generateInstr(tac, out);


	fclose(out);
}

void generateInstr(TAC * tac, FILE * out)
{
	LCcount = 0;

	if(tac == 0)
		return;

	TAC * firstTac = tac;
	TAC * aux;
	TAC * aux2, *aux3;

	int numArgs = 0;
	int numArgsPrint = 0;
	int beginFuncArgs = 0;
	int espOffset=0;
	int i;
	char tempString[100];

	for(; tac; tac = tac->next)
	{
		switch(tac->type)
		{
			      case TAC_BEGINFUNC:
					beginFuncArgs = 0;


					if(!strcmp(tac->res->text,"main")) //Se for a main
					{
						fprintf(out,
							"\t.globl	main\n"
							"\t.type	main, @function\n"
							"main:\n"
							".LFB%d:\n"		// Aux counter
							"\tpushl	%%ebp\n"
							"\tmovl	%%esp, %%ebp\n"
							"\tandl	$-16, %%esp\n"
						, LFBcount++);
					}

					else
					{
						aux = tac->next;
						/*if(aux->type == TAC_HEADER)
						{
							aux2=aux=aux->next;
							while(aux->type  == TAC_FUNCDEC_PARAMS2)
							{
								beginFuncArgs++;
								aux=aux->next;
							}
						}*/ //ver aqui


						fprintf(out,
							"\t.globl	%s\n"
							"%s:\n"
							".LFB%d:\n"		// Aux counter
							"\tpushl	%%ebp\n"
							"\tmovl	%%esp, %%ebp\n"
							, tac->res->text, tac->res->text, LFBcount++);
						if(beginFuncArgs > 0)
						{
							sprintf (tempString, "%d", beginFuncArgs*4);
							fprintf(out,
								"\tsubl	$%s, %%esp\n"
								,tempString);
							aux = aux2; //(primeiro argumento)
							for(i = 0; i < beginFuncArgs; i++, aux=aux->next)
							{
								sprintf (tempString, "%d", i*4+8);
								fprintf(out,
									"\tmovl	%s(%%ebp), %%eax\n"
									,tempString);
								sprintf (tempString, "%d", i*(-4)-4);
								fprintf(out,
									"\tmovw	%%ax, %s(%%ebp)\n"
									"\tmovw	%%ax, %s\n"
									,tempString,aux->res->text);
							}
						}

					}
				break;

				case TAC_ENDFUNC:
					if(!strcmp(tac->res->text,"main"))
						fprintf(out,
							"\tleave\n"
							"\tret\n"
							".LFE%d:\n"
							".size	main, .-main\n"
						, LFEcount++);
					else
						fprintf(out,
							"\tleave\n"
							"\tret\n"
							".LFE%d:\n"
							".size	%s, .-%s\n"
						, LFEcount++, tac->res->text, tac->res->text);
				break;

				case TAC_CALL:
					espOffset = 0;
					numArgs = 0;
					aux=tac->prev;
					while(aux)
					{
						printf("aux 22=%d\n",aux->type);
						if(aux->type == TAC_ARG)
							numArgs++;
						if(aux->type == TAC_ARG || aux->type == TAC_SYMBOL)
						{
							aux=aux->prev;
						}
						else
						{
							aux=aux->next;
							break;
						}
					}
					if(numArgs>0)
						fprintf(out,
								"\tsubl	$%d, %%esp\n"
							, numArgs*4);
					aux2=aux;
					while(aux2 && (aux2->type == TAC_ARG || aux2->type == TAC_SYMBOL))
					{
						if(aux2->type == TAC_ARG)
						{

							if(espOffset > 0)
								fprintf(out,
									"\tmovl	$%s, %d(%%esp)\n"
								,aux2->op1->text, espOffset);
							else
								fprintf(out,
									"\tmovl	$%s, (%%esp)\n"
								,aux2->op1->text);
							espOffset += 4;
						}
						if(aux2->type != TAC_ARG && aux2->type != TAC_SYMBOL)
							break;
						aux2=aux2->next;
					}


					fprintf(out,
						"\tcall\t%s\n"
						"\tmovw	%%ax, %s\n"
					, tac->op1->text, tac->res->text);	// function name, return value
				break;

				case TAC_RETURN:
					if(tac->res)
					if(tac->res->type == SYMBOL_IDENTIFIER || tac->res->type == SYMBOL_VARTEMP)
						fprintf(out,"\tmovzwl	%s, %%eax\n", tac->res->text);
					else
						fprintf(out,"\tmovl	$%s, %%eax\n", tac->res->text);
				break;

				case TAC_MOVE:
					// mov a,b (a = b)
					printf("type=%d name=%s\n",tac->op1->type,tac->op1->text);
					if((tac->op1->type == SYMBOL_IDENTIFIER || tac->op1->type == SYMBOL_VARTEMP))
					{
						fprintf(out,"\tmovw	%s, %%ax\n", tac->op1->text);
						fprintf(out,"\tmovw	%%ax, %s\n", tac->res->text);
					}
					else
					{
						if (!strcmp(tac->op1->text,"TRUE"))
							fprintf(out,"\tmovb	$1, %s\n", tac->res->text);
						else
						if (!strcmp(tac->op1->text,"FALSE"))
							fprintf(out,"\tmovb	$0, %s\n", tac->res->text);
						else
					   		fprintf(out,"\tmovw	$%s, %s\n", tac->op1->text,tac->res->text);
					}
				break;

				case TAC_PRINT:

				for(aux = tac->prev; aux->type == TAC_ARG ||
						aux->type == TAC_SYMBOL ||
						aux->type == TAC_TEMP ||
						aux->type == TAC_VECTOR_READ; aux = aux->prev)
					;

   			        numArgsPrint=0;
				for(aux = aux->next ; aux != tac ; aux = aux->next)
				{
					if(aux->type == TAC_ARG)
					{
						numArgsPrint++;
						printf("numargsprint=%d\n",numArgsPrint);

						if(aux->op1->type == SYMBOL_LIT_STRING && strcmp(aux->op1->text,"%c") && strcmp(aux->op1->text,"%d"))
							fprintf(out,
								"\tmovl	$.LC%d, %%eax\n"
								"\tmovl	%%eax, (%%esp)\n"
								"\tcall	printf\n"
							,LCcount++);
						else if(aux->op1->dataType == DATATYPE_ASTREE_INTEGER || aux->op1->dataType == DATATYPE_ASTREE_INTEGER || aux->op1->dataType == DATATYPE_ASTREE_BOOLEAN || aux->op1->type == SYMBOL_VARTEMP)
							if(aux->op1->natureza == SYMBOL_PTR && aux->prev->type == TAC_POINTER)
								;
							else
							{
								if(aux->op1->dataType == DATATYPE_ASTREE_INTEGER)
									fprintf(out,
									"\tmovzbl	%s, %%eax\n"
									"\tcwtl\n"
									"\tmovl	%%eax, 4(%%esp)\n"
									"\tmovl	$.LCD0, (%%esp)\n"
									"\tcall	printf\n"
									,aux->op1->text);
								else
									fprintf(out,
									"\tmovzwl	%s, %%eax\n"
									"\tcwtl\n"
									"\tmovl	%%eax, 4(%%esp)\n"
									"\tmovl	$.LCD0, (%%esp)\n"
									"\tcall	printf\n"
									,aux->op1->text);
							}

					}

				}
			break;

			case TAC_VECTOR_READ:
				if(tac->op1)
				{
					if(tac->op1->dataType == DATATYPE_ASTREE_INTEGER || tac->op1->dataType == DATATYPE_ASTREE_BOOLEAN)
						sprintf (tempString, "%d", atoi(tac->op2->text));
					else
						sprintf (tempString, "%d", atoi(tac->op2->text)*2);
					if(tac->res)
						fprintf(out,
							"\tmovzwl	%s+%s,  %%eax\n"
							"\tmovl	%%eax, %s\n"
							, tac->op1->text,tempString,tac->res->text);
				}
			break;

			case TAC_VECTOR_WRITE:
				if(tac->op1)
				{
					if(tac->op1->dataType == DATATYPE_ASTREE_INTEGER || tac->op1->dataType == DATATYPE_ASTREE_BOOLEAN)
						sprintf (tempString, "%d", atoi(tac->op1->text));
					else
						sprintf (tempString, "%d", atoi(tac->op1->text)*2);
					if(tac->res)
						if(tac->op2->type == SYMBOL_IDENTIFIER)
							fprintf(out,
								"\tmovzwl	%s,  %%eax\n"
								"\tmovl	%%eax, %s+%s\n"
								, tac->op2->text,tac->res->text,tempString);
						else
							fprintf(out,
								"\tmovw	$%s,  %s+%s\n"
								, tac->op2->text,tac->res->text,tempString);
				}
			break;

			case TAC_ADD:
				generateAdd(tac, out);
			break;

			case TAC_SUB:
				generateSub(tac, out);
			break;

			case TAC_MUL:
				generateMul(tac, out);
			break;

			case TAC_EQ:
			case TAC_LE:
			case TAC_GE:
			case TAC_NE:
			case TAC_GREATER:
			case TAC_LESS:
					generateBoolOp(tac, out);
					break;

			case TAC_AND:
			case TAC_OR:
				if(tac->type==TAC_OR)
					strcpy(tempString,"\torb	%ah,  %al\n");
				else
					strcpy(tempString,"\tandb	%ah,  %al\n");

				if(tac->op1->type == SYMBOL_LIT_STRING && tac->op2->type != SYMBOL_LIT_STRING)
				{
					if(!strcmp(tac->op1->text,"TRUE"))
						fprintf(out,
							"\tmovb	$1,  %%al\n");
					else
						fprintf(out,
							"\tmovb	$0,  %%al\n");
					fprintf(out,
						"\tmovb	%s,  %%ah\n"
						"%s"
						"\tmovb %%al, %s\n"
						,tac->op2->text,tempString,tac->res->text);
				}
				else
				if(tac->op1->type != SYMBOL_LIT_STRING && tac->op2->type == SYMBOL_LIT_STRING)
				{
					fprintf(out,
						"\tmovb	%s,  %%al\n"
						, tac->op1->text);
					if(!strcmp(tac->op2->text,"TRUE"))
						fprintf(out,
							"\tmovb	$1,  %%ah\n");
					else
						fprintf(out,
							"\tmovb	$0,  %%ah\n");
					fprintf(out,
						"%s"
						"\tmovb %%al, %s\n"
						,tempString,tac->res->text);
				}
				else
				if(tac->op1->type == SYMBOL_LIT_STRING && tac->op2->type == SYMBOL_LIT_STRING)
				{
					if(!strcmp(tac->op1->text,"TRUE"))
						fprintf(out,
							"\tmovb	$1,  %%al\n");
					else
						fprintf(out,
							"\tmovb	$0,  %%al\n");

					if(!strcmp(tac->op2->text,"TRUE"))
						fprintf(out,
							"\tmovb	$1,  %%ah\n");
					else
						fprintf(out,
							"\tmovb	$0,  %%ah\n");
					fprintf(out,
						"%s"
						"\tmovb %%al, %s\n"
						,tempString,tac->res->text);
				}
				else
				{
					fprintf(out,
						"\tmovb	%s,  %%al\n"
						"\tmovb	%s,  %%ah\n"
						"%s"
						"\tmovb %%al, %s\n"
						, tac->op1->text,tac->op2->text, tempString,tac->res->text);
				}
			break;


			case TAC_LABEL:
			//printf("antes do label\n");
				fprintf(out,
					"%s:\n"
				, tac->res->text);
			//printf("depois do label\n");
			break;

			case TAC_JUMP:
			//printf("antes do jump\n");
				fprintf(out,
					"\tjmp	%s\n"
				, tac->op1->text);
			//printf("depois do jump\n");
			break;

			case TAC_IFZ:
			//printf("antes do ifz\n");
				fprintf(out,
					"\tmovw	%s,%%ax\n"
					"\ttestw	%%ax,%%ax\n"
					"\tjz	%s\n"
				, tac->res->text, tac->op1->text);
			//printf("depois do ifz\n");
			break;

			case TAC_IFNZ:
				fprintf(out,
					"\tmovw	%s,%%ax\n"
					"\ttestw	%%ax,%%ax\n"
					"\tjnz	%s\n"
				, tac->res->text, tac->op1->text);
			break;

			case TAC_INPUT:

				if(tac->res->dataType == DATATYPE_ASTREE_INTEGER)
				{
					fprintf(out,
						"\tmovl	$%s, 4(%%esp)\n"
						"\tmovl	$.LCD0, (%%esp)\n"
						"\tcall	__isoc99_scanf\n"
					, tac->res->text);

				}
				else if(tac->res->dataType == DATATYPE_ASTREE_INTEGER)
				{
					fprintf(out,
						"\tmovl	$%s, 4(%%esp)\n"
						"\tmovl	$.LCC0, (%%esp)\n"
						"\tcall	__isoc99_scanf\n"
					, tac->res->text);
				}
			break;



		}
	}
}

void generateDeclarations(TAC * tac, FILE * out)
{
   TAC * aux, *aux2;
   char tempString[100];
   int i;

   for(aux = tac; aux; aux = aux->next)
	{
		switch(aux->type)
		{
			/*case TAC_VECTORDEC:
				if(aux->res)
					fprintf(out,"\t.comm	%s,%s,32\n",aux->res->text,aux->op1->text);
			break;
			case TAC_VECTORDEC_INIT:
				vectorInitVarCount = 0;
				fprintf(out,
					".globl 	%s\n"
				, aux->res->text);

				fprintf(out,"\t.align 32\n");

				fprintf(out,
					"\t.type	%s, @object\n"
				, aux->res->text);

				if(aux->res->dataType == DATATYPE_ASTREE_BOOLEAN || aux->res->dataType == DATATYPE_ASTREE_INTEGER)
				{
					vectorIsWord = 0;
					vectorInitSize = atoi(aux->op1->text);
					fprintf(out,"\t.size	%s,%s",aux->res->text,aux->op1->text);
				}
				else
				if(aux->res->dataType == DATATYPE_ASTREE_INTEGER)
				{
					vectorIsWord = 1;
					vectorInitSize = atoi(aux->op1->text)*2;
					sprintf (tempString, "%d", atoi(aux->op1->text)*2);
					fprintf(out,"\t.size	%s,%s",aux->res->text,tempString);
				}

				fprintf(out,
					"\n%s:\n"
				, aux->res->text);
			break;*/
			//  VER AQUI!!!!

			case TAC_VECTOR_INIT:
				if (vectorIsWord == 1)
					vectorInitVarCount++;
   				vectorInitVarCount++;
				fprintf(out,"\t.value %s\n",aux->res->text);
				if (aux->next)
					if (aux->next->type != TAC_VECTOR_INIT)
					{
						sprintf (tempString, "%d", vectorInitSize-vectorInitVarCount);
						if (strcmp(tempString,"0"))
							fprintf(out,"\t.zero %s\n",tempString);
					}
			break;

			case TAC_VARDEC_INIT:
			case TAC_POINTER_DEC:
				fprintf(out,
					".globl 	%s\n"
				, aux->res->text);

				if (firstVarInit == 0)
				{
					fprintf(out,
					"\t.data 	\n");
				}
				firstVarInit=1;

				if(aux->res->dataType == DATATYPE_ASTREE_INTEGER)
					fprintf(out,"\t.align 2\n");

				fprintf(out,
					"\t.type	%s, @object\n"
				, aux->res->text);

				if(aux->res->dataType == DATATYPE_ASTREE_BOOLEAN || aux->res->dataType == DATATYPE_ASTREE_INTEGER)
					fprintf(out,"\t.size	%s,1",aux->res->text);
				else
				if(aux->res->dataType == DATATYPE_ASTREE_INTEGER)
					fprintf(out,"\t.size	%s,2",aux->res->text);

				fprintf(out,
					"\n%s:\n"
				, aux->res->text);


				if(aux->res->dataType == DATATYPE_ASTREE_BOOLEAN)
					if(!strcmp(aux->op1->text,"TRUE"))
						fprintf(out,
							"\t.long	1\n");
					else
						fprintf(out,
							"\t.long	0\n");
				else if(aux->res->dataType == DATATYPE_ASTREE_INTEGER)
					fprintf(out,
						"\t.byte	%d\n", (*(aux)->op1->text) == 39 ? (*(aux->op1->text+1)) : atoi(aux->op1->text));
				else if(aux->res->dataType == DATATYPE_ASTREE_INTEGER)
					fprintf(out,
						"\t.long	%s\n"
					, aux->op1->text);
			break;

			case TAC_VARDEC:
			case TAC_POINTER_DEC_NO_INIT:
				if(aux->res)
				{
					if(aux->res->dataType == DATATYPE_ASTREE_BOOLEAN || aux->res->dataType == DATATYPE_ASTREE_INTEGER)
						fprintf(out,"\t.comm	%s,1,1\n",aux->res->text);
					else
						fprintf(out,"\t.comm	%s,2,2\n",aux->res->text);
				}
			break;

			case TAC_TEMP:
			case TAC_FUNCDEC_PARAMS2:
			//("antes do TEMP\n");
					fprintf(out,
						"\t.globl	%s\n"
						"%s:\n"
						"\t.long	0\n"
					, aux->res->text, aux->res->text);
			//printf("depois do TEMP\n");

				break;
		}
	}
}


void generateStrDec(TAC * tac, FILE * out)
{
	if(tac == 0)
		return;

	TAC * aux;
	TAC * aux2;

	for(aux = tac; aux->next ; aux = aux->next)
	{

			if(aux->type == TAC_ARG)
			{
				if(aux->op1->type == SYMBOL_LIT_STRING)
					fprintf(out,
						".LC%d:\n"
						"\t.string	%s\n"
					, LCcount++, aux->op1->text);
			}
			else if(aux->type == TAC_INPUT)
			{

				if(inStrDCount < 0)
				{
					inStrDCount = 1;
					fprintf(out,
						".LCD0:\n"
						"\t.string	\"%%d\"\n");
					fprintf(out,
						".LCC0:\n"
						"\t.string	 \"%%c\"\n");
				}
			}
			else if(aux->type == TAC_PRINT)
			{
				for(aux2 = aux->prev ; aux2->type == TAC_ARG ||
						aux2->type == TAC_SYMBOL ||
						aux2->type == TAC_TEMP ||
						aux2->type == TAC_VECTOR_READ ; aux2 = aux2->prev)
					;

				for(aux2 = aux2->next ; aux2 != aux ; aux2 = aux2->next)
				{
					if(aux2->type == TAC_ARG)
						if((aux2->op1->dataType == DATATYPE_ASTREE_INTEGER || aux2->op1->type == SYMBOL_VARTEMP || aux2->op1->dataType == DATATYPE_ASTREE_INTEGER || aux2->op1->dataType == DATATYPE_ASTREE_BOOLEAN) && inStrDCount < 0)
						{
							inStrDCount = 1;
							fprintf(out,
								".LCD0:\n"
								"\t.string	\"%%d\"\n");
							fprintf(out,
								".LCC0:\n"
								"\t.string	 \"%%c\"\n");

						}
				}
			}

	}

}



void generateAdd(TAC * tac, FILE * out)
{
	if(tac->op1->type == SYMBOL_LIT_INTEGER && tac->op2->type == SYMBOL_LIT_INTEGER)
	{
		fprintf(out,
				"\tmovl	$%s, %%eax\n"
				"\taddl	$%s, %%eax\n"
				"\tmovw	%%ax, %s\n"
				, tac->op1->text, tac->op2->text,tac->res->text);
	}
	else
	if((tac->op1->type == SYMBOL_IDENTIFIER || tac->op1->type == SYMBOL_VARTEMP) && tac->op2->type == SYMBOL_LIT_INTEGER)
	{
		fprintf(out,
				"\tmovl	%s, %%eax\n"
				"\taddl	$%s, %%eax\n"
				"\tmovw	%%ax, %s\n"
				, tac->op1->text, tac->op2->text,tac->res->text);
	}
	else
	if(tac->op1->type == SYMBOL_LIT_INTEGER && (tac->op2->type == SYMBOL_IDENTIFIER || tac->op2->type == SYMBOL_VARTEMP))
	{
		fprintf(out,
				"\tmovl	%s, %%eax\n"
				"\taddl	$%s, %%eax\n"
				"\tmovw	%%ax, %s\n"
				, tac->op2->text, tac->op1->text,tac->res->text);
	}
	else
	if((tac->op1->type == SYMBOL_IDENTIFIER || tac->op1->type == SYMBOL_VARTEMP) && (tac->op2->type == SYMBOL_IDENTIFIER || tac->op2->type == SYMBOL_VARTEMP))
	{
		fprintf(out,
				"\tmovl	%s, %%eax\n"
				"\tmovl	%s, %%edx\n"
				"\taddl	%%edx, %%eax\n"
				"\tmovw	%%ax, %s\n"
				, tac->op2->text, tac->op1->text,tac->res->text);
	}
}

void generateSub(TAC * tac, FILE * out)
{
	//printf("op2type=%d\n",tac->op2 ? tac->op2->type : 0);
	if(tac->op1->type == SYMBOL_LIT_INTEGER && tac->op2->type == SYMBOL_LIT_INTEGER)
	{
		fprintf(out,
				"\tmovl	$%s, %%eax\n"
				"\tsubl	$%s, %%eax\n"
				"\tmovw	%%ax, %s\n"
				, tac->op1->text, tac->op2->text,tac->res->text);
	}
	else
	if((tac->op1->type == SYMBOL_IDENTIFIER || tac->op1->type == SYMBOL_VARTEMP) && tac->op2->type == SYMBOL_LIT_INTEGER)
	{
		fprintf(out,
				"\tmovl	%s, %%eax\n"
				"\tsubl	$%s, %%eax\n"
				"\tmovw	%%ax, %s\n"
				, tac->op1->text, tac->op2->text,tac->res->text);
	}
	else
	if(tac->op1->type == SYMBOL_LIT_INTEGER && (tac->op2->type == SYMBOL_IDENTIFIER || tac->op2->type == SYMBOL_VARTEMP))
	{
		fprintf(out,
				"\tmovl	$%s, %%eax\n"
				"\tsubl	%s, %%eax\n"
				"\tmovw	%%ax, %s\n"
				, tac->op1->text, tac->op2->text,tac->res->text);
	}
	else
	if((tac->op1->type == SYMBOL_IDENTIFIER || tac->op1->type == SYMBOL_VARTEMP) && (tac->op2->type == SYMBOL_IDENTIFIER || tac->op2->type == SYMBOL_VARTEMP))
	{
		fprintf(out,
				"\tmovl	%s, %%eax\n"
				"\tmovl	%s, %%edx\n"
				"\tsubl	%%edx, %%eax\n"
				"\tmovw	%%ax, %s\n"
				, tac->op1->text, tac->op2->text,tac->res->text);
	}
}

void generateMul(TAC * tac, FILE * out)
{
	if(tac->op1->type == SYMBOL_LIT_INTEGER && tac->op2->type == SYMBOL_LIT_INTEGER)
	{
		fprintf(out,
				"\tmovl	$%s, %%eax\n"
				"\timulw	$%s, %%ax, %%ax\n"
				"\tmovw	%%ax, %s\n"
				, tac->op1->text, tac->op2->text,tac->res->text);
	}
	else
	if((tac->op1->type == SYMBOL_IDENTIFIER || tac->op1->type == SYMBOL_VARTEMP) && tac->op2->type == SYMBOL_LIT_INTEGER)
	{
		fprintf(out,
				"\tmovl	%s, %%eax\n"
				"\timulw	$%s, %%ax, %%ax\n"
				"\tmovw	%%ax, %s\n"
				, tac->op1->text, tac->op2->text,tac->res->text);
	}
	else
	if(tac->op1->type == SYMBOL_LIT_INTEGER && (tac->op2->type == SYMBOL_IDENTIFIER || tac->op2->type == SYMBOL_VARTEMP))
	{
		fprintf(out,
				"\tmovl	%s, %%eax\n"
				"\timulw	$%s, %%ax, %%ax\n"
				"\tmovw	%%ax, %s\n"
				, tac->op2->text, tac->op1->text,tac->res->text);
	}
	else
	if((tac->op1->type == SYMBOL_IDENTIFIER || tac->op1->type == SYMBOL_VARTEMP) && (tac->op2->type == SYMBOL_IDENTIFIER || tac->op2->type == SYMBOL_VARTEMP))
	{
		fprintf(out,
				"\tmovl	%s, %%eax\n"
				"\tmovl	%s, %%edx\n"
				"\timull	%%edx, %%eax\n"
				"\tmovw	%%ax, %s\n"
				, tac->op2->text, tac->op1->text,tac->res->text);
	}
}

void generateBoolOp(TAC *tac, FILE* out)
{
	char tempString[100];
	switch (tac->type)
	{
		case TAC_EQ:
			strcpy(tempString,"\tsete	%al\n");
		break;
		case TAC_LE:
			strcpy(tempString,"\tsetle	%al\n");
		break;
		case TAC_GE:
			strcpy(tempString,"\tsetge	%al\n");
		break;
		case TAC_LESS:
			strcpy(tempString,"\tsetl	%al\n");
		break;
		case TAC_GREATER:
			strcpy(tempString,"\tsetg	%al\n");
		break;
		case TAC_NE:
			strcpy(tempString,"\tsetne	%al\n");
		break;
	}
			if(tac->op1->type == SYMBOL_LIT_INTEGER && (tac->op2->type == SYMBOL_IDENTIFIER || tac->op2->type == SYMBOL_VARTEMP))
			{
				fprintf(out,
					"\tmovzwl	%s, %%eax\n"
					"\tcmpw	$%s, %%ax\n"
					"%s"
					"\tmovzbl	%%al, %%eax\n"
					"\tmovw	%%ax, %s\n"
					, tac->op2->text, tac->op1->text, tempString, tac->res->text);
			}
			else
			if((tac->op1->type == SYMBOL_IDENTIFIER || tac->op1->type == SYMBOL_VARTEMP) && tac->op2->type == SYMBOL_LIT_INTEGER)
			{
				fprintf(out,
					"\tmovzwl	%s, %%eax\n"
					"\tcmpw	$%s, %%ax\n"
					"%s"
					"\tmovzbl	%%al, %%eax\n"
					"\tmovw	%%ax, %s\n"
					, tac->op1->text, tac->op2->text, tempString, tac->res->text);
			}
			else
			if((tac->op1->type == SYMBOL_IDENTIFIER || tac->op1->type == SYMBOL_VARTEMP) && (tac->op2->type == SYMBOL_IDENTIFIER || tac->op2->type == SYMBOL_VARTEMP))
			{
				fprintf(out,
					"\tmovzwl	%s, %%eax\n"
					"\tmovzwl	%s, %%edx\n"
					"\tcmpw	%%dx, %%ax\n"
					"%s"
					"\tmovzbl	%%al, %%eax\n"
					"\tmovw	%%ax, %s\n"
					, tac->op1->text, tac->op2->text, tempString, tac->res->text);
			}
			else
			if(tac->op1->type == SYMBOL_LIT_INTEGER && tac->op2->type == SYMBOL_LIT_INTEGER)
			{
				fprintf(out,
					"\tmovw	$%s, %%ax\n"
					"\tcmpw	$%s, %%ax\n"
					"%s"
					"\tmovzbl	%%al, %%eax\n"
					"\tmovw	%%ax, %s\n"
					, tac->op1->text, tac->op2->text, tempString, tac->res->text);
			}

}
