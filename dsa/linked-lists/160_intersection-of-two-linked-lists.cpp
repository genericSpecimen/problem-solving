#include <iostream>
#include <vector>
#include <limits>
#include "LinkedList.h"

/*
 * If length of A == length of B, then at most one iteration is required.
 * Otherwise, we need two traversals:
 * Resolve the length difference so that remaining steps for tempA == remaining steps for tempB
 * Now, it's the same case as same length lists.
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }
    
    ListNode *tempA = headA;
    ListNode *tempB = headB;
    
    while (tempA != tempB) {
        if (tempA == nullptr) {
            tempA = headB;
        } else {
            tempA = tempA->next;
        }
        
        if (tempB == nullptr) {
            tempB = headA;
        } else {
            tempB = tempB->next;
        }
    }
    
    return tempA;
}

int main() {
    LinkedList l1;
    l1.push_back(4);
    l1.push_back(1);
    ListNode *l1tail = l1.tail;
    l1.push_back(8);
    l1.push_back(4);
    l1.push_back(5);
    
    LinkedList l2;
    l2.push_back(5);
    l2.push_back(6);
    l2.push_back(1);
    
    l2.tail->next = l1tail->next;
    
    
    l1.print_list(l1.head);
    l2.print_list(l2.head);
    
    ListNode *intersection = getIntersectionNode(l1.head, l2.head);
    std::cout << "Intersection at: " << (intersection == nullptr ? 0 : intersection->val) << "\n";
}
