#include <stdio.h>
#include <string.h>

typedef struct Node{
	struct Node *next[2];
	int val;
	int weight[2];
}node;

int stack[5];
int top=0;
void push(int input){stack[top++] = input;}
int pop(){return stack[--top];}
int show(){return stack[top-1];}
void Sort(int *arr, int size);

int main(){
	int wei[6][6] = { {0,0,0,0,0,0}, {0,0,0,0,0,20}, {0,10,0,0,15,0}, {0,0,10,10,0,0}, {0,0,0,20,0,0}, {0,0,30,0,10,0} };
	int i, j, k, sum_wei=0, start, finish, index, save, cnt=0, result[5], visit[6], cnt_n[6], cnt_p[6], cnt_w[6], pushList[6];
	node graph[6];
	char cmd[10];
	for(i=0;i<6;i++){visit[i] = pushList[i] = 0;}
	while(1){
		scanf("%s", cmd); getchar();
		if(!strcmp(cmd, "create")){
			for(i=1;i<=5;i++){
				cnt_n[i]=cnt_p[i]=cnt_w[i]=0;
				for(j=1;j<=5;j++){
					if(wei[i][j]){
						graph[i].val = i;
						graph[i].next[cnt_n[i]++] = &graph[j];
						graph[i].weight[cnt_w[i]++] = wei[i][j];
					}
				}
			}
		}
		if(!strcmp(cmd, "show")){
			for(i=1;i<=5;i++){
				printf("(%d, %d)", graph[i].val, cnt_n[i]);
				if(cnt_n[i]-1){
					for(j=0;j<2;j++)
						printf("->(%d, %d)", graph[i].next[j]->val, graph[i].weight[j]);
				}
				else
					printf("->(%d, %d)", graph[i].next[0]->val, graph[i].weight[0]);
				printf("\n");
			}
		}
		if(!strcmp(cmd, "path")){
			scanf("%d%d", &start, &finish); getchar();
			push(graph[start].val);	visit[start]++;
			while(top){
				if(show()!=start)	printf("-> (");
				else				printf("(");
				for(i=0;i<top;i++){
					if(i!=top-1)	printf("%d, ", stack[i]);
					else			printf("%d", stack[i]);
				}
				printf(")t");
				index = pop();
				for(k=0;k<cnt_n[index];k++){
					if(!visit[graph[index].next[k]->val]){
						save = graph[index].next[k]->val;
						visit[save]++;
						push(save);
						pushList[save] = index;
					}
				}
				if(index==finish){
					save = finish;
					result[cnt++] = finish;
					while(1){
						result[cnt] = pushList[save];
						save = result[cnt];
						if(save == start)	break;
						cnt++;
					}
					break;
				}
				Sort(stack, top);
			}
			printf("\n");
			for(i=cnt;i>=0;i--){
				if(i==cnt)	printf("%d", result[i]);
				else		printf("->%d", result[i]);
			}
			printf("\n");
			top=cnt=0;
			for(i=0;i<6;i++)	visit[i]=0;
		}
		if(!strcmp(cmd, "path-weight")){
			scanf("%d%d", &start, &finish); getchar();
			push(graph[start].val);	visit[start]++;
			while(top){
				index = pop();
				for(k=0;k<cnt_n[index];k++){
					if(!visit[graph[index].next[k]->val]){
						save = graph[index].next[k]->val;
						visit[save]++;
						push(save);
						pushList[save] = index;
					}
				}
				if(index==finish){
					save = finish;
					result[cnt++] = finish;
					while(1){
						result[cnt] = pushList[save];
						save = result[cnt];
						if(save == start)	break;
						cnt++;
					}
					break;
				}
				Sort(stack, top);
			}
			for(i=0;i<cnt;i++)	sum_wei += wei[result[i+1]][result[i]];
			printf("%d\n", sum_wei);
			top=cnt=sum_wei=0;
			for(i=0;i<6;i++)	visit[i]=0;
		}
		if(!strcmp(cmd, "quit"))	break;
	}
	return 0;
}

void Sort(int*arr, int size){
	int tmp, i, j;
	for(i=0;i<size;i++){
    	for(j=1;j<size;j++){
      		if(arr[j-1]>arr[j]){
        		tmp = arr[j];
        		arr[j] = arr[j-1];
        		arr[j-1] = tmp;
      		}
    	}
 	 }
}
