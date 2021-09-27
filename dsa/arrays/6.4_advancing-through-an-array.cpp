#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

/*
// O(n) time complexity. Need to traverse entire array.
bool canAdvanceToEnd(const std::vector<int> &A) {
    // A = {3, 3, 1, 0, 2, 0, 1};
    //      1  3  2  1  2  1  0  -1
    //      T  T  F  F  T  F  T
    int required_steps = -1;
    bool can_advance_to_next_milestone = false;
    
    for (int i=A.size()-1; i>=0; i--) {
        required_steps++;
        if (required_steps <= A[i]) {
            can_advance_to_next_milestone = true;
            required_steps = 0;
        } else {
            can_advance_to_next_milestone = false;
        }
    }
    
    return can_advance_to_next_milestone;
}
*/

// Greedy solution O(n)
bool canAdvanceToEnd(const std::vector<int> &A) {
    int goal = A.size() - 1;
    for (int i=A.size()-1; i>= 0; i--) {
        if (i+A[i] >= goal) {
            goal = i;
        }
    }
    return goal == 0;
}

/*
// brute force with memoization: TLE
bool canReachEndFrom(const std::vector<int> &nums, std::vector<int> &memo, int i) {
    bool can_reach = false;
    if (i == nums.size()-1) {
        memo[i] = 1;
        return true;
    } else if (nums[i] == 0) {
        memo[i] = 0;
        return false;
    } else {
        for (int j=1; j<=nums[i]; j++) {
            if (memo[i+j] != -1) {
                can_reach = can_reach || memo[i+j];
            } else {
                can_reach = can_reach || canReachEndFrom(nums, memo, i+j);
            }
            if (can_reach == true) {
                memo[i] = 1;
                break;
            }
        }
    }
    return can_reach;
}

bool canJump(const std::vector<int> &nums) {
    std::vector<int> memo(nums.size(), -1);
    return canReachEndFrom(nums, memo, 0);
}
*/

/*
// Bottom up DP solution : AC but long runtime 
// complexity somewhere between O(n) and O(n^2)
bool canJump(const std::vector<int> &nums) {
    std::vector<bool> can_reach_end(nums.size(), false);
    
    // can reach the end if already at the end
    can_reach_end[nums.size()-1] = true;
    
    // compute can_reach_end[0]
    for (int i=nums.size()-2; i>=0; i--) {
        if (nums[i] == 0) {
            // dead end, can't go anywhere (including the end) from here
            can_reach_end[i] = false;
        } else {
            // see if we can reach the end by jumping each possible number of steps from here
            for (int j=1; j<=nums[i]; j++) {
                if (can_reach_end[i+j] == true) {
                    can_reach_end[i] = true;
                    break;
                }
            }
        }
    }
    
    return can_reach_end[0];
}
*/

/*
// O(n) time complexity, but we can stop early in case we find max_advance_so_far >= last_idx
bool canAdvanceToEnd(const std::vector<int> &A) {
    int max_advance_so_far = 0;
    int last_idx = A.size()-1;
    
    for (int i=0; i<A.size(); i++) {
        if (i > max_advance_so_far || max_advance_so_far >= last_idx) {
            break;
        }
        max_advance_so_far = std::max(max_advance_so_far, i+A[i]);
    }
    
    return max_advance_so_far >= last_idx;
} 
*/


int minJumpsToEnd(const std::vector<int> &nums) {
    int min_jumps = 0;
    
    // currently reachable interval of indices
    std::pair<int, int> interval = {0, 0};
    
    // until we reach the end
    
    while (interval.second < nums.size()-1) {
        int max_interval_reach = 0;
        for (int i=interval.first; i<=interval.second; i++) {
            max_interval_reach = std::max(max_interval_reach, i+nums[i]);
        }
        
        if (max_interval_reach < interval.second + 1) {
            // can't reach to the next interval
            return -1;
        }
        interval.first = interval.second + 1;
        interval.second = max_interval_reach;
        
        min_jumps++;
        
    }
    
    return min_jumps;
    
} 

bool canAdvanceToEnd1(const std::vector<int> &nums) {
    //int min_jumps = 0;
    int curr_interval_end = 0;
    
    int max_interval_reach = 0;
    for (int i=0; i<nums.size(); i++) {
        max_interval_reach = std::max(max_interval_reach, i+nums[i]);
        
        if (curr_interval_end >= nums.size()-1) {
            // already reached end of array
            return true;
        }
        if (i == curr_interval_end) {
            // reached end of current interval
            if (max_interval_reach < curr_interval_end + 1) {
                // can't go past this interval
                return false;
            }
            
            // can jump past this interval
            //min_jumps++;
            curr_interval_end = max_interval_reach;
        }
    }
    // shouldn't reach here
    assert(false);
}

int minJumpsToEnd1(const std::vector<int> &nums) {
    int min_jumps = 0;
    int curr_interval_end = 0;
    
    int max_interval_reach = 0;
    for (int i=0; i<nums.size(); i++) {
        max_interval_reach = std::max(max_interval_reach, i+nums[i]);
        
        if (curr_interval_end >= nums.size()-1) {
            // already reached end of array
            break;
        }
        if (i == curr_interval_end) {
            // reached end of current interval
            if (max_interval_reach < curr_interval_end + 1) {
                // can't go past this interval
                return -1;
            }
            
            // can jump past this interval
            min_jumps++;
            curr_interval_end = max_interval_reach;
        }
    }
    
    return min_jumps;
}

int main() {
    //std::vector<int> A = {3, 3, 1, 0, 2, 0, 1};
    
    //                      1  3  2  1  2  1  0  -1
    //                      T  T  F  F  T  F  T
    
    //std::cout << std::boolalpha << canAdvanceToEnd(A) << std::endl;
    
    std::vector<std::vector<int>> test = {
        {3, 3, 1, 0, 2, 0, 1},
        {3, 2, 0, 0, 2, 0, 1},
        {2, 3, 1, 1, 4},
        {2, 3, 0, 1, 4},
        {3, 2, 1, 0, 4}
    };
    for (auto &vec : test) {
        std::cout << std::boolalpha << canAdvanceToEnd(vec) << ", min_jumps: " << minJumpsToEnd(vec) << std::endl;
        std::cout << std::boolalpha << canAdvanceToEnd1(vec) << ", min_jumps: " << minJumpsToEnd1(vec) << std::endl;
    }

}
