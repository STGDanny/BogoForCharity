/*
*	FILE			: gui.cpp
*	PROJECT			: BogoForCharity
*	PROGRAMMER(S)	: Daniel Pieczewski, Aidan Eastcott
*	FIRST VERSION	: 2019-10-8
*	DESCRIPTION		:
*		The function(s) in this file run the GUI portion of an infinite bogoSort on an increasingly large array
*/

#include <stdlib.h>
#include <stdio.h>
#include "proto.h"

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
	printArr(arr, size, -1, -1, false);
}

void printArr(int arr[], int size, bool clearScreen) {
	printArr(arr, size, -1, -1, clearScreen);
}

void printArr(int arr[], int size, int a, int b) {
	printArr(arr, size, a, b, false);
}

void printArr(int arr[], int size, int a, int b, bool clearScreen) {
	const char CHAR_DEFAULT_BAR = 219;
	const char CHAR_SWAP_BAR = 219;
	const char CHAR_BLANK = ' ';
	const char CHAR_NEW_LINE = '\n';

	const char CHAR_LEFT = 192;
	const char CHAR_RIGHT = 217;
	const char CHAR_MID = 196;
	const char CHAR_VERTICAL_LINE = 179;

	//	do not make these less than 1
	const int BAR_HEIGHT_MULTIPLE = 1;
	const int BAR_WIDTH = 2;
	const int BAR_SPACE_WIDTH = 2;
	const int BOTTOM_LINE_HEIGHT = 2;

	//	do not modify below this point
	const int FULL_WIDTH = BAR_WIDTH + BAR_SPACE_WIDTH;

	int maxElement = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > maxElement) {
			maxElement = arr[i];
		}
	}

	int strSize = ((FULL_WIDTH * size) * (BAR_HEIGHT_MULTIPLE * maxElement))
		+ ((FULL_WIDTH * size) * BOTTOM_LINE_HEIGHT)
		+ (FULL_WIDTH * size)
		+ ((BAR_HEIGHT_MULTIPLE * size) + BOTTOM_LINE_HEIGHT + 1) + 1;

	char* str = (char*)malloc(strSize * sizeof(char));
	int count = 0;

	for (int i = size - 1; i >= 0; i--) {
		for (int k = 0; k < BAR_HEIGHT_MULTIPLE; k++) {
			for (int j = 0; j < size; j++) {
				if (arr[j] > i) {
					if (j == a || j == b) {
						for (int x = 0; x < BAR_WIDTH; x++) {
							//printf("%c", CHAR_SWAP_BAR);
							str[count++] = CHAR_SWAP_BAR;
						}
						for (int x = 0; x < BAR_SPACE_WIDTH; x++) {
							//printf("%c", CHAR_BLANK);
							str[count++] = CHAR_BLANK;
						}
					}
					else {
						for (int x = 0; x < BAR_WIDTH; x++) {
							//printf("%c", CHAR_DEFAULT_BAR);
							str[count++] = CHAR_DEFAULT_BAR;
						}
						for (int x = 0; x < BAR_SPACE_WIDTH; x++) {
							//printf("%c", CHAR_BLANK);
							str[count++] = CHAR_BLANK;
						}
					}
				}
				else {
					for (int x = 0; x < FULL_WIDTH; x++) {
						//printf("%c", CHAR_BLANK);
						str[count++] = CHAR_BLANK;
					}
				}
			}
			//printf("\n");
			str[count++] = CHAR_NEW_LINE;
		}
	}

	if (a >= 0 && b >= 0 && a != b) {
		if (b > a) {
			int temp = a;
			a = b;
			b = temp;
		}

		if (BOTTOM_LINE_HEIGHT > 1) {
			for (int k = 1; k < BOTTOM_LINE_HEIGHT; k++) {
				for (int i = 0; i < size; i++) {
					if (i == b) {
						//printf("%c", CHAR_VERTICAL_LINE);
						str[count++] = CHAR_VERTICAL_LINE;
						for (int x = 0; x < BAR_WIDTH - 1; x++) {
							//printf("%c", CHAR_BLANK);
							str[count++] = CHAR_BLANK;
						}
					}
					else if (i == a) {
						for (int x = 0; x < FULL_WIDTH - 1; x++) {
							//printf("%c", CHAR_BLANK);
							str[count++] = CHAR_BLANK;
						}
						//printf("%c", CHAR_VERTICAL_LINE);
						str[count++] = CHAR_VERTICAL_LINE;
						for (int x = 0; x < BAR_SPACE_WIDTH; x++) {
							//printf("%c", CHAR_MID);
							str[count++] = CHAR_BLANK;
						}
					}
					else {
						for (int x = 0; x < FULL_WIDTH; x++) {
							//printf("%c", CHAR_BLANK);
							str[count++] = CHAR_BLANK;
						}
					}
				}
			}

			//printf("\n");
			str[count++] = CHAR_NEW_LINE;
		}

		for (int i = 0; i < size; i++) {
			if (i == b) {
				//printf("%c", CHAR_LEFT);
				str[count++] = CHAR_LEFT;
				for (int x = 0; x < BAR_WIDTH - 1; x++) {
					//printf("%c", CHAR_MID);
					str[count++] = CHAR_MID;
				}
			}
			else if (i == a) {
				for (int x = 0; x < FULL_WIDTH - 1; x++) {
					//printf("%c", CHAR_MID);
					str[count++] = CHAR_MID;
				}
				//printf("%c", CHAR_RIGHT);
				str[count++] = CHAR_RIGHT;
				for (int x = 0; x < BAR_SPACE_WIDTH; x++) {
					//printf("%c", CHAR_MID);
					str[count++] = CHAR_BLANK;
				}
			}
			else if (i > b&& i < a) {
				for (int x = 0; x < FULL_WIDTH; x++) {
					//printf("%c", CHAR_MID);
					str[count++] = CHAR_MID;
				}
			}
			else {
				for (int x = 0; x < FULL_WIDTH; x++) {
					//printf("%c", CHAR_BLANK);
					str[count++] = CHAR_BLANK;
				}
			}
		}

		//printf("\n");
		str[count++] = CHAR_NEW_LINE;
	}
	else {
		for (int i = 0; i < BOTTOM_LINE_HEIGHT; i++) {
			for (int m = 0; m < FULL_WIDTH * size; m++) {
				str[count++] = CHAR_BLANK;
			}
			str[count++] = CHAR_NEW_LINE;
		}
	}

	for (int i = 0; i < size; i++) {
		//printf("%-*d", BAR_WIDTH, arr[i]);
		int isNumber = 0;
		for (int m = 0; m < BAR_WIDTH; m++) {
			if (digitAt(arr[i], BAR_WIDTH - m) != 0 || isNumber) {
				str[count++] = ((char)digitAt(arr[i], BAR_WIDTH - m)) + 48;
				isNumber = 1;
			}
			else {
				str[count++] = CHAR_BLANK;
			}
		}
		for (int m = 0; m < BAR_SPACE_WIDTH; m++) {
			//printf("%c", CHAR_BLANK);
			str[count++] = CHAR_BLANK;
		}
	}

	//printf("\n");
	str[count++] = CHAR_NEW_LINE;
	str[count++] = '\0';

	if (clearScreen) {
		system("cls");
	}
	printf("%s", str);

	free(str);
}

int digitAt(int num, int index) {
	int base = 1;
	for (int i = 1; i < index; i++) {
		base *= 10;
	}

	int result = num / base;
	result = result % 10;

	return result;
}