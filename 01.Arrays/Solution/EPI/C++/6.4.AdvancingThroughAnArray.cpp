#include "../Debug.h"

using namespace std;

/* keep track of the reachability, if it is less than the current position that means it cannot get there; */
bool CanJump(vector<int>& nums) {
    int reachability = 0, len = nums.size();
     for (int i = 0; i < len; ++i) {
         if (reachability < i) {
            return false;
         }

         reachability = max(reachability, i + nums[i]);
     }

     return (reachability >= len - 1);
}
