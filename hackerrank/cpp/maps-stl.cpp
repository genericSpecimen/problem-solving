#include <iostream>
#include <map>

int main() {
    int n; std::cin >> n;
    int type;
    std::string x;
    int y;

    std::map<std::string,int> marks;
    for(int i=0;i<n;i++) {
        std::cin >> type;
        switch(type) {
            case 1: std::cin >> x >> y; marks[x] += y; break;
            case 2: std::cin >> x; marks.erase(x); break;
            case 3: std::cin >> x; auto it = marks.find(x); std::cout << (it != marks.end() ? it->second : 0) << std::endl; break;
        }
    }
}