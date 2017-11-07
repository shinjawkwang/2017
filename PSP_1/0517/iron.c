#include <stdio.h>
#include <string.h>

int stack[100000];
char brackets[100000];
int top=0;

void push(){
  stack[top] = 1;
  top++;
}
void pop(){
    stack[top-1] = NULL;
    top--;
}
void cut(){
    for(int i=0;i<top;i++)
        stack[i]++;
}

int main(){
    int result=0;
    scanf("%s", brackets);
    for(int i=0;i<strlen(brackets);i++){
        if(brackets[i] == '('){
            if(brackets[i+1] != ')')
                push();
            else
                cut();
        }
        else if(brackets[i-1]!='(' && brackets[i] == ')'){
            result += stack[top-1];
            pop();
        }
    }
    printf("%d\n", result);
    return 0;
}
