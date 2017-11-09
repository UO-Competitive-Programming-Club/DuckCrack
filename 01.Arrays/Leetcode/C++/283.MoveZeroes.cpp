class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return;
        
        int nlen = nums.size();
        for (int r = 0, w = 0; r < nlen; ++r) {
            if (nums[r] != 0) {
                swap(nums[r], nums[w++]);
            }
        }
    }
};
