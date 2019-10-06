#include <stdio.h>
#include <random>
#include <time.h>

//Function prototypes
void fillArray(int*, int);
void bogoSort(int[], int);
int checkIfSorted(int[], int);
void swap(int*, int*);
void shuffle(int[], int);

//Driver code for bogo
int main() {
	int calculatedTime = 0;

	for (int sizeOfArray = 2; 1 < 2; sizeOfArray++) {
		int* arr = (int*)malloc(sizeOfArray * sizeof(int));
		fillArray(&arr[0], sizeOfArray);
		printf("\nSorting...\n");
		clock_t begin = clock();
		bogoSort(arr, sizeOfArray);
		clock_t end = clock();
		calculatedTime = (end - begin) / CLOCKS_PER_SEC;
		for (int j = 0; j < sizeOfArray; j++) {
			printf("%d\t", arr[j]);
		}
		printf("\nSorted %d elements in %d seconds\n", sizeOfArray, calculatedTime);
	}
	/*for (int i = 0; i < sizeOfArray; i++) {
		int* arr = (int*)malloc(sizeOfArray * sizeof(int));

		//int* arr = (int*)realloc(arr, sizeOfArray * sizeof(int));
		fillArray(&arr[0], sizeOfArray);
		clock_t begin = clock();
		bogoSort(arr, sizeOfArray);
		clock_t end = clock();
		calculatedTime = (begin - end) / CLOCKS_PER_SEC;
		printf("Sorted %d elements in %d seconds", sizeOfArray, calculatedTime);
		free(arr);
	}*/
}

//Helper function to fill the array with unique random numbers
void fillArray(int* arr, int size) {
	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (size * 2);
	}
}

//Where all the magic happens
void bogoSort(int arr[], int size) {
	while (!checkIfSorted(arr, size)) {
		shuffle(arr, size);
	}
}

//Helper function to check if the array is sorted
int checkIfSorted(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return 0;
		}
	}
	return 1;
}

//Swap helper function
void swap(int* xp, int* yp) {
	int tmpInt = *xp;
	*xp = *yp;
	*yp = tmpInt;
}

//Shuffle helper function
void shuffle(int arr[], int size) {
	srand(time(NULL));

	for (int i = size + 1; i > 0; i--) {
		swap(&i, &arr[rand() % size]);
	}
}