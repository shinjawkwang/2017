#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;

vector <int> arr;
class Polynomial{
private:
  int CoIdx;
  int *x;
public:
  Polynomial();
  int getCoIdx(int n);
  int* getValIdx(int n);
  void setCoIdx();
  void setValIdx();
};
Polynomial::Polynomial(){}
int* Polynomial::getValIdx(int n){
  return &n;
}
bool search(int n){
  for(int i=0;i<arr.size();i++){
    if(n==arr[i]) return true;
  }
  return false;
}

int main(int argc, char *argv[]) {
  int inpt;
  string input;
  getline(cin, input);
  stringstream stream(input);
  while(stream){
    stream >> inpt;
    if(isalpha(inpt)){
      return 0;
    }
    if(!search(inpt))
      arr.push_back(inpt);
  }


  for(int i=0;i<arr.size();i++){
    cout << arr[i] << " ";
  }

  return 0;
}
