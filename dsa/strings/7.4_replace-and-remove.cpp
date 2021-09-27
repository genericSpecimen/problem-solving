#include <iostream>
#include <unordered_map>

/*
 * Two iterations of O(n) time, O(1) space
 */
int replaceAndRemove(std::string &str, int size) {
    // remove b's and count a's
    
    int write_idx = 0, a_count = 0;
    for (int i=0; i<size; i++) {
        if (str[i] != 'b') {
            str[write_idx++] = str[i];
        }
        if (str[i] == 'a') {
            a_count++;
        }
    }
    
    // now replace a by dd, start writing from the back
    int last_valid_idx = write_idx - 1;
    write_idx = last_valid_idx + a_count;
    
    for (int i=last_valid_idx; i>=0; i--) {
        if (str[i] == 'a') {
            str[write_idx--] = 'd';
            str[write_idx--] = 'd';
        } else {
            str[write_idx--] = str[i];
        }
    }
    
    int newsize = last_valid_idx + a_count + 1;
    return newsize;
}

bool isPunctutation(char ch) {
    return (
        ch == '.'  ||
        ch == ','  ||
        ch == '\'' ||
        ch == '?'  ||
        ch == '!'
    );
}

int telexEncoding(std::string &str) {
    std::unordered_map<char, std::string> punct = {
        {'.', "DOT"},
        {',', "COMMA"},
        {'\'', "APOSTROPHE"},
        {'?', "QUESTION MARK"},
        {'!', "EXCLAMATION MARK"}
    };
    //char ch = '!';
    //std::cout << punct[ch] << ", " << punct[ch].size() << std::endl;
    
    int oldsize = str.size();
    int newsize = str.size();
    for (char ch : str) {
        if (isPunctutation(ch)) {
            newsize += (punct[ch].size()-1);
        }
    }
    
    str.resize(newsize);
    
    int write_idx = newsize-1;
    for (int i=oldsize-1; i>=0; i--) {
        if (isPunctutation(str[i])) {
            std::string punct_telex = punct[str[i]];
            for (int k=punct_telex.size()-1; k>=0 ;k--) {
                str[write_idx--] = punct_telex[k];
            }
        } else {
            str[write_idx--] = str[i];
        }
    }
    
    return newsize;
}

int main() {
    //std::string s1 = "acdbbca";
    std::string s1 = "acdbbca";
    std::cout << s1 << std::endl;
    std::cout << replaceAndRemove(s1, s1.size()) << std::endl;
    std::cout << s1 << std::endl;
    
    std::string s2 = "Hello James. What's up with you today? Please call me!";
    std::string s2_telex = "Hello JamesDOT WhatAPOSTROPHEs up with you todayQUESTION MARK Please call meEXCLAMATION MARK";
    std::cout << s2 << std::endl;
    std::cout << "New size: " << telexEncoding(s2) << std::endl;
    //std::cout << s2_telex.size() << std::endl;
    std::cout << s2 << std::endl;
    std::cout << std::boolalpha << (s2 == s2_telex) << std::endl;
    
    return 0;
}
