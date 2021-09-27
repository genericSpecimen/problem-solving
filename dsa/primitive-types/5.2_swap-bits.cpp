#include <iostream>
#include <bitset>

/*
 * Time complexity: O(1)
 */
unsigned long swap_bits(unsigned long x, int i, int j) {    
    // check if the bits differ
    if ( ((x >> i) & 1) != ((x >> j) & 1) ) {
        // if yes, simply flip these bits
        
        // bits to flip are denoted by this mask
        unsigned long mask = ((1L << i) | (1L << j));
        //std::cout << std::bitset<8*sizeof(mask)>(mask) << std::endl;
        x = x ^ mask;
    }
    
    return x;
}

int main() {
    unsigned long x = 0b01001001;
    std::cout << std::bitset<8*sizeof(x)>(x) << std::endl;
    unsigned long y = swap_bits(x, 1, 6);
    std::cout << std::bitset<8*sizeof(y)>(y) << std::endl;
}
