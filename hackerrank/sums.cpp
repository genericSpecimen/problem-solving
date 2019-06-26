#include <iostream>
#include <climits>
int main() {
    long int input;
    long int sum = 0;
    long int min = INT_MAX;
    long int max = INT_MIN;
    for(int i=0;i<5;i++) {
        std::cin >> input;
        sum += input;
        if(input > max) max = input;
        if(input < min) min = input;
    }
    std::cout << sum-max << " " << sum-min << std::endl;

}