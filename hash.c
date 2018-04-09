#include "hash.h"
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
	HASHNODE * newNode = hashSearch(text);
	int address = getHashAddress(text);
	
	if (newNode != NULL)
		return newNode;
	newNode = (HASHNODE *) calloc (1, sizeof(HASHNODE));
	newNode->text = (char *) calloc (strlen(text)+1, sizeof(char));
	strcpy(newNode->text, text);
	newNode->type = type;
	newNode->next = hashTable[address];
	hashTable[address] = newNode;
	return newNode;
}

HASHNODE * hashSearch(char * text){
	int address;
	HASHNODE * node;
	address = getHashAddress(text);
	node = hashTable[address];
	while (node != NULL){
		if (strcmp(node->text, text))
			return node;
		node = node->next;
	}
	return NULL;
}

