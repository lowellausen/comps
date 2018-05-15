#define HASH_TABLE_SIZE 500

#define   NATUREZA_ESCALAR	0
#define   NATUREZA_VETOR	1
#define   NATUREZA_FUNCTION	2
#define   NATUREZA_POINTER	3

#define   DATATYPE_CHAR		4
#define   DATATYPE_FLOAT	5
#define   DATATYPE_INTEGER	6

typedef struct hashNode{
	char * text;
	int type;
	int is_declared;
	int natureza;
	int dataType;
	int number_of_param_func;
	int list_dataTypes[20];
	int list_naturezas[20];
	struct hashNode *next;
} HASHNODE;



void hashInit();
void hashPrint();
int getHashAddress(char * text);
HASHNODE * hashInsert(char * text, int type);
HASHNODE * hashSearch(char * text);

