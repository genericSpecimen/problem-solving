#include <iostream>

int main() {
    int n; std::cin >> n;
    std::string str;
    for(int i=0;i<n;i++) {
        std::cin >> str;
        std::string even; std::string odd;
        for(int i=0;i<str.size();i++) {
            if(i % 2 == 0) even += str[i];
            else odd += str[i];
        }
        std::cout << even << " " << odd << std::endl;
    }
}