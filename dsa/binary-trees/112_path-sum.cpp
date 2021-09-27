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
    bool dfs(TreeNode* root, int currSum, int targetSum) {
        if (root->left == nullptr &&
            root->right == nullptr &&
            currSum == targetSum) {
            return true;
        }
        
        bool has_left_path_sum = false;
        if (root->left != nullptr) {
            has_left_path_sum = dfs(root->left, currSum + root->left->val, targetSum);
        }
        
        bool has_right_path_sum = false;
        if (root->right != nullptr) {
            has_right_path_sum = dfs(root->right, currSum + root->right->val, targetSum);
        }
        
        return has_left_path_sum || has_right_path_sum;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return dfs(root, root->val, targetSum);
    }
    */
    
    /*
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) return true;
        
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
    */
    
    /*
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        
        stack<pair<TreeNode*, int>> st;
        st.push({root, targetSum});
        
        while (!st.empty()) {
            pair<TreeNode*, int> curr = st.top(); st.pop();
            
            if (curr.first->left  == nullptr &&
                curr.first->right == nullptr &&
                curr.first->val == curr.second) {
                return true;
            }
            
            if (curr.first->left != nullptr) {
                st.push({curr.first->left, curr.second - curr.first->val});
            }
            
            if (curr.first->right != nullptr) {
                st.push({curr.first->right, curr.second - curr.first->val});
            }
        }
        
        return false;
    }
    */
    
    bool hasPathSumHelper(TreeNode* root, int curr_sum, int targetSum) {
        if (root == nullptr) return false;
        
        int running_sum = curr_sum + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return (running_sum == targetSum);
        }
        
        return hasPathSumHelper(root->left, running_sum, targetSum) ||
               hasPathSumHelper(root->right, running_sum, targetSum);
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        
        return hasPathSumHelper(root, 0, targetSum);
    }
};
