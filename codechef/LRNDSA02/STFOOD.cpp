#include <iostream>
#include <algorithm>

int N, S, P, V, max_profit, possible_profit;

void solve_test_case() {
	max_profit = 0;
	std::cin >> N;
	while(N--) {
		std::cin >> S >> P >> V;
		possible_profit = (P / (S+1)) * V;
		max_profit = std::max(max_profit, possible_profit);
	}
	std::cout << max_profit << "\n";
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
