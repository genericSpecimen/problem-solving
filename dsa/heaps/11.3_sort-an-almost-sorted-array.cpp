#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void sortKSortedArray(vector<int> &arr, int k) {
    if (k >= arr.size()) throw std::invalid_argument("k must be less than size of array");
    
    priority_queue< int,
                    vector<int>,
                    std::greater<int>> min_pq;
    int read_idx = 0;
    while (read_idx < k+1) {
        min_pq.push(arr[read_idx]);
        read_idx++;
    }
    
    int write_idx = 0;
    while (!min_pq.empty() && read_idx < arr.size()) {
        arr[write_idx++] = min_pq.top(); min_pq.pop();
        min_pq.push(arr[read_idx++]);
    }
    
    while (!min_pq.empty()) {
        arr[write_idx++] = min_pq.top(); min_pq.pop();
    }
    
    //return arr;
}

int main() {
    vector<int> arr = {3, -1, 2, 6, 4, 5, 8};
    sortKSortedArray(arr, 2);
    for (auto &elem : arr) cout << elem << ", ";
    cout << endl;
}
