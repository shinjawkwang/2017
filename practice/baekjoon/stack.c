#include <stdio.h>

int main(){
	int n, stack[10050], i, j, push_num, seq=0;
	char input[10];
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%s", input);
		if(input[0] == 'p' && input[1] == 'u' && input[2] == 's' && input[3] == 'h'){
      scanf("%d", &push_num);		//push : 투입
			stack[seq] = push_num;
			seq++;
			}
		if(input[0] == 'p' && input[1] == 'o' && input[2] == 'p'){
			if(seq==0)		//pop : 뽑아냄
				printf("%d \n", -1);
			else{
				printf("%d \n", stack[seq-1]);
				stack[seq-1]=0;
				seq--;
			}
		}
		if(input[0] == 's' && input[1] == 'i' && input[2] == 'z' && input[3] == 'e')
			printf("%d \n", seq);
		if(input[0] == 'e' && input[1] == 'm' && input[2] == 'p' && input[3] == 't' && input[4] == 'y'){
			if(seq == 0)
				printf("%d \n", 1);
			else
				printf("%d \n", 0);
		}
		if(input[0] == 't' && input[1] == 'o' && input[2] == 'p'){
			if(seq == 0)
				printf("%d \n", -1);
			else
				printf("%d \n", stack[seq-1]);
		}

	}
	return 0;
}
