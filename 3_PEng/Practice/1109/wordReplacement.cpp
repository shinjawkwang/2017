#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

bool isLetter(char inpt){
  return ('A' <= inpt && inpt <= 'Z') || ('a' <= inpt && inpt <= 'z');
}

int main(int argc, char *args[]){
  string input, clear;
  string output;
  int n, i, j, cnt=0;
  cin >> n;
  getline(cin, clear);
  for(;n;n--){
    getline(cin, input);
    for(i=0;i<input.length();i++){
      if(isLetter(input[i])){
        cnt ++;
      }
      else{
        output.push_back(input[i]);
        cnt = 0;
      }
      if(0 < cnt && cnt < 4 && !isLetter(input[i+1])){
        if(cnt == 1)  output.push_back(input[i]);
        else          output.append(input, i-cnt+1, cnt);
      }
      if(cnt == 4 && !isLetter(input[i+1])){
        if(input[i-4] == ' ' || i-3 == 0){
          for(j=3;j>=0;j--){
            if(j==3){
              if('A' <= input[i-j] && input[i-j] <= 'Z')  output.append(1u, 'L');
              else                                        output.append(1u, 'l');
            }
            else if(j==2)                                 output.append(1u, 'o');
            else if(j==1)                                 output.append(1u, 'v');
            else if(j==0)                                 output.append(1u, 'e');
          }
          cnt = 0;
        }
        else  output.append(input, i-cnt+1, cnt);
      }
      if(4 < cnt && !isLetter(input[i+1])){
        output.append(input, i-cnt+1, cnt);
      }
    }
    output += '\n';
    cout << output;
    output.erase(0, output.length());
  }
  return 0;
}
