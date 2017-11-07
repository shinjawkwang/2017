#include <stdio.h>

void swap(int *a, int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(){
  int num1, num2;
  scanf("%d%d", &num1, &num2);
  printf("[Before Swap]\nnum1 : %d\tnum2 : %d\n", num1, num2);
  swap(&num1, &num2);
  printf("\n[After Swap]\nnum1 : %d\tnum2 : %d", num1, num2);
  return 0;
}
