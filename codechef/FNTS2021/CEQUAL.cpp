#include <iostream>
#include <vector>
#include <algorithm>

std::string solve_test_case() {
	int N; std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::sort(A.begin(), A.end());
	for(int i=0;i<N-1;i++) {
		if(A[i] == A[i+1]) return "Yes";
	}
	return "No";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T; std::cin >> T;
	while(T--) {
		std::cout << solve_test_case() << std::endl;
	}
	return 0;
}
