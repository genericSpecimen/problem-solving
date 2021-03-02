#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>

#include "LinkedList.h"

struct ListIterator {
    int index;
    std::vector<int>::iterator it;
};

/*
 * For conveniently comparing ranges using simply the < operator, we overload
 * the < operator for two vectors. Note that a range is a vector of two elements.
 */
bool operator<(const std::vector<int> &r1, const std::vector<int> &r2) {
    int range1 = r1[1] - r1[0];
    int range2 = r2[1] - r2[0];
    if ((range1 < range2) || (range1 == range2 && r1[0] < r2[0])){
        return true;
    }
    return false;
}

std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
    int k = nums.size();
    
    std::vector<ListIterator> l_itrs(k);
    
    for (int i=0; i<k; i++) {
        l_itrs[i].index = i;
        l_itrs[i].it = nums[i].begin();
        //std::cout << *itrs[i] << "\n";
    }
    
    auto comp = [](ListIterator &lit1, ListIterator &lit2) {
        return *lit1.it > *lit2.it;
    };
    
    std::priority_queue<ListIterator,
                        std::vector<ListIterator>,
                        decltype(comp)> min_pq(comp);
    
    int curr_min = std::numeric_limits<int>::max();
    int curr_max = std::numeric_limits<int>::min();
    for (auto lit : l_itrs) {
        curr_min = std::min(curr_min, *lit.it);
        curr_max = std::max(curr_max, *lit.it);
        min_pq.push(lit);
    }
    
    //std::cout << curr_min << ", " << curr_max << "\n";
    
    std::vector<int> curr_range = {curr_min, curr_max};
    std::vector<int> min_range = curr_range;
    
    ListIterator min_lit;
    int min_index;
    
    int last_pushed = curr_max;
    while (true) {
        min_lit = min_pq.top();
        min_pq.pop();
        
        curr_min = *min_lit.it;
        curr_max = std::max(curr_max, last_pushed);
        curr_range = {curr_min, curr_max};
        //std::cout << "[" << curr_range[0] << ", " << curr_range[1] << "], ";
        
        if (curr_range < min_range) {
            min_range = curr_range;
        }
        
        min_lit.it++;
        min_index = min_lit.index;
        
        if (min_lit.it == nums[min_index].end()) {
            // some list has been exhausted
            break;
        }
        
        // std::cout << "Pushing " << *min_lit.it << "\n";
        min_pq.push(min_lit);
        last_pushed = *min_lit.it;
    }
    
    return min_range;
}

int main() {
    std::vector<std::vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };
    
    /*
    std::vector<std::vector<int>> nums = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };
    */
    
    /*
    std::vector<std::vector<int>> nums = {
        {10, 10},
        {11, 11}
    };
    */
    
    /*
    std::vector<std::vector<int>> nums = {
        {10},
        {11}
    };
    */
    
    /*
    std::vector<std::vector<int>> nums = {
        {1}, {2}, {3}, {4}, {5}, {6}, {7}
    };
    */
    std::vector<int> range = smallestRange(nums);
    
    std::cout << "[" << range[0] << ", " << range[1] << "]\n";
}
