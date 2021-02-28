#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <limits>

#define INF std::numeric_limits<int>::max();

void solve_test_case() {
	int N, X, Y; std::cin >> N >> X >> Y;
	std::vector< std::pair<int, int> > contests(N);
	int S, E;
	for(int i=0;i<N;i++) {
		std::cin >> S >> E;
		contests[i] = std::make_pair(S, E);
	}
	std::vector<int> V(X), W(Y);

	for(int i=0;i<X;i++) std::cin >> V[i];
	std::sort(V.begin(), V.end());

	for(int i=0;i<Y;i++) std::cin >> W[i];
	std::sort(W.begin(), W.end());

	std::vector<int>::iterator latest_arrival_time, earliest_leaving_time;
	int t, min_time = INF;
	for(int i=0;i<N;i++) {
		S = contests[i].first; E = contests[i].second;
		// find the latest arrival time for start time
		latest_arrival_time = std::upper_bound(V.begin(), V.end(), S);
		latest_arrival_time--; // decrement the iterator since the "upper" bound was found

		earliest_leaving_time = std::lower_bound(W.begin(), W.end(), E);

		/*
		std::cout << "----- Contest " << i << " -------" << std::endl;
		std::cout << "S = " << S << ", E = " << E << std::endl;
		std::cout << "Latest arrival time: " << *latest_arrival_time << std::endl; 
		std::cout << "Earliest leaving time: " << *earliest_leaving_time << std::endl; 
		std::cout << "---------------------------------" << std::endl;
		*/
		if(earliest_leaving_time != W.end()) {
			t = *earliest_leaving_time - *latest_arrival_time + 1;
			min_time = std::min(min_time, t);
		}
	}
	std::cout << min_time << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve_test_case();
	
	return 0;
}
