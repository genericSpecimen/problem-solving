#include <iostream>
#include <algorithm>

struct Rectangle {
    int x, y; // bottom left corner
    int width, height;
};

/*
 * Check whether [a1, b1] and [a2, b2] intersect.
 */
bool rangesIntersect(int a1, int b1, int a2, int b2) {
    if (std::max(a1, a2) <= std::min(b1, b2)) {
        // maximum starting time <= min ending time
        return true;
    }
    return false;
}

/*
 * We treat the boundary as a part of the rectangle.
 */
Rectangle rectanglesIntersect(const Rectangle& r1, const Rectangle& r2) {
    if (rangesIntersect(r1.x, r1.x + r1.width, r2.x, r2.x + r2.width) &&
        rangesIntersect(r1.y, r1.y + r1.height, r2.y, r2.y + r2.height) 
    ) {
        // the rectangles have a nonempty intersection.
        Rectangle r;
        
        // the top left corner's coordinates
        // are the maximum starting values of x and y.
        r.x = std::max(r1.x, r2.x);
        r.y = std::max(r1.y, r2.y);
        
        r.width = std::min(r1.x + r1.width, r2.x + r2.width) - std::max(r1.x, r2.x);
        r.height = std::min(r1.y + r1.height, r2.y + r2.height) - std::max(r1.y, r2.y);
        
        return r;
        
    } else {
        // the rectangles don't intersect
        return {0, 0, -1, -1}; 
    }
}

int main() {
    Rectangle r1 = {1, 2, 4, 3};
    Rectangle r2 = {3, 3, 4, 4};
    //std::cout << std::boolalpha << rangesIntersect(1, 2, 1, 2) << std::endl;
    Rectangle r = rectanglesIntersect(r1, r2);
    std::cout << r.x << ", " << r.y << ", " << r.width << ", " << r.height << "\n";
    return 0;
}
