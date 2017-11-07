#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Palindrome(char *str){
	int i, len=0, flag=0;

	for(i=0;i<=strlen(str)/2;i++){
		if(str[i] != str[strlen(str)-i-1])	flag=1;
	}
	return flag?0:1;
}

int main(){
	char str[50];
	int test;
	while(1){
		printf("Input String (exit : 0)\n");
		scanf("%s", str);
		if(str[0]=='0')	return 0;
		test = Palindrome(str);
		printf("%d\n", test);
		if(Palindrome(str))	printf("YES\n\n");
		else				printf("NO\n\n");
	}
	return 0;
}
