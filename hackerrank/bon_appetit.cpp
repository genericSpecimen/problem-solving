#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> bill;
    int temp;
    for(int i=0;i<n;i++) {
        std::cin >> temp;
        bill.push_back(temp);
    }

    int b_charged;
    std::cin >> b_charged;

    int sum = 0;
    for(int i=0;i<n;i++) {
        if(i != k) {
            sum += bill[i];
        }
    }
    int b_actual = sum/2;
    if(b_charged == b_actual) std::cout << "Bon Appetit" << std::endl;
    else std::cout << b_charged - b_actual << std::endl;
}