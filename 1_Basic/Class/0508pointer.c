#include <stdio.h>

int main(){
  int a = 100;
  int* b = &a;
  printf("%d %p \n", a, b);
  return 0;
}
