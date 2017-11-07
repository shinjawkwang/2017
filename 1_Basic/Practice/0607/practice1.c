#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Employee{
	char name[20];
	char nationality[200];
	int salary;
	struct Employee *superior;
}employee;

void getInfo(employee *emp){
	printf("Input name : ");
	gets(emp->name);
	printf("Input Nationality : ");
	gets(emp->nationality);
	printf("Input salary : ");
	scanf("%d", &(emp->salary));
	getchar();
	char ans[4];
	printf("Does %s has a superior? <yes or no> : ", emp->name);
	gets(ans);
	if(!strcmp(ans,"yes")){
		emp->superior = (employee*)malloc(sizeof(employee));
		getInfo(emp->superior);
	}
	else
		emp->superior = NULL;
}

void printInfo(employee *emp){
	printf("name : %s\n", emp->name);
	printf("nationality : %s\n", emp->nationality);
	printf("salary : %d\n", emp->salary);
	if(emp->superior != NULL){
		printf("--------%s's superior------\n", emp->name);
		printInfo(emp->superior);
		free(emp->superior);
	}
}

int main(){
	employee emp[100];
	char ans[4];
	int cnt=0;
	while(1){
		printf("yes or no? ");
		gets(ans);
		if(strcmp(ans, "yes")==0){
			getInfo(&emp[cnt]);
			cnt ++;
			printf("\n");
		}
		else if(strcmp(ans, "no")==0)	break;
	}
	for(int i=0;i<cnt;i++){
		printf("--------employee %d--------\n", i+1);
		printInfo(&emp[i]);
	}
	return 0;
}
