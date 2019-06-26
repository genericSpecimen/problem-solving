#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::string path;
    std::cin >> path;

    int altitude = 0;
    int num_valleys = 0;

    for(int i=0;i<path.length();i++) {
        if(path[i] == 'U') {
            altitude++;
            if(altitude == 0) num_valleys++;
        } else if(path[i] == 'D') {
            altitude--;
        }
    }
    std::cout << num_valleys << std::endl;
}