#include <stdio.h>

int main(){
  int type, height, i, j;
  printf("종류를 입력하세요 <1 or 2> \n");
  scanf("%d", &type);
  printf("트리의 높이를 입력하세요 (odd number) \n");
  scanf("%d", &height);
  if(type == 1){
    for(i=height;i>0;i--){
      for(j=0;j<i;j++)
        printf("*");
      printf("\n");
  }
  }
  else if(type == 2){
    for(i=1;i<=height/2+1;i++){
      for(j=0;j<i;j++)
        printf("*");
      printf("\n");
    }
    for(i=height/2;i>0;i--){
      for(j=0;j<i;j++)
        printf("*");
      printf("\n");
    }
  }
  else
    printf("Input Error");
  return 0;
}
