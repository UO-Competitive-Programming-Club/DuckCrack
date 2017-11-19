#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

class Solution {
public:
    struct Status { bool pacific, atlantic; };
    struct State { int x, y; };
    typedef enum { PACIFIC, ATLANTIC } Ocean;

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        if (matrix.empty()) return result;
        
        int h = matrix.size(), w = matrix.front().size();
        vector<vector<Status>> memo(h, vector<Status>(w, {false, false}));
        for (int i = 0; i < h; ++i) {
            memo[i][0].pacific = true;
            memo[i][w - 1].atlantic = true;
            BFS(matrix, memo, {i, 0}, PACIFIC);
            BFS(matrix, memo, {i, w - 1}, ATLANTIC);
        }

        for (int j = 0; j < w; ++j) {
            memo[0][j].pacific = true;
            memo[h - 1][j].atlantic = true;
            BFS(matrix, memo, {0, j}, PACIFIC);
            BFS(matrix, memo, {h - 1, j}, ATLANTIC);
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (memo[i][j].pacific && memo[i][j].atlantic) result.push_back({i, j});
            }
        }

        return result;
    }

    
    void BFS(vector<vector<int>>& matrix, vector<vector<Status>>& memo, State state, Ocean ocean) {
        int h = memo.size(), w = memo.front().size();
        queue<State> frontier; frontier.push(state);
        array<array<int, 2>, 4> directions = { {{0, 1}, {1, 0}, {-1,  0}, {0, -1}} };

        while (!frontier.empty()) {
            State cs = frontier.front(); frontier.pop();
            for (auto& dir: directions) {
                int nx = cs.x + dir.front(), ny = cs.y + dir.back();
                if (0 <= nx && nx < h && 0 <= ny && ny < w && matrix[cs.x][cs.y] <= matrix[nx][ny]) {
                    if (ocean == PACIFIC && !memo[nx][ny].pacific) {
                        memo[nx][ny].pacific = true;
                        frontier.push({nx, ny});
                    }
                    if (ocean == ATLANTIC && !memo[nx][ny].atlantic) {
                        memo[nx][ny].atlantic = true;
                        frontier.push({nx, ny});
                    }
                }
            }
        }
    }
};
