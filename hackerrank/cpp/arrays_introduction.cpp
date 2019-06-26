#include <iostream>
#include <vector>

int main() {
    int n; std::cin >> n;
    int temp;
    std::vector<int> a;
    for(int i=0;i<n;i++) {
        std::cin >> temp;
        a.push_back(temp);
    }

    for(int i=a.size()-1;i>=0;i--) std::cout << a[i] << " ";
    std::cout << std::endl;
}