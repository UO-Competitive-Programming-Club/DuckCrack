#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int h = matrix.size(), w = matrix.front().size();
        vector<vector<int>> memo(h, vector<int>(w, 0));

        int result = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                result = max(result, findSmallAround(i, j, matrix, memo, INT_MAX));
            }
        }
        return result;
    }


    int findSmallAround(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& memo, int pre) {
        int h = matrix.size(), w = matrix.front().size();
        if (i < 0 || j < 0 || i >= h || j >= w || matrix[i][j] >= pre) return 0;

        if (memo[i][j] > 0) return memo[i][j];

        int cur = matrix[i][j]; int temp_max = 0;
        temp_max = max(temp_max, findSmallAround(i + 1, j, matrix, memo, cur));
        temp_max = max(temp_max, findSmallAround(i - 1, j, matrix, memo, cur));
        temp_max = max(temp_max, findSmallAround(i, j - 1, matrix, memo, cur));
        temp_max = max(temp_max, findSmallAround(i, j + 1, matrix, memo, cur));
        
        memo[i][j] = temp_max + 1;
        return memo[i][j];
    }
};


