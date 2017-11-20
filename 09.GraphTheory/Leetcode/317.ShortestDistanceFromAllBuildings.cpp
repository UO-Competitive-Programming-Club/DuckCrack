#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty()) return -1; 
        const int h = grid.size(), w = grid.front().size();
        vector<vector<int> > distance(h, vector<int>(w, 0)), reach(h, vector<int>(w, 0));
        int building = 0, res = INT_MAX;

        for (int i = 0; i < h; i++) 
            for (int j = 0; j < w; j++) {
            if (grid[i][j] == 1) {
                ++building;
                bfs(grid, distance, reach, i, j);
            }
        }
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (0 == grid[i][j] && reach[i][j] == building) {
                    res = min(res, distance[i][j]);
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& distance, vector<vector<int>>& reach, int sx, int sy)  {
        struct Node { int x, y, depth; };
        const int h = grid.size(), w = grid.front().size();
        vector<vector<bool>> visited(h, vector<bool>(w, false)); visited[sx][sy] = true;
        queue<Node> frontier; frontier.push({sx, sy, 0});
        array<array<int, 2>, 4> directions { {{1, 0}, {0, 1}, {-1, 0}, {0, -1}} };

        while (!frontier.empty()) {
            Node cn = frontier.front(); frontier.pop();
            reach[cn.x][cn.y]++;
            if (grid[cn.x][cn.y] == 0) distance[cn.x][cn.y] += cn.depth;
            for (auto& dir: directions) {
                int nx = cn.x + dir.front(), ny = cn.y + dir.back();
                if (0 <= nx && nx < h && 0 <= ny && ny < w && grid[nx][ny] == 0 && !visited[nx][ny]) {
                    frontier.push({nx, ny, cn.depth + 1});
                    visited[nx][ny] = true;
                }
            }
        }
    }
};
