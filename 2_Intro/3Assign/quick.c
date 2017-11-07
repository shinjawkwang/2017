

void quickSort(int *data, int first, int last){
	
	if(first < last){
		
		int splitPoint;

		splitPoint = split(data, first, last);
		quickSort(data, first, splitPoint-1);
		quickSort(data, splitPoint+1, last);
	}
}

int split(int *data, int first, int last){

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

