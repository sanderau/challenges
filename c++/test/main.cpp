#include <iostream>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

bool overflow(int x) {
	long int t = x;

	if(t*10 > INT_MAX || t*-10 < INT_MIN) {
		return true;
	} else {
		return false;
	}
}

int reverse(int x) {
	bool negative = false;
	int ans = 0;
        
	if(x < 0) {
		if(x <= INT_MIN) {
			return 0;
		}

		negative = true;
        	x *= -1;
	}

	while(x >= 10){
		if(overflow(ans)) {
			return 0;
		} else {
			ans *= 10;
		}
		
	
		ans += x % 10;
		x /= 10;
	}
	
	if(overflow(ans)) {
			std::cout << ans << std::endl;
			return 0;
		} else {
			ans *= 10;
		}

	ans += x % 10;

	if(negative) {
		ans *= -1;
	}
	
	return ans;
}

int main(int argc, char **argv) {
	std::cout << reverse(1463847412) << std::endl;

	return 0;
}
