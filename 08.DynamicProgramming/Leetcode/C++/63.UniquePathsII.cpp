
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0][0] == 1) return 0;
        int h = obstacleGrid.size(), w = obstacleGrid.front().size();
        vector<vector<int>> memo(h, vector<int>(w, 0));
        
        for (int i = 0; i < h; ++i) {
            if (obstacleGrid[i][0] == 0) memo[i][0] = 1;
            else break;
        }
        
        for (int j = 0; j < w; ++j) {
            if (obstacleGrid[0][j] == 0) memo[0][j] = 1;
            else break;
        }        
        
        for (int i = 1; i < h; ++i) {
            for (int j = 1; j < w; ++j) {
                if (obstacleGrid[i][j] == 1) continue;
                memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
            }
        }
        
        return memo[h - 1][w - 1];
        
    }
};
