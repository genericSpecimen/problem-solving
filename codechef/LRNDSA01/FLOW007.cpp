#include <iostream>

int reverse_integer(int num) {
	int reversed_num = 0, rem = 0;

	while(num > 0) {
		rem = num % 10;
		num /= 10;
		reversed_num = reversed_num*10 + rem;
	}

	return reversed_num;
}

int main() {
	int T, N;
	std::cin >> T;
	while(T--) {
		std::cin >> N;
		std::cout << reverse_integer(N) << "\n";
	}
	return 0;
}
