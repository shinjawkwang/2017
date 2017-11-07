#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 100

typedef struct __Stack{
  char items[MAX_STACK];
  int top;
}Stack;

typedef enum {false, true} bool;

bool IsFull(Stack *pstack){return pstack -> top == MAX_STACK - 1;}//check if stack is full
bool IsEmpty(Stack *pstack){return pstack -> top == -1;}//check if stack is empty

void InitStack (Stack *pstack){pstack -> top = -1;}//Start stack
void Push(Stack *pstack, char item){//if stack is full, end program. Or, push item to stack
	if (IsFull(pstack))  exit(1);
  pstack->items[++(pstack->top)] = item;
}
void Pop(Stack *pstack){//if stack is empty, end program. Or, pop item from stack
	if(IsEmpty(pstack))	exit(1);
	--(pstack -> top);
}
char Peek(Stack *pstack){//Peek an item from top of the stack if stack isn't empty
	if(IsEmpty(pstack))	exit(1);
	return pstack->items[pstack->top];
}

int main(){
  Stack stack;
  char input[MAX_STACK], result[MAX_STACK];
  int i, differ;
  InitStack(&stack);
  scanf("%s", input);

  for(i=0;i<strlen(input);i++)  Push(&stack, input[i]);//push all characters into stack
  for(i=0;i<strlen(input);i++){//peek and pop all elements to result array
    result[i] = Peek(&stack);
    Pop(&stack);
  }
  for(i=differ=0;i<strlen(input);i++){//find different characters
    if(input[i] != result[i]) differ ++;
  }
  printf("%s\n%d", result, differ);
}
