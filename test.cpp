#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int args, char *argv[]){
  string ch = "ar";
  ch.erase(1);
  cout << ch << " " << ch.length() << endl;
}
