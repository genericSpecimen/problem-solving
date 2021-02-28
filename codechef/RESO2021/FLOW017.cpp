#include <iostream>
#include <algorithm>
#include <vector>

void solve_test_case() {
	std::vector<int> V(3, 0);
	std::cin >> V[0] >> V[1] >> V[2];
	std::sort(V.begin(), V.end());
	std::cout << V[1] << std::endl;
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
