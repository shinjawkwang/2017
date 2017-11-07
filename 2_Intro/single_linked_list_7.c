#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

typedef struct _node{
  int data;
  struct _node* next;
} Node;

Node head;

void add (Node* head, int data) {
  Node* new = (Node*)malloc(sizeof(Node));
  while(head -> next) head = head -> next;
  head -> next = new;
  new -> data = data;
  new -> next = NULL;
}

#ifdef DEBUG
void printList (Node* head) {
  while(head -> next){
    printf("%d - ", head -> data);
    head = head -> next;
  }
  printf("%d\n", head -> data);
}
#endif

void delete(Node* head){
  while(head -> next -> next) head = head -> next;
  free(head -> next);
  head -> next = NULL;
}

int main(){
  int n, input, save;

  scanf("%d", &n);
  save = n;
  for( ;n;n--){
    scanf("%d", &input);
    add(&head, input);
    #ifdef DEBUG
    printList(&head);
    #endif
  }
  for( ;save;save--){
    delete(&head);
    #ifdef DEBUG
    printList(&head);
    #endif
  }

  return 0;
}
