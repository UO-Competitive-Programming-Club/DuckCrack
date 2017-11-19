#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    struct State { int x, y; };
    void wallsAndGates(vector<vector<int>>& rooms) {
        int h = rooms.size(), w = rooms.front().size();
        array<array<int, 2>, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
        queue<State> frontier;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (rooms[i][j] == 0) frontier.push({i, j});
            }
        }

        while (!frontier.empty()) {
            State cs = frontier.front(); frontier.pop();
            for (auto dir: directions) {    
                int nx = cs.x + dir.front(), ny = cs.y + dir.back();
                if (0 <= nx && nx < h && 0 <= ny && ny < w          // boundry checking
                    && rooms[nx][ny] != -1 && rooms[nx][ny] != 0    // not interested in walls and gates as well
                    && rooms[nx][ny] > rooms[cs.x][cs.y] + 1) {         // check if it needs to be explored
                    rooms[nx][ny] = rooms[cs.x][cs.y] + 1;
                    frontier.push({nx, ny});
                }
            }
        }
    }
};

