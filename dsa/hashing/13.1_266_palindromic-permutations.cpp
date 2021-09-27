#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool canFormPalindrome(const string &s) {
    if (s.empty()) return true;
    
    unordered_map<char, int> freq;
    for (char ch : s) freq[ch]++;
    
    int num_odd_freq = 0;
    for (auto cf : freq) {
        if (cf.second % 2 != 0) num_odd_freq++;
    }
    
    return num_odd_freq <= 1;
}

int main() {
    vector<string> tests = {
        "edified",
        "rttoora",
        "five",
        "ffiiivv",
        "",
        "a",
        "bba"
    };
    
    for (auto test : tests) cout << test << " : " << std::boolalpha << canFormPalindrome(test) << endl;
}
