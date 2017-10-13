#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int> >& grid) {
    int height = grid.size(), width = grid.front().size();

    vector<vector<int> > memo(height + 1, vector<int>(width + 1, INT_MAX));

    memo[0][0] = 0;

    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) {
            memo[i][j] = grid[i - 1][j - 1];
            int curMinSum = min(memo[i - 1][j], memo[i][j - 1]);
            memo[i][j] += curMinSum;
            memo[1][1] = grid[0][0];
        }
    }

    return memo[height][width];
}
