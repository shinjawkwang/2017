#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int max(int a, int b){return a>b?a:b;}
bool isPalinedrome(string input){
  int len = input.length();
  for(int i=0;i<len;i++){
    if(input[i] != input[len-i-1]){
      return false;
    }
  }
  return true;
}

int MaxPalinedrome(int &n){
  int i, j, testCase, max = 0;
  for(i=pow(10, n)-1;i>0;i--){
    for(j=i;j>0;j--){
      if(i * j < max) continue;
      testCase = i * j;
      if(isPalinedrome(to_string(testCase))){
        if(testCase > max){
          max = testCase;
        }
      }
    }
  }
  return max;
}

int main() {
  int n;
  cin >> n;
  cout << MaxPalinedrome(n) << endl;
  return 0;
}
