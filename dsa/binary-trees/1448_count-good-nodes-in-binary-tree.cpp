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
    int dfs(TreeNode* root, int max_so_far) {
        if (root == nullptr) return 0;
        
        int num_good = 0;
        if (root->val >= max_so_far) num_good++;
        
        max_so_far = std::max(root->val, max_so_far);
        num_good += dfs(root->left, max_so_far);
        num_good += dfs(root->right, max_so_far);
        
        return num_good;
    }
    
    int goodNodes(TreeNode* root) {
        return dfs(root, numeric_limits<int>::min());
    }
};
