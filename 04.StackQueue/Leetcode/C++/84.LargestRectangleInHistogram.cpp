#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int hlen = heights.size(),
        max_area = heights.front();

    for (int i = 0; i < hlen; ++i) {
        if (s.empty() || heights[s.top()] < heights[i]) {
            s.push(i);
        }

        else {
            int height = heights[s.top()]; s.pop();
            int width  = i - ((s.empty()) ? 0 : s.top()) - 1;
            max_area = max(max_area, height * width);
        }
    }

    while (!s.empty()) {
        
    }

    return max_area;
}
