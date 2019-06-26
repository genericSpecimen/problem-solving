#include <iostream>

int main() {
    int n = 10;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n;j++) {
            if(i & (1 << j))
                std::cout << j << ',';
        }
        std::cout << std::endl;
    }
}