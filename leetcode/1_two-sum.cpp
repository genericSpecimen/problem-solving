#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
// brute force
/*
void twoSum(std::vector<int> &nums, int target) {
	for(int i=0;i<nums.size();i++) {
		for(int j=i+1;j<nums.size();j++) {
			if((i != j) && nums[i]+nums[j] == target) {
				std::cout << "[" << i << ", " << j << "]\n";
			}
		}
	}
}
*/

// sort the array first to remove duplicates
/*
void twoSum(std::vector<int> &nums, int target) {
	std::sort(nums.begin(), nums.end());
	for(int i=0;i<nums.size();i++) {
		for(int j=i+1; j<nums.size();j++) {
			if(nums[i] + nums[j] == target) {
				std::cout << "[" << i << ", " << j << "]\n";
			}
		}
	}
}
*/

// maintain two pointers, one at the start and one at the end
/*
void twoSum(std::vector<int> &nums, int target) {
	std::sort(nums.begin(), nums.end());
	int i = 0, j = nums.size()-1, sum;
	while(i < j) {
		sum = nums[i] + nums[j];
		if(sum == target) {
			std::cout << "[" << i << ", " << j << "]\n";
			// assuming there are no duplicate elements in the array,
			// we increment i and decrement j
			i++; j--;
		} else if(sum > target) {
			// since sum is greater than target, we must reduce the second number
			// so that sum reduces
			j--;
		} else {
			// since sum is less than target, we must increase the first number
			// so that sum increases
			i++;
		}
	}
}
*/

// map - based implementation: preserves indices as well
std::vector<int> twoSum(std::vector<int> &nums, int target) {
	std::vector<int> indices(2, -1);
	std::multimap<int, int> m;
	for(int i=0;i<nums.size();i++) {
		m.insert({nums[i], i});
	}
	std::multimap<int, int>::iterator it;
	int complement;
	for(it = m.begin(); it != m.end(); it++) {
		std::cout << "m[" << it->first << "] = " << it->second << std::endl;
		complement = target - (it->first);
		std::multimap<int, int>::iterator itc = m.find(complement);
		if(itc != m.end() && itc != it) {
			indices[0] = it->second;
			indices[1] = itc->second;
			return indices;
		}
	}
	return indices;
}
int main() {
	//std::vector<int> arr = {1,2,3,4,5,6,7,8,9};
	std::vector<int> arr = {3,3};
	int target = 6;
	std::vector<int> indices = twoSum(arr, target);
	std::cout << "[" << indices[0] << ", " << indices[1] << "]" << std::endl;
}
