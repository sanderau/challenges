#include <iostream>
#include <vector>

int maxArea(std::vector<int> &height) {
	int largest = 0, current = 0;
	
	for(int i = 0; i < height.size(); i++)
	{
		for(int j = i + 1; j < height.size(); j++)
		{
			int localHeight = (height.at(i) <= height.at(j)) ? height.at(i) : height.at(j);
			int localWidth = j - i;
		
			current = localHeight*localWidth;
			std::cout << i << ", " << j << ": " << current << std::endl;
			largest = (current > largest) ? current : largest;
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
	int arr[7] = {2,3,4,5,18,17,6};

	std::vector<int> height;
	fillVector(height, arr, 7);

	std::cout << maxArea(height) << std::endl;

	return 0;
}
