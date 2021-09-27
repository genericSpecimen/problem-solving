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
    void preorder(TreeNode* root, string curr_path, vector<string> &paths) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            paths.push_back(curr_path);
            return;
        }
        if (root->left != nullptr) preorder(root->left, curr_path + "->" + std::to_string(root->left->val), paths);
        if (root->right != nullptr) preorder(root->right, curr_path + "->" + std::to_string(root->right->val), paths);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        preorder(root, std::to_string(root->val), paths);
        return paths;
    }
};
