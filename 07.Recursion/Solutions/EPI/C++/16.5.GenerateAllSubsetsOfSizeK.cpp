#include "../Debug.h"
using namespace std;


void SubsetHelper(vector<int>& result, int depth, int digit, int k, int n) {
    if (depth == k) {
        PrintVector(result);
    }
    else {
        int cur_level_max = n - k + depth + 1;
        for (int i = digit + 1; i <= cur_level_max; i++) {
            result.emplace_back(i);
            SubsetHelper(result, depth + 1, i, k, n);
            result.pop_back();
        }
    }
}

void Subset(int k, int n) {
    if (k > 0 && k <= n) {
        vector<int> result;
        SubsetHelper(result, 0, 0, k, n);
    }
}

int main(void) {
    Subset(4, 5);
    return 0;
}
