#include <iostream>
#include <vector>
#include "LinkedList.h"

// https://leetcode.com/problems/reverse-linked-list/

/*
 * Iterative version:
 * Time complexity: O(n), where n is the length of the list
 * Space complexity: O(1), stores at most constant additional space for pointers
 */
ListNode* reverseList(ListNode* head) {
	if (head == nullptr) {
		// empty list
		return head;
	}

	ListNode *curr = head;

	/*
	 * We are going to update curr->next, so
	 * we will lose the original link. Therefore,
	 * we must store the original link to the next
	 * node somewhere.
	 */
	ListNode *temp = curr->next;
	
	/*
	 * The first node in the original list is the last node
	 * in the reversed list, i.e. its next pointer is null.
	 */
	curr->next = nullptr;

	/*
	 * while there are more next nodes (temp) after curr to process,
	 * (i)	store the next link of temp somewhere, temp1
	 * (ii)	update the next link of temp to point to curr, to reverse the link
	 * (iii)move curr and temp the next nodes and continue
	 */

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
 * Recursive version:
 * Time complexity: O(n)
 * Space complexity: O(n) due to stack space used up by the O(n) recursive calls.
 */

ListNode* reverseList_recursive(ListNode* head) {
	// check if there's some list left to reverse
	if (head == nullptr || head->next == nullptr) {
        // if head->next is null, then this is the last node of the original list,
        // so make it the head of the reversed list.
		return head;
	}

	// if yes, first reverse the remaining list and next_head will be
	// the head of the reversed list
	ListNode *next_head = reverseList(head->next);

	/*
	 * The remaining list is reversed, now we just have to fix the links:
	 * (i) reverse the link between head and head->next
	 * (ii) discard the old link by setting it to null, it'll either get
	 * 	updated later or it will stay null in the case of the first node
	 * 	in the original list.
	 */
	
    head->next->next = head;
	head->next = nullptr;
    
	return next_head;
}


int main() {
    LinkedList l;
    
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    for (auto e : v) l.push_back(e);
    
    ListNode *curr = reverseList(l.head);
    
    l.print_list(curr);
}
