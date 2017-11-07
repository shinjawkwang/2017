#include <stdio.h>

int stack[100], top=0;
/*
1 - push
2 - pop
3 - print
4 - exit
*/
void push(n){
  stack[top] = n;
  top++;
}
void pop(){
  printf("%d\n", stack[top-1]);
  stack[top-1] = NULL;
  top--;
}

int main(){
  int order, input;
  while(1){
    scanf("%d", &order);
    if(order==1){
      scanf("%d", &input);
      push(input);
    }
    else if(order==2)
      pop();
    else if(order==3){
      printf("stack : ");
      for(int i=0;i<top;i++)
        printf("%d ", stack[i]);
      printf("<- top\n");
    }
    else if(order==4)  break;
    else printf("Input Error\n");
  }

}
