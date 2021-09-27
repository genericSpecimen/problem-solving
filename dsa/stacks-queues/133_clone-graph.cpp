/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // DFS iteratively
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        
        unordered_map<Node*, Node*> cloned;
        
        // clone the first node
        Node* cnode = new Node(node->val);
        cloned[node] = cnode;
        
        // push it onto stack to clone its neighbors
        stack<Node*> st;
        st.push(node);
        
        while (!st.empty()) {
            Node* curr = st.top(); st.pop();
            
            for (auto &neighbor : curr->neighbors) {
                if (cloned.find(neighbor) == cloned.end()) {
                    // clone the neighbor
                    Node* c_neighbor = new Node(neighbor->val);
                    cloned[neighbor] = c_neighbor;
                    // push it onto stack to clone its neighbors
                    st.push(neighbor);
                }
                
                // update the neighbors of cloned[curr]
                cloned[curr]->neighbors.push_back(cloned[neighbor]);
            }
        }

        return cloned[node];
    }    
    
    /*
    // DFS recursively
    Node* clone(Node* node, unordered_map<Node*, Node*> &cloned) {
        if (node == nullptr) return nullptr;
        
        Node* cnode = new Node(node->val, node->neighbors);
        cloned[node] = cnode;
        //cout << "cloned " << node->val << ", o: " << node << " c: " << cnode << endl;
        
        for (auto &n : cnode->neighbors) {
            if (cloned.find(n) == cloned.end()) {
                //cout << "node " << cnode->val << " : not cloned yet: " << n->val << endl;
                n = clone(n, cloned);
            } else {
                //cout << "node " << cnode->val << " : already cloned: " << n->val << endl;
                n = cloned[n];
            }
        }
        
        return cnode;
        
    }
    
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        
        unordered_map<Node*, Node*> cloned;
        
        Node* cnode = clone(node, cloned);
        
        
        //cout << endl;
        //for (auto n : cnode->neighbors) {
        //    cout << n << ", ";
        //}
        
        
        return cnode;
    }
    */
    
    /*
    // BFS using a queue
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        
        unordered_map<Node*, Node*> cloned;
        queue<Node*> q;
        
        // clone first node
        Node* cnode = new Node(node->val);
        cloned[node] = cnode;
        
        // push to queue to clone neighbors of the first node
        q.push(node);
        
        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            
            for (auto &neighbor : curr->neighbors) {
                if (cloned.find(neighbor) == cloned.end()) {
                    // clone the neighbor
                    Node* c_neighbor = new Node(neighbor->val);
                    cloned[neighbor] = c_neighbor;
                    // push the neighbor onto the queue so that its neighbors can be cloned
                    q.push(neighbor);
                }
                // update the neighbors for cloned[curr]
                cloned[curr]->neighbors.push_back(cloned[neighbor]);
            }
        }
        
        return cloned[node];
    }
    */
    
};
