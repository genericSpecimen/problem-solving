#include <iostream>
#include <vector>

int main() {
    int n, q; std::cin >> n >> q;
    std::vector<std::vector<int>> parent;
    for(int i=0;i<n;i++) {
        int size;
        std::cin >> size;
        std::vector<int> child;
        for(int i=0;i<size;i++) {
            int temp;
            std::cin >> temp;
            child.push_back(temp);
        }
        parent.push_back(child);
    }

    int a,b;
    for(int i=0;i<q;i++) {
        std::cin >> a >> b;
        std::cout << parent[a][b] << std::endl;
    }
}