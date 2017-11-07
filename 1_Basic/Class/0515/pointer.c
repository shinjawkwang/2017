#include <stdio.h>

void main(){
  int i, *p;
  p = &i;
  printf("%p", p);
}
