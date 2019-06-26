#include <iostream>
#include <cmath>

void cats_and_mouse(int x, int y, int z) {
    // x : Cat A, y : Cat B, z : Mouse C
    int dist_a = std::abs(z-x);
    int dist_b = std::abs(z-y);
    if(dist_a == dist_b) std::cout << "Mouse C" << std::endl;
    else if(dist_a < dist_b) std::cout << "Cat A" << std::endl;
    else std::cout << "Cat B" << std::endl;
}

int main() {
    int q;
    int x,y,z;
    std::cin >> q;
    for(int i=0;i<q;i++) {
        std::cin >> x >> y >> z;
        cats_and_mouse(x,y,z);
    }
}