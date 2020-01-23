#include <iostream>

#include "helpers.hpp"

void swap(int *a, int *b)
{
	int t = *a;
	
	*a = *b;
	*b = t;
}

void print_array(int arr[], int length)
// just prints the array bro
{
	std::cout << "{";	

	for(int i = 0; i < length; i++)
	{
		if(i == length-1) {
			std::cout << arr[i] << "}" << std::endl;
		} else {
			std::cout << arr[i] << ", ";
		}
	}
}

void load_array(int arr[], int length)
{
	for(int i = 0; i < length; i++)
	{
		arr[i] = rand()%100 + 1;
	}
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for(int j = low; j <= high - 1; j++)
	{
		if(arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i+1], &arr[high]);
	return (i+1);
}


