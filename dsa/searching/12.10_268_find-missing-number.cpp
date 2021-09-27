class Solution {
public:
    /*
    // simple sum
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int want = n * (n+1) / 2;
        
        int sum = 0;
        for (int elem : nums) sum += elem;
        
        return want - sum;
    }
    */
    
    /*
    // XOR approach: a ^ b ^ b = a
    int missingNumber(vector<int> &nums) {        
        int all_xor = 0;
        for (int i=0; i<=nums.size(); i++) all_xor ^= i;
        
        int arr_xor = 0;
        for (int i=0; i<nums.size(); i++) arr_xor ^= nums[i];
        
        return all_xor ^ arr_xor;
    }
    */
    
    // sorted array approach: find nums[idx] != idx
    int missingNumber(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = l + (r-l) / 2;
            if (nums[mid] == mid) l = mid + 1;
            else r = mid - 1;
        }
        
        return l;
    }
};
