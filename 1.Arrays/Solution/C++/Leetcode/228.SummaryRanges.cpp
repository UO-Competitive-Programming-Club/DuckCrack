#include "../Debug.h"

using namespace std;

vector<string> summaryRanges(const vector<int>& nums) {
    /* corner cases */
    if (nums.empty()){ return {}; }
    if (nums.size() == 1){ return { to_string(nums.front()) }; }

    vector<string> result;

    int nlen = nums.size(); 

    /* we pretend there is an extra element that is not in range with the last element */
    for (int begin = 0, end = 1; end < nlen + 1; ++end) {
        /* then we caculate the difference based on if we are at the last virual element or no */
        int difference = (end < nlen) ? abs(nums[end] - nums[end - 1]) : INT_MAX;

        if (difference > 1 || end == nlen) {
            (end - begin == 1) ? 
                result.emplace_back(to_string(nums[begin])) :
                result.emplace_back(to_string(nums[begin]) + "->" + to_string(nums[end - 1]));

            begin = end;
        }         
    }

    return result;
}


int main() {
    vector<int> nums = {-2147483648,-2147483647,2147483647};

    print_vector(nums);
    print_vector(summaryRanges(nums));

    return 0;
}

/* 1 2 3 5 7 8 */

