class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> min_pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto &num : nums) add(num);
    }
    
    int add(int val) {
        if (min_pq.size() < k) {
            min_pq.push(val);
        } else if (val > min_pq.top()) {
            min_pq.pop();
            min_pq.push(val);
        }
        
        return min_pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
