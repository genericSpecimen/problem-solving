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
    int maxGain(TreeNode* root, int &mps) {
        if (root == nullptr) return 0;
        
        int max_left_gain  = std::max(maxGain(root->left, mps), 0); // 0 to not choose negative values
        int max_right_gain = std::max(maxGain(root->right, mps), 0);
        
        int mps_with_split = root->val + max_left_gain + max_right_gain;
        mps = std::max(mps, mps_with_split);
        
        int mps_without_split = root->val + std::max(max_left_gain, max_right_gain);
        mps = std::max(mps, mps_without_split);
        
        return mps_without_split;
    }
    
    
    int maxPathSum(TreeNode* root) {
        int mps = numeric_limits<int>::min();
        maxGain(root, mps);
        return mps;
    }
};
