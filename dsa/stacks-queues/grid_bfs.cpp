#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;



std::ostream& operator<<(std::ostream &os, std::queue<std::pair<int, int>> q) {
    os << "[";
    
    while (!q.empty()) {
        cout << "(" << q.front().first << "," << q.front().second << ")" << ", ";
        q.pop();
    }
    
    os << "]";
    return os;
}

void bfs(vector<vector<int>> &mat, pair<int, int> root) {
    if (mat.empty()) return;
    int m = mat.size(), n = mat.front().size(); 
    
    deque<deque<bool>> visited(m, deque<bool>(n, false));
    vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
    
    queue<pair<int, int>> q;
    
    q.push({root.first, root.second});
    visited[root.first][root.second] = true;
    
    cout << q << endl;
    
    int step = 0, num_nodes_curr_layer = 1, num_nodes_next_layer = 0;
    
    vector<pair<int, int>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    
    
    while (!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();
        
        cout << "=> Exploring node at index (" << curr.first << "," << curr.second << ")";
        cout << ", val = " << mat[curr.first][curr.second] << ", dist from root = " << step << endl;
        dist[curr.first][curr.second] = step;
        
        for (auto dir : directions) {
            pair<int, int> neighbor = {curr.first + dir.first, curr.second + dir.second};
            if (neighbor.first >= 0 && neighbor.first < m &&
                neighbor.second >= 0 && neighbor.second < n &&
                !visited[neighbor.first][neighbor.second] && mat[neighbor.first][neighbor.second] != -1) {
                    // valid neighbor
                    
                    cout << "\tPushing unvisited neighbor at index = (" << neighbor.first <<
                    "," << neighbor.second << "), val = " << mat[neighbor.first][neighbor.second] << endl;  
                    q.push(neighbor);
                    visited[neighbor.first][neighbor.second] = true;
                    num_nodes_next_layer++;
            }
        }
        
        num_nodes_curr_layer--;
        if (num_nodes_curr_layer == 0) {
            num_nodes_curr_layer = num_nodes_next_layer;
            num_nodes_next_layer = 0;
            step++;
        }
        
        cout << q << endl;
    }
    
    cout << "[";
    for (auto row : dist) {
        cout << "[";
        for (auto elem : row) {
            cout << elem << ", ";
        }
        cout << "]\n";
    }
    cout << "]";
    
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, -1, -1},
        {7, -1, 9}
    };
    
    bfs(mat, {0, 0});
}
