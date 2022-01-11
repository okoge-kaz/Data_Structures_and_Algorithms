/*
test program for GRAPH
usage: ./test num_of_v num_of_e

example: ./test 10 10
  then input a pair of vertices such as
  input vertex to remove: 6 7
*/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char *argv[]) {
  int a, b;

  int V = atoi(argv[1]), E = atoi(argv[2]);

  Graph G = GRAPHrand(V, E);
  if (V < 20) 
    GRAPHshow(G);
  else
    printf("%d vertices, %d edges, ", V, E);
  
  printf("input vertex to remove:");
  scanf("%d %d", &a, &b);
  GRAPHremoveE(G, EDGE(a, b));
  GRAPHshow(G);

  return 0;
}
