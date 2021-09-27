class Solution {
public:
    /*
    // Brute force: recursive DFS
    //Time complexity : O(2^n). Size of recursion tree will be 2^n.
    //Space complexity : O(n). The depth of the recursion tree can go upto n
    
    void choose(vector<int>& nums, int idx, int target, int sum, int &num_ways) {        
        if (idx == nums.size() && sum == target) {
            num_ways++;
        }
        
        if (idx < nums.size()) {
            // choose to place '+' before nums[idx]
            choose(nums, idx+1, target, sum+nums[idx], num_ways);

            // choose to place '-' before nums[idx]
            choose(nums, idx+1, target, sum-nums[idx], num_ways);
        }
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int num_ways = 0;
        choose(nums, 0, target, 0, num_ways);
        return num_ways;
    }
    */
    
    
    
    // Brute force with memoization
    // memo table size: O(n * s), where s is the size of the longest sum string
    // time : O(n * s) - fill each table entry once
    // space : O(n * s) - size of memo table
    int choose(vector<int> &nums, int idx, int target, int sum, unordered_map<string, int> &memo) {
        if (idx == nums.size()) {
            if (sum == target) return 1;
            return 0;
        }
        
        string hash = std::to_string(idx) + "." + std::to_string(sum);
        if (memo.find(hash) != memo.end()) {
            return memo[hash];
        } else {
            int add = choose(nums, idx+1, target, sum+nums[idx], memo);
            int sub = choose(nums, idx+1, target, sum-nums[idx], memo);
            
            memo[hash] = add + sub;
            return memo[hash];
        }
    }
    
    int findTargetSumWays(vector<int> &nums, int target) {
        unordered_map<string, int> memo;
        return choose(nums, 0, target, 0, memo);
    }
};
