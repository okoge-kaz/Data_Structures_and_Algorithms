#include <stdio.h>

#define DISKNUM 10

void hanoi(int n, char* a, char* b, char* c) {
  if (n > 0) {
    hanoi(n-1, a, c, b);
    printf("Move disk %d from %s to %s \n", n, a, b);
    hanoi(n-1, c, b, a);    
  }
}

int main() {
  int n = DISKNUM;
  hanoi(n, "A", "B", "C");
  return 0;
}