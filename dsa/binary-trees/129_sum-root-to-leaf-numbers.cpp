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
    void dfs(TreeNode* root, int num, int &sum) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            // leaf
            sum += num * 10 + root->val;
        }
        dfs(root->left, num * 10 + root->val, sum);
        dfs(root->right, num * 10 + root->val, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        
        dfs(root, 0, sum);
        
        return sum;
    }
};
