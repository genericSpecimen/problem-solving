class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> mps(n+1, 0);
        
        for (int i=n-1; i>=0; i--) {
            for (int j=0; j<triangle[i].size(); j++) {
                mps[j] = triangle[i][j] + std::min(mps[j], mps[j+1]);
            }
        }
        
        return mps[0];
    }
};
