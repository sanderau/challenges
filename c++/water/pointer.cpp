#include <iostream>
#include <vector>

int maxArea(std::vector<int> &height) {
	int largest = 0, current = 0;
	int left = 0, right = height.size() - 1;
	
	while(right - left > 0) {

		int localHeight = (height.at(left) < height.at(right)) ? height.at(left) : height.at(right);
		int localWidth = right - left;

		current = localHeight * localWidth;
		largest = (current > largest) ? current : largest;


		if(localHeight == height.at(left)){
			left++;
		} else {
			right--;
		}
	}
	
	return largest;
}

void fillVector(std::vector<int> &height, int arr[], int length) {

	for(int i = 0; i < length; i++)
	{
		height.push_back(arr[i]);
	}

}

int main(int argc, char **argv)
{
	int arr[7] = {2, 3, 4, 5, 18, 17, 6};

	std::vector<int> height;
	fillVector(height, arr, 7);

	std::cout << maxArea(height) << std::endl;

	return 0;
}
