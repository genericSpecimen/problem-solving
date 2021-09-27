#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Building {
    int id;
    double height;
};

vector<Building> buildingsWithSunsetView(const vector<Building> &buildings) {
    if (buildings.empty()) return {};
    
    stack<int> st;
    for (int i=buildings.size()-1; i>=0; i--) {
        while (!st.empty() && buildings[i].height >= buildings[st.top()].height) st.pop();
        st.push(i);
    }
    
    vector<Building> result;
    while (!st.empty()) {
        result.push_back(buildings[st.top()]);
        st.pop();
    }
    
    return result;
}

int main() {
    // W to E order
    vector<Building> buildings = {
        {0, 180},
        {1, 168},
        {2, 190},
        {3, 188}
    };
    
    vector<Building> buildings_with_sunset_view = buildingsWithSunsetView(buildings);
    
    for (auto b : buildings_with_sunset_view) {
        cout << "{" << b.id << ", " << b.height << "}" << endl; 
    }
}
