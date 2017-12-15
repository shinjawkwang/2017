#include <iostream>

using namespace std;

void hanoi(int n, int a, int b){
  if(n == 1){
    cout << a << "->" << b << "\n";
  }
  else{
    int c = 6-a-b;
    hanoi(n-1, a, c);
    cout << a << "->" << b << "\n";
    hanoi(n-1, c, b);
  }
}

int main() {
  int n, input;
  cin >> n;

  for(int i=0;i<n;i++){
    cin >> input;
    cout << "Case #" << i+1 << "\n";
    hanoi(input, 1, 3);
  }
  return 0;
}
