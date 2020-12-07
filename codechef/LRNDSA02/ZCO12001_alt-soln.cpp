#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <limits>

#define INF std::numeric_limits<int>::max()
void solve_test_case() {
	int N;
	std::cin >> N;
	std::vector<int> sequence(N);
	for(int i=0;i<N;i++) std::cin >> sequence[i];

	std::stack<int> b_stack;
	std::vector<int> stack_zero_idx;
	int max_depth = -INF, max_depth_start_idx;
	for(int i=0;i<N;i++) {
		if(sequence[i] == 1) {
			b_stack.push(1);
			if(static_cast<int>(b_stack.size()) > max_depth) {
				max_depth = b_stack.size();
				max_depth_start_idx = i;

			}
		} else if(sequence[i] == 2) {
			b_stack.pop();
			if(b_stack.size() == 0) {
				stack_zero_idx.push_back(i+1);
			}
		}
	}

	int diff, max_symbols = stack_zero_idx[0], max_symbols_start_idx = 0;
	for(int i=1;i<stack_zero_idx.size();i++) {
		diff = stack_zero_idx[i] - stack_zero_idx[i-1];
		if(diff > max_symbols) {
			max_symbols = diff;
			max_symbols_start_idx = stack_zero_idx[i-1];
		}
	}

	std::cout << max_depth << " " << max_depth_start_idx + 1 << " ";
	std::cout << max_symbols << " " << max_symbols_start_idx + 1 << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve_test_case();

	return 0;
}
