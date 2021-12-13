#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

static Item *s;
static int N;

void STACKinit(int maxN) {
  s = malloc(maxN*sizeof (Item));
  N = 0;
}

int STACKempty() {
  return N == 0;
}

void STACKpush(Item item) {
  s[N] = item;
  N++;
}

Item STACKpop() {
  Item pop_item = s[N-1];
  N--;
  return pop_item;
}

void STACKprint() {
  for (int i=N-1; i>=0; i--) {
    printItem(s[i]);
    printf(" ");
  }
  printf("\n");
}
