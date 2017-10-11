#include <iostream>
#include <vector>

using namespace std;

int CutRod(vector<int> prices, int n) {
    int plen = prices.size();
    vector<int> memo(prices.size() + 1, 0);

    for (int l = 1; l <= plen; ++l) {
        memo[l] = prices[l - 1];
    }

    for (int l = 1; l <= plen; ++l) {
        for (int k = 1; k <= l; ++k) {
            memo[l] = max(memo[l], memo[k] + memo[l - k]);
        }
    }

    return memo[plen];
}

int main() {
	vector<int> arr = {1, 5, 8, 9, 10, 17, 17, 20};
	cout << CutRod(arr, arr.size()) << endl;;
	return 0;
}
