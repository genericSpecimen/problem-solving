/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
    bool LCAhelper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &lca) {
        if (root == nullptr) return false;
        
        bool at_here = false;
        if (root == p || root == q) at_here = true;
        
        bool on_left = LCAhelper(root->left, p, q, lca);
        bool on_right = LCAhelper(root->right, p, q, lca);
        
        if (
            (at_here && on_left) ||
            (at_here && on_right) ||
            (on_left && on_right)
        ) {
            lca = root;
        }
        
        return at_here || on_left || on_right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return root;
        if (p == q) return p;
        
        TreeNode* lca = nullptr;
        LCAhelper(root, p, q, lca);
        
        return lca;
    }
    */
    
    /*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        if (p == q) return p;
        
        TreeNode* lca = nullptr;
        
        queue<TreeNode*> Q;
        unordered_map<TreeNode*, TreeNode*> parent;
        
        Q.push(root);
        parent[root] = nullptr;
        
        pair<bool, bool> found = {false, false};
        
        while (!Q.empty()) {
            TreeNode* curr = Q.front(); Q.pop();
            
            if (curr->left != nullptr) {
                parent[curr->left] = curr;
                Q.push(curr->left);
                
                if (curr->left == p) found.first = true;
                else if (curr->left == q) found.second = true;
            }
            if (curr->right != nullptr) {
                parent[curr->right] = curr;
                Q.push(curr->right);
                
                if (curr->right == p) found.first = true;
                else if (curr->right == q) found.second = true;
            }
            
            if (found.first && found.second) break;
        }
        
        // for(auto cp : parent) cout << cp.first->val << " : " << (cp.second ? cp.second->val : -1) << endl;
        if (!found.first || !found.second) assert(false);
        
        TreeNode* curr_p = p;
        unordered_set<TreeNode*> p_ancestors;
        
        while (curr_p != nullptr) {
            p_ancestors.insert(curr_p);
            curr_p = parent[curr_p];
        }
        
        TreeNode* curr_q = q;
        while (p_ancestors.find(curr_q) == p_ancestors.end()) {
            curr_q = parent[curr_q];
        }
        
        lca = curr_q;
        
        return lca;
    }
    */
    
    pair<TreeNode*, int> lcaHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return {nullptr, 0};
        
        auto left = lcaHelper(root->left, p, q);
        if (left.second == 2) return left;
        
        auto right = lcaHelper(root->right, p, q);
        if (right.second == 2) return right;
        
        int num_nodes_found = left.second + right.second;
        if (root == p || root == q) num_nodes_found++;
        
        if (num_nodes_found == 2) return {root, num_nodes_found};
        return {nullptr, num_nodes_found};
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        if (p == q) return p;
        
        return lcaHelper(root, p, q).first;
    }
};
