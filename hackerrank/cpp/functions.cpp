#include <iostream>
#include <climits>

int main() {
    int temp, max = INT_MIN;
    for(int i=0;i<3;i++) {
        std::cin >> temp;
        if(temp > max) max = temp;
    }
    std::cout << max << std::endl;
}