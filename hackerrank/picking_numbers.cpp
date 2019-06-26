#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

int max_len_subarray(std::vector<int> a) {
    int max_count = INT_MIN;
    int count = 0;
    for(int i=0;i<a.size();i++) {
        count = 0;
        for(int j=i+1;j<a.size();j++) {
            if(std::abs(a[j] - a[i]) <= 1) count++;
        }
        if(count > max_count) max_count = count;
    }
    return max_count+1;
}

int main() {
    int n; std::cin >> n;
    std::vector<int> a;
    int temp;
    for(int i=0;i<n;i++) {
        std::cin >> temp;
        a.push_back(temp);
    }
    std::sort(a.begin(), a.end());
    std::cout << max_len_subarray(a) << std::endl;
}