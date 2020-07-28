#include <iostream> 
#include <vector>
#include <map>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) 
{
	std::vector<std::vector<int>> sols;

	std::map<int, int> map;

	for(int i = 0; i < nums.size(); i++)
	{
		map[nums.at(i)] = i;
	}

	bool notExhausted = true;

	int b = 0, i = b + 1;

	while(notExhausted)
	{
		int val = -(nums.at(b) + nums.at(i));

		if( (map.find(val) != map.end()) && (map[val] != b) && (map[val] != i))
		{
			// a legit combo was found, record it.
			
			std::vector<int> temp;
			temp.insert( temp.end(), {b, i, val} );

			sols.push_back(temp);
		}

		if(i+1 >= nums.size()) {

			//end of list reached
			if(b+1 >= nums.size()) {
				//completely done.
				notExhausted = !(notExhausted);
			} else {
				// iterate the base.
				b++;
				i = b+1;
			}


		} else {
			i++;
		}
	}

	return sols;
}

void print_sols(std::vector<std::vector<int>> sols)
{
	std::cout << "A solution set is:\n[\n";

	for(int i = 0; i < sols.size(); i++)
	{
		std::cout << "\t[ " << sols.at(i).at(0) << ", " << sols.at(i).at(1) << ", " << sols.at(i).at(2) << "]" << std::endl;
	}

	std::cout << "]" << std::endl;
}

int main(int argc, char **argv)
{
	std::vector<int> nums;

	std::vector<std::vector<int>> sols;

	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(-4);

	sols = threeSum(nums);

	print_sols(sols);

	return 0;
}
