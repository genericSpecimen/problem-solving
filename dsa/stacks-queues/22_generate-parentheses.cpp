class Solution {
public:
    
    bool isValid(const string &str) {
        int val = 0;
        for (char ch : str) {
            if (ch == '(') val++;
            else if (ch == ')') val--;
            
            if (val < 0) return false;
        }
        return val == 0;
    }
    
    /*
    // naive 
    void generate(int idx, string curr, vector<string> &combinations) {
        if (idx == curr.size()) {
            if (isValid(curr)) {
                combinations.push_back(curr);
            }
        } else {
            curr[idx] = '(';
            generate(idx+1, curr, combinations);
            curr[idx] = ')';
            generate(idx+1, curr, combinations);
        }
    }
    */
    
    
    // a bit more efficient: only open / close parentheses upto n/2
    void generate(int idx, string curr, int opened, int closed, vector<string> &combinations) {
        if (idx == curr.size()) {
            if (isValid(curr)) {
                combinations.push_back(curr);
            }
        } else {
            if (opened < curr.size()/2) {   
                curr[idx] = '(';
                generate(idx+1, curr, opened+1, closed, combinations);
            }
            
            if (closed < curr.size()/2) {   
                curr[idx] = ')';
                generate(idx+1, curr, opened, closed+1, combinations);
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        std::string curr(2*n, '.');
        int idx = 0;
        generate(idx, curr, 0, 0, combinations);
        return combinations;
    }
};
