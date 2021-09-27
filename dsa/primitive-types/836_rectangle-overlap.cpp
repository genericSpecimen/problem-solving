class Solution {
public:
    bool rangesIntersect(int a1, int b1, int a2, int b2) {        
        if (std::max(a1, a2) < std::min(b1, b2)) {
            return true;
        }
        return false;
    }
    
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // [x1, x2] : xrange
        // [y1, y2] : yrange
        
        // if xrange and yrange of two rectangles intersect,
        // then the rectangles intersect as well.
        
        if (rangesIntersect(rec1[0], rec1[2], rec2[0], rec2[2]) &&
            rangesIntersect(rec1[1], rec1[3], rec2[1], rec2[3]) ) {
            return true;
        }
        return false;
    }
};
