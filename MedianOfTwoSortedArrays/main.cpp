//libraries
#include <iostream>
#include <vector>

//definitions
#define VERBOSE 1 // print the output, or not. Used when measuring Big O.


double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
	double median = 0;

	return median;
}

void fillVec(std::vector<int> &vec, int arr[], int length) {
	for(int i = 0; i < length; i++)
	{
		vec.push_back(arr[i]);
	}
}

int main(int argc, char *argv[])
{
	int arr1[2] = {1,2};
	int arr2[2] = {3,4};

	std::vector<int> nums1, nums2;	
	fillVec(nums1, arr1, 2);
	fillVec(nums2, arr2, 2);

	std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;

	return 0;
}
