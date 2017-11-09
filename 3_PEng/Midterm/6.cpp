#include <iostream>
using namespace std;

int computeCombination(int n, int k){
  if(n==k)
    return 1;
  if(k==0)
    return 1;
  return computeCombination(n-1, k-1) + computeCombination(n-1, k);
}

int main(){
  int n,m;

  cin>>n;
  cin>>m;
  cout<<computeCombination(n,m)<<endl;

  return 0;
}
