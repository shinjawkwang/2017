#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool isLetter(char inpt){
  return ('A' <= inpt && inpt <= 'Z') || ('a' <= inpt && inpt <= 'z');
}

int main(int argc, char *args[]){
  string input, word, clear, find;
  int n, i, j, cnt=0, alpha=0;
  cin >> n;
  getline(cin, clear);
  for( ; n; n--){
    getline(cin, input);
    stringstream stream1(input);
    while(stream1 >> word){
			alpha=0;
			for(i=0;i<word.length();i++)
        if(isLetter(word[i])) alpha++;
      if(alpha > 4)
        continue;
      for(i=0;i<word.length();i++){
        if(isLetter(word[i]))  cnt++;
        else                   cnt=0;
        if(cnt==4 && !isLetter(word[i+1])){
          for(j=i-3;j<=i;j++) find.append(1u, word[j]);
          //cout << "<----Start Replace---->\tfind: " << find << "\ti: " << i << endl;
          if('A' <= word[i-3] && word[i-3] <= 'Z')
            input.replace(input.find(find), 4, "Love");
          else if('a' <= word[i-3] && word[i-3] <= 'z')
            input.replace(input.find(find), 4, "love");
          cnt = 0;
          //cout << input << endl;
          find.clear();
        }
        //cout << "Current characer: " << word[i] << "\t" << "Count: " << cnt << "\ti: " << i << endl;
      }
      cnt = 0;
    }
    cout << input << endl;
  }
}//a!!test!!aaaa!!!!test!!!!!
