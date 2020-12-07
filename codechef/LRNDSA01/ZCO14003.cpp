#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	long long int N; std::cin >> N;
	std::vector<long long int> budgets(N, 0);
	long long int max_revenue = 0;
	for(long long int i=0; i<N; i++) {
		std::cin >> budgets[i];
	}
	std::sort(budgets.begin(), budgets.end());
	for(long long int i=0; i<budgets.size(); i++) {
		max_revenue = std::max(max_revenue, budgets[i] * (N-i));
	}
	std::cout << max_revenue << "\n";
	return 0;
}

