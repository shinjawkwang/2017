#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
  int random_num;
  srand((unsigned)time(NULL));
  random_num = rand() % 100;
  while(1){
    int input;
    printf("Input a integer in 1~100` : ");
    scanf("%d", &input);
    if(input > random_num)
      printf("That's too large!!\n");
    if(input < random_num)
      printf("That's too small!!\n");
    if(input == random_num){
      printf("Correct! the random number is %d. \n", random_num);
      break;
    }
  }
}
