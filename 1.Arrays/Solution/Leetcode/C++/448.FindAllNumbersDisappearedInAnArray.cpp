#include "../Debug.h"

using namespace std;

/* using each entry as indices */ 

vector<int> FindDisappearedNumbers(vector<int>& nums) {
    int nlen = nums.size();
    vector<int> result;
    for (int i = 0; i < nlen; ++i) {
        if (nums[abs(nums[i]) - 1] > 0) { 
            nums[abs(nums[i]) - 1] *= -1;
        }
    }
    
    for (int i = 0; i < nlen; ++i) {
        if (nums[i] > 0) { 
            result.push_back(i + 1);
        }
    }
    
    return result;
}
