/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    /*
    void postorderTraversal(Node* root, vector<int> &traversed) {
        if (root == nullptr) return;
        
        for (auto &child : root->children) {
            postorderTraversal(child, traversed);
        }
        
        traversed.push_back(root->val);
        
    }
    vector<int> postorder(Node* root) {
        if (root == nullptr) return {};
        
        vector<int> traversed;
        
        postorderTraversal(root, traversed);
        
        return traversed;
    }
    */

    vector<int> postorder(Node* root) {
        if (root == nullptr) return {};
        
        vector<int> traversed;
        stack<pair<Node*, int>> st;
        
        st.push({root, 0});
        
        while (!st.empty()) {
            Node* curr = st.top().first;
            int c_idx = st.top().second;
            
            if (c_idx == curr->children.size()) {
                // finished processing all children of curr
                // now process curr
                traversed.push_back(curr->val);
                st.pop();
                if (!st.empty()) st.top().second++;
            } else {
                st.push({curr->children[c_idx], 0});
            }
        }
        
        return traversed;
    }
    
    
};
