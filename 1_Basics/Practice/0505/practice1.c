#include <stdio.h>

int main(){
  int arr[10] = {432, 654, 123, 54, 654, 765, 995, 394, 76, 832};
  int i, j, pos, min, tmp;
  printf("Before sorting : \n");
  for(i=0;i<10;i++)
    printf("%4d", arr[i]);
  printf("\n\n");
  for(i=0;i<10;i++){
    min = arr[i];
    pos = i;
    for(j=i;j<10;j++){
      if(min>arr[j]){
        min = arr[j];
        pos = j;
      }
    }
      tmp = arr[i];
      arr[i] = min;
      arr[pos] = tmp;
    }
  printf("After sorting : \n");
  for(i=0;i<10;i++)
    printf("%4d", arr[i]);
  return 0;
}
