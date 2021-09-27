#include <iostream>
#include <vector>

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v) {
    os << "[";
    for (auto x : v) {
        os << x << ", ";
    }
    os << "]";
    
    return os;
}

/*
 * O(n^2) time and space complexity.
 * row 1: 1 elem
 * row 2: 2 elems
 * row 3: 3 elems
 * ...
 * row n: n elems
 * ________________
 * total: 1+2+3+...+n = n(n+1)/2 = O(n^2)
 */

std::vector<std::vector<long long>> generate(int numRows) {
    /*
    // not necessary, gets implicitly handled by the j loop
    if (numRows == 1) {
        return {{1}};
    }
    if (numRows == 2) {
        return {{1},{1,1}};
    }
    */
    std::vector<std::vector<long long>> pascals_triangle(numRows);
    
//     for (int i=0; i<numRows; i++) {
//         pascals_triangle[i] = std::vector<long long>(i+1, 1);
//     }
    
    
    for (int i=0; i<numRows; i++) {
        pascals_triangle[i] = std::vector<long long>(i+1, 1);
        for (int j=1; j<i+1-1; j++) {
            // compute
            pascals_triangle[i][j] = pascals_triangle[i-1][j-1] + pascals_triangle[i-1][j];
        }
    }
    
    return pascals_triangle;
}

int main() {
    int numRows = 1000;
    generate(numRows);
    //std::cout << generate(numRows) << std::endl;
}
