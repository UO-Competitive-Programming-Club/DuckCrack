class Solution {
public:
    int numTrees(int n) {
        if (n < 3) return n;
        vector<int> memo(n + 1, 1);
        
        for (int i = 2; i <= n; ++i) {
            memo[i] = 0;
            for (int j = 1; j <= i; ++j) {
                memo[i] += memo[j - 1] * memo[i - j];
            }
        }
        
        return memo[n];
    }
};
