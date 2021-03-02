#include <iostream>
#include <vector>
#include "LinkedList.h"

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        // empty list, or,
        // a single node
        return head;
    }
    
    // Create a dummy node, it will simplify the process of fixing links like prev_tail
    ListNode *dummy_head = new ListNode(-1);
    dummy_head->next = head;
    ListNode *curr = head;
    ListNode *prev = dummy_head;
    ListNode *prev_tail = dummy_head;
    
    
    // keep track of number of nodes processed
    int p = 0;
    
    // refer to problem 25 for in depth explanation - this is problem 25 when k = 2
    while (curr != nullptr) {
        p++;
        
        if (p % 2 == 0) {
            prev_tail->next = curr;
            prev->next = curr->next;
            curr->next = prev;
            
            curr = prev->next;
            
            prev_tail = prev;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    
    // the real head is at the next of the dummy head we created
    return dummy_head->next;
}

int main() {
    LinkedList l;
    
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    //std::vector<int> v = {1};
    
    for (auto e : v) l.push_back(e);
    
    ListNode *curr = swapPairs(l.head);
    
    l.print_list(curr);
}
