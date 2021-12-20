#include "Item.h"

static Item *pq;
static int N;

void PQinit(int);
int PQempty();
void PQinsert(Item);
Item PQdelmin();