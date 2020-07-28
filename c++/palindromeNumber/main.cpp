#include <iostream>

using namespace std;


int reverse_num(int x) {

	long int r = 0;

	while( x > 0 ) {

		r *= 10;
		r += x % 10;

		x /= 10;

	}

	return r;

}


bool isPalindrome(int x) {

	/* if number is negative, automatic false */
	if( x < 0 ) {
		return false;
	}
	
	int reversed = reverse_num(x);
	/* if reversed, is equal to normal then it is a palindrome */
	if( x == reversed ) {
	
		return true;
	
	} else {
		/* otherwise it isn't a palindrome */
		return false;

	}
}

int main(int argc, char **argv)
{
	int x = 123;

	cout << x << "\n" << reverse_num(x)  << endl;

	return 0;
}
