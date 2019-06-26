#include <iostream>

std::string can_catch_up(int x1, int v1, int x2, int v2) {
    if(x2 > x1 && v2 > v1) return "NO";
    else if(x1 != x2 && v1 == v2) return "NO";
    else {
        if ((x1 - x2) % (v2 - v1) == 0) return "YES";
        return "NO";
    }
}

int main() {
    int x1,v1,x2,v2;
    std::cin >> x1 >> v1 >> x2 >> v2;
    std::cout << can_catch_up(x1,v1,x2,v2) << std::endl;
}