#include <iostream>
#include <set>

int main() {
    int q; std::cin >> q;
    int y; // type of query
    int x; // integer
    
    std::set<int> nums;
    for(int i=0;i<q;i++) {
        std::cin >> y >> x;
        switch(y) {
            case 1: nums.insert(x); break;
            case 2: nums.erase(x); break;
            case 3: std::cout << (nums.find(x) != nums.end() ? "Yes" : "No") << std::endl;
        }
    }
}