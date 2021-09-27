/*
 * O(n) time, O(1) space.
 * On the first non match in validPalindrome, at most two calls to
 * isPalindrome are made, each of which can take O(n) time.
*/
bool isPalindrome(std::string s) {        
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

// at most one deletion
bool validPalindrome(string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    int first = 0, last = s.size()-1;
    
    while (first < last) {
        if (isalnum(s[first]) && isalnum(s[last])) {
            if (s[first] != s[last]) {
                // try deleting either s[first] or s[last] and check if the middle part is a palindrome
                return (
                    isPalindrome(s.substr(first+1, last-first)) ||
                    isPalindrome(s.substr(first, last-first))
                );
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
