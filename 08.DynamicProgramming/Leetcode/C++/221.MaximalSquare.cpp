#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int h = matrix.size(), w = matrix.front().size(), result = 0;

        vector<vector<int>> left_right(h, vector<int>(w, 0)),
                            top_down(h, vector<int>(w, 0));

        /* compute from left_right */
        for (int i = 0; i < h; ++i) {
            for (int j = w - 1, value = 0; j >= 0; --j) {
                (matrix[i][j] == '1') ? ++value : value = 0;
                left_right[i][j] = value;
            }
        }

        /* compute from top_down*/
        for (int j = 0; j < w; ++j) {
            for (int i = h - 1, value = 0; i >= 0; --i) {
                (matrix[i][j] == '1') ? ++value : value = 0;
                top_down[i][j] = value;
            }
        }
        
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                int left_to_right = left_right[i][j], top_to_down = top_down[i][j],
                    square_length = min(left_to_right, top_to_down);

                int possible_largest_length = square_length;
                    
                
                for (int k = square_length - 1; k >= 0; --k) {
                    if (min(top_down[i][j + k],  left_right[i + k][j])  >=  k + 1) {
                        continue;
                    }

                    possible_largest_length = k;
                }

                result = max(result, possible_largest_length);
            }
        }

        return result * result;
    }
};

