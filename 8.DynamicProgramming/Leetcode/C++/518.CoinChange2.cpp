#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int change(int amount, vector<int>& coins) {
    
    int num_coins = coins.size();
    vector<vector<int> > memo(num_coins + 1, vector<int>(amount + 1, 0));
    std::sort(coins.begin(), coins.end());
    
    memo[0][0] = 1;

    /* begin from the second row */
    for (int i = 1; i <= num_coins; i++) {
        memo[i][0] = 1;
        for (int j = 1; j <= amount; j++) {                
            int previous_max_without_current_coin = memo[i-1][j];
            if (j < coins[i - 1]) {
                memo[i][j] = previous_max_without_current_coin;
            } else {
                memo[i][j] = memo[i][ j - coins[i - 1] ] + previous_max_without_current_coin;
            }           
        }
    }
            
    return memo[num_coins][amount];
}
