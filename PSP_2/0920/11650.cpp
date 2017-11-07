#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct __matrix{
  int x;
  int y;
}matrix;

matrix arr[100100];
matrix tmp[100100];

int compare(matrix a, matrix b){
  if(a.x==b.x)  return a.y > b.y;
  return a.x > b.x;
}

int partition(int left, int right){
  int l, r;
  matrix pivot;
  matrix tmp;
  pivot = arr[left];
  l = left+1, r = right;
  while(l<=r){
    while(compare(pivot, arr[l])){
      l++;
    }
    while (compare(arr[r], pivot)) {
      r--;
    }
    if(l<r){
      tmp = arr[l];
      arr[l] = arr[r];
      arr[r] = tmp;
    }
  }
  tmp = arr[r];
  arr[r] = arr[left];
  arr[left] = tmp;
  return r;
}

void qsort(int left, int right){
  if(left<right){
    int p = partition(left, right);
    qsort(left, p-1);
    qsort(p+1, right);
  }
}


int main() {
  int n,i;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d%d", &arr[i].x, &arr[i].y);
  }
  qsort(0, n-1);
  for(i=0;i<n;i++)  printf("%d %d\n", arr[i].x, arr[i].y);
  return 0;
}
