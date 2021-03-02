#include <iostream>
#include <vector>
#include "LinkedList.h"


ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode *odd_tail = head;
    ListNode *odd_tail_prev = nullptr;
    ListNode *even_head = head->next;
    
    ListNode *curr = head;
    ListNode *temp = head->next;
    
    int processed = 0;
    while (curr != nullptr && curr->next != nullptr) {
        processed++;
        
        temp = curr->next;
        curr->next = temp->next;
        
        if (processed % 2 != 0) {
            odd_tail_prev = curr;
            odd_tail = temp->next;
        }
        
        curr = temp;
    }
    
    if (odd_tail != nullptr) {
        odd_tail->next = even_head;
    } else {
        odd_tail_prev->next = even_head;
    }
    
    return head;
}

int main() {
    LinkedList l;
    
    //std::vector<int> v = {1, 2, 3, 4, 5, 6};
    //std::vector<int> v = {2, 1, 3, 5, 6, 4, 7};
    std::vector<int> v = {1, 2, 3};
    for (auto e : v) l.push_back(e);
    
    ListNode *curr = oddEvenList(l.head);
    
    l.print_list(curr);
}
