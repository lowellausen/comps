#include "hash.h"
#include "astree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HASHNODE * hashTable[HASH_TABLE_SIZE];

void hashInit(){
	int i;
	for (i=0; i < HASH_TABLE_SIZE; i++)
		hashTable[i] = NULL;
}

void hashPrint(){
	int i;
	HASHNODE *node;
	for (i=0; i < HASH_TABLE_SIZE; i++){
		node = hashTable[i];
		if (node != NULL)
			printf("Hash table %d:\n", i);
		while (node != NULL){
			printf("%s\n", node->text);
			node = node->next;
		}
	} // end for
}

int getHashAddress(char * text){
	int address =1;
	int i;

	for (i=0; i < strlen(text);i++)
		address = (address*text[i]) % HASH_TABLE_SIZE +1;
	return address -1;
}

HASHNODE * hashInsert(char * text, int type){
	//HASHNODE * newNode = hashSearch(text); //não insere caras iguais
	HASHNODE * newNode = NULL; //insere caras iguais
	int address = getHashAddress(text);
	
	if (newNode != NULL)
		return newNode;
	newNode = (HASHNODE *) calloc (1, sizeof(HASHNODE));
	newNode->text = (char *) calloc (strlen(text)+1, sizeof(char));
	strcpy(newNode->text, text);
	newNode->type = type;
	newNode->next = hashTable[address];
	hashTable[address] = newNode;
	/*if(address == 400){
	printf("\n\n\n%s!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n", newNode->text);
	}*/	
	return newNode;
}

HASHNODE * hashSearch(char * text){
	int address;
	HASHNODE * node;
	address = getHashAddress(text);
	node = hashTable[address];
	while (node != NULL){   //quando não tinha ninguém no addrres não entrava no while e retornava NULL  ok
		//if (strcmp(node->text, text)) //grrr		
		if (strcmp(node->text, text)==0)  //grrrrr
			return node;  //mas se tinha alguém ele retornava o próprio nodo só quando esse alguém era diferente!!
		node = node->next;
	}
	return NULL;
}

