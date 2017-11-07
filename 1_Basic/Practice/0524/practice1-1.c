#include <stdio.h>
#include <stdlib.h>

int main(){
	int init_n, n, input;
	int *numbers;
	printf("the number of initial data : ");
	scanf("%d", &init_n);
	numbers = (int*)malloc(sizeof(int)*init_n);
	n=0;
	while(1){
		printf("input : ");
		scanf("%d", &input);
		if(input == -1)	break;
		if(n<init_n){
			numbers[n] = input;
		}
		else{
			numbers = (int*)realloc(numbers, sizeof(int)*2*init_n);
			init_n *= 2;
			numbers[n] = input;
		}
		n++;
	}
	for(int i=0;i<n;i++)	printf("%d ", numbers[i]);
	free(numbers);
	return 0;
}
