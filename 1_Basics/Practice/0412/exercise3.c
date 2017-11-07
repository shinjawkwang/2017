#include <stdio.h>

int gcd(int num1, int num2){
  if(num2==0)
    return num1;
  return gcd(num2,num1%num2);
}

int main(){
  int num1, num2, result;
  printf("input 2 positive integers : ");
  scanf("%d%d", &num1, &num2);
  if(num1>num2)
    result = gcd(num1,num2);
  else
    result = gcd(num2,num1);
  printf("GCD of %d and %d is %d \n", num1, num2, result);
  return 0;
}
