int longestPalindromeSubseq(string s) {
    int slen = s.size();
    vector<vector<int>> memo(slen, vector<int>(slen, 1));
    
    for (int length = 1; length <= slen; ++length) {
        for (int start = 0; start + length <= slen; ++start) {
            int end = start + length - 1;
            
            if (start == end) continue;
            
            if (s[start] == s[end]) {
                if (end - start == 1) {
                    memo[start][end] = 2;
                } else {
                    memo[start][end] = memo[start + 1][end - 1] + 2;
                }
            } else {
                if (end - start == 1) {
                    memo[start][end] = 1;
                } else {
                    memo[start][end] = max(memo[start + 1][end], memo[start][end - 1]);
                }
            }
        }
    }
    
    return memo[0][slen - 1];
}
