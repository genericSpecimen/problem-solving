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
    pair<bool, int> isBalancedHelper(TreeNode* root) {
        if (root == nullptr) return {true, -1};
        
        auto left = isBalancedHelper(root->left);
        if (!left.first) return {false, INT_MIN};
        
        auto right = isBalancedHelper(root->right);
        if (!right.first) return {false, INT_MIN};
        
        bool is_balanced = std::abs(left.second - right.second) <= 1;
        int height = 1 + std::max(left.second, right.second);
        
        return {is_balanced, height};
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        
        auto root_balanced = isBalancedHelper(root);
        return root_balanced.first;
    }
};
