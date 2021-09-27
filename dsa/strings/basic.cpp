#include <iostream>
#include <vector>
#include <string>

bool isPalindrome(const std::string &str) {
    if (str.empty()) {
        return false;
    }
    
    int n = str.size();
    for (int i=0; i<n/2; i++) {
        if (str[i] != str[n-1-i]) return false;
    }
    
    return true;
}

int main() {
    std::vector<std::string> tests = {
        "hello",
        "racecar",
        "plshelp",
        "madam",
        ""
    };
    
    for (auto &str : tests) {
        std::cout << std::boolalpha << isPalindrome(str) << "\n";
    }
    
    std::string str = "Pascal";
    str.push_back('\'');
    str.push_back('s');
    str.append(" triangle.");
    std::cout << str << "\n";
    str.pop_back(); str.pop_back();
    std::cout << str << "\n";
    
    std::string s = "Greetingssalutations.";
    s.insert(9, " and ");
    std::cout << s << "\n";
    std::cout << s.substr(1) << "\n";
    
    std::cout << s.compare("Greetingssalutations") << std::endl;
    std::cout << s.compare("Greetings and salutations.") << std::endl;
    for (std::string::iterator it = s.begin(); it != s.end(); it++) {
        std::cout << *it;
    }
    std::cout << std::endl;
    
    std::string s1 = "hello", s2 = "world", s3 = "hello", s4 = s1;
    std::cout << std::boolalpha << (s1 == s1) << std::endl;
    std::cout << std::boolalpha << (s1 == s2) << std::endl;
    std::cout << std::boolalpha << (s1 == s3) << std::endl;
    std::cout << std::boolalpha << (s1 == s4) << std::endl;
}
