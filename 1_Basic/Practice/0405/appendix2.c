#include <stdio.h>

int main(){
  int i, j, num;
  printf("number : ");
  scanf("%d", &num);
  for(i=0;i<num;i++){
    for(j=i;j<i+num;j++)
      printf("%d", j+1);
    printf("\n");
  }
  return 0;
}
