#include <iostream>
#include <cmath>

int main() {
    double meal_cost;
    int tip_percent, tax_percent;
    std::cin >> meal_cost >> tip_percent >> tax_percent;
    double tip = meal_cost * (tip_percent/(double)100);
    double tax = meal_cost * (tax_percent/(double)100);
    double total_cost = meal_cost + tip + tax;
    std::cout << std::round(total_cost) << std::endl;
}