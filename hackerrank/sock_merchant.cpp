#include <iostream>
#include <vector>
#include <map>

int num_pairs(std::vector<int>& sock_colors) {
    int count = 0;
    std::map<int, int> sock_freq;
    for(int i=0;i<sock_colors.size();i++) {
        sock_freq[sock_colors[i]]++;
    }
    for(std::map<int,int>::iterator itr = sock_freq.begin(); itr != sock_freq.end(); itr++) {
        count += (itr->second)/2;
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> sock_colors;
    int temp;
    for(int i=0;i<n;i++) {
        std::cin >> temp;
        sock_colors.push_back(temp);
    }
    std::cout << num_pairs(sock_colors) << std::endl;
}