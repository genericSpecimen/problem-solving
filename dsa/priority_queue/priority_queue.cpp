#include <iostream>
#include <functional> // std::greater, std::less
#include <vector>
#include <queue> // std::priority_queue

// pass a copy of queue
template<typename T>
void print_queue(T q) {
	while (!q.empty()) {
		std::cout << q.top() << " ";
		q.pop();
	}
	std::cout << "\n";
}

/*
 * https://stackoverflow.com/questions/32748069/the-reason-of-using-stdgreater-for-creating-min-heap-via-priority-queue
 * https://stackoverflow.com/questions/37819038/stdpriority-queue-and-make-heap-api-design?rq=1
 */

int main() {
	std::vector<int> data = {1,8,5,6,3,4,0,9,7,2};

	/*
	 * Largest elements on the top of the PQ.
	 * The next two statements accomplish the same thing - PQ implemented as a max heap
	 */
	
	//std::priority_queue<int, std::vector<int>, std::less<int>> q;
	std::priority_queue<int> q;

	for (int d : data) q.push(d);

	print_queue(q);


	/*
	 * Smallest element on the top of the PQ - implemented as a min heap
	 * The compare parameter:
	 * returns true if first arg comes before second arg in the ordering
	 */
	std::priority_queue<int,
		std::vector<int>,
		std::greater<int> > q2(data.begin(), data.end());

	print_queue(q2);
}
