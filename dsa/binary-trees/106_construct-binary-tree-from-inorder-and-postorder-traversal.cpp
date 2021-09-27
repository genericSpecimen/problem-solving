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
    unordered_map<int, int> inorder_map;
    TreeNode* build(vector<int>& inorder, pair<int, int> ir,
                    vector<int>& postorder, pair<int, int> pr) {
        if (ir.first > ir.second ||
            pr.first > pr.second) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[pr.second]);
        
        int root_idx = inorder_map[root->val];
        
        // build left subtree
        int left_size = root_idx - ir.first;
        pair<int, int> left_ir = {ir.first, ir.first+left_size-1};
        pair<int, int> left_pr = {pr.first, pr.first+left_size-1};
        root->left = build(inorder, left_ir, postorder, left_pr);
        
        
        // build right subtree
        int right_size = ir.second - root_idx;
        pair<int, int> right_ir = {ir.first+left_size+1, ir.first+left_size+right_size}; 
        pair<int, int> right_pr = {pr.first+left_size, pr.first+left_size+right_size-1};
        root->right = build(inorder, right_ir, postorder, right_pr);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i=0; i<inorder.size(); i++) inorder_map[inorder[i]] = i;
        return build(inorder, {0, inorder.size()-1},
                     postorder, {0, postorder.size()-1});
    }
};
