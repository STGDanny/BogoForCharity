/*
*	FILE			: bogo.cpp
*	PROJECT			: BogoForCharity
*	PROGRAMMER		: Daniel Pieczewski
*	FIRST VERSION	: 2019-10-6
*	DESCRIPTION		:
*		The function(s) in this file run an infinite bogoSort on an increasingly large array
*/

#include <stdio.h>
#include <random>
#include <time.h>

//Function prototypes
void fillArray(int*, int, int);
void bogoSort(int[], int);
int checkIfSorted(int[], int);
void swap(int*, int*);
void shuffle(int[], int);

//Driver code for bogo
int main() {
	//Seed random number generator using current time (very random value)
	srand(time(NULL));
	int calculatedTime = 0;

	//Loop will run bogo, increase the size of the array each loop
	for (int sizeOfArray = 2; 1 < 2; sizeOfArray++) {
		//Allocate memory to arr. Equal in size to sizeOfArray * 4 bytes (size of an int in c)
		int* arr = (int*)malloc(sizeOfArray * sizeof(int));
		//Fill allocated memory with random values
		fillArray(&arr[0], sizeOfArray, 1);

		//Only here for feedback to the user
		printf("\nSorting...\n");

		//Start clock and bogo
		clock_t begin = clock();
		bogoSort(arr, sizeOfArray);
		clock_t end = clock();

		//Figure out how long that took
		calculatedTime = (end - begin) / CLOCKS_PER_SEC;

		//Print results
		for (int i = 0; i < sizeOfArray; i++) {
			printf("%d\t", arr[i]);
		}
		printf("\nSorted %d elements in %d seconds\n", sizeOfArray, calculatedTime);
		//Free up memory allocated to arr
		free(arr);
	}
}

/*
*	FUNCTION		: fillArray
*	DESCRIPTION		: Fills each element of an array with pseudo-random values
*
*	PARAMETERS		:
*	int* arr 	    : Memory address of an array
*	int size		: Amount of elements in array arr
*
*	RETURNS			:
*	void			: Void
*/
void fillArray(int* arr, int size, int lower) {
	//For every value in arr[]
	for (int i = 0; i < size; i++) {
		//Set value of current element to a random number (Can't be 0)
		arr[i] = rand() % (size - lower + 1) + lower;
	}
}

/*
*	FUNCTION		: bogoSort
*	DESCRIPTION		: The best / worst sorting algorithm ever conceptualized.
*					  Checks if array is sorted, if not it will shuffle array and check again
*					  until it is sorted
*
*	PARAMETERS		:
*	int arr[] 	    : Array to sort
*	int size 		: Amount of elements in array arr[]
*
*	RETURNS			:
*	void			: Void
*/
void bogoSort(int arr[], int size) {
	//While the array is NOT sorted, shuffle and repeat loop
	while (!checkIfSorted(arr, size)) {
		shuffle(arr, size);
	}
}

/*
*	FUNCTION		: checkIfSorted
*	DESCRIPTION		: Iterates through the list to check if array is sorted
*
*	PARAMETERS		:
*	int arr[]	    : Array to check
*	int size		: Amount of elements in array arr[]
*
*	RETURNS			:
*	int			    : Boolean value, returns 1 if array is sorted, 0 if not
*/
int checkIfSorted(int arr[], int size) {
	//For every element in arr[]
	for (int i = 0; i < size - 1; i++) {
		//If the current element is greater than the element to the right of it,
		//array is NOT sorted, return 0.
		if (arr[i] > arr[i + 1]) {
			return 0;
		}
	}
	//If loop exits without returning 0, array must be sorted, return 1.
	return 1;
}

/*
*	FUNCTION		: swap
*	DESCRIPTION		: Swaps two array elements
*
*	PARAMETERS		:
*	int* xp 	    : Value at the memory address of first element
*	int* yp 		: Value at the memory address of seconds element
*
*	RETURNS			:
*	void			: Void
*/
void swap(int* xp, int* yp) {
	//Create temporary value equal to the first number
	int tmpInt = *xp;
	//Set first number equal to second number
	*xp = *yp;
	//Set second number equal to temporary value
	*yp = tmpInt;
	//Numbers have been swapped
}

/*
*	FUNCTION		: shuffle
*	DESCRIPTION		: Shuffles an array in pseudo-random fashion
*
*	PARAMETERS		:
*	int arr[] 	    : Array to shuffle
*	int size 		: Amount of elements in array arr[]
*
*	RETURNS			:
*	void			: Void
*/
void shuffle(int arr[], int size) {
	//For every element in arr[], starting from the last element
	for (int i = size + 1; i > 0; i--) {
		//Swap current element with a random element in the array
		swap(&i, &arr[rand() % size]);
	}
}