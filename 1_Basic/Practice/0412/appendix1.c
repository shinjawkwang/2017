#include <stdio.h>

int nCr(int n, int r){
  if(r==1)
    return n;
  if(n==1)
    return 0;
  return nCr(n-1,r)+nCr(n-1,r-1);
}

int main(){
  int n, r;
  printf("input 2 numbers : ");
  scanf("%d%d", &n, &r);
  printf("%dC%d is %d", n, r, nCr(n,r));
  return 0;
}
