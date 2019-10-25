/*
*	FILE			: proto.h
*	PROJECT			: BogoForCharity
*	PROGRAMMER(S)	: Daniel Pieczewski, Aidan Eastcott
*	FIRST VERSION	: 2019-10-8
*	DESCRIPTION		:
*		This header is used to link all functions in the project together
*/

#pragma once

//Function prototypes for bogo.cpp
void fillArray(int*, int);
void bogoSort(int[], int);
int checkIfSorted(int[], int);
void swap(int*, int*);
void shuffle(int[], int);

//Function prototypes for gui.cpp
void printArr(int[], int, int, int);
void printArr(int[], int);
void printArr(int[], int, bool);
void printArr(int[], int, int, int, bool);
int digitAt(int, int);