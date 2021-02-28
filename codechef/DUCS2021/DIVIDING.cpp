#include <iostream>

void solve_test_case() {
	long long int N; std::cin >> N;
	long long int Ci, total = 0;
	for(int i=0;i<N;i++) {
		std::cin >> Ci;
		total += Ci;
	}
	std::cout << ((total == N*(N+1)/2) ? "YES":"NO") << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	solve_test_case();
	return 0;
}
