// 153
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_elem = numeric_limits<int>::max();
        
        int l = 0, r = nums.size()-1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            min_elem = std::min(min_elem, nums[mid]);
            
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return min_elem;
    }
};

// 154
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int min_elem = numeric_limits<int>::max();
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            min_elem= std::min(min_elem, nums[mid]);
            
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else if (nums[mid] < nums[r]) {
                r = mid - 1;
            } else {
                // nums[mid] == nums[r]
                r--;
            }
        }
        
        return min_elem;
    }
};
