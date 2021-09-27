class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto &num : nums) {
            freq[num]++;
        }
        
        priority_queue< pair<int, int>,
                        vector<pair<int, int>>,
                        greater<pair<int, int>> > min_pq;
        
        for (auto &elem_freq : freq) {
            if (min_pq.size() < k) {
                min_pq.push({elem_freq.second, elem_freq.first});           
            } else if (elem_freq.second > min_pq.top().first) {
                min_pq.pop();
                min_pq.push({elem_freq.second, elem_freq.first});
            }
        }
        
        vector<int> topKfreqElems;
        while (!min_pq.empty()) {
            topKfreqElems.push_back(min_pq.top().second);
            min_pq.pop();
        }
        
        return topKfreqElems;
    }
};
