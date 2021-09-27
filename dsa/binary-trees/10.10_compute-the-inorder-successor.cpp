#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode() : val(0), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int x, TreeNode* parent) : val(x), left(nullptr), right(nullptr), parent(parent) {}
    TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode* parent)
            : val(x), left(left), right(right), parent(parent) {}
};

TreeNode* inorderSuccessor(TreeNode *root) {
    if (root == nullptr) return nullptr;
    
    TreeNode *curr = nullptr;
    
    if (root->right != nullptr) {
        // succ is the leftmost element in the right subtree of root
        curr = root->right;
        while (curr->left != nullptr) curr = curr->left;
        return curr;
    }
    
    // right subtree is nullptr, find closest ancestor whose left subtree contains node
    curr = root;
    while (curr->parent != nullptr && curr != curr->parent->left) {
        curr = curr->parent;
    }
    
    return curr->parent;
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    
    TreeNode* curr = root;
    TreeNode* last_visited = nullptr;
    while (curr) {
        if (curr->left && curr->left != last_visited) curr = curr->left;
        
        else {
            // no left subtree for curr, so process curr
            cout << curr->val << ", ";
            last_visited = curr;
            
            if (curr->right != nullptr) curr = curr->right;
            else {
                while (curr->parent != nullptr && curr != curr->parent->left) curr = curr->parent;
                last_visited = curr;
                curr = curr->parent;
            }
        }
        
    }
    
}

int main() {
    TreeNode *root = new TreeNode(1, nullptr);
    
    root->left = new TreeNode(2, root);
    root->right = new TreeNode(3, root);
    
    root->left->left = new TreeNode(4, root->left);
    root->left->right = new TreeNode(5, root->left);

    root->right->left = new TreeNode(6, root->right);
    root->right->right = new TreeNode(7, root->right);
    
    /*
    cout << inorderSuccessor(root)->val << endl;
    
    cout << inorderSuccessor(root->left)->val << endl;
    cout << inorderSuccessor(root->right)->val << endl;
     
    cout << inorderSuccessor(root->left->left)->val << endl;
    cout << inorderSuccessor(root->left->right)->val << endl;
    
    cout << inorderSuccessor(root->right->left)->val << endl;
    cout << boolalpha << (inorderSuccessor(root->right->right) == nullptr) << endl;
    */
    
    inorder(root);
}
