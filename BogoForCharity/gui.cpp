#include <stdio.h>
#include "proto.h"

//Author : Aidan Eastcott
/*
*	FUNCTION		: printArr
*	DESCRIPTION		: Handles the GUI for bogoSort()
*
*	PARAMETERS		:
*	int arr[] 	    : Array to shuffle
*	int size 		: Amount of elements in array arr[]
*
*	RETURNS			:
*	void			: Void
*/
void printArr(int arr[], int size) {
	printArr(arr, size, -1, -1);
}
void printArr(int arr[], int size, int a, int b) {
	const char CHAR_DEFAULT_BAR = 219;
	const char CHAR_SWAP_BAR = 219;

	const char CHAR_LEFT1 = 192;
	const char CHAR_LEFT2 = 196;
	const char CHAR_RIGHT1 = 217;
	const char CHAR_RIGHT2 = 196;
	const char CHAR_MID = 196;

	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < size; j++) {
			if (arr[j] > i) {
				if (j == a || j == b) {
					printf("%c%c  ", CHAR_SWAP_BAR, CHAR_SWAP_BAR);
				}
				else {
					printf("%c%c  ", CHAR_DEFAULT_BAR, CHAR_DEFAULT_BAR);
				}
			}
			else {
				printf("    ");
			}
		}
		printf("\n");
	}

	if (a >= 0 && b >= 0 && a != b) {
		if (b > a) {
			swap(&a, &b);
		}

		for (int i = 0; i < a + 1; i++) {
			if (i == b) {
				printf("%c%c%c%c", CHAR_LEFT1, CHAR_LEFT2, CHAR_MID, CHAR_MID);
			}
			else if (i == a) {
				printf("%c%c  ", CHAR_RIGHT2, CHAR_RIGHT1);
			}
			else if (i > b&& i < a) {
				printf("%c%c%c%c", CHAR_MID, CHAR_MID, CHAR_MID, CHAR_MID);
			}
			else {
				printf("    ");
			}
		}

		printf("\n");
	}
	else {
		printf("\n");
	}

	for (int i = 0; i < size; i++) {
		printf("%02d  ", arr[i]);
	}

	printf("\n");
}