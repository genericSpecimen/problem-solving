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
    void inorder(TreeNode* root, vector<int> &result) {
        if (root == nullptr) {
            return;
        }
        
        if (root->left != nullptr) {
            inorder(root->left, result);
        }
        
        result.push_back(root->val);
        
        if (root->right != nullptr) {
            inorder(root->right, result);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
    */
    
    /*
    // uses a stack and visited set
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> result;
        stack<TreeNode*> st;
        unordered_set<TreeNode*> printed;
        
        st.push(root);
        
        
        while (!st.empty()) {
            TreeNode *curr = st.top();
            //cout << "popped " << curr->val << endl;
            
            if (curr->left != nullptr && printed.find(curr->left) == printed.end()) {
                //cout << "pushing " << curr->left->val << endl;
                st.push(curr->left);
            } else {
                printed.insert(curr);
                result.push_back(curr->val);
                st.pop();
                
                if (curr->right != nullptr && printed.find(curr->right) == printed.end()) {
                    st.push(curr->right);
                    //cout << "pushing " << curr->right->val << endl;
                }
            }
            
        }
        
        return result;
    }
    */
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        
        TreeNode* curr = root;
        
        while (curr != nullptr || !st.empty()) {
            // keep going left until a leaf is reached - (until you can)
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // no more left nodes, so process root node
            curr = st.top(); st.pop();
            result.push_back(curr->val);
            
            curr = curr->right;
            
        }
        
        return result;
    }
};
