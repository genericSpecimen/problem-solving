#include <iostream>
#include <cmath>

int num_page_turns(int n, int p) {
    int from_beginning = p/2;
    int from_end = 0;
    if(n % 2 == 0) from_end = std::ceil((n-p)/2.0);
    else from_end = (n-p)/2;
    std::cout << from_beginning << " " << from_end << std::endl;
    return (from_beginning < from_end ? from_beginning : from_end);
}

int main() {
    int n,p;
    std::cin >> n >> p;
    std::cout << num_page_turns(n,p) << std::endl;
}