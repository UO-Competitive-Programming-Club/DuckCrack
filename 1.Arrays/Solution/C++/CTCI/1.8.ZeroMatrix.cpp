#include "../Debug.h"

using namespace std;

/* space O(1) solution */
void ZeroMatrixInPlace(vector<vector<int>>& matrix) {
    /* using top row and the left most column to memoize whichs 
     * rows and columns should be set to zero */
    int width = matrix[0].size(),
        height = matrix.size(),
        first_row = 0,
        first_col = 0;

    bool first_row_zero = false,
         first_col_zero = false;
    
    /* check if the first row should be emptied */
    for (int col = 0; col < width && !first_row_zero; ++col) {
        if (matrix[first_row][col] == 0) {
            first_row_zero = true;
        }
    }

    /* check if the first column should be emptied */
    for (int row = 0; row < height && !first_col_zero; ++row) {
        if (matrix[row][first_col] == 0) {
            first_col_zero = true;
        }
    }

    /* memorize the zero rows and zero columns */
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (matrix[row][col] == 0) {
                matrix[0][col] = 0;
                matrix[row][0] = 0;
            }
        }
    }
    
    /* set zero rows to zero 
     * iterating starting from the second row since we use the first row
     * to memoize the zero columns*/
    for (int row = 1; row < height; ++row) {
        if (matrix[row][first_col] == 0) {
            fill(matrix[row].begin(), matrix[row].end(), 0);
        }
    }
    
    /* set columns to zero 
     * iterating starting from the second column since we use the first 
     * column to memoize the zero column */
    for (int col = 1; col < width; ++col) {
        if (matrix[first_row][col] == 0) {
            for (int row = 0; row < height; ++row) {
                matrix[row][col] = 0;
            }
        }
    }

    if (first_row_zero) {
        fill(matrix[first_row].begin(), matrix[first_col].end(), 0);
    }

    if (first_col_zero) {
        for (int row = 0; row < height; ++row) {
            matrix[row][first_col] = 0;
        }
    }
}

int main(void) {
    vector<vector<int>> matrix = {
        {1,0},
    };

    print_matrix(matrix);
    ZeroMatrixInPlace(matrix);
    std::cout << std::endl;
    print_matrix(matrix);
    return 0;
}
