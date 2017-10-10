int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    
    vector<vector<int>> memo(len1 + 1, vector<int>(len2 + 1));
    
    for (int i = 0; i <= len1; ++i) {
        memo[i][0] = i;
    }
    
    for (int j = 0; j <= len2; ++j) {
        memo[0][j] = j;
    }
    
    
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1];
            } else {
                vector<int> temp = {
                    memo[i - 1][j],
                    memo[i][j - 1],
                    memo[i - 1][j - 1]
                };
            
                memo[i][j] = *min_element(begin(temp), end(temp)) + 1;
            }
        }
    }
    
    
    
    return memo[len1][len2];
}
