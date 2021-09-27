#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Greater {
    bool operator()(const string &s1, const string &s2) {
        return s1.size() > s2.size();
    }
};

vector<string> topK(int k) {
    string next_string;
    
    priority_queue< string,
                    vector<string>,
                    Greater> min_pq;
    
    while (std::cin >> next_string) {
        if (min_pq.size() < k) {
            min_pq.push(next_string);
            cout << "=> pushed: " << next_string << endl;
        } else {
            if (next_string.size() > min_pq.top().size()) {
                cout << "=> popped: " << min_pq.top() << ", pushed: " << next_string << endl;
                min_pq.pop();
                min_pq.push(next_string);
            }
        }
    }
    
    vector<string> result;
    while (!min_pq.empty()) {
        result.push_back(min_pq.top());
        min_pq.pop();
    }
    return result;
}

int main() {
    vector<string> result = topK(5);
    
    for (auto s : result) cout << s << endl;
    
}
