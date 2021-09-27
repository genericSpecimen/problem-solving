#include <iostream>

struct Point {
    int x, y;
};

bool isOrthogonal(Point &p1, Point &p2, Point &p3) {
    // located vectors
    Point u = {p1.x - p2.x, p1.y - p2.y};
    //std::cout << "u: (" << u.x << ", " << u.y << ")\n";
    Point v = {p3.x - p2.x, p3.y - p2.y};
    //std::cout << "v: (" << v.x << ", " << v.y << ")\n";
    
    int dot_product = (u.x * v.x) + (u.y * v.y);
    //std::cout << "dot: " <<  dot_product << std::endl;
    
    if (dot_product == 0) {
        return true;
    }
    
    return false;
}

bool isRectangle(Point &p1, Point &p2, Point &p3, Point &p4) {
    if (isOrthogonal(p1, p2, p3) &&
        isOrthogonal(p2, p3, p4) &&
        isOrthogonal(p3, p4, p1)) {
            return true;
        }
    return false;
}

bool isRectangleAnyOrder(Point &p1, Point &p2, Point &p3, Point &p4) {
    if (isRectangle(p1, p2, p3, p4) ||
        isRectangle(p2, p3, p4, p1) ||
        isRectangle(p3, p4, p1, p2) ||
        isRectangle(p4, p1, p2, p3)
    ) {
        return true;
    }
    return false;
}

int main() {
    Point p1 = {2, 6};
    Point p2 = {2, 3};
    Point p3 = {5, 3};
    Point p4 = {5, 6};
    
    std::cout << std::boolalpha << isRectangleAnyOrder(p1, p2, p3, p4) << std::endl;
    
    return 0;
}
