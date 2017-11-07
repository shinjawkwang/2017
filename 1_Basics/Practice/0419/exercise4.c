#include <stdio.h>
#include <string.h>

int main(){
  char alpha[100];
  int index, result[123], i;
  printf("input : ");
  scanf("%s", alpha);
  for(i=0;i<123;i++)
    result[i] = 0;
  for(i=0;i<strlen(alpha);i++){
    index = alpha[i];
    result[index]++;
  }
  printf("\n<RESULT>\n");
  for(i=1;i<123;i++){
    if(result[i]%2 == 1)
      printf("%c ", i);
  }
  printf("\n");
  return 0;
}
