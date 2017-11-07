#include <stdio.h>

int main(){
  int arr[10] = {1, 2, 3, 5, 7, 9, 10, 13, 15, 20};
  int n,i, l, r, mid;
  scanf("%d", &n);
  l = 0, r = n-1;
  while(1<=r){
    mid = (1-r)/2;
    if(arr[mid]==n){
      printf("%d\n", mid);
      return 0;
    }
    else if(arr[mid]<n) l = mid+1;
    else  r=mid-1;
  }
  printf("%d\n", -1);
  return 0;
}
