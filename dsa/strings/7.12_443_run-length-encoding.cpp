#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void appendCountAndChar(std::string &encoded_str, int curr_count, char curr) {
    /*
    // manual conversion of count to string
    std::string count_str = "";
    while (curr_count > 0) {
        count_str += (curr_count % 10) + '0';
        curr_count /= 10;
    }
    std::reverse(count_str.begin(), count_str.end());
    encoded_str += count_str;
    */
    
    // better to use to_string instead
    encoded_str += std::to_string(curr_count);
    encoded_str += curr;    
}

std::string encode(const std::string &str) {
    if (str.empty()) return str;
    
    std::string encoded_str = "";
    char curr = str.front();
    int curr_count = 1;
    
    for (int i=1; i<str.size(); i++) {
        if (str[i] == curr) {
            curr_count++;
        } else {
            appendCountAndChar(encoded_str, curr_count, curr);
            
            curr = str[i];
            curr_count = 1;
        }
    }
    
    // account for last group
    appendCountAndChar(encoded_str, curr_count, curr);
    
    return encoded_str;
}

std::string decode(const std::string &str) {
    if (str.empty()) return str;
    
    std::string decoded_str = "";
    
    int curr_count = 0;
    for (int i=0; i<str.size(); i++) {
        char curr = str[i];
        if (isdigit(curr)) {
            curr_count = curr_count * 10 + str[i] - '0';
        } else {
            decoded_str.append(curr_count, curr);
            curr_count = 0;
        }
    }
    
    return decoded_str;
}

/*
// LC 443 String Compression https://leetcode.com/problems/string-compression/
void writeCharAndCount(vector<char> &chars, int &write_idx, char curr, int curr_count) {
    chars[write_idx++] = curr;
    if (curr_count > 1) {
        for (char ch : to_string(curr_count)) {
            chars[write_idx++] = ch;
        }
    }
}

int compress(vector<char>& chars) {
    if (chars.size() == 1) return 1;
    
    char curr = chars.front();
    int curr_count = 1;
    int write_idx = 0;
    
    for (int i=1; i<chars.size(); i++) {
        if (chars[i] == curr) {
            curr_count++;
        } else {
            writeCharAndCount(chars, write_idx, curr, curr_count);
            
            // switch group
            curr = chars[i];
            curr_count = 1;
        }
    }
    
    // account for last group
    writeCharAndCount(chars, write_idx, curr, curr_count);
    
    return write_idx;
}
*/


int main() {
    std::vector<std::string> tests = {
        "aaaabbbcc",
        "aa",
        "a",
        "zyxxya",
        "",
        "abbbbbbbbbbbb"
    };
    for (auto str : tests) {
        std::cout << encode(str) << std::endl;
        std::cout << decode(encode(str)) << std::endl;
    }
    return 0;
}
