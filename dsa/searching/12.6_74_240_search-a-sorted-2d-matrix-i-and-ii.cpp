// 240
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.front().empty()) return false;
        
        int m = matrix.size(), n = matrix.front().size();
        int row = 0, col = n - 1;
        
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                row++;
            } else {
                col--;
            }
        }
        
        return false;
    }
};


// 74
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.front().empty()) return false;
        
        int m = matrix.size(), n = matrix.front().size();
        
        int r_low = 0, r_high = m - 1;
        
        while (r_low <= r_high) {
            int mid = r_low + (r_high - r_low) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) {
                r_low = mid + 1;
            } else {
                r_high = mid - 1;
            }
        }
        
        // only need to search r_high now
        int row = r_high;
        if (row < 0) return false; // could happen when target < mat[0][0]
        
        int c_low = 0, c_high = n - 1;
        
        while (c_low <= c_high) {
            int mid = c_low + (c_high - c_low) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) {
                c_low = mid + 1;
            } else {
                c_high = mid - 1;
            }
        }
        
        return false;
    }
};
