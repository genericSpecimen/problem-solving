#include <iostream>
#include <map>

int main() {
    int m, n; std::cin >> m >> n;
    std::map<std::string, int> magazine_words;
    std::string temp;
    while(m--) {
        std::cin >> temp;
        magazine_words[temp]++;
    }
    int num_match = 0;
    int n_copy = n;
    while(n_copy--) {
        std::cin >> temp;
        auto it = magazine_words.find(temp);
        if(it != magazine_words.end() && it->second > 0) {
            num_match++;
            (it->second)--; // word is used up
        }
    }
    if(num_match == n) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
}