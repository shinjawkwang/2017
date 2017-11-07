#include <iostream>
using namespace std;

int calcFacto(int n){
  int i, result = 1;
  for(i=n;i>0;i--)  result *= i;
  return result;
}

int main(){
  int n, k, over, under1, under2, sub;
  cout << "Enter the [n] and the [k] combination values: " << endl;
  cin >> n >> k;
	sub = n-k;
  over = calcFacto(n);
  under1 = calcFacto(sub);
  under2 = calcFacto(k);
  cout << over / (under1 * under2);
  return 0;
}
