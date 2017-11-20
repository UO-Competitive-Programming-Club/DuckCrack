#include "../Debug.h"
using namespace std;

vector<int> CaculateStockSpan(const vector<int>& prices) {
    stack<int> S;
    vector<int> ret;
    S.emplace(0);
    ret[0] = 1;
    for (size_t i = 1; i < prices.size(); i++) {
        while (!S.empty() && S.top() <= prices[i]) {
            S.pop();
        }

        ret[i] = (S.empty()) ? (i + 1) : (i - S.top());

        S.emplace(i);
    }

    return ret;
}
