#include <iostream>
#include <vector>
#include <limits>

#define INF std::numeric_limits<int>::max()

void solve_test_case() {
	int N; std::cin >> N;
	std::vector<long long int> S(N, 0);
	long long int max_num_tokens = 0;
	for(int i=0;i<N;i++) {
		std::cin >> S[i];
	}

	long long int possible_tokens = INF;
	for(int i=0;i<N;i++) {
		if(S[i] <= possible_tokens) {
			possible_tokens = S[i];
			max_num_tokens += possible_tokens;
		} else {
			max_num_tokens += possible_tokens;
		}
	}
	std::cout << max_num_tokens << "\n";
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
