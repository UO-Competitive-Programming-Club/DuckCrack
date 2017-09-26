#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int res = nums.front(),
        cur = 0;

    int alen = nums.size();
    for (int i = 1; i < alen; i++) {
        int n = nums[i];
        cur = (n + cur) < 0 ? 0: n + cur;
        res = max(res, cur);
    }
    return res;
}

