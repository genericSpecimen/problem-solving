#include <iostream>
#include <string>
#include <vector>
#include <cmath>

/*
 * Naive string matching algorithm to find all matches.
 * Takes O((n-m+1)m) time, O(1) space. 
 */
std::vector<int> findAllMatches(const std::string &text, const std::string &pattern) {
    int n = text.size(), m = pattern.size();
    
    if (n < m) {
        // no match possible
        return {-1};
    }
    
    std::vector<int> match_indices;
    for (int shift = 0; shift <= n - m; shift++) {
        // check if T[shift+0, ..., shift+m-1] == P[0, ..., m-1]
        bool matches = true;
        for (int i=0; i<pattern.size(); i++) {
            if (text[shift+i] != pattern[i]) {
                matches = false;
            }
        }
        if (matches) {
            match_indices.push_back(shift);
        }
    }
    
    return match_indices;
}


// The Knuth-Morris-Pratt algorithm
std::vector<int> computePrefixFunction(const std::string &pattern) {
    std::vector<int> pi(pattern.size(), -1);
    
    // index of the last character of prefix matched with suffix
    int m = -1;
    
    // read pattern from L to R, starting from the first char
    for (int r=1; r<pattern.size(); r++) {
        while (m > -1 && pattern[m+1] != pattern[r]) {
            // found a mismatch, so try matching from after pi[m]
            m = pi[m];
        }
        if (pattern[m+1] == pattern[r]) {
            // expand matched prefix size
            m++;
        }
        // if a mismatch is found at pi[r+1], then start matching from
        // m+1, since characters upto index m have already been matched at this point
        pi[r] = m;
    }
    
    return pi;
}

std::vector<int> KMPMatcher(const std::string &text, const std::string &pattern) {
    std::vector<int> pi = computePrefixFunction(pattern);
    
    //for (auto p : pi) std::cout << p << std::endl;
    
    std::vector<int> match_indices;
    
    // index of the last character in text successfully matched with pattern
    int m = -1;
    
    for (int r=0; r<text.size(); r++) {
        while (m > -1 && pattern[m+1] != text[r]) {
            // found a mismatch, so try matching from after pi[m]
            m = pi[m];
        }
        
        if (pattern[m+1] == text[r]) {
            // increment matched characters index
            m++;
        }
        
        if (m == pattern.size()-1) {
            // entire pattern of pattern.size() has been matched that ends at index r
            //std::cout << "Pattern occurs with shift: " << r - m << std::endl;
            match_indices.push_back(r-m);
            m = pi[m]; // look for next match
        }
    }
    
    return match_indices;
}

/*
// decimal number strings for easy debugging
std::vector<int> RabinKarpMatcher(const std::string &text, const std::string &pattern, int d) {
    int n = text.size(), m = pattern.size();
    
    long long int pattern_value = 0;
    // value of first m chars of text
    long long int text_value = 0;
    for (int i=0; i<m; i++) {
        pattern_value = (pattern_value * d) + (pattern[i] - '0');
        text_value = (text_value * d) + (text[i] - '0');
    }
    
    std::cout << pattern_value << ", " << text_value << std::endl;
    
    long long int h = static_cast<long long int>(pow(d, m-1));
    
    for (int shift=0; shift <= n-m; shift++) {
        if (text_value == pattern_value) {
            bool matches = true;
            for (int i=0; i<pattern.size(); i++) {
                if (pattern[i] != text[shift+i]) matches = false;
            }
            if (matches) {
                std::cout << "Pattern occurs with shift: " << shift << std::endl;
            }
        }
        
        if (shift <= n-m-1) {
            text_value = ((text_value - (text[shift]-'0') * h) * d) + (text[shift+m] - '0');
            //std::cout << text_value << std::endl;
        }
    }
    
    return {0};
}
*/

std::vector<int> RabinKarpMatcher(const std::string &text, const std::string &pattern, int d, int DIV) {
    int n = text.size(), m = pattern.size();
    
    int pattern_value = 0;
    // value of first m chars of text
    int text_value = 0;
    for (int i=0; i<m; i++) {
        pattern_value = (d * pattern_value + pattern[i]) % DIV;
        text_value = (d * text_value + text[i]) % DIV;
    }
    
    std::cout << pattern_value << ", " << text_value << std::endl;
    
    int h = 1;
    for (int i=0; i<m-1; i++) {
        h = (h * d) % DIV;
    }
    std::cout << h << std::endl;
    
    
    std::vector<int> match_indices;
    
    for (int shift=0; shift <= n-m; shift++) {
        if (text_value == pattern_value) {
            bool matches = true;
            for (int i=0; i<pattern.size(); i++) {
                if (pattern[i] != text[shift+i]) matches = false;
            }
            if (matches) {
                //std::cout << "Pattern occurs with shift: " << shift << std::endl;
                match_indices.push_back(shift);
            }
        }
        
        if (shift <= n-m-1) {
            text_value = (d*(text_value - text[shift]*h) + text[shift+m]) % DIV;
            
            if (text_value < 0) {
                //std::cout << "negative text_value";
                text_value += DIV;
            }
        }
    }
    
    return match_indices;
}

// 0123456789
//    012345

int main() {
    /*
    std::string text = "Lorem ipsum lorem ipsum dolor sit amet";
    std::string pattern = "or";
    
    for (int idx : findAllMatches(text, pattern)) {
        std::cout << "Match found at index: " << idx << std::endl;
    }
    */
    
    
    /*
    //std::string text = "ababaaaabsbaababacajhhshaababaca";
    //std::string text = "ababacabacbabababacaabcbab";
    std::string text = "hello";
    //std::string pattern = "ababaca";
    //std::string pattern = "abcabcabcaf";
    //std::string pattern = "a";
    std::string pattern = "ll";
    
    for (int idx : KMPMatcher(text, pattern)) {
        std::cout << "Match found at index: " << idx << std::endl;
    }
    */
    
    /*
    std::string text = "23590314152673993141521";
    std::string pattern = "31415";
    RabinKarpMatcher(text, pattern, 10);
    */
    
    std::string text = "ababacabacbabababacaabcbab";
    std::string pattern = "ababaca";
    for (int idx : RabinKarpMatcher(text, pattern, 26, 101)) {
        std::cout << "Match found at index: " << idx << std::endl;
    }
    return 0;
}
