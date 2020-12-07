#include <iostream>

int N;
std::string S;
void solve_test_case() {
	std::cin >> N;
	int A_hits = 0, B_hits = 0;
	int A_left = N, B_left = N;
	std::cin >> S;

	for(int s=0; s<2*N; s++) {
		switch(s % 2) {
			case 0 : if(S[s] == '1') {A_hits++;} A_left--; break;
			case 1 : if(S[s] == '1') {B_hits++;} B_left--; break;
		}
		// std::cout << A_hits << " " << A_left << " " << B_hits << " " << B_left << "\n";
		
		if(A_hits > (B_hits + B_left) || B_hits > (A_hits + A_left)) {
			std::cout << s+1 << "\n";
			return;
		}

		if((A_hits == B_hits) && A_left == 0 && B_left == 0) {
			std::cout << s+1 << "\n";
		}
	}
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
