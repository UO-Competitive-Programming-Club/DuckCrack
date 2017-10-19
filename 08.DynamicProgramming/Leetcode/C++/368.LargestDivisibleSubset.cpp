vector<int> largestDivisibleSubset(vector<int>& nums) {
    int nlen = nums.size(), max_count = 1, max_count_element_end_idx = 0;
    if (nlen == 0) return {};
    sort(nums.begin(), nums.end());
    vector<pair<int, int>> memo(nlen, pair<int,int>(1, -1));
    
    for (int i = 1; i < nlen; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0) {
                
                int old_count = memo[i].first, 
                    potential_new_count = memo[j].first + 1;
                
                // update the current max
                if (old_count < potential_new_count) {
                    memo[i].first  = potential_new_count;
                    memo[i].second = j;
                }
                
                // update the global max
                if (memo[i].first > max_count) {
                    max_count = memo[i].first;
                    max_count_element_end_idx = i;
                }
            }
        }        
    }

    vector<int> result = { nums[max_count_element_end_idx] };
    int iter = memo[max_count_element_end_idx].second;
    
    while (iter != -1) {
        result.push_back(nums[iter]);
        iter = memo[iter].second;
    }
    
    return result;
}
