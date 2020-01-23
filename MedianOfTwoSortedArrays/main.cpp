//libraries
#include <iostream>

//definitions
#define VERBOSE 1 // print the output, or not. Used when measuring Big O.


double findMedianSortedArrays(int *nums1, int *nums2, int m, int n)
{


	return 0;
}

int main(int argc, char *argv[])
{
	double solution = -1;

	int m = 2, n = 2;

	int nums1[m] = {1, 2};
	int nums2[n] = {3, 4};

	solution = findMedianSortedArrays(nums1, nums2, m, n);
	
	if(VERBOSE) {
		std::cout << "The solution is: " << solution << std::endl;
	}
	

	return 0;
}
