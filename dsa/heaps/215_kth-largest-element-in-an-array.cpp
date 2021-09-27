class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue< int,
                        vector<int>,
                        std::greater<int>> min_pq;
        
        for (auto &num : nums) {
            if (min_pq.size() < k) {
                min_pq.push(num);
            } else if (num > min_pq.top()) {
                min_pq.pop();
                min_pq.push(num);
            }
        }
        
        return min_pq.top();
    }
};
