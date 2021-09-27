#include <iostream>

/*
 * Compute x/y
 * Brute force: subtract y from x until x < y.
 * The number of times this subtraction was
 * performed is the quotient.
 * Complexity: O(x) when y = 1 
 */
/*
unsigned long quotient(unsigned long x, unsigned long y) {
    unsigned long q = 0;
    
    while (x >= y) {
        q++;
        x = x - y;
    }
    
    return q;
}
*/

/*
 * Improvement: try to find the largest k such that
 * 2^k y <= x and then subtract it from x.
 * Add 2^k to the quotient. Continue until x < y.
 * 
 * O(n) time complexity.
 */
unsigned long quotient(unsigned long x, unsigned long y) {
    unsigned long q = 0;
    // start checking from 2^32 y
    int two_power = 32;
    unsigned long long two_power_y = static_cast<unsigned long long>(y) << two_power;
    
    while (x >= y) {
        // find two_power_y <= x
        while (two_power_y > x) {
            // decrement "k"
            two_power_y = two_power_y >> 1;
            two_power--;
        }
        
        // now 2^k y <= x
        
        x = x - two_power_y;
        q += (1UL << two_power);
    }
    return q;
}


int main() {
    unsigned long x = 0x8fffffffffffffff, y = 9;
    std::cout << x / y << std::endl;
    std::cout << quotient(x, y) << std::endl;    
}
