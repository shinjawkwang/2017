#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int i, j;
	for(i=1;i<=10;i++){
		if(i<=5){
			for(j=0;j<6-i;j++)			printf("*");
			for(j=0;j<(i-1)*2;j++)	printf(" ");
			for(j=0;j<6-i;j++)			printf("*");
		}
		else{
			for(j=0;j<i-5;j++)			printf("*");
			for(j=0;j<(10-i)*2;j++)	printf(" ");
			for(j=0;j<i-5;j++)			printf("*");
		}
		printf("\n");
	}
  return 0;
}
