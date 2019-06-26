#include <iostream>
#include <map>

int main() {
    int n; std::cin >> n;
    std::map<std::string, unsigned int> phone_book;
    std::string name;
    unsigned int number;
    while(n--) {
        std::cin >> name >> number;
        phone_book[name] = number;
    }
    std::string query_name;
    while(std::cin >> query_name) {
        auto it = phone_book.find(query_name);
        if(it != phone_book.end()) {
            std::cout << it->first << "=" << it->second << std::endl;
        } else std::cout << "Not found" << std::endl;
    }
}