#include <iostream>
#include <array>
#include <vector>

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v) {
    os << "[";
    for (auto x : v) {
        os << x << ", ";
    }
    os << "]";
    
    return os;
}

void size_test(int b[]) {
    int a[5] = {1, 2, 3, 4, 5};
    std::cout << sizeof(a) << std::endl;
    
    /*
     * Array b has decayed to a pointer,
     * sizeof no longer returns the correct size.
     * It returns the size of the T* pointer.
     */
    std::cout << sizeof(b) << std::endl;
    std::cout << sizeof(int*) << std::endl;
    std::cout << b << std::endl;
}

int main() {
    int b[5] = {8, 2, 4, 5, 6};
    size_test(b);
    
    // encapsulates c-style arrays, doesn't decay to a pointer
    std::array<int, 5> arr = {89, 289, 389 ,1990, 90};
    std::cout << arr[8] << std::endl;
    // bounds checking - throws std::out_of_range
    //std::cout << arr.at(8) << std::endl;
    
    // encapsulates dynamic sized arrays
    std::vector<double> a = {1, 2, 3, 4};
    std::cout << a.capacity() << ", " << a.size() << std::endl;
    std::cout << a << std::endl;
    
    std::vector<double> bee;
    std::cout << bee.capacity() << ", " << bee.size() << std::endl;
    bee.push_back(12);
    std::cout << bee.capacity() << ", " << bee.size() << std::endl;
    std::cout << bee << std::endl;

    int sz = 200;
    std::vector<int> v1;
 
    auto cap = v1.capacity();
    std::cout << "initial capacity=" << cap << '\n';
 
    for (int n = 0; n < sz; ++n) {
        v1.push_back(n);
        if (cap != v1.capacity()) {
            cap = v1.capacity();
            std::cout << "new capacity=" << cap << '\n';
        }
    }
 
    std::cout << "final size=" << v1.size() << '\n';
    std::cout << "final capacity=" << v1.capacity() << '\n';
    
    
    int i=0, j=5;
    std::vector<int> subvec(v1.begin()+i, v1.begin()+j);
    std::cout << subvec << std::endl;

    return 0;
}
