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

    void pathSumHelper(TreeNode* root,
                       int curr_sum, vector<int> curr_path,
                       int targetSum, vector<vector<int>> &result) {
        if (root == nullptr) return;
        
        int running_sum = curr_sum + root->val;
        curr_path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (running_sum == targetSum) result.push_back(curr_path);
        }
        
        pathSumHelper(root->left, running_sum, curr_path, targetSum, result);
        pathSumHelper(root->right, running_sum, curr_path, targetSum, result);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};
        
        vector<vector<int>> result;
        pathSumHelper(root, 0, {}, targetSum, result);
        
        return result;
    }
};
