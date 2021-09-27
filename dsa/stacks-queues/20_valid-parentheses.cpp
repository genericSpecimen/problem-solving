class Solution {
public:
    unordered_map<char, char> matchings = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
    };
    /*
    bool isValid(string s) {
        stack<char> st;
        
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (st.empty()) {
                    // got closing parentheses before opening
                    return false;
                }
                if (s[i] != matchings[st.top()]) {
                    return false;
                } else {
                    st.pop();
                }
            } else {
                std::cerr << "Invalid character in string: " << s[i] << std::endl;
                return false;
            }
        }
        
        return st.empty();
    }
    */
    
    bool isValid(string s) {
        // valid string must be of even length
        if (s.size() % 2 != 0) return false;
        
        stack<char> st;
        
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(matchings[ch]);
            } else if (st.empty()) {
                return false;
            } else if (st.top() != ch) {
                return false;
            } else {
                // st.top == ch
                st.pop();
            }
        }
        
        return st.empty();
    }
};
