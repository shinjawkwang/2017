#include <iostream>
#include <ctime>

#define SIZE 30
using namespace std;

void selectionSort(int arr[], int size);

void swap(int& v1, int& v2);
int indexOfSmallest(const int arr[], int startIndex, int size);
int main() {
  cout << "This is Selection Sort Program.\n";
  srand((unsigned int)time(NULL));
  int arr[SIZE];
  for (int i = 0; i < SIZE; i++){
    arr[i] = rand() % 100 + 1;
  }

  for (int i = 0; i < SIZE; i++){
    // Before Sort
    cout << arr[i] << " ";
  }
  cout << endl;
  selectionSort(arr, SIZE);
  for(int i = 0; i < SIZE; i++){
    // After Sort
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}

void selectionSort(int arr[], int size) {
  int indexOfNextSmallest;
  for (int i = 0; i < size - 1; i++) {
    indexOfNextSmallest = indexOfSmallest(arr, i, size);
    swap(arr[i], arr[indexOfNextSmallest]);
  }
}

void swap(int& v1, int&v2) {
  int temp;
  temp = v1;
  v1 = v2;
  v2 = temp;
}

int indexOfSmallest(const int arr[], int startIndex, int size) {
  int minPos = startIndex;
	for(int i=startIndex;i<size;i++){
	 	if(arr[i] <= arr[minPos])	minPos = i;
	 }
	return minPos;
}
