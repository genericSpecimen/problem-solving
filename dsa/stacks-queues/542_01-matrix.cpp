class Solution {
public:
    /*
    int nearestZero(vector<vector<int>> &mat, pair<int, int> root, vector<vector<int>> &result) {
        int m = mat.size(), n = mat.front().size();
        
        if (mat[root.first][root.second] == 0) {
            return 0;
        }
        
        vector<pair<int, int>> directions = {
            {0, 1}, // right
            {1, 0}, // down
            {0, -1}, // left
            {-1, 0} // up
        };
        
        // check each direction for a 0
        for (auto dir : directions) {
            pair<int, int> neighbor = {root.first + dir.first, root.second + dir.second};
            if (neighbor.first >= 0 && neighbor.first < m &&
                neighbor.second >= 0 && neighbor.second < n) {
                if (mat[neighbor.first][neighbor.second] == 0) {
                    return 1;
                }
            }
        }

        // if we are here, then no adjacent neighbors are 0 (all are 1)
        int mindist = std::numeric_limits<int>::max();
        for (auto dir : directions) {
            pair<int, int> neighbor = {root.first + dir.first, root.second + dir.second};
            if (neighbor.first >= 0 && neighbor.first < m &&
                neighbor.second >= 0 && neighbor.second < n) {
                
                if (result[neighbor.first][neighbor.second] != -1) {
                    mindist = std::min(mindist, 1 + result[neighbor.first][neighbor.second]);
                } else {
                    mindist = std::min(mindist, 1 + nearestZero(mat, neighbor, result));
                }
            }
        }
        
        return mindist;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        
        int m = mat.size(), n = mat.front().size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (result[i][j] == -1) {
                    // unvisited
                    result[i][j] = nearestZero(mat, {i, j}, result);
                }
            }
        }
        
        return result;
    }
    */
    
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        if (mat.empty()) return {};
        
        int m = mat.size(), n = mat.front().size();
        
        vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
        queue<pair<int, int>> Q;
        
        for(int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == 0) {
                    Q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
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
                    // valid neighbor, if it's zero then no need to update distances
                    if (mat[neighbor.first][neighbor.second] == 0) continue;
                    
                    // otherwise, we have a 1
                    // check if the nearest zero distance can be improved using curr
                    if (dist[neighbor.first][neighbor.second] > dist[curr.first][curr.second] + 1) {
                        // if yes, then improve it and push the 1 so that the zero distances of
                        // this 1's neighbors can also be improved if possible
                        dist[neighbor.first][neighbor.second] = dist[curr.first][curr.second] + 1;
                        Q.push(neighbor);
                    }
                }
            }            
        }
        
        return dist;
    }
};
