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
    int dfs(TreeNode* root, int &diameter) {
        if (root == nullptr) return -1; // height of null = -1
        
        int left_height = dfs(root->left, diameter);
        int right_height = dfs(root->right, diameter);
        
        // "2" accounts for additional edges to each child
        diameter = std::max(diameter, left_height + right_height + 2);
        
        // return height of tree rooted at root
        return 1 + max(left_height, right_height);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = numeric_limits<int>::min();
        dfs(root, diameter);
        return diameter;
    }
};
