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
    TreeNode* build(vector<int>& preorder, pair<int, int> pr, vector<int>& nextg_idx) {
        if (pr.first > pr.second) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[pr.first]);
        int root_nextg_idx = nextg_idx[pr.first];
                
        if (root_nextg_idx == -1 || root_nextg_idx > pr.second) {
            root->left = build(preorder, {pr.first+1, pr.second}, nextg_idx);
            return root;
        }
        
        int left_size = root_nextg_idx - (pr.first + 1);
        pair<int, int> left_pr = {pr.first+1, pr.first+left_size};
        root->left = build(preorder, left_pr, nextg_idx);
        
        int right_size = pr.second - root_nextg_idx + 1;
        pair<int, int> right_pr = {pr.first+left_size+1, pr.first+left_size+right_size};
        root->right = build(preorder, right_pr, nextg_idx);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        
        vector<int> nextg_idx(preorder.size(), -1);
        
        stack<int> st;
        for (int i=preorder.size()-1; i>=0; i--) {
            while (!st.empty() && preorder[st.top()] <= preorder[i]) {
                st.pop();
            }
            
            if (!st.empty()) nextg_idx[i] = st.top();
            
            st.push(i);
        }
        
        //for(auto i : nextg_idx) cout << i << ",";
        //cout << endl;
        
        return build(preorder, {0, preorder.size()-1}, nextg_idx);
    }
};
