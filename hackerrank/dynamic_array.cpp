#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> seq_list;
    int last_answer = 0;

    int n,q;
    std::cin >> n >> q;
    seq_list.resize(n);
    
    int type, x, y;
    while(q--) {
        std::cin >> type >> x >> y;
        switch(type) {
            case 1:  break;
            case 2:  break;
        }
        if(type == 1) {
            int index = ((x ^ last_answer) % n);
            seq_list[index].push_back(y);
        } else if(type == 2) {
            int index = ((x ^ last_answer) % n);
            last_answer = seq_list[index][y % seq_list[index].size()];
            std::cout << last_answer << std::endl;
        }
    }
}