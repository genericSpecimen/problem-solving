#include <iostream>
#include <vector>
#include <algorithm>
/*
 * given an array, return the smallest number which is not
 * a sum of some subset of the elements of the array
 * [12, 2, 1, 15, 2, 4]
 */

int smallestNonConstructibleValue(std::vector<int>& A) {
    int max_value = 0;
    
    std::sort(A.begin(), A.end()); // O(n log n) sort
    
    for (int num : A) { // O(n) iterate
        if (num > max_value + 1) {
            // we can't generate max_value + 1 because num is greater than that
            // so max_value + 1 is the smallest non constructible value.
            break;
        } else {
            // num <= max_value + 1, so we can generate max_value + 1 as well
            max_value += num;
        }
    }
        
        return max_value + 1;
}

int main() {
    std::vector<int> A = {12, 2, 1, 15, 2, 4};
    std::cout << smallestNonConstructibleValue(A) << std::endl;
}
