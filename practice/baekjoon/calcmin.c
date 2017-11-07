#include <stdio.h>

int min(int a, int b){return a>b?b:a;}

int main(){
  int D[1000005];
  int n, i;
  D[1] = 0;
  D[2] = 1;
  D[3] = 1;
  scanf("%d", &n);
  for(i=3;i<=n;i++){
    if(i%2==0 && i%3==0)
      D[i] = min(D[i/3]+1,D[i/2]+1);
    else if(i%2==0)
      D[i] = min(D[i-1]+1,D[i/2]+1);
    else if(i%3==0)
      D[i] = min(D[i-1]+1,D[i/3]+1);
    else
      D[i] = D[i-1]+1;
  }
  printf("%d", D[n]);
  return 0;
}
