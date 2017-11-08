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
XTreeNode *CreateNode(XData item){
	XTreeNode * newNode = (XTreeNode*)malloc(sizeof(XTreeNode));
	newNode->item = item;
	newNode->left_child = NULL;
	newNode->middle_child = NULL;
	newNode->right_child = NULL;

	return newNode;
}

void DestroyNode(XTreeNode *node){free(node);}

void CreateLeftSubtree(XTreeNode *root, XTreeNode *left){
	if(root->left_child != NULL)	exit(1); // error: there is a existing node.
	root->left_child = left;
}

void CreateMiddleSubtree(XTreeNode *root, XTreeNode *middle){
	if(root->middle_child != NULL)	exit(1); // error: there is a existing node.
	root->middle_child = middle;
}

void CreateRightSubtree(XTreeNode *root, XTreeNode *right){
	if(root->right_child != NULL)	exit(1); // error: there is a existing node.
	root->right_child = right;
}
void preorder(XTreeNode *root){
	if(root != NULL){
		printf("%d ", root->item);
		preorder(root->left_child);
		preorder(root->middle_child);
		preorder(root->right_child);
	}
}

void inorder(XTreeNode *root){
	if(root != NULL){
		inorder(root->left_child);
		printf("%d ", root->item);
		inorder(root->middle_child);
		inorder(root->right_child);
	}
}

void postorder(XTreeNode *root){
	if(root != NULL){
		postorder(root->left_child);
		postorder(root->middle_child);
		postorder(root->right_child);
		printf("%d ", root->item);
	}
}

int countNodes(XTreeNode *root){
	if(root == NULL)	return 0;
	else{
		int left = countNodes(root->left_child);
		int middle = countNodes(root->middle_child);
		int right = countNodes(root->right_child);
		return left + middle + right + 1;							//1 represents root itself.
	}
}

/* Modify to here */
