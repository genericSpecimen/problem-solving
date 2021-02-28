#include <iostream>
#include <vector>
#include "LinkedList.h"

/*
 * Length of list 1 = m
 * Length of list 2 = n
 * Time complexity: O(max(m, n)) :
 *      The while loop runs until both the lists are exhausted.
 *      In case one of the lists is exhausted earlier, the while loop
 *      still needs to consider the larger list.
 * 
 * Space complexity: O(max(m, n))
 *      Sum contains at most max(m, n) + 1 digits.
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *sum_head = nullptr;
    ListNode *sum_tail = nullptr;
    
    int sum = 0, carry = 0;
    
    /*
     * Handle the simple case in which we add the same number of
     * digits in both the lists.
     */
    
    while (l1 != nullptr && l2 != nullptr) {
        sum = carry + l1->val + l2->val;
        
        carry = sum / 10;
        
        sum = sum % 10;
        if (sum_head == nullptr) {
            sum_head = new ListNode(sum);
            sum_tail = sum_head;
        } else {
            sum_tail->next = new ListNode(sum);
            sum_tail = sum_tail->next;
        }
        
        l1 = l1->next;
        l2 = l2->next;
    }
    
    // Handle the case when the first list has more digits left to add
    while (l1 != nullptr) {
        sum = carry + l1->val;
        carry = sum / 10;
        sum = sum % 10;
        sum_tail->next = new ListNode(sum);
        sum_tail = sum_tail->next;
        
        l1 = l1->next;
    }
    
    // Handle the case when the second list has more digits left to add
    while (l2 != nullptr) {
        sum = carry + l2->val;
        carry = sum / 10;
        sum = sum % 10;
        sum_tail->next = new ListNode(sum);
        sum_tail = sum_tail->next;
        
        l2 = l2->next;
    }
    
    // add an additional node to the sum list in case carry is left
    if (carry != 0) {
        sum_tail->next = new ListNode(carry);
        sum_tail = sum_tail->next;
    }
    
    return sum_head;
}

int main() {
    
    //std::vector<int> v1 = {2, 4, 3};
    //std::vector<int> v1 = {0};
    std::vector<int> v1 = {9,9,9,9};
    LinkedList l1;
    for (auto e : v1) l1.push_back(e);
    l1.print_list(l1.head);
    
    //std::vector<int> v2 = {5, 6, 4};
    //std::vector<int> v2 = {0};
    std::vector<int> v2 = {9,9,9,9,9,9,9};
    LinkedList l2;
    for (auto e : v2) l2.push_back(e);
    l2.print_list(l2.head);
    
    ListNode *curr = addTwoNumbers(l1.head, l2.head);
    
    while (curr != nullptr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "null\n";
    
}
