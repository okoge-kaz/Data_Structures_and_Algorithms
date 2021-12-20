// heapのテストプログラム
// 引数の数のノードを持つheapを生成，heapからの最小要素の削除，heapへのa[]要素の挿入を繰り返す．
// 使用法: ./a.out 20

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "heap.h"

int main(int argc, char *argv[]) 
{
  int i, num;
  int a[] = {55, 41, 17, 89, 20, 62};

  srand(time(NULL));
  if (argc < 2)
    printf("You have not entered enough arguments: N required!\n ");
  else {
      N = atoi(argv[1]);
      PQinit(N);
      printf("Insert: ");
      for (i = 0; i < N; i++) {
	      num = (rand() % 101);
    	  printf("%d ", num);
    	  PQinsert(num);
    	}
      printf("\n");
      for (i = 0; i < (sizeof(a)/sizeof(a[0])); i++)	{
    	  printf("Deletemin: %d ", PQdelmin());
    	  printf("Insert: %d\n", a[i]);
    	  PQinsert(a[i]);
    	} 
    }
    printf("Deletemin: %d\n", PQdelmin());

  return 0;
}