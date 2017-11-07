#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK 100


typedef enum {false, true} bool;

typedef struct {
	char small;
	char large;
} Hex_num;

typedef struct {
	Hex_num items[MAX_STACK];
	int top;
} Stack;

Hex_num add(Hex_num b1, Hex_num b2);
Hex_num subtract(Hex_num b1, Hex_num b2);
Hex_num multiply(Hex_num b1, Hex_num b2);
Hex_num division(Hex_num b1, Hex_num b2);

void InitStack (Stack *pstack);
bool IsFull(Stack *pstack);
bool IsEmpty(Stack *pstack);
Hex_num Peek(Stack *pstack);
void Push(Stack *pstack, Hex_num item);
void Pop(Stack *pstack);

void ConvInfixToPostfix (char* exp, char* convExp, int len);
Hex_num EvalPostfix(char* exp, int len);
void print_Hex_num(Hex_num result);

int main() {
	char infix_exp[100];
	char postfix_exp[100];
	Hex_num result;

	scanf("%s",infix_exp);

	ConvInfixToPostfix (infix_exp, postfix_exp, strlen(infix_exp));

	printf("%s\n%s\n",infix_exp,postfix_exp);

	result = EvalPostfix (postfix_exp, strlen(postfix_exp));

	print_Hex_num(result);

	return 0;
}

/* Modify from here */
void InitStack (Stack *pstack){ //Start stack
	pstack -> top = -1;
}
void Push(Stack *pstack, Hex_num item){//if stack is full, end program. Or, push item to stack
	if (IsFull(pstack))
		exit(1);
  pstack->items[++(pstack->top)] = item;
}
void Pop(Stack *pstack){//if stack is empty, end program. Or, pop item from stack
	if(IsEmpty(pstack))	exit(1);
	--(pstack -> top);
}
Hex_num Peek(Stack *pstack){//Peek an item from top of the stack if stack isn't empty
	if(IsEmpty(pstack))	exit(1);
	return pstack->items[pstack->top];
}
bool IsFull(Stack *pstack){//check if stack is full
	return pstack -> top == MAX_STACK - 1;
}
bool IsEmpty(Stack *pstack){//check if stack is empty
	return pstack -> top == -1;
}
bool IsDigit(char exp){//check if an character is not operator(number)
	if(exp == '+' || exp == '-' || exp == '*' || exp == '/' || exp =='O')
		return false;
	else
		return true;
}
int GetPriority(char op){//give priority of operators
  if (op == '*' || op == '/')				return 2;
	else if (op == '+' || op == '-') 	return 1;
  else															return 0;
}
bool ComPriority(Hex_num op1, char op2) {//compare priority of operators
	char opp1 = op1.small;

  int op1_pr = GetPriority(opp1);
  int op2_pr = GetPriority(op2);
	if (op1_pr >= op2_pr) return true;
  else									return false;
}

void ConvInfixToPostfix (char* exp, char* convExp, int len){//convert infix expression to postfix expression
	Stack stack;
	Hex_num peeking, pushing;
	int i, pos = 0;
	InitStack(&stack);
	for(i=0;i<len;i++){
		if(IsDigit(exp[i])) //if expression is digit, print it to postfix expression
			convExp[pos++] = exp[i];
		else {
			while(!IsEmpty(&stack) && ComPriority(Peek(&stack), exp[i])){/*if expression is not digit*/
				peeking = Peek(&stack);																		 /*and priority operator at stack's top is higher than expression*/
				convExp[pos++] = peeking.small;														 /*Peek the operator at stack's top and print to postfix expression*/
				Pop(&stack);
			}
			pushing.small = exp[i];			//push expression to stack
			pushing.large = 'O';				//to devide from digits
			Push(&stack, pushing);
		}
	}
	while (!IsEmpty(&stack)) { //if expressions are left in stack, empty stack
		convExp[pos++] = Peek(&stack).small;
    Pop(&stack);
  }
	convExp[pos] = NULL;
}

