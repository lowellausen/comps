#include "hash.h"
#include "astree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//HASHNODE * hashTable[HASH_TABLE_SIZE];

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
		address = (address*text[i]) % HASH_TABLE_SIZE +7;
	return address -1;
}

HASHNODE * hashInsert(char * text, int type, int dataType){
	HASHNODE * newNode = hashSearch(text);
	int address = getHashAddress(text);
	
	if (newNode != NULL)
		return newNode;
	newNode = (HASHNODE *) calloc (1, sizeof(HASHNODE));
	newNode->text = (char *) calloc (strlen(text)+1, sizeof(char));
	strcpy(newNode->text, text);
	newNode->type = type;
	newNode->dataType = dataType;
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
		if (strcmp(node->text, text)==0)
			return node;
		node = node->next;
	}
	return NULL;
}
HASHNODE * makeTemp(void)
{
	static int nextTemp = 0;
	char tempName[256];

	sprintf(tempName,"Temp%d", nextTemp++);
	return hashInsert(tempName,SYMBOL_VARTEMP,0);
}


HASHNODE * makeLabel(void)
{
	static int nextLabel = 0;
	char labelName[256];

	sprintf(labelName, "Label%d", nextLabel++);
	return hashInsert(labelName, SYMBOL_LABEL,0);
}

