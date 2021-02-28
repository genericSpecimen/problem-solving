#include <iostream>
#include <vector>
#include "LinkedList.h"

/*
* Uses the Floyd's tortoise and hare cycle finding algorithm
* In each iteration,
*      tortoise moves one step ahead
*      hare moves two steps ahead
* If the list contains a cycle, then they will meet together
* at some node in the list: the hare moves faster than the
* tortoise, so, it will also loop back to the start of a cycle
* early on (before the tortoise). The hare will now catch up from
* the behind of the tortoise.
* 
* After each iteration, the distance between the hare and the tortoise
* increases by 1.
* 
* After both the hare and the tortoise enter the cycle (if one exists),
* the distance between them will keep on increasing until the distance
* is a multiple of the length of the cycle, say, k. Since it is a cycle
* of length k, and, the distance between the tortoise and the hare inside
* the cycle is k, this means that they are at the same node.
* 
* Some useful resources:
* https://en.wikipedia.org/wiki/Cycle_detection#Floyd%27s_tortoise_and_hare
* https://math.stackexchange.com/a/913529
* https://cs.stackexchange.com/a/90990
* https://stackoverflow.com/a/2936345
* https://www.youtube.com/watch?v=-YiQZi3mLq0
* 
* Length of cycle = C
* mu = index of the first node of the cycle
* Time complexity: O(mu + C)
* 
* Space complexity: O(1) - constant additional space for pointers
*/


bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        /*
         * if the list is empty, or,
         * if there's a single node and head->next doesn't 
         * point to itself, then there can't be a cycle.
         */
        return false;
    }
    
    ListNode *tortoise = head;
    ListNode *hare = head;
    
    while (tortoise != nullptr && hare != nullptr && hare->next != nullptr) {
        // tortoise != nullptr is not really necessary in the exit condition
        tortoise = tortoise->next;
        hare = hare->next->next;
        
        if (tortoise == hare) {
            return true;
        }
    }
    
    return false;
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
