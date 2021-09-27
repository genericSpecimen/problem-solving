#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>


/*
 * 615 (base 7) = 6*7^2 + 1*7^1 + 5*7^0 = 306 (integer, base 10)
 */
int convertToInt(const std::string &num_str, int from) {
    if (num_str.empty()) return 0;
    
    std::string num_base10_str = "";
    
    int sign = 0;
    if (num_str.front() == '-') sign = 1;
    
    int num = 0, weight=1;
    for (int i=num_str.size()-1; i>=sign; i--) {
        int digit = 0;
        if (isdigit(num_str[i])) {
            digit = num_str[i] - '0';
        } else if (islower(num_str[i])) {
            digit = num_str[i] - 'a' + 10;
        } else if (isupper(num_str[i])) {
            digit = num_str[i] - 'A' + 10;
        }
        
        num = num + (digit*weight);
        weight *= from;
    }
    
    if (sign == 1) num = -num;
    
    return num;
}

std::string convertIntToBase(int num, int to) {
    std::string num_str = "";
    
    int sign = 1;
    if (num < 0) {
        sign = -1;
        num = -num;
    }
    
    int rem = 0;
    while (num > 0) {
        rem = num % to;
        if (rem >= 10) {
            num_str += rem - 10 + 'A';
        } else {
            num_str += rem + '0';
        }
        num /= to;
    }
    
    if (sign == -1) {
        num_str += '-';
    }
    
    std::reverse(num_str.begin(), num_str.end());
    
    return num_str;
}

std::string convertFromBaseToBase(const std::string &num_str, int from, int to) {
    int num = convertToInt(num_str, from);
    std::string num_base_to_str = convertIntToBase(num, to);
    return num_base_to_str;
}

int main() {
    std::cout << convertFromBaseToBase("615", 7, 13) << "\n";
    std::cout << convertFromBaseToBase("-615", 7, 13) << "\n";
    std::cout << convertFromBaseToBase("ABCD", 16, 8) << "\n";
    std::cout << convertFromBaseToBase("abcd", 16, 8) << "\n";
}
