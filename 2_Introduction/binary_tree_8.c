#include <stdio.h>
#include <stdlib.h>

typedef struct Tree_node{
	int data;
	struct Tree_node* left;
	struct Tree_node* right;
}Node;

void InOrder(Node*root){
	if(root == NULL)	return;
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PreOrder(Node*root){
	if(root != NULL){
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
	else
		return;
}

void PostOrder(Node*root){
	if(root != NULL){
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
	else
		return;
}

Node*Insertion(Node*root, Node*child){
	if(root->data > child->data){
		if(root->left == NULL)
			root -> left = child;
		else
			Insertion(root->left, child);
	}
	else{
		if(root->right == NULL)
			root -> right = child;
		else
			Insertion(root->right, child);
	}
	return NULL;
}

Node* AddNode(int input){
	Node*newnode = (Node*)malloc(sizeof(Node));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = input;
	return newnode;
}

int main(){
	Node*root;
	Node*child;
	root = (Node*)malloc(sizeof(Node));
	child = (Node*)malloc(sizeof(Node));
	int first_input;
	int input;
	child->data = input;
	for(int i=0;i<6;i++){
		if(i){
			scanf("%d", &input);
			child = AddNode(input);
			Insertion(root, child);
		}
		else{
			scanf("%d", &first_input);
			root = AddNode(first_input);
			continue;
		}
	}//insertion end
	free(child);
	printf("InOrder : ");
	InOrder(root);
	printf("\n");
	printf("PreOrder : ");
	PreOrder(root);
	printf("\n");
	printf("PostOrder : ");
	PostOrder(root);
	free(root);
	printf("\n");
	return 0;
}
