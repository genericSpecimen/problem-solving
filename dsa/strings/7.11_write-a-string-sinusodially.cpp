#include <iostream>
#include <string>
#include <vector>

std::string snakeString(const std::string &str) {
    std::string snake_str = "";
    
    for (int i=1; i<str.size(); i+=4) {
        snake_str += str[i];
    }
    
    for (int i=0; i<str.size(); i+=2) {
        snake_str += str[i];
    }
    
    for (int i=3; i < str.size(); i+=4) {
        snake_str += str[i];
    }
    
    return snake_str;
}

int main() {
    std::vector<std::string> tests = {
        "Hey",
        "What on earth?",
        "P",
        "Please do not",
        "What is the meaning of this?",
        ""
    };
    for (auto str : tests) {
        std::cout << snakeString(str) << std::endl;
    }
    return 0;
}
