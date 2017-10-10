
#include <iostream>
#include <vector>
using namespace std;


int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size(), maxlen = 1, result = 0;

    vector<int> cnt(n, 1), lis(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {

                if (lis[j] + 1 > lis[i]) {
                    lis[i] = lis[j] + 1;
                    cnt[i] = cnt[j];
                } else if (lis[j] + 1 == lis[i])  {
                    cnt[i] += cnt[j];
                }
            }
        }

        maxlen = max(maxlen, lis[i]);
    }

    // find the longest increasing subsequence of the whole sequence
    // sum valid counts
    for (int i = 0; i < n; i++) {
        if (lis[i] == maxlen) {
            result += cnt[i];
        }
    }

    return result;
}
