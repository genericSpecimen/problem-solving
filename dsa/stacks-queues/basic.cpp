#include <iostream>
#include <list>
#include <stack>

void printLinkedListInReverse(const std::list<int> &l) {
    std::stack<int> elems;
    
    for (auto elem : l) {
        elems.push(elem);
    }
    
    while (!elems.empty()) {
        std::cout << elems.top() << ", ";
        elems.pop();
    }
    std::cout << "\n";
}

int main() {
    std::list<int> l = {8, 7, 2, 15, 89};
    printLinkedListInReverse(l);
    
    std::cout << atoi("+") << std::endl;
    return 0;
}
