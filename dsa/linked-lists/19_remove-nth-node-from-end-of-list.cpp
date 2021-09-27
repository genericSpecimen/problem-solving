#include <iostream>
#include <vector>
#include "LinkedList.h"

/*
 * Two pass approach:
 * Pass 1: find the length of the list, sz.
 * Pass 2: Starting from i = 1, traverse the list
 *         until you find the (sz - i + 1)th node.
 *         Delete it.
 * 
 * Time complexity: O(sz) : two traversals of sizes sz and sz - n : sz + (sz - n)
 * Space complexity: O(1) : stores additional constant space only.
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) {
        return head;
    }
    
    ListNode *curr = head;
    int sz = 0;
    while (curr != nullptr) {
        sz++;
        curr = curr->next;
    }
    //std::cout << "sz = " << sz << "\n";
    
    int i = 0;
    curr = head;
    ListNode *prev = nullptr;
    ListNode *temp = nullptr;
    
    while (curr != nullptr) {
        i++;
        if (sz - i + 1 == n) {
            // found the nth node from the last
            
            
            if (prev == nullptr) {
                // handle the edge case when n == sz, i.e., the first node is deleted
                temp = head;
                head = head->next;
                delete temp;
                return head;
            }
            
            // bypass the links
            prev->next = curr->next;
            
            // set curr to the next node and delete the old curr
            temp = curr;
            curr = curr->next;
            delete temp;
            
            // the edge case when n == 1, i.e., the last node is deleted, is implicitly handled by the return.
            
            // we deleted the nth node from the last, no need to go further.
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    
    return head;
}


/*
 * "one-pass" approach mentioned in the solution section gives us NO REAL IMPROVEMENT
 * Time complexity: O(sz) - again, traversals are of sizes (sz - n) and sz.
 * The only difference is that the two traversals have changed their order.
 * 
 * Use two pointers:
 * 1. first starts from the head
 * 2. second starts from n nodes away from head
 * 
 * Keep traversing the list; when the second pointer becomes nullptr,
 * the list has been exhausted and the first pointer points to the
 * node that is the nth node from the last. Delete this node.
 * 
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) {
        return head;
    }
    
    ListNode *dummy = new ListNode(std::numeric_limits<int>::max(), head);
    ListNode *first = dummy;
    ListNode *second = dummy;
    
    for (int i=0; i<n+1; i++) {
        first = first->next;
    }
    
    // now first is n nodes away from second
    
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }
    
    // now the node next to second is the node to be deleted
    
    ListNode *temp = second->next;
    second->next = second->next->next;
    
    delete temp;
    
    return dummy->next;
}


int main() {
    
    LinkedList l;
    //std::vector<int> v = {1, 2, 3, 4, 5}; int n = 1;
    //std::vector<int> v = {1}; int n = 1;
    //std::vector<int> v = {1, 2}; int n = 1;
    for (auto e : v) l.push_back(e);

    ListNode *curr = removeNthFromEnd(l.head, n);
    
    l.print_list(curr);
    
}
