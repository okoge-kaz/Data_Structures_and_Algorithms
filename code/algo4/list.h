#ifndef LIST_H
#define LIST_H

#include "item.h"
typedef struct node *link;

struct node {
  Item item;
  link l, r;
};

link new_node(Item, link, link);
void add_left_leaf(link, Item);
void add_right_leaf(link, Item);
  
#endif