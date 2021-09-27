#include <iostream>
#include <vector>
#include <limits>
#include "LinkedList.h"
/*
ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || k == 0) {
        return head;
    }
    
    int size = 0;
    ListNode *curr = head;
    ListNode *tail = curr;
    
    while (curr != nullptr) {
        size++;
        tail = curr;
        curr = curr->next;
    }
    
    //std::cout << "size: " << size << ", tail: " << tail->val << "\n";
    
    if (k == size) return head; 
    
    k = k % size;
    
    ListNode *dummy = new ListNode(std::numeric_limits<int>::max(), head);
    ListNode *prev = dummy;
    ListNode *temp = head;
    
    for (int i=size; i>=1; i--) {
        if (i == k) {
            //std::cout << "prev: " << prev->val
            //         << "temp: " << temp->val
            //          << "tail: " << tail->val << "\n";
            prev->next = nullptr;
            tail->next = head;
            head = temp;
            break;
        } else {
            if (temp == nullptr) break;
            prev = prev->next;
            temp = temp->next;
        }
    }
    
    return head;
}
*/

/*
ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || k == 0) {
        return head;
    }
    
    int size = 0;
    ListNode *curr = head;
    ListNode *tail = curr;
    
    while (curr != nullptr) {
        size++;
        tail = curr;
        curr = curr->next;
    }
    
    //std::cout << "size: " << size << ", tail: " << tail->val << "\n";
    
    if (k == size) return head; 
    
    k = k % size;
    
    // turn it to a circular list
    tail->next = head;
    curr = head;
    for (int i=0; i<size-k-1; i++) {
        curr = curr->next;
    }
    
    head = curr->next;
    curr->next = nullptr;
    
    return head;
}
*/

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || k == 0) {
        return head;
    }
    
    int size = 0;
    ListNode *curr = head;
    ListNode *tail = curr;
    
    while (curr != nullptr) {
        size++;
        tail = curr;
        curr = curr->next;
    }
    
    //std::cout << "size: " << size << ", tail: " << tail->val << "\n";
    
    if (k == size) return head; 
    
    k = k % size;
    
    ListNode *slow = head, *fast = head;
    for (int i=0;i<k;i++) {
        fast = fast->next;
    }
    
    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    
    fast->next = head;
    head = slow->next;
    slow->next = nullptr;
    
    return head;
}

int main() {
    LinkedList l1;
    std::vector<int> v1 = {1,2,3,4,5}; int k = 2;
    for (auto e : v1) l1.push_back(e);
    
    ListNode *curr = rotateRight(l1.head, k);
    
    l1.print_list(curr);
}
