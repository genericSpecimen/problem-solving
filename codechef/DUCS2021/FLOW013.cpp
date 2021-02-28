#include <iostream>

void solve_test_case() {
	int A, B, C; std::cin >> A >> B >> C;
	std::cout << ((A + B + C == 180) ? "YES":"NO") << std::endl;
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
