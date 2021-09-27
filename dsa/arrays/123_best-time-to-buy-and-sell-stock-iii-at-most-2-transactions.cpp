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

/*
int maxProfit(const std::vector<int> &prices) {
    if (prices.size() < 2) {
        return 0;
    }
    
    // maximum profit can only after be the second sell
    int max_balance_after_sell2 = 0;
    int max_balance_after_sell1 = 0; 
    
    // we want to spend as less as possible to buy the share,
    // so our balance after buying must be maximized. This is
    // equivalent to buying at the lowest possible price.
    int max_balance_after_buy2 = std::numeric_limits<int>::min();
    int max_balance_after_buy1 = std::numeric_limits<int>::min();
    
    for (int i=0; i<prices.size(); i++) {
        if (max_balance_after_buy2 + prices[i] > max_balance_after_sell2) {
            max_balance_after_sell2 = max_balance_after_buy2 + prices[i];
            
        } else if (max_balance_after_sell1 - prices[i] > max_balance_after_buy2) {
            // cheaper 2nd buy after 1st sell
            max_balance_after_buy2 = max_balance_after_sell1 - prices[i];
        }
        
        if (max_balance_after_buy1 + prices[i] > max_balance_after_sell1) {
            // more profitable to sell at this day (for first transaction)
            max_balance_after_sell1 = max_balance_after_buy1 + prices[i];
            
        } else if (0 - prices[i] > max_balance_after_buy1) {
            // cheaper to buy at ith day. 0 is our initial balance.
            max_balance_after_buy1 = 0 - prices[i];
        }
    }
    
    return max_balance_after_sell2;
}
*/

/*
// NOTE: interval tracking is buggy.
int maxProfit(const std::vector<int> &prices) {
    if (prices.size() < 2) {
        return 0;
    }
    
    // maximum profit can only after be the second sell
    int max_balance_after_sell2 = 0;
    int max_balance_after_sell1 = 0; 
    
    // we want to spend as less as possible to buy the share,
    // so our balance after buying must be maximized. This is
    // equivalent to buying at the lowest possible price.
    int max_balance_after_buy2 = std::numeric_limits<int>::min();
    int max_balance_after_buy1 = std::numeric_limits<int>::min();
    
    // stores buy and sell day indices for 2 transactions
    std::pair<int, int> curr_interval1, curr_interval2;
    std::pair<int, int> best_interval1, best_interval2;
    
    for (int i=0; i<prices.size(); i++) {
        if (max_balance_after_buy2 + prices[i] > max_balance_after_sell2) {
            max_balance_after_sell2 = max_balance_after_buy2 + prices[i];
            
            curr_interval2.second = i;
            best_interval2 = {curr_interval2.first, curr_interval2.second};
            
        } else if (max_balance_after_sell1 - prices[i] > max_balance_after_buy2) {
            // cheaper 2nd buy after 1st sell
            max_balance_after_buy2 = max_balance_after_sell1 - prices[i];
            curr_interval2.first = i;
        }
        
        if (max_balance_after_buy1 + prices[i] > max_balance_after_sell1) {
            // more profitable to sell at this day (for first transaction)
            max_balance_after_sell1 = max_balance_after_buy1 + prices[i];
            
            curr_interval1.second = i;
            best_interval1 = {curr_interval1.first, curr_interval1.second};
            
        } else if (0 - prices[i] > max_balance_after_buy1) {
            // cheaper to buy at ith day. 0 is our initial balance.
            max_balance_after_buy1 = 0 - prices[i];
            curr_interval1.first = i;
        }
        
        std::cout << "MBS2: " << max_balance_after_sell2 << ", "
                  << "MBB2: " << max_balance_after_buy2 << ", "
                  << "MBS1: " << max_balance_after_sell1 << ", "
                  << "MBB1: " << max_balance_after_buy1 << "\n";
    }
    
    return max_balance_after_sell2;
}
*/

int maxProfit(const std::vector<int> &prices) {
    if (prices.size() < 2) {
        return 0;
    }
    
    // maximum profit can only after be the second sell
    int max_balance_after_sell2 = 0;
    int max_balance_after_sell1 = 0; 
    
    int max_balance_after_buy2 = std::numeric_limits<int>::min();
    int max_balance_after_buy1 = std::numeric_limits<int>::min();
    
    for (int i=0; i<prices.size(); i++) {
        max_balance_after_sell2 = std::max(max_balance_after_sell2, max_balance_after_buy2 + prices[i]);
        max_balance_after_buy2 = std::max(max_balance_after_buy2, max_balance_after_sell1 - prices[i]);
        
        max_balance_after_sell1 = std::max(max_balance_after_sell1, max_balance_after_buy1 + prices[i]);
        max_balance_after_buy1 = std::max(max_balance_after_buy1, 0 - prices[i]);
        
        std::cout << "MBS2: " << max_balance_after_sell2 << ", "
                  << "MBB2: " << max_balance_after_buy2 << ", "
                  << "MBS1: " << max_balance_after_sell1 << ", "
                  << "MBB1: " << max_balance_after_buy1 << "\n";
    }
    
    return max_balance_after_sell2;
}

int main() {
    std::vector<std::vector<int>> test_cases = {
//         {310,315,275,295,260,270,290,230,255,250},
//         {1,4,2},
//         {2,1,4},
//         {1,2},
//         {7,1,5,3,6,4},
//         {1,2,3,4,5},
//         {7,6,4,3,1},
        {3,3,5,0,0,3,1,4}
    };
    for (auto &vec : test_cases) {
        //std::cout << "-----------------------------\n";
        std::cout << maxProfit(vec) << std::endl;
        //std::cout << "-----------------------------\n";
    }
    return 0;
}
// 
