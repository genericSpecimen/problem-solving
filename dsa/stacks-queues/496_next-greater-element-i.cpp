class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) return {};
        
        stack<int> st;
        unordered_map<int, int> m;
        
        vector<int> nextg(nums2.size(), -1);
        nextg[nums2.size()-1] = -1;
        m[nums2[nums2.size()-1]] = nums2.size() - 1;
        st.push(nums2.size()-1);
        
        for (int i=nums2.size()-2; i>=0; i--) {
            m[nums2[i]] = i;
            while (!st.empty() && nums2[st.top()] <= nums2[i]) {
                st.pop();
            }
            
            if (st.empty()) {
                nextg[i] = -1;
            } else {
                nextg[i] = nums2[st.top()];
            }
            
            st.push(i);
        }
        /*
        for (int i=0; i<nextg.size(); i++) {
            cout << i << ", " << nextg[i] << "\n";
        }
        
        cout << "\n";
        
        for (auto it : m) {
            cout << it.first << ", " << it.second << "\n";
        }
        */
        
        for (int i=0; i<nums1.size(); i++) {
            nums1[i] = nextg[m[nums1[i]]];
        }
        
        
        return nums1;
        
    }
};
