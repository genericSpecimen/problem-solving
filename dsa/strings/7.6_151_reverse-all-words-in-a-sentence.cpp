// strip leading and trailing whitespaces
int trimString(std::string &s) {
    // i: index of the first non whitespace character
    int first_nonws = 0;
    while (first_nonws < s.size() && s[first_nonws] == ' ') {
        first_nonws++;
    }
    
    int last_nonws = s.size()-1;
    while (last_nonws >= 0 && s[last_nonws] == ' ') {
        last_nonws--;
    }
    
    int num_spaces = first_nonws + s.size()-1-last_nonws;
    //std::cout << num_spaces << std::endl;
    
    int write_idx = s.size()-1;
    for (int i=last_nonws; i>=first_nonws; i--) {
        s[write_idx--] = s[i];
    }
    
    s.erase(0, num_spaces);
    
    //std::cout << first_nonws << ", " << last_nonws << std::endl;
    
    if (first_nonws > last_nonws) {
        // shouldn't reach here
        assert(false);
    }
    
    return num_spaces;
}

int trimConsecutiveSpaces(std::string &s) {
    int write_idx = s.size()-1;
    for (int i=s.size()-1; i>=0;) {
        if (s[i] == ' ') {
            s[write_idx--] = ' ';
            while (s[i] == ' ') {
                i--;
            }
        } else {
            s[write_idx--] = s[i--];
        }
    }
    
    if (write_idx >= 0) {
        s.erase(0, write_idx+1);
    }
    
    return write_idx;
    
}


string reverseWords(string &s) {
    int n = trimString(s);
    std::cout << "Trimmed " << n << " leading and trailing whitespaces\n";
    n = trimConsecutiveSpaces(s);
    std::cout << "Trimmed " << n << " consecutive whitespaces\n";
    //std::cout << s << std::endl;
    
    std::reverse(s.begin(), s.end());
    
    int w_start = 0, w_end = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ' ') {
            std::reverse(s.begin()+w_start, s.begin()+w_end);
            w_start = i+1;
            w_end = w_start;
        } else {
            w_end++;
        }
    }
    std::reverse(s.begin()+w_start, s.begin()+w_end);
    
    return s;
}

