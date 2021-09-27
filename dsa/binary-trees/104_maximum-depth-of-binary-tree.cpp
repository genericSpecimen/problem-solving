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
    void maxDepthHelper(TreeNode* root, int curr_depth, int &max_depth) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            // leaf node, update ans
            max_depth = std::max(curr_depth, max_depth);
        }
        maxDepthHelper(root->left, curr_depth+1, max_depth);
        maxDepthHelper(root->right, curr_depth+1, max_depth);
    }
    
    int maxDepth(TreeNode* root) {
        int max_depth = -1;
        
        if (root == nullptr) return max_depth + 1;
        
        // depth of root node is 0
        maxDepthHelper(root, 0, max_depth);
        
        // question says depth = number of "nodes", instead of edges
        return max_depth + 1;
    }
    */
    
    /*
    int maxDepth(TreeNode* root) {
        int max_depth = -1;
        
        if (root == nullptr) return max_depth + 1;
        
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        
        while (!st.empty()) {
            pair<TreeNode*, int> curr = st.top(); st.pop();
            
            if (curr.first->left == nullptr && curr.first->right == nullptr) {
                max_depth = max(curr.second, max_depth);
            } else {
                if (curr.first->left != nullptr) st.push({curr.first->left, curr.second + 1});
                if (curr.first->right != nullptr) st.push({curr.first->right, curr.second + 1});
            }
        }
        
        return max_depth + 1;
    }
    */
    
    
    int height(TreeNode* root) {
        if (root == nullptr) return -1;
        return 1 + std::max(height(root->left), height(root->right));
    }
    
    int maxDepth(TreeNode* root) {
        return 1 + height(root);
    }
};
