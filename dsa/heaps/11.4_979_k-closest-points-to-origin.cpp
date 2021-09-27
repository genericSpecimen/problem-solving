class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<int, int>,
                        vector<pair<int, int>>,
                        std::less<pair<int, int>> > max_pq;
        
        for (int i=0; i<points.size(); i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            
            if (max_pq.size() < k) {
                max_pq.push({dist, i});
            } else if (dist < max_pq.top().first) {
                max_pq.pop();
                max_pq.push({dist, i});
            }
        }
        
        vector<vector<int>> kclosest;
        for (int i=0; i<k; i++) {
            kclosest.push_back(points[max_pq.top().second]);
            max_pq.pop();
        }
        
        return kclosest;
    }
};
