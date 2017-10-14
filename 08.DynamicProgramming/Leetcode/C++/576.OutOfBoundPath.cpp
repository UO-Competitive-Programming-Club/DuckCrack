int findPaths(int m, int n, int N, int i, int j) {
    
    vector<vector<vector<int> > > dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
    
    for (int k = 1; k <= N; ++k) {
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                long long v1 = (x == 0) ? 1 : dp[k - 1][x - 1][y];
                long long v2 = (x == m - 1) ? 1 : dp[k - 1][x + 1][y];
                long long v3 = (y == 0) ? 1 : dp[k - 1][x][y - 1];
                long long v4 = (y == n - 1) ? 1 : dp[k - 1][x][y + 1];
                dp[k][x][y] = (v1 + v2 + v3 + v4) % 1000000007;
            }
        }
    } 
    return dp[N][i][j];
}
