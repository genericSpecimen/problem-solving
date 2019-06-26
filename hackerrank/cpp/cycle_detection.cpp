#include <iostream>

#define mod (1U << 31)
unsigned int p,q;

unsigned int f(unsigned int x) {
    return (x*p + q) % mod;
}

unsigned int floyd() {
    unsigned int n,s; std::cin >> n >> s >> p >> q;
    unsigned int x0 = s % mod; 
    unsigned int count = 1; // 1 for x0

    unsigned int tortoise = f(x0);
    unsigned int hare = f(f(x0));

    while(tortoise != hare) {
        count++;
        if(count >= n) return count;
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    // if the while loop ends, it means a cycle has been detected
    /*
        * the tortoise position, nu, equal to distance between hare and tortoise, is divisible by
        * the period lambda
    */

    unsigned int mu = 0;
    tortoise = x0;
    while(tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }

    unsigned int lambda = 1;
    hare = f(tortoise);
    while(tortoise != hare) {
        hare = f(hare);
        lambda++;
    }

    return (lambda + mu);

}
int main() {
    std::cout << floyd() << std::endl;
}