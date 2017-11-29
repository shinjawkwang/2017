#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_HEAP 100

typedef enum { false, true } bool;

typedef struct {
	char small;
	char middle;
	char large;
} Hex_num;

typedef struct {
	Hex_num data; // This is a priority as well as data
} HNode;

typedef struct {
	HNode items[MAX_HEAP + 1];
	int num;
} Heap;

void InitHeap(Heap *pheap);

bool IsEmpty(Heap *pheap);

bool IsFull(Heap *pheap);

void Insert(Heap *pheap, Hex_num data);

Hex_num Delete(Heap *pheap);

void HeapSort(Hex_num a[], int n);

Hex_num *CreateHexNum(char str[]);

void GetInput();

int main() {

	Hex_num a[5] = { {'0','F','0'},{'1','2','3'},{'F','F','F'},{ 'C','C','C' },{ '0','D','3' } }; // 0F0321FFFCCC3D0
	HeapSort(a, 5);

	// GetInput();
	/*
	5
	0F0321FFFCCC3D0
	*/

	return 0;
}

void HeapSort(Hex_num a[], int n) {
	Heap heap;
	InitHeap(&heap);

	// Insert all elements to the heap.
	for (int i = 0; i < n; i++)
		Insert(&heap, a[i]);
	for (int i = 1; i <= n; i++)
		printf("%c%c%c ", heap.items[i].data.large, heap.items[i].data.middle, heap.items[i].data.small);
	printf("\n");
	// Remove all elements from the heap.
	for (int i = n - 1; i >= 0; i--)
		a[i] = Delete(&heap);

	for (int i = 0; i < n; i++)
		printf("%c%c%c ", a[i].large, a[i].middle, a[i].small);
}

Hex_num *CreateHexNum(char str[]) {
	int n = strlen(str) / 3;
	Hex_num *res = (Hex_num*)malloc(sizeof(Hex_num)*(n));
	for (int i = 0; i < n; i++) {
		res[i].large = str[i * 3];
		res[i].middle = str[i * 3 + 1];
		res[i].small = str[i * 3 + 2];
	}
	return res;
}

void GetInput() {
	int n;
	char *a;
	Hex_num *data;

	scanf("%d", &n);
	a = malloc(sizeof(char)* (3*n+1));
	scanf("%s", a);
	data = CreateHexNum(a);
	HeapSort(data, n);
}

/* Modify from here */
void InitHeap(Heap *pheap){pheap->num = 0;}															//Initialize heap by making pheap->num 0.

bool IsEmpty(Heap *pheap){return pheap->num == 0;}											//If phaep->num == 0, the heap is empty, so return true. Else, return false.

bool IsFull(Heap *pheap){return pheap->num == MAX_HEAP;}								//If phaep->num == MAX_HEAP, the heap is full, so return true. Else, return false.

int GetParent(int idx){return idx/2;}																		//Return a parent index for a given index.
int GetLChild(int idx){return idx*2;}																		//Return a Left Child index for a given index.
int GetRChild(int idx){return idx*2+1;}																	//Return a parent index for a given index.

bool CompareHex(Hex_num a, Hex_num b){																	//If a is bigger than b, return true.
	if(a.large > b.large)							return true;
	else{
		if(a.large < b.large)						return false;
		else{
			if(a.middle > b.middle)				return true;
			else{
				if(a.middle < b.middle)			return false;
				else												return a.small > b.small;
			}
		}
	}
}
int GetHighPriorityChild(Heap *pheap, int idx){													//To get index of child that has larger value.
	if(GetLChild(idx) > pheap->num){																			//There doesn't any child.
		return 0;
	}
	else if(GetLChild(idx) == pheap->num){																//There doen't any other child.
		return GetLChild(idx);
	}
	else{
		int left = GetLChild(idx), right = GetRChild(idx);
		if(CompareHex(pheap->items[left].data, pheap->items[right].data)){
			return right;
		}
		else{
			return left;
		}
	}
}

void Insert(Heap *pheap, Hex_num data){
	HNode newNode;
	if(IsFull(pheap))	exit(1);																						//Exit program when the heap is full.
	int idx = pheap->num + 1;
	while(idx > 1){																												//Quit iteration when idx become the top of heap.
		int parent = GetParent(idx);																				//Get parent of index node.
		if(CompareHex(pheap->items[parent].data, data)){										//If item in parent node if larger than item in index node.
			pheap->items[idx] = pheap->items[parent];													//Change item at index to item parent.
			idx = parent;
		}
		else break;
	}
	newNode.data = data;
	pheap->items[idx] = newNode;
	pheap->num++;
}

Hex_num Delete(Heap *pheap){																						//
	Hex_num min = pheap->items[1].data;
	if(IsEmpty(pheap))	exit(1);																					//
	Hex_num last = pheap->items[pheap->num].data;
	int parent = 1, child;
	while((child = GetHighPriorityChild(pheap, parent))){
		if(CompareHex(last, pheap->items[child].data)){
			pheap->items[parent].data = pheap->items[child].data;
			parent = child;
		}
		else break;
	}
	pheap->items[parent].data = last;
	pheap->num --;

	return min;
}


/* Modify to here */
