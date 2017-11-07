#include <stdio.h>

int main(){
  int n, i, j, arr[1005], tmp;
  scanf("%d", &n);
  for(i=0;i<n;i++)
    scanf("%d", &arr[i]);
  for(i=0;i<n;i++){
    for(j=i;j>0;j--){
      if(arr[j]<arr[j-1]){
        tmp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = tmp;
      }
    }
  }
  for(i=0;i<n;i++)
    printf("%d ", arr[i]);
  return 0;
}
