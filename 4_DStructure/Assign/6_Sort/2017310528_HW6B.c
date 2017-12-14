#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define XORSWAP(a, b)   ((&(a) == &(b)) ? (a) : ((a)^=(b),(b)^=(a),(a)^=(b)))
#define COMPARE0(a, b)  (++(*cnt) && 1)
#define COMPARE1(a, b)	(++(*cnt) && (a*2017)%10000 > (b*2017)%10000)
#define COMPARE2(a, b)	(++(*cnt) && (a*2017)%10000 >= (b*2017)%10000)
#define MAX_SIZE 1000000

int SelectionSort(int *list, int n);

int BubbleSort(int *list, int n);

int InsertionSort(int *list, int n);

void IncInsertionSort(int *list, int first, int last, int k, int *cnt);

int ShellSort(int *list, int n);

int Partition(int *list, int left, int right, int *cnt);

int QuickSort(int *list, int left, int right);

void Merge(int *list, int left, int mid, int right, int *cnt);

int MergeSort(int *list, int n);

int Solution(int *list, int n, int *cnt);

int main() {

	int n, *list, *read, cnt = 0;

	scanf("%d", &n);
	list = malloc(sizeof(int)*n);
	read = malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
		read[i] = list[i];
	}

	switch (Solution(read, n, &cnt)) {
	case 0:
		cnt += SelectionSort(list, n);
		break;
	case 1:
		cnt += BubbleSort(list, n);
		break;
	case 2:
		cnt += InsertionSort(list, n);
		break;
	case 3:
		cnt += ShellSort(list, n);
		break;
	case 4:
		cnt += QuickSort(list, 0, n - 1);
		break;
	case 5:
		cnt += MergeSort(list, n);
		break;
	default:
		break;
	}
	printf("%d\n", cnt);

	for (int i = 0; i < n; i++) {
		printf("%d\t%d\n", list[i], list[i] * 2017 % 10000);
	}

	return 0;
}

int Solution(int *list, int n, int *cnt) {
/* Modify from here */
/* Based on Staticstical Reason, I decided to make result only of MergeSort. */
return 5;
/* Modify to here */
}
