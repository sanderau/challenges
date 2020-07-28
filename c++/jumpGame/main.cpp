#include <iostream>
#include <vector>

int jump(std::vector<int> &nums) {
	int jumps = 0;
	int pos = 0;

	if(nums.size() == 1) {
		return 0;
	}
	
	while(1) {
		if( pos + nums.at(pos) >= nums.size() - 1 ) {
			// we can jump to end, do that.
			jumps++;
			return jumps;
		} else {
			// we cannot jump to end, jump to position that gets us most jump.
			int largest_jump = 0;
			int jump_to = 0;
			
			for(int i = pos + 1; i <= pos + nums.at(pos); i++) {
			
				int curr_jump = i + nums.at(i);

				if( curr_jump >= largest_jump ) {
					largest_jump = curr_jump;
					jump_to = i;
				}
	
			}

			jumps++;
			pos = jump_to;
		}

	}
}

int main(int argc, char **argv)
{
	
	std::vector<int> nums;

	nums.push_back(10);
	nums.push_back(9);
	nums.push_back(8);
	nums.push_back(7);
	nums.push_back(6);
	nums.push_back(5);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(0);

	std::cout << jump(nums) << std::endl;

	return 0;
}
