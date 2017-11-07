#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10010];
int tmp[10010];

void merge(int first, int mid, int last){
  int a, b, p;
  a=p=first;
  b=mid+1;
  while(a<=b && b<=last){
    if(arr[a] > arr[b]){
      tmp[p] = arr[b];
      b++;
    }
    else if(a<=mid){
      tmp[p] = arr[a];
      a++;
    }
    p++;
  }
  if(a<=mid){
    for(;a<=mid;a++){
      tmp[p] = arr[a];
      p++;
    }
  }
  if(b<=last){
    for(;b<=last;b++){
      tmp[p] = arr[b];
      p++;
    }
  }
  for(int i=first;i<=last;i++)
    arr[i] = tmp[i];
}
void msort(int first, int last){
  int mid;
  if(first<last){
    mid = (first+last) / 2;
    msort(first, mid);
    msort(mid+1, last);
    merge(first, mid, last);
  }
}

int partition(int left, int right){
  int l, r, pivot, tmp;
  pivot = arr[left];
  l = left+1, r = right;
  while(l<=r){
    while(arr[l]<=pivot){
      l++;
    }
    while (arr[r]>pivot) {
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
  int n,i,j;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &arr[i]);
  }
  qsort(0, n-1);
  for(i=0;i<n;i++)  printf("%d ", arr[i]);
  printf("\n");
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &arr[i]);
  }
  msort(0, n-1);
  for(i=0;i<n;i++)  printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
