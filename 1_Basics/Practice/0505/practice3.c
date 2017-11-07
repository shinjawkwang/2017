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
  for(int i=0;i<5;i++){
    for(int j=0;j<10;j++){
      min = random_array[i][j];
      pos[0] = i;
      pos[1] = j;
      for(int k=i;k<5;k++){
        for(int l=j;l<10;l++){
          if(min>random_array[k][l]){
            min = random_array[k][l];
            pos[0] = k;
            pos[1] = l;
          }
        }
        tmp = random_array[i][j];
        random_array[i][j] = min;
        random_array[pos[0]][pos[1]] = tmp;
      }
    }
  }
  printf("\n[After Sorting]\n");
  for(int i=0;i<5;i++){
    for(int j=0;j<10;j++)
      printf("%5d", random_array[i][j]);
    printf("\n");
  }
  return 0;
}
