#include <iostream>
#include <vector>

using namespace std;

int firstElemGreaterThan(vector<int> &nums, int key) {
    int l = 0, u = nums.size() - 1, result = -1;
    
    while (l <= u) {
        int mid = l + (u - l) / 2;
        if (nums[mid] > key) {
            result = mid;
            // first occurence can't be on the right of mid
            u = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    
    vector<int> keys = {285, -13, 2, 108};
    
    for (auto key : keys) cout << firstElemGreaterThan(nums, key) << endl;
    
}
