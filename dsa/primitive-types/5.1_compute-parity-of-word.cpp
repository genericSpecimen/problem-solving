#include <iostream>
#include <vector>
/*
 * O(n) time, where n = number of bits
int compute_parity(unsigned long num) {
    int p = 0;
    
    while (num) {
        p = p ^ (num & 1);
        num = num >> 1;
    }
    
    return p;
}
*/
/*
 // O(s) time, where s = number of 1 bits
int compute_parity(unsigned long num) {
    int p = 0;
    
    while (num) {
        p = p ^ 1;
        // set the rightmost 1 bit to 0
        num = (num & (num-1));
    }
    
    return p;
}
*/

/*
 * Improvements:
 * Process multiple bits at a time
 * Cache results
 */

#define P2(n)   n,n^1,n^1,n 
#define P4(n)   P2(n),P2(n^1),P2(n^1),P2(n)
/*
#define P8h   P4(0),P4(1),P4(1),P4(0),\
                P4(1),P4(0),P4(0),P4(1),\
                P4(1),P4(0),P4(0),P4(1),\
                P4(0),P4(1),P4(1),P4(0)
*/
#define P8(n)   P4(n),P4(n^1),P4(n^1),P4(n),\
                P4(n^1),P4(n),P4(n),P4(n^1),\
                P4(n^1),P4(n),P4(n),P4(n^1),\
                P4(n),P4(n^1),P4(n^1),P4(n)

// parity lookup table for all 8-bit words
std::vector<int> parity_lookup = {P8(0)};

int compute_parity_32(unsigned int num) {
    /*
     * 32-bit num.
     * Divide it into blocks of 8 bits,
     * lookup parity of these 8 bit words,
     * XOR these results to get the parity of num.
     * 
     * after the table has been computer, this takes
     * O(n/w) where n = no. of bits in num, L = word_size,
     * assuming word level operations like shifting take O(1) time
     */
    
    const int word_size = 8;
    const int mask = 0xFF; // used to get the last "word_size" bits
    int p = parity_lookup[(num >> (3*word_size))] ^
            parity_lookup[(num >> (2*word_size)) & mask] ^
            parity_lookup[(num >> word_size) & mask] ^
            parity_lookup[num & mask];
    
    return p;
}

/*
 * XOR is commutative and associative
 */
int compute_parity_64(unsigned long num) {
    num = num ^ (num >> 32);
    num = num ^ (num >> 16);
    num = num ^ (num >> 8);
    
    /*
    // either this, or, simply lookup the parity of the 8 bit result
    num = num ^ (num >> 4);
    num = num ^ (num >> 2);
    num = num ^ (num >> 1);
    */
    int p = parity_lookup[num & 0xFF];
    
    return p;
}

int main() {
    unsigned long x = 0x7FFFFFFFFFFFFFFF;
    std::cout << compute_parity_32(x) << std::endl;
    std::cout << compute_parity_64(x) << std::endl;
    return 0;
}
