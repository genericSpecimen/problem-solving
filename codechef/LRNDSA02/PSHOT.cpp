#include <iostream>

int N;
std::string S;
void solve_test_case() {
	std::cin >> N;
	std::cin >> S;
	int A_hits = 0, A_misses = 0;
	int B_hits = 0, B_misses = 0;
	int s = 0;
	while(s < 2*N) {
		if(S[s] == '1') {
			A_hits++;
		} else A_misses++;

		//std::cout << A_hits << " " << A_misses << " " << B_hits << " " << B_misses << "\n";
		if( (B_misses >= (N - A_hits + 1)) || (A_misses >= (N - B_hits + 1)) ) {
			std::cout << s+1 << "\n";
			return;
		}
		s++;

		if(S[s] == '1') {
			B_hits++;
		} else B_misses++;
		
		//std::cout << A_hits << " " << A_misses << " " << B_hits << " " << B_misses << "\n";
		if( (B_misses >= (N - A_hits + 1)) || (A_misses >= (N - B_hits + 1)) ) {
			std::cout << s+1 << "\n";
			return;
		}
		s++;
	}
	std::cout << s << "\n";
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
