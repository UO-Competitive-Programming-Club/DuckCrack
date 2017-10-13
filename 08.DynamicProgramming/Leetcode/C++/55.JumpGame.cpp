#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

bool canJump(vector<int>& nums) {
    int nlen = nums.size(),
        maxJump = 0;

    for (int i = 0; i < nlen; ++i) {
        if (maxJump < i) return false;

        maxJump = max(maxJump, nums[i] + i);

        if (maxJump >= nlen - 1) return true;
    }

    return false;
}
