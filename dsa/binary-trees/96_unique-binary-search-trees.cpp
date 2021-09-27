class Solution {
public:
    int numTrees(int n) {
        // num_trees[0] = num_trees[1] = 1
        vector<long int> num_trees(n+1, 1);
        
        // start from num_nodes = 2
        for (int nodes=2; nodes < n+1; nodes++) {
            long int num_trees_using_nodes = 0;
            for (int root=1; root<nodes+1; root++) {
                int num_nodes_left = root - 1, num_nodes_right = nodes - root;
                num_trees_using_nodes += num_trees[num_nodes_left] * num_trees[num_nodes_right];
            }
            num_trees[nodes] = num_trees_using_nodes;
        }
        
        return num_trees[n];
    }
};
