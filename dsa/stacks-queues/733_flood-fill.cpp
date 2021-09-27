class Solution {
public:
    void fill(vector<vector<int>> &image, pair<int, int> pixel, int oldColor, int newColor, deque<deque<bool>> &filled) {
        int m = image.size();
        int n = image.front().size();
        
        if (pixel.first < 0 || pixel.first >= m ||
           pixel.second < 0 || pixel.second >= n ||
           image[pixel.first][pixel.second] != oldColor ||
           filled[pixel.first][pixel.second]) {
            return;
        }
        
        image[pixel.first][pixel.second] = newColor;
        filled[pixel.first][pixel.second] = true;
        
        vector<pair<int,int>> directions = {
            {0, 1}, // right
            {1, 0}, // down
            {0, -1}, // left
            {-1, 0} // right
        };
        
        
        for (auto dir : directions) {
            pair<int, int> next = {pixel.first + dir.first, pixel.second + dir.second};
            fill(image, next, oldColor, newColor, filled);
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        int m = image.size();
        int n = image.front().size();
        deque<deque<bool>> filled(m, deque<bool>(n, false));
        
        fill(image, {sr, sc}, oldColor, newColor, filled);
        
        return image;
    }
};
