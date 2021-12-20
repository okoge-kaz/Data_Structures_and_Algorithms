#include <stdio.h> 
#include <stdlib.h>
#include "item.h"
#include "list.h"

link new_node(Item item, link l, link r) {
  link t = malloc(sizeof *t);

  t->item = item;
  t->l = l; t->r = r;
  return t;
}

void add_left_leaf(link parent, Item item) {
  parent->l = new_node(item, NULL, NULL);
}

void add_right_leaf(link parent, Item item) {
  parent->r = new_node(item, NULL, NULL);
}