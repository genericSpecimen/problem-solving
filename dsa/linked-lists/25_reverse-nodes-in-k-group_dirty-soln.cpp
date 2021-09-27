#include <iostream>
#include <vector>
#include "LinkedList.h"

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k == 1) {
        // empty list, or,
        // reverse 1 at a time = same as original list
        return head;
    }
    
    /*
     * head of the final list is the head of the
     * first reversed sublist of k nodes.
     * For each sublist of k-nodes, maintain:
     * 1. curr_tail : the tail of the sublist
     * 2. 
     */
    
    
    ListNode *curr = head;
    ListNode *temp = head->next;
    
    
    // used during fixing links between two different k-sublists
    // dummy head to ease operations in the sublist merging
    ListNode *dummy_head = new ListNode(-1);
    ListNode *prev_tail = dummy_head;
    
    ListNode *curr_tail = head;
    
    // number of nodes processed
    int p = 0;
    
    
    ListNode *temp1 = nullptr;
    while (temp != nullptr) {
        // the tail of the current sublist under consideration will be the current node
        p++;
        if (p == k) {
            // fix links between two sublists of k nodes
            //std::cout << "prev tail = " << prev_tail->val << ", curr tail = " << curr_tail->val << ", curr = " << curr->val << ", temp = " << temp->val << "\n";
            prev_tail->next = curr;
            prev_tail = curr_tail;
            
            
            curr_tail = temp;
            
            temp1 = temp->next;
            curr = temp;
            temp = temp1;
            
            p = 0;
        } else {
            // continue reversing the current sublist of k nodes
            temp1 = temp->next;
            temp->next = curr;
            
            curr = temp;
            temp = temp1;
        }
    }
    //std::cout << "p = " << p << "\n";
    if (temp == nullptr && p == k-1) {
         p++;
         prev_tail->next = curr;
         curr_tail->next = nullptr;
     } else if (temp == nullptr && p != k) {
         //std::cout << "hereee\n";
         //std::cout << "curr: " << curr->val << " curr_tail: " << curr_tail->val << " prev_tail: " << prev_tail->val << "\n";
        // reverse back the links from curr_tail until curr
        ListNode *it = curr;
        ListNode *temp = it->next;
        //std::cout << "temp: " << temp->val << "\n";
        ListNode *temp1 = nullptr;
        while (temp != nullptr && temp != curr_tail) {
            temp1 = temp->next;
            temp->next = it;
            it = temp;
            temp = temp1;
        }
        prev_tail->next = curr_tail;
        curr->next = nullptr;
    }
    //std::cout << "p = " << p << "\n";
    
    return dummy_head->next;
}


int main() {
    LinkedList l;
    
    //std::vector<int> v = {1, 2, 3, 4, 5, 6}; int k = 4;
    //std::vector<int> v = {1, 2, 3, 4, 5}; int k = 2;
    //std::vector<int> v = {1, 2, 3, 4, 5}; int k = 3;
    std::vector<int> v = {3, 9, 6, 1, 1, 4, 7}; int k = 4;
    
    for (auto e : v) l.push_back(e);
    
    ListNode *curr = reverseKGroup(l.head, k);
    
    l.print_list(curr);
}
