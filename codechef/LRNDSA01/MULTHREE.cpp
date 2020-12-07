#include <iostream>
#include <vector>

long long int K, total_sum = 0;
int d0, d1;

void solve_test_case() {
	total_sum = 0;
	std::cin >> K >> d0 >> d1;
	int sum01 = d0 + d1; // initial sum

	if(K == 2) {
		if ((sum01 % 3) == 0) std::cout << "YES\n";
		else std::cout << "NO\n";

		return;
	}

	std::vector<int> cycle = {
		(2 * sum01) % 10,
		(4 * sum01) % 10,
		(8 * sum01) % 10,
		(16 * sum01) % 10
	};
	int cycle_sum = cycle[0] + cycle[1] + cycle[2] + cycle[3];

	total_sum += (sum01 + (sum01 % 10));
	total_sum += cycle_sum*((K-3)/4);

	int rem = (K-3)%4;
	for(int i=0;i<rem;i++) {
		total_sum += cycle[i];
	}

	if(total_sum % 3 == 0) std::cout << "YES\n";
	else std::cout << "NO\n";
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
