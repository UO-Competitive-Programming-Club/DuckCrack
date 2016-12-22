#include "../Debug.h"
using namespace std;
vector<int> SpiralOrdering(const vector<vector<int>>& matrix) {
    int msize = matrix.size(),
        layer_nums = matrix.size() / 2,
        cur_layer = 0;


    vector<int> result;
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


        /* t t t t r */
        /* l       r */
        /* l       r */
        /* l       r */
        /* l b b b b */

        /* bottom */
        for (int col = msize - cur_layer - 1, row = msize - cur_layer - 1;
                col > cur_layer; 
                --col) {

            result.push_back(matrix[row][col]);
        }

        /* t t t t r */
        /* l       r */
        /* l       r */
        /* l       r */
        /* l b b b b */

        /* left */
        for (int col = cur_layer, row = msize - cur_layer - 1;
                row > cur_layer;
                --row) {

            result.push_back(matrix[row][col]);
        }
    }

    /* if odd, we add the most inner element */
    if (msize % 2) {
        result.push_back(matrix[layer_nums][layer_nums]);
    }

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
