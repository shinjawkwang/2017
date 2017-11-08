#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int XData;

typedef struct _xTreeNode {
	XData item;
	struct _xTreeNode *left_child;
	struct _xTreeNode *middle_child;
	struct _xTreeNode *right_child;
} XTreeNode;

XTreeNode *CreateNode(XData item);

void DestroyNode(XTreeNode *node);

void CreateLeftSubtree(XTreeNode *root, XTreeNode *left);

void CreateMiddleSubtree(XTreeNode *root, XTreeNode *middle);

void CreateRightSubtree(XTreeNode *root, XTreeNode *right);

void PrintTreeNode(XTreeNode *node);

void Tester();

void preorder(XTreeNode *root);

void inorder(XTreeNode *root);

void postorder(XTreeNode *root);

int countNodes(XTreeNode *root);

int main() {
	XTreeNode *node1 = CreateNode(1);
	XTreeNode *node2 = CreateNode(2);
	XTreeNode *node3 = CreateNode(3);
	XTreeNode *node4 = CreateNode(4);
	XTreeNode *node5 = CreateNode(5);
	XTreeNode *node6 = CreateNode(6);
	XTreeNode *node7 = CreateNode(7);

	CreateLeftSubtree(node1, node2);
	CreateMiddleSubtree(node1, node3);
	CreateRightSubtree(node1, node4);

	CreateLeftSubtree(node2, node5);
	CreateMiddleSubtree(node2, node6);

	CreateLeftSubtree(node3, node7);

	PrintTreeNode(node1);
	PrintTreeNode(node2);
	PrintTreeNode(node3);
	PrintTreeNode(node4);
	PrintTreeNode(node5);
	PrintTreeNode(node6);
	PrintTreeNode(node7);

	preorder(node1);
    printf("\n");
    inorder(node1);
    printf("\n");
    postorder(node1);
    printf("\n");
    printf("%d\n", countNodes(node1));

	DestroyNode(node1);
	DestroyNode(node2);
	DestroyNode(node3);
	DestroyNode(node4);
	DestroyNode(node5);
	DestroyNode(node6);
	DestroyNode(node7);

	// Tester();
	/*
		7
		6
		l 1 2
		m 1 3
		r 1 4
		l 2 5
		m 2 6
		l 3 7
	*/
	return 0;
}

void Tester() {
	int n, m, root, child;
	char type;
	XTreeNode **Array;

	scanf("%d", &n);
	Array = (XTreeNode**)malloc(sizeof(XTreeNode*)*n);
	for (int i = 0; i < n; i++)
		Array[i] = CreateNode(i + 1);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		while(getchar()!='\n'); // = fflush(stdin) = __fpurge(stdin)
		scanf("%c %d %d", &type, &root, &child);
		if (type == 'l') CreateLeftSubtree(Array[root - 1], Array[child - 1]);
		else if (type == 'm') CreateMiddleSubtree(Array[root - 1], Array[child - 1]);
		else if (type == 'r') CreateRightSubtree(Array[root - 1], Array[child - 1]);
		else exit(1);
	}

    preorder(Array[0]);
    printf("\n");
    inorder(Array[0]);
    printf("\n");
    postorder(Array[0]);
    printf("\n");
    printf("%d\n", countNodes(Array[0]));

	for (int i = 0; i < n; i++)
		DestroyNode(Array[i]);

	free(Array);
}

void PrintTreeNode(XTreeNode *node) {
	printf("%d: ", node->item);
	node->left_child == NULL ? printf("null ") : printf("%d ", node->left_child->item);
	node->middle_child == NULL ? printf("null ") : printf("%d ", node->middle_child->item);
	node->right_child == NULL ? printf("null\n") : printf("%d\n", node->right_child->item);
}

/* Modify from here */
XTreeNode *CreateNode(XData item){																//Create new node
	XTreeNode * newNode = (XTreeNode*)malloc(sizeof(XTreeNode));		//Allocate new node
	newNode->item = item;																						//Push item to node
	newNode->left_child = NULL;																			//
	newNode->middle_child = NULL;																		//Node is single,
	newNode->right_child = NULL;																		//so left, middle, right child should be NULL

	return newNode;
}

void DestroyNode(XTreeNode *node){free(node);}										//Delete input node

void CreateLeftSubtree(XTreeNode *root, XTreeNode *left){
	if(root->left_child != NULL)	exit(1); 													//Error: there is a existing node.
	root->left_child = left;																				//Allocate 'left' node to left_child of 'root' node
}
void CreateMiddleSubtree(XTreeNode *root, XTreeNode *middle){
	if(root->middle_child != NULL)	exit(1); 												//Error: there is a existing node.
	root->middle_child = middle;																		//Allocate 'middle' node to middle_child of 'root' node
}
void CreateRightSubtree(XTreeNode *root, XTreeNode *right){
	if(root->right_child != NULL)	exit(1); 													//Error: there is a existing node.
	root->right_child = right;																			//Allocate 'right' node to right_child of 'root' node
}


void preorder(XTreeNode *root){
	if(root != NULL){																								//if root is NULL, end recursion
		printf("%d ", root->item);																		//First, print item of root Node (C)
		preorder(root->left_child);																		//Second, execute preorder function again with left_child of root (L)
		preorder(root->middle_child);																	//Third, execute preorder function again with middle_child of root (M)
		preorder(root->right_child);																	//Forth, execute preorder function again with right_child of root (R)
	}
}

void inorder(XTreeNode *root){
	if(root != NULL){																								//if root is NULL, end recursion
		inorder(root->left_child);																		//First, execute inorder function with left_child of root (L)
		printf("%d ", root->item);																		//Second, print item of root Node (C)
		inorder(root->middle_child);																	//Third, execute inorder function again with middle_child of root (M)
		inorder(root->right_child);																		//Forth, execute inorder function again with right_child of root (R)
	}
}

void postorder(XTreeNode *root){
	if(root != NULL){																								//if root is NULL, end recursion
		postorder(root->left_child);																	//First, execute postorder function with left_child of root (L)
		postorder(root->middle_child);																//Second, execute postorder function again with middle_child of root (M)
		postorder(root->right_child);																	//Third, execute postorder function again with right_child of root (R)
		printf("%d ", root->item);																		//Forth, print item of root Node (C)
	}
}

int countNodes(XTreeNode *root){
	if(root == NULL)	return 0;
	else{
		int left = countNodes(root->left_child);											//Count children nodes of left_child
		int middle = countNodes(root->middle_child);									//Count children nodes of middle_child
		int right = countNodes(root->right_child);										//Count children nodes of right_child
		return left + middle + right + 1;															//including root itself, return sum of counted children nodes + 1
	}
}

/* Modify to here */
