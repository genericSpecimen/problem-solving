#include <iostream>
#include <utility>
#include <vector>

void solve_test_case() {
	int N; std::cin >> N;
	std::vector<int> sequence(N);
	for(int i=0;i<N;i++) std::cin >> sequence[i];

	// stores nesting depth and index for each depth found
	std::vector<std::pair<int, int>> nesting;
	// stores max number of symbols and their index
	std::vector<std::pair<int, int>> symbols;
	int curr_depth = 0, max_depth = 0;
	int curr_symbols = 0, max_symbols = 0;
	for(int i=0;i<N;i++) {
		if(sequence[i] == 1) {
			curr_depth++;
			if(curr_depth > max_depth) {
				max_depth = curr_depth;
				nesting.push_back(std::make_pair(curr_depth, i));
			}

			curr_symbols++;
		}
		else if(sequence[i] == 2) {
			curr_depth--;
			curr_symbols++;
			if(curr_depth == 0) {
				// a matched bracket sequence has just ended
				if (curr_symbols > max_symbols) {
					max_symbols = curr_symbols;
					// std::cout << "=> " << i << " " << max_depth << std::endl;
					int start_idx = (i+1) - curr_symbols;
					symbols.push_back(std::make_pair(curr_symbols, start_idx));
				}
				curr_symbols = 0;
			}
		}
	}

	std::cout << nesting.back().first << " " << nesting.back().second + 1 << " ";
	std::cout << symbols.back().first << " " << symbols.back().second + 1 << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve_test_case();

	return 0;
}
