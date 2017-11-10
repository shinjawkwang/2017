#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

bool isLetter(char inpt){
  return ('A' <= inpt && inpt <= 'Z') || ('a' <= inpt && inpt <= 'z');
}

int main(int argc, char *args[]){
  string input, word, clear;
  int n, i, cnt=0, pos=-2;
  cin >> n;
  getline(cin, clear);
  for( ; n; n--){
    getline(cin, input);
    stringstream stream1(input);
    pos = -2;
    while(stream1 >> word){
			pos++;
      for(i=0;i<word.length();i++){
        pos ++;
        if(isLetter(word[i]))  cnt++;
        else                   cnt=0;
        if(cnt==4 && !isLetter(word[i+1])){
          if('A' <= word[i-3] && word[i-3] <= 'Z')
            input.replace(pos-3, 4, "Love");
          else if('a' <= word[i-3] && word[i-3] <= 'z')
            input.replace(pos-3, 4, "love");
          cnt = 0;
        }
      }
      cnt = 0;
    }
    cout << input << endl;
  }
  return 0;
}
