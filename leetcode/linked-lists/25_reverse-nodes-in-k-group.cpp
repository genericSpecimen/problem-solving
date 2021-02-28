#include <iostream>
#include <vector>
#include "LinkedList.h"

/*
 * Basic idea:
 * (i)  Try to traverse k nodes at a time.
 * (ii) If successful, then reverse this sublist of k-nodes. We keep track
 *      of the sublist using pointers.
 * (iii)Otherwise, a sublist of k nodes doesn't exist - so leave it as it is.
 * 
 * For each sublist, we maintain the previous_tail of the sublist just before it.
 * current_tail denotes the tail of the current sublist after reversing the list.
 * 
 * A sublist is denoted by the pointers: prev_tail, and, the node next to the
 * current node at which we discover that we have traversed k nodes. (curr->next).
 * Now we reverse the sublist between these two pointers, using the same approach
 * as Problem 206. But in this case, we start with the node prev_tail->next, and, 
 * the exit condition is when the temp pointer reaches curr->next.
 * 
 */

ListNode* reverseList(ListNode *prev_tail, ListNode *old_curr_next) {
    ListNode *curr = prev_tail->next;
    ListNode *temp = curr->next;

    ListNode *temp1 = nullptr;
    while (temp != old_curr_next) {
        temp1 = temp->next;
        temp->next = curr;
        
        curr = temp;
        temp = temp1;
    }
    
    /*
     * current_tail is the next of the prev_tail because
     * in the case of dummy_head, we explicitly set prev_tail->next = head.
     * And head is the curr_tail of the first sublist.
     * 
     * We maintain this throughout by setting curr_tail->next = old_curr_next,
     * so that the current tail is connected to the starting node of the next sublist.
     * Now, this current tail becomes the prev_tail for the next sublist and
     * curr_tail = prev_tail->next works as expected for the next sublist.
     */
    ListNode *curr_tail = prev_tail->next;
    //prev_tail->next->next = old_curr_next;
    curr_tail->next = old_curr_next;
    
    /*
     * curr is the head of the current sublist.
     * it should be connected to the previous tail.
     */
    prev_tail->next = curr;
    
    //std::cout << "prev_tail = " << prev_tail->val << ", curr_tail = " << curr_tail->val << ", curr = " << curr->val << "\n";
    
    /*
     * return the current tail, which becomes the previous tail for the next sublist
     * in the while loop of reverseKGroup.
     */
    return curr_tail;
}


ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k == 1) {
        // empty list, or,
        // reverse 1 at a time = same as original list
        return head;
    }
    
    // Create a dummy node, it will simplify the process of fixing links like prev_tail
    ListNode *dummy_head = new ListNode(-1);
    dummy_head->next = head;
    ListNode *prev_tail = dummy_head;
    
    ListNode *curr = head;
    
    // keep track of number of nodes processed
    int p = 0;
    
    while (curr != nullptr) {
        p++;
        
        if (p % k == 0) {
            /*
             * We have encountered k nodes, so we need to reverse them.
             * After reversing, the tail of the current sublist becomes the
             * previous tail for the next sublist. So we set prev_tail.
             * 
             */
            prev_tail = reverseList(prev_tail, curr->next);
            
            /*
             * the next node to process is simply the next of previous tail, since
             * we set this during the reversing process (curr_tail->next = old_curr_next;).
            */
            curr = prev_tail->next;
        } else {
            /*
             * We have not encountered k nodes yet, so keep traversing (without reversing anything).
             * The case where list length is not a multiple of k is covered elegantly by this.
             */
            curr = curr->next;
        }
    }
    
    // the real head is at the next of the dummy head we created
    return dummy_head->next;
}

int main() {
    LinkedList l;
    
    //std::vector<int> v = {1, 2, 3, 4, 5, 6}; int k = 4;
    //std::vector<int> v = {1, 2, 3, 4, 5}; int k = 2;
    //std::vector<int> v = {1, 2, 3, 4, 5}; int k = 3;
    std::vector<int> v = {3, 9, 6, 1, 1, 4, 7}; int k = 4;
    
    for (auto e : v) l.push_back(e);
    
    ListNode *curr = reverseKGroup(l.head, k);
    
    l.print_list(curr);
}
