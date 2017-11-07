#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, cnt = 0;
int col[55];

int isValid(int num){
  int i, flag = 1;
  for(i=1; i<num; i++){
    if(col[i]==col[num] || abs(col[i]-col[num]) == abs(i-num)){
      flag = 0;
      break;
    }
  }
  return flag;
}

void nqueen(int num){
  if(isValid(num)){
    if(num == n){cnt ++; return;}
    for(int i=1;i<=n;i++){
      col[num+1] = i;
      nqueen(num+1);
    }
  }
}

int main() {
  scanf("%d", &n);
  nqueen(0);
  printf("%d\n", cnt);
  return 0;
}
