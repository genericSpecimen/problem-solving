#include <iostream>
#include <vector>

// https://leetcode.com/problems/plus-one/

template <class T>
std::ostream& operator<< (std::ostream& os, const std::vector<T> v) {
    os << "[";
    for (auto elem : v) {
        os << elem << ", ";
    }
    os << "]";
    return os;
}

/*
 * Grade school addition method.
 * O(n), where n = size of array
 */
std::vector<int> plusOne(std::vector<int>& digits) {
    // increment the LSD
    int lsd_idx = digits.size()-1;
    int sum = digits[lsd_idx] + 1;
    digits[lsd_idx] = sum % 10;
    int carry = sum >= 10 ? 1 : 0;
    
    // propagate the carry, if any
    for (int i=lsd_idx-1; i>=0 && carry==1; i--) {
        sum = carry + digits[i];
        digits[i] = sum % 10;
        carry = sum >= 10 ? 1 : 0;
    }

    if (carry == 1) {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

int main() {
    std::vector<int> number = {1, 2, 9, 9};
    std::cout << plusOne(number) << std::endl;
}
