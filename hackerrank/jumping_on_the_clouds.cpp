#include <iostream>
#include <vector>

unsigned int min_jumps(const std::vector<bool>& c) {
    unsigned int jumps = 0;
    unsigned int current_position = 0;
    for(int i=0;i<c.size()-1;) {
        if(c[i+2] == 0) {
            // safe to jump two clouds ahead
            i += 2;
            jumps++;
        } else {
            // jump one cloud ahead
            i++;
            jumps++;
        }
    }
    return jumps;
}

int main() {
    unsigned int n; std::cin >> n;
    std::vector<bool> c;
    bool temp;
    while(n--) {
        std::cin >> temp;
        c.push_back(temp);
    }
    std::cout << min_jumps(c) << std::endl;
}