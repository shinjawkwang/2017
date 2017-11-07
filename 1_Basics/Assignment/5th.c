#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct User{
	char name[100];
	int numFriends;
	struct User *friends[100];
}us;

int main(){
 	int us_num, pa_num, i, j, k, pos, flag, len, cnt=0;
	char first[100], second[100], target[100], *result[100];
	us users[110];
	for(i=0;i<100;i++){
		users[i].numFriends = 0;
		for(j=0;j<100;j++)
			users[i].friends[j]=NULL;
	}
	scanf("%d%d", &us_num, &pa_num);
	printf("\n");
	for(i=0;i<us_num;i++)
		scanf("%s", users[i].name);
	for(i=0;i<pa_num;i++){
		scanf("%s%s", first, second);
		for(j=0;j<us_num;j++){
			if(!strcmp(first, users[j].name)){
				for(k=0;k<us_num;k++){
					if(!strcmp(second, users[k].name)){
						users[j].friends[users[j].numFriends++] = &users[k];
						users[k].friends[users[k].numFriends++] = &users[j];
					}
				}
			}
		}
	}
	scanf("%s", target);
	for(i=0;i<us_num;i++){
		if(!strcmp(target, users[i].name)){
			pos = i;
		}
	}
	for(i=0;i<users[pos].numFriends;i++){
		for(j=0;j<users[pos].friends[i]->numFriends;j++){
			if(users[pos].friends[i]->friends[j]==&users[pos])	continue;
			for(k=0;k<users[pos].numFriends;k++){
				if(users[pos].friends[k] == users[pos].friends[i]->friends[j]){
					flag=1;
					break;
				}
				flag=0;
			}
			if(flag)	continue;
			for(k=0;k<cnt;k++){
				if(!strcmp(users[pos].friends[i]->friends[j]->name, result[k]))	{
					flag=1;
					break;
				}
				flag=0;
			}
			if(flag)	continue;
			result[cnt++] = users[pos].friends[i]->friends[j]->name;
		}
	}


	for(i=0;i<cnt;i++){
		printf("%s ", result[i]);
	}
	printf("\n");
	return 0;
}
