#include <iostream>
#include <vector>
#include "LinkedList.h"

// https://leetcode.com/problems/remove-linked-list-elements/

/*
 * Time complexity: O(n) - where n is the size of the List
 * Space complexity: O(1) - stores at most constant additional space for pointers.
 */
ListNode* removeElements(ListNode* head, int val) {
    // empty list
    if (head == nullptr) {
        return head;
    }
    
    /*
     * until a head with different val is found, or, until, the list is exhausted, 
     * keep deleting elements at the start of the list.
     */
    ListNode *temp = nullptr;
    while (head != nullptr && head->val == val) {
        temp = head;
        head = head->next;
        delete temp;
    }
    
    
    ListNode *curr = head;
    temp = nullptr;
    
    /*
     * Iterate through the remaining list and whenever the
     * value of the next node == val, bypass the links and
     * delete the node with val.
     */
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->next->val == val) {
            temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    
    return head;
}

int main() {
    LinkedList l;
    
    std::vector<int> v = {1, 2, 6, 3, 4, 5, 6};
    int val = 6;
    
    for (auto e : v) l.push_back(e);
    
    ListNode *curr = removeElements(l.head, 6);
    
    l.print_list(curr);
}
