#include "../Debug.h"

using namespace std;

/* space O(1) solution */
void ZeroMatrixInPlace(vector<vector<int>>& matrix) {
    /* using top row and the left most column to memoize whichs 
     * rows and columns should be set to zero */
    int width = matrix[0].size(),
        height = matrix.size();

    /* memorize the zero rows and zero columns */
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (matrix[row][col] == 0) {
                matrix[0][col] = 0;
                matrix[row][0] = 0;
            }
        }
    }
    
    /* set zero rows to zero */
    for (int row = 0; row < height; ++row) {
        int first_col = 0;
        if (matrix[row][first_col] == 0) {
            fill(matrix[row].begin(), matrix[row].end(), 0);
        }
    }
    
    /* set columns to zero */
    for (int col = 0; col < width; ++col) {
        int first_row = 0;
        if (matrix[first_row][col] == 0) {
            for (int row = 0; row < height; ++row) {
                matrix[row][col] = 0;
            }
        }
    }
}

int main(void) {
    vector<vector<int>> matrix = {
        {1,1,1,1,1},
        {1,0,1,1,1},
        {1,0,0,1,1},
        {1,1,1,0,1},
        {1,1,1,1,1}
    };

    print_matrix(matrix);
    ZeroMatrixInPlace(matrix);
    std::cout << std::endl;
    print_matrix(matrix);
    return 0;
}
