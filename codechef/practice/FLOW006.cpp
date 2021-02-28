#include <iostream>

void solve_test_case() {
	int N; std::cin >> N;

	int rem, sum = 0;
	while(N > 0) {
		rem = N % 10;
		sum += rem;
		N /= 10;
	}
	std::cout << sum << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T; std::cin >> T;
	while(T--) {
		solve_test_case();
	}
	return 0;
}
