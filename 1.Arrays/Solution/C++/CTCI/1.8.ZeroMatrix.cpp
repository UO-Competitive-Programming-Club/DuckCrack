#include "../Debug.h"
using namespace std;

/* space O(N) solution */
void ZeroMatrix(vector<vector<int>>& matrix) {
    vector<int> zero_row(matrix[0].size(), 0), 
                zero_col(matrix.size(), 0);

    int m = matrix[0].size(),
        n = matrix.size();

    /* save row and col informations */
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                zero_row[i] = 1;
                zero_col[j] = 1;
            }
        }
    }

    /* clear rows */
    for (size_t i = 0; i < zero_row.size(); i++) {
        if (zero_row[i]) {
            fill(matrix[i].begin(), matrix[i].end(), 0);
        }
    }

    /* clear columns */
    for (size_t i = 0; i < zero_col.size(); i++) {
        if (zero_col[i]) {
            for (int j = 0; j < n; j++) {
                 matrix[j][i] = 0;
            }
        }
    }
}
