#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "graph.h"

typedef struct node *link;
struct node {int v; link next; };
struct graph {int V; int E; link *adj; };


link NEW(int v, link next){
  link x = malloc(sizeof *x); 
  x->v = v; x->next=next;
  return x;
}

Graph GRAPHinit(int V) {
  Graph G = malloc(sizeof *G); 
  G->V = V; G->E =0;
  G->adj = malloc(V*sizeof(link)); 
  for(int v = 0; v < V; v++)
    G->adj[v] = NULL;
  return G;
}

void GRAPHinsertE(Graph G, Edge e) {
  int v=e.v, w=e.w; 
  G->adj[v] = NEW(w, G->adj[v]);
  G->adj[w] = NEW(v, G->adj[w]);
  G->E++;
}

void GRAPHremoveE(Graph G, Edge e) {
  int v = e.v;
  int w = e.w;
  link t;
  if (G->adj[v]->v == w) {
    G->adj[v] = G->adj[v]->next;
  } else {
    for (t = G->adj[v]; t->next != NULL; t = t->next) {
      if (t->next->v == w) {
	t->next = t->next->next;
	break; 
      }
    } 
  }
  if (G->adj[w]->v == v) {
    G->adj[w] = G->adj[w]->next;
  } else {
    for (t = G->adj[w]; t->next != NULL; t = t->next) {
      if (t->next->v == v) {
	t->next = t->next->next;
	break;
      } 
    }
  } 
}

Edge EDGE(int v, int w) {
  Edge e;
  e.v = v; e.w = w;
  return e;
}

int randV(Graph G) {
  return G->V * (rand() / (RAND_MAX + 1.0));
}

Graph GRAPHrand(int V, int E) {
  Graph G = GRAPHinit(V);
  while (G->E < E) 
    GRAPHinsertE(G, EDGE(randV(G), randV(G)));
  return G;
}

void GRAPHshow(Graph G) {
  printf("%d vertics, %d edges\n", G->V, G->E);
  for(int i = 0; i < G->V; i++){
    printf("%2d:", i);
    for(link t = G->adj[i]; t != NULL; t = t->next){
      printf(" %2d", t->v);
    }
    printf("\n");
  }
}

