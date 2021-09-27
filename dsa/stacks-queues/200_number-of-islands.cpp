class Solution {
public:
    /*
    // BFS using queue
    void growIslandFrom(vector<vector<char>> &grid, deque<deque<bool>> &visited, pair<int,int> root) {
        int m = grid.size(), n = grid.front().size();
        std::vector<std::pair<int, int>> directions = {
            {0, 1}, // right
            {1, 0}, // down
            {0, -1}, // left
            {-1, 0} // up
        };
        
        queue<pair<int, int>> q;
        q.push({root.first, root.second});
        
        while (!q.empty()) {
            pair<int,int> loc = q.front();
            q.pop();

            visited[loc.first][loc.second] = true;
            if (grid[loc.first][loc.second] != '0') {
                // try to expand land in each direction
                for (int dir=0; dir<directions.size(); dir++) {
                    std::pair<int, int> next = {loc.first + directions[dir].first, loc.second + directions[dir].second};
                    if (next.first >= 0 && next.first < m &&
                        next.second >= 0 && next.second < n &&
                        !visited[next.first][next.second]) {
                        q.push(next);
                        visited[next.first][next.second] = true;
                    }
                }
                
            }
            
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.front().size();
        deque<deque<bool>> visited(m, deque<bool>(n, false));
        
        int num_islands = 0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!visited[i][j] && grid[i][j] != '0') {
                    num_islands++;
                    // grow an island from the root {i,j}
                    growIslandFrom(grid, visited, {i,j});
                }
            }
        }
        
        return num_islands;
    }
    */
    
    void growIslandFrom(vector<vector<char>> &grid, deque<deque<bool>> &visited, pair<int, int> root) {
        int m = grid.size(), n = grid.front().size();
        
        if (root.first < 0  || root.first >= m  ||
            root.second < 0 || root.second >= n ||
            visited[root.first][root.second]    ||
            grid[root.first][root.second] == '0') {
            return;
        }
        
        visited[root.first][root.second] = true;
        std::vector<std::pair<int, int>> directions = {
            {0, 1}, // right
            {1, 0}, // down
            {0, -1}, // left
            {-1, 0} // up
        };
        for (int dir=0; dir<directions.size(); dir++) {
            growIslandFrom(grid, visited, {root.first+directions[dir].first, root.second+directions[dir].second});
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.front().size();
        deque<deque<bool>> visited(m, deque<bool>(n, false));
        
        int num_islands = 0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!visited[i][j] && grid[i][j] != '0') {
                    num_islands++;
                    // grow an island from the root {i,j}
                    growIslandFrom(grid, visited, {i,j});
                }
            }
        }
        
        return num_islands;
    }
};
