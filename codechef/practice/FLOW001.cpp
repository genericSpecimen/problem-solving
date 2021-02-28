#include <iostream>

void solve_test_case() {
	int A, B;
	std::cin >> A >> B;
	std::cout << A+B << std::endl;
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
