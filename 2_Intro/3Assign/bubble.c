
void bubbleSort(int *data, int length){

	int firstUnsorted;
	int swapFlag;
	
	firstUnsorted = 0;
	swapFlag = 1;

	while(firstUnsorted<length  && swapFlag){
		
		int index;
		
		index = length -1;
		swapFlag = 0;

		while(index>=firstUnsorted-1){

			int temp;
			if(data[index]<data[index-1]){
				temp = data[index];
				data[index] = data[index-1];
				data[index-1] = temp;
			}
			swapFlag = 1;
			index--;
		}

		firstUnsorted = firstUnsorted + 1;
	}
}
