#include <stdio.h>
#include <stdlib.h>

int main(){
	int *array;
	int size=5, cnt=0, input, position;
	char command[2], cd_cmd[2];
	array = (int*)malloc(sizeof(int)*5);
	printf("-------------------------------------\n\n");
	printf("Array size = 5\nElements = []\n");
	printf("(a:add / d:delete / i:insert / cd:conditional delete)\n");
	printf("-------------------------------------\n");
	printf("Input commands : ");
	while(1){
		scanf("%s", command);
		if(command[0] == 'a'){
			scanf("%d", &input);
			if(cnt==size){
				array = realloc(array, sizeof(int)*size*2);
				size *= 2;
				array[cnt] = input;
			}
			else
				array[cnt] = input;
			cnt++;
		}
		if(command[0] == 'd'){
			scanf("%d", &input);
			for(int i=0;i<=cnt;i++){
				if(array[i] == input){
					for(int j=i;j<=cnt;j++)
						array[j]=array[j+1];
					break;
				}
			}
			cnt--;
			if(cnt<0.3*size && size>5){
				array = realloc(array, sizeof(int)*size*0.5);
				size/=2;
			}
		}
		if(command[0] == 'i'){
			scanf("%d%d", &input, &position);
			if(cnt==size){
				array = realloc(array, sizeof(int)*size*2);
				size *= 2;
			}
			for(int i=cnt-1;i>=position;i--)
				array[i+1] = array[i];
			array[position] = input;
		}
		if(command[0] == 'c' && command[1] == 'd'){
			scanf("%s%d", cd_cmd, &input);
			if(cd_cmd[0]=='<'){
				for(int i=0;i<=cnt;i++){
					if(array[i]<input){
						for(int j=i;j<=cnt;j++){
							array[j] = array[j+1];
						}
						cnt--;
						i--;
						array[cnt] = input;
					}
				}
			}
			else if(cd_cmd[0]=='>'){
				for(int i=0;i<=cnt;i++){
					if(array[i]>input){
						for(int j=i;j<=cnt;j++){
							array[j] = array[j+1];
						}
						cnt--;
						i--;
						array[cnt] = input;
					}
				}
			}
			else if(cd_cmd[0]=='=' && cd_cmd[1]=='='){
				for(int i=0;i<=cnt;i++){
					if(array[i]==input){
						for(int j=i;j<=cnt;j++){
							array[j] = array[j+1];
						}
						cnt--;
						i--;
						array[cnt] = input+1;
					}
				}
			}
			else if(cd_cmd[0]=='!' && cd_cmd[1]=='='){
				for(int i=0;i<=cnt;i++){
					if(array[i]!=input){
						for(int j=i;j<=cnt;j++){
							array[j] = array[j+1];
						}
						cnt--;
						i--;
						array[cnt] = input;
					}
				}
			}
			while(1){
				if(cnt<0.3*size && size>5){
					array = realloc(array, sizeof(int)*size*0.5);
					size/=2;
				}
				else	break;
			}
		}
		printf("-------------------------------------\n\n");
		printf("Array size = %d\nElements = [ ", size);
		if(cnt>2){
			for(int i=0;i<cnt-1;i++)	
				printf("%d, ", array[i]);
			printf("%d ", array[cnt-1]);
		}
		else{
			if(cnt==1)		printf("%d ", array[0]);
			else if(cnt==2)	printf("%d, %d ", array[0], array[1]);
			else			printf(" ");
		}
		printf("]\n(a:add / d:delete / i:insert / cd:conditional delete)\n");
		printf("-------------------------------------\n");
		printf("Input commands : ");
	}
	free(array);
	return 0;
}
