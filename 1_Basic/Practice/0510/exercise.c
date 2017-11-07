#include <stdio.h>

void mini_max(int *a, int *b){
  int mini, maxi, arr[10000], count = 0;
  for(int i=0; ;i++){
    scanf("%d", &arr[i]);
    if(arr[i] == -1)
      break;
    count++;
  }
  mini = maxi = arr[0];
  for(int i=0;i<count;i++){
    if(mini > arr[i])
      mini = arr[i];
    if(maxi < arr[i])
      maxi = arr[i];
  }
  *a = mini;
  *b = maxi;
}

int main(){
  int min, max;
  mini_max(&min, &max);
  printf("min : %d, max = %d\n", min, max);
  return 0;
}
