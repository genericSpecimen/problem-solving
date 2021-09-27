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
    // DFS
    void minDepthHelper(TreeNode* root, int curr_depth, int &min_depth) {
        if (root == nullptr) return;
        
        if (root->left == nullptr && root->right == nullptr) {
            // leaf node, update min_depth
            min_depth = std::min(min_depth, curr_depth);
        }
        
        minDepthHelper(root->left, curr_depth+1, min_depth);
        minDepthHelper(root->right, curr_depth+1, min_depth);
    }
    
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int min_depth = numeric_limits<int>::max();
        
        minDepthHelper(root, 0, min_depth);
        
        return min_depth + 1;
    }
    */
    
    // BFS
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int min_depth = numeric_limits<int>::max();
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            pair<TreeNode*, int> curr = q.front(); q.pop();
            
            if (curr.first->left == nullptr && curr.first->right == nullptr) {
                // leaf node
                min_depth = std::min(min_depth, curr.second);
                // first leaf encountered has minimum depth, so we can prematurely break
                break;
            } else {
                if (curr.first->left != nullptr) q.push({curr.first->left, curr.second+1});
                if (curr.first->right != nullptr) q.push({curr.first->right, curr.second+1});
            }
        }
        
        
        return min_depth + 1;
    }
};
