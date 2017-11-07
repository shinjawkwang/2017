#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand((unsigned)time(NULL));
  int random_array[5][10], min, pos[2], tmp;
  for(int i=0;i<5;i++){
    for(int j=0;j<10;j++){
      random_array[i][j] = rand() % 10000;
    }
  }
  printf("[Before Sorting]\n");
  for(int i=0;i<5;i++){
    for(int j=0;j<10;j++)
      printf("%5d", random_array[i][j]);
    printf("\n");
  }
  
  printf("\n[After Sorting]\n");
  for(int i=0;i<5;i++){
    for(int j=0;j<10;j++)
      printf("%5d", random_array[i][j]);
    printf("\n");
  }
  return 0;
}
