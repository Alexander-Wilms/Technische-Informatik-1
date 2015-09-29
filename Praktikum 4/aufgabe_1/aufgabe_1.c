// BUBBLE-SORT AND SELECTION-SORT

#include <stdio.h>
#include <time.h>
#define SIZE 5
typedef int bool; // Create a boolean type
#define true 1
#define false 0

// Prototypes
void resetList(int list[]);
void bubbleSort(int list[], size_t length);
void selectionSort(int list[], size_t length);
bool lessEqualSorted(int list[], size_t length);
void printArray(int list[]);
bool sorted = false;

int main( void )
{
    srand( time(NULL));
	int list[SIZE];
	resetList(list);     // Make the array unsorted
	printf("\n" "Sorted: "); if(lessEqualSorted(list, SIZE)) puts("true"); else puts("false"); // Check if sorted
	//bubbleSort(list, SIZE);   // Choose between bubbleSort and selectionSort
	selectionSort(list, SIZE);
	printf("\n" "Sorted: "); if(lessEqualSorted(list, SIZE)) puts("true"); else puts("false"); // Check if sorted
	return 0;
}

void resetList(int list[])
{
	int i;
	for(i = 1; i <= SIZE; i++) // Random number sequence
	{
		list[i-1] = 1 + rand() % 5;
	}
}

void bubbleSort(int list[], size_t length)
{
	int i, counter = 0;
	bool done = false;
	int tmp;

	while(!done) {                                      // As long as it's not sorted
		done = true;                                    // Assume the array is sorted
		for(i = 0; i < length; i++) {                   // Go through the whole array
			if(list[i] > list[i+1] && (i+1) < SIZE) {   // The current and the following number need to be exchanged & And dont access fields outside the array
				tmp = list[i];                          // Exchange the two numbers
				list[i] = list[i+1];
				list[i+1] = tmp;
				}
		}
		done = lessEqualSorted(list, SIZE);             //Check if the Array is already sorted
	}
}

void selectionSort(int list[], size_t length)
{
	int j, i, smallestInt, tmp, position;
	for(j=0; j < length; j++) {                         // Decrease the size of the remaining part
		smallestInt = list[j];                          // Assume that the first entry in the remaining part is the smallest int
		position = -1;
		for(i = j; i < length; i++) {                   // Go through the  remaining part
			if(list[i] < smallestInt) {                 // Check if one element is smaller than the first one of the remaining part
				smallestInt = list[i];
				position = i;                           // Save the position of the smallest int
			}
		}
		if(position != -1) {                             // If there's been at least one smaller element...
			tmp = list[j];                               // ... exchange them
			list[j] = smallestInt;
			list[position]= tmp;
		}
	}
}

//////////   Helper functions   ////////////////////

bool lessEqualSorted(int list[], size_t length) {
	int i;
	for(i = 0; i < length -1; i++) {
		if(list[i] > list[i+1]) {                       // Check if one element is bigger than the following one
			return false;                               // If that's the case the list is not sorted
		}
	}
	return true;                                        // Otherwise it is sorted
}

void printArray(int list[]) {
	int j;
	for(j = 0; j < SIZE; j++) {                         // Print each element of an integer array
		printf("%d ", list[j]);
	}
}
