#include <iostream>
#include <vector>

void bubble(std::vector<int> a) {
    a[0] = 100;
    for(int x:a) std::cout << x << " ";
    std::cout << std::endl;
}

void quack(std::vector<int> a) {
    a[1] = 45678;
    for(int x:a) std::cout << x << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> a = {1,2,3,4,5,6,7,8};
    bubble(a);
    quack(a);
}