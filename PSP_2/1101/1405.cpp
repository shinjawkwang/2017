#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

double ans, e, w, s, n;
int check[50][50];
int num;
void DFS(int cnt, int x, int y, double p){
  if(cnt == num){ans += p; return;}
  check[x][y] = 1;

  if(!check[x+1][y]) DFS(cnt+1, x+1, y, p*e);
  if(!check[x-1][y]) DFS(cnt+1, x-1, y, p*w);
  if(!check[x][y-1]) DFS(cnt+1, x, y-1, p*s);
  if(!check[x][y+1]) DFS(cnt+1, x, y+1, p*n);

  check[x][y] = 0;
}

int main(){
  scanf("%d%lf%lf%lf%lf", &num, &e, &w, &s, &n);
  e /= 100; w /= 100; s /= 100; n /= 100;
  DFS(0, 20, 20, 1.0);
  printf("%.9f", ans);
  return 0;
}
