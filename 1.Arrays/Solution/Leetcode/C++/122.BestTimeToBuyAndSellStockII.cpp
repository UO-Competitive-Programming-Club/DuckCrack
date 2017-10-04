#include "../Debug.h"
using namespace std; 

/* hint, draw the stock chart and find out what's important */  
int MaxProfit(const vector<int>& prices) {
    int total_profit = 0, plen = prices.size();

    for (int i = 0; i < plen - 1; i++) {
        total_profit += max(prices[i + 1] - prices[i], 0);
    }

    return total_profit;
}

