// O(m*n) time, O(m*n) space
std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> spiral_order;
    
    
    int m = matrix.size(), n = matrix[0].size();
    std::deque<std::deque<bool>> seen(m, std::deque<bool>(n, false));
    
    std::vector<std::pair<int,int>> directions = {
        { 0,  1}, // go right by incrementing y
        { 1,  0}, // go down by incrementing x
        { 0, -1}, // go left by decrementing y
        {-1,  0}, // go up by decrementing x
    };
    
    // index of current element and next element 
    std::pair<int, int> curr = {0, 0}, next;
    
    // start by going right
    int dir = 0;
    std::pair<int, int> direction = directions[dir];
    
    for (int i=0; i<m*n; i++) {
        spiral_order.push_back(matrix[curr.first][curr.second]);
        seen[curr.first][curr.second] = true;
        
        // compute the index of the next element
        next = {curr.first + direction.first, curr.second + direction.second};
        
        // check if we fell out of bounds or if we arrived at an already seen element
        if (next.first  < 0 || next.first  >= m ||
            next.second < 0 || next.second >= n ||
            seen[next.first][next.second]
            ) {
            // need to change direction
            dir = (dir+1)%4;
            direction = directions[dir];
            
            // recompute index of next element according to this direction
            next = {curr.first + direction.first, curr.second + direction.second};
        }
        
        curr = next;
    }
    
    return spiral_order;
}

// O(m*n) time, O(1) space
/*
std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> spiral_order;
    
    int m = matrix.size(), n = matrix[0].size();
    std::pair<int, int> start = {0, 0}, end = {m-1, n-1};
    
    while (start.first <= end.first && start.second <= end.second) {
        std::cout << "{" << start.first << "," << start.second <<"}, ";
        std::cout << "{" << end.first << "," << end.second <<"}, ";
        
        if (start.first == end.first && start.second == end.second) {
            spiral_order.push_back(matrix[start.first][start.second]);
        } else if (start.first == end.first) {
            // single row
            for (int j=start.second; j<=end.second; j++) {
                spiral_order.push_back(matrix[start.second][j]);
            }
        } else if (start.second == end.second) {
            // single column
            for (int i=start.first; i<=end.first; i++) {
                spiral_order.push_back(matrix[i][start.second]);
            }
        } else {
            // go right
            for (int i=start.first, j=start.second; j<end.second; j++) {
                spiral_order.push_back(matrix[i][j]);
            }

            // then down
            for (int j=end.second, i=start.first; i<end.first; i++) {
                spiral_order.push_back(matrix[i][j]);
            }

            // then left
            for (int i=end.first, j=end.second; j>start.second; j--) {
                spiral_order.push_back(matrix[i][j]);
            }

            // finally, up
            for (int j=start.second, i=end.first; i>start.first; i--) {
                spiral_order.push_back(matrix[i][j]);
            }
        }
        
        start = {start.first+1, start.second+1};
        end = {end.first-1, end.second-1};
    }
    
    return spiral_order;
}
*/
