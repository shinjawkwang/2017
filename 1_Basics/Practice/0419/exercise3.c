#include <stdio.h>

int main(){
  int arr[11], i, result[11], sum;
  for(i=0;i<11;i++){
    arr[i] = 0;
    result[i] = 0;
  }
  i = sum = 0;
  while(1){
    printf("input number (1~10) : ");
    scanf("%d", &i);
    if(i==-1)
      break;
    arr[i]++;
  }
  for(i=1;i<11;i++){
    if(arr[i]%2==1)
      result[i] = i;
    sum+=result[i];
  }
  printf("<RESULT>\n");
  for(i=0;i<11;i++){
    if(result[i] != 0)
      printf("%d ", result[i]);
  }
  printf("\nsum : %d", sum);
  return 0;
}
