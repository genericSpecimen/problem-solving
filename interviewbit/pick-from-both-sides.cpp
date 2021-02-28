#include <iostream>
#include <vector>
#include <limits>

int solve(const std::vector<int> &A, int B) {
	int left_sum = 0, right_sum = 0;

	// pick B elements from the left
	for (int i=0; i<B; i++) {
		left_sum += A[i];
	}

	int max_total_sum = left_sum;

	// start picking from the right and see
	// if we can achieve a better sum
	// by replacing some element from left

	int i = B-1, j = A.size()-1;
	for (int b = 0; b < B; b++) {
		left_sum -= A[i];
		right_sum += A[j];

		max_total_sum = std::max(max_total_sum, left_sum + right_sum);

		i--;
		j--;
	}

	return max_total_sum;
	
}


int main() {
	std::vector<int> A = {-533, -666, -500, 169, 724, 478, 358, -38, -536, 705, -855, 281, -173, 961, -509, -5, 942, -173, 436, -609, -396, 902, -847, -708, -618, 421, -284, 718, 895, 447, 726, -229, 538, 869, 912, 667, -701, 35, 894, -297, 811, 322, -667, 673, -336, 141, 711, -747, -132, 547, 644, -338, -243, -963, -141, -277, 741, 529, -222, -684, 35};
	int B = 48;
	std::cout << solve(A, B) << "\n";
}

