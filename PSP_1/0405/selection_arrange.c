#include <stdio.h>

int main(){
  int n, i, arr[1005], j, min, pos, tmp;
  scanf("%d", &n);
  for(i=0;i<n;i++)
    scanf("%d", &arr[i]);
  for(i=0;i<n;i++){
    min = arr[i];
    pos = i;
    for(j=i;j<n;j++){
      if(min>arr[j]){
        min = arr[j];
        pos = j;
      }
    }
    tmp = arr[i];
    arr[i] = min;
    arr[pos] = tmp;
  }
  for(i=0;i<n;i++)
    printf("%d ", arr[i]);
  return 0;
}
