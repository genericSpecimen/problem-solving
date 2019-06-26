#include <iostream>
#include <vector>

int minimum_swaps(std::vector<int>& a) {
    int num_swaps = 0;
    for(int i=0;i<a.size();i++) {
        if(a[i] != i+1) {
            // out of order
            std::swap(a[i],a[a[i]-1]);
            num_swaps++;
            i--;
        }
    }
    return num_swaps;
}

int main() {
    int n; std::cin >> n;
    int temp;
    std::vector<int> a; a.resize(n);
    for(int i=0;i<n;i++) std::cin >> a[i];
    std::cout << minimum_swaps(a) << std::endl;
}