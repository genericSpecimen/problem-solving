#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

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
 * m partial products, each with at most n+1 digits
 * O(1) operations on each digit in each partial product,
 * therefore, O(mn) time complexity.
 */

std::vector<int> multiply(std::vector<int> &num1, std::vector<int> &num2) {
    // record the sign of the result
    int sign = ((num1.front() < 0) ^ (num2.front() < 0)) ? -1 : 1;
    // and then work with nonnegative integers
    num1.front() = std::abs(num1.front());
    num2.front() = std::abs(num2.front());
    
    // number of digits required = O(m+n) where m, n = num digits
    std::vector<int> result(num1.size()+num2.size(), 0);
    
    int carry = 0;

    for (int j=num2.size()-1; j>=0; j--) {
        for (int i=num1.size()-1; i>=0; i--) {
            result[i+j+1] += num2[j] * num1[i];
            carry = result[i+j+1] / 10;
            result[i+j] += carry;
            result[i+j+1] %= 10;
        }
    }
    
    // strip leading zeros
    auto is_zero = [](int i) { return i==0; };
    result = { std::find_if_not(result.begin(), result.end(), is_zero), result.end()};
    
    result.front() = sign * result.front();
    return result;
}

int main() {
    
    //std::vector<int> num1 = {1,9,3,7,0,7,7,2,1};
    //std::vector<int> num2 = {-7,6,1,8,3,8,2,5,7,2,8,7};
    
    std::vector<int> num1 = {1, 2 ,3};
    std::vector<int> num2 = {-4, 5, 6};
    
    std::cout << multiply(num1, num2) << std::endl;
}
