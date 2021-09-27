/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    /*
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        int prev_layer = -1;
        Node *prev = nullptr;
        
        while (!q.empty()) {
            pair<Node*, int> curr = q.front(); q.pop();
            //cout << "popped: " << curr.first->val << endl;
            if (curr.second > prev_layer) {
                // start chaining a new layer
                //cout << "start chaining new layer: " << curr.second << " at " << curr.first->val << endl;
                if (prev != nullptr) prev->next = nullptr;
                prev = curr.first;
                prev_layer = curr.second;
            } else if (curr.second == prev_layer) {
                //cout << "continue chaining layer: " << curr.second << endl;
                //cout << "=> chained: " << curr.first->val << endl;
                prev->next = curr.first;
                prev = prev->next;
            }
            
            // explore curr
            if (curr.first->left != nullptr) {
                q.push({curr.first->left, curr.second+1});
                //cout << "pushed: " << curr.first->left->val << endl;
            }
            if (curr.first->right != nullptr) {
                q.push({curr.first->right, curr.second+1});
                //cout << "pushed: " << curr.first->right->val << endl;
            }
        }
        
        return root;
    }
    */
    
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        
        Node* dummy = new Node();
        Node* prev = dummy;
        Node* curr = root;
        
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                prev->next = curr->left;
                prev = prev->next;
            }
            
            if (curr->right != nullptr) {
                prev->next = curr->right;
                prev = prev->next;
            }
            
            curr = curr->next;
            if (curr == nullptr) {
                // finished current level
                prev = dummy;
                curr = dummy->next;
                dummy->next = nullptr;
            }
        }
        
        return root;  
    }
};
