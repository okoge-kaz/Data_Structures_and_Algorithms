#include <stdlib.h>
#include "Item.h"
#include "queue.h"

typedef struct QUEUEnode* qlink;
struct QUEUEnode { Item item; qlink next; };
static qlink head, tail;

qlink qNEW(Item item, qlink next){
  qlink x = malloc(sizeof *x);
  x->item = item; x->next = next;     
  return x;                         
}                                   

void QUEUEinit() {
  head = NULL; 
}

int QUEUEempty() {
  return head == NULL; 
}

void QUEUEput(Item item) {
  if (head == NULL) {
    head = (tail = qNEW(item, head)); 
    return; 
  }
  tail->next = qNEW(item, tail->next); 
  tail = tail->next;
}

Item QUEUEget() {
  Item item = head->item;
  qlink t = head->next; 
  free(head); 
  head = t;
  return item;
}
