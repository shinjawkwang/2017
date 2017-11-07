#include <stdio.h>

int main(){
  int i, j, num;
  printf("number : ");
  scanf("%d", &num);
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      if(i+j>=num-1)
        printf("%d", num);
      else
        printf("%d", j+i+1);
    }
  printf("\n");
  }
  return 0;
}
