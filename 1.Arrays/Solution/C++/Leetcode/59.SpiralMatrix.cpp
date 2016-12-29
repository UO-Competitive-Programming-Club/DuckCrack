#include "../Debug.h"

using namespace std;
vector<vector<int>> SpiralOrdering(int n) {
    /* we traverse through the array in 4 ways, from top -> right -> bottom -> left 
     * as the diagram shown blow */
    /* T T T T R */
    /* L       R */
    /* L       R */
    /* L       R */
    /* L B B B B */

    vector<vector<int>> result(n, vector<int>(n, 0));
    int msize = n,
        layer_nums = n / 2,
        cur_layer = 0, 
        counter = 1;

    /* loop layer by layers */
    for (; cur_layer < layer_nums; ++cur_layer) {
        /* top */
        for (int col = cur_layer, row = cur_layer; 
                col < msize - cur_layer - 1; 
                ++col) {
            result[row][col] = counter++;
        }

        /* right */ 
        for (int col = msize - cur_layer - 1, row = cur_layer; 
                row < msize - cur_layer - 1; 
                ++row) {
            result[row][col] = counter++;
        }

        /* bottom */
        for (int col = msize - cur_layer - 1, row = msize - cur_layer - 1;
                col > cur_layer; 
                --col) {
            result[row][col] = counter++;
        }

        /* left */
        for (int col = cur_layer, row = msize - cur_layer - 1;
                row > cur_layer;
                --row) {
            result[row][col] = counter++;
        }
    }

    /* if odd, we add the most inner element */
    if (msize % 2) { 
        result[layer_nums][layer_nums] = counter;
    }

    return result;
}
