#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

typedef struct Tree {
  ll a;
  ll b;
  ll w;
}tr;

ll tree[100100];
vector <tr> list;

ll compare(tr a, tr b){return a.w<b.w;}
ll find(ll p){
  if(tree[p]==-1) return p;
  tree[p] = find(tree[p]);
  return tree[p];
}
ll uni(ll a, ll b){
  a = find(a);
  b = find(b);
  if(a==b)  return 0;
  tree[b] = a;
  return 1;
}


int main(){
  tr tmp;
  ll v,e,a,b,w,i,cnt,x,sum;
  scanf("%lld%lld", &v, &e);
  for(i=0;i<e;i++){
    scanf("%lld%lld%lld", &a, &b, &w);
    tmp.a = a;
    tmp.b = b;
    tmp.w = w;
    list.push_back(tmp);
  }
  sort(list.begin(), list.end(), compare);
  for(i=1;i<=v;i++) tree[i] = -1;
  for(i=cnt=sum=0;i<e && cnt<v-2;i++){
    tmp = list[i];
    a=tmp.a, b=tmp.b;
    x = uni(a,b);
    if(x){
      sum += tmp.w;
      cnt ++;
    }
  }
  printf("%lld\n", sum);
  return 0;
}
