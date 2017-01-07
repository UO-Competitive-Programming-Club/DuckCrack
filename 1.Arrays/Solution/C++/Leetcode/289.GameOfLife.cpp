#include "../Debug.h"

using namespace std;
int CountNeighbors(const vector<vector<int>>& board, int i, int j) {
	int life_to_death = INT_MIN,
		neightbor_num = 0, 
		m = board.size(),
		n = board[0].size();

    for (int vertical_offset = -1; vertical_offset < 2; ++vertical_offset) {
        for (int horizontal_offset = -1; horizontal_offset < 2; ++horizontal_offset) {
            int i_p = i + vertical_offset, j_p = j + horizontal_offset;
            if (i_p < m && i_p >= 0 && j_p < n && j_p >= 0 && (i_p != i || j_p != j)) {
                neightbor_num += (board[i_p][j_p] == 1 || board[i_p][j_p] == life_to_death) ? 1 : 0; 
            }
        }
    }

	return neightbor_num;
}

void gameOfLife(vector<vector<int>>& board) {
	int death_to_life = INT_MAX,
		life_to_death = INT_MIN,
		m = board.size(),
		n = board[0].size();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int neightbor_num = CountNeighbors(board, i, j); 
			cout << neightbor_num << endl;
			if (neightbor_num < 2 || neightbor_num > 3) {
				board[i][j] = (board[i][j] == 1) ? life_to_death : 0;
			} else if (neightbor_num == 3) {
				board[i][j] = (board[i][j] == 0) ? death_to_life : 1;
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
