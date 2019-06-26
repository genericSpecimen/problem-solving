#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int x = n;
    while(x % 5 != 0) x++;
    std::cout << "Next multiple of 5 is: " << x << std::endl;
    std::cout << "Difference is: " << x-n << std::endl;
}