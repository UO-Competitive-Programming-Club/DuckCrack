#include "../Debug.h"
using namespace std;

bool SudokuChecker(const vector<vector<int>>& board) {
    if (board.size() != 9 && board.front().size() != 9) {
        return false;
    }

    int bsize = 9;
    set<int> number_set;

    /* check horizontal lines */
    for (int i = 0; i < bsize; ++i) {
        for (int j = 0; j < bsize; ++j) {
            if (board[i][j] <= 0 && board[i][j] > 9 ) { return false; } 
            else { number_set.insert(board[i][j]); }
        }

        if (number_set.size() != 9) { return false; }
        number_set.clear();
    }

    /* check vertical lines */
    for (int i = 0; i < bsize; ++i) {
        for (int j = 0; j < bsize; ++j) {
            if (board[j][i] <= 0 && board[j][i] > 9 ) { return false; } 
            else { number_set.insert(board[j][i]); }
        }

        if (number_set.size() != 9) { return false; }
        number_set.clear();
    }

    /* check squares get the position of the left upmost corner of each square */
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {

            /* do the checking of each square */
            for (int m = i; m < i + 3; ++m) {
                for (int n = j; n < j + 3; ++n) {
                    if (board[m][n] <= 0 && board[m][n] > 9 ) { return false; } 
                    else { number_set.insert(board[m][n]); }
                }
            }

            if (number_set.size() != 9) { return false; }
            number_set.clear();
        }
    }

    return true;
}
