#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> kLargestElements(vector<int> max_heap, int k) {
    if (max_heap.empty()) return {};
    
    vector<int> k_largest;
    priority_queue< pair<int, int>,
                    vector<pair<int, int>>,
                    std::less<pair<int, int>> > candidates_max_pq;
    
    // root is the largest
    candidates_max_pq.push({max_heap[0], 0});
    for (int i=1; i<=k; i++) {
        auto ith_max = candidates_max_pq.top(); candidates_max_pq.pop();
        k_largest.push_back(ith_max.first);
        
        int left_child_idx = 2*ith_max.second+1, right_child_idx = 2*ith_max.second+2;
        if (left_child_idx < max_heap.size()) {
            candidates_max_pq.push({max_heap[left_child_idx], left_child_idx});
        }
        if (right_child_idx < max_heap.size()) {
            candidates_max_pq.push({max_heap[right_child_idx], right_child_idx});
        }
    }
    
    return k_largest;
}

int main() {
    vector<int> max_heap = {561, 314, 401, 28, 156, 359, 271, 11, 3};
    vector<int> k_largest = kLargestElements(max_heap, 4);
    for (auto &elem : k_largest) cout << elem << ", ";
    cout << endl;
}
