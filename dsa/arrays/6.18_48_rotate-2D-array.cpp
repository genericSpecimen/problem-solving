void diagonalFlip(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void reverseRows(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n/2; j++) {
            std::swap(matrix[i][j], matrix[i][n-1-j]);
        }
    }
}

void antiDiagonalFlip(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i=n-1; i>=0; i--) {
        for (int j=n-1-i+1; j<n; j++) {
            std::swap(matrix[i][j], matrix[n-1-j][n-1-i]);
        }
    }
}

void reverseColumns(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int j=0; j<n; j++) {
        for (int i=0; i<n/2; i++) {
            std::swap(matrix[i][j], matrix[n-1-i][j]);
        }
    }
}

// clockwise 90 rotation
/*
 * diagonalFlip and reverseRows both take O(M) time, O(1) space.
 */
void rotate(vector<vector<int>>& matrix) {
    // Sol 1
    // rows -> columns
    diagonalFlip(matrix);
    // columns in reverse order: reverse each row
    reverseRows(matrix);
    
    // Sol 2
    /*
    antiDiagonalFlip(matrix);
    reverseColumns(matrix);
    */
    
    // Sol 3
    /*
    reverseColumns(matrix);
    diagonalFlip(matrix);
    */
    
    
}

void antiClockWiseRotate(vector<vector<int>> &matrix) {
    reverseRows(matrix);
    diagonalFlip(matrix);
}


/*
// O(M) time, M = n*n, O(1) space  
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i=0; i<n/2; i++) {
        for (int j=i; j<n-1-i; j++) {
            int first = matrix[i][j];
            int second = matrix[j][n-i-1];
            int third = matrix[n-i-1][n-j-1];
            int fourth = matrix[n-j-1][n-(n-i-1)-1];
            
            matrix[j][n-i-1] = first;
            matrix[n-i-1][n-j-1] = second;
            matrix[n-j-1][n-(n-i-1)-1] = third;
            matrix[i][j] = fourth;
        }
    }
}
*/
