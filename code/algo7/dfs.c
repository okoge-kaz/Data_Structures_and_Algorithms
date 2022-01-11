#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct graph { int V; int E; int **adj; };

#define maxV 1000
static int cnt;
static int visited[maxV];

void dfsR(Graph G, Edge e) {
  int w=e.w;
  visited[w] = cnt++;
  printf("visit %d\n", w);
  for (int t = 0; t < G->V; t++) 
    if (G->adj[w][t] != 0) 
      if (visited[t] == -1) {
        dfsR(G, EDGE(w, t));
      }
}

void GRAPHsearch(Graph G) {
  cnt = 0;

  for (int v=0; v < G->V; v++) 
    visited[v] = -1;

  for (int v=0; v < G->V; v++) 
    if (visited[v] == -1) 
      dfsR(G, EDGE(v, v));
}

int main(int agrc, char *argv[]) {
  Graph G = GRAPHinit(5);
  GRAPHinsertE(G, EDGE(0, 1));
  GRAPHinsertE(G, EDGE(0, 2));
  GRAPHinsertE(G, EDGE(0, 3));
  GRAPHinsertE(G, EDGE(1, 2));
  GRAPHinsertE(G, EDGE(2, 3));
  GRAPHinsertE(G, EDGE(3, 4));
  GRAPHshow(G);

  GRAPHsearch(G);
  
  return 0;
}
