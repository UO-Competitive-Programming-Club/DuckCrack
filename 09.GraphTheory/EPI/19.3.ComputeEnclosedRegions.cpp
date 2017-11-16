#include <iostream>
#include <vector>

using namespace std;

struct Point { int x, y; };

void PaintColorRegion(vector<vector<char>>& grid, const Point& start, char ocolor, char ncolor) {
    if (grid.empty()) return;
    int h = grid.size(), w = grid.front().size();
    if (0 <= start.x && start.x < h && 0 <= start.y && start.y < w && grid[start.x][start.y] == ocolor) {
        /* paint */
        grid[start.x][start.y] = ncolor;

        /* paint recursively */
        PaintColorRegion(grid, {start.x + 1, start.y}, ocolor, ncolor);
        PaintColorRegion(grid, {start.x - 1, start.y}, ocolor, ncolor);
        PaintColorRegion(grid, {start.x, start.y + 1}, ocolor, ncolor);
        PaintColorRegion(grid, {start.x, start.y - 1}, ocolor, ncolor);
    }
}

void PaintAll(vector<vector<char>>& grid, char ocolor, char ncolor) {
    int h = grid.size(), w = grid.front().size();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == ocolor) {
                grid[i][j] = ncolor;
            }
        }
    }
}

void FillSurroundingRegions(vector<vector<char>>& grid) {
    int h = grid.size(), w = grid.front().size();

    /*first paint all the white open region to grey */
    /* top border */
    for (int col = 0; col < w; col++) { PaintColorRegion(grid, {0, col}, 'W', 'G'); }
    /* bottom border */
    for (int col = 0; col < w; col++) { PaintColorRegion(grid, {h - 1, col}, 'W', 'G'); }
    /* left border */
    for (int row = 0; row < h; row++) { PaintColorRegion(grid, {row, 0}, 'W', 'G'); }
    /* right border */
    for (int row = 0; row < h; row++) { PaintColorRegion(grid, {row, w - 1}, 'W', 'G'); }

    /* then paint all the white regions to black */
    PaintAll(grid, 'W', 'B');

    /* then paint all the grey regions to white */
    PaintAll(grid, 'G', 'W');
}


