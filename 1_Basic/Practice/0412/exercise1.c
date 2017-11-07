#include <stdio.h>

int i;
void count(){
  printf("Count function is called %d times \n", i+1);
}

int main(){
  for(i=0;i<10;i++){
    count();
  }
  return 0;
}
