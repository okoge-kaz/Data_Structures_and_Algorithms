#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


struct graph { int V; int E; int **adj; };

Edge EDGE(int v, int w) {
  Edge e;
  e.v = v; e.w = w;
  return e;
}

int **MATRIXint(int r, int c, int val) {
  int i, j;
  int **t = malloc(r * sizeof(int *));
  for (i = 0; i < r; i++)
    t[i] = malloc(c * sizeof(int));
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
      t[i][j] = val;
  return t;
}


Graph GRAPHinit(int V) {
  Graph G = malloc(sizeof *G);
  G->V = V; G->E = 0;
  G->adj = MATRIXint(V, V, 0);
  return G;
}

void GRAPHinsertE(Graph G, Edge e) {
  int v = e.v, w = e.w;
  if (G->adj[v][w] == 0) G->E++;
  G->adj[v][w] = 1; 
  G->adj[w][v] = 1;
}

void GRAPHremoveE(Graph G, Edge e) {
  int v = e.v, w = e.w;
  if (G->adj[v][w] == 1) 
    G->E--;
  G->adj[v][w] = 0; 
  G->adj[w][v] = 0;
}

int GRAPHedges(Edge a[], Graph G) {
  int v, w, E = 0;
  for (v = 0; v < G->V; v++)
    for (w = v+1; w < G->V; w++)
      if (G->adj[v][w] == 1) 
	a[E++] = EDGE(v, w); 
  return E;
}

void GRAPHshow(Graph G) {
  int i, j; 
  printf("%d vertices, %d edges\n", G->V, G->E);
  for (i = 0; i < G->V; i++) {
    printf("%2d:", i);
    for (j = 0; j < G->V; j++)
      if (G->adj[i][j] == 1) 
	printf(" %2d", j);
    printf("\n");
  }
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
