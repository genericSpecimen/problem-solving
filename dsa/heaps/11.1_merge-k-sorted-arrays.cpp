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

int main() {
    vector<vector<int>> sorted_arrays = {
        {3, 5, 7},
        {0, 6},
        {0, 6, 28},
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };
    
    vector<int> merged_arrays = mergeKSortedArrays(sorted_arrays);
    
    for (auto &elem : merged_arrays) cout << elem << ", ";
    cout << endl;
}
