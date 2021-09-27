#include <iostream>
#include <vector>
#include <limits>
#include "LinkedList.h"

ListNode* sortAbsSortedList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode *prev = head;
    ListNode *curr = head->next;
    ListNode *temp = nullptr;
    while (curr != nullptr) {
        temp = curr->next;
        if (curr->val < prev->val) {
            prev->next = curr->next;
            curr->next = head;
            head = curr;
        } else {
            prev = prev->next;
        }
        curr = temp;
    }
    
    return head;
}

int main() {
    LinkedList l1;
    //std::vector<int> v1 = {1, -2, -3, 4, -5};
    std::vector<int> v1 = {5, 10};
    for (auto e : v1) l1.push_back(e);
    
    ListNode *curr = sortAbsSortedList(l1.head);
    
    l1.print_list(curr);
}
