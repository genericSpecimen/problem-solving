#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> kthLargestFromKthElement(vector<int> &arr, int k) {
    if (k > arr.size()) throw std::invalid_argument("k must be <= arr.size()");
    
    vector<int> result(arr.size(), -1);
    priority_queue< int,
                    vector<int>,
                    std::greater<int> > min_pq;
                    
    for (int i=0; i<k; i++) {
        min_pq.push(arr[i]);
    }
    
    result[k-1] = min_pq.top();
    
    for (int i=k; i<arr.size(); i++) {
        if (arr[i] > min_pq.top()) {
            min_pq.pop();
            min_pq.push(arr[i]);
        }
        result[i] = min_pq.top();
    }
    
    return result;
}

int main() {
    vector<int> arr = {10,5,8,2,15,20,1};
    vector<int> result = kthLargestFromKthElement(arr, 3);
    for (auto &elem : result) cout << elem << ", ";
    cout << endl;
}
