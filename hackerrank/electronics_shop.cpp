#include <iostream>
#include <vector>

int max_expenditure(int b, std::vector<int> keyboards, std::vector<int> drives) {
    int max_expense = -1;
    for(int i=0;i<keyboards.size();i++) {
        for(int j=0;j<drives.size();j++) {
            int sum = keyboards[i]+drives[j];
            if(sum > max_expense && sum <= b) max_expense = sum;
        }
    }
    return max_expense;
}

int main() {
    int b, n, m;
    std::cin >> b >> n >> m;
    std::vector<int> keyboards;
    std::vector<int> drives;
    for(int i=0;i<n;i++) {
        int temp; std::cin >> temp;
        keyboards.push_back(temp);
    }
    for(int i=0;i<m;i++) {
        int temp; std::cin >> temp;
        drives.push_back(temp);
    }
    std::cout << max_expenditure(b,keyboards,drives) << std::endl;
}