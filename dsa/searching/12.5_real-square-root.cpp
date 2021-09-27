#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

using namespace std;

int compare(double a, double b) {
    double diff = (a - b) / b;
    
    if (diff < -numeric_limits<double>::epsilon()) return -1;
    else if (diff > numeric_limits<double>::epsilon()) return 1;
    return 0;
}

double sqrt(double x) {
    if (x < 0) throw std::invalid_argument("x < 0");
    
    double low = 1.0, high = x;
    if (x < 1.0) {
        std::swap(low, high);
    }
    
    while (low <= high) {
        double mid = low + 0.5 * (high - low);
        double mid_squared = mid * mid;
        
        
        
        if (compare(mid_squared, x) == 0) return mid;
        else if (compare(mid_squared, x) == -1) low = mid;
        else high = mid;
    }
    
    return 0;
}

int main() {
    vector<double> nums = {0.1, 0.25, 0.5, 0.64, 1.0, 25.0, 30.25, 2147483648.0};
    //cout << std::fixed;
    //for (auto num : nums) cout << std::setprecision(10) << num << ": " << sqrt(num) << endl;
    for (auto num : nums) cout << num << ": " << sqrt(num) << endl;
}
