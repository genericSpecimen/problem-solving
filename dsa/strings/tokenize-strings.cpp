#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string str = "11 + -9 + 2003";
    
    /*
     * istringstream implements input operations on string based streams.
     * It effectively stores an instance of std::basic_string
     * and performs input operations on it. 
     */
    /*
    auto iss = std::istringstream(str);
    
    std::string tok;
    while (iss >> tok) {
        std::cout << tok << ", " << tok.size() << std::endl;
    }
    */
    
    
    std::string path = "/home///hooman/../hooman/Download/Telegram Desktop/";
    std::stringstream ss(path);
    std::string tok;
    while (std::getline(ss, tok, '/')) {
        std::cout << "size: " << tok.size() << ": " << tok << std::endl;
    }
}
