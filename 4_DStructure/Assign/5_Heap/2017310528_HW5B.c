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

void PrintGraph(Graph *pgraph);

void DFS(Graph *pgraph);

void BFS(Graph *pgraph);

void GetInput();

int main() {

	Graph g;
	CreateGraph(&g, 5, "ABCFC");
	AddEdge(&g, 0, 1);
	AddEdge(&g, 0, 2);
	AddEdge(&g, 0, 4);
	AddEdge(&g, 1, 2);
	AddEdge(&g, 2, 3);
	AddEdge(&g, 2, 4);
	AddEdge(&g, 3, 4);

	PrintGraph(&g);

	DFS(&g);
	BFS(&g);

	DestroyGraph(&g);

	// GetInput();
	/*
	5 7
	ABCFC
	0 1
	0 2
	0 4
	1 2
	2 3
	2 4
	3 4
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
	PrintGraph(&g);

	//DFS(&g);
	//BFS(&g);

	DestroyGraph(&g);

}

/* Modify from here */
void CreateGraph(Graph *pgraph, int num, char data[]){
	pgraph->num = num;
	pgraph->heads = (GNode **)malloc(sizeof(GNode*) * num);
	for(int i=0;i<num;i++){
		pgraph->heads[i] = (GNode *)malloc(sizeof(GNode));
		pgraph->heads[i]->id = i;
		pgraph->heads[i]->data = data[i];
		pgraph->heads[i]->next = NULL;
	}
}

void DestroyGraph(Graph *pgraph){
	for(int i = 0; i < pgraph->num; i++){
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

	newNode1 = (GNode *)malloc(sizeof(GNode));
	newNode1->id = dest;
	newNode1->data = pgraph->heads[dest]->data;
	newNode1->next = NULL;
	cur = pgraph->heads[src];
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = newNode1;

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

void PrintGraph(Graph *pgraph){
	GNode *cur;
	for(int i=0;i<pgraph->num;i++){
		for(cur = pgraph->heads[i];cur != NULL;cur = cur->next){//(1, B) -> (0, A) -> (2, C)
			if(cur->next != NULL){
				printf("(%d, %c) -> ", cur->id, cur->data);
			}
			else{
				printf("(%d, %c)", cur->id, cur->data);
			}
		}
		printf("\n");
	}
}

void DFS(Graph *pgraph){
	Stack stack;
	GNode *cur;
	bool *visit;
	int visitAlpha[6] = {0, };
	visit = (bool *)malloc(sizeof(bool) * pgraph->num);
	for(int i=0;i<pgraph->num;i++){
		visit[i] = false;
	}
	InitStack(&stack);
	Push(&stack, 0);

	while(!IsSEmpty(&stack)){
		int vtx = SPeek(&stack);
		Pop(&stack);
		if(visit[vtx])	continue;
		else{
			visit[vtx] = true;
			printf("%d ", vtx);
			visitAlpha[pgraph->heads[vtx]->data - 'A'] ++;
		}

		cur = pgraph->heads[vtx]->next;
		while(cur != NULL){
			Push(&stack, cur->id);
			cur = cur->next;
		}
	}
	printf("\n");
	for(int i=0;i<6;i++){
		printf("%c: %d\n", i+'A', visitAlpha[i]);
	}
}

void BFS(Graph *pgraph){
	Queue queue;
	GNode *cur;
	bool *visit;
	int visitAlpha[6] = {0, };
	visit = (bool *)malloc(sizeof(bool) * pgraph->num);
	for(int i=0;i<pgraph->num;i++){
		visit[i] = false;
	}
	InitQueue(&queue);
	EnQueue(&queue, 0);

	while(!IsQEmpty(&queue)){
		int vtx = QPeek(&queue);
		DeQueue(&queue);
		if(visit[vtx])	continue;
		else{
			visit[vtx] = true;
			printf("%d ", vtx);
			visitAlpha[pgraph->heads[vtx]->data - 'A'] ++;
		}

		cur = pgraph->heads[vtx]->next;
		while(cur != NULL){
			EnQueue(&queue, cur->id);
			cur = cur->next;
		}
	}
	printf("\n");
	for(int i=0;i<6;i++){
		printf("%c: %d\n", i+'A', visitAlpha[i]);
	}
}

/* Modify to here */
