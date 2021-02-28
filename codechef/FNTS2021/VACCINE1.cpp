#include <iostream>
#include <algorithm>

int solve_test_case() {
	int D1, V1, D2, V2, P; std::cin >> D1 >> V1 >> D2 >> V2 >> P;
	if(D1 == D2) {
		if (P % 2 != 0) return ((P / (V1 + V2)) + 1);

	int total_days = std::min(D1, D2) - 1;
	int one_works = (std::max(D1, D2) - std::min(D1, D2));
	total_days += one_works;

	if(D1 <= D2) {
		P = P - one_works * V1;
	} else if(D1 > D2) {
		P = P - one_works * V2;
	}
	
	total_days += ((P / (V1 + V2)) + 1);
	return total_days;	
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout << solve_test_case() << std::endl;
	
	return 0;
}
