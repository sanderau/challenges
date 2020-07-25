#include <iostream>
#include <vector>
#include <string>

using namespace std;

string get_letters(string digit) {

	if( digit == "2" ) {
		return "abc";
	} else if ( digit == "3" ) {
		return "def";
	} else if ( digit == "4" ) {
		return "ghi";
	} else if ( digit == "5" ) {
		return "jkl";
	} else if ( digit == "6" ) {
		return "mno";
	} else if ( digit == "7" ) {
		return "pqrs";
	} else if ( digit == "8" ) {
		return "tuv";
	} else if ( digit == "9" ) {
		return "wxyz";
	}
	
	return "-1";
}

vector<string> output;

void backtrack(string combo, string next_digits) {

	if(next_digits.length() == 0) {

		//there are no more digits, therefore this is a valid permutation to be added.
		output.push_back(combo);

	} else {

		//find the next branch.

		//get the list of letters for the current digit.
		string digit = next_digits.substr(0,1);
		string letters = get_letters(digit);

		for(int i = 0; i < letters.size(); i++) {
			//grab the current letter in the list.
			string letter = letters.substr(i,1);
			//add the letter to the combination, and return the remaining digits
			//so the algorithm can complete the logical binary tree.
			backtrack(combo + letter, next_digits.substr(1, next_digits.size()-1));
		}

	}
}

vector<string> letterCombinations(string digits) {

	if( output.size() != 0 ) {
		output.clear();
	}

	if( digits.size() != 0 ) {
		backtrack("", digits);
	}

	return output;
	
}

void print_output() {

	/* prints whatever is inside output */

	cout << "[";

	for(int i = 0; i < output.size()-2; i++) {
		cout << "\"" << output.at(i) << "\", "; 
	}

	cout << "\"" << output.at(output.size()-1) << "\"]" << endl;

}

int main(int argc, char **argv)
{
	letterCombinations("23");
	print_output();

	return 0;
}
