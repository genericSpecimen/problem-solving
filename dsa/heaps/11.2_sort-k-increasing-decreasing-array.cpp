#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct KeyWithIdx {
    //          kth arr, idx within it  
    int key;
    pair<int, int> idx;
};

struct GreaterKey {
    bool operator() (const KeyWithIdx &kwi1, const KeyWithIdx &kwi2) {
        return kwi1.key > kwi2.key;
    }
};


vector<int> mergeKSortedArrays(const vector<vector<int>> &sorted_arrays) {
    vector<int> merged_result;
    
    priority_queue< KeyWithIdx,
                    vector<KeyWithIdx>,
                    GreaterKey> min_pq;
    for (int k=0; k<sorted_arrays.size(); k++) {
        min_pq.push({sorted_arrays[k][0], {k, 0}});
    }
    
    while (!min_pq.empty()) {
        auto curr_min = min_pq.top(); min_pq.pop();
        int curr_k = curr_min.idx.first;
        int curr_k_idx = curr_min.idx.second;
        
        merged_result.push_back(curr_min.key);
        
        int curr_k_next_idx = curr_k_idx + 1;
        if (curr_k_next_idx < sorted_arrays[curr_k].size())
            min_pq.push({sorted_arrays[curr_k][curr_k_next_idx], {curr_k, curr_k_next_idx}});
    }
    
    return merged_result;
}

void pushCurrSubarray(const vector<int> &arr, vector<vector<int>> &sorted_subarrays, pair<int, int> idx) {
    vector<int> curr_subarray;
    if (idx.first <= idx.second) {
        for (int i=idx.first; i<=idx.second; i++) curr_subarray.push_back(arr[i]);
    } else {
        for (int i=idx.first; i>=idx.second; i--) curr_subarray.push_back(arr[i]);
    }
    sorted_subarrays.push_back(curr_subarray);
}

vector<int> sortKIncreasingDecreasingArray(const std::vector<int> &arr) {
    if (arr.size() <= 1) return arr;
    
    vector<vector<int>> sorted_subarrays;
    vector<int> curr_subarray;
    bool increasing = (arr[1] >= arr[0]);
    int start = 0, end = 0;
    for (int i=1; i<=arr.size(); i++) {
        if (i == arr.size()) {
            pushCurrSubarray(arr, sorted_subarrays, {start, end});
            break;
        }
        
        if (increasing) {
            if (arr[i] >= arr[i-1]) end++;
            else {
                pushCurrSubarray(arr, sorted_subarrays, {start, end});
                increasing = false;
                start = i; end = i;
            }
        } else {
            if (arr[i] <= arr[i-1]) start++;
            else {
                pushCurrSubarray(arr, sorted_subarrays, {start, end});
                increasing = true;
                start = i; end = i;
            }
        }
    }
    
    /*
    for (auto row : sorted_subarrays) {
        for (auto elem : row) cout << elem << ", ";
        cout << endl;
    }
    */
    
    vector<int> sorted_arr = mergeKSortedArrays(sorted_subarrays);
    return sorted_arr;
}

int main() {
    vector<int> arr = {57, 57, 131, 493, 294, 221, 339, 418, 452, 442, 442, 190};
    
    vector<int> sorted_arr = sortKIncreasingDecreasingArray(arr);
    
    for (auto &elem : sorted_arr) cout << elem << ", ";
    cout << endl;
}
