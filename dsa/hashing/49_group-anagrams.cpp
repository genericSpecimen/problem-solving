class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (int i=0; i<strs.size(); i++) {
            string str(strs[i]);
            std::sort(str.begin(), str.end());
            groups[str].push_back(strs[i]);
        }
        
        vector<vector<string>> grouped_anagrams;
        for (auto sv : groups) {
            grouped_anagrams.push_back(sv.second);
        }
        
        return grouped_anagrams;
    }
};
