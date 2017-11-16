#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        if (boxes.empty()) return 0;

        int blen = boxes.size();
        vector<vector<vector<int>>> memo(blen, 
                                     vector<vector<int>>(blen, 
                                                         vector<int>(blen, 0)));

        /* memo[i][j][k] means that from boxes[i:j] and k boxes of the same color as i attached to the left */

        /* base case when i = j */
        for (int i = 0; i < blen; ++i) {
            for (int k = 0; k < blen; ++k) {
                memo[i][i][k] = (k + 1) * (k + 1);
            }
        }

        for (int l = 1; l <= blen; ++l) {
            for (int begin = 0; begin <= blen - l; ++begin) {
                int end = begin + l - 1;

                for (int k = 0; k <= begin; ++k) {
                    memo[begin][end][k] = (k + 1) * (k + 1) + memo[begin + 1][end][0];

                    for (int m = begin + 1; m <= end; ++m) {
                        if (boxes[m] == boxes[begin]) {
                            memo[begin][end][k] = max(memo[begin][end][k], 
                                                      memo[begin + 1][m - 1][0] + memo[m][end][k + 1]);
                        }
                    }
                }
            }
        }
        
        return memo[0][blen - 1][0];
    }
};
