#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int*numbers[5];

	for(int i=0;i<5;i++){
		printf("input : ");
		scanf("%d", &n);
		numbers[i] = (int*)malloc(sizeof(int)*(n+1));
		numbers[i][0] = n;
		for(int j=1;j<=n;j++)	numbers[i][j] = j;
	}
	printf("<RESULT>\n");
	for(int i=0;i<5;i++){
		n = numbers[i][0];
		for(int j=0;j<=n;j++)
			printf("%d ", numbers[i][j]);
		printf("\n");
	}
	for(int i=0;i<5;i++)	free(numbers[i]);
	return 0;
}
