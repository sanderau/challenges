#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int> &nums, int target) 
{
	std::vector<int> solutions;
	bool noSolution = true;

	int b = 0, i = 1;

	while(noSolution)
	{
		if(nums.at(b) + nums.at(i) == target) {
			//solution found
			solutions.push_back(b);
			solutions.push_back(i);
			
			noSolution = !(noSolution);
		} else {
			//solution not found, iterate through possible permutations.
			if(i+1 >= nums.size()) {
				//reached end of set with current base. Iterate base, and start over.
				b++;
				i = b+1;
			} else {
				// iterate the i value
				i++;
			}
		}
	}

	return solutions;
}

int main(int argc, char** argv)
{
	std::vector<int> nums;

	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	int target = 9;

	std::vector<int> sol = twoSum(nums, target);

	std::cout << "The solution to the set is: (" << sol.at(0) << ", " << sol.at(1) << ")." << std::endl;
	
	return 0;
}
