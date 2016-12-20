#include "../Debug.h"

using namespace std;

int MaxProfit(const vector<int>& prices) {
    /* M is the maxium profile can be made each day only buying and selling once */ 
    if (prices.empty()) {
        return 0;
    }

    vector<int> M(prices.size(), 0);
    int min_price = prices.front(), max_price = prices.back(), single_max_profit = 0, double_max_profit = 0;

    /* forward iteration, keep track of the the max profit if sell on each day */
    for (size_t i = 0; i < prices.size(); ++i) {
        single_max_profit = max(single_max_profit, prices[i] - min_price);
        min_price = min(min_price, prices[i]);
        M[i] = single_max_profit;
    }


    /* backward iteration, keep track of the max profile assuming we buy one that day */
    for (size_t i = prices.size() - 1; i > 0; --i) {
        int profile_buy_today = max_price - prices[i];
        double_max_profit = max(double_max_profit, M[i - 1] + profile_buy_today); 
        max_price = max(max_price, prices[i]);
    }

    /* handling edge cases where the number of entries of input is less than 4 */
    return max(double_max_profit, M.back());
}

int main() {

    vector<int> prices = { 3, 2, 6, 5, 0, 3 } ;
    std::cout << MaxProfit(prices) << std::endl;

    return 0;
}
