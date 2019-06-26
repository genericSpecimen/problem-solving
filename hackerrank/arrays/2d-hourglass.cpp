#include <iostream>
#include <vector>
#include <climits>

void print_array(int a[6][6]) {
    for(int i=0;i<6;i++) {
        for(int j=0;j<6;j++) std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }
}
int hour_glass_sum(int a[6][6]) {
    /*

    00 01 02    01 02 03    02 03 04    03 04 05
       11          12          13          14 
    20 21 22    21 22 23    22 23 24    23 24 25

    10 11 12    11 12 13    12 13 14    13 14 15
       21          22          23          24  
    30 31 32    31 32 33    32 33 34    33 34 35

    20 21 22
       31
    40 41 42

    30 31 32
       41
    50 51 52

    */
    int max_hourglass_sum = INT_MIN;
    int sum = 0;
    for(int i=1;i<=4;i++) {
        for(int j=1;j<=4;j++) {
            sum = 0;
            sum += (a[i][j] + a[i-1][j-1] + a[i-1][j] + a[i-1][j+1] + a[i+1][j-1] + a[i+1][j] + a[i+1][j+1]);
            if(sum > max_hourglass_sum) max_hourglass_sum = sum;
        }
    }

    return max_hourglass_sum;
}

int main() {
    int a[6][6];
    for(int i=0;i<6;i++) {
        for(int j=0;j<6;j++) std::cin >> a[i][j];
    }
    std::cout << hour_glass_sum(a) << std::endl;
}