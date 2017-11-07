#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct {
	char small;
	char large;
} Hex_num;

typedef struct _Node
{
	Hex_num hex;
	struct _Node* next;
} Node;

typedef struct
{
	Node* head;
	int len;
} LinkedList;

void InitList(LinkedList* plist);
int IsEmpty(LinkedList* plist);
void Insert(LinkedList* plist, Hex_num data);
void MergeTwoList(LinkedList* plist_a, LinkedList* plist_b, LinkedList* plist_c);
void PrintList(LinkedList* plist);

int main() {
    int i,j;
    int cnt;
    char input[3];
    Hex_num hex;
    LinkedList list_a,list_b,list_c;

    InitList(&list_a);
    InitList(&list_b);
    InitList(&list_c);

    for(i=0; i<2; i++)
    {
        scanf("%d",&cnt);
        for(j=0; j<cnt; j++)
        {
            scanf("%s",input);
            hex.large = input[0];
            hex.small = input[1];
            if(i == 0)
                Insert(&list_a,hex);
            else
                Insert(&list_b,hex);
        }
    }
    MergeTwoList(&list_a,&list_b, &list_c);

    PrintList(&list_a);
    PrintList(&list_b);
    PrintList(&list_c);

	return 0;
}

void PrintList(LinkedList* plist)
{
    Node* cur;
	for (cur = plist->head->next; cur != NULL; cur = cur->next)
		printf("%c%c ", cur->hex.large, cur->hex.small);
    printf("\n");
}

/* Modify from here */
void InitList(LinkedList* plist){
	plist->head = (Node *)malloc(sizeof(Node)); 										//allocate new Node, the head of the LinkedList.
	plist->head->next = NULL;																				//because there is only a dummy Node, head.
	plist->len = 0;																									//because there are no data.
}
int IsEmpty(LinkedList* plist) {
  return plist->len == 0;																					//when there are no data at LinkedList, the variable len will be 0.
}
bool compareHex(Hex_num a, Hex_num b){
	if(a.large>b.large)					return true;												//1.when large digit is bigger, the digit must be bigger than the other.
	else if(a.large == b.large)	return a.small >= b.small;					//2.when large digit is same, we have to compare the small digit.
	else												return false;												//same as 1.
}

void Insert(LinkedList* plist, Hex_num data){
	int pos = 0;																										//the variable pos represent the position where the data should be in.
	Node *cur, *inserting;																					//the Node inserting represent the Node that data is in.
	inserting = (Node *)malloc(sizeof(Node));												//1.allocate inserting.
	inserting->hex = data;																					//2.input data to inserting.
	if(IsEmpty(plist)){
		plist->head->next = inserting;																//when plist is empty, inserting will be the first Node('next' of head).
		inserting->next = NULL;																				//because there are only one Node, inserting, 'next' of inserting will be NULL.
	}
	else{
		cur = plist->head;																						//cur represents the position of data that we are comparing inserting's data.
		while(cur->next != NULL && compareHex(data, cur->next->hex)){	//to find position of inserting . . .
			pos++;																											//pos will be added until meeting a data that is bigger than inserting's data.
			cur = cur->next;																						//current Node will be moved to next Node when a loop is over.
		}
		cur = plist->head;																						//in this time, cur find the position where inserting Node should be in.
    for (int i = 0; i < pos; i++)
        cur = cur->next;
    inserting->next = cur->next;																	//the inserting Node is inserted to right position.
    cur->next = inserting;
	}
	plist->len++;																										//the length of the LinkedList is added by 1.
}
void MergeTwoList(LinkedList* plist_a, LinkedList* plist_b, LinkedList* plist_c){
	Node *cur;
	//merge a and b maintaning sorted
	for(cur = plist_a->head->next; cur != NULL; cur = cur->next)		//insert every Nodes in LinkedList a into LinkedList c.
		Insert(plist_c, cur->hex);
	for(cur = plist_b->head->next; cur != NULL; cur = cur->next)		//insert every Nodes in LinkedList b into LinkedList c. Every elements are auotomatically sorted.
		Insert(plist_c, cur->hex);
}
/* Modify to here */
