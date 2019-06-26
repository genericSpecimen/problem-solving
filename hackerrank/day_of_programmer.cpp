#include <iostream>

void day_of_programmer(int y) {
    //int days = 215; //sum of number of days in jan,march,april,may,june,july,august
    int day_of_programmer = 256;
    if(y >= 1700 && y <= 1917) {
        // Julian calendar
        if(y % 4 == 0) {
            std::cout << "12.09." << y << std::endl;
        } else {
            std::cout << "13.09." << y << std::endl;
        }
    }
    else if(y == 1918) {
        // transition
        std::cout << "26.09." << y << std::endl;
    }
    else if(y >= 1919 && y <= 2700) {
        // Gregorian calendar
        if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
            // leap year
            std::cout << "12.09." << y << std::endl;

        } else {
            std::cout << "13.09." << y << std::endl;
        }
    }
}

int main() {
    int y;
    std::cin >> y;
    day_of_programmer(y);
}