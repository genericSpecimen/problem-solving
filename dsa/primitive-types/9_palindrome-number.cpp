#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>

/*
bool isPalindrome(int x) {
	std::string num_str(std::to_string(x));
	std::string rev_str(num_str);
	std::reverse(rev_str.begin(), rev_str.end());
	//std::cout << num_str << "\n";
	if( num_str.compare(rev_str) != 0 ) {
		return false;
	}
	return true;
}
*/

/*
bool isPalindrome(int x) {
	if(x == 0) return true;
	if(x < 0) return false;
	int num_digits = std::floor(std::log10(x)) + 1;
	std::cout << num_digits << std::endl;
	std::stack<int> digits;
	if(num_digits % 2 == 0) {
		// push last num_digits/2 digits into a stack
		// pop corresponding to the first num_digits/2 digits
		for(int i=0; i<num_digits/2; i++) {
			digits.push(x % 10);
			x /= 10;
		}
		for(int i=0; i<num_digits/2;i++) {
			if(x % 10 != digits.top()) {
				return false;
			} else {
				digits.pop();
				x /= 10;
			}
		}
		if(!digits.empty()) return false;
	} else {
		int n = std::floor(num_digits/2);
		for(int i=0;i<n;i++) {
			digits.push(x % 10);
			x /= 10;
		}
		x /= 10; 
		for(int i=0;i<n;i++) {
			if(x % 10 != digits.top()) {
				return false;
			} else {
				digits.pop();
				x /= 10;
			}
		}
		if(!digits.empty()) return false;
	}
	return true;
}
*/

bool isPalindrome(int x) {
	if(x < 0 || x % 10 == 0 && x != 0) return false;

	int rev = 0;
	while(x > rev) {
		rev = rev * 10 + (x % 10);
		x /= 10;
	}
	return (x == rev || x == (rev / 10));
}

int main(int argc, char *argv[]) {
	int num;
	std::cout << std::boolalpha << isPalindrome(std::atoi(argv[1])) << std::endl;
}
