#include <stdio.h>
#include <string.h>

int main(){
	char words[10][20], swap1[20], swap2[20];
	char tmp[20];
	int i, j, k;
	for(int i=0;i<10;i++){
		printf("Enter 10 words (%d/10) : ", i+1);
		scanf("%s", words[i]);
	}
	printf("[Before Sorting]\n");
	for(i=0;i<10;i++)
		printf("%s\n", words[i]);
	for(i=0;i<10;i++){
		for(j=1;j<10;j++){
			if(strcmp(words[j], words[j-1])<0){
				strcpy(tmp,words[j]);
				strcpy(words[j],words[j-1]);
				strcpy(words[j-1],tmp);
			}
		}
	}

	printf("\n[After Sorting]\n");
	for(i=0;i<10;i++)
		printf("%s\n", words[i]);
	return 0;
}
