#
# UFRGS - Compiladores B - Marcelo Johann - 2009/2 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa1: lex.yy.o main.o hash.o
	gcc -o etapa1 lex.yy.o main.o hash.o
hash.o:	hash.c
	gcc -c hash.c
main.o: main.c
	gcc -c main.c
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c 
lex.yy.c: scanner.l
	lex scanner.l

run: etapa1
	./etapa1

file: etapa1
	./etapa1 code.test


clean:
	rm lex.yy.c lex.yy.o main.o hash.o etapa1
