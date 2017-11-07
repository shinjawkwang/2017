#include <stdio.h>

int max(int a, int b){return a>=b?a:b;}

int main(){
  int arr[505][505], n, i, j, result = 0;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    for(j=0;j<=i;j++)
      scanf("%d", &arr[j][i]);
  }
  for(i=0;i<n;i++){
    for(j=0;j<=i;j++){
      if(j==0 && i!=0)
        arr[j][i] += arr[j][i-1];
      else if(i==j){
        if(i!=0)
          arr[j][i] += arr[j-1][i-1];
      }
      else
        arr[j][i] += max(arr[j][i-1], arr[j-1][i-1]);
    }
  }
  for(i=0;i<n;i++){
    if(result<=arr[i][n-1])
      result = arr[i][n-1];
  }
  printf("%d", result);
  return 0;
}
