class Solution {
public:
    
    int partition(vector<int> &nums, int p, int r) {
        int random_idx = rand() % (r-p+1) + p;
        std::swap(nums[random_idx], nums[r]);
        
        int pivot = nums[r];
        
        int i = p - 1;
        
        for (int j=p; j<r; j++) {
            if (nums[j] <= pivot) {
                i++;
                std::swap(nums[j], nums[i]);
            }
        }
        std::swap(nums[i+1], nums[r]);
        
        return i+1;
    }
    
    int quickSelect(vector<int> &nums, int p, int r, int k) {
        if (p == r) return nums[p];
        
        int q = partition(nums, p, r);
        
        int num_elements = r - q + 1;
        
        if (num_elements == k) return nums[q];
        else if (num_elements < k) return quickSelect(nums, p, q-1, k - num_elements);
        else return quickSelect(nums, q+1, r, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return quickSelect(nums, 0, nums.size()-1, k);
    }
};
