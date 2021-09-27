#include <iostream>
#include <bitset>

int main() {
    //int x = 0b00101100;
    /*
    std::bitset<8> x{"00101100"};
    std::cout << sizeof(x) << std::endl;
    std::cout << x << std::endl;
    */
    /*
    // left shift
    std::cout << (x << 1) << std::endl;
    // right shift
    std::cout << (x >> 1) << std::endl;
    */
    // bitmasking
    //x &= 0b00000001;
    //std::cout << x << std::endl;
    
    
    // time complexity: O(n), where n = length of integer
    int x = 0b00101100;
    int count = 0;
    for (int i=0; i<8*sizeof(x); i++) {
        if (x & 1 == 1) {
            count++;
        }
        x = x >> 1;
    }
    std::cout << count << std::endl;
    
    /*
     * x-1  = x + (-1) = x + 2's complement of 1
     *      = 00101100 + 11111111
     *      = 00101011
     */
    x = 0b00101100;
    std::cout <<  std::bitset<8*sizeof(x)>(x) << std::endl;
    std::cout <<  std::bitset<8*sizeof(x)>(x - 1) << std::endl;
    std::cout <<  std::bitset<8*sizeof(x)>(~(x - 1)) << std::endl;
    int y = x & ~(x - 1);
    std::cout <<  std::bitset<8*sizeof(y)>(y) << std::endl;
    int z = x ^ y;
    std::cout <<  std::bitset<8*sizeof(z)>(z) << std::endl;
    
    count = 0;
    while (true){
        y = x & ~(x - 1);
        if (y == 0) {
            break;
        }
        count++;
        x = x ^ y;
    }
    std::cout << count << std::endl;
    
    x = 0b01010000;
    int mask = x & ~(x - 1);
    while (mask != 0) {
        x = x | mask;
        mask = mask >> 1;
    }
    std::cout <<  std::bitset<8*sizeof(x)>(x) << std::endl;
    
    // x mod 2^n =
    // x modulo y = (x & (y − 1))
    x = 77;
    int modulo = 128;
    std::cout <<  (x & (modulo-1)) << std::endl;
    
    
    // power of two: (x & (x-1)) == 0
    
    return 0;
}
