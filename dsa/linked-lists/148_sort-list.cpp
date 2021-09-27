#include <iostream>
#include <vector>
#include <limits>
#include "LinkedList.h"
/*
 * Top-down merge sort implementation
 * O(n log n) time complexity
 * O(log n) space complexity due to recursive calls
 */
/*
 
ListNode* merge(ListNode *l1, ListNode *l2) {
    ListNode *dummy_head = new ListNode(std::numeric_limits<int>::max());
    // keeps track of the current node in the final merged list
    ListNode *curr = dummy_head;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }

    if (l1 != nullptr) {
        curr->next = l1;
    } else if (l2 != nullptr) {
        curr->next = l2;
    }
    return dummy_head->next;
}

ListNode* sortList(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode *mid = slow;
    //std::cout << "mid: " << mid->val << "\n";
    
    ListNode *sorted_head;
    
    if (mid->next == fast && fast == nullptr) {
        // single node, no need to do anything
        sorted_head = head;
    } else {
        // recurse and merge
        ListNode *mid_next = mid->next;
        mid->next = nullptr;
        ListNode *lhead = sortList(head);
        ListNode *rhead = sortList(mid_next);
        sorted_head = merge(lhead, rhead);
    }
    
    return sorted_head;
}
*/

/*
 * Bottom-up implementation
 * Repeatedly merge chunks of size 1,
 * then size 2, then size 4, and so on,
 * until chunk size exceeds size of list.
 */

int listSize(ListNode *head) {
    int size = 0;
    ListNode *curr = head;
    while (curr != nullptr) {
        size++;
        curr = curr->next;
    }
    return size;
}

/*
 * splitChunk splits a chunk of size "size" from
 * the head and returns a pointer to the starting
 * node of the next chunk
 */
ListNode* splitChunk(ListNode *head, int size) {
    ListNode *curr = head;
    for(int i=0; i<size-1;i++) {
        if (curr == nullptr) {
            break;
        }
        
        curr = curr->next;
    }
    if (curr == nullptr) {
        return nullptr;
    }
    ListNode *next_chunk_head = curr->next;
    // split this chunk from the rest of the list
    curr->next = nullptr;
    
    return next_chunk_head;
}

ListNode* merge(ListNode *l1, ListNode *l2, ListNode *start_prev) {
    ListNode *curr = start_prev;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }

    if (l1 != nullptr) {
        curr->next = l1;
    } else if (l2 != nullptr) {
        curr->next = l2;
    }
    
    ListNode *chunk_tail = nullptr;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    chunk_tail = curr;
    
    // return the tail of this merged list
    // it will be the start_prev for the next list to be merged
    return chunk_tail;
}

ListNode* sortList(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    
    int total_size = listSize(head);
    //std::cout << "Size of list: " << total_size << "\n";
    
    /*
     * individual elements are already trivially sorted,
     * so first we merge chunks of size 1
     */
    int chunk_size = 1;
    
    ListNode *dummy = new ListNode(std::numeric_limits<int>::min(), head);
    
    ListNode *start_prev = nullptr;
    ListNode *start = nullptr;
    
    ListNode *left_head = nullptr;
    ListNode *right_head = nullptr;
    
    while (chunk_size < total_size) {
        start_prev = dummy;
        start = dummy->next;
        
        while (start != nullptr) {
            left_head = start;
            // split a chunk of size from the left
            right_head = splitChunk(left_head, chunk_size);
            // split a chunk of size from the right
            start = splitChunk(right_head, chunk_size);
            start_prev = merge(left_head, right_head, start_prev);
        }
        
        // after the merging step, chunks of size ```size*2``` are already sorted
        chunk_size *= 2;
    }
    
    return dummy->next;
}

int main() {
    LinkedList l1;
    std::vector<int> v1 = {4,2,1,3};
    for (auto e : v1) l1.push_back(e);
    
    ListNode *curr = sortList(l1.head);
    
    l1.print_list(curr);
    
    LinkedList l2;
    std::vector<int> v2 = {-1,5,3,4,0};
    for (auto e : v2) l2.push_back(e);
    
    curr = sortList(l2.head);
    l2.print_list(curr);
}
