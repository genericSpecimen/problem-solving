// 33 without duplicates
class Solution {
public:
    /*
    int search(vector<int>& nums, int target) {
        if (nums.empty() || nums.size() == 1 && nums.front() != target) return -1;
        
        int l = 0, r = nums.size()-1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int elem = nums[mid];
            
            if (elem == target) return mid;
            
            if (elem >= nums[0] && elem > nums[nums.size()-1]) {
                // in left sorted portion
                if (elem < target) {
                    l = mid + 1;
                } else {
                    if (target < nums[0]) l = mid + 1;
                    else r = mid - 1;
                }
                
            } else if (elem < nums[0] && elem <= nums[nums.size()-1]) {
                // in right sorted portion
                if (elem > target) {
                    r = mid - 1;
                } else {
                    if (target > nums[nums.size()-1]) r = mid - 1;
                    else l = mid + 1;
                }
            } else {
                // not rotated
                if (elem < target) l = mid + 1;
                else r = mid - 1;
            }
        }
        
        return -1;
    }
    */
    /*
    int search(vector<int>& nums, int target) {
        if (nums.empty() || nums.size() == 1 && nums.front() != target) return -1;
        
        int l = 0, r = nums.size()-1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int elem = nums[mid];
            
            if (elem == target) return mid;
            
            if (elem >= nums[l] && elem > nums[r]) {
                // elem is in left sorted portion
                if (elem < target || target < nums[l]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
                
            } else if (elem < nums[l] && elem <= nums[r]) {
                // elem in right sorted portion
                if (elem > target || target > nums[r]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // elem is in not-rotated portion, perform simple binary search
                if (elem < target) l = mid + 1;
                else r = mid - 1;
            }
        }
        
        return -1;
    }
    */
    int search(vector<int>& nums, int target) {
        //if (nums.empty() || nums.size() == 1 && nums.front() != target) return -1;
        
        int l = 0, r = nums.size()-1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int elem = nums[mid];
            
            if (elem == target) return mid;
            
            if (elem >= nums[l]) {
                // elem is in left sorted portion
                if (elem < target || target < nums[l]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
                
            } else {
                // elem in right sorted portion
                if (elem > target || target > nums[r]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        
        return -1;
    }    
};


// 81 with duplicates
class Solution {
public:
    
    /*
    there are 4 cases here:
    1 target == nums[mid], then we find it;
    2 nums[left] < nums[mid], then the left part must be sorted;
    3 nums[left] > nums[mid], then the right part must be sorted;
    4 nums[left] == nums[mid], we can not make sure which part is sorted, the only thing we can do is scale in the problem size. Since target != nums[mid] == nums[left], we just offset right by left++.
    */
    bool search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size()-1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int elem = nums[mid];
            
            if (elem == target) return true;
            
            if (elem > nums[l]) {
                // elem is in left sorted portion
                if (elem < target || target < nums[l]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
                
            } else if (elem < nums[l]) {
                // elem in right sorted portion
                if (elem > target || target > nums[r]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // elem == nums[l], can't make a decision, so just increment l
                l++;
            }
        }
        
        return false;
    }  
};
