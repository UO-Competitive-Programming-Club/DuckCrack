class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int nlen = nums.size();
        vector<int> pos(nlen, 1), neg(nlen, 1);
        
        for (int i = 0; i < nlen; ++i) {
            for (int j = i; j >= 0; --j) {
                if (nums[i] - nums[j] > 0) {
                    pos[i] = max(pos[i], neg[j] + 1);
                }
                
                if (nums[i] - nums[j] < 0) {
                    neg[i] = max(neg[i], pos[j] + 1);
                }
            }
        }
        
        return max(pos[nlen - 1], neg[nlen - 1]);
    }
};
