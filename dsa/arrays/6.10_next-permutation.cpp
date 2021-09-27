#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
std::ostream& operator<< (std::ostream& os, const std::vector<T> v) {
    os << "[";
    for (auto elem : v) {
        os << elem << ",";
    }
    os << "]";
    return os;
}

std::vector<int> nextPermutation(std::vector<int>& nums) {
    if (nums.size() == 1) {
        return nums;
    }
    int i = nums.size()-2;
    // find first nums[i] < nums[i+1]
    while (i >= 0 && nums[i] >= nums[i+1]) {
        i--;
    }
    
    if (i < 0) {
        // the array denotes the last permutation in dictionary order
        // just sort and return. here, we can simply reverse.
        std::reverse(nums.begin(), nums.end());
        return nums;
    } else {
        // nums[i] is the first element after which elements appear in decreasing order
        int j = nums.size()-1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        
        // now nums[j] is the first element in the subarray greater than elem
        
//         std::cout << "[";
//         for (auto elem : nums) std::cout << elem << ",";
//         std::cout << "]";
//         
//         std::cout << j << i << std::endl;
        std::swap(nums[j], nums[i]);
        
        std::reverse(nums.begin()+i+1, nums.end());
    }
    return nums;
}

int main() {
    std::vector<std::vector<int>> test_cases = {
        {1,2,3},
        {3,2,1},
        {1,2},
        {1},
        {1,5,1}
    };
    for (auto vec : test_cases) {
        std::cout << nextPermutation(vec) << std::endl;
    }
    return 0;
}
