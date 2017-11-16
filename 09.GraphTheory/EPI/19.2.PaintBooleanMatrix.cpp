#include <iostream>
#include <vector>

using namespace std;

struct Point { int x, y; };
typedef enum { WHITE, BLACK } Color;

void PaintBooleanMatrix(vector<vector<Color>>& grid, Point cur, Color t_color) {
    int h = grid.size(), w = grid.front().size();
    if (cur.x < h && cur.x >= 0 && cur.y < w && cur.y >= 0 && grid[cur.x][cur.y] != t_color) {
        grid[cur.x][cur.y] = t_color;
        PaintBooleanMatrix(grid, { cur.x + 1, cur.y }, t_color);
        PaintBooleanMatrix(grid, { cur.x - 1, cur.y }, t_color);
        PaintBooleanMatrix(grid, { cur.x, cur.y - 1 }, t_color);
        PaintBooleanMatrix(grid, { cur.x, cur.y + 1 }, t_color);
    }
}
