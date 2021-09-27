class Solution {
public:
    /*
    
    // Brute Force O(n^2)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        
        for (int i=0; i<temperatures.size(); i++) {
            for (int j=i+1; j<temperatures.size(); j++) {
                if (temperatures[j] > temperatures[i]) {
                    answer[i] = j - i;
                    break;
                }
            }
        }
        
        return answer;
    }
    */
    
    /*
     * Use a stack to maintain the list of warmer days from the current day.
     * Overall, a specific index can only be pushed once and can only be popped once.
     * The total number of times the body of the while loop executes, cannot be greater than n.
     * And so we have O(n + n) = O(n).
     */ 
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        if (temperatures.empty()) return {};
        
        vector<int> answer(temperatures.size(), -1);
        stack<int> st;
        
        answer[temperatures.size()-1] = 0;
        st.push(temperatures.size()-1);
        
        for (int i=temperatures.size()-2; i>=0; i--) {
            // search for next warmer day
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                // we can pop without concern because:
                // for days before i, the next warmer day will be i itself.
                st.pop();
            }
            
            // no next warmer day
            if (st.empty()) {
                answer[i] = 0;
            } else {
                // found next warmer day: temperatures[st.top()] > temperatures[i]
                answer[i] = st.top() - i;
            }
            
            st.push(i);
        }
        
        return answer;
    }
};
