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

	// Remove all elements from the heap.
	for (int i = n - 1; i >= 0; i--)
		a[i] = Delete(&heap);

	for (int i = 0; i < n; i++)
		printf("%c%c%c", a[i].large, a[i].middle, a[i].small);
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
	a = malloc(sizeof(char)*(n+1));
	scanf("%s", a);
	data = CreateHexNum(a);
	HeapSort(data, n);
}

/* Modify from here */

/* Modify to here */