class Solution {
public:
    int firstOfK(const vector<int> &nums, int target) {
        int l = 0, u = nums.size()-1, first = -1;
        
        while (l <= u) {
            int mid = l + (u - l) / 2;
            
            if (nums[mid] == target) {
                first = mid;
                // first occurence can't be to the right of mid
                u = mid - 1;
            } else if (nums[mid] > target) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return first;
    }
    
    int lastOfK(const vector<int> &nums, int target) {
        int l = 0, u = nums.size()-1, last = -1;
        
        while (l <= u) {
            int mid = l + (u - l) / 2;
            
            if (nums[mid] == target) {
                last = mid;
                // last occurence can't be to the left of mid
                l = mid + 1;
            } else if (nums[mid] > target) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return last;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOfK(nums, target), lastOfK(nums, target)};
    }
};

