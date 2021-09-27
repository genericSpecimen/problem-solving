/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    /*
    TreeNode* LCAhelper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) return LCAhelper(root->left, p, q);
        else if (p->val > root->val && q->val > root->val) return LCAhelper(root->right, p, q);
        
        // p and q diverge from here, there can be no other common ancestor except root
        return root;
    }
    */
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        if (p == q) return p;
        
        //return LCAhelper(root, p, q);
        
        // iterative
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (p->val < curr->val && q->val < curr->val) curr = curr->left;
            else if (p->val > curr->val && q->val > curr->val) curr = curr->right;
            else return curr;
        }
        
        assert(false);
        return nullptr;
    }
};
