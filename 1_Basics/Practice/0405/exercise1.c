#include <stdio.h>

int main(){
  int sum = 0, i;
  for(i=1;i<=50;i++)
    sum+=2*i-1;
  printf("%d \n", sum);
  return 0;
}
