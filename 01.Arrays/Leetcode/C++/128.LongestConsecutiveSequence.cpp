#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int longestConsecutive(const vector<int>& nums) {
    std::unordered_map<int, int> map;
    int alen = nums.size();
    int result = 0;
    for (int i = 0; i < alen; i++) {
        if (map.find(nums[i]) == map.end()) {
            int cur   = nums[i],
                left  = (map.find(cur - 1) != map.end())  ? map[cur - 1] : 0,
                right = (map.find(cur + 1) != map.end()) ? map[cur + 1] : 0;

            int sum = left + right + 1;
            map[cur] = sum;
            result = max(sum, result);

            map[cur - left] = sum;
            map[cur + right] = sum;
        }
    }

    return result;
}
