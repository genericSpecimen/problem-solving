#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> findDupAndMiss(const vector<int> &nums) {
    int dup_XOR_miss = 0;
    for (int i=0; i<nums.size(); i++) {
        dup_XOR_miss ^= (i ^ nums[i]);
    }
    cout << "    dup_XOR_miss: " << dup_XOR_miss << endl;
    if (dup_XOR_miss == 0) throw std::invalid_argument("no duplicate and missing element exists");
    
    
    int lsb_differ = dup_XOR_miss & ~(dup_XOR_miss - 1);
    
    int dup_or_miss = 0;
    for (int i=0; i<nums.size(); i++) {
        if (i & lsb_differ) dup_or_miss ^= i;
        if (nums[i] & lsb_differ) dup_or_miss ^= nums[i];
    }
    cout << "    dup_or_miss: " << dup_or_miss << endl;
    
    for (int num : nums) {
        if (num == dup_or_miss) {
            return {dup_or_miss, dup_or_miss ^ dup_XOR_miss};
        }
    }
    
    return {dup_or_miss ^ dup_XOR_miss, dup_or_miss};
}

int main() {
    vector<vector<int>> tests = {
        //{2,5,1,0,4,3},
        {2,5,1,3,4,3},
        {5,3,0,3,1,2}
    };
    
    for (auto test : tests) {
        auto dup_miss = findDupAndMiss(test);
        cout << "dup: " << dup_miss.first << ", miss: " << dup_miss.second << endl;
    }
}
