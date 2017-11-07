#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

char a[55], b[55];

int checker(int pos){
  int diff=0;
  for(int i=pos;i<pos+strlen(a);i++){
    if(a[i-pos] != b[i])  diff ++;
  }
  return diff;
}
int main() {
  int result;
  scanf("%s%s", a, b);
  result = checker(0);
  for(int i=0;i<=strlen(b)-strlen(a);i++){
    if(result > checker(i))
      result = checker(i);
    printf("%d\n", result);
  }
  printf("%d\n", result);
  return 0;
}
