#include <stdio.h>
#include "STACK.h"

int main() {
  STACKinit(5);
  STACKprint();

  for (int i=0; i<5; i++) {
    STACKpush(i);
    STACKprint();
  }

  for (int i=0; i<5; i++) {
    STACKpop();
    STACKprint();
  }
}
