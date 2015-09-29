#include <stdio.h>
#include <time.h>
#define SIZE 5
typedef int bool; // Create a boolean type
#define true 1
#define false 0

void resetList(int list[]);
void bubbleSort(int list[], size_t length);
void selectionSort(int list[], size_t length);
bool lessEqualSorted(int list[], size_t length);
void printArray(int list[]);
bool sorted = false;

int main( void )
{
	//srand( time(NULL) ); // Seed random
	int list[SIZE];
	resetList(list);     // Make the array unsorted
	printArray(list);
	printf("\n" "Sorted: "); if(lessEqualSorted(list, SIZE)) puts("true"); else puts("false"); //Check if sorted
	//bubbleSort(list, SIZE);   // Choose between bubbleSort and selectionSort
	selectionSort(list, SIZE);
	printf("\n" "Sorted: "); if(lessEqualSorted(list, SIZE)) puts("true"); else puts("false"); //Check if sorted
	printf("\n" "Sorted Array: ");
	printArray(list);
	puts("");
	return 0;
}

void resetList(int list[])
{
	int i;
	for(i = 1; i <= SIZE; i++) // Random number sequence
	{
		list[i-1] = 1 + rand() % SIZE;
	}
}

void bubbleSort(int list[], size_t length)
{
	int i, counter = 0;
	bool done = false;
	int tmp;

	while(!done) { // As long as it's not sorted
		done = true; // Assume the array is sorted
		for(i = 0; i < length; i++) { // Go through the whole array
			if(list[i] > list[i+1] && (i+1) < SIZE) { // The current and the following number need to be exchanged
                                                      // And dont access fields outside the array
				tmp = list[i]; // Exchange the two numbers
				list[i] = list[i+1];
				list[i+1] = tmp;
				//done = false; // Go through the whole array if there's been at least one instance of a false order
			} else if ((list[i] <= list[i+1]) && (i+1) < SIZE) { // Both numbers are in the correct order
				printArray(list);                                // And don't access fields outside the array
				printf(" | i = %d: %d <= %d \n", i, list[i], list[i+1]);
			}
		}
		printArray(list);
		puts("");
		done = lessEqualSorted(list, SIZE); //Check if the Array is already sorted
		printf("Done: %d \n", done);
	}
}

void selectionSort(int list[], size_t length)
{
	int j, i, smallestInt, tmp, counter;
	for(j=0; j < length; j++) { // Decrease the size of the remaining part
		smallestInt = list[j]; // Assume that the first entry in the remaining part is the smallest int
		counter = 0;
		printf("\n" "Smallest Integer so far: %d \n", smallestInt);
		for(i = j; i < length; i++) { // Go through the  remaining part
			if(list[i] < smallestInt) { // Check if one element is smaller than the first one of the remaining part
				smallestInt = list[i];
				counter = i; // Save the position of first occurrence of the smallest int
				printf("Smallest Integer so far: %d \n", smallestInt);
			}
		}
		puts("");
		if(counter >= 1) { // If there's been at least one smaller element...
			tmp = list[j]; // ... exchange them
			list[j] = smallestInt;
			list[counter]= tmp;
		}
		printArray(list);
	}
}

bool lessEqualSorted(int list[], size_t length) {
	int i;
	for(i = 0; i < length -1; i++) {
		if(list[i] > list[i+1]) { // Check if one element is bigger than the following one
			return false; // If that's the case the list is not sorted
		}
	}
	return true; // Otherwise it is sorted
}

void printArray(int list[]) {
	int j;
	for(j = 0; j < SIZE; j++) { // Print each element of an integer array
		printf("%d ", list[j]);
	}
}
