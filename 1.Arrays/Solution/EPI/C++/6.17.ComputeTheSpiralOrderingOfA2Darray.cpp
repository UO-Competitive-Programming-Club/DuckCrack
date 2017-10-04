#include "../Debug.h"
using namespace std;
vector<int> SpiralOrdering(const vector<vector<int>>& matrix) {
    /* we traverse through the array in 4 ways, from top -> right -> bottom -> left 
     * as the diagram shown blow */
    /* T T T T R */
    /* L       R */
    /* L       R */
    /* L       R */
    /* L B B B B */

    vector<int> result;
    int msize = matrix.size(),
        layer_nums = matrix.size() / 2,
        cur_layer = 0;

    /* loop layer by layers */
    for (; cur_layer < layer_nums; ++cur_layer) {
        /* top */
        for (int col = cur_layer, row = cur_layer; 
                col < msize - cur_layer - 1; 
                ++col) {
            result.push_back(matrix[row][col]);
        }

        /* right */ 
        for (int col = msize - cur_layer - 1, row = cur_layer; 
                row < msize - cur_layer - 1; 
                ++row) {
            result.push_back(matrix[row][col]);
        }

        /* bottom */
        for (int col = msize - cur_layer - 1, row = msize - cur_layer - 1;
                col > cur_layer; 
                --col) {
            result.push_back(matrix[row][col]);
        }

        /* left */
        for (int col = cur_layer, row = msize - cur_layer - 1;
                row > cur_layer;
                --row) {
            result.push_back(matrix[row][col]);
        }
    }

    /* if odd, we add the most inner element */
    if (msize % 2) { result.push_back(matrix[layer_nums][layer_nums]); }

    return result;
}

int main(void) {
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> B = {
        {1, 2},
        {3, 4}
    };
    
    vector<int> answer = {1,2,3,6,9,8,7,4,5};
    print_vector(answer);
    print_vector(SpiralOrdering(B));

    return 0;
}
