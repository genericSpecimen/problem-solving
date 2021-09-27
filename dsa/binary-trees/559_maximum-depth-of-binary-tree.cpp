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
    void maxDepthHelper(Node* root, int curr_depth, int &max_depth) {
        if (root == nullptr) return;
        
        if (root->children.empty()) {
            // leaf node, update ans
            max_depth = std::max(max_depth, curr_depth);
        }
        
        for (auto &child : root->children) {
            maxDepthHelper(child, curr_depth+1, max_depth);
        }
    }
    
    int maxDepth(Node* root) {
        int max_depth = -1;
        
        if (root == nullptr) return max_depth + 1;
        
        maxDepthHelper(root, 0, max_depth);
        
        return max_depth + 1;
    }
    */
    
    int maxDepth(Node* root) {
        int max_depth = -1;
        
        if (root == nullptr) return max_depth + 1;
        
        stack<pair<Node*, int>> st;
        st.push({root, 0});
        
        while (!st.empty()) {
            pair<Node*, int> curr = st.top(); st.pop();
            
            if (curr.first->children.empty()) {
                max_depth = max(curr.second, max_depth);
            } else {
                for (auto &child : curr.first->children) {
                    st.push({child, curr.second + 1});
                }
            }
        }
        
        
        return max_depth + 1;
    }
};
