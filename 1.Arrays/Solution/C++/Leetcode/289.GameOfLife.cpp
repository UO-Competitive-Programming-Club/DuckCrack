#include "../Debug.h"

using namespace std;
int CountNeighbors(const vector<vector<int>>& board, int i, int j) {
    int life_to_death = INT_MIN,
        neightbor_num = 0, 
        m = board.size(),
        n = board[0].size();

    /* top left */
    if (i - 1 >= 0 && j - 1 >= 0) { 
        neightbor_num += (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == life_to_death) ? 1 : 0; 
    }
    /* top */
    if (i - 1 >= 0) { 
        neightbor_num += (board[i - 1][j] == 1 || board[i - 1][j] == life_to_death) ? 1 : 0; 
    }
    /* top right */
    if (i + 1 < m && j - 1 >= 0) { 
        neightbor_num += (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == life_to_death) ? 1 : 0; 
    }
    /* left */
    if (j - 1 >= 0) { 
        neightbor_num += (board[i][j - 1] == 1 || board[i][j - 1] == life_to_death) ? 1 : 0; 
    }
    /* right */
    if (j + 1 < m) { 
        neightbor_num += (board[i][j + 1] == 1 || board[i][j + 1] == life_to_death) ? 1 : 0; 
    }
    /* down left */
    if (i + 1 < m && j - 1 >= 0) { 
        neightbor_num += (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == life_to_death) ? 1 : 0;
    }
    /* down */
    if (i + 1 < n) { 
        neightbor_num += (board[i + 1][j] == 1 || board[i + 1][j] == life_to_death) ? 1 : 0;
    }
    /* down right */
    if (i + 1 < m && j + 1 < n) { 
        neightbor_num += (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == life_to_death) ? 1 : 0; 
    }

    return neightbor_num;
}

void GameOfLife(vector<vector<int>>& board) {
    int death_to_life = INT_MAX,
        life_to_death = INT_MIN,
        m = board.size(),
        n = board[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int neightbor_num = CountNeighbors(board, i, j); 

            if (neightbor_num < 2 || neightbor_num > 3) {
                board[i][j] = life_to_death;
            } else if (neightbor_num == 3) {
                board[i][j] = death_to_life;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == life_to_death) {
                board[i][j] = 0;
            } else if (board[i][j] == death_to_life) {
                board[i][j] = 1;
            }
        }
    }
}
