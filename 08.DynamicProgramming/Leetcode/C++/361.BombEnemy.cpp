#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        struct point {
            int up, down, left, right;
        };
        
        int h = grid.size(), w = grid.front().size(), result = 0;
        vector<vector<point>> memo(h, vector<point>(w, { 0, 0, 0, 0 }));

        /* from top left to bottom right */
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] == 'E') {
                    memo[i][j].up   = ((i >= 1) ? memo[i - 1][j].up   : 0) + 1;
                    memo[i][j].left = ((j >= 1) ? memo[i][j - 1].left : 0) + 1; 
                } else if (grid[i][j] == '0') {
                    memo[i][j].up   = ((i >= 1) ? memo[i - 1][j].up   : 0);
                    memo[i][j].left = ((j >= 1) ? memo[i][j - 1].left : 0); 
                }
            }
        }   
        
        /* from bottom right to top left */
        for (int i = h - 1; i >= 0; --i) {
            for (int j = w - 1; j >= 0; --j) {
                if (grid[i][j] == 'E') {
                    memo[i][j].down   = ((i < h - 1) ? memo[i + 1][j].down   : 0) + 1;
                    memo[i][j].right  = ((j < w - 1) ? memo[i][j + 1].right  : 0) + 1; 
                } else if (grid[i][j] == '0') {
                    memo[i][j].down   = ((i < h - 1) ? memo[i + 1][j].down   : 0);
                    memo[i][j].right  = ((j < w - 1) ? memo[i][j + 1].right  : 0); 
                }
            }
        }   
        
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] == '0') {
                    result = max(result, memo[i][j].up + memo[i][j].down + memo[i][j].right + memo[i][j].left);
                }
            }
        }
        
        return result;
    }
};
