#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int h = grid.size(), w = grid.front().size(), counter = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == '1') {
                    ++counter;
                    bfsFrom(grid, i, j);
                }
            }
        }

        return counter;
    }

    void bfsFrom(vector<vector<char>>& grid, int sx, int sy) {
        struct point { int x; int y; };
        int h = grid.size(), w = grid.front().size();
        stack<point> frontier;
        frontier.push({ sx, sy });
        
        while (!frontier.empty()) {
            /* first vist current node */
            point cp = frontier.top();
            int x = cp.x, y = cp.y;

            /* mark as visited */
            frontier.pop();
            grid[x][y] = '0';
            
            /* up */
            if (x - 1 >= 0 && grid[x - 1][y] == '1') { frontier.push({ x - 1, y }); }
            /* down */
            if (x + 1 < h  && grid[x + 1][y] == '1') { frontier.push({ x + 1, y }); }
            /* left */
            if (y - 1 >= 0 && grid[x][y - 1] == '1') { frontier.push({ x, y - 1});  }
            /* right */
            if (y + 1 < w  && grid[x][y + 1] == '1') { frontier.push({ x, y + 1});  }
        }
    }
};

