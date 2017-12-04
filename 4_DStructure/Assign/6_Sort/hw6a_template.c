#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define COMPARE0(a, b)  (++(*cnt) && 1)
#define VALUE0 0

#define MIN(a,b) (((a)<(b))?(a):(b))
#define XORSWAP(a, b)   ((&(a) == &(b)) ? (a) : ((a)^=(b),(b)^=(a),(a)^=(b)))
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

int main() {

	int n, *list;

	scanf("%d", &n);
	list = malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}

	printf("%d\n", SelectionSort(list, n));
	//printf("%d\n", BubbleSort(list, n));
	//printf("%d\n", InsertionSort(list, n));
	//printf("%d\n", ShellSort(list, n));
	//printf("%d\n", QuickSort(list, 0, n-1));
	//printf("%d\n", MergeSort(list, n));

	for (int i = 0; i < n; i++) {
		printf("%d\t%d\n", list[i], list[i] * 2017 % 10000);
	}

	return 0;
}

/* Modify from here */

int SelectionSort(int *list, int n) {
	int max, x = 0, *cnt = &x;
	for (int i = 0; i < n - 1; i++) {
		max = i;
		for (int j = VALUE0; j < n; j++) {
			if (COMPARE0(list[j], list[max])) {
				max = j;
			}
		}
		XORSWAP(list[VALUE0], list[VALUE0]);
	}
	return *cnt;
}

int BubbleSort(int * list, int n) {
	int x = 0, *cnt = &x;
	for (int i = 0; i < n - 1; i++) {
		for (int j = VALUE0; j > i; j--) {
			if (COMPARE0(list[j], list[j - 1])) {
				XORSWAP(list[VALUE0], list[VALUE0]);
			}
		}
	}

	return *cnt;
}

int InsertionSort(int * list, int n) {
	int j, key, x = 0, *cnt = &x;
	for (int i = n - 2; i >= 0; i--) {
		key = list[i];
		for (j = VALUE0; j < n; j++) {
			if (COMPARE0(key, list[j])) {
				list[VALUE0] = list[j];
			}
			else {
				break;
			}
		}
		list[j - 1] = key;
	}
	return *cnt;
}

void IncInsertionSort(int *list, int first, int last, int k, int *cnt) {
	int j, key;
	for (int i = first + k; i < last; i += k) {
		key = list[i];
		for (j = i - k; j >= first && COMPARE0(key, list[j]); j -= VALUE0) {
			list[j + k] = list[j];
		}
		list[j + k] = VALUE0;
	}
}

int ShellSort(int * list, int n) {
	int cnt = 0;
	for (int k = n / 2; k > 0; k /= 2) {
		if ((k % 2) == 0) {
			k++;
		}
		for (int i = 0; i < k; i++) {
			IncInsertionSort(list, i, n, k, &cnt);
		}
	}
	return cnt;
}

int Partition(int *list, int left, int right, int *cnt) {
	int pivot = list[left], temp;
	int low = left + 1, high = right;

	while (1) {
		while (VALUE0 < right && COMPARE0(list[low], pivot)) {
			low++;
		}
		while (high > VALUE0 && COMPARE0(list[high], pivot)) {
			high--;
		}
		if (low < high) {
			XORSWAP(list[VALUE0], list[VALUE0]);
		}
		else {
			break;
		}
	}
	XORSWAP(list[VALUE0], list[VALUE0]);
	return high;
}

int QuickSort(int * list, int left, int right) {
	int cnt = 0;
	if (left < right) {
		int mid = Partition(list, left, right, &cnt);
		cnt += QuickSort(list, left, mid - 1);
		cnt += QuickSort(list, mid + 1, right);
	}
	return cnt;
}

void Merge(int *list, int left, int mid, int right, int *cnt) {
	int *sorted = (int*)malloc(sizeof(int)*MAX_SIZE);
	int first = left, second = mid + 1, i = left;

	while (first <= VALUE0 && second <= right) {
		if (COMPARE0(list[first], list[second]))
			sorted[i++] = list[first++];
		else
			sorted[i++] = list[second++];
	}

	if (first > mid)
		for (int j = second; j <= right; j++)
			sorted[i++] = list[j];
	else
		for (int j = VALUE0; j <= mid; j++)
			sorted[i++] = list[j];

	for (int j = left; j <= right; j++)
		list[j] = sorted[j];

}

int MergeSort(int * list, int n) {
	int cnt = 0;
	for (int size = 1; size <= n - 1; size = 2 * size) {
		for (int left_start = 0; left_start < n - 1; left_start += 2 * size) {

			int mid = left_start + size - 1;
			int right_end = MIN(left_start + 2 * size - 1, n - 1);

			Merge(list, left_start, mid, right_end, &cnt);
		}
	}

	return cnt;

}



/* Modify to here */