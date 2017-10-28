#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int largestRectangleArea(vector<int> &height) {

    int ret = 0;
    height.push_back(0);
    vector<int> index;

    for(int i = 0; i < height.size(); i++)
    {
        while(index.size() > 0 && height[index.back()] >= height[i])
        {
            int h = height[index.back()];
            index.pop_back();

            int sidx = index.size() > 0 ? index.back() : -1;
            if(h * (i-sidx-1) > ret)
                ret = h * (i-sidx-1);
        }
        index.push_back(i);
    }

    return ret;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int result = 0, h = matrix.size(), w = matrix.front().size();
    vector<int> histogram(w, 0);
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int cur = matrix[i][j] - '0';
            histogram[j] = (cur == 0) ? 0 : histogram[j] + 1;
        }
        result = max(result, largestRectangleArea(histogram));
    }

    return result;
}
