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
    int dfs(TreeNode* root, int &lup) {
        if (root == nullptr) return 0;
        
        int left_lup = dfs(root->left, lup);
        int right_lup = dfs(root->right, lup);
        
        int left_with_root_lup = 0;
        if (root->left && root->left->val == root->val) left_with_root_lup = left_lup + 1;
        
        int right_with_root_lup = 0;
        if (root->right && root->right->val == root->val) right_with_root_lup = right_lup + 1;
        
        lup = std::max(lup, left_with_root_lup + right_with_root_lup);
        
        return max(left_with_root_lup, right_with_root_lup);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        int lup = numeric_limits<int>::min();
        dfs(root, lup);
        return lup;
    }
};
