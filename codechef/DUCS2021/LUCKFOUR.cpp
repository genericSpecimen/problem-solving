#include <iostream>

void solve_test_case() {
	long long int T; std::cin >> T;
	long long int freq = 0;
	while(T > 0) {
		if (T % 10 == 4) freq++;
		T /= 10;
	}
	std::cout << freq << std::endl;

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long int T; std::cin >> T;
	while(T--) {
		solve_test_case();
	}
	return 0;
}
