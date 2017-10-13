#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int single_max = *max_element(nums.begin(), nums.end()),
        cur_max = 0,
        result = 0;
    
    if (single_max <= 0) {
        return single_max;
    }
    
    for (int n: nums) {
        (cur_max + n < 0) ? cur_max = 0 : cur_max += n;
        result = max(result, cur_max);
    }
    
    return result;
}
