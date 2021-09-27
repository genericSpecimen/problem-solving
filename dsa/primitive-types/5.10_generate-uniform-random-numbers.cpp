#include <iostream>
#include <cstdlib>

int zeroOneTrial() {
    return rand()%2;
}

/*
 * Generate a random number in the range [L, U]
 * = generate a random num in the range [0, U-L], then add L.
 * if (U-L) == (2^i - 1), the problem is to generate a random number
 * in the range [0, 2^i-1], which can be done by concatenating
 * the results of i zero-one trials.
 * 
 * if (U-L) != (2^i - 1), then find the smallest i such that
 * 2^i-1 > (U-L).
 * Then, generate numbers as before and return them only if
 * they lie in [0, U-L]
 * 
 * number of outcomes, t = U-L+1
 * P(success on first try): t / 2^i,
 * where 2^i (the smallest power of 2) >= t
 * => 2^i < 2t
 * 
 * eg:
 * t = 6 = 0b0110
 * i = 3, 2^i = 8 >= t
 *     8 = 0b1000
 * 2t=12 = 0b1100
 * 
 *      2^i < 2t
 * => t/2^i > t/2t
 *          = (1/2)
 * this means that the probability of success on the
 * first try is more than 50% and the probability of failure
 * is (1 - t/2^i) < 1/2
 * 
 * P(k failures) < 1/2^k
 * expected number of tries, = 1 + 2(1/2)^1 + 3(1/2)^2 = O(1).
 * 
 * each try makes ceil(log_2(U-L+1)) calls to zeroOneTrial, which runs in O(1) time.
 * => overall running time: O(log_2(U-L+1))
 */
int uniformRandom(int L, int U) {
    int result = 0;
    //std::cout << (U-L) << "\n";
    
    do {
        result = 0;
        for (int i=0; (1 << i)-1 <= (U-L); i++) {
            //std::cout << i << ": " << (1 << i)-1 << "\n";
            //std::cout << "Trial " << i << ": generated " << zeroOneTrial() << "\n";
            result = result << 1;
            result = result | zeroOneTrial();
        }
    } while (result > (U-L)); // try again in case the result is out of range
    
    return result + L;
    
}

int main() {
    for (int i=0; i<1000; i++) {
        std::cout << uniformRandom(2, 10) << ", ";
    }
    std::cout << "\n";
}
