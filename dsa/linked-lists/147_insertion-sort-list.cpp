#include <iostream>
#include <vector>
#include <limits>
#include "LinkedList.h"

ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode *dummy = new ListNode(std::numeric_limits<int>::min(), head);
    ListNode *prev = dummy;
    ListNode *curr = head;
    
    ListNode *next = nullptr;
    ListNode *temp = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        
        if (curr->val < prev->val) {
            //std::cout << "curr: " << curr->val << ", prev: " << prev->val;
            temp = dummy;
            while (temp != prev) {
                if (temp->next->val >= curr->val) {
                    break;
                }
                temp = temp->next;
            }
            
            prev->next = curr->next;
            curr->next = temp->next;
            temp->next = curr;
            curr = next;
        } else {
            prev = prev->next;
            curr = curr->next;
        }
    }
    
    return dummy->next;
}

int main() {
    LinkedList l1;
    std::vector<int> v1 = {4,2,1,3};
    for (auto e : v1) l1.push_back(e);
    
    ListNode *curr = insertionSortList(l1.head);
    
    l1.print_list(curr);
    
    LinkedList l2;
    std::vector<int> v2 = {-1,5,3,4,0};
    for (auto e : v2) l2.push_back(e);
    
    curr = insertionSortList(l2.head);
    l2.print_list(curr);
}
