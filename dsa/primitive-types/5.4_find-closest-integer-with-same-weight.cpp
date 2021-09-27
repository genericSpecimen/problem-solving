#include <iostream>
#include <bitset>

/*
 * Swap the two rightmost consecutive bits that differ
 * O(n) time complexity.
 */
/*
unsigned long closestSameWeightInteger(unsigned long x) {
    for (int i=0; i<8*sizeof(x)-1; i++) {
        // if ith and i+1th bit differ
        if ( ((x >> i) & 1) != ((x >> (i+1)) & 1) ) {
            x = x ^ ( (1UL << i) | (1UL << (i+1)) );
            return x;
        }
    }
    
    throw std::invalid_argument("All bits are 0 or 1");
}
*/

/*
 * Find the lowest set bit and the lowest unset bit.
 * By defintion, they are different.
 * Depending on the location of these bits, set / flip bits.
 * 
 * O(1) constant time.
 */
unsigned long closestSameWeightInteger(unsigned long x) {
    unsigned long lowest_bit_set = x & ~(x - 1);
    unsigned long lowest_bit_notset = ~x & ~(~x - 1);
    std::cout << std::bitset<8*sizeof(lowest_bit_set)>(lowest_bit_set) << std::endl;
    std::cout << std::bitset<8*sizeof(lowest_bit_notset)>(lowest_bit_notset) << std::endl;
    
    if (lowest_bit_notset > lowest_bit_set) {
        // set the lowest unset(0) bit to 1
        x = x | lowest_bit_notset;
        // and flip the next bit (which is not 0), so that weight is maintained
        x = x ^ (lowest_bit_notset >> 1);
    } else {
        // flip the lowest set bit
        x = x ^ lowest_bit_set;
        // set the next bit (which is not 1) to 1  
        x = x | (lowest_bit_set >> 1);
    }
    
    return x;
}


int main() {
    unsigned long x = 6;
    std::cout << std::bitset<8*sizeof(x)>(x) << std::endl;
    unsigned long y = closestSameWeightInteger(x);
    std::cout << std::bitset<8*sizeof(y)>(y) << std::endl;
    
}
