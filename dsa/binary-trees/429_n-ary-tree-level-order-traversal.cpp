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
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        
        vector<vector<int>> levels;
        vector<int> temp;
        
        queue<Node*> q;
        q.push(root);
        levels.push_back({root->val});
        
        int num_nodes_curr_layer = 1, num_nodes_next_layer = 0, step = 0;
        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            //cout << "exploring " << curr->val << ", step " << step << endl;
            
            for (auto &child : curr->children) {
                q.push(child);
                temp.push_back(child->val);
                //cout << "visited child: " << child->val << endl;
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
    
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        
        vector<vector<int>> levels;
        vector<int> temp;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        temp.push_back(root->val);
        
        int prev_layer = -1;
        while (!q.empty()) {
            pair<Node*, int> curr = q.front(); q.pop();
            //cout << "exploring " << curr.first->val << ", step " << curr.second << endl;
            
            if (curr.second > prev_layer) {
                // started exploring nodes in a new layer
                levels.push_back(temp);
                temp = {};
                prev_layer = curr.second;
            }
            
            for (auto &child : curr.first->children) {
                q.push({child, curr.second+1});
                temp.push_back(child->val);
                //cout << "visited child: " << child->val << endl;
            }
        }
        
        return levels;
    }
};
