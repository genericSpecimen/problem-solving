/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* buildBST(ListNode* start, ListNode* end) {
        if (start == nullptr || end == nullptr || end->next == start) return nullptr;
        if (start == end) return new TreeNode(start->val);
                
        ListNode* prev = nullptr;
        ListNode* slow = start;
        ListNode* fast = start;
        
        while (fast != end && fast != end->next && fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow;
        
        //cout << "start: " << start->val << ", end : " << end->val << endl;
        //cout << "prev: " << (prev ? prev->val : -9999999) << ", mid: " << mid->val << endl;
        
        TreeNode* root = new TreeNode(mid->val);
        //cout << "=> created tree node : " << root->val << endl << endl;
        root->left = buildBST(start, prev);
        root->right = buildBST(mid->next, end);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode* curr = head;
        while (curr->next != nullptr) curr = curr->next;
        
        return buildBST(head, curr);
    }
};
