#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "graph.h"

typedef struct node *link;
struct node {int v; link next; };
struct graph { int V; int E; link *adj; };

#define maxV 1000
static int cnt;
static int visited[maxV];

void bfs(Graph G, Edge e) {
  QUEUEinit();
  QUEUEput(e);
  printf("visit %d\n", e.w);
  visited[e.w] = cnt++;
  while(!QUEUEempty()){
    // first visit
    if(visited[(e = QUEUEget()).w] == -1){
      for(link nv=G->adj[e.w];nv!=NULL;nv=nv->next){
        if(visited[nv->v] == -1){
          // first visit
          QUEUEput(EDGE(e.w, nv->v));
          printf("visit %d\n", nv->v);
          visited[nv->v] = cnt++;
        }
      }
    }
  }
}


void GRAPHsearch(Graph G) {
  cnt = 0;

  QUEUEinit();

  for (int v=0; v < G->V; v++) 
    visited[v] = -1;

  for (int v=0; v < G->V; v++) 
    if (visited[v] == -1) 
      bfs(G, EDGE(v, v));
}


int main(int argc, char *argv[]){
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
