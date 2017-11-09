#include "../Debug.h"
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> val_idx_map;
    vector<int> result = {-1, -1};
    int nlen = nums.size();

    for (int i = 0; i < nlen; i++) { val_idx_map[nums[i]] = i; }

    for (int i = 0; i < nlen; i++) {
        if (val_idx_map.find(target - nums[i]) != val_idx_map.end() &&
            i != val_idx_map[target - nums[i]]) {
            result[0] = i;
            result[1] = val_idx_map[target - nums[i]];
            break;
        }
    }
    
    return result;
}

