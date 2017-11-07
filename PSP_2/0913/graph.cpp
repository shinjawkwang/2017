#include <stdio.h>
#include <vector>
using namespace std;

vector <int> list[32323]; //1번째 방법
vector <int> stack;
int visit[32323];
//vector <vector <int> > list2; ->2번째 방법

void DFS(int curr){
  int i;
  visit[curr] = 1;
  for(i=0;i<list[curr].size();i++){
    if(visit[list[curr][i]] == 0){
      DFS(list[curr][i]);
    }
  }
  stack.push_back(curr);
}
/*
void printlist(int v){
  int i;
  for(i=1;i<=v;i++){
    printf("%d: ", i);
    for(int j=0;j<list[i].size();j++){
      printf("%d ", list[i][j]);
    }
    printf("\n");
  }
}
*/
int main(){
  int v, e, i, a, b;
  scanf("%d%d", &v, &e);
  for(i=0;i<e;i++){
    scanf("%d%d", &a, &b);
    list[a].push_back(b);
    //list[b].push_back(a);
  }

  for(i=1;i<=v;i++){
    if(visit[i] == 0){
      DFS(i);
    }
  }

  for(i=stack.size()-1;i>=0;i--){
    printf("%d ", stack[i]);
  }

  return 0;
}
