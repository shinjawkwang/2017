

void randomGen(int *data, int length);
void printData(int *data, int length);

#ifdef SELECTION
void selectionSort(int *data, int length);	
#elif defined BUBBLE
void bubbleSort(int *data, int length);
#elif defined INSERTION	
void insertionSort(int *data, int length);
#elif defined Merge
void mergeSort(int *data, int first, int last);
#elif defined QUICK
void quickSort(int *data, int first, int last);
#elif defined RANDOM-QUICK
void randomquickSort(int *data, int first, int last);
#elif defined COMPARE 
void selectionSort(int *data, int length);
void bubbleSort(int *data, int length);
void insertionSort(int *data, int length);
void mergeSort(int *data, int first, int last);
void quickSort(int *data, int first, int last);
void randomquickSort(int *data, int first, int last);
#endif

