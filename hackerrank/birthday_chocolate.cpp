#include <iostream>
#include <vector>

int ways_to_portion(std::vector<int> numbers_on_squares, int d, int m) {
    // select m squares that sum to d
    int count = 0;
    for(int i=0;i<numbers_on_squares.size();i++) {
        int length = 0;
        int sum = 0;
        for(int j=i;j<numbers_on_squares.size();j++) {
            length++;
            sum += numbers_on_squares[j];
            if(length == m && sum == d) {
                count++;
                break;
            }
            if(sum > d || length > m) break;
        }
    }
    return count;
}

int main() {
    int n; //number of squares
    std::cin >> n;
    
    std::vector<int> numbers_on_squares;
    int temp;
    for(int i=0;i<n;i++) {
        std::cin >> temp;
        numbers_on_squares.push_back(temp);
    }

    int d; // birth day
    int m; // birth month
    std::cin >> d >> m;

    std::cout << ways_to_portion(numbers_on_squares, d, m) << std::endl;
    
}