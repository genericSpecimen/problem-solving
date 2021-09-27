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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<vector<int>> levels;
        vector<int> temp;
        
        queue<TreeNode*> q;
        q.push(root);
        levels.push_back({root->val});
        
        int num_nodes_curr_layer = 1, num_nodes_next_layer = 0, step = 0;
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            //cout << "exploring " << curr->val << ", step " << step << endl;
            
            if (curr->left != nullptr) {
                q.push(curr->left);
                temp.push_back(curr->left->val);
                //cout << "visited left: " << curr->left->val << endl;
                num_nodes_next_layer++;
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
                temp.push_back(curr->right->val);
                //cout << "visited right: " << curr->right->val << endl;
                num_nodes_next_layer++;
            }
            
            num_nodes_curr_layer--;
            if (num_nodes_curr_layer == 0) {
                num_nodes_curr_layer = num_nodes_next_layer;
                num_nodes_next_layer = 0;
                step++;
                
                if (!temp.empty()) {   
                    levels.push_back(temp);
                    temp = {};
                }
            }
        }
        
        return levels;
    }
    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<vector<int>> levels;
        vector<int> temp;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        temp.push_back(root->val);
        
        int prev_layer = -1;
        while (!q.empty()) {
            pair<TreeNode*, int> curr = q.front(); q.pop();
            //cout << "exploring " << curr.first->val << ", step " << curr.second << endl;
            
            if (curr.second > prev_layer) {
                // started exploring nodes in a new layer
                levels.push_back(temp);
                temp = {};
                prev_layer = curr.second;
            }
            
            if (curr.first->left != nullptr) {
                q.push({curr.first->left, curr.second+1});
                temp.push_back(curr.first->left->val);
                //cout << "visited left: " << curr.first->left->val << endl;
            }
            if (curr.first->right != nullptr) {
                q.push({curr.first->right, curr.second+1});
                temp.push_back(curr.first->right->val);
                //cout << "visited right: " << curr.first->right->val << endl;
            }
            
        }
        
        return levels;
    }
};
