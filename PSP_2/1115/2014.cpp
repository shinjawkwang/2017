#include <stdio.h>
#include <vector>
#define MAX 2147483647
#define ll long long
using namespace std;

ll heap[100100];
ll n, k, s, p[100100];
ll heap_size;
ll cnt=0;
void swap(ll *i, ll *j){
  ll temp = *i;
  *i = *j;
  *j = temp;
}

void insert(int item){
  int size = heap_size;
  heap[size] = item;
  while(size > 1){
    if(heap[size] > heap[size/2]){
      swap(&heap[size], &heap[size/2]);
      size /= 2;
    }
    else  break;
  }
}
void heapSort(){
  int i=1;
  while(i <= heap_size / 2){
    if(heap[2*i]<heap[2*i+1] && 2*i+1 <= heap_size){
      if(heap[i] < heap[2*i+1]){
        swap(&heap[i], &heap[i*2+1]);
        i *= 2;
        i++;
      }
      else break;
    }
    else{
      if(heap[i] < heap[2*i]){
        swap(&heap[i], &heap[2*i]);
        i *= 2;
      }
      else  break;
    }
  }
}
void back(ll cur, ll s){
  ll i;
  if(cur>MAX) return;
  if(cnt>n+1) return;
  if(heap[1]<cur && cnt==n+1) return;
  if(cnt==n+1){
    heap[1] = cur;
    heapSort();
  }
  else{
    insert(cur);
    cnt ++;
  }
  for(i=s;i<=k;i++){
    back(cur*p[i], i);
  }
}

int main(int argc, char *argv[]){
  heap_size = 0;
  scanf("%lld%lld", &k, &n);
  for(int i=1;i<=k;i++){
    scanf("%lld", &p[i]);
  }
  back(1,1);
  printf("%lld", heap[1]);
  return 0;
}
