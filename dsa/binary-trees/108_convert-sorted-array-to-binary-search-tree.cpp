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
    TreeNode* buildBST(vector<int>& nums, pair<int, int> idx) {
        if (idx.first > idx.second) return nullptr;
        
        //int mid = (idx.first + idx.second ) / 2;
        int mid = idx.first + (idx.second - idx.first) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = buildBST(nums, {idx.first, mid-1});
        root->right = buildBST(nums, {mid+1, idx.second});
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return buildBST(nums, {0, nums.size()-1});
    }
};
