#include "../Debug.h"
using namespace std;
int MaxiumProfile(const vector<int>& prices) {
    int max_profit = 0, min_price = INT_MIN;

    for (auto & n: prices) {
        max_profit = max(max_profit, n - min_price);
        min_price = min(n, min_price);
    }

    return max_profit;
}
