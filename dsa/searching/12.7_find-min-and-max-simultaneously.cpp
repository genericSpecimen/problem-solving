#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> findMinMax(vector<int> &nums) {
    if (nums.empty()) return {};
    if (nums.size() == 1) return {nums.front(), nums.front()};
    
    int min = nums[0], max = nums[1];
    
    if (min > max) {
        std::swap(min, max);
    }
    
    cout << min << ", " << max << endl;
    
    for (int i=2; i+1<nums.size(); i+=2) {
        int curr_min, curr_max;
        if (nums[i] <= nums[i+1]) {
            curr_min = nums[i];
            curr_max = nums[i+1];
        } else {
            curr_min = nums[i+1];
            curr_max = nums[i];
        }
        cout << curr_min << ", " << curr_max << endl;
        if (curr_min < min) min = curr_min;
        if (curr_max > max) max = curr_max;
    }
    
    if (nums.size() % 2 != 0) {
        if (nums.back() < min) min = nums.back();
        if (nums.back() > max) max = nums.back();
    }
    
    return {min, max};
}

int main() {
    vector<int> nums = {3, 3, 5, 1, 2, 4, 100};
    auto minmax = findMinMax(nums);
    cout << minmax.first << ", " << minmax.second << endl;
}
