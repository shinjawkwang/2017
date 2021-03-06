#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stackqueue.h"

typedef struct _GNode {
	int id;
	char data; //The data can be either 'A', 'B', 'C', 'D', 'E' and 'F'.
	struct _GNode *next;
} GNode;

typedef struct {
	int num;
	GNode **heads;
} Graph;

void CreateGraph(Graph *pgraph, int num, char data[]);

void DestroyGraph(Graph *pgraph);

void AddEdge(Graph *pgraph, int src, int dest);

void Solution(Graph *pgraph);

void GetInput();

int main() {
	Graph g;
	CreateGraph(&g, 8, "ABCFCDBD");
	AddEdge(&g, 0, 1);
	AddEdge(&g, 0, 2);
	AddEdge(&g, 0, 4);
	AddEdge(&g, 1, 2);
	AddEdge(&g, 2, 3);
	AddEdge(&g, 2, 4);
	AddEdge(&g, 3, 4);
	AddEdge(&g, 5, 6);
	AddEdge(&g, 6, 7);

	Solution(&g);

	DestroyGraph(&g);

	// GetInput();
	/*
	8 9
	ABCFCDBD
	0 1
	0 2
	0 4
	1 2
	2 3
	2 4
	3 4
	5 6
	6 7
	*/

	return 0;

}

void GetInput(){
	int node, edge, src, des;
	char *a;

	scanf("%d %d",&node, &edge);
	while(getchar()!='\n'); // = fflush(stdin) = __fpurge(stdin)

	a = malloc(sizeof(char)*(node+1));
	scanf("%s",a);

	Graph g;
	CreateGraph(&g, node, a);
	for(int i = 0; i<edge; i++){
		while(getchar()!='\n'); // = fflush(stdin) = __fpurge(stdin)
		scanf("%d %d", &src, &des);
		AddEdge(&g, src, des);
	}

	Solution(&g);

	DestroyGraph(&g);

}

/* Modify from here */
void CreateGraph(Graph *pgraph, int num, char data[]){
	pgraph->num = num;																				//Allocate num of graph.
	pgraph->heads = (GNode **)malloc(sizeof(GNode*) * num);
	for(int i=0;i<num;i++){																		//Allocate every data into graph.
		pgraph->heads[i] = (GNode *)malloc(sizeof(GNode));
		pgraph->heads[i]->id = i;
		pgraph->heads[i]->data = data[i];
		pgraph->heads[i]->next = NULL;
	}
}

void DestroyGraph(Graph *pgraph){
	for(int i = 0; i < pgraph->num; i++){											//Free every allocated pointer in graph.
		GNode* cur = pgraph->heads[i];
		while(cur != NULL) {
			GNode* temp = cur;
			cur = cur->next;
			free(temp);
		}
	}
	free(pgraph->heads);
}

void AddEdge(Graph *pgraph, int src, int dest){
	GNode *newNode1, *newNode2, *cur;
	//For src Node.
	newNode1 = (GNode *)malloc(sizeof(GNode));
	newNode1->id = dest;
	newNode1->data = pgraph->heads[dest]->data;
	newNode1->next = NULL;
	cur = pgraph->heads[src];
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = newNode1;
	//For dest Node.
	newNode2 = (GNode *)malloc(sizeof(GNode));
	newNode2->id = src;
	newNode2->data = pgraph->heads[src]->data;
	newNode2->next = NULL;
	cur = pgraph->heads[dest];
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = newNode2;
}

void Solution(Graph *pgraph){													//Using DFS Algorithm
	Stack stack;
	GNode *cur;
	bool *visit;																				//To define whether I visited node.
	int visitAlpha[6] = {0, };													//For tracking visited data.
	bool result[6] = {false, };													//For finding condition required node.
	bool resultAlpha[6] = {false, };
	visit = (bool *)malloc(sizeof(bool) * pgraph->num);
	for(int i=0;i<pgraph->num;i++){
		visit[i] = false;
	}
	InitStack(&stack);
	Push(&stack, 0);																		//Push First node.

	while(!IsSEmpty(&stack)){														//Do not end searching until the stack is empty.
		int vtx = SPeek(&stack);													//Peek & Pop node.
		Pop(&stack);
		if(visit[vtx])	continue;													//If we already visited node, skip this step.
		else{																							//If we didn't visit node
			visit[vtx] = true;															//We visited here.
			visitAlpha[pgraph->heads[vtx]->data - 'A'] ++;	//Based on ASCII Code
		}
		cur = pgraph->heads[vtx]->next;										//Move current node to next node.
		while(cur != NULL){																//If current node exists
			Push(&stack, cur->id);
			cur = cur->next;
		}
	}
	for(int i=0;i<6;i++){
		if(visitAlpha[i] > 1){														//If there are path to another node having same data
			result[i] = true;
			resultAlpha[i] = true;
		}
	}
	for(int i=0;i<6;i++){
		if(result[i]){
			printf("%c\n", i+'A');													//Print data that having condition
		}
	}
	for(int i=0;i<6;i++){
		if(visit[i])	continue;
		else{																							//If there is non-visited node, do DFS again started from the node.
			for(int i=0;i<6;i++){														//Before starting DFS, clear previous data.
				visitAlpha[i] = 0;
				result[i] = false;
			}
			Push(&stack, i);
			while(!IsSEmpty(&stack)){
				int vtx = SPeek(&stack);
				Pop(&stack);
				if(visit[vtx])	continue;
				else{
					visit[vtx] = true;
					visitAlpha[pgraph->heads[vtx]->data - 'A'] ++;
				}

				cur = pgraph->heads[vtx]->next;
				while(cur != NULL){
					Push(&stack, cur->id);
					cur = cur->next;
				}
			}
			for(int i=0;i<6;i++){
				if(visitAlpha[i] > 1){
					result[i] = true;
				}
			}
			for(int i=0;i<6;i++){
				if(result[i] && !resultAlpha[i]){
					printf("%c\n", i+'A');
				}
			}
		}
	}
}

/* Modify to here */
