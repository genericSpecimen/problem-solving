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
    void postorder(TreeNode* root, vector<int> &traversed) {
        if (root == nullptr) return;
        
        postorder(root->left, traversed);
        postorder(root->right, traversed);
        
        traversed.push_back(root->val);
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> traversed;
        
        postorder(root, traversed);
        
        return traversed;
    }
    */
    /*
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> traversed;
        stack<pair<TreeNode*, int>> st;
        // 0: none, 1: L, 2: LR, 3: LRD
        st.push({root, 0});
        
        while (!st.empty()) {
            pair<TreeNode*, int> curr = st.top();
            
            switch (curr.second) {
                case 0: {
                    // left not done
                    if (curr.first->left == nullptr) {
                        cout << "left done at : " << curr.first->val << endl;
                        st.top().second = 1;
                    } else {
                        st.push({curr.first->left, 0});
                        cout << "pushed left " << curr.first->left->val << endl;
                    }
                    break;
                }
                case 1: {
                    // left done, now do right
                    if (curr.first->right == nullptr) {
                        st.top().second = 2;
                        cout << "right done at : " << curr.first->val << endl;
                    } else {
                        st.push({curr.first->right, 0});
                        cout << "pushed right " << curr.first->right->val << endl;
                    }                    
                    break;
                }
                case 2: {
                    // left and right done, now process data
                    traversed.push_back(curr.first->val);
                    cout << "processed " << curr.first->val << endl;
                    st.top().second = 3;
                    break;
                }
                case 3: {
                        cout << "finish: popping " << curr.first->val << endl;
                        st.pop();
                        if (!st.empty()) st.top().second += 1;
                        break;
                }
            }     
        }
        
        return traversed;
    }
    */
    
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> traversed;
        stack<TreeNode*> st;
        
        TreeNode* curr = root;
        TreeNode* last_visited = nullptr;
        while (curr != nullptr || !st.empty()) {
            if (curr != nullptr) {
                // process curr later on
                st.push(curr);
                // first go left
                curr = curr->left;
            } else {
                // exhausted left subtree
                TreeNode* peek = st.top();
                // go right if necessary
                if (peek->right != nullptr && last_visited != peek->right) {
                    curr = peek->right;
                } else {
                    // process top of stack (peeked node)
                    traversed.push_back(peek->val);
                    last_visited = peek; st.pop();
                }
            }
        }
        
        return traversed;
    }
    
};
