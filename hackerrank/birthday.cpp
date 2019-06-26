#include <bits/stdc++.h>
int birthdayCakeCandles(std::vector<int> ar) {
    std::map<int,int> num_candles;
    for(int x:ar) num_candles[x]++;
    int max_key = INT_MIN;
    for(std::map<int,int>::iterator itr=num_candles.begin(); itr!=num_candles.end();++itr) {
        std::cout << itr->first << ": " << itr->second << std::endl;
        if(itr->first > max_key) max_key = itr->first;
    }
    std::cout << "Maximum height: " << max_key << std::endl;
    return num_candles[max_key];

}

int main() {
    std::vector<int> arr = {3,2,1,3};
    int num = birthdayCakeCandles(arr);
    std::cout << "NUM: " << num << std::endl;
}