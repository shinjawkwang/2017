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

	printf("Selection : %d\n", SelectionSort(list, n));
	//printf("Bubble : %d\n", BubbleSort(list, n));
	//printf("Insertion : %d\n", InsertionSort(list, n));
	//printf("Shell : %d\n", ShellSort(list, n));
	//printf("Quick : %d\n", QuickSort(list, 0, n-1));
	//printf("Merge : %d\n", MergeSort(list, n));

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
		for (int j = i; j < n; j++) {							// Find the position of maximum value in given range [i, n)
			if (COMPARE1(list[j], list[max])) {
				max = j;
			}
		}
		XORSWAP(list[i], list[max]);							// Swap value of i and value of max
	}
	return *cnt;
}

int BubbleSort(int * list, int n) {
	int x = 0, *cnt = &x;
	for (int i = 0; i < n - 1; i++) {
		for (int j = n; j > i; j--) {
			if (COMPARE1(list[j], list[j - 1])) {	// Compare each pare of adjacent items
				XORSWAP(list[j], list[j-1]);					// Swap if they are in wrong order
			}
		}
	}

	return *cnt;
}

int InsertionSort(int * list, int n) {
	int j, key, x = 0, *cnt = &x;
	for (int i = n - 2; i >= 0; i--) {
		key = list[i];														// Choose i-th item
		for (j = i + 1; j < n; j++) {
			if (!COMPARE2(key, list[j])) {					// If j-th item is larger than key
				list[j-1] = list[j];									// Move j-th item to j-1th
			}
			else {
				break;
			}
		}
		list[j - 1] = key;												// After iteration, move key to (j-1)-th position
	}
	return *cnt;
}

void IncInsertionSort(int *list, int first, int last, int k, int *cnt) {	// Sort every k-th item
	int j, key;
	for (int i = first + k; i < last; i += k) {
		key = list[i];																												// Choose i-th item
		for (j = i - k; j >= first && COMPARE1(key, list[j]); j -= k) {				// If key is larger than j-th item
			list[j + k] = list[j];																							// Move j-th item to (j+k)-th item
		}
		list[j + k] = key;
	}
}

int ShellSort(int * list, int n) {
	int cnt = 0;
	for (int k = n / 2; k > 0; k /= 2) {																		// Sort every k-thelement by reducing from n/2 to 1
		if ((k % 2) == 0) {																										// k should be odd
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
		while (low < right && COMPARE1(list[low], pivot)) {
			low++;																							// Move low until list[low] < pivot
		}
		while (high > left && !COMPARE2(list[high], pivot)) {
			high--;																							// Move high until list[high] > pivot
		}
		if (low < high) {
			XORSWAP(list[low], list[high]);											// Swap list[low] & list[high]
		}
		else {
			break;
		}
	}
	XORSWAP(list[left], list[high]);												// Swap list[left] & list[high]
	return high;																						// Return Pivot position to use in QuickSort
}

int QuickSort(int * list, int left, int right) {
	int cnt = 0;
	if (left < right) {
		int mid = Partition(list, left, right, &cnt);
		cnt += QuickSort(list, left, mid - 1);								// All items are bigger than pivot
		cnt += QuickSort(list, mid + 1, right);								// All items are smaller than pivot
	}
	return cnt;
}

void Merge(int *list, int left, int mid, int right, int *cnt) {
	int *sorted = (int*)malloc(sizeof(int)*MAX_SIZE);
	int first = left, second = mid + 1, i = left;

	while (first <= mid && second <= right) {				// Merge Two lists by comparing items in sequence
		if (COMPARE1(list[first], list[second]))
			sorted[i++] = list[first++];
		else
			sorted[i++] = list[second++];
	}

	if (first > mid)																// When there are remained & not sorted items
		for (int j = second; j <= right; j++)
			sorted[i++] = list[j];
	else
		for (int j = first; j <= mid; j++)
			sorted[i++] = list[j];

	for (int j = left; j <= right; j++)							// Copy sorted list into list
		list[j] = sorted[j];

}

int MergeSort(int * list, int n) {
	int cnt = 0;
	for (int size = 1; size <= n - 1; size = 2 * size) {
		for (int left_start = 0; left_start < n - 1; left_start += 2 * size) {	// Pick starting point of different subarrays of current size
			// Find ending point of left subarray.
			int mid = left_start + size - 1;
			int right_end = MIN(left_start + 2 * size - 1, n - 1);

			Merge(list, left_start, mid, right_end, &cnt);												// Merge subarrays
		}
	}

	return cnt;

}



/* Modify to here */
