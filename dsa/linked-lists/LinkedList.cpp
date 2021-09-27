#include <iostream>
#include <vector>
#include "LinkedList.h"

int main() {
    LinkedList l;
    
    std::vector<int> v = {3, 2, 0, -4};
    for (auto e : v) {
        l.push_back(e);
    }
    l.print_list(l.head);
}
