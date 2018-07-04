#include "tac.h"


void generateAdd(TAC * tac, FILE * out);
void generateSub(TAC * tac, FILE * out);
void generateMul(TAC * tac, FILE * out);
void generateInstr(TAC * tac, FILE * out);

void generateAsm(TAC * tac);
void generateBoolOp(TAC * tac, FILE * out);
void generateStrDec(TAC * tac, FILE * out);
void generateDeclarations(TAC * tac, FILE * out);
