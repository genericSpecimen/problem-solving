#include <iostream>
#include <vector>

std::vector<int>& round_off(std::vector<int>& grades) {
    for(int i=0;i<grades.size();i++) {
        if(grades[i] >= 38) {
            int y = grades[i];
            while(y % 5 != 0) y++;
            if(y-grades[i] < 3) grades[i] = y;
        }
    }
    return grades;
}

int main() {
    std::vector<int> grades;
    int n; std::cin >> n;
    for(int i=0;i<n;i++) {
        int temp;
        std::cin >> temp;
        grades.push_back(temp);
    }
    for(int x:grades) std::cout << x << " ";
    std::cout << std::endl;
    std::vector<int> rounded_off_grades = round_off(grades);
    for(int x : rounded_off_grades) std::cout << x << " ";
    std::cout << std::endl;
}