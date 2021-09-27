class Solution {
public:
    int maxDistance(vector<vector<int>> &mat) {
        if (mat.empty()) return -1;
        
        int m = mat.size(), n = mat.front().size();
        
        vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
        queue<pair<int, int>> Q;
        
        for(int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == 1) {
                    Q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        // no land or water exists
        if (Q.empty() || Q.size() == m*n) return -1;
        
        vector<pair<int, int>> directions = {
            {0, 1}, // right
            {1, 0}, // down
            {0, -1}, // left
            {-1, 0} // up
        };
        
        while (!Q.empty()) {
            pair<int, int> curr = Q.front(); Q.pop();

            // check each direction for a 0
            for (auto dir : directions) {
                pair<int, int> neighbor = {curr.first + dir.first, curr.second + dir.second};
                if (neighbor.first >= 0 && neighbor.first < m &&
                    neighbor.second >= 0 && neighbor.second < n) {
                    // valid neighbor, if it's one then no need to update distances
                    if (mat[neighbor.first][neighbor.second] == 1) continue;
                    
                    // otherwise, we have a 0
                    // check if the nearest one distance can be improved using curr
                    if (dist[neighbor.first][neighbor.second] > dist[curr.first][curr.second] + 1) {
                        // if yes, then improve it and push the 0 so that the one distances of
                        // this 0's neighbors can also be improved if possible
                        dist[neighbor.first][neighbor.second] = dist[curr.first][curr.second] + 1;
                        Q.push(neighbor);
                    }
                }
            }            
        }
        
        int max_distance = numeric_limits<int>::min();
        
        for (auto row : dist) {
            for (auto elem : row) {
                max_distance = std::max(max_distance, elem);
            }
        }
        
        return max_distance;
    }
};
