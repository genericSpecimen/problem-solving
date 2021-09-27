#include <iostream>
#include <bitset>

/*
 * Bit by bit addition.
 * O(n) time complexity.
 */
unsigned long add(unsigned long x, unsigned long y) {
    unsigned long sum = 0;
    // mask will denote the position of the bit we're adding
    unsigned long mask = 1;
    
    unsigned long temp_x = x, temp_y = y;
    
    unsigned long xm, ym, carry = 0;
    while (temp_x != 0 || temp_y != 0) {
        // get the bits of x and y at the current bit position
        xm = x & mask;
        ym = y & mask;
        
        // compute the sum (XOR) and carry at this position
        sum = sum | (xm ^ ym ^ carry);
        carry = (xm & ym) | (xm & carry) | (ym & carry);
        
        // propagate the carry and mask to the next bit position
        carry = carry << 1;
        mask = mask << 1;
        
        // just to know when to stop
        temp_x = temp_x >> 1;
        temp_y = temp_y >> 1;
        
    }
    
    // account for any leftover carry
    sum = sum | carry;
    
    return sum;
}

/*
 * n additions are required for a single multiplication.
 * Total time complexity: O(n^2)
 */
unsigned long multiply(unsigned long x, unsigned long y) {
    unsigned long product = 0;
    
    while (x != 0) {
        // if the bit is set
        if (x & 1) {
            // add y to the product
            product = add(product, y);
        }
        // now need to look at the next bit of x
        x = x >> 1;
        // to factor in the 2^k caused by shifting
        y = y << 1;
    }
    
    return product;
}

int main() {
    unsigned long x = 78;
    std::cout << std::bitset<8*sizeof(x)>(x) << std::endl;
    unsigned long y = 9;
    std::cout << std::bitset<8*sizeof(y)>(y) << std::endl;
    std::cout << multiply(x, y) << std::endl;
    return 0;
}
