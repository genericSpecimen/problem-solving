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
		//for(int Ci : C) std::cout << Ci << " ";
		
		// cooking time elapsed on burner 1 and 2
		int t_b1 = 0, t_b2 = 0;
		for(int Ci : C) {
			// this only works because of the specified constraints
			if(t_b1 < t_b2) {
				// burner 1 is free; use it
				t_b1 += Ci;
			} else {
				t_b2 += Ci;
			}
		}

		std::cout << std::max(t_b1, t_b2) << "\n";
	}
	return 0;
}
