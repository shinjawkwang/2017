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
	
	DFS(&g);	
	BFS(&g);

	DestroyGraph(&g);

}

/* Modify from here */

/* Modify to here */
