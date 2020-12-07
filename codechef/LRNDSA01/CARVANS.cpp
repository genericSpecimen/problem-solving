#include <iostream>
#include <vector>
#include <limits>

#define INF std::numeric_limits<int>::max()

int main() {
	int T; std::cin >> T;
	int N;
	int max_till_now = INF, num_max_speed = 0;
	std::vector<int> max_speeds;
	while(T--) {
		std::cin >> N;
		max_speeds.resize(N);
		max_till_now = INF;
		num_max_speed = 0;
		for(int i=0; i<N; i++) {
			std::cin >> max_speeds[i];
			
			if(max_till_now >= max_speeds[i]) {
				num_max_speed++;
				max_till_now = max_speeds[i];
			}
		}
		std::cout << num_max_speed << "\n";
	}
}
