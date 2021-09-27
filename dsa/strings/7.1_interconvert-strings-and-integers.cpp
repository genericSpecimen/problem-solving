#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

#define MAX std::numeric_limits<int>::max()
#define MIN std::numeric_limits<int>::min()

int stringToInteger(const std::string &str) {
    int num = 0;
    if (str.size() == 0) return num;
    
    int i = 0;
    while (str[i] == ' ' && i < str.size()) {
        // skip any leading whitespaces
        i++;
    }
    
    if (i == str.size()) {
        // reached end of string
        return num;
    }
    
    int sign = 1;
    // otherwise, found the first non-whitespace character at index i
    switch (str[i]) {
        case '-' : sign = -1; i++; break;
        case '+' : sign =  1; i++; break;
        case '.' : return num; // starts with . means not an integer
    }
    
    while (i < str.size()) {
        int digit = str[i] - '0';
        if (digit >= 0 && digit <= 9) {
            // valid digit
            
            // check for overflow
            if (sign == 1) {
                if ( (num == MAX/10 && digit > 7) || (num > MAX/10) ){
                    return MAX;
                }
            } else if (sign == -1) {
                                                // = 8 accounts for MIN implicitly
                                                // otherwise, it will cause overflow when we add digit=8 on line 52
                if ( (sign*num == MIN/10 && digit >= 8) || (sign*num < MIN/10) ) {
                    return MIN;
                }
            }
            
            // otherwise, safe to add
            num = num * 10 + digit;
            i++;
        } else {
            // found a non digit, break;
            break;
        }
    }
    
    return sign*num;
}

std::string integerToString(int num) {
    if (num == 0) {
        return "0";
    }
    
    int sign = 1;
    if (num < 0) {
        sign = -1;
        if (num == MIN) {
            // special case, can't be negated
            return "-2147483648";
        }
        num = -num;
    }
    
    int num_digits = static_cast<int>(log10(num)) + 1;
    std::string num_str = "";
    
    if (sign == -1) {
        num_str.push_back('-');
    }
    
    int mask = static_cast<int>(pow(10, num_digits-1));
    while (num > 0) {
        char ch = (num / mask) + '0';
        num_str.push_back(ch);
        num = num % mask;
        mask = mask / 10;
    }
    
    return num_str;
}

std::string integerToString1(int num) {
    if (num == 0) {
        return "0";
    }
    
    int sign = 1;
    if (num < 0) {
        sign = -1;
        if (num == MIN) {
            // special case, can't be negated
            return "-2147483648";
        }
        num = -num;
    }
    
    std::string num_str = "";
    while (num > 0) {
        num_str += (num % 10) + '0';
        num /= 10;
    }
    
    if (sign == -1) {
        num_str += '-';
    }
    
    std::reverse(num_str.begin(), num_str.end());
    return num_str;
}

int main() {
    std::vector<std::string> tests = {
        "",
        " ",
        "  123  ",
        "123.456",
        " 123 456 ",
        "   -134.78",
        "-123", "-1",
        "0",
        "1","123",
        "4193 with words",
        "words and 987",
        "  -42",
        "-91283472332",
        "2147483647", "2147483648",
        "-2147483648", "-2147483649",
        "0032"
    };
    
    for (auto test : tests) {
        //std::cout << stringToInteger(test) << std::endl;
    }
    
    std::vector<int> testnums = {
        -123, -1, 0, 1, 123, MAX, MIN, MAX-1, MIN+1
    };
    
    for (auto test : testnums) {
        std::cout << integerToString(test) << std::endl;
        std::cout << integerToString1(test) << std::endl;
    }
}
