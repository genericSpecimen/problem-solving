class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.empty()) return true;
        
        deque<bool> visited(rooms.size(), false);
        
        queue<int> Q;
        Q.push(0);
        visited[0] = true;
        int num_visited = 1;
        
        while (!Q.empty()) {
            int current_room = Q.front(); Q.pop();
            
            for (auto next_room : rooms[current_room]) {
                if (!visited[next_room]) {
                    visited[next_room] = true;
                    num_visited++;
                    Q.push(next_room);
                }
            }
        }
        
        return num_visited == rooms.size();
    }
};
