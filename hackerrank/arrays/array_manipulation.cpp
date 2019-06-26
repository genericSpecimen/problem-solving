#include <iostream>
#include <vector>

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<long int> arr; arr.resize(n);

    int a, b, k;
    while(m--) {
        std::cin >> a >> b >> k;
        arr[a-1] += k;
        arr[b] -= k;
    }

    long sum = 0;
    long max = 0;
    for(int i=0;i<n;i++) {
        sum += arr[i];
        max = (max > sum ? max : sum);
    }
    std::cout << max << std::endl;
}