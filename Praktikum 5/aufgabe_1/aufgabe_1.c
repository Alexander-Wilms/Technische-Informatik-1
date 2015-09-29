// QUICKSORT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

static int array[SIZE];
int curLocation, k;

void quickSort(int array[], int first, int last);
int lessEqualSorted(int array[], size_t length);

int main()
{
	srand( time(NULL)); // Initialize random numbers
	for(k = 0; k < SIZE; k++)
	{
		array[k] = 1 + rand() % 10000; // Fill array with numbers from 1 to 10000
		printf("%3d ", array[k]);
	}
	quickSort(array, 0, SIZE - 1); // Sort the array
	puts("");
	for(k = 0; k < SIZE; k++) // Print the array
	{
		printf("%3d ", array[k]);
	}
	printf("\n LessEqualSorted? %d", lessEqualSorted(array, SIZE)); // Check if the array is sorted
	return (0);
}

void quickSort(int array[], int first, int last)
{
	int partition(int array[], int first, int last);
	if(first < last)
	{
		curLocation = partition(array, first, last);
		quickSort(array, first, curLocation - 1);    // A recursive function
		quickSort(array, curLocation + 1, last);     // Sort each half the same way
	}
}

int partition(int array[], int first, int last) {    // All numbers on the right of the middle number should be bigger
                                                      // and all numbers on the left should be smaller
	int right = first; // Right border
	int left = last -1;// Left Border                             // Search relative to Pivot, don't include Pivot
	int pivot = array[last];
	do {
		while(array[right] <= pivot && right < last) { // Go through the array from left
			right++;                                    // Find the first number from the left that's bigger than Pivot
		}
		while(array[left] >= pivot && left > first) { // Go through the array from right
			left--;                                   // Find the first number from the right that's smaller than Pivot
		}
		if(right < left) { // If the bigger number is in the left half of the array...
		    int tmp = array[right]; // Exchange both numbers
			array[right] = array[left];
			array[left] = tmp;
		}
	}while(right < left); // Until both meet - then all numbers on the left are smaller
                          // and all numbers on the right are bigger

	if(array[right] > pivot) { // Replace pivot and the number in the middle
	    int tmp = array[right];
		array[right] = array[last];
		array[last] = tmp;
	}
	return right; // Partitioning done - middle value is being returned
}

int lessEqualSorted(int array[], size_t length)
{
	int i;
	for(i = 0; i < length -1; i++)
	{
		if(array[i] > array[i+1]) // Check if one element is bigger than the following one
		{
			return 0; // If that's the case the list is not sorted
		}
	}
	return 1; // Otherwise it is sorted
}
