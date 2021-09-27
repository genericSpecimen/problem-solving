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
    void printOrder(vector<int> Xorder, pair<int, int> idx, string subtree, string order) {
        cout << subtree << " " << ": (" << idx.first << "," << idx.second << "): ";
        cout << "[";
        for (int i=idx.first; i<=idx.second; i++) {
            cout << Xorder[i] << ",";
        }
        cout << "]" << endl;        
    }
    
    TreeNode* build(vector<int>& preorder, pair<int, int> pr,
                    vector<int>& inorder,  pair<int, int> ir) {
        if (pr.first > pr.second || 
            ir.first > ir.second) {
            return nullptr;
        }
        
        // root is the first elem of preorder
        TreeNode* root = new TreeNode(preorder[pr.first]);
        // cout << "created node: " << root->val << endl;
        
        // find this elem's idx in inorder
        /*
        int root_idx = -1;
        for (int i=ir.first; i<=ir.second; i++) {
            if (inorder[i] == root->val) {
                root_idx = i;
                break;
            }
        }
        if (root_idx == -1) {
            cout << "could not find " << root->val << " in [" << ir.first << "," << ir.second << "]\n"; 
            assert(false);
        }
        */
        
        int root_idx = inorder_map[root->val];
        
        // cout << "found " << root->val << " at index " << root_idx << " in inorder" << endl;
        
        
        // build left subtree
        int left_size = root_idx - ir.first;
        pair<int, int> left_pr = {pr.first+1, pr.first+left_size};
        pair<int, int> left_ir = {ir.first, ir.first+left_size-1};
        
        //cout << "left size: " << left_size << endl;
        //printOrder(preorder, left_pr, "left", "preorder");
        //printOrder(inorder, left_ir, "left", "inorder");
        
        root->left = build(preorder, left_pr, inorder, left_ir);
        
        // build right subtree
        int right_size = ir.second - root_idx;
        pair<int, int> right_pr = {pr.first+left_size+1, pr.first+left_size+right_size};
        pair<int, int> right_ir = {ir.first+left_size+1, ir.first+left_size+right_size};
        
        //cout << "right size: " << right_size << endl;
        //printOrder(preorder, right_pr, "right", "preorder");
        //printOrder(inorder, right_ir, "right", "inorder");
        
        root->right = build(preorder, right_pr, inorder, right_ir);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i<inorder.size(); i++) inorder_map[inorder[i]] = i;
        
        return build(preorder, {0, preorder.size()-1},
                     inorder,  {0, inorder.size()-1});
    }
};
