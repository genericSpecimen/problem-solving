#include <iostream>
#include <stack>
void solve_test_case() {	
	// angled brackets stack
	std::stack<int> ab_stack;
	std::string s;
	std::cin >> s;
	char c;
	int last_valid_index = -1;
	for(int i=0;i<s.size();i++) {
		c = s[i];
		if(c == '<') {
			ab_stack.push(c);
		} else if(c == '>') {
			if(!ab_stack.empty()) {
				ab_stack.pop();
				if(ab_stack.empty()) last_valid_index = i;
			} else break;
		}
	}
	std::cout << last_valid_index + 1 << "\n";
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
