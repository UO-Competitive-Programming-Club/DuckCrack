#include "../Debug.h"
using namespace std;

/* this problem is trival to solve with O(n) space */
int MajorityElement(const vector<int>& nums) {
    int nlen = nums.size(),
        count = 0,
        cannidate;

    for (int i = 0; i < nlen; ++i) {
        if (count == 0) {
            cannidate = nums[i];
            ++count;
        } else {
            if (cannidate == nums[i]) {
                ++count;
            } else {
                --count;
            }
        }
    }

    return 0;
}

