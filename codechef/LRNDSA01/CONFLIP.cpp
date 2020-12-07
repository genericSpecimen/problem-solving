#include <iostream>
#include <vector>
/*
 // O(N) solution works but results in TLE 
int count_HorT_after_flips(int I, int N, int Q) {
	std::vector<int> coins(N, I);
	std::vector<int> counts_HT(2, 0);

	// if N is even, start i from 1, otherwise 0
	int i = (N%2 == 0) ? 1 : 0;
	// std::cout << "i: " << i << "\n";
	for(; i<N; i+=2) {
		// flip 1 to 0 and 0 to 1
		coins[i] = 1 - coins[i];
	}

	for(auto c : coins) {
		counts_HT[c]++;
	}
	return counts_HT[Q];
}
*/

// O(1) solution
int count_HorT_after_flips(int I, int N, int Q) {
	if(N % 2 == 0) {
		// same number of alternating H and T (int(N/2))
		return N/2;
	} else {
		if(I == Q) {
			// initial config has 1 less count at the end
			return N/2;
		} else {
			return N/2 + 1;
		}
	}
}

int main() {
	int T; std::cin >> T;
	int G, I, N, Q;
	while(T--) {
		std::cin >> G;
		while(G--) {
			std::cin >> I >> N >> Q;
			// I--; Q--; // for easier 0 1 notation
			std::cout << count_HorT_after_flips(I, N, Q) << "\n";
		}
	}
	return 0;
}
