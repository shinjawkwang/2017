#include <stdio.h>

int main(){
  int i, j;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      if(j%8==0 || i%8==0)
        printf("5");
       else if(i*j%7==0 || i*j==i || i==1 || i%7==0)
        printf("4");
      else if()
        printf(" ");
    }
  printf("\n");
  }
  return 0;
}
