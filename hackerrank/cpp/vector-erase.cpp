#include <iostream>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::vector<int> nums;
    int temp;
    for(int i=0;i<n;i++) {
        std::cin >> temp;
        nums.push_back(temp);
    }

    int x; std::cin >> x; //erase element at position x
    nums.erase(nums.begin() + (x-1));

    int a,b; std::cin >> a >> b; // range of elements to be deleted

    nums.erase(nums.begin() + (a-1), nums.begin() + (b-1));
    std::cout << nums.size();
    for(int x:nums) std::cout << x << " ";
    std::cout << std::endl;
}