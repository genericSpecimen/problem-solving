class Solution {
public:
    /*
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.front().size();
        
        deque<bool> set_row(m, false), set_col(n, false);
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == 0) {
                    // set i-th row to 0s
                    set_row[i] = true;
                    // set j-th column to 0s
                    set_col[j] = true;
                }
            }
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (set_row[i] || set_col[j]) matrix[i][j] = 0;
            }
        }  
    }
    */
    
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.front().size();
        
        // use matrix[0][0..n-1] as set_col
        // use matrix[1..m-1][0] as set_row
        // use additional var set_row0 to account for overlap
        bool set_row0 = false;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) set_row0 = true;
                    else matrix[i][0] = 0; // 0 indicates that we need to set row i to 0s
                    matrix[0][j] = 0; // need to set col j to 0s
                }
            }
        }
        
        // start from (1,1)
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        
        // now set col and row 0 IN THAT ORDER (setting row0 could affect mat[0][0])
        
        // set col 0 if needed
        if (matrix[0][0] == 0) {
            for (int i=0; i<m; i++) matrix[i][0] = 0;
        }
        
        // set row 0 if needed
        if (set_row0) {
            for (int j=0; j<n; j++) matrix[0][j] = 0;
        }
        
    }
};
