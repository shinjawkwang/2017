#include <stdio.h>
#include <string.h>

double stack[30];
int top=0;

void push(double n){
	stack[top] = n;
	top++;
}
void pop(){
	stack[top-1] = 0;
	top--;
}
double calc(char calculator){
	if(calculator == '+')
		return stack[top-2] + stack[top-1];
	else if(calculator == '-')
		return stack[top-2] - stack[top-1];
	else if(calculator == '*')
		return stack[top-2] * stack[top-1];
	else if(calculator == '/')
		return stack[top-2]/stack[top-1];
	else
		return 0;
}


int main(){
	int alphabets, nums[26], flag;
	double result=0;
	char expression[1000];
	scanf("%d", &alphabets);
	scanf("%s", expression);
	for(int i=0;i<alphabets;i++)
		scanf("%d", &nums[i]);
	for(int i=0;i<strlen(expression);i++){
		flag = 1;
		for(int j=65;j<65+alphabets;j++){
			if(expression[i] == j){
				push(nums[j-65]);
				flag = 0;
			}
		}
		if(flag){
			result = calc(expression[i]);
			pop();
			pop();
			push(result);
		}
	}
	printf("%.2f", result);
	return 0;
}
