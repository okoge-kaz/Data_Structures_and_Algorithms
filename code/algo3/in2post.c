/*
  入力: in2post '(5*((9+8)*(4*6))+7))'
  出力: 5 9 8 + 4 6 * * 7 + *
 */


#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

int main(int argc, char *argv[]) {
  char *a = argv[1];
  int N = strlen(a);

  STACKinit(N);

  // operation
  for(int i=0;i<N;i++){
    if(a[i] == ')'){
      printf("%c ", STACKpop());
    }
    if(a[i] == '*' || a[i] == '+'){
      STACKpush(a[i]);
    }
    // 数字のとき
    if(('0' <= a[i]) && (a[i] <= '9')){
      int number = a[i] - '0';
      printf("%d ", number);
    }

  }
  printf("\n");
}
