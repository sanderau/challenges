#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> populate_vector(int*, int);
void print_sol(vector<vector<int>>);
void print_vec(vector<int>);
bool set_exists(vector<int>, vector<vector<int>>);

bool set_exists(vector<int> set, vector<vector<int>> list) {

	/*
	* Name: set_exists
	* Description: Given a set of vectors, and a single vector this function will
	 return true if the vector exists in set and false if it does not.
	* Parameters: set to check, and the list of vectors
	* Warnings: None.
	*/

	 sort(set.begin(), set.end());

	for(unsigned int long i = 0; i < list.size(); i++) {
		sort(list.at(i).begin(), list.at(i).end());
		
		if( list.at(i) == set ) {
			return true;
		}
	}

	return false;
}

vector<vector<int>> threeSum(vector<int> &nums) {

	/*
	* name: threeSum
	* Description: Given a vector this function will parse through it,
	 and find all sets where three unique numbers add to 0
	* paramaters: vector<int> - the vector you would like to search
	* Warning: none
	*/
	
	vector<vector<int>> sol;

	for(unsigned int long i = 0; i < nums.size()-2; i++) {

		for(unsigned int long j = i+1; j < nums.size()-1; j++) {

			for(unsigned int long k = j+1; k < nums.size(); k++) {
				if( ( nums.at(i) + nums.at(j) + nums.at(k) ) == 0 ) {
					vector<int> temp;
					temp.push_back(nums.at(i));
					temp.push_back(nums.at(j));
					temp.push_back(nums.at(k));

					if( !(set_exists(temp, sol) ) ) {
						
						sol.push_back(temp);
			
					}
				}
			}
		}
	}

	return sol;
}


vector<int> populate_vector(int* arr, int l) {
	
	/*
	* Name: populate_vector
	* Descriptiion: Will turn given array into a vector
	* Parameters: array, and the length of array
	* Warnings: none
	*/

	vector<int> vec;

	for(int i = 0; i < l; i++) {

		vec.push_back(arr[i]);

	}

	return vec;

}


void print_vec(vector<int> v) {
	
	/*
	* Name: print_vec
	* Description: Given a vector, the function will print the vec.
	* Parameters: the vector you would like to print
	* Warnings: none
	*/

	cout << "[";

	for(unsigned int long i = 0; i < v.size()-1; i++) {

		cout << v.at(i) << ", ";		

	}

	cout << v.at(v.size()-1) << "]" << endl;

}

void print_sol(vector<vector<int>> sol) {

	cout << "[" << endl;
	
	for(unsigned int long i = 0; i < sol.size(); i++) {
		cout << "\t";
		print_vec(sol.at(i));
	}

	cout << "]" << endl;

}

int main(int argc, char **argv)
{

	int arr[6] = {-1, 0, 1, 2, -1, -4};

	vector<int> v = populate_vector(arr, 6);
	
	print_sol(threeSum(v));
	

	return 0;
}
