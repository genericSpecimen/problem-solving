#include <iostream>
#include <bitset>

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

/*
 * Simple brute force : swap the 32 LSBs with corresponding MSBs
 * Time Complexity: 32 O(1) swaps = O(n/2)
 */
/*
unsigned long reverse_bits(unsigned long x) {
    for (int i=0; i<8*sizeof(x)/2; i++) {
        //std::cout << "swapping " << i << " and " << 8*sizeof(x)-1-i << "\n";
        x = swap_bits(x, i, 8*sizeof(x)-1-i);
        //std::cout << i << ": " << std::bitset<8*sizeof(x)>(x) << std::endl;
    }
    return x;
}
*/

/*
 * Create a lookup table for the reverse of 16 bit words.
 * Break 64 bit word into 4 chunks of 16 bits.
 * For each least significant chunk, lookup the reverse
 * and store it in the corresponding most significant chunk.
 * 
 * Time: O(n/L), n-bit integers, L-bit cache keys.
 */
/*
unsigned long reverse_bits(unsigned long x) {
    const int word_size = 16;
    const int bit_mask = 0xFFFF;
    
    unsigned long result =  (reverse_lookup[x & bit_mask] << (3*word_size)) |
                            (reverse_lookup[(x >> word_size) & bit_mask] << (2*word_size)) |
                            (reverse_lookup[(x >> 2*word_size) & bit_mask] << word_size) |
                            (reverse_lookup[(x >> 3*word_size) & bit_mask]);
}
*/

/*
1010 1011
    \/
    /\
1011 1010
 \/    \/
 /\    /\
11 10 10 10

1100

// first 16 bits    last 16 bits
num & 0xffff0000    num & 0x0000ffff
// shift right >> 16  shift left << 16
((num & 0xffff0000) >> 16) | ((num & 0x0000ffff) << 16);
*/

uint32_t reverseBits(uint32_t n) {
    //std::cout << std::bitset<8*sizeof(n)>(n) << std::endl;
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    //std::cout << std::bitset<8*sizeof(n)>(n) << std::endl;
    n = ((n & 0xff00ff00) >>  8) | ((n & 0x00ff00ff) <<  8);
    //std::cout << std::bitset<8*sizeof(n)>(n) << std::endl;
    n = ((n & 0xf0f0f0f0) >>  4) | ((n & 0x0f0f0f0f) <<  4);
    //std::cout << std::bitset<8*sizeof(n)>(n) << std::endl;
    n = ((n & 0xcccccccc) >>  2) | ((n & 0x33333333) <<  2);
    //std::cout << std::bitset<8*sizeof(n)>(n) << std::endl;
    n = ((n & 0xaaaaaaaa) >>  1) | ((n & 0x55555555) <<  1);
    return n;
}

int main() {
    /*
    unsigned long x = 0b10101010;
    //std::cout << std::bitset<8*sizeof(x)>(x) << std::endl;
    unsigned long x_rev = reverse_bits(x);
    //std::cout << std::bitset<8*sizeof(x_rev)>(x_rev) << std::endl;
    */
    
    uint32_t x = 0b11101010101111010101;
    std::cout << std::bitset<8*sizeof(x)>(x) << std::endl;
    uint32_t x_rev = reverseBits(x);
    std::cout << std::bitset<8*sizeof(x_rev)>(x_rev) << std::endl;
    return 0;
}
