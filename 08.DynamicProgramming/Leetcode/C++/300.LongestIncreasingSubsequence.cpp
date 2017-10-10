int lengthOfLIS(vector<int>& nums) {
    int nlen = nums.size();
    if (nlen == 0) return 0;
    vector<int> memo(nlen, 1);
    int result = 1; 

    /* i is the end of longest increasing subsequence */
    for (int i = 1; i < nlen; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                memo[i] = max(memo[i], memo[j] + 1);
                result = max(result, memo[i]);
            }
        }
    }
    
    return result;
}
