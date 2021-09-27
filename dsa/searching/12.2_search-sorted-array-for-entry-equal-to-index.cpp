#include <iostream>
#include <vector>

using namespace std;

int fixedPoint(const vector<int> &nums) {
    int l = 0, u = nums.size()-1;
    
    while (l <= u) {
        int mid = l + (u - l) / 2;
        int diff = nums[mid] - mid;
        
        if (diff == 0) {
            return mid;
        } else if (diff < 0) {
            // move right
            l = mid + 1;
        } else {
            // move left
            u = mid - 1;
        }
    }
    
    return -1;
}

int fixedPointDup(const vector<int> &nums, int start, int end) {    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (nums[mid] == mid) {
            return mid;
        }
        
        // potential to skip some entries if A[mid] < mid
        int left_idx = std::min(mid-1, nums[mid]);
        int left_fpd = fixedPointDup(nums, start, left_idx);
        if (left_fpd != -1) return left_fpd;
        
        // potential to skip some entries if A[mid] > mid
        int right_idx = std::max(mid+1, nums[mid]);
        int right_fpd = fixedPointDup(nums, right_idx, end);
        
        return right_fpd;
    }
    
    return -1;
}

int main() {
    // distinct numbers
    //vector<int> nums = {-2, 0, 2, 4, 6, 7, 9};
    
    // with duplicates
    //vector<int> nums = {-14, -10, 1, 4, 4, 243, 285, 285, 285, 401};
    vector<int> nums = {1, 2, 3, 4, 4, 6, 7};
    
    
    //cout << fixedPoint(nums) << endl;
    cout << fixedPointDup(nums, 0, nums.size()-1) << endl;
}
