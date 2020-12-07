#include <iostream>
#include <algorithm>
#include <vector>

void solve_test_case() {
	int N, K; std::cin >> N >> K;
	std::vector<int> A(N);
	for(int i=0;i<N;i++) {
		std::cin >> A[i];
	}

	// track the frequencies of each type of flavour in a subsegment
	std::vector<int> freq(K+1, 0); // freq[0] won't be used

	// track the currently selected number of flavours
	int flavours_selected = 0;
	int max_valid_length = 0;
	for(int L=0, R=0; R < N;) {
		if(freq[A[R]] == 0) {
			// a new flavour has been selected
			flavours_selected++;
		}
		freq[A[R]]++;
		if(flavours_selected < K) {
			max_valid_length = std::max(max_valid_length, R-L+1);
		}
		while(flavours_selected == K) {
			// since more than K-1 flavours have
			// been selected, we need to remove
			// one flavour. We start from the left (L).
			freq[A[L]]--;
			if(freq[A[L]] == 0) {
				// a flavour has been dropped
				flavours_selected--;
			}
			// increment left pointer to indicate that the cake has been dropped
			L++;
		}
		// check if we can add the next cake R to the mix
		R++;
	}
	std::cout << max_valid_length << "\n";

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