Hex_num add(Hex_num b1, Hex_num b2){
	int left=0, right=0, ten_result;
	Hex_num result;
	if(b1.large >= 'A')	left += (b1.large - 55) * 16;
	else								left += (b1.large - '0') * 16;

	if(b2.large >= 'A')	right += (b2.large - 55) * 16;
	else								right += (b2.large - '0') * 16;

	if(b1.small >= 'A')	left += (b1.small - 55) * 1;
	else								left += (b1.small - '0') * 1;

	if(b2.small >= 'A')	right += (b2.small - 55) * 1;
	else								right += (b2.small - '0') * 1;

	ten_result = left + right;
	if(ten_result / 16 < 10)	result.large = ten_result/16 + '0';
	else											result.large = ten_result/16 + 55;
	if(ten_result % 16 < 10)	result.small = ten_result%16 + '0';
	else											result.small = ten_result%16 + 55;
	return result;
}
Hex_num subtract(Hex_num b1, Hex_num b2){
	int left=0, right=0, ten_result;
	Hex_num result;
	if(b1.large >= 'A')	left += (b1.large - 55) * 16;
	else								left += (b1.large - '0') * 16;

	if(b2.large >= 'A')	right += (b2.large - 55) * 16;
	else								right += (b2.large - '0') * 16;

	if(b1.small >= 'A')	left += (b1.small - 55) * 1;
	else								left += (b1.small - '0') * 1;

	if(b2.small >= 'A')	right += (b2.small - 55) * 1;
	else								right += (b2.small - '0') * 1;

	ten_result = left - right;
	if(ten_result / 16 < 10)	result.large = ten_result/16 + '0';
	else											result.large = ten_result/16 + 55;
	if(ten_result % 16 < 10)	result.small = ten_result%16 + '0';
	else											result.small = ten_result%16 + 55;
	return result;
}
Hex_num multiply(Hex_num b1, Hex_num b2){
	int left=0, right=0, ten_result;
	Hex_num result;
	if(b1.large >= 'A')	left += (b1.large - 55) * 16;
	else								left += (b1.large - '0') * 16;

	if(b2.large >= 'A')	right += (b2.large - 55) * 16;
	else								right += (b2.large - '0') * 16;

	if(b1.small >= 'A')	left += (b1.small - 55) * 1;
	else								left += (b1.small - '0') * 1;

	if(b2.small >= 'A')	right += (b2.small - 55) * 1;
	else								right += (b2.small - '0') * 1;

	ten_result = left * right;
	if(ten_result / 16 < 10)	result.large = ten_result/16 + '0';
	else											result.large = ten_result/16 + 55;
	if(ten_result % 16 < 10)	result.small = ten_result%16 + '0';
	else											result.small = ten_result%16 + 55;
	return result;
}
Hex_num division(Hex_num b1, Hex_num b2){
	int left=0, right=0, ten_result;
	Hex_num result;
	if(b1.large >= 'A')	left += (b1.large - 55) * 16;
	else								left += (b1.large - '0') * 16;

	if(b2.large >= 'A')	right += (b2.large - 55) * 16;
	else								right += (b2.large - '0') * 16;

	if(b1.small >= 'A')	left += (b1.small - 55) * 1;
	else								left += (b1.small - '0') * 1;

	if(b2.small >= 'A')	right += (b2.small - 55) * 1;
	else								right += (b2.small - '0') * 1;

	ten_result = left / right;
	if(ten_result / 16 < 10)	result.large = ten_result/16 + '0';
	else											result.large = ten_result/16 + 55;
	if(ten_result % 16 < 10)	result.small = ten_result%16 + '0';
	else											result.small = ten_result%16 + 55;
	return result;
}
Hex_num EvalPostfix(char* exp, int len){
	Stack stack;
	Hex_num pushing, op1, op2;
	int flag = 1;
	InitStack(&stack);
	for(int i=0;i<len;i++){
		if(IsDigit(exp[i])){//push Hex_num to stack
			if(flag){
				pushing.large = exp[i];
				pushing.small = exp[i+1];
				Push(&stack, pushing);
				flag = 0;
			}
			else	flag = 1;
		}
		else {//operate numbers
			op2 = Peek(&stack);
			Pop(&stack);
			op1 = Peek(&stack);
			Pop(&stack);
			if(exp[i] == '+')					Push(&stack, add(op1, op2));
			else if(exp[i] == '-')		Push(&stack, subtract(op1, op2));
			else if(exp[i] == '*')		Push(&stack, multiply(op1, op2));
			else if(exp[i] == '/')		Push(&stack, division(op1, op2));
		}
	}
	return Peek(&stack);
}
void print_Hex_num(Hex_num result){printf("%c%c", result.large, result.small);}

/* Modify to here */
