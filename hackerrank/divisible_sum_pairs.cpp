#include <iostream>
#include <vector>

int num_divisible_sum_pairs(std::vector<int> ar, int k) {
    int count = 0;
    for(int i=0;i<ar.size();i++) {
        for(int j=i+1;j<ar.size();j++) {
            if(i < j && ((ar[i] + ar[j]) % k) == 0) count++;
        }
    }
    return count;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> ar;
    int temp;
    for(int i=0;i<n;i++) {
        std::cin >> temp;
        ar.push_back(temp);
    }

    std::cout << num_divisible_sum_pairs(ar,k) << std::endl;
}