#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        for (int i = 0; i <= num; i++) {
            result[i] = (i & 1) ? result[i / 2] + 1 : result[i / 2];
        }

        return result;
    }
};
