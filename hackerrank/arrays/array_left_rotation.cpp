#include <iostream>
#include <vector>

std::vector<int> rotate_left_by_d(std::vector<int>& a, int n, int d) {
    std::vector<int> temp;
    temp.resize(n);
    for(int i=0;i<n;i++) {
        int new_i = ((i + (n-d)) % n);
        temp[new_i] = a[i];
    }
    return temp;
}

int main() {
    int n, d; std::cin >> n >> d;
    std::vector<int> a;
    int temp;
    int n_copy = n;
    while(n_copy--) {
        std::cin >> temp;
        a.push_back(temp);
    }

    a = rotate_left_by_d(a,n,d);
    for(int x : a) std::cout << x << " ";
    std::cout << std::endl;
}
