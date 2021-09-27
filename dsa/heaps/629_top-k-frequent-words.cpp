class Solution {
public:
    /*
    */
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        
        for (auto &w : words) {
            freq[w]++;
        }
        
    struct Compare {
        bool operator()(const pair<int, string> &p1, const pair<int, string> &p2) {
            if (p1.first == p2.first) {
                return (p1.second.compare(p2.second) < 0);
            }
            return (p1.first > p2.first);
        }
    };
        priority_queue< pair<int, string>,
                        vector<pair<int, string>>,
                        Compare > min_pq;
        
        for (auto w_f : freq) {
            if (min_pq.size() < k) {
                min_pq.push({w_f.second, w_f.first});
            } else if ( (w_f.second > min_pq.top().first) ||
                        (w_f.second == min_pq.top().first && w_f.first.compare(min_pq.top().second) < 0) ) {
                min_pq.pop();
                min_pq.push({w_f.second, w_f.first});
            }
        }
        
        vector<string> topKFreqWords(k);
        
        int i = k-1;
        
        while (!min_pq.empty()) {
            topKFreqWords[i] = min_pq.top().second;
            i--;
            min_pq.pop();
        }
        
        return topKFreqWords;
    }
};
