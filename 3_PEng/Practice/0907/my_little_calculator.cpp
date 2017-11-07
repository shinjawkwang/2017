#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  int result, num1, num2;
  char opr;
  result = 1;
  while (result != 0) {
    scanf("%d%c%d", &num1, &opr, &num2);
    if(opr == '+') {
      result = num1 + num2;
      printf("%d\n", result);
    }
    else if(opr == '-'){
      result = num1 - num2;
      printf("%d\n", result);
    }
    else if (opr == '*') {
      result = num1 * num2;
      printf("%d\n", result);
    }
    else if (opr == '/') {
      if (num2 == 0) {
        printf("D0\n");
        continue;
      }
      result = num1 / num2;
      printf("%d\n", result);
    }
    else if (opr == '%') {
      if (num2 == 0) {
        printf("D0\n");
        continue;
      }
      result = num1 % num2;
      printf("%d\n", result);
    }
		else printf("OP\n");
  }
  return 0;
}
