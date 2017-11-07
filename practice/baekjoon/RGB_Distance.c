#include <stdio.h>

int min(int a, int b){return a>b?b:a;}

int main(){
  int house[4][1010], n, i, j, result;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    for(j=1;j<=3;j++)
      scanf("%d", &house[j][i]);
  }
  for(i=0;i<n;i++){
    for(j=1;j<=3;j++){
      if(i>0){
        if(j==1)
          house[j][i] += min(house[2][i-1], house[3][i-1]);
        if(j==2)
          house[j][i] += min(house[1][i-1], house[3][i-1]);
        if(j==3)
          house[j][i] += min(house[1][i-1], house[2][i-1]);
      }
    }
  }
  result = house[1][n-1];
  for(i=1;i<=3;i++){
    if(result>=house[i][n-1])
      result = house[i][n-1];
  }
  printf("%d", result);
  return 0;
}
