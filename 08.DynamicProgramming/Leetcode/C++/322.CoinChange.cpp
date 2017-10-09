int coinChange(vector<int>& coins, int amount) {        
    vector<int> memo(amount + 1, INT_MAX);
    memo[0] = 0;
    
    for (int i = 1; i <= amount; ++i) {
        for (int coin: coins) {
            if (i >= coin) {
                
                if (memo[i - coin] == INT_MAX) {
                    continue;  
                } 
                
                memo[i] = min(memo[i], memo[i - coin] + 1);
            }
        }
    }
    
    return memo[amount] == INT_MAX ? -1 : memo[amount];
}
