#include <iostream>
#include <vector>
int gcd_two_nums(int num1, int num2) {
    int a = (num1 > num2)? num1 : num2; //max
    int b = (num1 < num2)? num1 : num2; //min
    while(b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int gcd_of_array(std::vector<int>& a) {
    int result = a[0];
    for(int i=1;i<a.size();i++) {
        result = gcd_two_nums(a[i], result);
    }
    return result;
}

int lcm_two_nums(int num1, int num2) {
    return num1/gcd_two_nums(num1,num2) * num2;
}

int lcm_of_array(std::vector<int>& a) {
    int result = a[0];
    for(int i=1;i<a.size();i++) {
        result = lcm_two_nums(a[i], result);
    }
    return result;
}

int get_total(std::vector<int>& a, std::vector<int>& b) {
    int lcm_a = lcm_of_array(a);
    int gcd_b = gcd_of_array(b);
    int count = 0;
    for(int i=lcm_a;i<=gcd_b;i+=lcm_a) {
        if(gcd_two_nums(i, gcd_b) == i) count++; 
    }
    return count;
}

int main() {
    int size1, size2;
    std::cin >> size1 >> size2;
    std::vector<int> a;
    std::vector<int> b;
    for(int i=0;i<size1;i++) {
        int temp;
        std::cin >> temp;
        a.push_back(temp);
    }
    for(int i=0;i<size2;i++) {
        int temp;
        std::cin >> temp;
        b.push_back(temp);
    }
    std::cout << get_total(a,b) << std::endl;
}