#include <iostream>
#include <limits>
#include <vector>
#include "LinkedList.h"



ListNode* partition(ListNode* head, int x) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    // Dummy nodes to ease fixing up of links
    ListNode *L_head = new ListNode(std::numeric_limits<int>::min());
    ListNode *L_tail = L_head;
    
    ListNode *GE_head = new ListNode(std::numeric_limits<int>::max());
    ListNode *GE_tail = GE_head;
    
    ListNode *curr = head;
    ListNode *temp = nullptr;
    while (curr != nullptr) {
        temp = curr->next;
        
        if (curr->val < x) {
            L_tail->next = curr;
            L_tail = L_tail->next;
        } else {
            GE_tail->next = curr;
            GE_tail = GE_tail->next;
        }
        
        curr->next = nullptr;
        curr = temp;
    }
    
    ListNode *partition_head = nullptr;
    if (L_head->next == nullptr) {
        partition_head = GE_head->next;
    } else {
        partition_head = L_head->next;
        L_tail->next = GE_head->next;
    }
    
    return partition_head;
}

int main() {
    LinkedList l;
    
    //std::vector<int> v = {1, 2, 3, 4, 5, 6}; int x = 3;
    //std::vector<int> v = {2, 1, 3, 5, 6, 4, 7}; int x = 3;
    //std::vector<int> v = {1, 2, 3}; int x = 3;
    std::vector<int> v = {1, 4, 3, 2, 5, 2}; int x = 0;
    //std::vector<int> v = {2, 1}; int x = 1;
    for (auto e : v) l.push_back(e);
    
    ListNode *curr = partition(l.head, x);
    
    l.print_list(curr);
}
