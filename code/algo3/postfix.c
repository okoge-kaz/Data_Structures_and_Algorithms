/*
  後置記法の算術式を計算して結果を返す
  入力: ./postfix '5 9 8 + 4 6 * * 7 + *'
  出力: 2075
 */


#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

int main(int argc, char *argv[]) {
  char *a = argv[1]; // 引数の算術式を格納する配列
  int N = strlen(a); // 配列の大きさ

  // stackの初期化
  STACKinit(N);

  //  文字列の先頭から最後まで繰り返す
  for (int i=0; i<N; i++) {
    // 文字が'+'だったら、stackの1番上と2番目の値をstackからpopして、加算してstackにpush
    if (a[i] == '+') {
      int number1 = STACKpop();
      int number2 = STACKpop();
      int number = number1 + number2;
      STACKpush(number);
    }

    // 文字が'*'だったら、stackの1番上と2番目の値をstackからpopして、乗算してstackにpush
    if (a[i] == '*') {
      int number1 = STACKpop();
      int number2 = STACKpop();
      int number = number1 * number2;
      STACKpush(number);
    }

    // 以下は、文字が'0'-'9'の数字の場合の処理
    if ((a[i] >= '0') && (a[i] <= '9')) {
      // とりあえず0をstackにpushする
      STACKpush(0);
    }
    // stackの１番めを10倍したものとa[i]の値を加算しstackにpush。iをインクリメント
    while ((a[i] >= '0') && (a[i] <= '9')) {
      int top_number = STACKpop();
      top_number *= 10;
      top_number += (a[i] - '0');
      STACKpush(top_number);
      i++;
    }
  }

  // 最終的にstackの値をpopして出力  
  printf("%d \n", STACKpop());
}
