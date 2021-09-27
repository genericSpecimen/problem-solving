class Solution {
public:
    /*
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        
        if (s.size() > t.size()) return false;
        
        int si = 0, ti = 0;
        
        while (si < s.size() && ti < t.size()) {
            if (s[si] == t[ti]) si++;
            ti++;
            if (si == s.size()) break;
        }
        
        return si == s.size();
    }
    */
    
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        
        if (s.size() > t.size()) return false;
        
        unordered_map<char, vector<int>> indices;
        for (int i=0; i<t.size(); i++) indices[t[i]].push_back(i);
        
        int curr = -1;
        
        for (char ch : s) {
            if (indices.find(ch) == indices.end()) return false;
            
            auto next_ge = upper_bound(indices[ch].begin(), indices[ch].end(), curr);
            if (next_ge == indices[ch].end()) return false;
            
            curr = *next_ge;
        }
        
        return true;
    }
    
};
