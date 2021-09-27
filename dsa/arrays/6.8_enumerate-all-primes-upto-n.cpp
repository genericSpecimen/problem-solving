#include <iostream>
#include <vector>
#include <deque>

template <class T>
std::ostream& operator<< (std::ostream& os, const std::vector<T> v) {
    os << "[";
    for (auto elem : v) {
        os << elem << ",";
    }
    os << "]";
    return os;
}
std::vector<int> generatePrimesUpto(int n) {
    std::vector<int> primes;
    std::deque<bool> is_prime(n+1, true);
    is_prime[0] = false; is_prime[1] = false;
    
    for (int num=2; num<n; num++) {
        if (is_prime[num]) {
            primes.push_back(num);
            for (int i=num+num; i<=n; i+=num) {
                // mark all multiples of num (except itself) false
                is_prime[i] = false;
            }
        }
    }
    std::cout << primes.size() << std::endl;
    return primes;
}

std::vector<int> generatePrimesUpto1(int n) {
    std::vector<int> primes;
    std::deque<bool> is_prime(n+1, true);
    is_prime[0] = false; is_prime[1] = false;
    
    for (int num=2; num*num<n; num++) {
        if (is_prime[num]) {
            for (int i=num*num; i<=n; i+=num) {
                // mark all multiples of num (except itself) false
                is_prime[i] = false;
            }
        }
    }
    
    int count = 0;
    for (int i=2; i<n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            count++;
        }
    }
    
    std::cout << primes.size() << std::endl;
    return primes;
}

int main() {
    int n = 10000000;
    //std::cout << generatePrimesUpto(n) << std::endl;
    generatePrimesUpto(n);
    //std::cout << generatePrimesUpto1(n) << std::endl;
    //generatePrimesUpto1(n);
    return 0;
}
