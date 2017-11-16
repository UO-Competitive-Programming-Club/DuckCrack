#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int slen = strs.size();
        vector<int> ones(slen, 0), zeros(slen, 0);
        vector<vector<vector<int>>> memo(slen + 1, 
                                         vector<vector<int>>(m + 1, 
                                                             vector<int>(n + 1, 0)));
        
        /* populate the ones and zeros count */
        for (int i = 0; i < slen; ++i) {
            string & s = strs[i];
            int strlen = s.size();
            for (int j = 0; j < strlen; ++j) {
                if (s[j] == '1') ++ones[i];
                if (s[j] == '0') ++zeros[i];
            }            
        }        
        
        for (int k = 1; k <= slen; ++k) {
            for (int n_zeros = 0; n_zeros <= m; ++n_zeros) {
                for (int n_ones = 0; n_ones <= n; ++n_ones) {
                    
                    int ones_left = n_ones - ones[k - 1], 
                        zeros_left = n_zeros - zeros[k - 1];

                    if (ones_left >= 0 && zeros_left >= 0) {
                        memo[k][n_zeros][n_ones] = max(memo[k - 1][n_zeros][n_ones], memo[k - 1][zeros_left][ones_left] + 1);
                    } else {
                        memo[k][n_zeros][n_ones] = memo[k - 1][n_zeros][n_ones];                        
                    }
                }
            }
        }
        
        return memo[slen][m][n];
    }
};
