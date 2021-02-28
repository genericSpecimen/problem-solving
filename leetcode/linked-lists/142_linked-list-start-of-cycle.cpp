#include <iostream>
#include <vector>
#include "LinkedList.h"

/*
 * Refer to explanation of Problem 141 first.
 * 
 * We need to return the node where the cycle begins.
 * After we have found where the hare and tortoise meet,
 * we use two pointers:
 *      p1 starting from the head of the list,
 *      p2 starting from the meeting point we just found
 * The point at which p1 and p2 meet is the node at which
 * the cycle starts. The proof that this works is in the
 * resources mentioned in problem 141.
 */


ListNode* detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        /*
         * if the list is empty, or,
         * if there's a single node and head->next doesn't 
         * point to itself, then there can't be a cycle.
         */
        return nullptr;
    }
    
    ListNode *tortoise = head;
    ListNode *hare = head;
    
    while (tortoise != nullptr && hare != nullptr && hare->next != nullptr) {
        // tortoise != nullptr is not really necessary in the exit condition
        tortoise = tortoise->next;
        hare = hare->next->next;
        
        if (tortoise == hare) {
            ListNode *p1 = head;
            ListNode *p2 = hare;
            
            while (p1 != p2) {
                p1 = p1->next;
                p2 = p2->next;
            }
            
            return p1;
        }
    }
    
    return nullptr;
}

int main() {
    LinkedList l;
    
    //std::vector<int> v = {3, 2, 0, -4};
    //std::vector<int> v = {1, 2};
    std::vector<int> v = {1};
    for (auto e : v) l.push_back(e);
    
    //l.tail->next = l.head->next;
    //l.tail->next = l.head;
    //l.head->next = l.head;
    
    //l.print_list(l.head);
    
    std::cout << (hasCycle(l.head) ? "True" : "False") << "\n";
    
}
