#include <iostream>
#include <cmath>

/*
 * Brute force:
 * O(y-1) multiplications = O(2^n),
 * where n = num bits in y.
 */
/*
double power(double x, int y) {
    double result = 1.0;
    
    long long power = y;
    if (y < 0) {
        x = 1/x;
        power = -power;
    }    
    
    while (power != 0) {
        result = result * x;
        power--;
    }
    
    return result;
}
*/

/*
 * x^5 = x^4 * x
 * x^4 = x^2 * x^2 iterated squaring when powers of 2
 * 
 * if LSB(y) == 0 => result = (x^(y/2))^2
 *              else,result = ((x^(y/2))^2) * x
 * 
 * number of multiplications = at most twice the index (1-based) of MSB(y)
 * eg: y = 0b00111
 * takes 2 multiplications in each of the 3 iterations.
 * 
 * therefore, O(2n) = O(n)
 */
double power(double x, int y) {
    double result = 1.0;
    long long power = y;
    if (y < 0) {
        x = 1/x;
        power = -power;
    }
    
    while (power != 0) {
        if (power & 1) {
            // eg: x^5 = (x^2)^2 * x;
            result = result * x;
        }
        // eg: x^2 = x * x
        x = x * x;
        
        power = power >> 1;
    }
    return result;
}

int main() {
    double x = -3.1;
    int y = 8;
    std::cout << pow(x, y) << std::endl;
    std::cout << power(x, y) << std::endl;    
    return 0;
}
