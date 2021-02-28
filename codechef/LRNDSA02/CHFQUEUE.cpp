#include <iostream>
#include <stack>
#include <vector>
#include <utility>

#define MOD 1000000007

void solve_test_case() {
	int N, K; std::cin >> N >> K;
	std::vector<int> A(N+1); // A[0] is meaningless
	for(int i=1;i<=N;i++) std::cin >> A[i];

	// this stack will contain records (seniority and index) of chefs processed
	std::stack< std::pair<int,int> > chef_st;
	// push the chef at the front
	chef_st.push(std::make_pair(A[N], N));

	long long int total_fearfulness = 1;
	// start from the second chef in the queue
	for(int j=N-1;j>=1;j--) {
		// the seniority of the chef in stack is > current chef
		// so chef j can't delegate the job
		while(!chef_st.empty() && chef_st.top().first >= A[j]) {
			chef_st.pop();	
		}
		if(!chef_st.empty()) {
			// there exists a chef with seniority less than chef j and now
			// that chef is on the top of the stack
			int idx = chef_st.top().second;
			total_fearfulness = ((total_fearfulness % MOD) * ((idx-j+1) % MOD)) % MOD;
		}
		// push the current chef so that they can be considered for the chefs at the behind
		chef_st.push(std::make_pair(A[j], j));
	}
	std::cout << total_fearfulness << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve_test_case();

	return 0;
}

