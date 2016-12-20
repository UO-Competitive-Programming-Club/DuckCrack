#include "../Debug.h"
using namespace std;

/* keep track of the minimal prices have seen iterate forward */
int MaxiumProfileForwardIteration(const vector<int>& prices) {
    int max_profit = 0, min_price = INT_MAX;

    for (auto & n: prices) {
        max_profit = max(max_profit, n - min_price);
        min_price = min(n, min_price);
    }

    return max_profit;
}

/* keep track of the maxium prices have seen iterate backward */
int MaxiumProfileBackwardIteration(const vector<int>& prices) {
    int max_profit = 0, max_price = INT_MIN;

    for (auto & n: prices) {
        max_profit = max(max_profit, max_price - n);
        max_price = max(n, max_price);
    }

    return max_profit;
}
