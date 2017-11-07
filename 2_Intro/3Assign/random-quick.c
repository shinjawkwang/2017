

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

	int i = rand() %(last-first+1)+first;
	/* select a random pivot i */
	int temp;
	temp = data[i];
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

	left = first;
	right = last - 1;
	splitVal = data[last];

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
	splitPoint = left;
	temp = data[last];
	data[last] = data[splitPoint];
	data[splitPoint] = temp;

	return splitPoint;

}
