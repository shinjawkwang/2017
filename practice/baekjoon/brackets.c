#include <stdio.h>
#include <string.h>

int main(){
  int test, i, j, seq;
  char stack[55];
  scanf("%d", &test);
  for(i=0;i<test;i++){
      scanf("%s", stack);
      seq = 0;
      for(j=0;j<strlen(stack) && seq>=0;j++){
        if(stack[j] == '(')
          seq++;
        else if(stack[j] == ')')
          seq--;
      }
      if(seq<0 || seq>0)
        printf("NO\n");
      else
        printf("YES\n");
  }
  return 0;
}
