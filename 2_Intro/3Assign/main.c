#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "general.h"


int main(int argc, char **argv){

	int length, i, j; // i is a variable for repeating 10 times to compare performances, j is for selecting the algorithm.
	int *data;
	struct timeval start, end;
	double result;
	FILE * stat;
	void (*increments[3])(int*, int), (*div_n_conqs[3])(int*, int, int);



	if(argc < 2){
#if defined SELECTION
		printf("Usage: ./Selection.out NumOfData \n");
#elif defined BUBBLE
		printf("Usage: ./Bubble.out NumOfData \n");
#elif defined INSERTION
		printf("Usage: ./Insertion.out NumOfData \n");
#elif defined MERGE
		printf("Usage: ./Merge.out NumOfData \n");
#elif defined QUICK
		printf("Usage: ./Quick.out NumOfData \n");
#elif defined RANDOM-QUICK
		printf("Usage: ./Random-Quick.out NumOfData \n");
#elif defined COMPARE
		stat = fopen("statistics.txt", "w+");
		data = (int*)malloc(15000);
		increments[0] = selectionSort;
		increments[1] = bubbleSort;
		increments[2] = insertionSort;
		div_n_conqs[0] = mergeSort;
		div_n_conqs[1] = quickSort;
		div_n_conqs[2] = randomquickSort;

		fprintf(stat, "\tSEL\t \tBUB\t \tINS\t \tMER\t \tQUI\t \tRAN-QUI");
		srand(time(NULL));

		for(length = 500; length <= 3000; length += 500){
			printf("Length : %d\n", length);
			fprintf(stat, "\n%d\t", length);
			for (j = 0; j < 3; j ++){
				if(j == 0) 			printf("\tTesting Selection Sort");
				else if (j == 1) 	printf("\tTesting Bubble Sort");
				else 				printf("\tTesting Insertion Sort");
				gettimeofday(&start, NULL);
				for(i = 1; i <= 10; i ++){
					randomGen(data, length);
					(*increments[j])(data, length);
					printf(".");
				}
				printf(" Complete\n");
				gettimeofday(&end, NULL);
				fprintf(stat, "%f\t", ((end.tv_sec + end.tv_usec/1000000.0) - (start.tv_sec + start.tv_usec/1000000.0))/10);
			}
			for (j = 0; j < 3; j ++){
				if(j == 0) 			printf("\tTesting Merge Sort");
				else if (j == 1)	printf("\tTesting Quick Sort");
				else				printf("\tTesting Random Quick Sort");
				gettimeofday(&start, NULL);
				for(i = 1; i <= 10; i ++){
					randomGen(data, length);
					(*div_n_conqs[j])(data, 0, length - 1);
					printf(".");
				}
				printf(" Complete\n");
				gettimeofday(&end, NULL);
				fprintf(stat, "%f\t", ((end.tv_sec + end.tv_usec/1000000.0) - (start.tv_sec + start.tv_usec/1000000.0))/10);
			}
		};
		printf("Check \"statistics.txt\" file.\n");
		free(data);
		fclose(stat);
#endif
		exit(0);
	}

	if((length = atoi( argv[1] )) <= 0 ){

		printf("Input positive value.\n");
		exit(0);

	}


	data = (int*)malloc(sizeof(int)*length);

	srand(time(NULL));
	randomGen(data, length);

	if(argc < 3 || strcmp(argv[2], "-s") != 0){
		printf("Before Sort..\n", length);
		printData(data, length);
	}

	gettimeofday(&start, NULL);

#if defined SELECTION
	selectionSort(data, length);
#elif defined BUBBLE
	bubbleSort(data, length);
#elif defined INSERTION
	insertionSort(data, length);
#elif defined MERGE
	mergeSort(data, 0, length -1);
#elif defined QUICK
	quickSort(data, 0, length -1);
#elif defined RANDOM-QUICK
	randomquickSort(data, 0, length -1);
#endif

	gettimeofday(&end, NULL);

	if(argc < 3 || strcmp(argv[2], "-s") != 0){
		printf("After Sort..\n", length);
		printData(data, length);
	}

	result = (end.tv_sec + end.tv_usec/1000000.0)
				- (start.tv_sec + start.tv_usec/1000000.0);


	printf("Elapsed time : %lf \n", result);
	free(data);

}
