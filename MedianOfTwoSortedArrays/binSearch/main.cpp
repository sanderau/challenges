#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "helpers.hpp"

int binary_search(int arr[], int length, int search)
/*********************************************************
 * name: binary search
 * description: searches a sorted array for a value
 * Time complexity: log(n)
 * returns: index of requested number, or -1 if not present
 *********************************************************/
{
	bool notFound = true;
	int low = 0, high = length-1, index = -1;

	while(notFound) 
	{
		int mid = low + (high - low) / 2;

		if(arr[mid] > search) {
			
			high = mid;
			mid = mid / 2;		

		} else if (arr[mid] < search) {

			low = mid;
			mid = (mid) + (mid/2);

		} else if (arr[mid] == search) {
			
			index = mid;
			notFound = !(notFound);
		
		}
	}

	return index;
}

void quicksort(int arr[], int low, int high)
/************************************************************
 * name: quick sort 
 * description: quickly sorts.
 * average: n * log(n)
 * worst: n^2
 ************************************************************/
{
	if(low < high)
	{
		int pi = partition(arr, low, high);

		quicksort(arr, low, pi-1);
		quicksort(arr, pi+1, high);
	}
}

int main(int argc, char **argv)
{
	srand(time(NULL));

	int length = rand() % 20 + 1;
	int arr[length];

	load_array(arr, length);

	int search = arr[rand()%length];

	quicksort(arr, 0, length-1);

	print_array(arr, length);

	std::cout << "The value <" << search << "> is located at index: " << binary_search(arr, length, search) << std::endl;

	return 0;
}
