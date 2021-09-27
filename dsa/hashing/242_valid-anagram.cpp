class Solution {
public:
    /*
    bool isAnagram(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s.compare(t) == 0;
    }
    */
    
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, int> freq;
        
        for (int i=0; i<s.size(); i++) {
            freq[s[i]]++;
            freq[t[i]]--;
        }
        
        for (auto cf : freq) {
            if (cf.second != 0) return false;
        }
        
        
        return true;
    }
};

