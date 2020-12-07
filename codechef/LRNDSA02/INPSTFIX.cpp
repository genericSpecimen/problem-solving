#include <iostream>
#include <stack>

int priority(char c) {
	switch(c) {
		case '^' : return 3; break;
		case '*' :
		case '/' : return 2; break;
		case '+' :
		case '-' : return 1; break;
	}	
	return -1;
}


void solve_test_case() {
	int N; std::cin >> N;
	std::string S; std::cin >> S;
	std::stack<char> i2p;
	for(int i=0;i<N;i++) {
		char c = S[i];
		if (c == '(') {
			i2p.push(c);
			//std::cout << "Pushed: " << c << std::endl;
		}
		else if (c >= 'A' && c <= 'Z') std::cout << c;
		else if (c == ')') {
			// pop and write symbols to output
			// until a '(' is found
			while(!i2p.empty() && i2p.top() != '(') {
				std::cout << i2p.top();
				//std::cout << "Popped: " << i2p.top() << std::endl;
				i2p.pop();
			}
			if(i2p.top() == '(') {
				//std::cout << "Popped: " << c << std::endl;
				i2p.pop(); // discard '('
			}
		}
		else {
			// operator
			while(!i2p.empty() && priority(c) <= priority(i2p.top())) {
				std::cout << i2p.top();
				//std::cout << "Popped: " << c << std::endl;
				i2p.pop();
			}
			//std::cout << "Pushed: " << c << std::endl;
			i2p.push(c);
		}

	}
	
	while(!i2p.empty()) {
		std::cout << i2p.top();
		i2p.pop();
	}
	
	std::cout << "\n";
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
