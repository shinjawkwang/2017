#include <stdio.h>

int main(){
  int arr[10], N, i, input;
  printf("Input N: ");
  scanf("%d", &N);
  printf("Input %d numbers: ", N);
  for(i=0;i<N;i++)
    scanf("%d", &arr[i]);
  while(1){
    printf("Input a number to find : ");
    scanf("%d", &input);
    if(input==-1)
      break;
    for(i=0;i<N;i++){
      if(input==arr[i]){
        printf("Found! \n\n");
        break;
      }
      else if(i==N-1)
        printf("Not Found \n\n");
    }
  }
}
