#include <iostream>
#include <cctype>
#include <algorithm>

// O(n) time and O(1) space.
bool isPalindrome(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    int first = 0, last = s.size()-1;
    
    while (first < last) {
        if (isalnum(s[first]) && isalnum(s[last])) {
            if (s[first] != s[last]) {
                return false;
            }
            first++; last--;
        } else if (!isalnum(s[first])) {
            first++;
        } else if (!isalnum(s[last])) {
            last--;
        }
    }
    
    return true;
}

int main() {
    std::cout << std::boolalpha << isPalindrome("A man, a plan, a canal: Panama") << std::endl;
    
    return 0;
}
