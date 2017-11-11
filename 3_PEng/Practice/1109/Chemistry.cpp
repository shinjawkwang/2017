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

bool search(string str){
  if(!str.length()) return true;
  int i, j=0, k, pos_List[3];
  string st1, st2;
  for(i=0;i<sizeof(element)/sizeof(string);i++){
    if((element[i].length()==1 && str[0]==element[i][0]) || (element[i].length()==2 && str[0]==element[i][0] && str[1]==element[i][1])){
      pos_List[j++] = i;
    }
  }
  cout << "j = "<< j << "\npos_List : ";
  for(k=0;k<j;k++)  cout << element[pos_List[k]] << " ";
  cout << endl;
  if(j==0){
    cout << "ERROR! j is 0.\n";
    return false;
  }
  if(j==1){
    st1.clear();
    if(element[pos_List[0]].length()== 1){
      st1.assign(str, 1, str.length()-1);
    }
    else{
      st1.assign(str, 2, str.length()-2);
    }
    cout << "<----Assign #1---->\n" << st1 << endl;
    return search(st1);
  }
  if(j==2){
    st1.clear(); st2.clear();
    st1.assign(str, 1, str.length()-1);
    st2.assign(str, 2, str.length()-2);
    cout << "<----Assign #2---->\n" << st1 << endl << st2 << endl;
    return search(st1) || search(st2);
  }
  if(j!=0 && j!=1 && j!=2) exit(1); // Error
}

int main(int argc, char *argv[]) {
  string input, clear;
  int n;
  cin >> n;
  getline(cin, clear);
  for(int i=1; i<=n; i++){
    getline(cin, input);
    for(int i=0;i<input.length();i++){
      input[i] = tolower(input[i]);
    }
    cout << "Case #" << i << endl;
    if(search(input)){
      cout << "yes\n";
    }
    else{
      cout << "no\n";
    }
  }
  return 0;
}
