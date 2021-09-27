#include <iostream>
#include <string>


/*
 * The successive number can have at most twice as many digits
 * as the previous number - which happens when all digits are different.
 * Therefore, maximum length number = 2^n.
 * 
 * The loop in countAndSay runs for n-1 iterations. So, overall
 * time complexity = O(n 2^n) - loose upper bound. Tighter bound analysis is difficult.
 */
std::string getNextLookAndSay(std::string str) {
    if (str.size() == 1) {
        return "11";
    }

    char curr = str.front();
    int i = 1, curr_cnt = 1;
    std::string next = "";

    str.push_back('e'); // sentinel
    for (int i=1; i<str.size(); i++) {
        if (str[i] == 'e') {
            next += (curr_cnt + '0');
            next += curr;
        } else if (str[i] != curr) {
            next += (curr_cnt + '0');
            next += curr;

            curr = str[i];
            curr_cnt = 1;
        } else {
            curr_cnt++;
        }
    }
    str.pop_back();
    
    return next;
}

std::string countAndSay(int n) {
    std::string str = "1";
    if (n == 1) return str;
    for (int i=0; i<n-1; i++) {
        str = getNextLookAndSay(str);
    }

    return str;
}

int main() {
    for (int i=0; i<10; i++) {
        std::cout << countAndSay(i+1) << std::endl;
    }
}
