#include <stdio.h>

int main(){
  int n, num, i, ze[50], one[50];
  ze[2] = one[1] = 0;
  ze[1] = one[2] = 1;
  for(i=3;i<50;i++){
    ze[i] = ze[i-1] + ze[i-2];
    one[i] = one[i-1] + one[i-2];
  }
  scanf("%d", &num);
  for(i=0;i<num;i++){
    scanf("%d", &n);
    printf("%d %d \n", ze[n+1], one[n+1]);
  }
  return 0;
}
/*
int zero(int n){
  if(n==0)  return 1;
  if(n==1)  return 0;
  return zero(n-1)+zero(n-2);
}

int one(int n){
  if(n==0)  return 0;
  if(n==1)  return 1;
  return one(n-1)+one(n-2);
}

int main(){
  int n, ze, on;
  scanf("%d", &n);
  printf("%d", zero(n)+one(n));
}
재귀버전  */
