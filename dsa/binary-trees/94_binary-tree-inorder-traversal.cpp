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
    
    /*
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> traversed;
        stack<TreeNode*> st;
        
        TreeNode* curr = root;
        
        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                // need to process this data, but later
                st.push(curr);
                // for now, go left
                curr = curr->left;
            }
            
            // at this point, we've exhausted a left subtree
            // therefore, start processing data from the stack
            curr = st.top(); st.pop();
            traversed.push_back(curr->val);
            
            // now go right, and repeat the entire process all over again
            curr = curr->right;
            
        }
        
        return traversed;  
    }
    */
    
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> traversed;
        stack<TreeNode*> st;
        
        TreeNode* curr = root;
        
        while (curr != nullptr || !st.empty()) {
            if (curr != nullptr) {
                // need to process this data, but later
                st.push(curr);
                // for now, go left
                curr = curr->left;
            } else {
                // no left subtree
                curr = st.top(); st.pop();
                traversed.push_back(curr->val);

                // go right
                curr = curr->right;   
            }   
            
        }
        
        return traversed;  
    }
    
    /*
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> traversed;
        stack<pair<TreeNode*, int>> st;
        // 0: none, 1: L, 2: LD, 3: LDR
        st.push({root, 0});
        
        while (!st.empty()) {
            pair<TreeNode*, int> curr = st.top();
            
            switch (curr.second) {
                case 0: {
                    // left not done
                    if (curr.first->left == nullptr) {
                        //cout << "left done at : " << curr.first->val << endl;
                        st.top().second = 1;
                    } else {
                        st.push({curr.first->left, 0});
                        //cout << "pushed left " << curr.first->left->val << endl;
                    }
                    break;
                }
                case 1: {
                    // left done, now process data
                    traversed.push_back(curr.first->val);
                    //cout << "processed " << curr.first->val << endl;
                    st.top().second = 2;
                    break;
                }
                case 2: {
                    // left and data done
                    if (curr.first->right == nullptr) {
                        st.top().second = 3;
                    } else {
                        st.push({curr.first->right, 0});
                        //cout << "pushed right " << curr.first->right->val << endl;
                    }                    
                    break;
                }
                case 3: {
                        //cout << "finish: popping " << curr.first->val << endl;
                        st.pop();
                        if (!st.empty()) st.top().second += 1;
                        break;
                }
            }     
        }
        
        return traversed;
    }
    */
};
