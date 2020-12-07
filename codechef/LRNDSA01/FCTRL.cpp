#include <iostream>

int num_trailing_zeros(int n) {
	int ntz = 0;

	while(n > 0) {
		ntz += (n / 5);
		n /= 5;
	}
	return ntz;
}

int main() {
	int T; std::cin >> T;
	int N;
	while(T--) {
		std::cin >> N;
		std::cout << num_trailing_zeros(N) << "\n";
	}
	return 0;
}
