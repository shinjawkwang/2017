#include <iostream>
#include <string>
#include <vector>
using namespace std;

string element[] = { "h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al",
"si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe",
"co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr",
"y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb",
"te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au",
"hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "rf", "db", "sg",
"bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd",
"pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "ac",
"th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md",
"no", "lr" };
string input;

vector<int> stack;
vector<int> pushlog;
int pushPos=-1;

bool search(int inptPos, int rewflag){
  int cnt = 0, flag = 1;
  for(int i=0;i<sizeof(element)/sizeof(string) && flag;i++){
    int pos = element[i].find(input[inptPos]);
    if(pos != string::npos && !pos){
      cout << "<----push_back " << i << ": " << element[i] << " into stack---->\n";
      stack.push_back(i);
      cnt ++;
    }
  }
  if(flag){
    pushlog.push_back(cnt);
    pushPos ++;
  }
  flag = 1;
  if(stack.empty()){
    cout << "ERROR! Stack Empty -- We cannot find element.\n";
    return false;
  }
  else{
    while(!stack.empty()){
      string ch = element[stack.back()];
      if(element[stack.back()].length() == 1){
        ch.erase(1);
      }
      stack.pop_back();
      if(ch.length() == 2){
        if(input[inptPos] == ch[0] && input[inptPos+1] == ch[1]){
          if(inptPos+1 == input.length()-1){
            cout << "<----True Case1---->\n";
            return true;
          }
          return search(inptPos+2, 2);
        }
        else{
          cout << "ERROR! Second character mismatch.\n";
          pushlog[pushPos] --;
          if(stack.empty()){
            cout << "ERROR! Stack Empty -- characters are remained.\n";
            return false;
          }
          if(!pushlog[pushPos]){
            cout << "<----Rewind with flag: "<< rewflag << "---->\n";
            flag = 0;
            if(rewflag==2){
              inptPos -= 2;
              pushPos -= 2;
            }
            else{
              inptPos --;
              pushPos --;
            }
          }
        }
      }
      else{
        if(input[inptPos] == ch[0]){
          if(inptPos == input.length()-1){
            cout << "<----True Case2---->\n";
            return true;
          }
          return search(inptPos+1, 1);
        }
        else{
          cout << "ERROR! First character mismatch.\n";
          pushlog[pushPos] --;
          if(stack.empty()){
            cout << "ERROR! Stack Empty -- characters are remained.\n";
            return false;
          }
          if(!pushlog[pushPos]){
            cout << "<----Rewind with flag: "<< rewflag << "---->\n";
            flag = 0;
            if(rewflag==2){
              inptPos -= 2;
              pushPos -= 2;
            }
            else{
              inptPos --;
              pushPos --;
            }
          }
        }
      }
    }
    return false;
  }
}

int main(int argc, char *argv[]) {
  string clear;
  int n;
  cin >> n;
  getline(cin, clear);
  for(int i=1; i<=n; i++){
    getline(cin, input);
    for(int i=0;i<input.length();i++){
      input[i] = tolower(input[i]);
    }
    cout << "Case #" << i << endl;
    if(search(0, 0)){
      cout << "yes\n";
    }
    else{
      cout << "no\n";
    }
    stack.clear();
  }
  return 0;
}
