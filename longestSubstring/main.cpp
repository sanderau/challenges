#include <iostream>

void reset_list(int arr[]) {
	for(int i = 0; i < 127; i++) {
		arr[i] = 0;
	}
}

int lengthOfLongestSubstring(std::string s) {
	int current = 0;
	int longest = 0;
	int start_of_streak = 0;

	int mylist[127];
	reset_list(mylist);
	
	for(int i = 0; i < s.length(); i++) {
		
		if(mylist[s.at(i)]) {
			longest = (longest > current) ? longest : current;
			current = 0;
			
			reset_list(mylist);
			
			start_of_streak++;
			i = start_of_streak;
		} 
		mylist[s.at(i)] = 1;
		current++;
		
	}

	longest = (longest > current) ? longest : current;

	return longest;
}

int main(int argc, char **argv) {
	std::string input = "bbbbb";
	std::cout << "Input: " << input << std::endl;

	std::cout << "Output: " << lengthOfLongestSubstring(input) << std::endl;

	return 0 ;
}
