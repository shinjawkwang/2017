#include <stdio.h>

int stack[100010];

void push(int a){
  printf("+\n");
  stack[a] = a;
}
void pop(int a){
  printf("-\n");
  stack[a] = 0;
}
int max(int a, int b){return a>b?a:b;}

int main(){
  int num, i, j, input, store[100010], max = 0, stack_num = 1;
  scanf("%d", &num);
  for(i=0;i<num;i++){
    scanf("%d", &input);
    store[i] = input;
    if(max<=store[i])
      max = store[i];
    for(j=0; ;j++){
      if(input > stack_num){
        push(input);
        if(input != stack_num)
          input--;
        if(input == stack_num)
          push(input);
      }
      else if(input < stack_num){
        pop(input);
        if(input != stack_num)
          input++;
      }
      if(input == stack_num){
        pop(input);
        input--;
        break;
      }
    }
    stack_num = max-1;
  }
  return 0;
}
