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
    /*
    bool isMirror(TreeNode* n1, TreeNode* n2) {
        // trivial mirror images: empty trees
        if (n1 == nullptr && n2 == nullptr) return true;
        // an empty and a non empty tree can never be mirror images
        if (n1 == nullptr || n2 == nullptr) return false;
        
        // otherwise, both trees are non empty
        if (n1->val == n2->val &&
            isMirror(n1->left, n2->right) &&
            isMirror(n1->right, n2->left)) {
            return true;
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        
        // check if left and right subtree are mirror images of each other
        return isMirror(root->left, root->right);
    }
    */
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        
        stack<pair<TreeNode*, TreeNode*>> st;
        
        // check if left and right subtree are mirror images of each other
        st.push({root->left, root->right});
        
        while (!st.empty()) {
            pair<TreeNode*, TreeNode*> curr = st.top(); st.pop();
            
            // trivial mirror images: empty trees, continue processing other nodes
            if (curr.first == nullptr && curr.second == nullptr) continue;
            // an empty and a non empty tree can never be mirror images
            if (curr.first == nullptr || curr.second == nullptr) return false;
            
            if (curr.first->val != curr.second->val) return false;
            
            // check if left subtree of first is a mirror image of right subtree of second
            st.push({curr.first->left, curr.second->right});
            // check if right subtree of first is a mirror image of left subtree of second
            st.push({curr.first->right, curr.second->left});
        }
        
        // at this point, all node pairs in the stack have been processed
        // and none of processing resulted in false
        return true;
    }
    
    
};
