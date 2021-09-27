class Solution {
public:
    string decodeString(string str) {
        stack<pair<string, int>> st;
        
        st.push({"", 1});
        
        int i = 0, num = 0;
        while (i < str.size()) {
            if (isdigit(str[i])) {
                while (isdigit(str[i])) {
                    num = num * 10 + (str[i] - '0');
                    i++;
                }
                i--;
            } else if (str[i] == '[') {
                st.push({"", num});
                num = 0;
            } else if (str[i] == ']') {
                pair<string, int> curr = st.top(); st.pop();
                
                for (int i=0; i<curr.second; i++) {
                    st.top().first += curr.first;
                }
            } else {
                st.top().first += str[i];
            }
            
            i++;
        }
        
        return st.top().first;
    }
};
