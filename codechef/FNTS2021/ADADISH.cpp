#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int T, N, Ci;
	std::vector<int> C;
	std::cin >> T;
	while(T--) {
		std::cin >> N;
		C.clear();
		while(N--) {
			std::cin >> Ci;
			C.push_back(Ci);
		}
		
		std::sort(C.rbegin(), C.rend());
		
		int t_b1 = 0, t_b2 = 0;
		for(int Ci : C) {
			if(t_b1 < t_b2) {
				t_b1 += Ci;
			} else {
				t_b2 += Ci;
			}
		}

		std::cout << std::max(t_b1, t_b2) << "\n";
	}
	return 0;
}
