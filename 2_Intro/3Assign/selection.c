

selectionSort(int *data, int length){

	int firstUnsorted;

	firstUnsorted = 0;
	while(firstUnsorted<length){

		int indexOfSmallest;
		int index;
		int temp;		

		indexOfSmallest = firstUnsorted;
		index = firstUnsorted + 1;
		
		for(int i=index;i<length;i++){
			if(data[i]<data[indexOfSmallest])
				indexOfSmallest = i;
		}

		temp = data[firstUnsorted];
		data[firstUnsorted] = data[indexOfSmallest];
		data[indexOfSmallest] = temp;

		firstUnsorted = firstUnsorted + 1;
	
	}

}
