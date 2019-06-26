#include <iostream>
#include <bitset>
#include <array>

template <bool...digits>
void test() {
    std::array<bool, sizeof...(digits)> ar{digits...};
    std::bitset<sizeof...(digits)> bits;
    for(int i=0;i<ar.size();i++) {
        bits[i] = ar[i];
    }
    std::cout << bits.to_ulong() << std::endl;
}

int main() {
    test<0,0,1>();
}