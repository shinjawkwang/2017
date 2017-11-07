#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void randomquickSort(int *data, int first, int last){
	
	if(first < last){
		
		int splitPoint;

		splitPoint = randomsplit(data, first, last);
		randomquickSort(data, first, splitPoint-1);
		randomquickSort(data, splitPoint+1, last);
	}
}

int randomsplit(int *data, int first, int last){
	int splitPoint;
	srand(time(NULL));
	int i = rand()%last;
	/* select a random pivot i */
	int temp = data[i];
	data[i] = data[last];
	data[last] = temp;
	/* exchange data[i] and data[last] */

	splitPoint = split2(data, first, last);

	return splitPoint;
}

int split2(int *data, int first, int last){

	int left;
	int right;
	int splitPoint;
	int splitVal;
	int temp;
	
	left = first + 1;
	right = last;
	splitVal = data[first];

	while(left <= right){
		while(left<=right){
			if(data[left]>splitVal)	break;
			left++;
		}
		while(left <= right){
			if(data[right]<splitVal) break;
			right--;
		}
		if(left < right){
			int temp = data[left];
			data[left] = data[right];
			data[right] = temp;
		}
	}
	splitPoint = right;
	temp = data[first];
	data[first] = data[splitPoint];
	data[splitPoint] = temp;

	return splitPoint;

}
int main(){
	int data[] = { 0, 3, 9, 5, 4, 1, 2, 7, 6, 8 };
	randomquickSort(data, 0, 9);
	for(int i=0;i<10;i++)	printf("%d ", data[i]);
	return 0;
}
