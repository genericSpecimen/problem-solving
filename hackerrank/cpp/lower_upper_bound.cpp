#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::vector<int> nums;
    int temp;
    for(int i=0;i<n;i++) {
        std::cin >> temp;
        nums.push_back(temp);
    }
    int q; std::cin >> q;
    int query;
    for(int i=0;i<q;i++) {
        std::cin >> query;
        auto low = std::lower_bound(nums.begin(), nums.end(), query);
        std::cout << (*low == query ? "Yes " : "No ") << (low - nums.begin() + 1) << std::endl;
    }
}