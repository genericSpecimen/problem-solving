#include <iostream>
#include <vector>
#include "LinkedList.h"

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    /*
     * Create a dummy node - helps with cleaning up the
     * code from checking whether the head node exists.
     */
    ListNode *merged_head = new ListNode(-9999);
    ListNode *merged_tail = merged_head;
    
    int lesser;
    while (l1 != nullptr && l2 != nullptr) {
        // while both lists are nonempty, append the lesser of the values at the front of the list
        if (l1->val < l2->val) {
            lesser = l1->val;
            l1 = l1->next;
        } else {
            lesser = l2->val;
            l2 = l2->next;
        }
        merged_tail->next = new ListNode(lesser);
        merged_tail = merged_tail->next;
    }
    
    // while l1 is empty, append all the nodes to the end of the merged list
    while (l1 != nullptr) {
        merged_tail->next = new ListNode(l1->val);
        merged_tail = merged_tail->next;
        l1 = l1->next;
    }
    
    // while l2 is empty, append all the nodes to the end of the merged list
    while (l2 != nullptr) {
        merged_tail->next = new ListNode(l2->val);
        merged_tail = merged_tail->next;
        l2 = l2->next;
    }
    
    // since we created a dummy head, the actual head is the next node
    return merged_head->next;
}

int main() {
    
    LinkedList l1;
    std::vector<int> v1 = {1, 2, 4};
    //std::vector<int> v1 = {};
    for (auto e : v1) l1.push_back(e);
    
    LinkedList l2;
    std::vector<int> v2 = {1, 3, 4};
    //std::vector<int> v2 = {0};
    for (auto e : v2) l2.push_back(e);
    
    ListNode *curr = mergeTwoLists(l1.head, l2.head);
    
    while (curr != nullptr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "null\n";
}
