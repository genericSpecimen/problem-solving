class Solution {
public:
    bool isSubsequence(const string &s, const string &p, const unordered_set<int> &removed) {
        if (p.empty()) return true;
        if (p.size() > s.size()) return false;
        
        int si = 0, pi = 0;
        
        while (si < s.size() && pi < p.size()) {
            
            if (removed.find(si) != removed.end()) {
                si++;
                continue;
            }
            
            if (s[si] == p[pi]) pi++;
            si++;
            
            if (pi == p.size()) break;
        }
        
        return pi == p.size();
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int max_removals = 0;
        
        unordered_set<int> removed;
        
        /*
        for (int i=0; i<removable.size(); i++) {
            removed.insert(removable[i]);
            //cout << "removed " << removable[i];
            if (isSubsequence(s, p, removed)) {
                max_removals++;
                //cout << " : yes" << endl;
            } else {
                //cout << " : no " << endl;
            }
        }
        */
        
        int l = 0, r = removable.size()-1;
        
        while (l <= r) {
            removed.clear();
            
            int mid = l + (r-l)/2;
            for (int i=0; i<=mid; i++) removed.insert(removable[i]);
            
            if (isSubsequence(s, p, removed)) {
                max_removals = std::max(max_removals, mid+1);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return max_removals;
    }
};

