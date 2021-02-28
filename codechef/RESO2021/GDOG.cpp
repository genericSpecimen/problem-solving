#include <iostream>
#include <algorithm>

void solve_test_case() {
	int N, K; std::cin >> N >> K;
	int max_coins = 0;
	for(int i=1;i<=K;i++) {
		max_coins = std::max(max_coins, N % i);
	}
	std::cout << max_coins << std::endl;

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
