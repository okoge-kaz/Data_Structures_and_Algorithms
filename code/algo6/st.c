#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "st.h"

typedef struct STnode* link;
struct STnode {
  Item item;
  link next;
};
static link *heads, z;
static int N, M;

int hash(char *v, int M) {
  int h;
  int a = 127;

  for (h = 0; *v != '\0'; v++)
    h = (a*h + *v) % M;
  return h;
}

int eq(char *a, char *b) {
  return (strcmp(a, b) == 0);
}

static link NEW(Item item, link next) {
  link x = malloc(sizeof *x);

  x->item = item;
  x->next = next;
  return x;
}

Item searchR(link t, Key v) {
  if (t == z)
    return NULLitem;
  if (eq(key(t->item), v))
    return t->item;
  return searchR(t->next, v);
}

Item search(link h, Key v) {
  while (h != z) {
    if (eq(key(h->item), v))
      return h->item;
    h = h->next;
  }
  return z->item;
}

void STinit(int max) {
  int i;
  
  N = 0;
  M = max/5;
  heads = malloc(M*sizeof(link));
  z = NEW(NULLitem, NULL);
  for (i = 0; i < M; i++)
    heads[i] = z;
}

void STinsert(Item item) {
  int i = hash(key(item), M);

  heads[i] = NEW(item, heads[i]);
  N++;
}

Item STsearch(Key v) {
  return searchR(heads[hash(v, M)], v);
}

/* オリジナルのst.cのdeleteを修正したバージョン 2022/1/4 by koike */
link delete(link h, Item item) {
  link l = h;
  link t;

  if (l == z){
    return z;
  }
  if (eq(key(l->item), key(item))) {
    h = l->next;
    free(l);
    return h;
  }
  t = l->next;
  while (t != z) {
    if (eq(key(t->item), key(item))) {
      // add expression here
      l->next = t->next;
      free(t);
      break;
    }
    l = l->next;
    t = l->next;
  }
  return h;
}

void STdelete(Item item) {
  int i = hash(key(item), M);

  heads[i] = delete(heads[i], item);
}