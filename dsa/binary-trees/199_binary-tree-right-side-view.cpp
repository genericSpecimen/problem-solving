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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> view;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        int prev_layer = -1;
        TreeNode *prev = nullptr;
        while (!q.empty()) {
            pair<TreeNode*, int> curr = q.front(); q.pop();
            //cout << "popped: " << curr.first->val << endl;
            if (curr.second > prev_layer) {
                // new layer
                if (prev != nullptr) view.push_back(prev->val);
                prev = curr.first;
                prev_layer = curr.second;
            } else {
                prev = curr.first;
            }
            
            // explore curr
            if (curr.first->left != nullptr) {
                q.push({curr.first->left, curr.second+1});
                //cout << "pushed: " << curr.first->left->val << endl;
            }
            if (curr.first->right != nullptr) {
                q.push({curr.first->right, curr.second+1});
                //cout << "pushed: " << curr.first->right->val << endl;
            }
        }
        view.push_back(prev->val);
        
        return view;
    }
};
