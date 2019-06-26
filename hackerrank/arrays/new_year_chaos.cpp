#include <iostream>
#include <vector>
#include <climits>

void minimum_bribes(std::vector<int>& queue) {
    unsigned int min_bribes = 0;
    for(int i=queue.size()-1;i>=0;i--) {
        if((queue[i] - (i+1)) > 2) {
            // person has bribed more than two persons
            std::cout << "Too chaotic" << std::endl;
            return;
        } else {
            for(int j=std::max(0, queue[i] - 2); j<i; j++) {
                if(queue[j] > queue[i]) min_bribes++;
            }
        }
    }
    std::cout << min_bribes << std::endl;
}

int main() {
    unsigned int t; std::cin >> t;
    unsigned int n;
    int temp;
    while(t--) {
        std::vector<int> queue;
        std::cin >> n;
        while(n--) {
            std::cin >> temp;
            queue.push_back(temp);
        }
        minimum_bribes(queue);
    }
}