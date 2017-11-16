#include <stdio.h>
#include <vector>
using namespace std;

int heap[100100];
int heap_size;
void swap(int *i, int *j){
  int temp = *i;
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

int main(int argc, char *argv[]){
  int n, item;
  heap_size = 0;
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    scanf("%d", &item);
    heap_size ++;
    insert(item);
  }
  /*
  for(int i=1;i<=n;i++){
    printf("%d ", heap[i]);
  }
  printf("\n");
  */
  for(int i=n;i>0;i--){
    swap(&heap[1], &heap[heap_size]);
    heap_size --;
    heapSort();
  }
  for(int i=1;i<=n;i++){
    printf("%d\n", heap[i]);
  }

  return 0;
}
