std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> generated_matrix(n, std::vector<int>(n, 0));
    
    std::deque<std::deque<bool>> generated(n, std::deque<bool>(n, false));
    
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
    
    for (int i=1; i<=n*n; i++) {
        generated_matrix[curr.first][curr.second] = i;
        generated[curr.first][curr.second] = true;
        
        // compute the index of the next element
        next = {curr.first + direction.first, curr.second + direction.second};
        
        // check if we fell out of bounds or if we arrived at an already generated element
        if (next.first  < 0 || next.first  >= n ||
            next.second < 0 || next.second >= n ||
            generated[next.first][next.second]
            ) {
            // need to change direction
            dir = (dir+1)%4;
            direction = directions[dir];
            
            // recompute index of next element according to this direction
            next = {curr.first + direction.first, curr.second + direction.second};
        }
        curr = next;
    }
    return generated_matrix;
}
