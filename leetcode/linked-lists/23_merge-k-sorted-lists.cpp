#include <iostream>
#include <vector>
#include <limits>
#include "LinkedList.h"

#define INF std::numeric_limits<int>::max()

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    /*
     * Create a dummy node - helps with cleaning up the
     * code from checking whether the head node exists.
     */
    ListNode *merged_head = new ListNode(INF);
    ListNode *merged_tail = merged_head;
    
    int lesser;
    while (l1 != nullptr && l2 != nullptr) {
        // while both lists are nonempty, append the lesser of the values at the front of the list
        if (l1->val < l2->val) {
            lesser = l1->val;
            l1 = l1->next;
        } else {
            lesser = l2->val;
            l2 = l2->next;
        }
        merged_tail->next = new ListNode(lesser);
        merged_tail = merged_tail->next;
    }
    
    // while l1 is empty, append all the nodes to the end of the merged list
    while (l1 != nullptr) {
        merged_tail->next = new ListNode(l1->val);
        merged_tail = merged_tail->next;
        l1 = l1->next;
    }
    
    // while l2 is empty, append all the nodes to the end of the merged list
    while (l2 != nullptr) {
        merged_tail->next = new ListNode(l2->val);
        merged_tail = merged_tail->next;
        l2 = l2->next;
    }
    
    // since we created a dummy head, the actual head is the next node
    return merged_head->next;
}


/*
 * Approach 1: Merge lists one by one.
 * 1. Merge the first two lists and call it currently_merged_head.
 * 2. Merge the next list (if it exists) with currently_merged_head and update currently_merged_head
 * 3. Continue until all lists have been merged.
 * 
 * Time complexity: O(k N), where N = number of nodes in all the k lists.
 *      We can merge two sorted lists in O(n) time where n = number of nodes in the the two lists.
 *      For k >=2 lists, we perform k-1 merging operations.
 *      TODO
 * 
 * Space complexity:
 *      TODO
 */
/*
ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    int k = lists.size();
    
    if (k == 0) {
        return nullptr;
    }
    
    if (k == 1) {
        return lists[0];
    }
    
    // there are at least two lists at this point
    ListNode *currently_merged_head = mergeTwoLists(lists[0], lists[1]);
    
    // this loop is entered only when there are >2 lists
    for (int i=2; i<k; i++) {
        // keep merging the already merged list with other lists
        currently_merged_head = mergeTwoLists(currently_merged_head, lists[i]);
    }
    
    return currently_merged_head;
}
*/

/*
 * Approach 2:
 * Merge pairs of lists repeatedly.
 * For k >= 2,
 * 1. Take pairs of lists and merge them. After merging
 *    pairs of lists, we are left with k/2 lists.
 * 2. Again, out of the k/2 remaining lists, merge pairs of lists.
 * 3. Continue until a single merged list is left.
 * 
 * Time complexity:
 *      TODO
 * 
 * Space complexity:
 *      TODO
 */

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    int k = lists.size();
    
    if (k == 0) {
        return nullptr;
    }
    
    if (k == 1) {
        return lists[0];
    }
    
    // there are at least two lists at this point
    
    /*
     * interval denotes the difference in the index at which
     * the heads of two lists to be merged are located.
     * 
     * Initially, interval = 1, i.e. the heads of lists to be merged
     * are one index apart.
     * 
     * As we merge pairs of lists, the interval doubles.
     * After the first iteration of merging of pairs of lists,
     * the list heads of the merged 2-sorted lists are located
     * 2 positions apart (we explicitly make sure of this using the lists[i] = ... line)
     * 
     * Similarly, after the second iteration, interval doubles to 4, and, so on.
     */
    int interval = 1;
    
    while (interval < k) {
        for (int i=0; i < k - interval; i += (interval*2)) {
            lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
        }
        interval *= 2;
    }
    
    // the head of the final merged list is at the first position of lists vector
    return lists[0];
}

int main() {
    
    LinkedList l1;
    std::vector<int> v1 = {1, 4, 5};
    //std::vector<int> v1 = {};
    for (auto e : v1) l1.push_back(e);
    
    LinkedList l2;
    std::vector<int> v2 = {1, 3, 4};
    //std::vector<int> v2 = {0};
    for (auto e : v2) l2.push_back(e);
    
    LinkedList l3;
    std::vector<int> v3 = {2, 6};
    //std::vector<int> v3 = {0};
    for (auto e : v3) l3.push_back(e);
    
    LinkedList l4;
    std::vector<int> v4 = {};
    //std::vector<int> v3 = {0};
    for (auto e : v4) l4.push_back(e);
    
    std::vector<ListNode*> lists = {l1.head, l2.head, l3.head};
    //std::vector<ListNode*> lists = {};
    //std::vector<ListNode*> lists = {l4.head};
    
    ListNode *curr = mergeKLists(lists);
    while (curr != nullptr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "null\n";
}
