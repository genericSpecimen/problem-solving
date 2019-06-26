#include <iostream>

struct X {
    enum direction { left = 'l', right = 'r'};
};

X x;
X* p = &x;

// enum Color { red, yellow, green=20, blue};

enum class Color { red, green = 20, blue};

int main() {
    /*
    Color r = red;
    int n = red;
    std::cout << n << std::endl;
    n = green;
    std::cout << n << std::endl;
    n = blue;
    std::cout << n << std::endl;

    int a = X::direction::left; std::cout << a << std::endl;
    int b = X::left; std::cout << b << std::endl;
    int c = x.left; std::cout << c << std::endl;
    int d = p->left; std::cout << d << std::endl;
    */

    Color r = Color::blue;
    switch(r) {
        case Color::red : std::cout << "red" << std::endl; break;
        case Color::blue : std::cout << "blue" << std::endl; break;
    }

    int n = static_cast<int>(r); std::cout << n << std::endl;
}