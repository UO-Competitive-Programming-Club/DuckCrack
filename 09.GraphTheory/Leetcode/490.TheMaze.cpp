#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        int sx = start.front(), sy = start.back(), dx = dest.front(), dy = dest.back();
        if (maze.empty() || maze[sx][sy] == 1 || maze[dx][dy] == 1) return false;
        struct point { int x, y; };
        
        int h = maze.size(), w = maze.front().size();
        stack<point> frontier; frontier.push({ start.front(), start.back() });
        while (!frontier.empty()) {
            point cp = frontier.top(); frontier.pop();
            if (cp.x == dx && cp.y == dy) return true;            
            maze[cp.x][cp.y] = 1;
            if (cp.x - 1 >= 0 && maze[cp.x - 1][cp.y] == 0) frontier.push({ cp.x - 1, cp.y });
            if (cp.x + 1  < h && maze[cp.x - 1][cp.y] == 0) frontier.push({ cp.x + 1, cp.y });
            if (cp.y - 1 >= 0 && maze[cp.x][cp.y - 1] == 0) frontier.push({ cp.x, cp.y - 1 });
            if (cp.y + 1  < w && maze[cp.x][cp.y + 1] == 0) frontier.push({ cp.x, cp.y + 1 });
            
        }
        
        return false;
    }
};
