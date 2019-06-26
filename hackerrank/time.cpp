#include <iostream>

std::string timeconversion(std::string s) {
    int am_pos = s.find("AM");
    int pm_pos = s.find("PM");
    if(am_pos != std::string::npos) {
        std::string hh = s.substr(0,2);
        int hour = std::atoi(hh.c_str());
        if(hour == 12) hh = "00";
        std::string result = hh + s.substr(2,6);
        return result;
    } else if(pm_pos != std::string::npos) {
        std::string hh = s.substr(0,2);
        int hour = std::atoi(hh.c_str());
        if(hour < 12) hh = std::to_string(hour + 12);
        else if(hour == 12) hh = "12";
        std::string result = hh + s.substr(2,6);
        return result;
    }
    return "Invalid time";
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::cout << timeconversion(input) << std::endl;
}