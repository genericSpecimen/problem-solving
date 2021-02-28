#include <iostream>


bool jerry_wins(long long int JS, long long int TS) {
	if(JS % 2 == 0 && TS % 2 == 0) {
		// play next turn
		JS /= 2;
		TS /= 2;
		return jerry_wins(JS, TS);
	} else if(JS % 2 != 0 && TS % 2 != 0) {
		// tie
		return false;
	} else if(TS % 2 == 0 && JS % 2 != 0) {
		// tom wins
		return false;
	}
	return true;
}

long long int solve_test_case() {
	long long int TS; std::cin >> TS;
	if(TS % 2 != 0) return ((TS-1)/2);
	else {
		/*
		long long int n = 0;
		for (long long int JS = 2; JS <= TS; JS += 2) {
			if(jerry_wins(JS, TS)) {
				n++;
			}
		}
		*/

		while(TS % 2 == 0) {
			TS /= 2;
		} 
		return (TS / 2);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T; std::cin >> T;
	while(T--) {
		std::cout << solve_test_case() << std::endl;
	}
	return 0;
}
