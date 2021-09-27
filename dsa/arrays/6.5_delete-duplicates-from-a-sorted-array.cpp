#include <iostream>
#include <vector>
#include <set>

template <class T>
std::ostream& operator<< (std::ostream& os, const std::vector<T> v) {
    os << "[";
    for (auto elem : v) {
        os << elem << ",";
    }
    os << "]";
    return os;
}

/*
// brute force, O(n^2) time complexity, O(1) space complexity
std::vector<int> removeDuplicatesBruteForce(std::vector<int> &nums) {
    if (nums.empty()) {
        return nums;
    }
    
    for (int i=0; i<nums.size()-1; i++) {
        
        // while loop in case nums[i+2] is also = nums[i]
        while (nums[i+1] == nums[i]) {
            // shift all elements at and after i+2 to the left by one
            for (int j=i+2; j<nums.size(); j++) {
                nums[j-1] = nums[j];
            }
            nums.pop_back(); // remove the last element
        }
    }
    
    return nums;
}
*/

// O(n) time complexity, O(1) space complexity
std::vector<int> removeDuplicates(std::vector<int> &nums) {
    if (nums.empty()) {
        return nums;
    }
    
    // start from the second element
    int write_idx = 1;
    for (int i=1; i<nums.size(); i++) {
        if (nums[i] != nums[write_idx-1]) {
            // new unique element found
            nums[write_idx++] = nums[i];
        }
    }
    //nums.erase(nums.begin()+write_idx, nums.end());
    // return write_idx; // returns the number of unique elements
    return nums;
}

std::vector<int> removeDuplicatesAtMostKAllowed(std::vector<int> &nums, int k) {
    if (nums.empty() || k < 1) {
        return nums;
    }
    
    int write_idx = 0;
    for (int i=0; i<nums.size(); i++) {
        if (write_idx < k || nums[i] != nums[write_idx-k]) {
            // either we haven't encountered k elements yet,
            // or, ith (current) element is different from the
            // write_idx-k th element.
            // this way, k duplicates are allowed.
            nums[write_idx++] = nums[i];
        }
    }
    
    nums.erase(nums.begin()+write_idx, nums.end());
    // return write_idx; // returns the number of unique elements
    return nums;
}

// O(n) space complexity, O(n) time complexity, assuming find and insert take average constant time.
std::vector<int> removeDuplicatesUsingHashTable(std::vector<int> &nums) {
    std::set<int> unique_elements;
    for (auto num : nums) {
        if (unique_elements.find(num) == unique_elements.end()) {
            unique_elements.insert(num);
        }
    }
    
    int write_idx=0;
    for (auto it=unique_elements.begin(); it!=unique_elements.end(); it++) {
        nums[write_idx++] = *it;
    }
    // return write_idx;
    return nums;
}

int main() {
    std::vector<std::vector<int>> test_cases = {
        {2, 3, 5, 5, 7, 11, 11, 11, 13},
        {2, 2, 2, 2},
        {0},
        {}
    };
    for (auto &vec : test_cases) {
        //std::cout << removeDuplicatesBruteForce(vec) << std::endl;
        //std::cout << removeDuplicates(vec) << std::endl;
        //std::cout << removeDuplicatesAtMostKAllowed(vec, 2) << std::endl;
        std::cout << removeDuplicatesUsingHashTable(vec) << std::endl;
    }
    return 0;
}
