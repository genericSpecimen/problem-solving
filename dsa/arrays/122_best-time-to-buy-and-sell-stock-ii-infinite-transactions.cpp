#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

template <class T>
std::ostream& operator<< (std::ostream& os, const std::pair<T, T> p) {
    os << "[" << p.first << "," << p.second << "]";
    return os;
}

template <class T>
std::ostream& operator<< (std::ostream& os, const std::vector<T> v) {
    os << "[";
    for (auto elem : v) {
        os << elem << ",";
    }
    os << "]";
    return os;
}

// Peaks and valleys approach
/*
int maxProfit(const std::vector<int> &prices) {
    // max profit = sum of the differences of all valley-peak pairs
    
    int max_profit = 0;
    
    std::vector<std::pair<int, int>> best_intervals;
    std::pair<int, int> curr_interval;
    
    int i=0;
    while (i < prices.size()-1) {
        // find a valley
        while (i < prices.size()-1 && prices[i] >= prices[i+1]) {
            i++;
        }
        
        // at this point, prices[i] < prices[i+1]
        int valley = prices[i];
        curr_interval.first = i;
        
        // find a peak
        while (i < prices.size()-1 && prices[i] <= prices[i+1]) {
            i++;
        }
        
        // at this point, prices[i] > prices[i+1]
        int peak = prices[i];
        curr_interval.second = i;
        
        
        if (peak - valley > 0) {
            best_intervals.push_back(curr_interval);
            max_profit += (peak-valley);
        }
        
    }
    
    std::cout << best_intervals << std::endl;
    return max_profit;
}
*/

int maxProfit(const std::vector<int> &prices) {
    if (prices.size() < 2) {
        return 0;
    }
    
    // maximum profit can only after be sell
    int max_balance_after_sell = 0; 
    
    // we want to spend as less as possible to buy the share,
    // so our balance after buying must be maximized. This is
    // equivalent to buying at the lowest possible price.
    int max_balance_after_buy = std::numeric_limits<int>::min();
    
    // stores buy and sell day indices
    std::pair<int, int> curr_interval;
    std::pair<int, int> best_interval;
    std::vector<std::pair<int, int>> best_intervals;
    
    for (int i=0; i<prices.size(); i++) {
        if (max_balance_after_buy + prices[i] > max_balance_after_sell) {
            max_balance_after_sell = max_balance_after_buy + prices[i];
            
            curr_interval.second = i;
            
            if (!best_intervals.empty() && best_intervals.back().first == curr_interval.first) {
                best_intervals.back().second = curr_interval.second;
            } else {
                best_intervals.push_back({curr_interval.first, curr_interval.second});
            }
        } else if (max_balance_after_sell - prices[i] > max_balance_after_buy) {
            // cheaper to buy at ith day. balance is our current balance.
            max_balance_after_buy = max_balance_after_sell - prices[i];
            curr_interval.first = i;
        }
    }
    std::cout << best_intervals << std::endl;
    return max_balance_after_sell;
}


int main() {
    std::vector<std::vector<int>> test_cases = {
        {310,315,275,295,260,270,290,230,255,250},
        //{1,4,2},
        //{2,1,4},
        //{1,2},
        {7,1,5,3,6,4},
        {1,2,3,4,5},
        {7,6,4,3,1}
    };
    for (auto &vec : test_cases) {
        std::cout << "-----------------------------\n";
        std::cout << maxProfit(vec) << std::endl;
        std::cout << "-----------------------------\n";
    }
    return 0;
}
