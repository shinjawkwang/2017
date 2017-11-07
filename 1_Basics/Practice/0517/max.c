#include <stdio.h>

int* getMaxIndex(int *arr, int size){
  int max = arr[0], pos;
  for(int i=0;i<size;i++){
    if(max<arr[i]){
      max = arr[i];
      pos = i;
    }
  }
  return arr+pos;
}

int main(){
  int arr[10] = {11, 34, 82, 7, 64, 98, 47, 18, 29, 20};
  printf("%d\n", *getMaxIndex(arr, 10));
  return 0;
}
