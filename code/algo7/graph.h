#ifndef _GRAPH_H
#define _GRAPH_H

typedef struct { int v; int w; } Edge;
Edge EDGE(int, int);

typedef struct graph *Graph;
Graph GRAPHinit(int);
void GRAPHinsertE(Graph, Edge);
void GRAPHremoveE(Graph, Edge);
int GRAPHedges(Edge[], Graph G);
void GRAPHshow(Graph);
Graph GRAPHrand(int, int);

#endif
