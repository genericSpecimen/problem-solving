#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
int migratory_birds(std::vector<int> sightings) {
    // return the type of bird with most sightings
    std::sort(sightings.begin(), sightings.end());
    std::map<int, int> num_sightings;
    for(std::vector<int>::iterator itr = sightings.begin(); itr != sightings.end(); itr++) {
        num_sightings[*itr]++;
    }

    int type;
    int max_sightings = INT_MIN;
    for(std::map<int, int>::iterator itr = num_sightings.begin(); itr != num_sightings.end();itr++) {
        if(itr->second > max_sightings) {
            max_sightings = itr->second;
            type = itr->first; 
        }
    }
    return type;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sightings;
    int temp;
    for(int i=0;i<n;i++) {
        std::cin >> temp;
        sightings.push_back(temp);
    }

    std::cout << migratory_birds(sightings) << std::endl;
}