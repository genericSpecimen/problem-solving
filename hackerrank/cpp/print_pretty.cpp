#include <iostream>
#include <iomanip>

std::string decimal_to_hex(double a) {
    int trunc_a = (int) a;
    std::string lookup("0123456789ABCDEF");
    std::string result("");
    int temp = 0;
    int rem;
    do {
        rem = trunc_a % 16;
        result = lookup[rem] + result;
        trunc_a /= 16;
    } while(trunc_a > 0);

    return result;
}

int main() {
    double a,b,c;
    std::cin >> a >> b >> c;
    std::cout << std::nouppercase << std::left << std::showbase << std::setbase(16) << (int) a << std::endl;
    std::cout << std::right << std::setw(15) << std::setfill('_') << std::showpos << std::fixed << std::setprecision(2) << b << std::endl;
    std::cout << std::uppercase << std::noshowpos << std::scientific << std::setprecision(9) << c << std::endl;
}