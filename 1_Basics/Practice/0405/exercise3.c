#include <stdio.h>

int find_prime_number(int a, int b){
  int i, j, key, prime_nums;
  for(i=a;i<=b;i++){
    for(j=2;j<i;j++){
      if(i%j == 0)
        key++;
    }
    if(key == 0)
      prime_nums++;
    key = 0;
  }
  if(a==1)
    prime_nums --;
  return prime_nums;
}

int main(){
  int a, b, result;
  while(1){
  scanf("%d%d", &a, &b);
  if(a == -1 || b == -1)
    return 0;
  result = find_prime_number(a,b);
  printf("%d\n", result);
  }
  return 0;
}
