

void insertionSort(int *data, int length){

	int current;

	current = 1;
	while(current < length ){

		int index;
		int placeFound;

		index = current;
		placeFound = 0;

		while(placeFound<current){

			int temp;
			temp = data[current];
			if(data[placeFound]>temp){
				while(index>placeFound){
					data[index] = data[index-1];
					index--;
				}
				data[placeFound] = temp;
				break;
			}
			placeFound++;
		}

		current++;
	
	}

}
