#include <sstream>
#include <vector>
#include <iostream>

std::vector<int> parseInts(std::string str) {
    std::stringstream ss(str);
    std::vector<int> nums;
    std::string num;
    while(std::getline(ss, num, ',')) {
        nums.push_back(std::stoi(num));
    }
    return nums;
}

int main() {
    std::string str;
    std::cin >> str;
    std::vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        std::cout << integers[i] << "\n";
    }
    
    return 0;
}

