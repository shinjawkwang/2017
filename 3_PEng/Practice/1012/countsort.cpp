#include <iostream>
#include <stdio.h>
using namespace std;

int counter[100] = {0,};
int input[25];
int result[25];

//void countersort(int )

int main(){
  int i,j, pos=0;

  for(i=0;i<20;i++)   scanf("%d", &input[i]);
  for(i=0;i<20;i++)   counter[input[i]]++;

  for(i=0;i<100;i++){
    for(j=0;j<counter[i];j++){
      result[pos] = i;
      pos ++;
    }
  }
  for(i=0;i<20;i++) cout << result[i] << " ";
  cout << endl;
  return 0;
}
