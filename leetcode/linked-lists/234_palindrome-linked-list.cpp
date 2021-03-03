#include <iostream>
#include <vector>
#include "LinkedList.h"

ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
        // empty list
        return head;
    }

    ListNode *curr = head;
    ListNode *temp = curr->next;
    curr->next = nullptr;
    ListNode *temp1 = nullptr;
    while (temp != nullptr) {
        temp1 = temp->next;
        temp->next = curr;
        
        curr = temp;
        temp = temp1;
    }
    return curr;
}

/*
 * Uses the slow and fast pointer approach to determine when we 
 * have reached the middle of the list.
 * 
 * If fast has reached the end of the list, then slow must've
 * covered "half" of the distance that fast has covered.
 * Thus, slow denotes the middle of the list.
 * 
 * We reverse the list starting from slow->next and then
 * compare elements one by one from the left and (reversed )right sublist.
 * 
 * Time complexity: O(n) 
 * Space complexity: O(1)
 */

bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    
    ListNode *slow = head;
    ListNode *fast = head;
    
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // slow is at the middle of the list
    //std::cout << slow->val << "\n";
    
    ListNode *middle = slow;  
    
    //std::cout << "middle = " << middle->val << "\n";
    
    ListNode *middle_rev = reverseList(middle->next);
    
    ListNode *left = head;
    ListNode *right = middle_rev;
    
    //std::cout << middle_rev->val << "\n";
    
    while (left != middle_rev && right != nullptr) {
        if (left->val != right->val) {
            return false;
        }
        left = left->next;
        right = right->next;
    }
    return true;
}

/*
// This approach does a little extra work with repeated scanning to determine the index of the elements.
// still O(n) time and O(1) space complexity.
bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    
    int size = 0;
    ListNode *curr = head;
    while (curr != nullptr) {
        size++;
        curr = curr->next;
    }
    //std::cout << "size = " << size << "\n";
    
    ListNode *middle = nullptr;
    ListNode *middle_prev = nullptr;
    curr = head;
    
    int p = 0;
    
    if (size % 2 == 0) {
        p = (size/2) + 1;
    } else {
        p = (size/2) + 2;
    }
    
    int i = 0;
    while (curr != nullptr) {
        i++;
        if (i == p) {
            middle = curr;
            break;
        }
        middle_prev = curr;
        curr = curr->next;
    }
    //std::cout << "middle = " << middle->val << "middle prev = " << middle_prev->val << "\n";
    
    ListNode *middle_rev = reverseList(middle);
    middle_prev->next = middle_rev;
    
    ListNode *left = head;
    ListNode *right = middle_rev;
    
    //std::cout << middle_rev->val << "\n";
    
    while (left != middle_rev && right != nullptr) {
        if (left->val != right->val) {
            return false;
        }
        left = left->next;
        right = right->next;
    }
    
    return true;
}
*/


int main() {
    LinkedList l;
    
    /*
    std::vector<int> v = {};
    std::vector<int> v = {1};
    std::vector<int> v = {1, 2};
    std::vector<int> v = {1, 2, 1};
    std::vector<int> v = {1, 2, 2, 1};
    std::vector<int> v = {1, 2, 3, 4, 5};
    */
    std::vector<int> v = {1, 2, 3, 2, 1};
    for (auto e : v) l.push_back(e);
    
    l.print_list(l.head);
    std::cout << std::boolalpha << isPalindrome(l.head) << "\n";
    
}
