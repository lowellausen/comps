#
# UFRGS - Compiladores B - Marcelo Johann - 2009/2 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa3: y.tab.o lex.yy.o main.o hash.o y.tab.o astree.o
	gcc -o etapa3 lex.yy.o main.o hash.o y.tab.o astree.o
hash.o:	hash.c
	gcc -c hash.c
astree.o: astree.c
	gcc -c astree.c
main.o: main.c
	gcc -c main.c
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c 
lex.yy.c: scanner.l
	lex scanner.l
y.tab.o: y.tab.c
	gcc -c y.tab.c
y.tab.c: parser.y
	yacc -d -v parser.y

run: etapa3
	./etapa3

file: etapa3
	./etapa3 code.test out.test


clean:
	rm lex.yy.c lex.yy.o main.o hash.o y.tab.h y.tab.c y.tab.o etapa3 astree.o
