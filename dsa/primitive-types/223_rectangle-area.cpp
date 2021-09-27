class Solution {
public:
    bool rangesIntersect(int a1, int b1, int a2, int b2) {        
        if (std::max(a1, a2) < std::min(b1, b2)) {
            return true;
        }
        return false;
    }
    
    bool isRectangleOverlap(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {        
        if (rangesIntersect(ax1, ax2, bx1, bx2) &&
            rangesIntersect(ay1, ay2, by1, by2) ) {
            return true;
        }
        return false;
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        int total_area = area1 + area2;
        
        if (isRectangleOverlap(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2)) {
            // subtract area of overlapping part since it has been added twice
            int width = std::min(ax2, bx2) - std::max(ax1, bx1);
            int height = std::min(ay2, by2) - std::max(ay1, by1);
            
            total_area -= (width * height);
        }
        
        return total_area;
    }
};
