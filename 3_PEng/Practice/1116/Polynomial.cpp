#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

vector <int> arr;
class Polynomial{
private:
  int CoIdx;
  int *x;
public:
  Polynomial();
  int getCoIdx(int n);
  int* getValIdx(int *n);
  void setCoIdx();
  void setValIdx();
  void Print();
};
Polynomial::Polynomial(){}
int* Polynomial::getValIdx(int *n){
  return n;
}
void Polynomial::setValIdx(){
  if(arr.size() > 0)
    x = getValIdx(&arr[1]);
}
int Polynomial::getCoIdx(int n){
  return n;
}
void Polynomial::setCoIdx(){
  if(arr.size() > 0)
    CoIdx = getCoIdx(arr[0]);
}
void Polynomial::Print(){
  int sum = 0;
  for(int i=0;arr.size()>0 &&i<arr.size()-1;i++){
    sum += pow(CoIdx, x[i]);
  }
  cout << "Sum = " << sum << endl;
}

bool search(int n){
  for(int i=0;i<arr.size();i++){
    if(n==arr[i]) return true;
  }
  return false;
}

int main(int argc, char *argv[]) {
  Polynomial poly;
  int inpt, inpt2;
  string input;
  getline(cin, input);
  stringstream stream(input);
  while(stream >> inpt){
    if(!search(inpt)){
      arr.push_back(inpt);
    }
  }
  poly.setValIdx();
  poly.setCoIdx();
  poly.Print();
  cout << "New X Val: ";
  cin >> inpt2;
  if(arr.size()>0)
    arr[0] = inpt2;
  poly.setCoIdx();
  poly.Print();
  return 0;
}
