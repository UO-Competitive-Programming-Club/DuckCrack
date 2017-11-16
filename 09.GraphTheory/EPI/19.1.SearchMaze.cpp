#include <iostream>
#include <array>
#include <vector>

using namespace std;

typedef enum { WHITE, BLACK } Color;
struct Point {
    bool operator==(const Point& other) const {
        return other.x == x && other.y == y;
    }

    int x, y;
};

bool IsValidVisit(const vector<vector<Color>>& maze, const Point& p) {
    int h = maze.size(), w = maze.front().size();
    return p.x >= 0 && p.x < h && p.y >= 0 && p.y < w && maze[p.x][p.y] == WHITE;
}

bool SearchMazeHelper(vector<vector<Color>>& maze, vector<Point>& path, 
        const Point& cur, const Point& dest) {
    /* found the item */
    if (cur == dest) return true;
    /* mark current node as visited */
    maze[cur.x][cur.y] = BLACK;
    const array<array<int, 2>, 4> directions = { {{0, 1}, {0, -1}, {1, 0}, {-1, 0}} };
    for (auto& d: directions) {
        Point next = { cur.x + d.front(), cur.y + d.back() };
        if (IsValidVisit(maze, next)) {
            path.emplace_back(next);
            if (SearchMazeHelper(maze, path, next, dest)) return true;
            path.pop_back();
        }
    }

    return false;
}


vector<Point> SearchMaze(vector<vector<Color>> maze, const Point& start, const Point& dest) { 
    vector<Point> path;
    maze[start.x][start.y] = BLACK;
    path.emplace_back(start);

    /* push the first item inside */
    if (!SearchMazeHelper(maze, path, start, dest)) path.pop_back();
    return path;
}
