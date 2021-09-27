#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

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
 * Brute Force:
 * Try each pair of buying and selling price.
 * O(n^2) time complexity.
 * sum_i{0, n-2} (n-1-i) = (n-1)n / 2
 * 
 * TLE
 */
int maxProfitBF(const std::vector<int> &prices) {
    int max_profit = 0;
    
    int buying_price, selling_price;
    for (int i=0; i<prices.size()-1; i++) {
        buying_price = prices[i];
        for (int j=i+1; j<prices.size(); j++) {
            selling_price = prices[j];
            max_profit = std::max(max_profit, selling_price-buying_price);
        }
    }
    
    return max_profit;
}

/*
 * Divide and Conquer: O(n log n)
 * T(n) = 2T(n/2) + O(n)
 * O(n) combine step
 */

int maxProfitDnC(const std::vector<int> &prices) {
    if (prices.size() < 2) {
        return 0;
    } else if (prices.size() == 2) {
        int profit = prices[1]-prices[0];
        return (profit > 0 ? profit : 0);
    }
    
    auto mid = prices.begin() + prices.size()/2;
    
    // [first, last)
    int max_profit_left = maxProfitDnC(std::vector<int>(prices.begin(), mid+1));
    int max_profit_right = maxProfitDnC(std::vector<int>(mid, prices.end()));
    
    // Find the smallest / largest element in the range [first, last)
    int min_buy_left = *std::min_element(prices.begin(), mid+1);
    int max_sell_right = *std::max_element(mid, prices.end());
    
    int max_profit_across = max_sell_right - min_buy_left;
    if (max_profit_across < 0) {
        max_profit_across = 0;
    }
    
    int max_profit = std::max({
        max_profit_left,
        max_profit_right,
        max_profit_across
    });
    
    return max_profit;
}

/*
 * O(n) time complexity and O(1) space complexity.
 * IDEA: max profit that can be made on day i = price[i] - min(all buying prices on day 0..i-1)
 */
/*
int maxProfit(const std::vector<int> &prices) {
    if (prices.size() < 2) {
        return 0;
    }
    
    int min_buying_price = prices[0];
    int max_profit = 0;
    
    for (int i=1; i<prices.size(); i++) {
        if (prices[i] < min_buying_price) {
            // buy at this lower price
            min_buying_price = prices[i];
        } else {
            // and see if we can make some more profit
            max_profit = std::max(max_profit, prices[i]-min_buying_price);
        }
    }
    
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
    
    for (int i=0; i<prices.size(); i++) {
        if (max_balance_after_buy + prices[i] > max_balance_after_sell) {
            max_balance_after_sell = max_balance_after_buy + prices[i];
            
            curr_interval.second = i;
            best_interval = {curr_interval.first, curr_interval.second};
            
        } else if (0 - prices[i] > max_balance_after_buy) {
            // cheaper to buy at ith day. 0 is our initial balance.
            max_balance_after_buy = 0 - prices[i];
            curr_interval.first = i;
        }
    }
    
    std::cout << "Interval: [" << best_interval.first << "," << best_interval.second << "]\n";
    return max_balance_after_sell;
}

int main() {
    std::vector<std::vector<int>> test_cases = {
        {310,315,275,295,260,270,290,230,255,250},
        {1,4,2},
        {2,1,4},
        {1,2},
        {7,1,5,3,6,4}
    };
    for (auto &vec : test_cases) {
        //std::cout << maxProfitBF(vec) << std::endl;
        //std::cout << maxProfitDnC(vec) << std::endl;
        std::cout << maxProfit(vec) << std::endl;
    }
    return 0;
}
