#include <iostream>
#include <vector>

void num_apples_and_oranges_on_house(int s, int t, int a, int b, std::vector<int> apples, std::vector<int> oranges) {
    int num_apples_on_house = 0;
    int num_oranges_on_house = 0;
    for(int x:apples) {
        x += a;
        if(x>=s && x<=t) num_apples_on_house++;
    }
    for(int x:oranges) {
        x += b;
        if(x>=s && x<=t) num_oranges_on_house++;
    }
    std::cout << num_apples_on_house << std::endl;
    std::cout << num_oranges_on_house << std::endl;
}

int main() {
    int s, t; //starting and ending point of house
    std::cin >> s >> t;

    int a,b; // position of apple tree and orange tree
    std::cin >> a >> b;
    
    int m, n; // number of apples and oranges thrown
    std::cin >> m >> n;
    
    std::vector<int> apples;
    for(int i=0;i<m;i++){
        int temp;
        std::cin >> temp;
        apples.push_back(temp);
    }
    
    std::vector<int> oranges;
    for(int i=0;i<n;i++){
        int temp;
        std::cin >> temp;
        oranges.push_back(temp);
    }
    num_apples_and_oranges_on_house(s,t,a,b,apples,oranges);
}