#include <stdio.h>
#include <stdlib.h>


void randomGen(int *data, int length){

	int i;
	for(i = 0; i < length; i++){

		data[i] = rand()%20000;

	}
}


void printData(int *data, int length){

	int i;
	for(i = 0; i < length; i++){
	
		if(i != 0 && i % 10 == 0){ 
			printf("\n");
		}
		
		printf("%5d ", data[i]);//0x%xd 
	}

	printf("\n");
}



