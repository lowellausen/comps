#define HASH_TABLE_SIZE 500

typedef struct hashNode{
	char * text;
	int type;
	struct hashNode *next;
} HASHNODE;

HASHNODE * hashTable[HASH_TABLE_SIZE];

void hashInit();
void hashPrint();
int getHashAddress(char * text);
HASHNODE * hashInsert(char * text, int type);
HASHNODE * hashSearch(char * text);
