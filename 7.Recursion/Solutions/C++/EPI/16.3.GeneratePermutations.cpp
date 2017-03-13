#include "../Debug.h"

using namespace std;

void PermutationHelper(vector<int>& nums, int index) {
    if (index == nums.size() - 1) {
        PrintVector(nums);
    } 
    
    else {
        for (size_t i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            PermutationHelper(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
}

void Permutation(vector<int>& nums) {
    PermutationHelper(nums, 0);
}
