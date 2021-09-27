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
    void preorder(TreeNode* root, vector<int> &traversed) {
        if (root == nullptr) {
            return;
        }
        
        traversed.push_back(root->val);
        preorder(root->left, traversed);
        preorder(root->right, traversed);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversed;
        
        preorder(root, traversed);
        
        return traversed;
        
    }
    */
    /*
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> traversed;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* curr = st.top(); st.pop();
            traversed.push_back(curr->val);
            
            if (curr->right != nullptr) st.push(curr->right);
            if (curr->left  != nullptr) st.push(curr->left);
            
        }
        
        
        return traversed;
        
    }
    */
    
    
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> traversed;
        stack<pair<TreeNode*, int>> st;
        // 0: none, 1: D, 2: DL, 3: DLR
        st.push({root, 0});
        
        while (!st.empty()) {
            pair<TreeNode*, int> curr = st.top();
            
            switch (curr.second) {
                case 0: {
                    // data not done
                    traversed.push_back(curr.first->val);
                    cout << "processed " << curr.first->val << endl;
                    st.top().second = 1;
                    break;
                }
                case 1: {
                    // data done, left not done
                    if (curr.first->left == nullptr) {
                        cout << "left done at : " << curr.first->val << endl;
                        st.top().second = 2;
                    } else {
                        st.push({curr.first->left, 0});
                        cout << "pushed left " << curr.first->left->val << endl;
                    }
                    break;
                }
                case 2: {
                    // data and left done
                    if (curr.first->right == nullptr) {
                        st.top().second = 3;
                    } else {
                        st.push({curr.first->right, 0});
                        cout << "pushed right " << curr.first->right->val << endl;
                    }                    
                    break;
                }
                case 3: {
                        cout << "finish: popping " << curr.first->val << endl;
                        st.pop();
                        if (!st.empty()) st.top().second += 1;
                }
            }     
        }
        
        return traversed;
    }
};
