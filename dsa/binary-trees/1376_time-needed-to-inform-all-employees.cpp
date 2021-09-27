class Solution {
public:
    /*
    // this BFS approach doesn't work
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> subordinates;
        for (int i=0; i<manager.size(); i++) subordinates[manager[i]].push_back(i);
        
        // first : employee ID, second : depth
        queue<pair<int, int>> Q;
        Q.push({headID, 0});
        
        int time_to_inform = 0, max_time_to_inform_next_layer = 0;
        
        int prev_layer = -1, curr_layer;
        while (!Q.empty()) {
            auto curr = Q.front(); Q.pop();
            curr_layer = curr.second;
            
            if (curr_layer > prev_layer) {
                time_to_inform += max_time_to_inform_next_layer;
                max_time_to_inform_next_layer = informTime[curr.first];
                prev_layer = curr_layer;
            } else {
                max_time_to_inform_next_layer = std::max(max_time_to_inform_next_layer, informTime[curr.first]);
            }
            
            for (int sub : subordinates[curr.first]) {
                Q.push({sub, curr_layer + 1});
            }
        }
        
        return time_to_inform;
    }
    */
    
    int dfs(int ID, unordered_map<int, vector<int>> &subordinates, vector<int> &informTime) {
        int max_time = 0;
        
        for (int sub : subordinates[ID]) {
            max_time = std::max(max_time, informTime[ID] + dfs(sub, subordinates, informTime));
        }
        return max_time;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> subordinates;
        for (int i=0; i<manager.size(); i++) subordinates[manager[i]].push_back(i);
        
        // find leaf with maximum time required
        return dfs(headID, subordinates, informTime);
    }
};
