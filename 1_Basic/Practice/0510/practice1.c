#include <stdio.h>

int main(){
  char c = 'a';
  int i = 10;
  double f = 10.1;
  char *pc = &c;
  int *pi = &i;
  double *pf = &f;
  printf("\nAddress of variable c : %p\nAddress of variable i : %p\nAddress of variable f : %p\n", pc, pi, pf);
  printf("\nValue of variable c : %c\nValue of variable i : %d\nValue of variable f : %lf\n", *pc, *pi, *pf);
  printf("\nSize of pointer variable pc : %d\nSize of pointer variable pi : %d\nSize of pointer variable pf : %d\n", sizeof(pc), sizeof(pi), sizeof(pf));
  printf("\nSize of variable c : %d\nSize of variable i : %d\nSize of variable f : %d\n", sizeof(*pc), sizeof(*pi), sizeof(*pf));
  return 0;
}
