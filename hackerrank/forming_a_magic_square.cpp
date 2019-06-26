#include <iostream>
#include <climits>
#include <cmath>

int minimum_cost(int input[3][3]) {
    // possible 3 x 3 magic squares
    int magic_squares[8][3][3] = {
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
    };

    int min_cost = INT_MAX;
    for(int i=0;i<8;i++) {
        int cost = 0;
        for(int j=0;j<3;j++) {
            for(int k=0;k<3;k++) {
                cost += std::abs(input[j][k] - magic_squares[i][j][k]); 
            }
        }
        if(cost < min_cost) min_cost = cost;
    }
    return min_cost;
}

int main() {
    int input[3][3];
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) std::cin >> input[i][j];
    }
    std::cout << minimum_cost(input) << std::endl;
}