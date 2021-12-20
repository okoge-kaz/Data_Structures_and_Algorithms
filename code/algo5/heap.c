#include <stdio.h> 
#include <stdlib.h>
#include "Item.h"
#include "heap.h"

void fixUp(Item a[], int k) {
  while (k > 0) {
    // 課題：以下のAとして正しいkの式を入れなさい．ex. k-1
    if (less(a[k], a[(k-1)/2])) { // 自分と親の値を比べて必要なら交換する
      exch(a[k], a[(k-1)/2]); 
    }
    k = (k-1)/2; // 親ノードに移動する
  }
}

void fixDown(Item a[], int k, int N) {
  int j;
  // 課題：以下のBとして正しいkの式を入れなさい．ex. k-1
  while (2*k+1 <= N) { // インデックスkの左の子を調べる
    j = 2*k+1;
    if (a[j] > a[j+1]) // 左の子が小さければ左に移動
      j++;
    if (j > N)
      break;
    if (a[j] >= a[k])
      break;
    exch(a[k], a[j]); // 子ノードの値と交換
    k = j;
  }
}

void PQinit(int maxN) {
  pq = malloc((maxN+1)*sizeof(Item));
  N = 0;
}

int PQempty(void) {
  return N == 0;
}

void PQinsert(Item v) {
  pq[N] = v;
  N = N+1;
  fixUp(pq, N-1);
}

Item PQdelmin() {
  Item v = pq[0];
  pq[0] = pq[N-1];
  N = N-1;
  fixDown(pq, 0, N-1);
  return v;
}