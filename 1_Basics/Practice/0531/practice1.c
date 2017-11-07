#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_gets(char *str, int max_length){
	int cnt = 0;
	char c;
	while(1){
		c = getchar();
		
		if(cnt < max_length-1){
			str[cnt] = c;
			if(str[cnt]=='\n')	break;

			cnt++;
		}
		else if(cnt==max_length-1){
			if(c=='\n')	break;
		}
			
	}
	return cnt;
}

int main(){
	char str[10];
	my_gets(str, 10);
	printf("%s", str);

	return 0;

}
