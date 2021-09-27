class Solution {
public:
    int numSquares(int n) {
        int sum = 0;
        int n_sqrt = sqrt(n);
        
        queue<int> Q;
        Q.push(0);
        
        int steps = 0, num_nodes_curr_layer = 1, num_nodes_next_layer = 0;
        
        while (!Q.empty()) {
            int curr = Q.front(); Q.pop();
            
            for (int i=1; i<=n_sqrt; i++) {
                int next = i*i;
                
                if (curr + next == n) return steps+1;
                
                Q.push(curr + next);
                num_nodes_next_layer++;
            }
            
            num_nodes_curr_layer--;
            if (num_nodes_curr_layer == 0) {
                num_nodes_curr_layer = num_nodes_next_layer;
                num_nodes_next_layer = 0;
                steps++;
            }
        }
        
        return -1;
    }
};
