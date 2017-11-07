#include <stdio.h>

int power(int base, int exponent){
  if(exponent==0)
    return 1;
  else
    return base*power(base,exponent-1);
}
int main(){
  int base, exponent;
  printf("Input base and exponent:");
  scanf("%d%d", &base, &exponent);
  printf("%d\n", power(base,exponent));
  return 0;
}
