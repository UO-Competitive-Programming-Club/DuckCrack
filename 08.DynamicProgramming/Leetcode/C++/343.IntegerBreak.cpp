class Solution {
public:
    int integerBreak(int n) {
        vector<int> memo(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            for (int j = i - 1; j > 0; --j) {                
                memo[i] = max(memo[i], 
                              max(memo[j], j) * max(memo[i - j], i - j));
            }
        }
        
        return memo[n];
    }
};
