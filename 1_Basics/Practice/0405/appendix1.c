#include <stdio.h>

int main(){
  int i, j, num;
  printf("number : ");
  scanf("%d", &num);
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      if(i==j || i+j==num-1)
        printf("1");
      else
        printf("0");
    }
    printf("\n");
  }
  return 0;
}
