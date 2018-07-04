#
# UFRGS - Compiladores B - Marcelo Johann - 2009/2 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa6: y.tab.o lex.yy.o main.o hash.o semantics.o astree.o tac.o y.tab.o asm.o
	gcc -g -gdwarf -o etapa6 lex.yy.o main.o hash.o semantics.o astree.o tac.o y.tab.o asm.o
hash.o:	hash.c
	gcc -g -gdwarf -c hash.c
tac.o:	tac.c
	gcc -g -gdwarf -c tac.c
asm.o:
	gcc -g -gdwarf -c asm.c
semantics.o:	semantics.c
	gcc -g -gdwarf -c semantics.c
astree.o: astree.c
	gcc -g -gdwarf -c astree.c
main.o: main.c
	gcc -g -gdwarf -c main.c
lex.yy.o: lex.yy.c
	gcc -g -gdwarf -c lex.yy.c
lex.yy.c: scanner.l
	lex scanner.l
y.tab.o: y.tab.c
	gcc -g -gdwarf -c y.tab.c
y.tab.c: parser.y
	yacc -d -v parser.y

run: etapa6
	./etapa6

file: etapa6
	./etapa6 code.test out.test


clean:
	rm lex.yy.c lex.yy.o main.o hash.o y.tab.h y.tab.c y.tab.o etapa6 astree.o semantics.o tac.o asm.o
