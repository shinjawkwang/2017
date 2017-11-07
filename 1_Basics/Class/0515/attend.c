#include <stdio.h>
#define N 10

void max_min(int a[], int n, int *max, int *min){
  *max = *min = a[0];
  for(int i=0;i<n;i++){
    if(a[i]>*max)
      *max = a[i];
    if(a[i]<*min)
      *min = a[i];
  }
}
int main(){
  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, sum = 0, *p;
  for(p=a;p<&a[N];p++){
    sum += *p;
  }
  printf("%d", sum);
}
