void merge (int* data, int first, int middle, int last);

void mergeSort(int *data, int first, int last){
	int middle = 0;

	if(first < last){
		
		middle = (first + last) / 2;

		mergeSort(data, first, middle);
		mergeSort(data, middle+1, last);
		merge(data, first, middle, last);
	}
}

void merge(int *data, int first, int middle, int last){
	int k = first, l = middle+1 ,*result;
	result = (int*)malloc((last-first+1)*sizeof(int));
	for(int i=0;i<=last-first;i++){
		if(data[k]<data[l])	result[i] = data[k++];
		else				result[i] = data[l++];
	}
	for(int i=0;i<=last-first;i++)	data[i+first] = result[i];
	free(result);
}

