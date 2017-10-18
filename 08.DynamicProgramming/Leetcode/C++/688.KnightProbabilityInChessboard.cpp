#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double knightProbability(int N, int K, int r, int c) {
    vector<vector<vector<double> > >memo (K + 1, vector<vector<double> >(N, vector<double>(N, 0.0)));
    vector<vector<int>> dirs = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    
    if (r < 0 || r >= N || c < 0 || c >= N) {
        return 0.0;
    }
    
    if (K == 0) {
        return 1.0;
    }
    
    memo[0][r][c] = 1.0;
    double sum = 0.0;

    for (int k = 1; k <= K; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (auto dir : dirs) {
                    int x = dir[0] + i;
                    int y = dir[1] + j;
                    if (x < 0 || x >= N || y < 0 || y >= N) continue;
                    memo[k][i][j] += memo[k - 1][x][y];
                }
                

                if (k == K) {
                    sum += memo[k][i][j];
                }
            }
        }
    }

    return sum / pow(8, K);;
}
