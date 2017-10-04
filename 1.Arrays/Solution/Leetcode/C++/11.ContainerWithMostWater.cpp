#include "../Debug.h"
#include <algorithm>
using namespace std;

/* Initially we consider the area constituting the exterior most lines. Now, to maximize the area, we need to */ 
/* consider the area between the lines of larger lengths. If we try to move the pointer at the longer line */ 
/* inwards, we won't gain any increase in area, since it is limited by the shorter line. But moving the */ 
/* shorter line's pointer could turn out to be beneficial, as per the same argument, despite the reduction */ 
/* in the width. This is done since a relatively longer line obtained by moving the shorter line's pointer */ 
/* might overcome the reduction in area caused by the width reduction. */

int MaxArea(const vector<int>& height) {
    int left = 0, right = height.size() - 1, max_area = 0;

    while (left < right) {
        int new_area = min(height[left], height[right]) * (right - left);
        max_area = max(new_area, max_area);
        (height[left] < height[right]) ? ++left : --right;
    }

    return max_area;
}

