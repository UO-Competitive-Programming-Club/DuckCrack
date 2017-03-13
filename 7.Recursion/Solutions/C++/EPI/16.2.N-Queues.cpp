#include "../Debug.h"
using namespace std;

/* we encode each arrangement in a vector of size n
 * eg: (1, 5) can be encoded as vector[1] = 5
 * */  

/* this function does not check if all the placement is valid 
 * it only checks if the most recent placement is valid against all
 * previous placements
 * */
bool IsValid(const vector<int>& col_placement) {
    int row_id = col_placement.size() - 1;
    for (int i = 0; i < row_id; ++i) {
        int diff = abs(col_placement[i] - col_placement[row_id]);
        if (diff == 0 || diff == row_id - 1) {
            return false;
        }
    }
    return true;
}

void SolveNQueues(int n, int row, vector<int>* col_placement, vector<vector<int>>* result) {
    /* base case it means the last row placement is successful */
    if (row == n) {
        /* push the value of the placement to the result */
        result->emplace_back(*col_placement);
    } 
    
    else {
        for (int col = 0; col < n; ++col) {
            col_placement->emplace_back(col);
            if (IsValid(*col_placement)) {
                SolveNQueues(n, row + 1, col_placement, result);
            }
            col_placement->pop_back();
        }
    }
}

vector<vector<int>> NQueues(int n) {
    vector<vector<int>> result;
    SolveNQueues(n, 0, make_unique<vector<int>>().get(), &result);
    return result;
}
