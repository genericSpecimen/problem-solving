/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void dfs(TreeNode* root, pair<int, int> pos, map<int, map<int, multiset<int>>> &visited) {
        if (root == nullptr) return;
        visited[pos.second][pos.first].insert(root->val);
        
        dfs(root->left, {pos.first+1, pos.second-1}, visited);
        dfs(root->right, {pos.first+1, pos.second+1}, visited);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> vertical_traversal;
        vector<int> curr_column;
        
        //  col      row  node
        //map<int, map<int, TreeNode*>> visited;
        map<int, map<int, multiset<int>>> visited;
        dfs(root, {0, 0}, visited);
        
        for (auto col=visited.begin(); col!=visited.end(); col++) {
            curr_column = {};
            for (auto row=col->second.begin(); row!=col->second.end(); row++) {
                for (auto it=row->second.begin(); it!= row->second.end(); it++) {
                    //cout << "(" << col->first << ", " << row->first << ") : " << *it << ", ";
                    curr_column.push_back(*it);
                }
                //cout << endl;
            }
            //cout << endl;
            vertical_traversal.push_back(curr_column);
        }
       return vertical_traversal; 
    }
};
